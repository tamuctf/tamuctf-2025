import string  
import re
from sage.all import *

chrs = (string.ascii_letters + string.digits + "_").encode()  
avg = sorted(chrs)[len(chrs) // 2] - 1  
print(f"{avg = }")  
print([x - avg for x in sorted(chrs)])  # within [-37, 37]  
  
flaglen = 38
M = 114093090821120352479644063983906458923779848139997892783140659734927967458173
C = int.from_bytes(b"gigem{" + b"\x00" * flaglen + b"}", "big")  
rem = 58809011802516045741268578327158509054400633329629779038362406616616290661238
C -= rem

P = PolynomialRing(ZZ, "ap", flaglen)  
aps = P.gens()  
aa = [ap + avg for ap in aps]  
f = C + sum([a * 256**i for i, a in enumerate(aa)]) * 256  
print(f)  
  
L = matrix(f.coefficients()).T  
L = block_matrix([[M, 0], [L, 1]])  
bounds = [1] + [37] * flaglen + [1]  
scale = [2**20 // i for i in bounds]  
Q = diagonal_matrix(scale)  
L *= Q  
L = L.BKZ(block_size=25)  
L /= Q  

  
# not good enough  
# for row in L:  
#     if row[-1] < 0:  
#         row = -row  
#     if row[0] == 0 and row[-1] == 1:  
#         print(row)  
#         print(f(*row[1:-1]) % M == 0)  
#         aa = [x + avg for x in row[1:-1]][::-1]  
#         flag = b"gigem{" + bytes(aa) + b"}"  
#         
#         assert int.from_bytes(flag, "big") % M == rem  
#         print(flag)  
# exit()  

from fpylll import IntegerMatrix, LLL  
from fpylll.fplll.gso import MatGSO  
from fpylll.fplll.enumeration import Enumeration  
  
sols = []  
  
L[:, 0] *= 2**10  
A = IntegerMatrix.from_matrix(L.change_ring(ZZ))  
LLL.reduction(A)  
MG = MatGSO(A)  
MG.update_gso()  
sol_cnt = 10000  
enum = Enumeration(MG, sol_cnt)  
size = int(L.nrows())  
bound = 37  
answers = enum.enumerate(0, size, (size * bound**2), 0, pruning=None)  
for _, s in answers:  
    v = IntegerMatrix.from_iterable(1, A.nrows, map(int, s))  
    sv = v * A  
  
    if abs(sv[0, size - 1]) <= bound and sv[0, -1] in (-1, 1):  
        print(sv)  
        neg = sv[0, -1]  
        sol = [neg * sv[0, i + 1] for i in range(flaglen)]  
        assert f(*sol) % M == 0  
        aa = [x + avg for x in sol][::-1]  
        try:
            flag = b"gigem{" + bytes(aa) + b"}"  
        except:
            continue
        assert int.from_bytes(flag, "big") % M == rem
        print(flag)  
        
        try:  
            if re.fullmatch(r"gigem{\w{38}}", flag.decode()):  
                print("FOUND")  
                break  
        except UnicodeDecodeError:  
            pass  