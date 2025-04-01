#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
HANDLE events[1033];
void CreateEvents() {
for (int i = 0; i < 1033; i++) {
events[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
}
}
HANDLE semaphores[302];
void CreateSemaphores() {
for (int i = 0; i < 302; i++) {
semaphores[i] = CreateSemaphore(NULL, 0, 1337, NULL);
}
}
void WINAPI Thread_0(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[942], INFINITE);
WaitForSingleObject(events[787], INFINITE);
WaitForSingleObject(events[949], INFINITE);
WaitForSingleObject(events[2], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[177], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 1, NULL);
ReleaseSemaphore(semaphores[22], 4, NULL);
ReleaseSemaphore(semaphores[161], 4, NULL);
ReleaseSemaphore(semaphores[140], 1, NULL);
SetEvent(events[157]);
SetEvent(events[453]);
SetEvent(events[47]);
SetEvent(events[636]);
} else {
WaitForSingleObject(events[118], INFINITE);
// bad checks done
SetEvent(events[917]);
SetEvent(events[599]);
ReleaseSemaphore(semaphores[179], 4, NULL);
ReleaseSemaphore(semaphores[110], 2, NULL);
}
}
void WINAPI Thread_1(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[290], INFINITE);
WaitForSingleObject(events[771], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[136], INFINITE);
}
// good checks done
SetEvent(events[970]);
SetEvent(events[79]);
SetEvent(events[1020]);
ReleaseSemaphore(semaphores[301], 2, NULL);
ReleaseSemaphore(semaphores[177], 2, NULL);
SetEvent(events[623]);
ReleaseSemaphore(semaphores[125], 2, NULL);
ReleaseSemaphore(semaphores[69], 2, NULL);
} else {
WaitForSingleObject(events[765], INFINITE);
WaitForSingleObject(events[280], INFINITE);
WaitForSingleObject(events[59], INFINITE);
WaitForSingleObject(events[130], INFINITE);
WaitForSingleObject(events[1009], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[136], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[9], 1, NULL);
ReleaseSemaphore(semaphores[238], 1, NULL);
ReleaseSemaphore(semaphores[201], 4, NULL);
ReleaseSemaphore(semaphores[267], 4, NULL);
ReleaseSemaphore(semaphores[94], 2, NULL);
}
}
void WINAPI Thread_2(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[544], INFINITE);
WaitForSingleObject(events[587], INFINITE);
WaitForSingleObject(events[854], INFINITE);
// good checks done
SetEvent(events[91]);
SetEvent(events[622]);
SetEvent(events[273]);
SetEvent(events[823]);
ReleaseSemaphore(semaphores[252], 3, NULL);
SetEvent(events[919]);
ReleaseSemaphore(semaphores[27], 1, NULL);
ReleaseSemaphore(semaphores[144], 1, NULL);
SetEvent(events[641]);
SetEvent(events[929]);
SetEvent(events[26]);
} else {
WaitForSingleObject(events[1026], INFINITE);
WaitForSingleObject(events[1022], INFINITE);
WaitForSingleObject(events[948], INFINITE);
WaitForSingleObject(events[59], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[163], 1, NULL);
ReleaseSemaphore(semaphores[200], 3, NULL);
SetEvent(events[104]);
SetEvent(events[784]);
SetEvent(events[734]);
ReleaseSemaphore(semaphores[135], 2, NULL);
SetEvent(events[929]);
ReleaseSemaphore(semaphores[125], 3, NULL);
ReleaseSemaphore(semaphores[166], 3, NULL);
SetEvent(events[750]);
}
}
void WINAPI Thread_3(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[625], INFINITE);
WaitForSingleObject(events[1004], INFINITE);
WaitForSingleObject(events[45], INFINITE);
WaitForSingleObject(events[817], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[255], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[140], 2, NULL);
SetEvent(events[834]);
ReleaseSemaphore(semaphores[180], 2, NULL);
ReleaseSemaphore(semaphores[131], 4, NULL);
SetEvent(events[617]);
SetEvent(events[244]);
SetEvent(events[477]);
ReleaseSemaphore(semaphores[177], 3, NULL);
SetEvent(events[841]);
ReleaseSemaphore(semaphores[132], 4, NULL);
} else {
WaitForSingleObject(events[521], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[255], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[22], 3, NULL);
ReleaseSemaphore(semaphores[140], 1, NULL);
ReleaseSemaphore(semaphores[261], 4, NULL);
ReleaseSemaphore(semaphores[97], 1, NULL);
ReleaseSemaphore(semaphores[207], 1, NULL);
SetEvent(events[975]);
ReleaseSemaphore(semaphores[141], 2, NULL);
SetEvent(events[859]);
ReleaseSemaphore(semaphores[246], 4, NULL);
ReleaseSemaphore(semaphores[92], 3, NULL);
}
}
void WINAPI Thread_4(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[167], INFINITE);
WaitForSingleObject(events[370], INFINITE);
// bad checks done
SetEvent(events[788]);
SetEvent(events[33]);
SetEvent(events[479]);
ReleaseSemaphore(semaphores[99], 4, NULL);
SetEvent(events[4]);
ReleaseSemaphore(semaphores[216], 3, NULL);
SetEvent(events[394]);
} else {
WaitForSingleObject(events[589], INFINITE);
WaitForSingleObject(events[864], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[4], INFINITE);
}
// good checks done
SetEvent(events[917]);
SetEvent(events[200]);
SetEvent(events[834]);
SetEvent(events[724]);
SetEvent(events[908]);
}
}
void WINAPI Thread_5(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[193], INFINITE);
WaitForSingleObject(events[181], INFINITE);
WaitForSingleObject(events[700], INFINITE);
WaitForSingleObject(events[608], INFINITE);
WaitForSingleObject(events[3], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[62], INFINITE);
}
// good checks done
SetEvent(events[712]);
SetEvent(events[611]);
ReleaseSemaphore(semaphores[225], 3, NULL);
} else {
WaitForSingleObject(events[596], INFINITE);
WaitForSingleObject(events[185], INFINITE);
// bad checks done
SetEvent(events[226]);
ReleaseSemaphore(semaphores[110], 1, NULL);
ReleaseSemaphore(semaphores[148], 1, NULL);
ReleaseSemaphore(semaphores[291], 2, NULL);
SetEvent(events[418]);
ReleaseSemaphore(semaphores[83], 1, NULL);
}
}
void WINAPI Thread_6(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[893], INFINITE);
WaitForSingleObject(events[1029], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[14], INFINITE);
}
// good checks done
} else {
WaitForSingleObject(events[615], INFINITE);
WaitForSingleObject(events[781], INFINITE);
WaitForSingleObject(events[51], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[14], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[99], 4, NULL);
SetEvent(events[286]);
ReleaseSemaphore(semaphores[190], 2, NULL);
ReleaseSemaphore(semaphores[98], 3, NULL);
ReleaseSemaphore(semaphores[92], 4, NULL);
}
}
void WINAPI Thread_7(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[875], INFINITE);
WaitForSingleObject(events[252], INFINITE);
WaitForSingleObject(events[258], INFINITE);
WaitForSingleObject(events[481], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[172], INFINITE);
}
// bad checks done
SetEvent(events[247]);
SetEvent(events[907]);
SetEvent(events[455]);
ReleaseSemaphore(semaphores[222], 2, NULL);
ReleaseSemaphore(semaphores[100], 2, NULL);
ReleaseSemaphore(semaphores[214], 1, NULL);
SetEvent(events[482]);
SetEvent(events[425]);
} else {
WaitForSingleObject(events[315], INFINITE);
WaitForSingleObject(events[550], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[172], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[163], 1, NULL);
SetEvent(events[905]);
SetEvent(events[456]);
SetEvent(events[758]);
ReleaseSemaphore(semaphores[82], 4, NULL);
SetEvent(events[951]);
}
}
void WINAPI Thread_8(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[259], INFINITE);
WaitForSingleObject(events[792], INFINITE);
WaitForSingleObject(events[321], INFINITE);
WaitForSingleObject(events[986], INFINITE);
WaitForSingleObject(events[254], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[226], INFINITE);
}
// good checks done
SetEvent(events[766]);
ReleaseSemaphore(semaphores[192], 3, NULL);
} else {
WaitForSingleObject(events[78], INFINITE);
WaitForSingleObject(events[102], INFINITE);
WaitForSingleObject(events[730], INFINITE);
WaitForSingleObject(events[974], INFINITE);
WaitForSingleObject(events[783], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[226], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[37], 2, NULL);
ReleaseSemaphore(semaphores[215], 3, NULL);
ReleaseSemaphore(semaphores[243], 1, NULL);
ReleaseSemaphore(semaphores[14], 2, NULL);
SetEvent(events[610]);
SetEvent(events[403]);
ReleaseSemaphore(semaphores[204], 2, NULL);
SetEvent(events[951]);
SetEvent(events[902]);
SetEvent(events[23]);
}
}
void WINAPI Thread_9(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[98], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[104], 1, NULL);
SetEvent(events[113]);
ReleaseSemaphore(semaphores[5], 4, NULL);
SetEvent(events[118]);
ReleaseSemaphore(semaphores[251], 1, NULL);
ReleaseSemaphore(semaphores[291], 4, NULL);
ReleaseSemaphore(semaphores[173], 2, NULL);
} else {
WaitForSingleObject(events[138], INFINITE);
WaitForSingleObject(events[1010], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[98], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[271], 4, NULL);
ReleaseSemaphore(semaphores[81], 4, NULL);
SetEvent(events[58]);
ReleaseSemaphore(semaphores[290], 3, NULL);
SetEvent(events[149]);
SetEvent(events[153]);
}
}
void WINAPI Thread_10(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[47], INFINITE);
WaitForSingleObject(events[1000], INFINITE);
WaitForSingleObject(events[531], INFINITE);
WaitForSingleObject(events[995], INFINITE);
WaitForSingleObject(events[634], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[36], 1, NULL);
ReleaseSemaphore(semaphores[291], 1, NULL);
} else {
WaitForSingleObject(events[745], INFINITE);
WaitForSingleObject(events[578], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[30], INFINITE);
}
// good checks done
}
}
void WINAPI Thread_11(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[979], INFINITE);
WaitForSingleObject(events[91], INFINITE);
WaitForSingleObject(events[441], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[233], INFINITE);
}
// good checks done
SetEvent(events[302]);
ReleaseSemaphore(semaphores[56], 2, NULL);
ReleaseSemaphore(semaphores[23], 3, NULL);
SetEvent(events[945]);
ReleaseSemaphore(semaphores[217], 4, NULL);
SetEvent(events[443]);
SetEvent(events[330]);
ReleaseSemaphore(semaphores[171], 1, NULL);
ReleaseSemaphore(semaphores[43], 2, NULL);
SetEvent(events[669]);
SetEvent(events[237]);
} else {
WaitForSingleObject(events[402], INFINITE);
WaitForSingleObject(events[346], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[233], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[107], 4, NULL);
SetEvent(events[744]);
ReleaseSemaphore(semaphores[223], 2, NULL);
ReleaseSemaphore(semaphores[119], 3, NULL);
SetEvent(events[792]);
ReleaseSemaphore(semaphores[70], 3, NULL);
}
}
void WINAPI Thread_12(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[547], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[234], INFINITE);
}
// bad checks done
SetEvent(events[241]);
SetEvent(events[375]);
SetEvent(events[556]);
SetEvent(events[144]);
} else {
WaitForSingleObject(events[543], INFINITE);
WaitForSingleObject(events[654], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[234], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[9], 3, NULL);
SetEvent(events[307]);
SetEvent(events[832]);
SetEvent(events[373]);
ReleaseSemaphore(semaphores[134], 1, NULL);
ReleaseSemaphore(semaphores[107], 4, NULL);
ReleaseSemaphore(semaphores[223], 3, NULL);
SetEvent(events[1012]);
ReleaseSemaphore(semaphores[197], 2, NULL);
SetEvent(events[464]);
}
}
void WINAPI Thread_13(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[740], INFINITE);
WaitForSingleObject(events[877], INFINITE);
WaitForSingleObject(events[534], INFINITE);
WaitForSingleObject(events[925], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[5], INFINITE);
}
// good checks done
SetEvent(events[516]);
ReleaseSemaphore(semaphores[114], 3, NULL);
ReleaseSemaphore(semaphores[22], 1, NULL);
ReleaseSemaphore(semaphores[261], 1, NULL);
ReleaseSemaphore(semaphores[231], 4, NULL);
ReleaseSemaphore(semaphores[265], 1, NULL);
SetEvent(events[533]);
ReleaseSemaphore(semaphores[97], 4, NULL);
SetEvent(events[469]);
ReleaseSemaphore(semaphores[50], 3, NULL);
ReleaseSemaphore(semaphores[46], 3, NULL);
ReleaseSemaphore(semaphores[240], 3, NULL);
SetEvent(events[953]);
} else {
WaitForSingleObject(events[202], INFINITE);
WaitForSingleObject(events[926], INFINITE);
WaitForSingleObject(events[868], INFINITE);
WaitForSingleObject(events[809], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[64], 2, NULL);
SetEvent(events[998]);
ReleaseSemaphore(semaphores[183], 2, NULL);
}
}
void WINAPI Thread_14(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[658], INFINITE);
WaitForSingleObject(events[256], INFINITE);
WaitForSingleObject(events[97], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[189], INFINITE);
}
// good checks done
SetEvent(events[893]);
ReleaseSemaphore(semaphores[286], 3, NULL);
ReleaseSemaphore(semaphores[87], 1, NULL);
} else {
WaitForSingleObject(events[64], INFINITE);
WaitForSingleObject(events[581], INFINITE);
WaitForSingleObject(events[93], INFINITE);
WaitForSingleObject(events[1009], INFINITE);
WaitForSingleObject(events[412], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[189], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[46], 4, NULL);
ReleaseSemaphore(semaphores[50], 2, NULL);
}
}
void WINAPI Thread_15(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[150], INFINITE);
}
// bad checks done
SetEvent(events[325]);
ReleaseSemaphore(semaphores[111], 4, NULL);
ReleaseSemaphore(semaphores[269], 3, NULL);
SetEvent(events[465]);
} else {
WaitForSingleObject(events[618], INFINITE);
WaitForSingleObject(events[967], INFINITE);
WaitForSingleObject(events[240], INFINITE);
WaitForSingleObject(events[242], INFINITE);
WaitForSingleObject(events[345], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[150], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[122], 4, NULL);
}
}
void WINAPI Thread_16(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[910], INFINITE);
WaitForSingleObject(events[471], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[24], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 1, NULL);
ReleaseSemaphore(semaphores[22], 3, NULL);
SetEvent(events[267]);
ReleaseSemaphore(semaphores[140], 4, NULL);
ReleaseSemaphore(semaphores[42], 4, NULL);
SetEvent(events[674]);
SetEvent(events[344]);
ReleaseSemaphore(semaphores[99], 1, NULL);
} else {
WaitForSingleObject(events[239], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[24], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[177], 1, NULL);
SetEvent(events[710]);
}
}
void WINAPI Thread_17(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[383], INFINITE);
WaitForSingleObject(events[267], INFINITE);
WaitForSingleObject(events[465], INFINITE);
WaitForSingleObject(events[528], INFINITE);
WaitForSingleObject(events[790], INFINITE);
WaitForSingleObject(events[224], INFINITE);
for (i = 0; i < 26; i++) {
    WaitForSingleObject(semaphores[161], INFINITE);
}
// good checks done
SetEvent(events[604]);
SetEvent(events[322]);
} else {
WaitForSingleObject(events[1019], INFINITE);
WaitForSingleObject(events[887], INFINITE);
WaitForSingleObject(events[684], INFINITE);
WaitForSingleObject(events[140], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[161], INFINITE);
}
// bad checks done
SetEvent(events[902]);
ReleaseSemaphore(semaphores[84], 2, NULL);
ReleaseSemaphore(semaphores[248], 3, NULL);
SetEvent(events[922]);
ReleaseSemaphore(semaphores[153], 4, NULL);
ReleaseSemaphore(semaphores[28], 3, NULL);
SetEvent(events[974]);
}
}
void WINAPI Thread_18(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[614], INFINITE);
WaitForSingleObject(events[707], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[242], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 1, NULL);
ReleaseSemaphore(semaphores[86], 2, NULL);
SetEvent(events[179]);
ReleaseSemaphore(semaphores[225], 3, NULL);
SetEvent(events[336]);
} else {
WaitForSingleObject(events[447], INFINITE);
WaitForSingleObject(events[570], INFINITE);
WaitForSingleObject(events[639], INFINITE);
WaitForSingleObject(events[700], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[226], 1, NULL);
ReleaseSemaphore(semaphores[72], 3, NULL);
}
}
void WINAPI Thread_19(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[923], INFINITE);
WaitForSingleObject(events[566], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[70], INFINITE);
}
// bad checks done
SetEvent(events[984]);
ReleaseSemaphore(semaphores[85], 1, NULL);
ReleaseSemaphore(semaphores[258], 1, NULL);
SetEvent(events[449]);
ReleaseSemaphore(semaphores[203], 1, NULL);
ReleaseSemaphore(semaphores[263], 4, NULL);
SetEvent(events[726]);
SetEvent(events[41]);
} else {
WaitForSingleObject(events[366], INFINITE);
WaitForSingleObject(events[816], INFINITE);
WaitForSingleObject(events[775], INFINITE);
WaitForSingleObject(events[861], INFINITE);
WaitForSingleObject(events[548], INFINITE);
WaitForSingleObject(events[433], INFINITE);
WaitForSingleObject(events[759], INFINITE);
WaitForSingleObject(events[356], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[70], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[47], 4, NULL);
SetEvent(events[474]);
ReleaseSemaphore(semaphores[297], 2, NULL);
SetEvent(events[435]);
ReleaseSemaphore(semaphores[274], 4, NULL);
SetEvent(events[647]);
SetEvent(events[551]);
ReleaseSemaphore(semaphores[28], 1, NULL);
}
}
void WINAPI Thread_20(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[669], INFINITE);
WaitForSingleObject(events[618], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[283], INFINITE);
}
// bad checks done
} else {
WaitForSingleObject(events[834], INFINITE);
WaitForSingleObject(events[455], INFINITE);
WaitForSingleObject(events[69], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[283], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 2, NULL);
ReleaseSemaphore(semaphores[269], 1, NULL);
SetEvent(events[499]);
SetEvent(events[798]);
SetEvent(events[424]);
ReleaseSemaphore(semaphores[44], 1, NULL);
}
}
void WINAPI Thread_21(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[428], INFINITE);
WaitForSingleObject(events[411], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[224], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[213], 4, NULL);
ReleaseSemaphore(semaphores[174], 1, NULL);
SetEvent(events[687]);
SetEvent(events[887]);
SetEvent(events[405]);
} else {
WaitForSingleObject(events[87], INFINITE);
// bad checks done
SetEvent(events[140]);
ReleaseSemaphore(semaphores[96], 4, NULL);
SetEvent(events[150]);
ReleaseSemaphore(semaphores[270], 4, NULL);
SetEvent(events[78]);
SetEvent(events[904]);
SetEvent(events[724]);
ReleaseSemaphore(semaphores[241], 1, NULL);
}
}
void WINAPI Thread_22(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[35], INFINITE);
WaitForSingleObject(events[830], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[69], INFINITE);
}
// good checks done
SetEvent(events[238]);
ReleaseSemaphore(semaphores[161], 1, NULL);
ReleaseSemaphore(semaphores[231], 3, NULL);
SetEvent(events[496]);
SetEvent(events[374]);
SetEvent(events[446]);
SetEvent(events[457]);
ReleaseSemaphore(semaphores[99], 1, NULL);
} else {
WaitForSingleObject(events[188], INFINITE);
WaitForSingleObject(events[301], INFINITE);
WaitForSingleObject(events[766], INFINITE);
WaitForSingleObject(events[728], INFINITE);
WaitForSingleObject(events[151], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[69], INFINITE);
}
// bad checks done
SetEvent(events[46]);
ReleaseSemaphore(semaphores[85], 4, NULL);
SetEvent(events[177]);
ReleaseSemaphore(semaphores[194], 1, NULL);
SetEvent(events[768]);
SetEvent(events[103]);
SetEvent(events[659]);
ReleaseSemaphore(semaphores[110], 1, NULL);
ReleaseSemaphore(semaphores[59], 2, NULL);
}
}
void WINAPI Thread_23(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[707], INFINITE);
WaitForSingleObject(events[871], INFINITE);
WaitForSingleObject(events[955], INFINITE);
// bad checks done
SetEvent(events[899]);
ReleaseSemaphore(semaphores[75], 2, NULL);
SetEvent(events[547]);
SetEvent(events[655]);
SetEvent(events[627]);
ReleaseSemaphore(semaphores[89], 4, NULL);
SetEvent(events[210]);
ReleaseSemaphore(semaphores[280], 4, NULL);
} else {
// good checks done
ReleaseSemaphore(semaphores[130], 3, NULL);
ReleaseSemaphore(semaphores[65], 2, NULL);
ReleaseSemaphore(semaphores[172], 4, NULL);
SetEvent(events[46]);
}
}
void WINAPI Thread_24(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[655], INFINITE);
WaitForSingleObject(events[444], INFINITE);
for (i = 0; i < 24; i++) {
    WaitForSingleObject(semaphores[54], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[131], 1, NULL);
ReleaseSemaphore(semaphores[10], 1, NULL);
SetEvent(events[485]);
ReleaseSemaphore(semaphores[170], 1, NULL);
ReleaseSemaphore(semaphores[300], 1, NULL);
SetEvent(events[870]);
ReleaseSemaphore(semaphores[29], 1, NULL);
SetEvent(events[805]);
ReleaseSemaphore(semaphores[48], 3, NULL);
} else {
WaitForSingleObject(events[283], INFINITE);
WaitForSingleObject(events[707], INFINITE);
WaitForSingleObject(events[375], INFINITE);
WaitForSingleObject(events[301], INFINITE);
WaitForSingleObject(events[856], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[54], INFINITE);
}
// bad checks done
SetEvent(events[708]);
SetEvent(events[791]);
SetEvent(events[142]);
SetEvent(events[522]);
SetEvent(events[779]);
}
}
void WINAPI Thread_25(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[919], INFINITE);
WaitForSingleObject(events[714], INFINITE);
WaitForSingleObject(events[550], INFINITE);
WaitForSingleObject(events[682], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[129], INFINITE);
}
// bad checks done
SetEvent(events[64]);
SetEvent(events[848]);
SetEvent(events[776]);
} else {
WaitForSingleObject(events[516], INFINITE);
WaitForSingleObject(events[393], INFINITE);
WaitForSingleObject(events[607], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[129], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[239], 4, NULL);
}
}
void WINAPI Thread_26(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1004], INFINITE);
WaitForSingleObject(events[802], INFINITE);
WaitForSingleObject(events[931], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[156], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 2, NULL);
ReleaseSemaphore(semaphores[161], 1, NULL);
SetEvent(events[23]);
SetEvent(events[233]);
ReleaseSemaphore(semaphores[231], 1, NULL);
ReleaseSemaphore(semaphores[229], 2, NULL);
SetEvent(events[672]);
SetEvent(events[525]);
SetEvent(events[867]);
} else {
WaitForSingleObject(events[162], INFINITE);
WaitForSingleObject(events[577], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[156], INFINITE);
}
// bad checks done
SetEvent(events[366]);
ReleaseSemaphore(semaphores[63], 3, NULL);
ReleaseSemaphore(semaphores[20], 4, NULL);
}
}
void WINAPI Thread_27(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[874], INFINITE);
WaitForSingleObject(events[1023], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[132], INFINITE);
}
// bad checks done
SetEvent(events[268]);
SetEvent(events[493]);
SetEvent(events[193]);
ReleaseSemaphore(semaphores[23], 4, NULL);
} else {
WaitForSingleObject(events[327], INFINITE);
WaitForSingleObject(events[266], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[132], INFINITE);
}
// good checks done
SetEvent(events[666]);
ReleaseSemaphore(semaphores[214], 3, NULL);
ReleaseSemaphore(semaphores[269], 4, NULL);
ReleaseSemaphore(semaphores[224], 3, NULL);
SetEvent(events[510]);
SetEvent(events[608]);
SetEvent(events[473]);
ReleaseSemaphore(semaphores[194], 2, NULL);
}
}
void WINAPI Thread_28(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[987], INFINITE);
WaitForSingleObject(events[429], INFINITE);
WaitForSingleObject(events[746], INFINITE);
WaitForSingleObject(events[78], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[22], INFINITE);
}
// bad checks done
SetEvent(events[677]);
SetEvent(events[568]);
SetEvent(events[367]);
} else {
WaitForSingleObject(events[772], INFINITE);
WaitForSingleObject(events[162], INFINITE);
WaitForSingleObject(events[124], INFINITE);
for (i = 0; i < 29; i++) {
    WaitForSingleObject(semaphores[22], INFINITE);
}
// good checks done
SetEvent(events[321]);
ReleaseSemaphore(semaphores[189], 4, NULL);
ReleaseSemaphore(semaphores[239], 3, NULL);
}
}
void WINAPI Thread_29(int bit) {
int i = 0;
if (bit) {
// good checks done
ReleaseSemaphore(semaphores[222], 2, NULL);
SetEvent(events[349]);
SetEvent(events[315]);
} else {
WaitForSingleObject(events[870], INFINITE);
WaitForSingleObject(events[966], INFINITE);
WaitForSingleObject(events[911], INFINITE);
WaitForSingleObject(events[380], INFINITE);
WaitForSingleObject(events[540], INFINITE);
// bad checks done
SetEvent(events[717]);
ReleaseSemaphore(semaphores[226], 1, NULL);
}
}
void WINAPI Thread_30(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[952], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[87], INFINITE);
}
// good checks done
} else {
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[87], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[295], 2, NULL);
ReleaseSemaphore(semaphores[296], 1, NULL);
SetEvent(events[1009]);
SetEvent(events[281]);
ReleaseSemaphore(semaphores[65], 4, NULL);
SetEvent(events[755]);
SetEvent(events[604]);
SetEvent(events[348]);
ReleaseSemaphore(semaphores[64], 3, NULL);
}
}
void WINAPI Thread_31(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[887], INFINITE);
WaitForSingleObject(events[402], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[269], INFINITE);
}
// bad checks done
SetEvent(events[995]);
ReleaseSemaphore(semaphores[210], 1, NULL);
SetEvent(events[504]);
ReleaseSemaphore(semaphores[29], 4, NULL);
} else {
WaitForSingleObject(events[505], INFINITE);
WaitForSingleObject(events[244], INFINITE);
WaitForSingleObject(events[980], INFINITE);
WaitForSingleObject(events[585], INFINITE);
WaitForSingleObject(events[223], INFINITE);
WaitForSingleObject(events[562], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[269], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 2, NULL);
ReleaseSemaphore(semaphores[209], 1, NULL);
SetEvent(events[1017]);
SetEvent(events[818]);
SetEvent(events[148]);
}
}
void WINAPI Thread_32(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[357], INFINITE);
WaitForSingleObject(events[323], INFINITE);
WaitForSingleObject(events[155], INFINITE);
WaitForSingleObject(events[515], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[171], INFINITE);
}
// good checks done
SetEvent(events[1015]);
ReleaseSemaphore(semaphores[20], 2, NULL);
ReleaseSemaphore(semaphores[170], 3, NULL);
ReleaseSemaphore(semaphores[70], 3, NULL);
ReleaseSemaphore(semaphores[262], 3, NULL);
SetEvent(events[120]);
} else {
WaitForSingleObject(events[425], INFINITE);
WaitForSingleObject(events[955], INFINITE);
WaitForSingleObject(events[117], INFINITE);
WaitForSingleObject(events[1013], INFINITE);
WaitForSingleObject(events[191], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[171], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[31], 4, NULL);
}
}
void WINAPI Thread_33(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[835], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[48], INFINITE);
}
// bad checks done
SetEvent(events[958]);
SetEvent(events[572]);
SetEvent(events[1025]);
ReleaseSemaphore(semaphores[161], 2, NULL);
SetEvent(events[419]);
ReleaseSemaphore(semaphores[270], 4, NULL);
ReleaseSemaphore(semaphores[131], 4, NULL);
SetEvent(events[399]);
ReleaseSemaphore(semaphores[119], 3, NULL);
ReleaseSemaphore(semaphores[100], 2, NULL);
} else {
WaitForSingleObject(events[365], INFINITE);
WaitForSingleObject(events[935], INFINITE);
WaitForSingleObject(events[514], INFINITE);
WaitForSingleObject(events[314], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[48], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[91], 3, NULL);
ReleaseSemaphore(semaphores[89], 2, NULL);
ReleaseSemaphore(semaphores[277], 3, NULL);
ReleaseSemaphore(semaphores[272], 1, NULL);
SetEvent(events[487]);
ReleaseSemaphore(semaphores[75], 2, NULL);
}
}
void WINAPI Thread_34(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[906], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[238], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[233], 2, NULL);
ReleaseSemaphore(semaphores[126], 3, NULL);
ReleaseSemaphore(semaphores[178], 3, NULL);
SetEvent(events[857]);
ReleaseSemaphore(semaphores[134], 4, NULL);
ReleaseSemaphore(semaphores[107], 1, NULL);
ReleaseSemaphore(semaphores[252], 3, NULL);
SetEvent(events[531]);
SetEvent(events[778]);
SetEvent(events[976]);
ReleaseSemaphore(semaphores[146], 2, NULL);
SetEvent(events[144]);
} else {
WaitForSingleObject(events[391], INFINITE);
WaitForSingleObject(events[884], INFINITE);
WaitForSingleObject(events[721], INFINITE);
WaitForSingleObject(events[292], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[238], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[48], 2, NULL);
SetEvent(events[91]);
ReleaseSemaphore(semaphores[175], 4, NULL);
}
}
void WINAPI Thread_35(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[856], INFINITE);
WaitForSingleObject(events[646], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[19], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[9], 1, NULL);
ReleaseSemaphore(semaphores[77], 2, NULL);
ReleaseSemaphore(semaphores[126], 3, NULL);
SetEvent(events[362]);
SetEvent(events[226]);
SetEvent(events[1000]);
ReleaseSemaphore(semaphores[107], 4, NULL);
ReleaseSemaphore(semaphores[27], 3, NULL);
ReleaseSemaphore(semaphores[197], 4, NULL);
} else {
WaitForSingleObject(events[729], INFINITE);
WaitForSingleObject(events[339], INFINITE);
WaitForSingleObject(events[857], INFINITE);
WaitForSingleObject(events[565], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[19], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[236], 3, NULL);
SetEvent(events[230]);
ReleaseSemaphore(semaphores[259], 3, NULL);
SetEvent(events[898]);
SetEvent(events[253]);
SetEvent(events[278]);
SetEvent(events[375]);
}
}
void WINAPI Thread_36(int bit) {
int i = 0;
if (bit) {
// bad checks done
ReleaseSemaphore(semaphores[163], 3, NULL);
ReleaseSemaphore(semaphores[46], 3, NULL);
ReleaseSemaphore(semaphores[251], 3, NULL);
ReleaseSemaphore(semaphores[250], 2, NULL);
SetEvent(events[608]);
} else {
// good checks done
ReleaseSemaphore(semaphores[181], 4, NULL);
SetEvent(events[417]);
SetEvent(events[174]);
}
}
void WINAPI Thread_37(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[763], INFINITE);
WaitForSingleObject(events[517], INFINITE);
WaitForSingleObject(events[849], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[116], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 1, NULL);
ReleaseSemaphore(semaphores[213], 3, NULL);
ReleaseSemaphore(semaphores[281], 3, NULL);
SetEvent(events[168]);
ReleaseSemaphore(semaphores[84], 3, NULL);
ReleaseSemaphore(semaphores[8], 3, NULL);
SetEvent(events[225]);
} else {
WaitForSingleObject(events[830], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[116], INFINITE);
}
// bad checks done
SetEvent(events[346]);
ReleaseSemaphore(semaphores[238], 2, NULL);
SetEvent(events[577]);
ReleaseSemaphore(semaphores[146], 1, NULL);
ReleaseSemaphore(semaphores[160], 4, NULL);
}
}
void WINAPI Thread_38(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[990], INFINITE);
WaitForSingleObject(events[300], INFINITE);
WaitForSingleObject(events[539], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[211], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[85], 2, NULL);
ReleaseSemaphore(semaphores[299], 3, NULL);
ReleaseSemaphore(semaphores[300], 2, NULL);
ReleaseSemaphore(semaphores[67], 2, NULL);
SetEvent(events[552]);
ReleaseSemaphore(semaphores[247], 1, NULL);
SetEvent(events[70]);
} else {
WaitForSingleObject(events[793], INFINITE);
WaitForSingleObject(events[230], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[211], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[239], 1, NULL);
SetEvent(events[625]);
ReleaseSemaphore(semaphores[3], 4, NULL);
SetEvent(events[67]);
ReleaseSemaphore(semaphores[197], 4, NULL);
ReleaseSemaphore(semaphores[154], 2, NULL);
ReleaseSemaphore(semaphores[134], 1, NULL);
}
}
void WINAPI Thread_39(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[408], INFINITE);
WaitForSingleObject(events[868], INFINITE);
WaitForSingleObject(events[939], INFINITE);
WaitForSingleObject(events[624], INFINITE);
WaitForSingleObject(events[80], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[1], INFINITE);
}
// bad checks done
SetEvent(events[513]);
SetEvent(events[811]);
SetEvent(events[300]);
} else {
WaitForSingleObject(events[44], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[1], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[213], 3, NULL);
SetEvent(events[605]);
SetEvent(events[454]);
SetEvent(events[5]);
SetEvent(events[371]);
ReleaseSemaphore(semaphores[149], 2, NULL);
}
}
void WINAPI Thread_40(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[720], INFINITE);
WaitForSingleObject(events[262], INFINITE);
WaitForSingleObject(events[551], INFINITE);
WaitForSingleObject(events[907], INFINITE);
WaitForSingleObject(events[908], INFINITE);
WaitForSingleObject(events[175], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[68], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 3, NULL);
ReleaseSemaphore(semaphores[244], 2, NULL);
SetEvent(events[527]);
ReleaseSemaphore(semaphores[116], 3, NULL);
ReleaseSemaphore(semaphores[287], 4, NULL);
ReleaseSemaphore(semaphores[224], 1, NULL);
SetEvent(events[17]);
ReleaseSemaphore(semaphores[278], 4, NULL);
ReleaseSemaphore(semaphores[242], 4, NULL);
SetEvent(events[971]);
} else {
WaitForSingleObject(events[626], INFINITE);
WaitForSingleObject(events[316], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[68], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[267], 3, NULL);
ReleaseSemaphore(semaphores[178], 2, NULL);
ReleaseSemaphore(semaphores[173], 4, NULL);
SetEvent(events[928]);
SetEvent(events[748]);
}
}
void WINAPI Thread_41(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[143], INFINITE);
WaitForSingleObject(events[494], INFINITE);
WaitForSingleObject(events[951], INFINITE);
WaitForSingleObject(events[554], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[83], INFINITE);
}
// good checks done
SetEvent(events[596]);
ReleaseSemaphore(semaphores[51], 3, NULL);
SetEvent(events[916]);
ReleaseSemaphore(semaphores[175], 4, NULL);
ReleaseSemaphore(semaphores[98], 2, NULL);
SetEvent(events[88]);
ReleaseSemaphore(semaphores[165], 3, NULL);
SetEvent(events[615]);
ReleaseSemaphore(semaphores[182], 1, NULL);
ReleaseSemaphore(semaphores[184], 2, NULL);
} else {
WaitForSingleObject(events[1026], INFINITE);
WaitForSingleObject(events[762], INFINITE);
WaitForSingleObject(events[71], INFINITE);
WaitForSingleObject(events[181], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[83], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[201], 3, NULL);
ReleaseSemaphore(semaphores[72], 4, NULL);
SetEvent(events[288]);
ReleaseSemaphore(semaphores[117], 2, NULL);
SetEvent(events[837]);
SetEvent(events[691]);
}
}
void WINAPI Thread_42(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[617], INFINITE);
WaitForSingleObject(events[984], INFINITE);
WaitForSingleObject(events[329], INFINITE);
WaitForSingleObject(events[889], INFINITE);
WaitForSingleObject(events[379], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[222], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[105], 3, NULL);
ReleaseSemaphore(semaphores[65], 3, NULL);
ReleaseSemaphore(semaphores[221], 4, NULL);
ReleaseSemaphore(semaphores[199], 1, NULL);
SetEvent(events[19]);
} else {
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[222], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[39], 3, NULL);
SetEvent(events[863]);
SetEvent(events[83]);
ReleaseSemaphore(semaphores[108], 2, NULL);
ReleaseSemaphore(semaphores[295], 1, NULL);
SetEvent(events[899]);
SetEvent(events[353]);
SetEvent(events[895]);
ReleaseSemaphore(semaphores[145], 2, NULL);
SetEvent(events[305]);
SetEvent(events[143]);
}
}
void WINAPI Thread_43(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[305], INFINITE);
WaitForSingleObject(events[90], INFINITE);
WaitForSingleObject(events[10], INFINITE);
// good checks done
ReleaseSemaphore(semaphores[18], 2, NULL);
SetEvent(events[681]);
ReleaseSemaphore(semaphores[216], 4, NULL);
SetEvent(events[107]);
SetEvent(events[130]);
SetEvent(events[16]);
SetEvent(events[215]);
} else {
// bad checks done
ReleaseSemaphore(semaphores[50], 2, NULL);
ReleaseSemaphore(semaphores[15], 3, NULL);
ReleaseSemaphore(semaphores[103], 1, NULL);
ReleaseSemaphore(semaphores[20], 2, NULL);
ReleaseSemaphore(semaphores[60], 2, NULL);
}
}
void WINAPI Thread_44(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[74], INFINITE);
WaitForSingleObject(events[600], INFINITE);
WaitForSingleObject(events[434], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[176], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[84], 2, NULL);
ReleaseSemaphore(semaphores[225], 2, NULL);
ReleaseSemaphore(semaphores[6], 4, NULL);
} else {
WaitForSingleObject(events[993], INFINITE);
WaitForSingleObject(events[567], INFINITE);
WaitForSingleObject(events[799], INFINITE);
WaitForSingleObject(events[235], INFINITE);
WaitForSingleObject(events[68], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[176], INFINITE);
}
// bad checks done
SetEvent(events[436]);
ReleaseSemaphore(semaphores[83], 4, NULL);
ReleaseSemaphore(semaphores[116], 3, NULL);
SetEvent(events[299]);
ReleaseSemaphore(semaphores[187], 3, NULL);
ReleaseSemaphore(semaphores[13], 1, NULL);
SetEvent(events[713]);
}
}
void WINAPI Thread_45(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[435], INFINITE);
WaitForSingleObject(events[25], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[110], INFINITE);
}
// good checks done
SetEvent(events[209]);
ReleaseSemaphore(semaphores[38], 1, NULL);
ReleaseSemaphore(semaphores[214], 2, NULL);
ReleaseSemaphore(semaphores[12], 2, NULL);
ReleaseSemaphore(semaphores[109], 4, NULL);
ReleaseSemaphore(semaphores[179], 2, NULL);
ReleaseSemaphore(semaphores[116], 1, NULL);
SetEvent(events[133]);
SetEvent(events[797]);
SetEvent(events[943]);
ReleaseSemaphore(semaphores[249], 4, NULL);
} else {
WaitForSingleObject(events[336], INFINITE);
WaitForSingleObject(events[850], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[110], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[249], 3, NULL);
}
}
void WINAPI Thread_46(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[752], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[145], INFINITE);
}
// good checks done
SetEvent(events[441]);
SetEvent(events[914]);
ReleaseSemaphore(semaphores[51], 1, NULL);
SetEvent(events[99]);
ReleaseSemaphore(semaphores[175], 2, NULL);
SetEvent(events[698]);
SetEvent(events[939]);
} else {
WaitForSingleObject(events[24], INFINITE);
WaitForSingleObject(events[602], INFINITE);
WaitForSingleObject(events[587], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[145], INFINITE);
}
// bad checks done
SetEvent(events[973]);
ReleaseSemaphore(semaphores[178], 3, NULL);
ReleaseSemaphore(semaphores[194], 3, NULL);
SetEvent(events[850]);
ReleaseSemaphore(semaphores[24], 1, NULL);
SetEvent(events[387]);
SetEvent(events[762]);
}
}
void WINAPI Thread_47(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[196], INFINITE);
WaitForSingleObject(events[173], INFINITE);
WaitForSingleObject(events[581], INFINITE);
WaitForSingleObject(events[348], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[164], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[148], 3, NULL);
} else {
WaitForSingleObject(events[598], INFINITE);
WaitForSingleObject(events[329], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[164], INFINITE);
}
// good checks done
SetEvent(events[37]);
SetEvent(events[351]);
SetEvent(events[172]);
ReleaseSemaphore(semaphores[38], 4, NULL);
SetEvent(events[980]);
SetEvent(events[27]);
ReleaseSemaphore(semaphores[210], 3, NULL);
ReleaseSemaphore(semaphores[1], 3, NULL);
ReleaseSemaphore(semaphores[287], 1, NULL);
SetEvent(events[205]);
ReleaseSemaphore(semaphores[224], 1, NULL);
ReleaseSemaphore(semaphores[278], 2, NULL);
ReleaseSemaphore(semaphores[245], 3, NULL);
SetEvent(events[713]);
SetEvent(events[838]);
}
}
void WINAPI Thread_48(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[735], INFINITE);
WaitForSingleObject(events[290], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[300], INFINITE);
}
// bad checks done
SetEvent(events[640]);
SetEvent(events[1005]);
SetEvent(events[75]);
} else {
WaitForSingleObject(events[783], INFINITE);
WaitForSingleObject(events[955], INFINITE);
WaitForSingleObject(events[875], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[300], INFINITE);
}
// good checks done
SetEvent(events[635]);
ReleaseSemaphore(semaphores[137], 4, NULL);
ReleaseSemaphore(semaphores[139], 3, NULL);
ReleaseSemaphore(semaphores[283], 1, NULL);
ReleaseSemaphore(semaphores[272], 3, NULL);
ReleaseSemaphore(semaphores[274], 1, NULL);
SetEvent(events[262]);
}
}
void WINAPI Thread_49(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[95], INFINITE);
WaitForSingleObject(events[185], INFINITE);
WaitForSingleObject(events[251], INFINITE);
WaitForSingleObject(events[166], INFINITE);
WaitForSingleObject(events[237], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[219], INFINITE);
}
// bad checks done
SetEvent(events[783]);
SetEvent(events[836]);
SetEvent(events[676]);
ReleaseSemaphore(semaphores[242], 3, NULL);
SetEvent(events[938]);
SetEvent(events[715]);
} else {
WaitForSingleObject(events[1031], INFINITE);
WaitForSingleObject(events[890], INFINITE);
WaitForSingleObject(events[43], INFINITE);
WaitForSingleObject(events[686], INFINITE);
for (i = 0; i < 23; i++) {
    WaitForSingleObject(semaphores[219], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[91], 3, NULL);
SetEvent(events[182]);
SetEvent(events[394]);
ReleaseSemaphore(semaphores[274], 1, NULL);
ReleaseSemaphore(semaphores[235], 1, NULL);
ReleaseSemaphore(semaphores[100], 1, NULL);
SetEvent(events[581]);
ReleaseSemaphore(semaphores[75], 4, NULL);
ReleaseSemaphore(semaphores[37], 4, NULL);
}
}
void WINAPI Thread_50(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[573], INFINITE);
for (i = 0; i < 24; i++) {
    WaitForSingleObject(semaphores[79], INFINITE);
}
// good checks done
SetEvent(events[334]);
SetEvent(events[308]);
ReleaseSemaphore(semaphores[299], 2, NULL);
ReleaseSemaphore(semaphores[16], 3, NULL);
ReleaseSemaphore(semaphores[212], 1, NULL);
SetEvent(events[836]);
SetEvent(events[426]);
SetEvent(events[668]);
SetEvent(events[890]);
ReleaseSemaphore(semaphores[247], 4, NULL);
ReleaseSemaphore(semaphores[48], 2, NULL);
} else {
WaitForSingleObject(events[834], INFINITE);
WaitForSingleObject(events[1018], INFINITE);
WaitForSingleObject(events[645], INFINITE);
WaitForSingleObject(events[529], INFINITE);
WaitForSingleObject(events[336], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[79], INFINITE);
}
// bad checks done
SetEvent(events[1023]);
SetEvent(events[140]);
SetEvent(events[574]);
ReleaseSemaphore(semaphores[34], 4, NULL);
ReleaseSemaphore(semaphores[218], 4, NULL);
SetEvent(events[798]);
ReleaseSemaphore(semaphores[91], 3, NULL);
ReleaseSemaphore(semaphores[59], 1, NULL);
}
}
void WINAPI Thread_51(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[259], INFINITE);
}
// bad checks done
SetEvent(events[163]);
} else {
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[259], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 4, NULL);
SetEvent(events[230]);
SetEvent(events[851]);
SetEvent(events[281]);
ReleaseSemaphore(semaphores[231], 1, NULL);
SetEvent(events[599]);
ReleaseSemaphore(semaphores[248], 2, NULL);
}
}
void WINAPI Thread_52(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[532], INFINITE);
WaitForSingleObject(events[66], INFINITE);
WaitForSingleObject(events[932], INFINITE);
WaitForSingleObject(events[470], INFINITE);
WaitForSingleObject(events[247], INFINITE);
WaitForSingleObject(events[317], INFINITE);
WaitForSingleObject(events[765], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[227], INFINITE);
}
// good checks done
SetEvent(events[603]);
ReleaseSemaphore(semaphores[49], 2, NULL);
ReleaseSemaphore(semaphores[218], 1, NULL);
ReleaseSemaphore(semaphores[4], 1, NULL);
ReleaseSemaphore(semaphores[300], 4, NULL);
ReleaseSemaphore(semaphores[67], 1, NULL);
ReleaseSemaphore(semaphores[70], 1, NULL);
SetEvent(events[154]);
ReleaseSemaphore(semaphores[36], 3, NULL);
ReleaseSemaphore(semaphores[219], 3, NULL);
SetEvent(events[161]);
SetEvent(events[935]);
} else {
WaitForSingleObject(events[266], INFINITE);
WaitForSingleObject(events[334], INFINITE);
WaitForSingleObject(events[273], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[227], INFINITE);
}
// bad checks done
SetEvent(events[378]);
ReleaseSemaphore(semaphores[153], 2, NULL);
SetEvent(events[812]);
ReleaseSemaphore(semaphores[87], 2, NULL);
SetEvent(events[295]);
ReleaseSemaphore(semaphores[17], 2, NULL);
SetEvent(events[758]);
ReleaseSemaphore(semaphores[78], 1, NULL);
SetEvent(events[51]);
}
}
void WINAPI Thread_53(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[990], INFINITE);
WaitForSingleObject(events[195], INFINITE);
WaitForSingleObject(events[735], INFINITE);
WaitForSingleObject(events[514], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[104], INFINITE);
}
// bad checks done
SetEvent(events[740]);
ReleaseSemaphore(semaphores[247], 2, NULL);
ReleaseSemaphore(semaphores[261], 4, NULL);
ReleaseSemaphore(semaphores[99], 4, NULL);
} else {
WaitForSingleObject(events[275], INFINITE);
WaitForSingleObject(events[476], INFINITE);
WaitForSingleObject(events[439], INFINITE);
WaitForSingleObject(events[319], INFINITE);
WaitForSingleObject(events[545], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[104], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[105], 4, NULL);
ReleaseSemaphore(semaphores[154], 1, NULL);
SetEvent(events[259]);
ReleaseSemaphore(semaphores[41], 4, NULL);
ReleaseSemaphore(semaphores[189], 2, NULL);
ReleaseSemaphore(semaphores[239], 4, NULL);
SetEvent(events[574]);
ReleaseSemaphore(semaphores[58], 4, NULL);
SetEvent(events[118]);
}
}
void WINAPI Thread_54(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[31], INFINITE);
WaitForSingleObject(events[141], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[55], INFINITE);
}
// good checks done
SetEvent(events[765]);
ReleaseSemaphore(semaphores[103], 4, NULL);
SetEvent(events[990]);
SetEvent(events[203]);
SetEvent(events[109]);
ReleaseSemaphore(semaphores[253], 4, NULL);
SetEvent(events[947]);
SetEvent(events[55]);
ReleaseSemaphore(semaphores[173], 4, NULL);
ReleaseSemaphore(semaphores[43], 1, NULL);
ReleaseSemaphore(semaphores[54], 1, NULL);
SetEvent(events[355]);
SetEvent(events[789]);
SetEvent(events[316]);
} else {
WaitForSingleObject(events[891], INFINITE);
WaitForSingleObject(events[217], INFINITE);
// bad checks done
SetEvent(events[739]);
SetEvent(events[426]);
ReleaseSemaphore(semaphores[193], 2, NULL);
ReleaseSemaphore(semaphores[17], 4, NULL);
ReleaseSemaphore(semaphores[216], 4, NULL);
SetEvent(events[435]);
ReleaseSemaphore(semaphores[202], 3, NULL);
ReleaseSemaphore(semaphores[90], 4, NULL);
}
}
void WINAPI Thread_55(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[236], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[43], 1, NULL);
ReleaseSemaphore(semaphores[29], 2, NULL);
} else {
WaitForSingleObject(events[846], INFINITE);
WaitForSingleObject(events[639], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[236], INFINITE);
}
// good checks done
SetEvent(events[1032]);
ReleaseSemaphore(semaphores[77], 4, NULL);
ReleaseSemaphore(semaphores[155], 3, NULL);
ReleaseSemaphore(semaphores[51], 3, NULL);
SetEvent(events[793]);
ReleaseSemaphore(semaphores[223], 4, NULL);
ReleaseSemaphore(semaphores[27], 4, NULL);
SetEvent(events[873]);
ReleaseSemaphore(semaphores[182], 1, NULL);
ReleaseSemaphore(semaphores[258], 1, NULL);
}
}
void WINAPI Thread_56(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[178], INFINITE);
WaitForSingleObject(events[828], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[223], INFINITE);
}
// bad checks done
SetEvent(events[251]);
SetEvent(events[387]);
ReleaseSemaphore(semaphores[280], 2, NULL);
ReleaseSemaphore(semaphores[229], 3, NULL);
ReleaseSemaphore(semaphores[25], 4, NULL);
ReleaseSemaphore(semaphores[41], 3, NULL);
SetEvent(events[379]);
} else {
WaitForSingleObject(events[114], INFINITE);
WaitForSingleObject(events[799], INFINITE);
for (i = 0; i < 25; i++) {
    WaitForSingleObject(semaphores[223], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[103], 3, NULL);
SetEvent(events[509]);
ReleaseSemaphore(semaphores[43], 2, NULL);
ReleaseSemaphore(semaphores[127], 3, NULL);
SetEvent(events[288]);
}
}
void WINAPI Thread_57(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[507], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[288], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[39], 3, NULL);
SetEvent(events[413]);
ReleaseSemaphore(semaphores[188], 4, NULL);
ReleaseSemaphore(semaphores[108], 1, NULL);
ReleaseSemaphore(semaphores[187], 2, NULL);
SetEvent(events[676]);
} else {
WaitForSingleObject(events[575], INFINITE);
WaitForSingleObject(events[157], INFINITE);
WaitForSingleObject(events[704], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[288], INFINITE);
}
// bad checks done
SetEvent(events[529]);
SetEvent(events[834]);
SetEvent(events[916]);
}
}
void WINAPI Thread_58(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[269], INFINITE);
WaitForSingleObject(events[935], INFINITE);
WaitForSingleObject(events[529], INFINITE);
WaitForSingleObject(events[569], INFINITE);
WaitForSingleObject(events[802], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[293], 4, NULL);
ReleaseSemaphore(semaphores[53], 4, NULL);
SetEvent(events[68]);
} else {
WaitForSingleObject(events[903], INFINITE);
WaitForSingleObject(events[715], INFINITE);
WaitForSingleObject(events[125], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[130], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[238], 1, NULL);
SetEvent(events[654]);
SetEvent(events[833]);
SetEvent(events[554]);
}
}
void WINAPI Thread_59(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[14], INFINITE);
WaitForSingleObject(events[166], INFINITE);
WaitForSingleObject(events[224], INFINITE);
WaitForSingleObject(events[903], INFINITE);
WaitForSingleObject(events[444], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[50], INFINITE);
}
// bad checks done
SetEvent(events[137]);
SetEvent(events[475]);
} else {
WaitForSingleObject(events[384], INFINITE);
WaitForSingleObject(events[47], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[50], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[154], 2, NULL);
ReleaseSemaphore(semaphores[226], 1, NULL);
ReleaseSemaphore(semaphores[41], 1, NULL);
ReleaseSemaphore(semaphores[150], 2, NULL);
ReleaseSemaphore(semaphores[166], 4, NULL);
SetEvent(events[137]);
}
}
void WINAPI Thread_60(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[353], INFINITE);
WaitForSingleObject(events[6], INFINITE);
WaitForSingleObject(events[1028], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[82], INFINITE);
}
// good checks done
SetEvent(events[116]);
ReleaseSemaphore(semaphores[233], 3, NULL);
SetEvent(events[396]);
SetEvent(events[412]);
ReleaseSemaphore(semaphores[178], 3, NULL);
SetEvent(events[692]);
ReleaseSemaphore(semaphores[107], 1, NULL);
SetEvent(events[114]);
SetEvent(events[731]);
SetEvent(events[372]);
SetEvent(events[709]);
SetEvent(events[236]);
SetEvent(events[45]);
} else {
WaitForSingleObject(events[908], INFINITE);
WaitForSingleObject(events[574], INFINITE);
WaitForSingleObject(events[67], INFINITE);
WaitForSingleObject(events[852], INFINITE);
WaitForSingleObject(events[781], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[82], INFINITE);
}
// bad checks done
SetEvent(events[1031]);
ReleaseSemaphore(semaphores[166], 4, NULL);
ReleaseSemaphore(semaphores[208], 3, NULL);
SetEvent(events[162]);
SetEvent(events[286]);
ReleaseSemaphore(semaphores[189], 3, NULL);
}
}
void WINAPI Thread_61(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[599], INFINITE);
WaitForSingleObject(events[363], INFINITE);
WaitForSingleObject(events[882], INFINITE);
WaitForSingleObject(events[374], INFINITE);
WaitForSingleObject(events[367], INFINITE);
WaitForSingleObject(events[828], INFINITE);
WaitForSingleObject(events[284], INFINITE);
WaitForSingleObject(events[855], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[159], INFINITE);
}
// good checks done
SetEvent(events[981]);
ReleaseSemaphore(semaphores[154], 1, NULL);
SetEvent(events[934]);
ReleaseSemaphore(semaphores[239], 1, NULL);
} else {
WaitForSingleObject(events[380], INFINITE);
WaitForSingleObject(events[595], INFINITE);
WaitForSingleObject(events[42], INFINITE);
WaitForSingleObject(events[503], INFINITE);
WaitForSingleObject(events[647], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[212], 2, NULL);
ReleaseSemaphore(semaphores[158], 2, NULL);
ReleaseSemaphore(semaphores[232], 1, NULL);
ReleaseSemaphore(semaphores[291], 4, NULL);
}
}
void WINAPI Thread_62(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[660], INFINITE);
WaitForSingleObject(events[610], INFINITE);
WaitForSingleObject(events[136], INFINITE);
WaitForSingleObject(events[490], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[294], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 2, NULL);
ReleaseSemaphore(semaphores[256], 4, NULL);
SetEvent(events[171]);
SetEvent(events[289]);
ReleaseSemaphore(semaphores[269], 3, NULL);
SetEvent(events[170]);
ReleaseSemaphore(semaphores[179], 1, NULL);
SetEvent(events[886]);
SetEvent(events[71]);
SetEvent(events[656]);
SetEvent(events[122]);
SetEvent(events[294]);
SetEvent(events[950]);
SetEvent(events[542]);
ReleaseSemaphore(semaphores[245], 2, NULL);
} else {
WaitForSingleObject(events[549], INFINITE);
WaitForSingleObject(events[621], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[294], INFINITE);
}
// bad checks done
SetEvent(events[755]);
SetEvent(events[370]);
SetEvent(events[861]);
ReleaseSemaphore(semaphores[185], 3, NULL);
SetEvent(events[697]);
ReleaseSemaphore(semaphores[166], 2, NULL);
SetEvent(events[282]);
}
}
void WINAPI Thread_63(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[239], INFINITE);
}
// bad checks done
SetEvent(events[151]);
SetEvent(events[146]);
SetEvent(events[240]);
} else {
WaitForSingleObject(events[722], INFINITE);
WaitForSingleObject(events[824], INFINITE);
for (i = 0; i < 22; i++) {
    WaitForSingleObject(semaphores[239], INFINITE);
}
// good checks done
SetEvent(events[1029]);
SetEvent(events[745]);
}
}
void WINAPI Thread_64(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[386], INFINITE);
WaitForSingleObject(events[661], INFINITE);
WaitForSingleObject(events[904], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[263], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 2, NULL);
ReleaseSemaphore(semaphores[114], 2, NULL);
ReleaseSemaphore(semaphores[289], 3, NULL);
SetEvent(events[383]);
ReleaseSemaphore(semaphores[104], 3, NULL);
SetEvent(events[595]);
ReleaseSemaphore(semaphores[42], 2, NULL);
ReleaseSemaphore(semaphores[159], 1, NULL);
ReleaseSemaphore(semaphores[248], 2, NULL);
ReleaseSemaphore(semaphores[141], 2, NULL);
ReleaseSemaphore(semaphores[46], 2, NULL);
ReleaseSemaphore(semaphores[92], 2, NULL);
} else {
WaitForSingleObject(events[482], INFINITE);
WaitForSingleObject(events[277], INFINITE);
WaitForSingleObject(events[889], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[263], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[112], 3, NULL);
ReleaseSemaphore(semaphores[276], 3, NULL);
ReleaseSemaphore(semaphores[61], 4, NULL);
ReleaseSemaphore(semaphores[125], 3, NULL);
}
}
void WINAPI Thread_65(int bit) {
int i = 0;
if (bit) {
// bad checks done
ReleaseSemaphore(semaphores[95], 2, NULL);
} else {
WaitForSingleObject(events[612], INFINITE);
WaitForSingleObject(events[344], INFINITE);
WaitForSingleObject(events[972], INFINITE);
WaitForSingleObject(events[457], INFINITE);
WaitForSingleObject(events[859], INFINITE);
WaitForSingleObject(events[504], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[240], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[150], 1, NULL);
ReleaseSemaphore(semaphores[166], 3, NULL);
SetEvent(events[380]);
SetEvent(events[211]);
}
}
void WINAPI Thread_66(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[825], INFINITE);
WaitForSingleObject(events[563], INFINITE);
WaitForSingleObject(events[286], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[64], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[152], 4, NULL);
ReleaseSemaphore(semaphores[114], 2, NULL);
} else {
WaitForSingleObject(events[1005], INFINITE);
WaitForSingleObject(events[531], INFINITE);
WaitForSingleObject(events[169], INFINITE);
WaitForSingleObject(events[769], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[64], INFINITE);
}
// good checks done
SetEvent(events[492]);
SetEvent(events[300]);
SetEvent(events[129]);
SetEvent(events[840]);
SetEvent(events[933]);
ReleaseSemaphore(semaphores[253], 2, NULL);
SetEvent(events[591]);
SetEvent(events[194]);
ReleaseSemaphore(semaphores[31], 1, NULL);
ReleaseSemaphore(semaphores[296], 1, NULL);
SetEvent(events[177]);
SetEvent(events[664]);
ReleaseSemaphore(semaphores[171], 2, NULL);
ReleaseSemaphore(semaphores[127], 1, NULL);
ReleaseSemaphore(semaphores[25], 2, NULL);
SetEvent(events[206]);
}
}
void WINAPI Thread_67(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[113], INFINITE);
WaitForSingleObject(events[981], INFINITE);
WaitForSingleObject(events[898], INFINITE);
WaitForSingleObject(events[80], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[105], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[87], 3, NULL);
ReleaseSemaphore(semaphores[122], 2, NULL);
} else {
WaitForSingleObject(events[36], INFINITE);
WaitForSingleObject(events[532], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[105], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[248], 2, NULL);
ReleaseSemaphore(semaphores[133], 2, NULL);
ReleaseSemaphore(semaphores[47], 1, NULL);
SetEvent(events[286]);
SetEvent(events[535]);
}
}
void WINAPI Thread_68(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[511], INFINITE);
WaitForSingleObject(events[62], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[170], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[297], 1, NULL);
SetEvent(events[131]);
SetEvent(events[631]);
ReleaseSemaphore(semaphores[272], 2, NULL);
ReleaseSemaphore(semaphores[274], 3, NULL);
SetEvent(events[610]);
ReleaseSemaphore(semaphores[285], 1, NULL);
ReleaseSemaphore(semaphores[132], 3, NULL);
SetEvent(events[576]);
SetEvent(events[33]);
} else {
WaitForSingleObject(events[643], INFINITE);
WaitForSingleObject(events[937], INFINITE);
WaitForSingleObject(events[609], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[170], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[7], 4, NULL);
ReleaseSemaphore(semaphores[255], 2, NULL);
}
}
void WINAPI Thread_69(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[219], INFINITE);
WaitForSingleObject(events[478], INFINITE);
WaitForSingleObject(events[421], INFINITE);
WaitForSingleObject(events[1023], INFINITE);
WaitForSingleObject(events[670], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[275], INFINITE);
}
// good checks done
SetEvent(events[258]);
SetEvent(events[166]);
ReleaseSemaphore(semaphores[283], 1, NULL);
ReleaseSemaphore(semaphores[272], 4, NULL);
ReleaseSemaphore(semaphores[21], 1, NULL);
SetEvent(events[228]);
ReleaseSemaphore(semaphores[37], 2, NULL);
} else {
WaitForSingleObject(events[843], INFINITE);
WaitForSingleObject(events[112], INFINITE);
WaitForSingleObject(events[18], INFINITE);
WaitForSingleObject(events[139], INFINITE);
WaitForSingleObject(events[373], INFINITE);
// bad checks done
SetEvent(events[173]);
SetEvent(events[576]);
SetEvent(events[418]);
}
}
void WINAPI Thread_70(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[547], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[267], INFINITE);
}
// good checks done
SetEvent(events[56]);
ReleaseSemaphore(semaphores[295], 2, NULL);
SetEvent(events[6]);
SetEvent(events[718]);
ReleaseSemaphore(semaphores[15], 3, NULL);
} else {
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[267], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[99], 3, NULL);
ReleaseSemaphore(semaphores[46], 1, NULL);
ReleaseSemaphore(semaphores[96], 1, NULL);
SetEvent(events[140]);
}
}
void WINAPI Thread_71(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[582], INFINITE);
WaitForSingleObject(events[22], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[63], INFINITE);
}
// bad checks done
SetEvent(events[174]);
SetEvent(events[813]);
ReleaseSemaphore(semaphores[88], 2, NULL);
SetEvent(events[176]);
SetEvent(events[628]);
SetEvent(events[728]);
} else {
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[63], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[39], 1, NULL);
ReleaseSemaphore(semaphores[266], 3, NULL);
ReleaseSemaphore(semaphores[295], 2, NULL);
ReleaseSemaphore(semaphores[234], 1, NULL);
SetEvent(events[912]);
}
}
void WINAPI Thread_72(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[372], INFINITE);
WaitForSingleObject(events[346], INFINITE);
WaitForSingleObject(events[698], INFINITE);
WaitForSingleObject(events[571], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[11], INFINITE);
}
// good checks done
SetEvent(events[317]);
SetEvent(events[806]);
SetEvent(events[847]);
ReleaseSemaphore(semaphores[13], 2, NULL);
SetEvent(events[999]);
ReleaseSemaphore(semaphores[40], 1, NULL);
ReleaseSemaphore(semaphores[71], 1, NULL);
} else {
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[11], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[40], 4, NULL);
}
}
void WINAPI Thread_73(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[116], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[18], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[227], 2, NULL);
ReleaseSemaphore(semaphores[211], 3, NULL);
ReleaseSemaphore(semaphores[56], 2, NULL);
SetEvent(events[682]);
ReleaseSemaphore(semaphores[79], 1, NULL);
SetEvent(events[741]);
SetEvent(events[414]);
ReleaseSemaphore(semaphores[290], 1, NULL);
ReleaseSemaphore(semaphores[25], 1, NULL);
ReleaseSemaphore(semaphores[71], 1, NULL);
} else {
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[18], INFINITE);
}
// bad checks done
SetEvent(events[762]);
ReleaseSemaphore(semaphores[51], 1, NULL);
SetEvent(events[1026]);
SetEvent(events[360]);
SetEvent(events[170]);
SetEvent(events[120]);
ReleaseSemaphore(semaphores[231], 2, NULL);
}
}
void WINAPI Thread_74(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[889], INFINITE);
WaitForSingleObject(events[884], INFINITE);
WaitForSingleObject(events[109], INFINITE);
WaitForSingleObject(events[933], INFINITE);
WaitForSingleObject(events[509], INFINITE);
WaitForSingleObject(events[36], INFINITE);
WaitForSingleObject(events[255], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[113], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[131], 3, NULL);
SetEvent(events[670]);
ReleaseSemaphore(semaphores[49], 1, NULL);
ReleaseSemaphore(semaphores[169], 3, NULL);
ReleaseSemaphore(semaphores[284], 3, NULL);
ReleaseSemaphore(semaphores[4], 3, NULL);
SetEvent(events[714]);
SetEvent(events[348]);
SetEvent(events[328]);
ReleaseSemaphore(semaphores[48], 1, NULL);
} else {
WaitForSingleObject(events[933], INFINITE);
WaitForSingleObject(events[212], INFINITE);
WaitForSingleObject(events[262], INFINITE);
WaitForSingleObject(events[531], INFINITE);
WaitForSingleObject(events[292], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[113], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_75(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[399], INFINITE);
WaitForSingleObject(events[375], INFINITE);
WaitForSingleObject(events[178], INFINITE);
WaitForSingleObject(events[565], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[193], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[91], 1, NULL);
SetEvent(events[738]);
ReleaseSemaphore(semaphores[117], 1, NULL);
ReleaseSemaphore(semaphores[285], 2, NULL);
ReleaseSemaphore(semaphores[132], 3, NULL);
ReleaseSemaphore(semaphores[68], 3, NULL);
ReleaseSemaphore(semaphores[28], 2, NULL);
SetEvent(events[892]);
SetEvent(events[312]);
} else {
WaitForSingleObject(events[904], INFINITE);
WaitForSingleObject(events[525], INFINITE);
WaitForSingleObject(events[479], INFINITE);
// bad checks done
SetEvent(events[80]);
SetEvent(events[967]);
ReleaseSemaphore(semaphores[174], 2, NULL);
SetEvent(events[278]);
ReleaseSemaphore(semaphores[260], 4, NULL);
}
}
void WINAPI Thread_76(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[809], INFINITE);
WaitForSingleObject(events[657], INFINITE);
WaitForSingleObject(events[909], INFINITE);
WaitForSingleObject(events[975], INFINITE);
WaitForSingleObject(events[780], INFINITE);
WaitForSingleObject(events[697], INFINITE);
WaitForSingleObject(events[602], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[248], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[105], 2, NULL);
ReleaseSemaphore(semaphores[41], 3, NULL);
ReleaseSemaphore(semaphores[58], 4, NULL);
ReleaseSemaphore(semaphores[118], 1, NULL);
} else {
WaitForSingleObject(events[765], INFINITE);
WaitForSingleObject(events[288], INFINITE);
WaitForSingleObject(events[534], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[248], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[79], 4, NULL);
ReleaseSemaphore(semaphores[242], 3, NULL);
ReleaseSemaphore(semaphores[72], 2, NULL);
ReleaseSemaphore(semaphores[233], 4, NULL);
ReleaseSemaphore(semaphores[200], 4, NULL);
}
}
void WINAPI Thread_77(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[425], INFINITE);
WaitForSingleObject(events[760], INFINITE);
WaitForSingleObject(events[860], INFINITE);
WaitForSingleObject(events[764], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[33], INFINITE);
}
// bad checks done
SetEvent(events[678]);
ReleaseSemaphore(semaphores[86], 3, NULL);
ReleaseSemaphore(semaphores[278], 3, NULL);
SetEvent(events[190]);
SetEvent(events[979]);
SetEvent(events[757]);
ReleaseSemaphore(semaphores[66], 2, NULL);
SetEvent(events[82]);
} else {
WaitForSingleObject(events[626], INFINITE);
WaitForSingleObject(events[732], INFINITE);
WaitForSingleObject(events[637], INFINITE);
WaitForSingleObject(events[51], INFINITE);
WaitForSingleObject(events[486], INFINITE);
WaitForSingleObject(events[92], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[33], INFINITE);
}
// good checks done
SetEvent(events[82]);
SetEvent(events[771]);
SetEvent(events[751]);
ReleaseSemaphore(semaphores[59], 3, NULL);
SetEvent(events[295]);
SetEvent(events[325]);
}
}
void WINAPI Thread_78(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[723], INFINITE);
WaitForSingleObject(events[728], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[278], INFINITE);
}
// good checks done
SetEvent(events[629]);
ReleaseSemaphore(semaphores[94], 2, NULL);
ReleaseSemaphore(semaphores[6], 1, NULL);
} else {
WaitForSingleObject(events[132], INFINITE);
WaitForSingleObject(events[816], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[278], INFINITE);
}
// bad checks done
SetEvent(events[855]);
SetEvent(events[600]);
SetEvent(events[422]);
SetEvent(events[8]);
}
}
void WINAPI Thread_79(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[825], INFINITE);
WaitForSingleObject(events[652], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[58], INFINITE);
}
// bad checks done
SetEvent(events[97]);
SetEvent(events[137]);
ReleaseSemaphore(semaphores[86], 1, NULL);
SetEvent(events[656]);
ReleaseSemaphore(semaphores[177], 2, NULL);
SetEvent(events[605]);
ReleaseSemaphore(semaphores[38], 1, NULL);
SetEvent(events[371]);
ReleaseSemaphore(semaphores[102], 1, NULL);
} else {
WaitForSingleObject(events[137], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[58], INFINITE);
}
// good checks done
SetEvent(events[746]);
}
}
void WINAPI Thread_80(int bit) {
int i = 0;
if (bit) {
// bad checks done
SetEvent(events[272]);
ReleaseSemaphore(semaphores[99], 3, NULL);
SetEvent(events[777]);
SetEvent(events[553]);
SetEvent(events[487]);
ReleaseSemaphore(semaphores[142], 3, NULL);
} else {
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[202], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[22], 2, NULL);
SetEvent(events[224]);
SetEvent(events[991]);
SetEvent(events[994]);
SetEvent(events[1006]);
ReleaseSemaphore(semaphores[260], 2, NULL);
ReleaseSemaphore(semaphores[207], 2, NULL);
SetEvent(events[780]);
ReleaseSemaphore(semaphores[99], 2, NULL);
}
}
void WINAPI Thread_81(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[65], INFINITE);
WaitForSingleObject(events[491], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[106], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[72], 4, NULL);
SetEvent(events[63]);
SetEvent(events[1004]);
SetEvent(events[189]);
ReleaseSemaphore(semaphores[237], 2, NULL);
ReleaseSemaphore(semaphores[177], 4, NULL);
ReleaseSemaphore(semaphores[191], 3, NULL);
SetEvent(events[106]);
ReleaseSemaphore(semaphores[202], 3, NULL);
} else {
WaitForSingleObject(events[240], INFINITE);
WaitForSingleObject(events[131], INFINITE);
WaitForSingleObject(events[302], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[106], INFINITE);
}
// bad checks done
SetEvent(events[271]);
ReleaseSemaphore(semaphores[13], 3, NULL);
ReleaseSemaphore(semaphores[182], 3, NULL);
}
}
void WINAPI Thread_82(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[206], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[127], INFINITE);
}
// bad checks done
SetEvent(events[356]);
ReleaseSemaphore(semaphores[40], 1, NULL);
SetEvent(events[425]);
SetEvent(events[199]);
ReleaseSemaphore(semaphores[116], 4, NULL);
ReleaseSemaphore(semaphores[90], 3, NULL);
ReleaseSemaphore(semaphores[275], 4, NULL);
SetEvent(events[602]);
ReleaseSemaphore(semaphores[287], 2, NULL);
} else {
WaitForSingleObject(events[557], INFINITE);
WaitForSingleObject(events[176], INFINITE);
WaitForSingleObject(events[29], INFINITE);
WaitForSingleObject(events[789], INFINITE);
WaitForSingleObject(events[928], INFINITE);
WaitForSingleObject(events[711], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[127], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[218], 2, NULL);
SetEvent(events[145]);
ReleaseSemaphore(semaphores[4], 3, NULL);
SetEvent(events[565]);
SetEvent(events[34]);
ReleaseSemaphore(semaphores[219], 3, NULL);
}
}
void WINAPI Thread_83(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[613], INFINITE);
WaitForSingleObject(events[781], INFINITE);
WaitForSingleObject(events[600], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[15], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[220], 4, NULL);
ReleaseSemaphore(semaphores[51], 4, NULL);
ReleaseSemaphore(semaphores[240], 3, NULL);
ReleaseSemaphore(semaphores[42], 4, NULL);
ReleaseSemaphore(semaphores[232], 3, NULL);
} else {
WaitForSingleObject(events[895], INFINITE);
WaitForSingleObject(events[676], INFINITE);
WaitForSingleObject(events[251], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[15], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[18], 3, NULL);
ReleaseSemaphore(semaphores[178], 2, NULL);
ReleaseSemaphore(semaphores[3], 1, NULL);
SetEvent(events[858]);
ReleaseSemaphore(semaphores[158], 3, NULL);
SetEvent(events[103]);
SetEvent(events[1005]);
ReleaseSemaphore(semaphores[98], 2, NULL);
ReleaseSemaphore(semaphores[27], 3, NULL);
ReleaseSemaphore(semaphores[11], 3, NULL);
ReleaseSemaphore(semaphores[146], 4, NULL);
ReleaseSemaphore(semaphores[165], 1, NULL);
SetEvent(events[911]);
ReleaseSemaphore(semaphores[112], 4, NULL);
ReleaseSemaphore(semaphores[55], 1, NULL);
}
}
void WINAPI Thread_84(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[537], INFINITE);
WaitForSingleObject(events[258], INFINITE);
WaitForSingleObject(events[917], INFINITE);
WaitForSingleObject(events[788], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[91], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[152], 4, NULL);
SetEvent(events[1018]);
ReleaseSemaphore(semaphores[176], 1, NULL);
SetEvent(events[244]);
SetEvent(events[1003]);
ReleaseSemaphore(semaphores[210], 2, NULL);
ReleaseSemaphore(semaphores[116], 2, NULL);
SetEvent(events[22]);
ReleaseSemaphore(semaphores[124], 1, NULL);
SetEvent(events[181]);
SetEvent(events[614]);
} else {
WaitForSingleObject(events[635], INFINITE);
WaitForSingleObject(events[16], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[91], INFINITE);
}
// bad checks done
SetEvent(events[245]);
SetEvent(events[938]);
SetEvent(events[790]);
SetEvent(events[367]);
ReleaseSemaphore(semaphores[254], 2, NULL);
}
}
void WINAPI Thread_85(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[733], INFINITE);
WaitForSingleObject(events[962], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[139], INFINITE);
}
// good checks done
SetEvent(events[937]);
ReleaseSemaphore(semaphores[176], 3, NULL);
ReleaseSemaphore(semaphores[214], 3, NULL);
ReleaseSemaphore(semaphores[179], 1, NULL);
SetEvent(events[520]);
SetEvent(events[309]);
ReleaseSemaphore(semaphores[124], 4, NULL);
SetEvent(events[633]);
SetEvent(events[862]);
SetEvent(events[440]);
} else {
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[139], INFINITE);
}
// bad checks done
SetEvent(events[225]);
SetEvent(events[441]);
SetEvent(events[944]);
}
}
void WINAPI Thread_86(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[797], INFINITE);
WaitForSingleObject(events[902], INFINITE);
WaitForSingleObject(events[683], INFINITE);
WaitForSingleObject(events[652], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[71], INFINITE);
}
// bad checks done
SetEvent(events[511]);
ReleaseSemaphore(semaphores[242], 4, NULL);
SetEvent(events[164]);
SetEvent(events[534]);
} else {
WaitForSingleObject(events[206], INFINITE);
WaitForSingleObject(events[153], INFINITE);
WaitForSingleObject(events[442], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[71], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 2, NULL);
SetEvent(events[201]);
ReleaseSemaphore(semaphores[284], 2, NULL);
SetEvent(events[589]);
ReleaseSemaphore(semaphores[201], 2, NULL);
ReleaseSemaphore(semaphores[193], 2, NULL);
ReleaseSemaphore(semaphores[300], 1, NULL);
SetEvent(events[861]);
ReleaseSemaphore(semaphores[16], 2, NULL);
ReleaseSemaphore(semaphores[29], 2, NULL);
SetEvent(events[536]);
ReleaseSemaphore(semaphores[219], 1, NULL);
}
}
void WINAPI Thread_87(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[391], INFINITE);
WaitForSingleObject(events[722], INFINITE);
WaitForSingleObject(events[150], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[247], INFINITE);
}
// bad checks done
SetEvent(events[852]);
SetEvent(events[287]);
SetEvent(events[464]);
SetEvent(events[290]);
SetEvent(events[644]);
} else {
WaitForSingleObject(events[572], INFINITE);
WaitForSingleObject(events[881], INFINITE);
WaitForSingleObject(events[161], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[247], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[47], 1, NULL);
ReleaseSemaphore(semaphores[89], 3, NULL);
SetEvent(events[540]);
ReleaseSemaphore(semaphores[139], 1, NULL);
ReleaseSemaphore(semaphores[164], 1, NULL);
ReleaseSemaphore(semaphores[153], 4, NULL);
SetEvent(events[1021]);
SetEvent(events[660]);
ReleaseSemaphore(semaphores[132], 1, NULL);
SetEvent(events[498]);
SetEvent(events[987]);
SetEvent(events[936]);
ReleaseSemaphore(semaphores[151], 2, NULL);
}
}
void WINAPI Thread_88(int bit) {
int i = 0;
if (bit) {
// good checks done
ReleaseSemaphore(semaphores[222], 1, NULL);
SetEvent(events[601]);
ReleaseSemaphore(semaphores[102], 3, NULL);
ReleaseSemaphore(semaphores[172], 2, NULL);
ReleaseSemaphore(semaphores[232], 2, NULL);
ReleaseSemaphore(semaphores[288], 2, NULL);
SetEvent(events[630]);
} else {
WaitForSingleObject(events[511], INFINITE);
WaitForSingleObject(events[20], INFINITE);
WaitForSingleObject(events[71], INFINITE);
WaitForSingleObject(events[840], INFINITE);
// bad checks done
SetEvent(events[26]);
SetEvent(events[796]);
}
}
void WINAPI Thread_89(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[464], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[258], INFINITE);
}
// good checks done
SetEvent(events[184]);
SetEvent(events[248]);
ReleaseSemaphore(semaphores[31], 1, NULL);
ReleaseSemaphore(semaphores[217], 2, NULL);
SetEvent(events[965]);
SetEvent(events[450]);
SetEvent(events[155]);
SetEvent(events[796]);
SetEvent(events[888]);
SetEvent(events[655]);
SetEvent(events[753]);
ReleaseSemaphore(semaphores[40], 2, NULL);
} else {
WaitForSingleObject(events[757], INFINITE);
WaitForSingleObject(events[795], INFINITE);
WaitForSingleObject(events[613], INFINITE);
WaitForSingleObject(events[234], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[258], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[250], 2, NULL);
ReleaseSemaphore(semaphores[139], 1, NULL);
SetEvent(events[742]);
ReleaseSemaphore(semaphores[200], 1, NULL);
ReleaseSemaphore(semaphores[4], 2, NULL);
}
}
void WINAPI Thread_90(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[192], INFINITE);
WaitForSingleObject(events[241], INFINITE);
WaitForSingleObject(events[64], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[237], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[206], 4, NULL);
ReleaseSemaphore(semaphores[207], 1, NULL);
SetEvent(events[283]);
SetEvent(events[1014]);
ReleaseSemaphore(semaphores[254], 3, NULL);
SetEvent(events[100]);
} else {
WaitForSingleObject(events[642], INFINITE);
WaitForSingleObject(events[690], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[237], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[98], 4, NULL);
ReleaseSemaphore(semaphores[173], 4, NULL);
ReleaseSemaphore(semaphores[18], 2, NULL);
}
}
void WINAPI Thread_91(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[432], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[21], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[152], 4, NULL);
ReleaseSemaphore(semaphores[12], 3, NULL);
SetEvent(events[451]);
ReleaseSemaphore(semaphores[93], 2, NULL);
SetEvent(events[415]);
SetEvent(events[739]);
SetEvent(events[335]);
SetEvent(events[257]);
ReleaseSemaphore(semaphores[279], 4, NULL);
} else {
WaitForSingleObject(events[741], INFINITE);
WaitForSingleObject(events[542], INFINITE);
WaitForSingleObject(events[491], INFINITE);
WaitForSingleObject(events[619], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[21], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[220], 3, NULL);
ReleaseSemaphore(semaphores[102], 4, NULL);
ReleaseSemaphore(semaphores[18], 3, NULL);
}
}
void WINAPI Thread_92(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[102], INFINITE);
WaitForSingleObject(events[312], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[37], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 4, NULL);
ReleaseSemaphore(semaphores[269], 1, NULL);
SetEvent(events[865]);
SetEvent(events[763]);
SetEvent(events[44]);
SetEvent(events[253]);
SetEvent(events[193]);
ReleaseSemaphore(semaphores[279], 3, NULL);
ReleaseSemaphore(semaphores[135], 3, NULL);
ReleaseSemaphore(semaphores[249], 4, NULL);
} else {
WaitForSingleObject(events[273], INFINITE);
WaitForSingleObject(events[432], INFINITE);
WaitForSingleObject(events[591], INFINITE);
WaitForSingleObject(events[649], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[37], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[87], 2, NULL);
ReleaseSemaphore(semaphores[20], 2, NULL);
ReleaseSemaphore(semaphores[239], 1, NULL);
SetEvent(events[303]);
ReleaseSemaphore(semaphores[30], 2, NULL);
ReleaseSemaphore(semaphores[11], 1, NULL);
SetEvent(events[21]);
SetEvent(events[772]);
SetEvent(events[949]);
SetEvent(events[652]);
}
}
void WINAPI Thread_93(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[745], INFINITE);
WaitForSingleObject(events[202], INFINITE);
WaitForSingleObject(events[465], INFINITE);
WaitForSingleObject(events[957], INFINITE);
WaitForSingleObject(events[533], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[121], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[161], 2, NULL);
ReleaseSemaphore(semaphores[227], 3, NULL);
SetEvent(events[864]);
ReleaseSemaphore(semaphores[223], 1, NULL);
ReleaseSemaphore(semaphores[278], 1, NULL);
ReleaseSemaphore(semaphores[197], 1, NULL);
SetEvent(events[329]);
} else {
WaitForSingleObject(events[466], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[121], INFINITE);
}
// good checks done
SetEvent(events[841]);
SetEvent(events[537]);
SetEvent(events[324]);
SetEvent(events[733]);
SetEvent(events[941]);
SetEvent(events[387]);
ReleaseSemaphore(semaphores[272], 2, NULL);
ReleaseSemaphore(semaphores[294], 1, NULL);
}
}
void WINAPI Thread_94(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[186], INFINITE);
WaitForSingleObject(events[296], INFINITE);
WaitForSingleObject(events[636], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[167], INFINITE);
}
// good checks done
SetEvent(events[242]);
ReleaseSemaphore(semaphores[239], 4, NULL);
ReleaseSemaphore(semaphores[118], 1, NULL);
} else {
WaitForSingleObject(events[762], INFINITE);
WaitForSingleObject(events[655], INFINITE);
WaitForSingleObject(events[742], INFINITE);
WaitForSingleObject(events[569], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[167], INFINITE);
}
// bad checks done
SetEvent(events[486]);
SetEvent(events[602]);
SetEvent(events[805]);
SetEvent(events[135]);
SetEvent(events[821]);
}
}
void WINAPI Thread_95(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[331], INFINITE);
WaitForSingleObject(events[499], INFINITE);
WaitForSingleObject(events[724], INFINITE);
WaitForSingleObject(events[397], INFINITE);
WaitForSingleObject(events[31], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[185], INFINITE);
}
// bad checks done
SetEvent(events[521]);
SetEvent(events[328]);
ReleaseSemaphore(semaphores[195], 4, NULL);
SetEvent(events[253]);
SetEvent(events[723]);
ReleaseSemaphore(semaphores[238], 2, NULL);
ReleaseSemaphore(semaphores[72], 3, NULL);
ReleaseSemaphore(semaphores[0], 3, NULL);
ReleaseSemaphore(semaphores[34], 3, NULL);
} else {
WaitForSingleObject(events[264], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[185], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[22], 3, NULL);
SetEvent(events[489]);
ReleaseSemaphore(semaphores[229], 3, NULL);
ReleaseSemaphore(semaphores[206], 2, NULL);
ReleaseSemaphore(semaphores[97], 4, NULL);
ReleaseSemaphore(semaphores[207], 1, NULL);
SetEvent(events[276]);
ReleaseSemaphore(semaphores[99], 4, NULL);
ReleaseSemaphore(semaphores[254], 3, NULL);
}
}
void WINAPI Thread_96(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[377], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[83], 3, NULL);
SetEvent(events[106]);
SetEvent(events[805]);
SetEvent(events[961]);
SetEvent(events[317]);
ReleaseSemaphore(semaphores[64], 2, NULL);
ReleaseSemaphore(semaphores[192], 1, NULL);
ReleaseSemaphore(semaphores[138], 1, NULL);
SetEvent(events[153]);
} else {
// good checks done
ReleaseSemaphore(semaphores[130], 3, NULL);
SetEvent(events[1027]);
ReleaseSemaphore(semaphores[65], 3, NULL);
ReleaseSemaphore(semaphores[288], 1, NULL);
}
}
void WINAPI Thread_97(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[536], INFINITE);
WaitForSingleObject(events[426], INFINITE);
WaitForSingleObject(events[84], INFINITE);
WaitForSingleObject(events[552], INFINITE);
WaitForSingleObject(events[388], INFINITE);
WaitForSingleObject(events[694], INFINITE);
WaitForSingleObject(events[845], INFINITE);
WaitForSingleObject(events[120], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[183], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[89], 1, NULL);
SetEvent(events[188]);
ReleaseSemaphore(semaphores[283], 3, NULL);
ReleaseSemaphore(semaphores[26], 3, NULL);
ReleaseSemaphore(semaphores[153], 1, NULL);
ReleaseSemaphore(semaphores[143], 2, NULL);
SetEvent(events[620]);
SetEvent(events[744]);
ReleaseSemaphore(semaphores[75], 1, NULL);
} else {
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[183], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[15], 2, NULL);
ReleaseSemaphore(semaphores[253], 1, NULL);
}
}
void WINAPI Thread_98(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[538], INFINITE);
WaitForSingleObject(events[803], INFINITE);
WaitForSingleObject(events[129], INFINITE);
WaitForSingleObject(events[839], INFINITE);
WaitForSingleObject(events[11], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[88], INFINITE);
}
// good checks done
SetEvent(events[844]);
ReleaseSemaphore(semaphores[7], 1, NULL);
SetEvent(events[407]);
SetEvent(events[67]);
SetEvent(events[481]);
SetEvent(events[483]);
ReleaseSemaphore(semaphores[193], 1, NULL);
ReleaseSemaphore(semaphores[67], 3, NULL);
ReleaseSemaphore(semaphores[247], 3, NULL);
ReleaseSemaphore(semaphores[119], 3, NULL);
} else {
WaitForSingleObject(events[1000], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[88], INFINITE);
}
// bad checks done
SetEvent(events[788]);
SetEvent(events[536]);
SetEvent(events[831]);
SetEvent(events[723]);
}
}
void WINAPI Thread_99(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[128], INFINITE);
}
// bad checks done
SetEvent(events[323]);
ReleaseSemaphore(semaphores[196], 4, NULL);
SetEvent(events[588]);
ReleaseSemaphore(semaphores[221], 3, NULL);
ReleaseSemaphore(semaphores[273], 2, NULL);
SetEvent(events[733]);
SetEvent(events[609]);
} else {
WaitForSingleObject(events[16], INFINITE);
WaitForSingleObject(events[26], INFINITE);
WaitForSingleObject(events[615], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[128], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[113], 1, NULL);
ReleaseSemaphore(semaphores[79], 4, NULL);
SetEvent(events[146]);
SetEvent(events[463]);
SetEvent(events[998]);
ReleaseSemaphore(semaphores[54], 4, NULL);
ReleaseSemaphore(semaphores[243], 3, NULL);
ReleaseSemaphore(semaphores[25], 4, NULL);
}
}
void WINAPI Thread_100(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[762], INFINITE);
WaitForSingleObject(events[164], INFINITE);
WaitForSingleObject(events[176], INFINITE);
WaitForSingleObject(events[607], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[118], 1, NULL);
SetEvent(events[423]);
} else {
// good checks done
ReleaseSemaphore(semaphores[130], 1, NULL);
SetEvent(events[1013]);
ReleaseSemaphore(semaphores[120], 1, NULL);
SetEvent(events[550]);
}
}
void WINAPI Thread_101(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[361], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[214], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[96], 1, NULL);
ReleaseSemaphore(semaphores[124], 2, NULL);
ReleaseSemaphore(semaphores[62], 4, NULL);
ReleaseSemaphore(semaphores[151], 3, NULL);
ReleaseSemaphore(semaphores[255], 2, NULL);
SetEvent(events[619]);
SetEvent(events[236]);
} else {
WaitForSingleObject(events[785], INFINITE);
WaitForSingleObject(events[217], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[214], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[213], 2, NULL);
SetEvent(events[57]);
ReleaseSemaphore(semaphores[94], 1, NULL);
SetEvent(events[338]);
SetEvent(events[606]);
SetEvent(events[957]);
ReleaseSemaphore(semaphores[203], 1, NULL);
}
}
void WINAPI Thread_102(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[524], INFINITE);
WaitForSingleObject(events[758], INFINITE);
WaitForSingleObject(events[252], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[123], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[292], 4, NULL);
SetEvent(events[354]);
SetEvent(events[301]);
ReleaseSemaphore(semaphores[107], 1, NULL);
ReleaseSemaphore(semaphores[223], 3, NULL);
SetEvent(events[571]);
SetEvent(events[703]);
SetEvent(events[140]);
ReleaseSemaphore(semaphores[197], 3, NULL);
SetEvent(events[848]);
SetEvent(events[141]);
ReleaseSemaphore(semaphores[258], 4, NULL);
} else {
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[123], INFINITE);
}
// bad checks done
SetEvent(events[888]);
ReleaseSemaphore(semaphores[43], 2, NULL);
SetEvent(events[814]);
SetEvent(events[149]);
}
}
void WINAPI Thread_103(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[672], INFINITE);
WaitForSingleObject(events[1003], INFINITE);
WaitForSingleObject(events[758], INFINITE);
WaitForSingleObject(events[952], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[84], INFINITE);
}
// bad checks done
SetEvent(events[335]);
ReleaseSemaphore(semaphores[294], 2, NULL);
SetEvent(events[975]);
ReleaseSemaphore(semaphores[5], 4, NULL);
SetEvent(events[701]);
} else {
WaitForSingleObject(events[553], INFINITE);
WaitForSingleObject(events[21], INFINITE);
WaitForSingleObject(events[212], INFINITE);
WaitForSingleObject(events[761], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[84], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[106], 3, NULL);
ReleaseSemaphore(semaphores[148], 4, NULL);
SetEvent(events[956]);
ReleaseSemaphore(semaphores[111], 3, NULL);
SetEvent(events[164]);
ReleaseSemaphore(semaphores[45], 4, NULL);
ReleaseSemaphore(semaphores[59], 1, NULL);
SetEvent(events[794]);
ReleaseSemaphore(semaphores[80], 2, NULL);
}
}
void WINAPI Thread_104(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[23], INFINITE);
WaitForSingleObject(events[807], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[140], INFINITE);
}
// good checks done
SetEvent(events[986]);
SetEvent(events[97]);
} else {
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[140], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[181], 1, NULL);
ReleaseSemaphore(semaphores[147], 1, NULL);
ReleaseSemaphore(semaphores[280], 4, NULL);
ReleaseSemaphore(semaphores[123], 4, NULL);
ReleaseSemaphore(semaphores[208], 3, NULL);
}
}
void WINAPI Thread_105(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[925], INFINITE);
WaitForSingleObject(events[298], INFINITE);
WaitForSingleObject(events[744], INFINITE);
WaitForSingleObject(events[955], INFINITE);
WaitForSingleObject(events[254], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[152], INFINITE);
}
// bad checks done
SetEvent(events[6]);
ReleaseSemaphore(semaphores[90], 4, NULL);
SetEvent(events[80]);
SetEvent(events[619]);
SetEvent(events[859]);
SetEvent(events[102]);
} else {
WaitForSingleObject(events[37], INFINITE);
WaitForSingleObject(events[341], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[152], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 4, NULL);
ReleaseSemaphore(semaphores[209], 1, NULL);
SetEvent(events[21]);
ReleaseSemaphore(semaphores[268], 4, NULL);
}
}
void WINAPI Thread_106(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[907], INFINITE);
WaitForSingleObject(events[121], INFINITE);
WaitForSingleObject(events[348], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[45], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[40], 3, NULL);
ReleaseSemaphore(semaphores[183], 4, NULL);
SetEvent(events[786]);
SetEvent(events[230]);
SetEvent(events[427]);
SetEvent(events[526]);
} else {
WaitForSingleObject(events[406], INFINITE);
for (i = 0; i < 22; i++) {
    WaitForSingleObject(semaphores[45], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[133], 1, NULL);
SetEvent(events[984]);
SetEvent(events[717]);
SetEvent(events[534]);
ReleaseSemaphore(semaphores[273], 3, NULL);
ReleaseSemaphore(semaphores[24], 2, NULL);
ReleaseSemaphore(semaphores[191], 4, NULL);
ReleaseSemaphore(semaphores[168], 4, NULL);
}
}
void WINAPI Thread_107(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[490], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[276], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[80], 4, NULL);
ReleaseSemaphore(semaphores[177], 3, NULL);
SetEvent(events[1022]);
ReleaseSemaphore(semaphores[92], 1, NULL);
SetEvent(events[1019]);
} else {
WaitForSingleObject(events[94], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[276], INFINITE);
}
// good checks done
SetEvent(events[535]);
SetEvent(events[465]);
ReleaseSemaphore(semaphores[261], 4, NULL);
ReleaseSemaphore(semaphores[42], 1, NULL);
ReleaseSemaphore(semaphores[207], 3, NULL);
ReleaseSemaphore(semaphores[248], 1, NULL);
SetEvent(events[918]);
ReleaseSemaphore(semaphores[240], 2, NULL);
ReleaseSemaphore(semaphores[167], 3, NULL);
SetEvent(events[748]);
ReleaseSemaphore(semaphores[254], 3, NULL);
ReleaseSemaphore(semaphores[92], 3, NULL);
}
}
void WINAPI Thread_108(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[332], INFINITE);
WaitForSingleObject(events[959], INFINITE);
WaitForSingleObject(events[969], INFINITE);
WaitForSingleObject(events[995], INFINITE);
WaitForSingleObject(events[784], INFINITE);
WaitForSingleObject(events[154], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[29], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[277], 4, NULL);
SetEvent(events[95]);
ReleaseSemaphore(semaphores[283], 2, NULL);
SetEvent(events[475]);
SetEvent(events[459]);
ReleaseSemaphore(semaphores[294], 4, NULL);
ReleaseSemaphore(semaphores[37], 2, NULL);
} else {
WaitForSingleObject(events[785], INFINITE);
WaitForSingleObject(events[437], INFINITE);
WaitForSingleObject(events[367], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[29], INFINITE);
}
// bad checks done
SetEvent(events[666]);
SetEvent(events[104]);
SetEvent(events[307]);
ReleaseSemaphore(semaphores[257], 2, NULL);
SetEvent(events[257]);
SetEvent(events[897]);
}
}
void WINAPI Thread_109(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[778], INFINITE);
WaitForSingleObject(events[919], INFINITE);
WaitForSingleObject(events[1026], INFINITE);
// good checks done
SetEvent(events[470]);
ReleaseSemaphore(semaphores[88], 4, NULL);
SetEvent(events[556]);
ReleaseSemaphore(semaphores[81], 4, NULL);
SetEvent(events[429]);
ReleaseSemaphore(semaphores[171], 4, NULL);
SetEvent(events[29]);
ReleaseSemaphore(semaphores[25], 3, NULL);
SetEvent(events[835]);
} else {
WaitForSingleObject(events[976], INFINITE);
WaitForSingleObject(events[293], INFINITE);
WaitForSingleObject(events[978], INFINITE);
WaitForSingleObject(events[635], INFINITE);
WaitForSingleObject(events[1007], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[168], 2, NULL);
SetEvent(events[821]);
}
}
void WINAPI Thread_110(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[17], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[66], INFINITE);
}
// bad checks done
SetEvent(events[896]);
ReleaseSemaphore(semaphores[235], 3, NULL);
} else {
WaitForSingleObject(events[218], INFINITE);
WaitForSingleObject(events[318], INFINITE);
WaitForSingleObject(events[984], INFINITE);
WaitForSingleObject(events[337], INFINITE);
WaitForSingleObject(events[1024], INFINITE);
WaitForSingleObject(events[826], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[66], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[22], 3, NULL);
ReleaseSemaphore(semaphores[161], 3, NULL);
ReleaseSemaphore(semaphores[140], 1, NULL);
ReleaseSemaphore(semaphores[231], 3, NULL);
SetEvent(events[828]);
ReleaseSemaphore(semaphores[246], 4, NULL);
ReleaseSemaphore(semaphores[254], 1, NULL);
}
}
void WINAPI Thread_111(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[126], INFINITE);
WaitForSingleObject(events[780], INFINITE);
WaitForSingleObject(events[540], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[103], INFINITE);
}
// bad checks done
} else {
WaitForSingleObject(events[754], INFINITE);
WaitForSingleObject(events[558], INFINITE);
WaitForSingleObject(events[302], INFINITE);
WaitForSingleObject(events[774], INFINITE);
WaitForSingleObject(events[235], INFINITE);
WaitForSingleObject(events[492], INFINITE);
WaitForSingleObject(events[152], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[103], INFINITE);
}
// good checks done
SetEvent(events[920]);
ReleaseSemaphore(semaphores[85], 1, NULL);
SetEvent(events[219]);
ReleaseSemaphore(semaphores[169], 2, NULL);
ReleaseSemaphore(semaphores[170], 3, NULL);
ReleaseSemaphore(semaphores[201], 3, NULL);
ReleaseSemaphore(semaphores[299], 3, NULL);
ReleaseSemaphore(semaphores[36], 4, NULL);
ReleaseSemaphore(semaphores[119], 3, NULL);
}
}
void WINAPI Thread_112(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[169], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[199], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[267], 2, NULL);
SetEvent(events[733]);
SetEvent(events[504]);
} else {
WaitForSingleObject(events[123], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[199], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[72], 2, NULL);
SetEvent(events[218]);
SetEvent(events[108]);
SetEvent(events[877]);
ReleaseSemaphore(semaphores[298], 3, NULL);
ReleaseSemaphore(semaphores[180], 4, NULL);
SetEvent(events[13]);
ReleaseSemaphore(semaphores[24], 1, NULL);
SetEvent(events[98]);
SetEvent(events[191]);
ReleaseSemaphore(semaphores[125], 2, NULL);
ReleaseSemaphore(semaphores[74], 3, NULL);
}
}
void WINAPI Thread_113(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[971], INFINITE);
WaitForSingleObject(events[838], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[249], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 4, NULL);
ReleaseSemaphore(semaphores[213], 4, NULL);
SetEvent(events[326]);
SetEvent(events[271]);
SetEvent(events[333]);
} else {
WaitForSingleObject(events[139], INFINITE);
WaitForSingleObject(events[771], INFINITE);
// bad checks done
SetEvent(events[903]);
ReleaseSemaphore(semaphores[4], 2, NULL);
ReleaseSemaphore(semaphores[95], 3, NULL);
ReleaseSemaphore(semaphores[182], 1, NULL);
ReleaseSemaphore(semaphores[269], 1, NULL);
}
}
void WINAPI Thread_114(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[672], INFINITE);
WaitForSingleObject(events[918], INFINITE);
WaitForSingleObject(events[24], INFINITE);
WaitForSingleObject(events[276], INFINITE);
WaitForSingleObject(events[779], INFINITE);
WaitForSingleObject(events[369], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[46], INFINITE);
}
// good checks done
SetEvent(events[240]);
ReleaseSemaphore(semaphores[166], 3, NULL);
ReleaseSemaphore(semaphores[58], 2, NULL);
ReleaseSemaphore(semaphores[118], 3, NULL);
} else {
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[46], INFINITE);
}
// bad checks done
SetEvent(events[14]);
ReleaseSemaphore(semaphores[292], 3, NULL);
ReleaseSemaphore(semaphores[177], 1, NULL);
ReleaseSemaphore(semaphores[144], 3, NULL);
ReleaseSemaphore(semaphores[62], 1, NULL);
SetEvent(events[9]);
SetEvent(events[525]);
ReleaseSemaphore(semaphores[207], 4, NULL);
SetEvent(events[145]);
SetEvent(events[443]);
}
}
void WINAPI Thread_115(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[613], INFINITE);
WaitForSingleObject(events[730], INFINITE);
WaitForSingleObject(events[796], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[290], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[85], 3, NULL);
SetEvent(events[879]);
SetEvent(events[291]);
ReleaseSemaphore(semaphores[284], 3, NULL);
ReleaseSemaphore(semaphores[299], 1, NULL);
SetEvent(events[759]);
SetEvent(events[659]);
SetEvent(events[969]);
ReleaseSemaphore(semaphores[36], 1, NULL);
SetEvent(events[462]);
SetEvent(events[883]);
SetEvent(events[845]);
ReleaseSemaphore(semaphores[48], 2, NULL);
} else {
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[290], INFINITE);
}
// bad checks done
SetEvent(events[648]);
ReleaseSemaphore(semaphores[19], 4, NULL);
SetEvent(events[187]);
SetEvent(events[212]);
SetEvent(events[635]);
ReleaseSemaphore(semaphores[101], 4, NULL);
}
}
void WINAPI Thread_116(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[417], INFINITE);
WaitForSingleObject(events[253], INFINITE);
WaitForSingleObject(events[698], INFINITE);
WaitForSingleObject(events[719], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[209], INFINITE);
}
// bad checks done
SetEvent(events[821]);
SetEvent(events[301]);
ReleaseSemaphore(semaphores[191], 4, NULL);
} else {
WaitForSingleObject(events[168], INFINITE);
WaitForSingleObject(events[72], INFINITE);
WaitForSingleObject(events[606], INFINITE);
WaitForSingleObject(events[687], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[209], INFINITE);
}
// good checks done
SetEvent(events[491]);
SetEvent(events[1002]);
SetEvent(events[651]);
}
}
void WINAPI Thread_117(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[227], INFINITE);
WaitForSingleObject(events[835], INFINITE);
WaitForSingleObject(events[237], INFINITE);
WaitForSingleObject(events[60], INFINITE);
WaitForSingleObject(events[640], INFINITE);
WaitForSingleObject(events[938], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[40], INFINITE);
}
// good checks done
SetEvent(events[701]);
SetEvent(events[4]);
SetEvent(events[868]);
SetEvent(events[775]);
ReleaseSemaphore(semaphores[262], 3, NULL);
SetEvent(events[813]);
ReleaseSemaphore(semaphores[219], 1, NULL);
} else {
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[40], INFINITE);
}
// bad checks done
SetEvent(events[155]);
ReleaseSemaphore(semaphores[131], 4, NULL);
SetEvent(events[173]);
SetEvent(events[455]);
ReleaseSemaphore(semaphores[271], 1, NULL);
}
}
void WINAPI Thread_118(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[556], INFINITE);
WaitForSingleObject(events[590], INFINITE);
WaitForSingleObject(events[378], INFINITE);
WaitForSingleObject(events[42], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[271], INFINITE);
}
// good checks done
SetEvent(events[128]);
SetEvent(events[812]);
ReleaseSemaphore(semaphores[49], 2, NULL);
SetEvent(events[110]);
SetEvent(events[783]);
SetEvent(events[548]);
SetEvent(events[735]);
ReleaseSemaphore(semaphores[212], 2, NULL);
} else {
WaitForSingleObject(events[98], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[271], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[166], 2, NULL);
ReleaseSemaphore(semaphores[133], 3, NULL);
ReleaseSemaphore(semaphores[160], 2, NULL);
ReleaseSemaphore(semaphores[197], 1, NULL);
}
}
void WINAPI Thread_119(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[477], INFINITE);
WaitForSingleObject(events[508], INFINITE);
WaitForSingleObject(events[1026], INFINITE);
WaitForSingleObject(events[500], INFINITE);
WaitForSingleObject(events[418], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[224], 4, NULL);
ReleaseSemaphore(semaphores[44], 3, NULL);
ReleaseSemaphore(semaphores[185], 1, NULL);
ReleaseSemaphore(semaphores[283], 2, NULL);
SetEvent(events[977]);
SetEvent(events[97]);
SetEvent(events[317]);
SetEvent(events[838]);
ReleaseSemaphore(semaphores[301], 2, NULL);
SetEvent(events[1027]);
} else {
WaitForSingleObject(events[121], INFINITE);
WaitForSingleObject(events[19], INFINITE);
WaitForSingleObject(events[662], INFINITE);
WaitForSingleObject(events[1020], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[162], INFINITE);
}
// good checks done
SetEvent(events[393]);
ReleaseSemaphore(semaphores[114], 2, NULL);
SetEvent(events[897]);
SetEvent(events[275]);
SetEvent(events[624]);
SetEvent(events[985]);
ReleaseSemaphore(semaphores[260], 1, NULL);
SetEvent(events[389]);
SetEvent(events[293]);
}
}
void WINAPI Thread_120(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[358], INFINITE);
WaitForSingleObject(events[494], INFINITE);
WaitForSingleObject(events[518], INFINITE);
WaitForSingleObject(events[5], INFINITE);
WaitForSingleObject(events[682], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[225], INFINITE);
}
// bad checks done
SetEvent(events[356]);
ReleaseSemaphore(semaphores[135], 2, NULL);
SetEvent(events[400]);
SetEvent(events[967]);
SetEvent(events[696]);
ReleaseSemaphore(semaphores[74], 3, NULL);
ReleaseSemaphore(semaphores[261], 1, NULL);
SetEvent(events[541]);
} else {
WaitForSingleObject(events[818], INFINITE);
WaitForSingleObject(events[887], INFINITE);
WaitForSingleObject(events[395], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[225], INFINITE);
}
// good checks done
SetEvent(events[59]);
SetEvent(events[506]);
SetEvent(events[653]);
SetEvent(events[290]);
SetEvent(events[795]);
ReleaseSemaphore(semaphores[59], 2, NULL);
SetEvent(events[436]);
SetEvent(events[625]);
}
}
void WINAPI Thread_121(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[886], INFINITE);
WaitForSingleObject(events[192], INFINITE);
WaitForSingleObject(events[312], INFINITE);
WaitForSingleObject(events[855], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[178], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[218], 4, NULL);
ReleaseSemaphore(semaphores[177], 2, NULL);
ReleaseSemaphore(semaphores[268], 4, NULL);
SetEvent(events[461]);
SetEvent(events[196]);
ReleaseSemaphore(semaphores[96], 1, NULL);
} else {
WaitForSingleObject(events[273], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[178], INFINITE);
}
// good checks done
SetEvent(events[774]);
ReleaseSemaphore(semaphores[271], 1, NULL);
SetEvent(events[52]);
ReleaseSemaphore(semaphores[253], 4, NULL);
ReleaseSemaphore(semaphores[217], 4, NULL);
SetEvent(events[408]);
ReleaseSemaphore(semaphores[54], 1, NULL);
SetEvent(events[339]);
SetEvent(events[60]);
}
}
void WINAPI Thread_122(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[934], INFINITE);
WaitForSingleObject(events[167], INFINITE);
WaitForSingleObject(events[996], INFINITE);
WaitForSingleObject(events[842], INFINITE);
WaitForSingleObject(events[820], INFINITE);
WaitForSingleObject(events[85], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[41], INFINITE);
}
// good checks done
SetEvent(events[437]);
} else {
WaitForSingleObject(events[833], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[41], INFINITE);
}
// bad checks done
SetEvent(events[231]);
}
}
void WINAPI Thread_123(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1017], INFINITE);
WaitForSingleObject(events[1016], INFINITE);
WaitForSingleObject(events[847], INFINITE);
WaitForSingleObject(events[505], INFINITE);
WaitForSingleObject(events[692], INFINITE);
// bad checks done
SetEvent(events[294]);
ReleaseSemaphore(semaphores[149], 1, NULL);
} else {
WaitForSingleObject(events[1021], INFINITE);
WaitForSingleObject(events[427], INFINITE);
WaitForSingleObject(events[519], INFINITE);
WaitForSingleObject(events[894], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[274], INFINITE);
}
// good checks done
SetEvent(events[117]);
ReleaseSemaphore(semaphores[244], 4, NULL);
ReleaseSemaphore(semaphores[38], 4, NULL);
ReleaseSemaphore(semaphores[12], 1, NULL);
ReleaseSemaphore(semaphores[179], 1, NULL);
SetEvent(events[517]);
ReleaseSemaphore(semaphores[190], 2, NULL);
SetEvent(events[728]);
ReleaseSemaphore(semaphores[124], 1, NULL);
SetEvent(events[147]);
}
}
void WINAPI Thread_124(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[184], INFINITE);
WaitForSingleObject(events[964], INFINITE);
WaitForSingleObject(events[277], INFINITE);
WaitForSingleObject(events[498], INFINITE);
WaitForSingleObject(events[1005], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[277], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[77], 3, NULL);
ReleaseSemaphore(semaphores[171], 3, NULL);
ReleaseSemaphore(semaphores[133], 1, NULL);
ReleaseSemaphore(semaphores[61], 3, NULL);
} else {
WaitForSingleObject(events[324], INFINITE);
WaitForSingleObject(events[397], INFINITE);
WaitForSingleObject(events[540], INFINITE);
WaitForSingleObject(events[555], INFINITE);
WaitForSingleObject(events[182], INFINITE);
WaitForSingleObject(events[188], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[277], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[12], 2, NULL);
ReleaseSemaphore(semaphores[109], 1, NULL);
ReleaseSemaphore(semaphores[179], 2, NULL);
SetEvent(events[716]);
SetEvent(events[737]);
ReleaseSemaphore(semaphores[135], 4, NULL);
ReleaseSemaphore(semaphores[249], 2, NULL);
}
}
void WINAPI Thread_125(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[164], INFINITE);
WaitForSingleObject(events[560], INFINITE);
WaitForSingleObject(events[751], INFINITE);
WaitForSingleObject(events[638], INFINITE);
WaitForSingleObject(events[597], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[95], INFINITE);
}
// good checks done
SetEvent(events[904]);
ReleaseSemaphore(semaphores[259], 4, NULL);
ReleaseSemaphore(semaphores[156], 1, NULL);
ReleaseSemaphore(semaphores[34], 4, NULL);
ReleaseSemaphore(semaphores[76], 3, NULL);
SetEvent(events[19]);
ReleaseSemaphore(semaphores[276], 2, NULL);
SetEvent(events[963]);
ReleaseSemaphore(semaphores[168], 4, NULL);
ReleaseSemaphore(semaphores[74], 3, NULL);
SetEvent(events[830]);
ReleaseSemaphore(semaphores[205], 1, NULL);
} else {
WaitForSingleObject(events[442], INFINITE);
WaitForSingleObject(events[190], INFINITE);
WaitForSingleObject(events[136], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[95], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_126(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[125], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 1, NULL);
ReleaseSemaphore(semaphores[22], 3, NULL);
ReleaseSemaphore(semaphores[161], 4, NULL);
SetEvent(events[807]);
ReleaseSemaphore(semaphores[229], 3, NULL);
ReleaseSemaphore(semaphores[265], 4, NULL);
ReleaseSemaphore(semaphores[260], 3, NULL);
ReleaseSemaphore(semaphores[159], 4, NULL);
} else {
WaitForSingleObject(events[78], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[125], INFINITE);
}
// bad checks done
SetEvent(events[931]);
SetEvent(events[872]);
SetEvent(events[846]);
SetEvent(events[424]);
SetEvent(events[304]);
}
}
void WINAPI Thread_127(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[274], INFINITE);
WaitForSingleObject(events[209], INFINITE);
// bad checks done
SetEvent(events[863]);
ReleaseSemaphore(semaphores[220], 3, NULL);
SetEvent(events[680]);
ReleaseSemaphore(semaphores[161], 4, NULL);
SetEvent(events[720]);
ReleaseSemaphore(semaphores[181], 4, NULL);
SetEvent(events[933]);
SetEvent(events[149]);
ReleaseSemaphore(semaphores[53], 4, NULL);
} else {
WaitForSingleObject(events[570], INFINITE);
WaitForSingleObject(events[166], INFINITE);
WaitForSingleObject(events[394], INFINITE);
WaitForSingleObject(events[95], INFINITE);
WaitForSingleObject(events[131], INFINITE);
for (i = 0; i < 22; i++) {
    WaitForSingleObject(semaphores[270], INFINITE);
}
// good checks done
SetEvent(events[249]);
ReleaseSemaphore(semaphores[214], 1, NULL);
SetEvent(events[585]);
SetEvent(events[915]);
ReleaseSemaphore(semaphores[190], 2, NULL);
SetEvent(events[866]);
}
}
void WINAPI Thread_128(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[349], INFINITE);
WaitForSingleObject(events[601], INFINITE);
WaitForSingleObject(events[1013], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[181], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[266], 3, NULL);
SetEvent(events[559]);
ReleaseSemaphore(semaphores[123], 2, NULL);
ReleaseSemaphore(semaphores[82], 2, NULL);
ReleaseSemaphore(semaphores[200], 4, NULL);
SetEvent(events[639]);
SetEvent(events[646]);
} else {
WaitForSingleObject(events[887], INFINITE);
WaitForSingleObject(events[849], INFINITE);
WaitForSingleObject(events[592], INFINITE);
WaitForSingleObject(events[310], INFINITE);
WaitForSingleObject(events[602], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[181], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[264], 3, NULL);
SetEvent(events[532]);
SetEvent(events[417]);
SetEvent(events[51]);
}
}
void WINAPI Thread_129(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[182], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[253], 3, NULL);
ReleaseSemaphore(semaphores[23], 4, NULL);
SetEvent(events[885]);
ReleaseSemaphore(semaphores[186], 2, NULL);
ReleaseSemaphore(semaphores[173], 3, NULL);
ReleaseSemaphore(semaphores[43], 3, NULL);
ReleaseSemaphore(semaphores[290], 4, NULL);
ReleaseSemaphore(semaphores[0], 1, NULL);
SetEvent(events[569]);
ReleaseSemaphore(semaphores[71], 3, NULL);
} else {
WaitForSingleObject(events[824], INFINITE);
WaitForSingleObject(events[45], INFINITE);
WaitForSingleObject(events[667], INFINITE);
WaitForSingleObject(events[556], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[50], 1, NULL);
ReleaseSemaphore(semaphores[165], 4, NULL);
SetEvent(events[73]);
SetEvent(events[204]);
ReleaseSemaphore(semaphores[39], 4, NULL);
ReleaseSemaphore(semaphores[78], 4, NULL);
SetEvent(events[341]);
}
}
void WINAPI Thread_130(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[922], INFINITE);
WaitForSingleObject(events[559], INFINITE);
// good checks done
ReleaseSemaphore(semaphores[233], 3, NULL);
ReleaseSemaphore(semaphores[292], 4, NULL);
ReleaseSemaphore(semaphores[155], 2, NULL);
SetEvent(events[40]);
ReleaseSemaphore(semaphores[223], 4, NULL);
SetEvent(events[960]);
} else {
WaitForSingleObject(events[450], INFINITE);
WaitForSingleObject(events[475], INFINITE);
// bad checks done
SetEvent(events[904]);
ReleaseSemaphore(semaphores[223], 3, NULL);
ReleaseSemaphore(semaphores[155], 4, NULL);
}
}
void WINAPI Thread_131(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[595], INFINITE);
WaitForSingleObject(events[978], INFINITE);
WaitForSingleObject(events[503], INFINITE);
WaitForSingleObject(events[496], INFINITE);
WaitForSingleObject(events[28], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[265], INFINITE);
}
// good checks done
SetEvent(events[710]);
SetEvent(events[256]);
ReleaseSemaphore(semaphores[239], 1, NULL);
ReleaseSemaphore(semaphores[58], 4, NULL);
} else {
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[265], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[138], 3, NULL);
SetEvent(events[663]);
SetEvent(events[591]);
ReleaseSemaphore(semaphores[84], 3, NULL);
SetEvent(events[416]);
SetEvent(events[492]);
ReleaseSemaphore(semaphores[109], 3, NULL);
ReleaseSemaphore(semaphores[91], 4, NULL);
SetEvent(events[677]);
}
}
void WINAPI Thread_132(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[106], INFINITE);
WaitForSingleObject(events[127], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[196], INFINITE);
}
// good checks done
SetEvent(events[287]);
ReleaseSemaphore(semaphores[22], 2, NULL);
SetEvent(events[528]);
SetEvent(events[320]);
SetEvent(events[663]);
SetEvent(events[786]);
SetEvent(events[896]);
ReleaseSemaphore(semaphores[254], 3, NULL);
ReleaseSemaphore(semaphores[92], 2, NULL);
} else {
WaitForSingleObject(events[695], INFINITE);
WaitForSingleObject(events[106], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[196], INFINITE);
}
// bad checks done
SetEvent(events[1]);
SetEvent(events[372]);
ReleaseSemaphore(semaphores[148], 2, NULL);
ReleaseSemaphore(semaphores[76], 3, NULL);
}
}
void WINAPI Thread_133(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[421], INFINITE);
WaitForSingleObject(events[797], INFINITE);
WaitForSingleObject(events[149], INFINITE);
WaitForSingleObject(events[424], INFINITE);
// bad checks done
SetEvent(events[901]);
SetEvent(events[406]);
ReleaseSemaphore(semaphores[287], 1, NULL);
SetEvent(events[451]);
SetEvent(events[653]);
ReleaseSemaphore(semaphores[255], 2, NULL);
ReleaseSemaphore(semaphores[56], 2, NULL);
ReleaseSemaphore(semaphores[180], 2, NULL);
} else {
// good checks done
SetEvent(events[715]);
SetEvent(events[690]);
SetEvent(events[61]);
SetEvent(events[78]);
ReleaseSemaphore(semaphores[288], 4, NULL);
}
}
void WINAPI Thread_134(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[767], INFINITE);
WaitForSingleObject(events[1011], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[201], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[47], 1, NULL);
ReleaseSemaphore(semaphores[110], 1, NULL);
SetEvent(events[570]);
ReleaseSemaphore(semaphores[153], 3, NULL);
ReleaseSemaphore(semaphores[272], 3, NULL);
ReleaseSemaphore(semaphores[294], 4, NULL);
ReleaseSemaphore(semaphores[68], 4, NULL);
} else {
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[201], INFINITE);
}
// bad checks done
SetEvent(events[663]);
ReleaseSemaphore(semaphores[282], 4, NULL);
ReleaseSemaphore(semaphores[271], 2, NULL);
ReleaseSemaphore(semaphores[105], 3, NULL);
ReleaseSemaphore(semaphores[42], 1, NULL);
ReleaseSemaphore(semaphores[231], 3, NULL);
}
}
void WINAPI Thread_135(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[235], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[212], 4, NULL);
ReleaseSemaphore(semaphores[80], 4, NULL);
SetEvent(events[433]);
ReleaseSemaphore(semaphores[176], 3, NULL);
ReleaseSemaphore(semaphores[123], 2, NULL);
SetEvent(events[832]);
ReleaseSemaphore(semaphores[27], 1, NULL);
SetEvent(events[512]);
SetEvent(events[980]);
SetEvent(events[652]);
} else {
WaitForSingleObject(events[609], INFINITE);
WaitForSingleObject(events[671], INFINITE);
WaitForSingleObject(events[586], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[235], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 1, NULL);
ReleaseSemaphore(semaphores[38], 2, NULL);
ReleaseSemaphore(semaphores[12], 1, NULL);
ReleaseSemaphore(semaphores[157], 3, NULL);
ReleaseSemaphore(semaphores[278], 2, NULL);
SetEvent(events[831]);
}
}
void WINAPI Thread_136(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[409], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[194], 2, NULL);
} else {
WaitForSingleObject(events[682], INFINITE);
WaitForSingleObject(events[806], INFINITE);
WaitForSingleObject(events[52], INFINITE);
WaitForSingleObject(events[840], INFINITE);
WaitForSingleObject(events[101], INFINITE);
WaitForSingleObject(events[452], INFINITE);
WaitForSingleObject(events[924], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[81], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 3, NULL);
SetEvent(events[966]);
SetEvent(events[478]);
ReleaseSemaphore(semaphores[121], 2, NULL);
SetEvent(events[546]);
ReleaseSemaphore(semaphores[20], 1, NULL);
SetEvent(events[541]);
ReleaseSemaphore(semaphores[183], 2, NULL);
SetEvent(events[1031]);
ReleaseSemaphore(semaphores[247], 3, NULL);
}
}
void WINAPI Thread_137(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[459], INFINITE);
WaitForSingleObject(events[527], INFINITE);
WaitForSingleObject(events[402], INFINITE);
WaitForSingleObject(events[648], INFINITE);
WaitForSingleObject(events[300], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[26], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[22], 4, NULL);
} else {
WaitForSingleObject(events[150], INFINITE);
WaitForSingleObject(events[89], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[26], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[244], 4, NULL);
SetEvent(events[582]);
ReleaseSemaphore(semaphores[160], 2, NULL);
ReleaseSemaphore(semaphores[190], 4, NULL);
ReleaseSemaphore(semaphores[124], 4, NULL);
ReleaseSemaphore(semaphores[194], 4, NULL);
SetEvent(events[707]);
ReleaseSemaphore(semaphores[249], 1, NULL);
}
}
void WINAPI Thread_138(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1030], INFINITE);
WaitForSingleObject(events[156], INFINITE);
WaitForSingleObject(events[8], INFINITE);
WaitForSingleObject(events[227], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[42], INFINITE);
}
// bad checks done
SetEvent(events[319]);
SetEvent(events[261]);
SetEvent(events[982]);
SetEvent(events[251]);
ReleaseSemaphore(semaphores[26], 1, NULL);
ReleaseSemaphore(semaphores[243], 1, NULL);
SetEvent(events[160]);
ReleaseSemaphore(semaphores[76], 1, NULL);
} else {
WaitForSingleObject(events[533], INFINITE);
WaitForSingleObject(events[500], INFINITE);
WaitForSingleObject(events[513], INFINITE);
WaitForSingleObject(events[392], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[42], INFINITE);
}
// good checks done
SetEvent(events[254]);
ReleaseSemaphore(semaphores[58], 2, NULL);
}
}
void WINAPI Thread_139(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[199], INFINITE);
WaitForSingleObject(events[645], INFINITE);
WaitForSingleObject(events[801], INFINITE);
WaitForSingleObject(events[966], INFINITE);
WaitForSingleObject(events[138], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[107], INFINITE);
}
// bad checks done
SetEvent(events[802]);
SetEvent(events[865]);
ReleaseSemaphore(semaphores[129], 3, NULL);
ReleaseSemaphore(semaphores[12], 2, NULL);
SetEvent(events[481]);
SetEvent(events[544]);
} else {
WaitForSingleObject(events[760], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[107], INFINITE);
}
// good checks done
SetEvent(events[235]);
SetEvent(events[364]);
ReleaseSemaphore(semaphores[296], 4, NULL);
ReleaseSemaphore(semaphores[13], 2, NULL);
ReleaseSemaphore(semaphores[43], 3, NULL);
ReleaseSemaphore(semaphores[290], 4, NULL);
ReleaseSemaphore(semaphores[0], 1, NULL);
SetEvent(events[928]);
}
}
void WINAPI Thread_140(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[414], INFINITE);
WaitForSingleObject(events[134], INFINITE);
WaitForSingleObject(events[55], INFINITE);
WaitForSingleObject(events[330], INFINITE);
WaitForSingleObject(events[177], INFINITE);
WaitForSingleObject(events[965], INFINITE);
WaitForSingleObject(events[998], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[220], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[85], 4, NULL);
SetEvent(events[14]);
ReleaseSemaphore(semaphores[275], 3, NULL);
ReleaseSemaphore(semaphores[49], 4, NULL);
SetEvent(events[398]);
SetEvent(events[178]);
SetEvent(events[391]);
ReleaseSemaphore(semaphores[228], 2, NULL);
} else {
WaitForSingleObject(events[761], INFINITE);
WaitForSingleObject(events[408], INFINITE);
WaitForSingleObject(events[656], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[220], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[221], 3, NULL);
ReleaseSemaphore(semaphores[146], 1, NULL);
ReleaseSemaphore(semaphores[103], 1, NULL);
ReleaseSemaphore(semaphores[26], 1, NULL);
SetEvent(events[106]);
SetEvent(events[547]);
ReleaseSemaphore(semaphores[105], 2, NULL);
}
}
void WINAPI Thread_141(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[927], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[260], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[226], 4, NULL);
ReleaseSemaphore(semaphores[239], 1, NULL);
SetEvent(events[269]);
ReleaseSemaphore(semaphores[118], 2, NULL);
} else {
WaitForSingleObject(events[316], INFINITE);
WaitForSingleObject(events[911], INFINITE);
WaitForSingleObject(events[598], INFINITE);
WaitForSingleObject(events[932], INFINITE);
// bad checks done
SetEvent(events[710]);
SetEvent(events[223]);
SetEvent(events[455]);
SetEvent(events[381]);
SetEvent(events[764]);
}
}
void WINAPI Thread_142(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[31], INFINITE);
WaitForSingleObject(events[188], INFINITE);
WaitForSingleObject(events[1001], INFINITE);
WaitForSingleObject(events[288], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[195], 3, NULL);
SetEvent(events[516]);
SetEvent(events[576]);
} else {
WaitForSingleObject(events[173], INFINITE);
WaitForSingleObject(events[78], INFINITE);
// good checks done
ReleaseSemaphore(semaphores[163], 2, NULL);
SetEvent(events[876]);
ReleaseSemaphore(semaphores[123], 2, NULL);
ReleaseSemaphore(semaphores[187], 2, NULL);
ReleaseSemaphore(semaphores[145], 3, NULL);
SetEvent(events[856]);
}
}
void WINAPI Thread_143(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[618], INFINITE);
WaitForSingleObject(events[159], INFINITE);
WaitForSingleObject(events[998], INFINITE);
WaitForSingleObject(events[780], INFINITE);
WaitForSingleObject(events[470], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[143], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[215], 2, NULL);
ReleaseSemaphore(semaphores[183], 4, NULL);
SetEvent(events[415]);
} else {
WaitForSingleObject(events[387], INFINITE);
WaitForSingleObject(events[577], INFINITE);
WaitForSingleObject(events[430], INFINITE);
WaitForSingleObject(events[459], INFINITE);
WaitForSingleObject(events[631], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[143], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[152], 2, NULL);
SetEvent(events[685]);
ReleaseSemaphore(semaphores[12], 3, NULL);
SetEvent(events[756]);
SetEvent(events[652]);
SetEvent(events[811]);
ReleaseSemaphore(semaphores[160], 1, NULL);
ReleaseSemaphore(semaphores[208], 2, NULL);
}
}
void WINAPI Thread_144(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[200], INFINITE);
WaitForSingleObject(events[847], INFINITE);
WaitForSingleObject(events[21], INFINITE);
WaitForSingleObject(events[403], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[111], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[254], 3, NULL);
ReleaseSemaphore(semaphores[117], 1, NULL);
ReleaseSemaphore(semaphores[23], 1, NULL);
ReleaseSemaphore(semaphores[86], 1, NULL);
SetEvent(events[390]);
} else {
WaitForSingleObject(events[755], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[111], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[52], 2, NULL);
SetEvent(events[627]);
ReleaseSemaphore(semaphores[5], 2, NULL);
SetEvent(events[705]);
ReleaseSemaphore(semaphores[35], 3, NULL);
SetEvent(events[241]);
ReleaseSemaphore(semaphores[191], 1, NULL);
ReleaseSemaphore(semaphores[196], 3, NULL);
ReleaseSemaphore(semaphores[230], 4, NULL);
ReleaseSemaphore(semaphores[69], 2, NULL);
}
}
void WINAPI Thread_145(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[0], INFINITE);
WaitForSingleObject(events[469], INFINITE);
WaitForSingleObject(events[857], INFINITE);
// bad checks done
SetEvent(events[260]);
SetEvent(events[445]);
SetEvent(events[741]);
SetEvent(events[93]);
ReleaseSemaphore(semaphores[248], 3, NULL);
ReleaseSemaphore(semaphores[107], 3, NULL);
} else {
WaitForSingleObject(events[118], INFINITE);
WaitForSingleObject(events[447], INFINITE);
WaitForSingleObject(events[580], INFINITE);
WaitForSingleObject(events[211], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[118], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[147], 2, NULL);
ReleaseSemaphore(semaphores[14], 4, NULL);
SetEvent(events[87]);
}
}
void WINAPI Thread_146(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1025], INFINITE);
WaitForSingleObject(events[498], INFINITE);
WaitForSingleObject(events[913], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[100], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[244], 3, NULL);
SetEvent(events[223]);
SetEvent(events[274]);
SetEvent(events[948]);
ReleaseSemaphore(semaphores[93], 2, NULL);
SetEvent(events[12]);
ReleaseSemaphore(semaphores[208], 4, NULL);
ReleaseSemaphore(semaphores[278], 1, NULL);
ReleaseSemaphore(semaphores[242], 2, NULL);
ReleaseSemaphore(semaphores[249], 2, NULL);
} else {
WaitForSingleObject(events[429], INFINITE);
WaitForSingleObject(events[197], INFINITE);
WaitForSingleObject(events[539], INFINITE);
WaitForSingleObject(events[975], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[100], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[52], 1, NULL);
ReleaseSemaphore(semaphores[251], 1, NULL);
ReleaseSemaphore(semaphores[97], 2, NULL);
ReleaseSemaphore(semaphores[4], 4, NULL);
ReleaseSemaphore(semaphores[23], 2, NULL);
}
}
void WINAPI Thread_147(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[163], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[112], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[266], 3, NULL);
ReleaseSemaphore(semaphores[33], 1, NULL);
ReleaseSemaphore(semaphores[185], 4, NULL);
ReleaseSemaphore(semaphores[76], 3, NULL);
ReleaseSemaphore(semaphores[100], 1, NULL);
} else {
WaitForSingleObject(events[215], INFINITE);
WaitForSingleObject(events[848], INFINITE);
WaitForSingleObject(events[342], INFINITE);
WaitForSingleObject(events[621], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[112], INFINITE);
}
// good checks done
SetEvent(events[42]);
ReleaseSemaphore(semaphores[81], 4, NULL);
SetEvent(events[946]);
ReleaseSemaphore(semaphores[217], 4, NULL);
ReleaseSemaphore(semaphores[43], 2, NULL);
ReleaseSemaphore(semaphores[290], 4, NULL);
ReleaseSemaphore(semaphores[0], 1, NULL);
SetEvent(events[444]);
ReleaseSemaphore(semaphores[25], 3, NULL);
SetEvent(events[442]);
}
}
void WINAPI Thread_148(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[630], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[250], INFINITE);
}
// good checks done
SetEvent(events[460]);
SetEvent(events[105]);
ReleaseSemaphore(semaphores[73], 3, NULL);
ReleaseSemaphore(semaphores[238], 2, NULL);
ReleaseSemaphore(semaphores[234], 3, NULL);
SetEvent(events[252]);
SetEvent(events[1028]);
SetEvent(events[544]);
ReleaseSemaphore(semaphores[200], 3, NULL);
ReleaseSemaphore(semaphores[236], 2, NULL);
} else {
WaitForSingleObject(events[133], INFINITE);
WaitForSingleObject(events[493], INFINITE);
// bad checks done
SetEvent(events[430]);
ReleaseSemaphore(semaphores[137], 2, NULL);
ReleaseSemaphore(semaphores[248], 4, NULL);
}
}
void WINAPI Thread_149(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[564], INFINITE);
WaitForSingleObject(events[622], INFINITE);
WaitForSingleObject(events[307], INFINITE);
WaitForSingleObject(events[523], INFINITE);
WaitForSingleObject(events[596], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[292], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[227], 2, NULL);
ReleaseSemaphore(semaphores[103], 3, NULL);
SetEvent(events[538]);
ReleaseSemaphore(semaphores[113], 1, NULL);
ReleaseSemaphore(semaphores[79], 1, NULL);
SetEvent(events[279]);
SetEvent(events[376]);
ReleaseSemaphore(semaphores[127], 1, NULL);
ReleaseSemaphore(semaphores[25], 2, NULL);
ReleaseSemaphore(semaphores[71], 2, NULL);
} else {
WaitForSingleObject(events[904], INFINITE);
WaitForSingleObject(events[539], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[292], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[288], 2, NULL);
SetEvent(events[891]);
SetEvent(events[408]);
SetEvent(events[902]);
SetEvent(events[99]);
SetEvent(events[257]);
}
}
void WINAPI Thread_150(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[469], INFINITE);
WaitForSingleObject(events[702], INFINITE);
WaitForSingleObject(events[896], INFINITE);
WaitForSingleObject(events[954], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[141], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[226], 4, NULL);
SetEvent(events[967]);
ReleaseSemaphore(semaphores[215], 2, NULL);
ReleaseSemaphore(semaphores[118], 2, NULL);
} else {
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[141], INFINITE);
}
// bad checks done
SetEvent(events[780]);
SetEvent(events[511]);
SetEvent(events[420]);
SetEvent(events[686]);
}
}
void WINAPI Thread_151(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[556], INFINITE);
WaitForSingleObject(events[800], INFINITE);
WaitForSingleObject(events[139], INFINITE);
WaitForSingleObject(events[654], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[232], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[150], 2, NULL);
ReleaseSemaphore(semaphores[23], 1, NULL);
ReleaseSemaphore(semaphores[111], 1, NULL);
SetEvent(events[477]);
ReleaseSemaphore(semaphores[169], 2, NULL);
SetEvent(events[984]);
SetEvent(events[1015]);
SetEvent(events[1014]);
} else {
WaitForSingleObject(events[46], INFINITE);
WaitForSingleObject(events[417], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[232], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[221], 1, NULL);
SetEvent(events[561]);
ReleaseSemaphore(semaphores[82], 2, NULL);
SetEvent(events[587]);
ReleaseSemaphore(semaphores[236], 4, NULL);
SetEvent(events[90]);
ReleaseSemaphore(semaphores[83], 1, NULL);
}
}
void WINAPI Thread_152(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[235], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[76], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[20], 3, NULL);
ReleaseSemaphore(semaphores[57], 4, NULL);
ReleaseSemaphore(semaphores[56], 1, NULL);
ReleaseSemaphore(semaphores[58], 3, NULL);
} else {
WaitForSingleObject(events[303], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[76], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[140], 3, NULL);
SetEvent(events[319]);
ReleaseSemaphore(semaphores[229], 3, NULL);
ReleaseSemaphore(semaphores[260], 2, NULL);
ReleaseSemaphore(semaphores[97], 2, NULL);
SetEvent(events[282]);
SetEvent(events[779]);
SetEvent(events[504]);
}
}
void WINAPI Thread_153(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[350], INFINITE);
WaitForSingleObject(events[518], INFINITE);
WaitForSingleObject(events[363], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[221], INFINITE);
}
// bad checks done
SetEvent(events[566]);
SetEvent(events[194]);
} else {
WaitForSingleObject(events[431], INFINITE);
WaitForSingleObject(events[413], INFINITE);
WaitForSingleObject(events[680], INFINITE);
WaitForSingleObject(events[905], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[221], INFINITE);
}
// good checks done
SetEvent(events[675]);
ReleaseSemaphore(semaphores[178], 2, NULL);
ReleaseSemaphore(semaphores[216], 4, NULL);
SetEvent(events[760]);
SetEvent(events[769]);
ReleaseSemaphore(semaphores[98], 2, NULL);
SetEvent(events[418]);
SetEvent(events[342]);
SetEvent(events[791]);
ReleaseSemaphore(semaphores[258], 3, NULL);
}
}
void WINAPI Thread_154(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[329], INFINITE);
WaitForSingleObject(events[800], INFINITE);
WaitForSingleObject(events[801], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[266], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[118], 2, NULL);
ReleaseSemaphore(semaphores[243], 1, NULL);
ReleaseSemaphore(semaphores[206], 4, NULL);
ReleaseSemaphore(semaphores[257], 3, NULL);
SetEvent(events[556]);
} else {
WaitForSingleObject(events[863], INFINITE);
WaitForSingleObject(events[781], INFINITE);
WaitForSingleObject(events[617], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[266], INFINITE);
}
// good checks done
SetEvent(events[160]);
SetEvent(events[41]);
ReleaseSemaphore(semaphores[155], 4, NULL);
ReleaseSemaphore(semaphores[216], 3, NULL);
ReleaseSemaphore(semaphores[252], 4, NULL);
ReleaseSemaphore(semaphores[98], 1, NULL);
ReleaseSemaphore(semaphores[223], 1, NULL);
ReleaseSemaphore(semaphores[27], 4, NULL);
ReleaseSemaphore(semaphores[11], 4, NULL);
SetEvent(events[340]);
}
}
void WINAPI Thread_155(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[54], INFINITE);
WaitForSingleObject(events[191], INFINITE);
WaitForSingleObject(events[204], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[168], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 3, NULL);
SetEvent(events[124]);
SetEvent(events[503]);
SetEvent(events[513]);
ReleaseSemaphore(semaphores[97], 1, NULL);
ReleaseSemaphore(semaphores[159], 3, NULL);
ReleaseSemaphore(semaphores[248], 4, NULL);
SetEvent(events[24]);
ReleaseSemaphore(semaphores[99], 2, NULL);
ReleaseSemaphore(semaphores[92], 2, NULL);
} else {
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[168], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[62], 1, NULL);
ReleaseSemaphore(semaphores[236], 4, NULL);
ReleaseSemaphore(semaphores[254], 1, NULL);
SetEvent(events[431]);
ReleaseSemaphore(semaphores[93], 4, NULL);
SetEvent(events[76]);
SetEvent(events[724]);
}
}
void WINAPI Thread_156(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[291], INFINITE);
WaitForSingleObject(events[900], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[198], INFINITE);
}
// bad checks done
SetEvent(events[13]);
ReleaseSemaphore(semaphores[91], 2, NULL);
ReleaseSemaphore(semaphores[253], 2, NULL);
ReleaseSemaphore(semaphores[116], 2, NULL);
ReleaseSemaphore(semaphores[232], 4, NULL);
ReleaseSemaphore(semaphores[149], 1, NULL);
} else {
WaitForSingleObject(events[63], INFINITE);
WaitForSingleObject(events[108], INFINITE);
WaitForSingleObject(events[627], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[198], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[22], 2, NULL);
ReleaseSemaphore(semaphores[289], 3, NULL);
ReleaseSemaphore(semaphores[140], 1, NULL);
SetEvent(events[804]);
ReleaseSemaphore(semaphores[265], 4, NULL);
SetEvent(events[284]);
ReleaseSemaphore(semaphores[46], 4, NULL);
}
}
void WINAPI Thread_157(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[0], INFINITE);
WaitForSingleObject(events[696], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[133], INFINITE);
}
// good checks done
SetEvent(events[512]);
SetEvent(events[992]);
ReleaseSemaphore(semaphores[229], 2, NULL);
ReleaseSemaphore(semaphores[206], 1, NULL);
ReleaseSemaphore(semaphores[207], 4, NULL);
SetEvent(events[602]);
ReleaseSemaphore(semaphores[50], 3, NULL);
ReleaseSemaphore(semaphores[246], 1, NULL);
} else {
WaitForSingleObject(events[537], INFINITE);
WaitForSingleObject(events[798], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[133], INFINITE);
}
// bad checks done
SetEvent(events[780]);
ReleaseSemaphore(semaphores[197], 4, NULL);
ReleaseSemaphore(semaphores[236], 4, NULL);
ReleaseSemaphore(semaphores[292], 1, NULL);
ReleaseSemaphore(semaphores[278], 2, NULL);
ReleaseSemaphore(semaphores[204], 1, NULL);
}
}
void WINAPI Thread_158(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[588], INFINITE);
WaitForSingleObject(events[647], INFINITE);
WaitForSingleObject(events[743], INFINITE);
WaitForSingleObject(events[53], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[285], INFINITE);
}
// good checks done
SetEvent(events[81]);
ReleaseSemaphore(semaphores[152], 1, NULL);
ReleaseSemaphore(semaphores[256], 4, NULL);
ReleaseSemaphore(semaphores[244], 4, NULL);
SetEvent(events[1]);
SetEvent(events[974]);
ReleaseSemaphore(semaphores[109], 4, NULL);
ReleaseSemaphore(semaphores[17], 3, NULL);
ReleaseSemaphore(semaphores[208], 1, NULL);
SetEvent(events[723]);
ReleaseSemaphore(semaphores[194], 3, NULL);
ReleaseSemaphore(semaphores[135], 4, NULL);
ReleaseSemaphore(semaphores[249], 3, NULL);
} else {
// bad checks done
SetEvent(events[350]);
SetEvent(events[210]);
ReleaseSemaphore(semaphores[100], 4, NULL);
SetEvent(events[824]);
ReleaseSemaphore(semaphores[166], 1, NULL);
ReleaseSemaphore(semaphores[232], 4, NULL);
ReleaseSemaphore(semaphores[268], 1, NULL);
}
}
void WINAPI Thread_159(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[28], INFINITE);
}
// bad checks done
SetEvent(events[368]);
SetEvent(events[864]);
ReleaseSemaphore(semaphores[93], 2, NULL);
SetEvent(events[582]);
} else {
WaitForSingleObject(events[987], INFINITE);
WaitForSingleObject(events[581], INFINITE);
WaitForSingleObject(events[487], INFINITE);
WaitForSingleObject(events[250], INFINITE);
WaitForSingleObject(events[744], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[28], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 2, NULL);
SetEvent(events[497]);
SetEvent(events[297]);
SetEvent(events[74]);
ReleaseSemaphore(semaphores[214], 3, NULL);
SetEvent(events[688]);
SetEvent(events[579]);
SetEvent(events[86]);
}
}
void WINAPI Thread_160(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[690], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[195], INFINITE);
}
// good checks done
SetEvent(events[461]);
ReleaseSemaphore(semaphores[264], 2, NULL);
SetEvent(events[431]);
ReleaseSemaphore(semaphores[108], 3, NULL);
ReleaseSemaphore(semaphores[82], 4, NULL);
ReleaseSemaphore(semaphores[200], 3, NULL);
ReleaseSemaphore(semaphores[187], 4, NULL);
SetEvent(events[752]);
} else {
// bad checks done
SetEvent(events[985]);
}
}
void WINAPI Thread_161(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1017], INFINITE);
WaitForSingleObject(events[18], INFINITE);
WaitForSingleObject(events[5], INFINITE);
WaitForSingleObject(events[198], INFINITE);
WaitForSingleObject(events[390], INFINITE);
WaitForSingleObject(events[104], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[8], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[106], 2, NULL);
ReleaseSemaphore(semaphores[241], 1, NULL);
ReleaseSemaphore(semaphores[61], 4, NULL);
ReleaseSemaphore(semaphores[136], 3, NULL);
ReleaseSemaphore(semaphores[111], 2, NULL);
ReleaseSemaphore(semaphores[45], 3, NULL);
ReleaseSemaphore(semaphores[59], 4, NULL);
} else {
WaitForSingleObject(events[735], INFINITE);
WaitForSingleObject(events[644], INFINITE);
WaitForSingleObject(events[351], INFINITE);
WaitForSingleObject(events[42], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[33], 4, NULL);
ReleaseSemaphore(semaphores[126], 4, NULL);
SetEvent(events[955]);
ReleaseSemaphore(semaphores[71], 4, NULL);
ReleaseSemaphore(semaphores[120], 3, NULL);
}
}
void WINAPI Thread_162(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[772], INFINITE);
WaitForSingleObject(events[843], INFINITE);
WaitForSingleObject(events[819], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[137], INFINITE);
}
// bad checks done
SetEvent(events[747]);
ReleaseSemaphore(semaphores[284], 1, NULL);
ReleaseSemaphore(semaphores[209], 4, NULL);
ReleaseSemaphore(semaphores[91], 3, NULL);
SetEvent(events[376]);
ReleaseSemaphore(semaphores[200], 4, NULL);
} else {
WaitForSingleObject(events[474], INFINITE);
WaitForSingleObject(events[96], INFINITE);
WaitForSingleObject(events[518], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[137], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[142], 3, NULL);
ReleaseSemaphore(semaphores[17], 1, NULL);
ReleaseSemaphore(semaphores[210], 1, NULL);
ReleaseSemaphore(semaphores[116], 1, NULL);
ReleaseSemaphore(semaphores[224], 2, NULL);
SetEvent(events[815]);
SetEvent(events[648]);
ReleaseSemaphore(semaphores[135], 3, NULL);
}
}
void WINAPI Thread_163(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[996], INFINITE);
WaitForSingleObject(events[56], INFINITE);
WaitForSingleObject(events[298], INFINITE);
// bad checks done
} else {
WaitForSingleObject(events[798], INFINITE);
WaitForSingleObject(events[22], INFINITE);
WaitForSingleObject(events[205], INFINITE);
WaitForSingleObject(events[811], INFINITE);
WaitForSingleObject(events[520], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[157], INFINITE);
}
// good checks done
SetEvent(events[104]);
ReleaseSemaphore(semaphores[6], 1, NULL);
}
}
void WINAPI Thread_164(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[142], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[293], INFINITE);
}
// good checks done
SetEvent(events[386]);
ReleaseSemaphore(semaphores[259], 2, NULL);
ReleaseSemaphore(semaphores[156], 4, NULL);
SetEvent(events[549]);
SetEvent(events[699]);
ReleaseSemaphore(semaphores[162], 3, NULL);
SetEvent(events[192]);
ReleaseSemaphore(semaphores[276], 1, NULL);
SetEvent(events[285]);
SetEvent(events[54]);
ReleaseSemaphore(semaphores[230], 2, NULL);
ReleaseSemaphore(semaphores[255], 3, NULL);
ReleaseSemaphore(semaphores[205], 4, NULL);
} else {
WaitForSingleObject(events[855], INFINITE);
WaitForSingleObject(events[643], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[293], INFINITE);
}
// bad checks done
SetEvent(events[873]);
SetEvent(events[765]);
SetEvent(events[888]);
ReleaseSemaphore(semaphores[271], 3, NULL);
SetEvent(events[844]);
SetEvent(events[861]);
ReleaseSemaphore(semaphores[155], 4, NULL);
ReleaseSemaphore(semaphores[50], 4, NULL);
}
}
void WINAPI Thread_165(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[285], INFINITE);
WaitForSingleObject(events[963], INFINITE);
WaitForSingleObject(events[679], INFINITE);
WaitForSingleObject(events[98], INFINITE);
WaitForSingleObject(events[1016], INFINITE);
WaitForSingleObject(events[623], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[191], INFINITE);
}
// good checks done
SetEvent(events[1022]);
SetEvent(events[458]);
ReleaseSemaphore(semaphores[229], 4, NULL);
SetEvent(events[926]);
SetEvent(events[927]);
SetEvent(events[814]);
ReleaseSemaphore(semaphores[92], 2, NULL);
} else {
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[191], INFINITE);
}
// bad checks done
SetEvent(events[429]);
SetEvent(events[509]);
SetEvent(events[214]);
SetEvent(events[246]);
ReleaseSemaphore(semaphores[300], 3, NULL);
ReleaseSemaphore(semaphores[290], 2, NULL);
ReleaseSemaphore(semaphores[186], 1, NULL);
ReleaseSemaphore(semaphores[293], 3, NULL);
SetEvent(events[37]);
}
}
void WINAPI Thread_166(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[297], INFINITE);
}
// bad checks done
SetEvent(events[884]);
SetEvent(events[408]);
ReleaseSemaphore(semaphores[249], 3, NULL);
ReleaseSemaphore(semaphores[198], 3, NULL);
ReleaseSemaphore(semaphores[15], 3, NULL);
SetEvent(events[214]);
} else {
WaitForSingleObject(events[311], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[297], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[152], 4, NULL);
ReleaseSemaphore(semaphores[38], 4, NULL);
ReleaseSemaphore(semaphores[176], 3, NULL);
ReleaseSemaphore(semaphores[214], 1, NULL);
ReleaseSemaphore(semaphores[269], 1, NULL);
SetEvent(events[852]);
ReleaseSemaphore(semaphores[224], 1, NULL);
ReleaseSemaphore(semaphores[160], 3, NULL);
ReleaseSemaphore(semaphores[278], 3, NULL);
ReleaseSemaphore(semaphores[245], 1, NULL);
ReleaseSemaphore(semaphores[249], 1, NULL);
}
}
void WINAPI Thread_167(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[472], INFINITE);
WaitForSingleObject(events[537], INFINITE);
WaitForSingleObject(events[442], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[262], 1, NULL);
ReleaseSemaphore(semaphores[233], 3, NULL);
SetEvent(events[212]);
ReleaseSemaphore(semaphores[207], 2, NULL);
} else {
WaitForSingleObject(events[401], INFINITE);
WaitForSingleObject(events[850], INFINITE);
WaitForSingleObject(events[620], INFINITE);
for (i = 0; i < 26; i++) {
    WaitForSingleObject(semaphores[272], INFINITE);
}
// good checks done
SetEvent(events[526]);
SetEvent(events[505]);
ReleaseSemaphore(semaphores[17], 1, NULL);
ReleaseSemaphore(semaphores[62], 4, NULL);
ReleaseSemaphore(semaphores[245], 3, NULL);
ReleaseSemaphore(semaphores[194], 1, NULL);
SetEvent(events[48]);
}
}
void WINAPI Thread_168(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[128], INFINITE);
WaitForSingleObject(events[311], INFINITE);
WaitForSingleObject(events[773], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[243], INFINITE);
}
// bad checks done
SetEvent(events[490]);
ReleaseSemaphore(semaphores[62], 1, NULL);
ReleaseSemaphore(semaphores[42], 2, NULL);
ReleaseSemaphore(semaphores[165], 1, NULL);
SetEvent(events[134]);
ReleaseSemaphore(semaphores[182], 1, NULL);
ReleaseSemaphore(semaphores[141], 2, NULL);
SetEvent(events[299]);
} else {
WaitForSingleObject(events[409], INFINITE);
WaitForSingleObject(events[355], INFINITE);
WaitForSingleObject(events[669], INFINITE);
WaitForSingleObject(events[151], INFINITE);
WaitForSingleObject(events[39], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[243], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 3, NULL);
ReleaseSemaphore(semaphores[49], 3, NULL);
ReleaseSemaphore(semaphores[218], 3, NULL);
ReleaseSemaphore(semaphores[284], 1, NULL);
ReleaseSemaphore(semaphores[170], 4, NULL);
ReleaseSemaphore(semaphores[193], 3, NULL);
ReleaseSemaphore(semaphores[70], 3, NULL);
ReleaseSemaphore(semaphores[183], 2, NULL);
}
}
void WINAPI Thread_169(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[148], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[156], 3, NULL);
SetEvent(events[691]);
SetEvent(events[502]);
SetEvent(events[303]);
SetEvent(events[662]);
SetEvent(events[64]);
SetEvent(events[2]);
ReleaseSemaphore(semaphores[24], 1, NULL);
ReleaseSemaphore(semaphores[191], 4, NULL);
SetEvent(events[204]);
ReleaseSemaphore(semaphores[125], 4, NULL);
ReleaseSemaphore(semaphores[202], 4, NULL);
} else {
WaitForSingleObject(events[296], INFINITE);
WaitForSingleObject(events[860], INFINITE);
WaitForSingleObject(events[772], INFINITE);
WaitForSingleObject(events[666], INFINITE);
WaitForSingleObject(events[209], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[148], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[245], 4, NULL);
ReleaseSemaphore(semaphores[211], 1, NULL);
ReleaseSemaphore(semaphores[135], 1, NULL);
ReleaseSemaphore(semaphores[262], 1, NULL);
ReleaseSemaphore(semaphores[70], 1, NULL);
}
}
void WINAPI Thread_170(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[109], INFINITE);
}
// bad checks done
SetEvent(events[626]);
ReleaseSemaphore(semaphores[108], 3, NULL);
ReleaseSemaphore(semaphores[183], 2, NULL);
} else {
WaitForSingleObject(events[170], INFINITE);
WaitForSingleObject(events[527], INFINITE);
WaitForSingleObject(events[756], INFINITE);
WaitForSingleObject(events[274], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[109], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 4, NULL);
ReleaseSemaphore(semaphores[86], 1, NULL);
ReleaseSemaphore(semaphores[8], 2, NULL);
ReleaseSemaphore(semaphores[149], 3, NULL);
}
}
void WINAPI Thread_171(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[53], INFINITE);
}
// bad checks done
SetEvent(events[84]);
SetEvent(events[716]);
} else {
WaitForSingleObject(events[506], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[53], INFINITE);
}
// good checks done
SetEvent(events[337]);
SetEvent(events[49]);
SetEvent(events[931]);
SetEvent(events[567]);
ReleaseSemaphore(semaphores[273], 3, NULL);
ReleaseSemaphore(semaphores[32], 2, NULL);
ReleaseSemaphore(semaphores[35], 2, NULL);
ReleaseSemaphore(semaphores[301], 1, NULL);
SetEvent(events[787]);
SetEvent(events[910]);
ReleaseSemaphore(semaphores[57], 2, NULL);
}
}
void WINAPI Thread_172(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[174], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[204], 2, NULL);
ReleaseSemaphore(semaphores[101], 4, NULL);
SetEvent(events[819]);
ReleaseSemaphore(semaphores[111], 3, NULL);
SetEvent(events[638]);
ReleaseSemaphore(semaphores[45], 3, NULL);
SetEvent(events[642]);
SetEvent(events[757]);
} else {
WaitForSingleObject(events[1018], INFINITE);
WaitForSingleObject(events[540], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[174], INFINITE);
}
// bad checks done
SetEvent(events[348]);
ReleaseSemaphore(semaphores[227], 3, NULL);
}
}
void WINAPI Thread_173(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[412], INFINITE);
WaitForSingleObject(events[681], INFINITE);
WaitForSingleObject(events[832], INFINITE);
WaitForSingleObject(events[665], INFINITE);
WaitForSingleObject(events[41], INFINITE);
WaitForSingleObject(events[675], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[126], INFINITE);
}
// good checks done
SetEvent(events[66]);
ReleaseSemaphore(semaphores[56], 4, NULL);
ReleaseSemaphore(semaphores[88], 1, NULL);
ReleaseSemaphore(semaphores[113], 2, NULL);
ReleaseSemaphore(semaphores[31], 2, NULL);
SetEvent(events[134]);
ReleaseSemaphore(semaphores[290], 4, NULL);
ReleaseSemaphore(semaphores[0], 1, NULL);
SetEvent(events[409]);
SetEvent(events[557]);
SetEvent(events[227]);
ReleaseSemaphore(semaphores[71], 1, NULL);
} else {
WaitForSingleObject(events[376], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[126], INFINITE);
}
// bad checks done
SetEvent(events[283]);
ReleaseSemaphore(semaphores[181], 1, NULL);
SetEvent(events[698]);
SetEvent(events[73]);
}
}
void WINAPI Thread_174(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[279], INFINITE);
WaitForSingleObject(events[664], INFINITE);
WaitForSingleObject(events[477], INFINITE);
WaitForSingleObject(events[801], INFINITE);
WaitForSingleObject(events[993], INFINITE);
WaitForSingleObject(events[508], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[173], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[7], 2, NULL);
SetEvent(events[20]);
ReleaseSemaphore(semaphores[10], 1, NULL);
ReleaseSemaphore(semaphores[193], 2, NULL);
SetEvent(events[955]);
SetEvent(events[433]);
ReleaseSemaphore(semaphores[29], 3, NULL);
SetEvent(events[304]);
SetEvent(events[84]);
ReleaseSemaphore(semaphores[219], 3, NULL);
ReleaseSemaphore(semaphores[247], 1, NULL);
ReleaseSemaphore(semaphores[119], 2, NULL);
} else {
WaitForSingleObject(events[217], INFINITE);
WaitForSingleObject(events[279], INFINITE);
// bad checks done
SetEvent(events[530]);
SetEvent(events[608]);
}
}
void WINAPI Thread_175(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[212], INFINITE);
WaitForSingleObject(events[1001], INFINITE);
WaitForSingleObject(events[14], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[60], INFINITE);
}
// bad checks done
SetEvent(events[187]);
SetEvent(events[635]);
ReleaseSemaphore(semaphores[38], 2, NULL);
SetEvent(events[51]);
} else {
WaitForSingleObject(events[625], INFINITE);
WaitForSingleObject(events[325], INFINITE);
WaitForSingleObject(events[642], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[60], INFINITE);
}
// good checks done
SetEvent(events[826]);
ReleaseSemaphore(semaphores[156], 2, NULL);
ReleaseSemaphore(semaphores[34], 3, NULL);
SetEvent(events[949]);
SetEvent(events[471]);
SetEvent(events[264]);
ReleaseSemaphore(semaphores[168], 4, NULL);
SetEvent(events[127]);
SetEvent(events[214]);
ReleaseSemaphore(semaphores[57], 4, NULL);
}
}
void WINAPI Thread_176(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[110], INFINITE);
WaitForSingleObject(events[1008], INFINITE);
WaitForSingleObject(events[485], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[169], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[270], 3, NULL);
SetEvent(events[69]);
ReleaseSemaphore(semaphores[164], 1, NULL);
ReleaseSemaphore(semaphores[272], 3, NULL);
SetEvent(events[519]);
SetEvent(events[490]);
ReleaseSemaphore(semaphores[285], 3, NULL);
SetEvent(events[266]);
SetEvent(events[175]);
ReleaseSemaphore(semaphores[28], 2, NULL);
ReleaseSemaphore(semaphores[75], 1, NULL);
SetEvent(events[704]);
} else {
WaitForSingleObject(events[646], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[169], INFINITE);
}
// bad checks done
SetEvent(events[847]);
}
}
void WINAPI Thread_177(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[281], INFINITE);
WaitForSingleObject(events[233], INFINITE);
WaitForSingleObject(events[624], INFINITE);
WaitForSingleObject(events[566], INFINITE);
WaitForSingleObject(events[320], INFINITE);
WaitForSingleObject(events[923], INFINITE);
WaitForSingleObject(events[458], INFINITE);
WaitForSingleObject(events[992], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[115], INFINITE);
}
// good checks done
SetEvent(events[616]);
SetEvent(events[996]);
ReleaseSemaphore(semaphores[239], 4, NULL);
ReleaseSemaphore(semaphores[215], 2, NULL);
} else {
WaitForSingleObject(events[893], INFINITE);
WaitForSingleObject(events[283], INFINITE);
WaitForSingleObject(events[690], INFINITE);
WaitForSingleObject(events[201], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[115], INFINITE);
}
// bad checks done
SetEvent(events[242]);
ReleaseSemaphore(semaphores[249], 4, NULL);
ReleaseSemaphore(semaphores[235], 3, NULL);
ReleaseSemaphore(semaphores[201], 4, NULL);
SetEvent(events[499]);
SetEvent(events[742]);
}
}
void WINAPI Thread_178(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[108], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[126], 4, NULL);
ReleaseSemaphore(semaphores[178], 2, NULL);
SetEvent(events[139]);
ReleaseSemaphore(semaphores[155], 4, NULL);
ReleaseSemaphore(semaphores[51], 2, NULL);
ReleaseSemaphore(semaphores[158], 4, NULL);
ReleaseSemaphore(semaphores[252], 4, NULL);
ReleaseSemaphore(semaphores[175], 3, NULL);
SetEvent(events[1010]);
SetEvent(events[1026]);
SetEvent(events[1007]);
ReleaseSemaphore(semaphores[138], 1, NULL);
ReleaseSemaphore(semaphores[182], 2, NULL);
ReleaseSemaphore(semaphores[184], 2, NULL);
} else {
WaitForSingleObject(events[804], INFINITE);
WaitForSingleObject(events[756], INFINITE);
WaitForSingleObject(events[71], INFINITE);
WaitForSingleObject(events[153], INFINITE);
WaitForSingleObject(events[297], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[108], INFINITE);
}
// bad checks done
SetEvent(events[289]);
SetEvent(events[766]);
SetEvent(events[467]);
SetEvent(events[138]);
ReleaseSemaphore(semaphores[101], 4, NULL);
}
}
void WINAPI Thread_179(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[194], INFINITE);
WaitForSingleObject(events[248], INFINITE);
WaitForSingleObject(events[119], INFINITE);
WaitForSingleObject(events[736], INFINITE);
WaitForSingleObject(events[946], INFINITE);
WaitForSingleObject(events[30], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[186], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[7], 4, NULL);
ReleaseSemaphore(semaphores[193], 1, NULL);
ReleaseSemaphore(semaphores[212], 2, NULL);
} else {
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[186], INFINITE);
}
// bad checks done
SetEvent(events[710]);
SetEvent(events[854]);
SetEvent(events[1022]);
SetEvent(events[646]);
}
}
void WINAPI Thread_180(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[546], INFINITE);
WaitForSingleObject(events[77], INFINITE);
WaitForSingleObject(events[879], INFINITE);
WaitForSingleObject(events[1015], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[49], INFINITE);
}
// good checks done
SetEvent(events[272]);
SetEvent(events[397]);
ReleaseSemaphore(semaphores[139], 4, NULL);
SetEvent(events[588]);
SetEvent(events[720]);
ReleaseSemaphore(semaphores[100], 1, NULL);
SetEvent(events[878]);
SetEvent(events[102]);
} else {
WaitForSingleObject(events[633], INFINITE);
WaitForSingleObject(events[112], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[49], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[232], 1, NULL);
ReleaseSemaphore(semaphores[72], 3, NULL);
ReleaseSemaphore(semaphores[36], 2, NULL);
ReleaseSemaphore(semaphores[84], 1, NULL);
ReleaseSemaphore(semaphores[147], 1, NULL);
SetEvent(events[964]);
SetEvent(events[2]);
}
}
void WINAPI Thread_181(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[969], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[228], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[168], 4, NULL);
SetEvent(events[219]);
SetEvent(events[821]);
ReleaseSemaphore(semaphores[286], 3, NULL);
SetEvent(events[54]);
SetEvent(events[336]);
} else {
WaitForSingleObject(events[813], INFINITE);
WaitForSingleObject(events[668], INFINITE);
WaitForSingleObject(events[328], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[228], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[137], 4, NULL);
SetEvent(events[89]);
SetEvent(events[265]);
ReleaseSemaphore(semaphores[272], 4, NULL);
SetEvent(events[427]);
SetEvent(events[913]);
}
}
void WINAPI Thread_182(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[968], INFINITE);
WaitForSingleObject(events[673], INFINITE);
WaitForSingleObject(events[988], INFINITE);
WaitForSingleObject(events[221], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[43], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 1, NULL);
SetEvent(events[750]);
ReleaseSemaphore(semaphores[4], 1, NULL);
ReleaseSemaphore(semaphores[201], 3, NULL);
SetEvent(events[973]);
SetEvent(events[468]);
ReleaseSemaphore(semaphores[262], 3, NULL);
ReleaseSemaphore(semaphores[183], 2, NULL);
ReleaseSemaphore(semaphores[219], 4, NULL);
ReleaseSemaphore(semaphores[247], 3, NULL);
ReleaseSemaphore(semaphores[48], 1, NULL);
} else {
WaitForSingleObject(events[618], INFINITE);
WaitForSingleObject(events[590], INFINITE);
WaitForSingleObject(events[543], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[43], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_183(int bit) {
int i = 0;
if (bit) {
// bad checks done
SetEvent(events[575]);
SetEvent(events[61]);
ReleaseSemaphore(semaphores[34], 1, NULL);
SetEvent(events[809]);
ReleaseSemaphore(semaphores[293], 3, NULL);
ReleaseSemaphore(semaphores[266], 2, NULL);
SetEvent(events[363]);
ReleaseSemaphore(semaphores[167], 1, NULL);
} else {
WaitForSingleObject(events[304], INFINITE);
WaitForSingleObject(events[462], INFINITE);
WaitForSingleObject(events[34], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[212], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[270], 4, NULL);
ReleaseSemaphore(semaphores[164], 1, NULL);
ReleaseSemaphore(semaphores[143], 3, NULL);
SetEvent(events[894]);
ReleaseSemaphore(semaphores[285], 1, NULL);
SetEvent(events[232]);
}
}
void WINAPI Thread_184(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[749], INFINITE);
WaitForSingleObject(events[79], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[282], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[289], 1, NULL);
ReleaseSemaphore(semaphores[161], 2, NULL);
SetEvent(events[923]);
SetEvent(events[678]);
SetEvent(events[954]);
ReleaseSemaphore(semaphores[46], 2, NULL);
ReleaseSemaphore(semaphores[240], 4, NULL);
ReleaseSemaphore(semaphores[246], 3, NULL);
SetEvent(events[977]);
} else {
WaitForSingleObject(events[1010], INFINITE);
WaitForSingleObject(events[820], INFINITE);
WaitForSingleObject(events[529], INFINITE);
WaitForSingleObject(events[138], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[282], INFINITE);
}
// bad checks done
SetEvent(events[151]);
ReleaseSemaphore(semaphores[33], 1, NULL);
ReleaseSemaphore(semaphores[103], 3, NULL);
SetEvent(events[422]);
SetEvent(events[862]);
SetEvent(events[557]);
}
}
void WINAPI Thread_185(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[815], INFINITE);
WaitForSingleObject(events[257], INFINITE);
WaitForSingleObject(events[943], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[194], INFINITE);
}
// good checks done
SetEvent(events[51]);
SetEvent(events[983]);
ReleaseSemaphore(semaphores[94], 4, NULL);
ReleaseSemaphore(semaphores[86], 4, NULL);
SetEvent(events[72]);
SetEvent(events[18]);
ReleaseSemaphore(semaphores[203], 3, NULL);
ReleaseSemaphore(semaphores[6], 4, NULL);
} else {
WaitForSingleObject(events[689], INFINITE);
WaitForSingleObject(events[886], INFINITE);
WaitForSingleObject(events[929], INFINITE);
WaitForSingleObject(events[657], INFINITE);
WaitForSingleObject(events[484], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[194], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[225], 1, NULL);
SetEvent(events[609]);
ReleaseSemaphore(semaphores[89], 1, NULL);
ReleaseSemaphore(semaphores[8], 3, NULL);
SetEvent(events[733]);
ReleaseSemaphore(semaphores[208], 4, NULL);
}
}
void WINAPI Thread_186(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[277], INFINITE);
WaitForSingleObject(events[696], INFINITE);
WaitForSingleObject(events[418], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[196], 4, NULL);
ReleaseSemaphore(semaphores[238], 4, NULL);
ReleaseSemaphore(semaphores[120], 4, NULL);
} else {
WaitForSingleObject(events[869], INFINITE);
WaitForSingleObject(events[663], INFINITE);
WaitForSingleObject(events[489], INFINITE);
WaitForSingleObject(events[994], INFINITE);
for (i = 0; i < 27; i++) {
    WaitForSingleObject(semaphores[231], INFINITE);
}
// good checks done
SetEvent(events[824]);
ReleaseSemaphore(semaphores[166], 1, NULL);
}
}
void WINAPI Thread_187(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[357], INFINITE);
WaitForSingleObject(events[195], INFINITE);
WaitForSingleObject(events[52], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[160], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[198], 1, NULL);
} else {
WaitForSingleObject(events[294], INFINITE);
WaitForSingleObject(events[213], INFINITE);
WaitForSingleObject(events[133], INFINITE);
WaitForSingleObject(events[628], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[160], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 1, NULL);
ReleaseSemaphore(semaphores[281], 1, NULL);
ReleaseSemaphore(semaphores[94], 3, NULL);
ReleaseSemaphore(semaphores[8], 2, NULL);
ReleaseSemaphore(semaphores[225], 2, NULL);
SetEvent(events[165]);
ReleaseSemaphore(semaphores[6], 3, NULL);
}
}
void WINAPI Thread_188(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1], INFINITE);
WaitForSingleObject(events[297], INFINITE);
WaitForSingleObject(events[685], INFINITE);
WaitForSingleObject(events[582], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[38], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[174], 4, NULL);
ReleaseSemaphore(semaphores[203], 4, NULL);
ReleaseSemaphore(semaphores[149], 2, NULL);
ReleaseSemaphore(semaphores[6], 3, NULL);
} else {
WaitForSingleObject(events[558], INFINITE);
WaitForSingleObject(events[959], INFINITE);
WaitForSingleObject(events[620], INFINITE);
// bad checks done
}
}
void WINAPI Thread_189(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[333], INFINITE);
WaitForSingleObject(events[957], INFINITE);
WaitForSingleObject(events[860], INFINITE);
WaitForSingleObject(events[643], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[268], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[106], 4, NULL);
ReleaseSemaphore(semaphores[53], 3, NULL);
ReleaseSemaphore(semaphores[241], 2, NULL);
SetEvent(events[727]);
ReleaseSemaphore(semaphores[45], 4, NULL);
ReleaseSemaphore(semaphores[80], 4, NULL);
} else {
WaitForSingleObject(events[128], INFINITE);
WaitForSingleObject(events[300], INFINITE);
WaitForSingleObject(events[742], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[207], 3, NULL);
ReleaseSemaphore(semaphores[33], 4, NULL);
ReleaseSemaphore(semaphores[112], 4, NULL);
ReleaseSemaphore(semaphores[298], 1, NULL);
ReleaseSemaphore(semaphores[35], 1, NULL);
}
}
void WINAPI Thread_190(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1030], INFINITE);
WaitForSingleObject(events[135], INFINITE);
WaitForSingleObject(events[105], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[295], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[51], 1, NULL);
SetEvent(events[880]);
ReleaseSemaphore(semaphores[252], 4, NULL);
SetEvent(events[530]);
ReleaseSemaphore(semaphores[64], 1, NULL);
ReleaseSemaphore(semaphores[27], 1, NULL);
SetEvent(events[621]);
} else {
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[295], INFINITE);
}
// bad checks done
SetEvent(events[589]);
SetEvent(events[411]);
ReleaseSemaphore(semaphores[159], 1, NULL);
}
}
void WINAPI Thread_191(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[342], INFINITE);
WaitForSingleObject(events[879], INFINITE);
WaitForSingleObject(events[354], INFINITE);
WaitForSingleObject(events[652], INFINITE);
WaitForSingleObject(events[694], INFINITE);
// bad checks done
SetEvent(events[749]);
ReleaseSemaphore(semaphores[141], 1, NULL);
ReleaseSemaphore(semaphores[236], 4, NULL);
SetEvent(events[1014]);
} else {
// good checks done
ReleaseSemaphore(semaphores[267], 2, NULL);
ReleaseSemaphore(semaphores[130], 2, NULL);
ReleaseSemaphore(semaphores[181], 3, NULL);
ReleaseSemaphore(semaphores[65], 1, NULL);
ReleaseSemaphore(semaphores[232], 3, NULL);
ReleaseSemaphore(semaphores[63], 3, NULL);
ReleaseSemaphore(semaphores[250], 4, NULL);
}
}
void WINAPI Thread_192(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[701], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[80], INFINITE);
}
// bad checks done
SetEvent(events[491]);
SetEvent(events[898]);
SetEvent(events[74]);
ReleaseSemaphore(semaphores[61], 2, NULL);
SetEvent(events[204]);
SetEvent(events[346]);
} else {
WaitForSingleObject(events[472], INFINITE);
WaitForSingleObject(events[757], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[80], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[156], 2, NULL);
SetEvent(events[448]);
SetEvent(events[1019]);
SetEvent(events[210]);
SetEvent(events[749]);
ReleaseSemaphore(semaphores[237], 3, NULL);
ReleaseSemaphore(semaphores[177], 3, NULL);
ReleaseSemaphore(semaphores[125], 4, NULL);
ReleaseSemaphore(semaphores[196], 4, NULL);
SetEvent(events[684]);
ReleaseSemaphore(semaphores[74], 4, NULL);
}
}
void WINAPI Thread_193(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1001], INFINITE);
WaitForSingleObject(events[403], INFINITE);
WaitForSingleObject(events[531], INFINITE);
WaitForSingleObject(events[523], INFINITE);
WaitForSingleObject(events[1005], INFINITE);
// bad checks done
SetEvent(events[762]);
ReleaseSemaphore(semaphores[64], 3, NULL);
SetEvent(events[152]);
SetEvent(events[636]);
SetEvent(events[885]);
} else {
WaitForSingleObject(events[725], INFINITE);
WaitForSingleObject(events[343], INFINITE);
WaitForSingleObject(events[299], INFINITE);
WaitForSingleObject(events[400], INFINITE);
WaitForSingleObject(events[563], INFINITE);
WaitForSingleObject(events[1014], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[246], INFINITE);
}
// good checks done
SetEvent(events[345]);
}
}
void WINAPI Thread_194(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[769], INFINITE);
// bad checks done
SetEvent(events[262]);
ReleaseSemaphore(semaphores[148], 4, NULL);
SetEvent(events[466]);
SetEvent(events[448]);
SetEvent(events[914]);
ReleaseSemaphore(semaphores[243], 4, NULL);
} else {
WaitForSingleObject(events[921], INFINITE);
WaitForSingleObject(events[246], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[72], INFINITE);
}
// good checks done
SetEvent(events[545]);
SetEvent(events[402]);
ReleaseSemaphore(semaphores[231], 4, NULL);
SetEvent(events[853]);
SetEvent(events[697]);
SetEvent(events[369]);
SetEvent(events[493]);
}
}
void WINAPI Thread_195(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[20], INFINITE);
}
// bad checks done
SetEvent(events[682]);
ReleaseSemaphore(semaphores[201], 1, NULL);
ReleaseSemaphore(semaphores[190], 3, NULL);
ReleaseSemaphore(semaphores[39], 1, NULL);
ReleaseSemaphore(semaphores[15], 2, NULL);
SetEvent(events[28]);
SetEvent(events[224]);
SetEvent(events[48]);
ReleaseSemaphore(semaphores[129], 4, NULL);
} else {
WaitForSingleObject(events[67], INFINITE);
WaitForSingleObject(events[156], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[20], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[91], 2, NULL);
SetEvent(events[555]);
ReleaseSemaphore(semaphores[110], 3, NULL);
SetEvent(events[962]);
ReleaseSemaphore(semaphores[283], 4, NULL);
SetEvent(events[907]);
ReleaseSemaphore(semaphores[100], 1, NULL);
ReleaseSemaphore(semaphores[28], 3, NULL);
}
}
void WINAPI Thread_196(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[148], INFINITE);
WaitForSingleObject(events[371], INFINITE);
WaitForSingleObject(events[159], INFINITE);
WaitForSingleObject(events[419], INFINITE);
WaitForSingleObject(events[199], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[203], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[106], 4, NULL);
ReleaseSemaphore(semaphores[96], 2, NULL);
SetEvent(events[361]);
ReleaseSemaphore(semaphores[136], 1, NULL);
ReleaseSemaphore(semaphores[199], 4, NULL);
ReleaseSemaphore(semaphores[45], 4, NULL);
SetEvent(events[410]);
} else {
WaitForSingleObject(events[107], INFINITE);
WaitForSingleObject(events[522], INFINITE);
WaitForSingleObject(events[633], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[203], INFINITE);
}
// bad checks done
SetEvent(events[911]);
ReleaseSemaphore(semaphores[113], 3, NULL);
ReleaseSemaphore(semaphores[211], 3, NULL);
ReleaseSemaphore(semaphores[37], 3, NULL);
ReleaseSemaphore(semaphores[59], 1, NULL);
SetEvent(events[49]);
ReleaseSemaphore(semaphores[157], 2, NULL);
}
}
void WINAPI Thread_197(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[289], INFINITE);
WaitForSingleObject(events[974], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[12], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[281], 3, NULL);
SetEvent(events[900]);
ReleaseSemaphore(semaphores[84], 2, NULL);
ReleaseSemaphore(semaphores[225], 3, NULL);
} else {
WaitForSingleObject(events[829], INFINITE);
WaitForSingleObject(events[347], INFINITE);
WaitForSingleObject(events[408], INFINITE);
WaitForSingleObject(events[71], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[12], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[146], 3, NULL);
ReleaseSemaphore(semaphores[270], 1, NULL);
}
}
void WINAPI Thread_198(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[277], INFINITE);
WaitForSingleObject(events[327], INFINITE);
WaitForSingleObject(events[414], INFINITE);
WaitForSingleObject(events[334], INFINITE);
WaitForSingleObject(events[55], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[32], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[273], 1, NULL);
SetEvent(events[799]);
SetEvent(events[18]);
ReleaseSemaphore(semaphores[9], 1, NULL);
SetEvent(events[823]);
} else {
WaitForSingleObject(events[189], INFINITE);
WaitForSingleObject(events[377], INFINITE);
WaitForSingleObject(events[1019], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[32], INFINITE);
}
// good checks done
SetEvent(events[445]);
SetEvent(events[439]);
SetEvent(events[593]);
SetEvent(events[500]);
ReleaseSemaphore(semaphores[207], 1, NULL);
ReleaseSemaphore(semaphores[46], 3, NULL);
SetEvent(events[725]);
SetEvent(events[488]);
SetEvent(events[726]);
}
}
void WINAPI Thread_199(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[89], INFINITE);
}
// bad checks done
SetEvent(events[894]);
ReleaseSemaphore(semaphores[141], 2, NULL);
SetEvent(events[359]);
} else {
WaitForSingleObject(events[200], INFINITE);
WaitForSingleObject(events[961], INFINITE);
WaitForSingleObject(events[776], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[89], INFINITE);
}
// good checks done
SetEvent(events[112]);
SetEvent(events[438]);
ReleaseSemaphore(semaphores[210], 2, NULL);
ReleaseSemaphore(semaphores[1], 1, NULL);
SetEvent(events[411]);
ReleaseSemaphore(semaphores[62], 3, NULL);
ReleaseSemaphore(semaphores[44], 3, NULL);
ReleaseSemaphore(semaphores[279], 3, NULL);
}
}
void WINAPI Thread_200(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[499], INFINITE);
WaitForSingleObject(events[184], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[254], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[22], 2, NULL);
SetEvent(events[566]);
SetEvent(events[849]);
ReleaseSemaphore(semaphores[224], 4, NULL);
ReleaseSemaphore(semaphores[118], 1, NULL);
ReleaseSemaphore(semaphores[183], 2, NULL);
ReleaseSemaphore(semaphores[135], 1, NULL);
SetEvent(events[685]);
} else {
WaitForSingleObject(events[525], INFINITE);
WaitForSingleObject(events[293], INFINITE);
WaitForSingleObject(events[488], INFINITE);
WaitForSingleObject(events[872], INFINITE);
WaitForSingleObject(events[977], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[254], INFINITE);
}
// good checks done
SetEvent(events[80]);
ReleaseSemaphore(semaphores[150], 2, NULL);
}
}
void WINAPI Thread_201(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[371], INFINITE);
WaitForSingleObject(events[287], INFINITE);
WaitForSingleObject(events[961], INFINITE);
WaitForSingleObject(events[912], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[97], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[257], 4, NULL);
SetEvent(events[688]);
ReleaseSemaphore(semaphores[133], 4, NULL);
ReleaseSemaphore(semaphores[154], 3, NULL);
SetEvent(events[592]);
SetEvent(events[684]);
} else {
WaitForSingleObject(events[674], INFINITE);
WaitForSingleObject(events[786], INFINITE);
WaitForSingleObject(events[222], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[97], INFINITE);
}
// good checks done
SetEvent(events[113]);
ReleaseSemaphore(semaphores[215], 2, NULL);
}
}
void WINAPI Thread_202(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[261], INFINITE);
WaitForSingleObject(events[1000], INFINITE);
WaitForSingleObject(events[880], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[216], INFINITE);
}
// good checks done
SetEvent(events[932]);
ReleaseSemaphore(semaphores[103], 4, NULL);
SetEvent(events[115]);
ReleaseSemaphore(semaphores[88], 3, NULL);
SetEvent(events[634]);
SetEvent(events[573]);
SetEvent(events[467]);
ReleaseSemaphore(semaphores[90], 3, NULL);
SetEvent(events[292]);
SetEvent(events[310]);
SetEvent(events[323]);
ReleaseSemaphore(semaphores[127], 4, NULL);
ReleaseSemaphore(semaphores[40], 2, NULL);
} else {
WaitForSingleObject(events[81], INFINITE);
WaitForSingleObject(events[659], INFINITE);
WaitForSingleObject(events[711], INFINITE);
WaitForSingleObject(events[91], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[216], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[134], 1, NULL);
ReleaseSemaphore(semaphores[234], 1, NULL);
SetEvent(events[611]);
}
}
void WINAPI Thread_203(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[187], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[301], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[231], 3, NULL);
ReleaseSemaphore(semaphores[42], 3, NULL);
SetEvent(events[822]);
SetEvent(events[563]);
ReleaseSemaphore(semaphores[92], 1, NULL);
} else {
WaitForSingleObject(events[370], INFINITE);
WaitForSingleObject(events[404], INFINITE);
WaitForSingleObject(events[1027], INFINITE);
WaitForSingleObject(events[224], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[301], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_204(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[958], INFINITE);
WaitForSingleObject(events[378], INFINITE);
WaitForSingleObject(events[702], INFINITE);
WaitForSingleObject(events[793], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[2], INFINITE);
}
// bad checks done
SetEvent(events[1029]);
SetEvent(events[334]);
SetEvent(events[656]);
SetEvent(events[797]);
SetEvent(events[408]);
} else {
WaitForSingleObject(events[280], INFINITE);
WaitForSingleObject(events[179], INFINITE);
WaitForSingleObject(events[611], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[2], INFINITE);
}
// good checks done
SetEvent(events[270]);
SetEvent(events[185]);
SetEvent(events[619]);
ReleaseSemaphore(semaphores[101], 2, NULL);
SetEvent(events[306]);
ReleaseSemaphore(semaphores[111], 2, NULL);
ReleaseSemaphore(semaphores[95], 2, NULL);
ReleaseSemaphore(semaphores[257], 2, NULL);
}
}
void WINAPI Thread_205(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[171], INFINITE);
WaitForSingleObject(events[1018], INFINITE);
WaitForSingleObject(events[172], INFINITE);
WaitForSingleObject(events[112], INFINITE);
WaitForSingleObject(events[666], INFINITE);
WaitForSingleObject(events[423], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[244], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 2, NULL);
SetEvent(events[829]);
} else {
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[244], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[55], 4, NULL);
ReleaseSemaphore(semaphores[265], 4, NULL);
ReleaseSemaphore(semaphores[216], 4, NULL);
ReleaseSemaphore(semaphores[21], 2, NULL);
ReleaseSemaphore(semaphores[159], 4, NULL);
}
}
void WINAPI Thread_206(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[692], INFINITE);
WaitForSingleObject(events[362], INFINITE);
WaitForSingleObject(events[139], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[3], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[227], 3, NULL);
SetEvent(events[754]);
ReleaseSemaphore(semaphores[211], 3, NULL);
ReleaseSemaphore(semaphores[81], 2, NULL);
ReleaseSemaphore(semaphores[253], 3, NULL);
ReleaseSemaphore(semaphores[23], 3, NULL);
ReleaseSemaphore(semaphores[217], 4, NULL);
} else {
WaitForSingleObject(events[81], INFINITE);
WaitForSingleObject(events[844], INFINITE);
WaitForSingleObject(events[136], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[3], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[267], 2, NULL);
ReleaseSemaphore(semaphores[280], 4, NULL);
ReleaseSemaphore(semaphores[24], 3, NULL);
SetEvent(events[494]);
SetEvent(events[817]);
ReleaseSemaphore(semaphores[32], 3, NULL);
SetEvent(events[866]);
ReleaseSemaphore(semaphores[48], 2, NULL);
}
}
void WINAPI Thread_207(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[169], INFINITE);
WaitForSingleObject(events[324], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[61], INFINITE);
}
// bad checks done
SetEvent(events[763]);
ReleaseSemaphore(semaphores[42], 4, NULL);
SetEvent(events[126]);
ReleaseSemaphore(semaphores[281], 2, NULL);
SetEvent(events[727]);
SetEvent(events[747]);
ReleaseSemaphore(semaphores[126], 1, NULL);
} else {
WaitForSingleObject(events[727], INFINITE);
WaitForSingleObject(events[32], INFINITE);
WaitForSingleObject(events[381], INFINITE);
WaitForSingleObject(events[185], INFINITE);
WaitForSingleObject(events[82], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[61], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[72], 1, NULL);
ReleaseSemaphore(semaphores[259], 4, NULL);
SetEvent(events[802]);
ReleaseSemaphore(semaphores[282], 3, NULL);
ReleaseSemaphore(semaphores[237], 2, NULL);
ReleaseSemaphore(semaphores[69], 1, NULL);
}
}
void WINAPI Thread_208(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[741], INFINITE);
WaitForSingleObject(events[310], INFINITE);
WaitForSingleObject(events[443], INFINITE);
WaitForSingleObject(events[408], INFINITE);
WaitForSingleObject(events[837], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[296], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[85], 1, NULL);
SetEvent(events[734]);
ReleaseSemaphore(semaphores[49], 3, NULL);
ReleaseSemaphore(semaphores[284], 4, NULL);
SetEvent(events[864]);
SetEvent(events[208]);
SetEvent(events[375]);
ReleaseSemaphore(semaphores[16], 3, NULL);
ReleaseSemaphore(semaphores[36], 1, NULL);
ReleaseSemaphore(semaphores[212], 4, NULL);
SetEvent(events[592]);
SetEvent(events[694]);
ReleaseSemaphore(semaphores[219], 1, NULL);
SetEvent(events[207]);
} else {
WaitForSingleObject(events[650], INFINITE);
WaitForSingleObject(events[902], INFINITE);
WaitForSingleObject(events[8], INFINITE);
WaitForSingleObject(events[349], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[296], INFINITE);
}
// bad checks done
SetEvent(events[12]);
SetEvent(events[25]);
ReleaseSemaphore(semaphores[69], 3, NULL);
ReleaseSemaphore(semaphores[249], 1, NULL);
SetEvent(events[622]);
}
}
void WINAPI Thread_209(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[398], INFINITE);
WaitForSingleObject(events[922], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[298], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[23], 3, NULL);
ReleaseSemaphore(semaphores[81], 4, NULL);
SetEvent(events[444]);
SetEvent(events[6]);
ReleaseSemaphore(semaphores[251], 4, NULL);
SetEvent(events[481]);
SetEvent(events[544]);
SetEvent(events[942]);
} else {
WaitForSingleObject(events[549], INFINITE);
WaitForSingleObject(events[347], INFINITE);
WaitForSingleObject(events[691], INFINITE);
WaitForSingleObject(events[708], INFINITE);
WaitForSingleObject(events[970], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[298], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[289], 2, NULL);
ReleaseSemaphore(semaphores[161], 2, NULL);
ReleaseSemaphore(semaphores[104], 4, NULL);
ReleaseSemaphore(semaphores[261], 3, NULL);
SetEvent(events[825]);
ReleaseSemaphore(semaphores[141], 1, NULL);
SetEvent(events[343]);
}
}
void WINAPI Thread_210(int bit) {
int i = 0;
if (bit) {
// good checks done
SetEvent(events[547]);
ReleaseSemaphore(semaphores[181], 4, NULL);
SetEvent(events[416]);
SetEvent(events[1001]);
ReleaseSemaphore(semaphores[250], 3, NULL);
} else {
// bad checks done
SetEvent(events[9]);
ReleaseSemaphore(semaphores[144], 1, NULL);
ReleaseSemaphore(semaphores[164], 3, NULL);
SetEvent(events[281]);
SetEvent(events[171]);
ReleaseSemaphore(semaphores[224], 4, NULL);
ReleaseSemaphore(semaphores[170], 2, NULL);
SetEvent(events[908]);
SetEvent(events[140]);
}
}
void WINAPI Thread_211(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[218], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[192], 4, NULL);
ReleaseSemaphore(semaphores[9], 4, NULL);
ReleaseSemaphore(semaphores[81], 1, NULL);
SetEvent(events[57]);
ReleaseSemaphore(semaphores[175], 3, NULL);
ReleaseSemaphore(semaphores[268], 3, NULL);
SetEvent(events[315]);
SetEvent(events[200]);
} else {
WaitForSingleObject(events[407], INFINITE);
WaitForSingleObject(events[201], INFINITE);
WaitForSingleObject(events[291], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[218], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[137], 1, NULL);
ReleaseSemaphore(semaphores[277], 1, NULL);
ReleaseSemaphore(semaphores[110], 1, NULL);
ReleaseSemaphore(semaphores[139], 3, NULL);
SetEvent(events[15]);
SetEvent(events[220]);
ReleaseSemaphore(semaphores[143], 4, NULL);
ReleaseSemaphore(semaphores[272], 4, NULL);
ReleaseSemaphore(semaphores[294], 4, NULL);
SetEvent(events[743]);
ReleaseSemaphore(semaphores[132], 2, NULL);
ReleaseSemaphore(semaphores[68], 4, NULL);
ReleaseSemaphore(semaphores[37], 2, NULL);
}
}
void WINAPI Thread_212(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[719], INFINITE);
WaitForSingleObject(events[857], INFINITE);
WaitForSingleObject(events[916], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[158], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[23], 1, NULL);
SetEvent(events[30]);
SetEvent(events[644]);
SetEvent(events[508]);
SetEvent(events[221]);
ReleaseSemaphore(semaphores[54], 1, NULL);
ReleaseSemaphore(semaphores[243], 2, NULL);
ReleaseSemaphore(semaphores[127], 4, NULL);
ReleaseSemaphore(semaphores[40], 1, NULL);
} else {
WaitForSingleObject(events[883], INFINITE);
WaitForSingleObject(events[57], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[158], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[63], 3, NULL);
ReleaseSemaphore(semaphores[26], 4, NULL);
ReleaseSemaphore(semaphores[135], 3, NULL);
ReleaseSemaphore(semaphores[27], 1, NULL);
}
}
void WINAPI Thread_213(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[683], INFINITE);
WaitForSingleObject(events[944], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[74], INFINITE);
}
// good checks done
SetEvent(events[607]);
ReleaseSemaphore(semaphores[22], 3, NULL);
ReleaseSemaphore(semaphores[161], 4, NULL);
ReleaseSemaphore(semaphores[261], 1, NULL);
ReleaseSemaphore(semaphores[206], 4, NULL);
ReleaseSemaphore(semaphores[159], 3, NULL);
SetEvent(events[384]);
SetEvent(events[972]);
SetEvent(events[296]);
} else {
WaitForSingleObject(events[106], INFINITE);
WaitForSingleObject(events[331], INFINITE);
WaitForSingleObject(events[612], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[74], INFINITE);
}
// bad checks done
SetEvent(events[928]);
}
}
void WINAPI Thread_214(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[437], INFINITE);
WaitForSingleObject(events[746], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[122], INFINITE);
}
// good checks done
} else {
WaitForSingleObject(events[232], INFINITE);
WaitForSingleObject(events[183], INFINITE);
WaitForSingleObject(events[478], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[122], INFINITE);
}
// bad checks done
SetEvent(events[125]);
SetEvent(events[452]);
SetEvent(events[175]);
}
}
void WINAPI Thread_215(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[504], INFINITE);
// bad checks done
SetEvent(events[741]);
SetEvent(events[163]);
ReleaseSemaphore(semaphores[62], 2, NULL);
SetEvent(events[696]);
} else {
// good checks done
SetEvent(events[125]);
SetEvent(events[331]);
SetEvent(events[507]);
ReleaseSemaphore(semaphores[251], 1, NULL);
}
}
void WINAPI Thread_216(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[911], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[151], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[284], 1, NULL);
ReleaseSemaphore(semaphores[17], 3, NULL);
ReleaseSemaphore(semaphores[289], 4, NULL);
ReleaseSemaphore(semaphores[0], 3, NULL);
} else {
WaitForSingleObject(events[878], INFINITE);
WaitForSingleObject(events[228], INFINITE);
WaitForSingleObject(events[33], INFINITE);
WaitForSingleObject(events[989], INFINITE);
WaitForSingleObject(events[704], INFINITE);
WaitForSingleObject(events[232], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[151], INFINITE);
}
// good checks done
SetEvent(events[423]);
ReleaseSemaphore(semaphores[176], 2, NULL);
SetEvent(events[217]);
ReleaseSemaphore(semaphores[12], 3, NULL);
ReleaseSemaphore(semaphores[269], 1, NULL);
SetEvent(events[777]);
SetEvent(events[245]);
SetEvent(events[3]);
SetEvent(events[352]);
ReleaseSemaphore(semaphores[242], 4, NULL);
ReleaseSemaphore(semaphores[279], 2, NULL);
ReleaseSemaphore(semaphores[249], 4, NULL);
}
}
void WINAPI Thread_217(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[955], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[44], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[194], 4, NULL);
SetEvent(events[431]);
ReleaseSemaphore(semaphores[35], 3, NULL);
ReleaseSemaphore(semaphores[246], 4, NULL);
SetEvent(events[652]);
ReleaseSemaphore(semaphores[247], 2, NULL);
} else {
WaitForSingleObject(events[648], INFINITE);
WaitForSingleObject(events[48], INFINITE);
WaitForSingleObject(events[579], INFINITE);
WaitForSingleObject(events[633], INFINITE);
WaitForSingleObject(events[352], INFINITE);
WaitForSingleObject(events[737], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[44], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[94], 1, NULL);
ReleaseSemaphore(semaphores[209], 3, NULL);
ReleaseSemaphore(semaphores[6], 3, NULL);
}
}
void WINAPI Thread_218(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[424], INFINITE);
WaitForSingleObject(events[542], INFINITE);
WaitForSingleObject(events[716], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[124], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[213], 1, NULL);
SetEvent(events[73]);
SetEvent(events[313]);
ReleaseSemaphore(semaphores[8], 2, NULL);
SetEvent(events[860]);
SetEvent(events[159]);
SetEvent(events[729]);
} else {
WaitForSingleObject(events[446], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[124], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_219(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[839], INFINITE);
WaitForSingleObject(events[542], INFINITE);
WaitForSingleObject(events[786], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[197], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[34], 2, NULL);
ReleaseSemaphore(semaphores[95], 1, NULL);
ReleaseSemaphore(semaphores[112], 1, NULL);
ReleaseSemaphore(semaphores[55], 4, NULL);
SetEvent(events[168]);
} else {
WaitForSingleObject(events[911], INFINITE);
WaitForSingleObject(events[929], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[197], INFINITE);
}
// good checks done
SetEvent(events[11]);
SetEvent(events[452]);
SetEvent(events[119]);
ReleaseSemaphore(semaphores[173], 1, NULL);
ReleaseSemaphore(semaphores[43], 3, NULL);
ReleaseSemaphore(semaphores[54], 2, NULL);
ReleaseSemaphore(semaphores[40], 2, NULL);
}
}
void WINAPI Thread_220(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[243], INFINITE);
WaitForSingleObject(events[425], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[34], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 3, NULL);
ReleaseSemaphore(semaphores[104], 3, NULL);
SetEvent(events[869]);
SetEvent(events[93]);
ReleaseSemaphore(semaphores[159], 3, NULL);
SetEvent(events[657]);
ReleaseSemaphore(semaphores[167], 1, NULL);
} else {
// bad checks done
ReleaseSemaphore(semaphores[218], 2, NULL);
ReleaseSemaphore(semaphores[127], 1, NULL);
SetEvent(events[176]);
SetEvent(events[132]);
ReleaseSemaphore(semaphores[3], 1, NULL);
ReleaseSemaphore(semaphores[124], 2, NULL);
SetEvent(events[133]);
}
}
void WINAPI Thread_221(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[271], INFINITE);
WaitForSingleObject(events[338], INFINITE);
WaitForSingleObject(events[454], INFINITE);
WaitForSingleObject(events[313], INFINITE);
WaitForSingleObject(events[900], INFINITE);
WaitForSingleObject(events[695], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[86], INFINITE);
}
// good checks done
SetEvent(events[597]);
SetEvent(events[263]);
SetEvent(events[594]);
ReleaseSemaphore(semaphores[78], 3, NULL);
} else {
WaitForSingleObject(events[436], INFINITE);
WaitForSingleObject(events[1019], INFINITE);
WaitForSingleObject(events[297], INFINITE);
WaitForSingleObject(events[0], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[86], INFINITE);
}
// bad checks done
SetEvent(events[941]);
SetEvent(events[83]);
SetEvent(events[502]);
SetEvent(events[536]);
}
}
void WINAPI Thread_222(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[982], INFINITE);
WaitForSingleObject(events[936], INFINITE);
WaitForSingleObject(events[892], INFINITE);
WaitForSingleObject(events[706], INFINITE);
WaitForSingleObject(events[576], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[75], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[152], 3, NULL);
ReleaseSemaphore(semaphores[244], 2, NULL);
SetEvent(events[785]);
ReleaseSemaphore(semaphores[160], 2, NULL);
ReleaseSemaphore(semaphores[208], 2, NULL);
ReleaseSemaphore(semaphores[124], 4, NULL);
ReleaseSemaphore(semaphores[62], 1, NULL);
ReleaseSemaphore(semaphores[44], 2, NULL);
SetEvent(events[747]);
} else {
WaitForSingleObject(events[802], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[75], INFINITE);
}
// bad checks done
SetEvent(events[182]);
ReleaseSemaphore(semaphores[33], 2, NULL);
ReleaseSemaphore(semaphores[124], 1, NULL);
ReleaseSemaphore(semaphores[17], 1, NULL);
ReleaseSemaphore(semaphores[122], 4, NULL);
ReleaseSemaphore(semaphores[83], 1, NULL);
SetEvent(events[53]);
SetEvent(events[197]);
}
}
void WINAPI Thread_223(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1025], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[0], INFINITE);
}
// bad checks done
SetEvent(events[153]);
SetEvent(events[1031]);
SetEvent(events[408]);
ReleaseSemaphore(semaphores[26], 1, NULL);
ReleaseSemaphore(semaphores[107], 3, NULL);
ReleaseSemaphore(semaphores[157], 1, NULL);
ReleaseSemaphore(semaphores[97], 1, NULL);
} else {
WaitForSingleObject(events[888], INFINITE);
WaitForSingleObject(events[940], INFINITE);
WaitForSingleObject(events[149], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[0], INFINITE);
}
// good checks done
SetEvent(events[871]);
ReleaseSemaphore(semaphores[131], 1, NULL);
SetEvent(events[1023]);
ReleaseSemaphore(semaphores[201], 4, NULL);
SetEvent(events[875]);
SetEvent(events[995]);
SetEvent(events[881]);
}
}
void WINAPI Thread_224(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[8], INFINITE);
WaitForSingleObject(events[76], INFINITE);
WaitForSingleObject(events[653], INFINITE);
WaitForSingleObject(events[270], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[241], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[263], 1, NULL);
SetEvent(events[0]);
SetEvent(events[740]);
SetEvent(events[68]);
ReleaseSemaphore(semaphores[32], 2, NULL);
ReleaseSemaphore(semaphores[177], 3, NULL);
ReleaseSemaphore(semaphores[230], 2, NULL);
SetEvent(events[521]);
SetEvent(events[35]);
SetEvent(events[773]);
SetEvent(events[75]);
} else {
WaitForSingleObject(events[180], INFINITE);
WaitForSingleObject(events[348], INFINITE);
WaitForSingleObject(events[942], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[241], INFINITE);
}
// bad checks done
SetEvent(events[989]);
ReleaseSemaphore(semaphores[37], 4, NULL);
ReleaseSemaphore(semaphores[114], 3, NULL);
ReleaseSemaphore(semaphores[213], 4, NULL);
SetEvent(events[834]);
ReleaseSemaphore(semaphores[11], 3, NULL);
ReleaseSemaphore(semaphores[167], 2, NULL);
SetEvent(events[664]);
}
}
void WINAPI Thread_225(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[606], INFINITE);
WaitForSingleObject(events[46], INFINITE);
WaitForSingleObject(events[563], INFINITE);
WaitForSingleObject(events[0], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[25], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[9], 2, NULL);
SetEvent(events[558]);
SetEvent(events[184]);
ReleaseSemaphore(semaphores[103], 2, NULL);
ReleaseSemaphore(semaphores[246], 3, NULL);
ReleaseSemaphore(semaphores[249], 2, NULL);
ReleaseSemaphore(semaphores[208], 2, NULL);
SetEvent(events[132]);
SetEvent(events[942]);
} else {
WaitForSingleObject(events[999], INFINITE);
WaitForSingleObject(events[316], INFINITE);
WaitForSingleObject(events[339], INFINITE);
WaitForSingleObject(events[288], INFINITE);
WaitForSingleObject(events[753], INFINITE);
WaitForSingleObject(events[495], INFINITE);
WaitForSingleObject(events[569], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[25], INFINITE);
}
// good checks done
SetEvent(events[229]);
ReleaseSemaphore(semaphores[49], 4, NULL);
ReleaseSemaphore(semaphores[20], 4, NULL);
ReleaseSemaphore(semaphores[299], 3, NULL);
ReleaseSemaphore(semaphores[193], 2, NULL);
SetEvent(events[356]);
SetEvent(events[784]);
ReleaseSemaphore(semaphores[183], 3, NULL);
SetEvent(events[686]);
ReleaseSemaphore(semaphores[247], 1, NULL);
}
}
void WINAPI Thread_226(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[82], INFINITE);
WaitForSingleObject(events[471], INFINITE);
WaitForSingleObject(events[916], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[23], INFINITE);
}
// bad checks done
SetEvent(events[845]);
ReleaseSemaphore(semaphores[271], 1, NULL);
ReleaseSemaphore(semaphores[254], 3, NULL);
ReleaseSemaphore(semaphores[198], 2, NULL);
SetEvent(events[244]);
SetEvent(events[478]);
SetEvent(events[966]);
SetEvent(events[553]);
} else {
WaitForSingleObject(events[467], INFINITE);
WaitForSingleObject(events[583], INFINITE);
WaitForSingleObject(events[947], INFINITE);
WaitForSingleObject(events[997], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[23], INFINITE);
}
// good checks done
SetEvent(events[379]);
SetEvent(events[466]);
SetEvent(events[511]);
ReleaseSemaphore(semaphores[299], 1, NULL);
SetEvent(events[366]);
SetEvent(events[964]);
ReleaseSemaphore(semaphores[212], 1, NULL);
SetEvent(events[572]);
SetEvent(events[365]);
}
}
void WINAPI Thread_227(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[230], INFINITE);
WaitForSingleObject(events[196], INFINITE);
WaitForSingleObject(events[445], INFINITE);
WaitForSingleObject(events[216], INFINITE);
WaitForSingleObject(events[535], INFINITE);
WaitForSingleObject(events[287], INFINITE);
WaitForSingleObject(events[238], INFINITE);
for (i = 0; i < 22; i++) {
    WaitForSingleObject(semaphores[114], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[105], 1, NULL);
SetEvent(events[190]);
SetEvent(events[618]);
SetEvent(events[658]);
SetEvent(events[722]);
} else {
// bad checks done
SetEvent(events[74]);
ReleaseSemaphore(semaphores[42], 1, NULL);
ReleaseSemaphore(semaphores[296], 2, NULL);
ReleaseSemaphore(semaphores[290], 2, NULL);
ReleaseSemaphore(semaphores[265], 4, NULL);
}
}
void WINAPI Thread_228(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[261], INFINITE);
WaitForSingleObject(events[380], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[230], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[35], 4, NULL);
ReleaseSemaphore(semaphores[117], 2, NULL);
SetEvent(events[7]);
} else {
WaitForSingleObject(events[214], INFINITE);
WaitForSingleObject(events[684], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[230], INFINITE);
}
// good checks done
SetEvent(events[163]);
ReleaseSemaphore(semaphores[104], 2, NULL);
ReleaseSemaphore(semaphores[261], 3, NULL);
SetEvent(events[28]);
SetEvent(events[392]);
SetEvent(events[222]);
SetEvent(events[855]);
ReleaseSemaphore(semaphores[207], 2, NULL);
ReleaseSemaphore(semaphores[248], 1, NULL);
ReleaseSemaphore(semaphores[240], 1, NULL);
ReleaseSemaphore(semaphores[167], 3, NULL);
SetEvent(events[299]);
}
}
void WINAPI Thread_229(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[236], INFINITE);
WaitForSingleObject(events[183], INFINITE);
WaitForSingleObject(events[144], INFINITE);
WaitForSingleObject(events[641], INFINITE);
WaitForSingleObject(events[350], INFINITE);
WaitForSingleObject(events[140], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[165], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[81], 4, NULL);
ReleaseSemaphore(semaphores[253], 2, NULL);
ReleaseSemaphore(semaphores[79], 2, NULL);
ReleaseSemaphore(semaphores[31], 2, NULL);
ReleaseSemaphore(semaphores[220], 1, NULL);
ReleaseSemaphore(semaphores[13], 4, NULL);
SetEvent(events[988]);
} else {
WaitForSingleObject(events[918], INFINITE);
WaitForSingleObject(events[71], INFINITE);
WaitForSingleObject(events[442], INFINITE);
WaitForSingleObject(events[23], INFINITE);
WaitForSingleObject(events[449], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[165], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[111], 4, NULL);
}
}
void WINAPI Thread_230(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[709], INFINITE);
WaitForSingleObject(events[1012], INFINITE);
WaitForSingleObject(events[873], INFINITE);
WaitForSingleObject(events[88], INFINITE);
WaitForSingleObject(events[340], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[144], INFINITE);
}
// good checks done
SetEvent(events[152]);
ReleaseSemaphore(semaphores[271], 1, NULL);
ReleaseSemaphore(semaphores[253], 1, NULL);
ReleaseSemaphore(semaphores[79], 4, NULL);
ReleaseSemaphore(semaphores[296], 2, NULL);
SetEvent(events[477]);
ReleaseSemaphore(semaphores[43], 2, NULL);
SetEvent(events[938]);
} else {
// bad checks done
SetEvent(events[118]);
SetEvent(events[764]);
ReleaseSemaphore(semaphores[99], 1, NULL);
ReleaseSemaphore(semaphores[253], 4, NULL);
SetEvent(events[668]);
ReleaseSemaphore(semaphores[145], 4, NULL);
}
}
void WINAPI Thread_231(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[506], INFINITE);
WaitForSingleObject(events[223], INFINITE);
WaitForSingleObject(events[849], INFINITE);
WaitForSingleObject(events[64], INFINITE);
WaitForSingleObject(events[832], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[71], 3, NULL);
SetEvent(events[166]);
ReleaseSemaphore(semaphores[238], 3, NULL);
} else {
WaitForSingleObject(events[158], INFINITE);
WaitForSingleObject(events[446], INFINITE);
WaitForSingleObject(events[825], INFINITE);
WaitForSingleObject(events[420], INFINITE);
WaitForSingleObject(events[282], INFINITE);
WaitForSingleObject(events[822], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[207], INFINITE);
}
// good checks done
SetEvent(events[898]);
SetEvent(events[447]);
}
}
void WINAPI Thread_232(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[267], INFINITE);
WaitForSingleObject(events[996], INFINITE);
WaitForSingleObject(events[940], INFINITE);
WaitForSingleObject(events[1016], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[150], 4, NULL);
SetEvent(events[117]);
} else {
WaitForSingleObject(events[985], INFINITE);
WaitForSingleObject(events[93], INFINITE);
WaitForSingleObject(events[453], INFINITE);
WaitForSingleObject(events[1006], INFINITE);
WaitForSingleObject(events[678], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[229], INFINITE);
}
// good checks done
SetEvent(events[820]);
SetEvent(events[580]);
}
}
void WINAPI Thread_233(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[391], INFINITE);
WaitForSingleObject(events[795], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[180], INFINITE);
}
// bad checks done
SetEvent(events[436]);
SetEvent(events[869]);
} else {
WaitForSingleObject(events[800], INFINITE);
WaitForSingleObject(events[567], INFINITE);
WaitForSingleObject(events[502], INFINITE);
WaitForSingleObject(events[448], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[180], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[129], 4, NULL);
SetEvent(events[196]);
ReleaseSemaphore(semaphores[231], 3, NULL);
ReleaseSemaphore(semaphores[229], 3, NULL);
SetEvent(events[978]);
ReleaseSemaphore(semaphores[97], 4, NULL);
ReleaseSemaphore(semaphores[159], 2, NULL);
SetEvent(events[809]);
ReleaseSemaphore(semaphores[141], 4, NULL);
ReleaseSemaphore(semaphores[50], 2, NULL);
SetEvent(events[612]);
SetEvent(events[186]);
ReleaseSemaphore(semaphores[246], 1, NULL);
}
}
void WINAPI Thread_234(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[373], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[251], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[55], 1, NULL);
SetEvent(events[366]);
SetEvent(events[925]);
} else {
WaitForSingleObject(events[174], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[251], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[39], 2, NULL);
SetEvent(events[484]);
ReleaseSemaphore(semaphores[264], 3, NULL);
SetEvent(events[680]);
SetEvent(events[617]);
SetEvent(events[135]);
SetEvent(events[922]);
ReleaseSemaphore(semaphores[82], 2, NULL);
SetEvent(events[251]);
SetEvent(events[494]);
ReleaseSemaphore(semaphores[19], 4, NULL);
}
}
void WINAPI Thread_235(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[906], INFINITE);
WaitForSingleObject(events[302], INFINITE);
WaitForSingleObject(events[682], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[23], 4, NULL);
SetEvent(events[550]);
ReleaseSemaphore(semaphores[233], 2, NULL);
ReleaseSemaphore(semaphores[63], 3, NULL);
SetEvent(events[145]);
} else {
WaitForSingleObject(events[920], INFINITE);
WaitForSingleObject(events[844], INFINITE);
WaitForSingleObject(events[379], INFINITE);
WaitForSingleObject(events[701], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[280], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[110], 1, NULL);
ReleaseSemaphore(semaphores[117], 4, NULL);
ReleaseSemaphore(semaphores[274], 3, NULL);
ReleaseSemaphore(semaphores[235], 3, NULL);
ReleaseSemaphore(semaphores[21], 3, NULL);
ReleaseSemaphore(semaphores[151], 4, NULL);
}
}
void WINAPI Thread_236(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[83], INFINITE);
WaitForSingleObject(events[403], INFINITE);
WaitForSingleObject(events[231], INFINITE);
WaitForSingleObject(events[561], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[188], INFINITE);
}
// good checks done
SetEvent(events[979]);
ReleaseSemaphore(semaphores[9], 2, NULL);
SetEvent(events[564]);
ReleaseSemaphore(semaphores[126], 3, NULL);
SetEvent(events[721]);
ReleaseSemaphore(semaphores[216], 1, NULL);
ReleaseSemaphore(semaphores[134], 1, NULL);
ReleaseSemaphore(semaphores[107], 4, NULL);
ReleaseSemaphore(semaphores[64], 1, NULL);
ReleaseSemaphore(semaphores[223], 4, NULL);
SetEvent(events[382]);
ReleaseSemaphore(semaphores[146], 1, NULL);
ReleaseSemaphore(semaphores[144], 2, NULL);
ReleaseSemaphore(semaphores[165], 4, NULL);
ReleaseSemaphore(semaphores[182], 1, NULL);
ReleaseSemaphore(semaphores[184], 3, NULL);
} else {
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[188], INFINITE);
}
// bad checks done
SetEvent(events[988]);
ReleaseSemaphore(semaphores[211], 3, NULL);
ReleaseSemaphore(semaphores[34], 2, NULL);
ReleaseSemaphore(semaphores[104], 4, NULL);
SetEvent(events[253]);
ReleaseSemaphore(semaphores[270], 3, NULL);
SetEvent(events[77]);
SetEvent(events[750]);
}
}
void WINAPI Thread_237(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[526], INFINITE);
WaitForSingleObject(events[81], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[142], INFINITE);
}
// good checks done
SetEvent(events[626]);
SetEvent(events[360]);
SetEvent(events[650]);
ReleaseSemaphore(semaphores[174], 4, NULL);
ReleaseSemaphore(semaphores[2], 4, NULL);
SetEvent(events[553]);
ReleaseSemaphore(semaphores[8], 2, NULL);
ReleaseSemaphore(semaphores[268], 4, NULL);
ReleaseSemaphore(semaphores[203], 2, NULL);
} else {
WaitForSingleObject(events[330], INFINITE);
WaitForSingleObject(events[602], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[142], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[289], 4, NULL);
ReleaseSemaphore(semaphores[57], 2, NULL);
ReleaseSemaphore(semaphores[211], 4, NULL);
ReleaseSemaphore(semaphores[195], 2, NULL);
}
}
void WINAPI Thread_238(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[915], INFINITE);
WaitForSingleObject(events[258], INFINITE);
WaitForSingleObject(events[316], INFINITE);
WaitForSingleObject(events[452], INFINITE);
WaitForSingleObject(events[756], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[17], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[222], 3, NULL);
ReleaseSemaphore(semaphores[297], 4, NULL);
ReleaseSemaphore(semaphores[115], 2, NULL);
ReleaseSemaphore(semaphores[22], 1, NULL);
} else {
WaitForSingleObject(events[499], INFINITE);
WaitForSingleObject(events[886], INFINITE);
WaitForSingleObject(events[27], INFINITE);
WaitForSingleObject(events[451], INFINITE);
WaitForSingleObject(events[245], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[17], INFINITE);
}
// good checks done
SetEvent(events[732]);
SetEvent(events[126]);
ReleaseSemaphore(semaphores[86], 2, NULL);
ReleaseSemaphore(semaphores[174], 4, NULL);
SetEvent(events[280]);
ReleaseSemaphore(semaphores[84], 4, NULL);
}
}
void WINAPI Thread_239(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[963], INFINITE);
WaitForSingleObject(events[739], INFINITE);
WaitForSingleObject(events[797], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[252], INFINITE);
}
// bad checks done
SetEvent(events[981]);
SetEvent(events[371]);
SetEvent(events[1014]);
SetEvent(events[378]);
ReleaseSemaphore(semaphores[82], 2, NULL);
ReleaseSemaphore(semaphores[281], 1, NULL);
} else {
WaitForSingleObject(events[40], INFINITE);
WaitForSingleObject(events[358], INFINITE);
WaitForSingleObject(events[99], INFINITE);
WaitForSingleObject(events[762], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[252], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[113], 1, NULL);
ReleaseSemaphore(semaphores[79], 4, NULL);
SetEvent(events[993]);
ReleaseSemaphore(semaphores[43], 1, NULL);
ReleaseSemaphore(semaphores[243], 1, NULL);
}
}
void WINAPI Thread_240(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[74], INFINITE);
WaitForSingleObject(events[550], INFINITE);
WaitForSingleObject(events[760], INFINITE);
WaitForSingleObject(events[542], INFINITE);
WaitForSingleObject(events[341], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[13], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[180], 2, NULL);
ReleaseSemaphore(semaphores[203], 2, NULL);
} else {
WaitForSingleObject(events[376], INFINITE);
WaitForSingleObject(events[450], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[13], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 1, NULL);
ReleaseSemaphore(semaphores[275], 2, NULL);
ReleaseSemaphore(semaphores[121], 3, NULL);
SetEvent(events[399]);
SetEvent(events[816]);
SetEvent(events[959]);
ReleaseSemaphore(semaphores[219], 4, NULL);
}
}
void WINAPI Thread_241(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[804], INFINITE);
WaitForSingleObject(events[926], INFINITE);
WaitForSingleObject(events[853], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[206], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[58], 1, NULL);
SetEvent(events[808]);
} else {
WaitForSingleObject(events[22], INFINITE);
WaitForSingleObject(events[373], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[206], INFINITE);
}
// bad checks done
SetEvent(events[700]);
ReleaseSemaphore(semaphores[170], 2, NULL);
ReleaseSemaphore(semaphores[129], 2, NULL);
SetEvent(events[736]);
SetEvent(events[583]);
ReleaseSemaphore(semaphores[205], 2, NULL);
SetEvent(events[437]);
ReleaseSemaphore(semaphores[139], 3, NULL);
SetEvent(events[14]);
ReleaseSemaphore(semaphores[195], 2, NULL);
}
}
void WINAPI Thread_242(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[858], INFINITE);
WaitForSingleObject(events[721], INFINITE);
WaitForSingleObject(events[373], INFINITE);
WaitForSingleObject(events[301], INFINITE);
WaitForSingleObject(events[501], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[155], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[227], 2, NULL);
SetEvent(events[558]);
SetEvent(events[9]);
SetEvent(events[803]);
ReleaseSemaphore(semaphores[186], 2, NULL);
ReleaseSemaphore(semaphores[31], 2, NULL);
SetEvent(events[357]);
SetEvent(events[176]);
ReleaseSemaphore(semaphores[71], 4, NULL);
} else {
WaitForSingleObject(events[847], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[155], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[202], 4, NULL);
ReleaseSemaphore(semaphores[280], 4, NULL);
ReleaseSemaphore(semaphores[208], 1, NULL);
ReleaseSemaphore(semaphores[254], 1, NULL);
SetEvent(events[646]);
ReleaseSemaphore(semaphores[252], 3, NULL);
SetEvent(events[81]);
SetEvent(events[634]);
SetEvent(events[42]);
}
}
void WINAPI Thread_243(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[309], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[208], INFINITE);
}
// good checks done
SetEvent(events[404]);
ReleaseSemaphore(semaphores[94], 3, NULL);
SetEvent(events[695]);
ReleaseSemaphore(semaphores[174], 1, NULL);
SetEvent(events[198]);
SetEvent(events[632]);
SetEvent(events[575]);
} else {
WaitForSingleObject(events[807], INFINITE);
WaitForSingleObject(events[1003], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[208], INFINITE);
}
// bad checks done
SetEvent(events[867]);
SetEvent(events[333]);
SetEvent(events[759]);
SetEvent(events[340]);
SetEvent(events[652]);
ReleaseSemaphore(semaphores[286], 2, NULL);
}
}
void WINAPI Thread_244(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[852], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[77], INFINITE);
}
// bad checks done
SetEvent(events[978]);
SetEvent(events[763]);
ReleaseSemaphore(semaphores[151], 4, NULL);
SetEvent(events[926]);
ReleaseSemaphore(semaphores[266], 4, NULL);
ReleaseSemaphore(semaphores[233], 3, NULL);
SetEvent(events[1004]);
ReleaseSemaphore(semaphores[211], 4, NULL);
} else {
WaitForSingleObject(events[901], INFINITE);
WaitForSingleObject(events[914], INFINITE);
WaitForSingleObject(events[354], INFINITE);
WaitForSingleObject(events[160], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[77], INFINITE);
}
// good checks done
SetEvent(events[532]);
ReleaseSemaphore(semaphores[211], 1, NULL);
SetEvent(events[385]);
ReleaseSemaphore(semaphores[290], 1, NULL);
ReleaseSemaphore(semaphores[54], 4, NULL);
}
}
void WINAPI Thread_245(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[677], INFINITE);
WaitForSingleObject(events[70], INFINITE);
WaitForSingleObject(events[207], INFINITE);
WaitForSingleObject(events[782], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[119], INFINITE);
}
// good checks done
SetEvent(events[518]);
SetEvent(events[455]);
SetEvent(events[706]);
} else {
WaitForSingleObject(events[145], INFINITE);
WaitForSingleObject(events[439], INFINITE);
WaitForSingleObject(events[82], INFINITE);
WaitForSingleObject(events[243], INFINITE);
WaitForSingleObject(events[866], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[119], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[175], 2, NULL);
ReleaseSemaphore(semaphores[147], 2, NULL);
SetEvent(events[294]);
ReleaseSemaphore(semaphores[222], 3, NULL);
SetEvent(events[576]);
ReleaseSemaphore(semaphores[240], 4, NULL);
SetEvent(events[333]);
ReleaseSemaphore(semaphores[233], 1, NULL);
SetEvent(events[11]);
SetEvent(events[708]);
}
}
void WINAPI Thread_246(int bit) {
int i = 0;
if (bit) {
// good checks done
SetEvent(events[903]);
ReleaseSemaphore(semaphores[195], 4, NULL);
ReleaseSemaphore(semaphores[120], 2, NULL);
SetEvent(events[173]);
} else {
WaitForSingleObject(events[827], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[65], 1, NULL);
ReleaseSemaphore(semaphores[108], 1, NULL);
}
}
void WINAPI Thread_247(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[721], INFINITE);
WaitForSingleObject(events[133], INFINITE);
WaitForSingleObject(events[582], INFINITE);
WaitForSingleObject(events[579], INFINITE);
// bad checks done
SetEvent(events[346]);
SetEvent(events[345]);
SetEvent(events[830]);
ReleaseSemaphore(semaphores[71], 2, NULL);
SetEvent(events[539]);
SetEvent(events[304]);
} else {
WaitForSingleObject(events[656], INFINITE);
WaitForSingleObject(events[688], INFINITE);
WaitForSingleObject(events[415], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[210], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[94], 1, NULL);
SetEvent(events[643]);
ReleaseSemaphore(semaphores[225], 1, NULL);
SetEvent(events[199]);
ReleaseSemaphore(semaphores[6], 3, NULL);
}
}
void WINAPI Thread_248(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[484], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[163], INFINITE);
}
// good checks done
SetEvent(events[501]);
ReleaseSemaphore(semaphores[158], 3, NULL);
SetEvent(events[111]);
ReleaseSemaphore(semaphores[107], 3, NULL);
SetEvent(events[268]);
ReleaseSemaphore(semaphores[64], 3, NULL);
ReleaseSemaphore(semaphores[223], 3, NULL);
SetEvent(events[132]);
ReleaseSemaphore(semaphores[144], 1, NULL);
} else {
WaitForSingleObject(events[829], INFINITE);
WaitForSingleObject(events[458], INFINITE);
WaitForSingleObject(events[621], INFINITE);
WaitForSingleObject(events[390], INFINITE);
WaitForSingleObject(events[496], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[163], INFINITE);
}
// bad checks done
SetEvent(events[10]);
SetEvent(events[294]);
ReleaseSemaphore(semaphores[300], 4, NULL);
SetEvent(events[721]);
SetEvent(events[965]);
SetEvent(events[604]);
ReleaseSemaphore(semaphores[148], 3, NULL);
}
}
void WINAPI Thread_249(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[899], INFINITE);
WaitForSingleObject(events[456], INFINITE);
WaitForSingleObject(events[876], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[73], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[9], 4, NULL);
ReleaseSemaphore(semaphores[3], 2, NULL);
ReleaseSemaphore(semaphores[158], 4, NULL);
ReleaseSemaphore(semaphores[134], 1, NULL);
SetEvent(events[234]);
SetEvent(events[350]);
ReleaseSemaphore(semaphores[197], 2, NULL);
ReleaseSemaphore(semaphores[112], 2, NULL);
SetEvent(events[31]);
} else {
WaitForSingleObject(events[292], INFINITE);
WaitForSingleObject(events[161], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[73], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[190], 3, NULL);
ReleaseSemaphore(semaphores[69], 3, NULL);
ReleaseSemaphore(semaphores[260], 4, NULL);
ReleaseSemaphore(semaphores[8], 3, NULL);
SetEvent(events[237]);
}
}
void WINAPI Thread_250(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1030], INFINITE);
WaitForSingleObject(events[249], INFINITE);
WaitForSingleObject(events[204], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[253], INFINITE);
}
// bad checks done
SetEvent(events[484]);
SetEvent(events[907]);
SetEvent(events[596]);
ReleaseSemaphore(semaphores[295], 1, NULL);
} else {
WaitForSingleObject(events[634], INFINITE);
WaitForSingleObject(events[429], INFINITE);
WaitForSingleObject(events[480], INFINITE);
WaitForSingleObject(events[847], INFINITE);
WaitForSingleObject(events[529], INFINITE);
WaitForSingleObject(events[38], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[253], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[280], 4, NULL);
ReleaseSemaphore(semaphores[10], 2, NULL);
SetEvent(events[421]);
ReleaseSemaphore(semaphores[121], 3, NULL);
ReleaseSemaphore(semaphores[169], 4, NULL);
ReleaseSemaphore(semaphores[284], 4, NULL);
SetEvent(events[332]);
SetEvent(events[197]);
ReleaseSemaphore(semaphores[247], 3, NULL);
SetEvent(events[677]);
}
}
void WINAPI Thread_251(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[341], INFINITE);
WaitForSingleObject(events[1012], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[284], INFINITE);
}
// bad checks done
SetEvent(events[901]);
ReleaseSemaphore(semaphores[159], 1, NULL);
SetEvent(events[599]);
ReleaseSemaphore(semaphores[184], 1, NULL);
SetEvent(events[973]);
SetEvent(events[417]);
} else {
WaitForSingleObject(events[481], INFINITE);
WaitForSingleObject(events[541], INFINITE);
WaitForSingleObject(events[145], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[284], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[137], 2, NULL);
SetEvent(events[25]);
ReleaseSemaphore(semaphores[270], 2, NULL);
SetEvent(events[430]);
SetEvent(events[850]);
ReleaseSemaphore(semaphores[28], 2, NULL);
ReleaseSemaphore(semaphores[151], 2, NULL);
ReleaseSemaphore(semaphores[37], 2, NULL);
}
}
void WINAPI Thread_252(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[950], INFINITE);
WaitForSingleObject(events[17], INFINITE);
WaitForSingleObject(events[739], INFINITE);
WaitForSingleObject(events[510], INFINITE);
WaitForSingleObject(events[12], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[190], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[33], 2, NULL);
ReleaseSemaphore(semaphores[2], 3, NULL);
ReleaseSemaphore(semaphores[8], 4, NULL);
} else {
// bad checks done
SetEvent(events[763]);
SetEvent(events[100]);
ReleaseSemaphore(semaphores[142], 1, NULL);
SetEvent(events[772]);
SetEvent(events[906]);
SetEvent(events[137]);
ReleaseSemaphore(semaphores[200], 4, NULL);
ReleaseSemaphore(semaphores[7], 3, NULL);
}
}
void WINAPI Thread_253(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[396], INFINITE);
WaitForSingleObject(events[1032], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[9], INFINITE);
}
// good checks done
SetEvent(events[768]);
ReleaseSemaphore(semaphores[88], 2, NULL);
SetEvent(events[101]);
SetEvent(events[997]);
ReleaseSemaphore(semaphores[186], 4, NULL);
ReleaseSemaphore(semaphores[296], 3, NULL);
SetEvent(events[730]);
ReleaseSemaphore(semaphores[243], 2, NULL);
ReleaseSemaphore(semaphores[40], 3, NULL);
} else {
WaitForSingleObject(events[519], INFINITE);
WaitForSingleObject(events[562], INFINITE);
// bad checks done
SetEvent(events[487]);
SetEvent(events[950]);
SetEvent(events[1016]);
SetEvent(events[231]);
}
}
void WINAPI Thread_254(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[568], INFINITE);
WaitForSingleObject(events[651], INFINITE);
WaitForSingleObject(events[263], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[59], INFINITE);
}
// good checks done
SetEvent(events[246]);
SetEvent(events[318]);
ReleaseSemaphore(semaphores[198], 2, NULL);
ReleaseSemaphore(semaphores[282], 2, NULL);
ReleaseSemaphore(semaphores[162], 2, NULL);
SetEvent(events[94]);
ReleaseSemaphore(semaphores[301], 1, NULL);
SetEvent(events[1016]);
ReleaseSemaphore(semaphores[196], 4, NULL);
ReleaseSemaphore(semaphores[205], 4, NULL);
} else {
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[59], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[122], 2, NULL);
ReleaseSemaphore(semaphores[206], 4, NULL);
SetEvent(events[574]);
SetEvent(events[143]);
ReleaseSemaphore(semaphores[283], 2, NULL);
SetEvent(events[666]);
}
}
void WINAPI Thread_255(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1001], INFINITE);
WaitForSingleObject(events[147], INFINITE);
WaitForSingleObject(events[261], INFINITE);
WaitForSingleObject(events[650], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[85], INFINITE);
}
// bad checks done
SetEvent(events[884]);
SetEvent(events[611]);
ReleaseSemaphore(semaphores[203], 1, NULL);
SetEvent(events[202]);
} else {
WaitForSingleObject(events[4], INFINITE);
WaitForSingleObject(events[812], INFINITE);
WaitForSingleObject(events[20], INFINITE);
WaitForSingleObject(events[810], INFINITE);
WaitForSingleObject(events[871], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[85], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[91], 1, NULL);
SetEvent(events[96]);
ReleaseSemaphore(semaphores[277], 3, NULL);
ReleaseSemaphore(semaphores[270], 2, NULL);
ReleaseSemaphore(semaphores[143], 1, NULL);
ReleaseSemaphore(semaphores[132], 1, NULL);
ReleaseSemaphore(semaphores[21], 3, NULL);
}
}
void WINAPI Thread_256(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[87], INFINITE);
WaitForSingleObject(events[766], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[286], INFINITE);
}
// good checks done
} else {
WaitForSingleObject(events[25], INFINITE);
WaitForSingleObject(events[751], INFINITE);
WaitForSingleObject(events[162], INFINITE);
// bad checks done
SetEvent(events[845]);
SetEvent(events[54]);
ReleaseSemaphore(semaphores[248], 3, NULL);
SetEvent(events[467]);
SetEvent(events[1010]);
}
}
void WINAPI Thread_257(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[120], INFINITE);
}
// good checks done
SetEvent(events[202]);
ReleaseSemaphore(semaphores[264], 4, NULL);
ReleaseSemaphore(semaphores[221], 1, NULL);
SetEvent(events[781]);
SetEvent(events[231]);
SetEvent(events[906]);
SetEvent(events[958]);
ReleaseSemaphore(semaphores[187], 4, NULL);
ReleaseSemaphore(semaphores[145], 4, NULL);
SetEvent(events[846]);
} else {
WaitForSingleObject(events[323], INFINITE);
WaitForSingleObject(events[400], INFINITE);
WaitForSingleObject(events[868], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[120], INFINITE);
}
// bad checks done
SetEvent(events[377]);
ReleaseSemaphore(semaphores[124], 1, NULL);
SetEvent(events[376]);
SetEvent(events[337]);
SetEvent(events[368]);
SetEvent(events[985]);
}
}
void WINAPI Thread_258(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1002], INFINITE);
WaitForSingleObject(events[956], INFINITE);
WaitForSingleObject(events[306], INFINITE);
WaitForSingleObject(events[819], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[291], INFINITE);
}
// good checks done
SetEvent(events[1024]);
SetEvent(events[347]);
ReleaseSemaphore(semaphores[35], 1, NULL);
ReleaseSemaphore(semaphores[168], 4, NULL);
ReleaseSemaphore(semaphores[125], 3, NULL);
ReleaseSemaphore(semaphores[69], 2, NULL);
ReleaseSemaphore(semaphores[57], 1, NULL);
} else {
WaitForSingleObject(events[890], INFINITE);
WaitForSingleObject(events[725], INFINITE);
WaitForSingleObject(events[76], INFINITE);
WaitForSingleObject(events[663], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[291], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[288], 4, NULL);
SetEvent(events[647]);
}
}
void WINAPI Thread_259(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[699], INFINITE);
WaitForSingleObject(events[68], INFINITE);
WaitForSingleObject(events[705], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[273], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 3, NULL);
ReleaseSemaphore(semaphores[289], 2, NULL);
ReleaseSemaphore(semaphores[161], 4, NULL);
SetEvent(events[476]);
ReleaseSemaphore(semaphores[261], 3, NULL);
ReleaseSemaphore(semaphores[260], 4, NULL);
SetEvent(events[882]);
SetEvent(events[909]);
ReleaseSemaphore(semaphores[240], 1, NULL);
} else {
WaitForSingleObject(events[806], INFINITE);
WaitForSingleObject(events[708], INFINITE);
WaitForSingleObject(events[396], INFINITE);
WaitForSingleObject(events[418], INFINITE);
WaitForSingleObject(events[358], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[273], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[247], 3, NULL);
ReleaseSemaphore(semaphores[284], 1, NULL);
SetEvent(events[724]);
ReleaseSemaphore(semaphores[260], 4, NULL);
ReleaseSemaphore(semaphores[127], 4, NULL);
SetEvent(events[207]);
SetEvent(events[665]);
ReleaseSemaphore(semaphores[133], 3, NULL);
}
}
void WINAPI Thread_260(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[827], INFINITE);
WaitForSingleObject(events[841], INFINITE);
WaitForSingleObject(events[272], INFINITE);
WaitForSingleObject(events[635], INFINITE);
WaitForSingleObject(events[260], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[47], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[179], 4, NULL);
SetEvent(events[843]);
SetEvent(events[849]);
ReleaseSemaphore(semaphores[124], 1, NULL);
SetEvent(events[742]);
} else {
WaitForSingleObject(events[373], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[47], INFINITE);
}
// bad checks done
SetEvent(events[472]);
ReleaseSemaphore(semaphores[116], 2, NULL);
}
}
void WINAPI Thread_261(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[362], INFINITE);
WaitForSingleObject(events[397], INFINITE);
// bad checks done
SetEvent(events[1020]);
} else {
WaitForSingleObject(events[958], INFINITE);
WaitForSingleObject(events[821], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[200], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[18], 4, NULL);
ReleaseSemaphore(semaphores[233], 3, NULL);
ReleaseSemaphore(semaphores[51], 2, NULL);
SetEvent(events[261]);
SetEvent(events[719]);
ReleaseSemaphore(semaphores[134], 2, NULL);
SetEvent(events[346]);
SetEvent(events[183]);
ReleaseSemaphore(semaphores[197], 4, NULL);
ReleaseSemaphore(semaphores[128], 4, NULL);
ReleaseSemaphore(semaphores[112], 4, NULL);
ReleaseSemaphore(semaphores[184], 4, NULL);
}
}
void WINAPI Thread_262(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[817], INFINITE);
WaitForSingleObject(events[225], INFINITE);
WaitForSingleObject(events[359], INFINITE);
WaitForSingleObject(events[575], INFINITE);
WaitForSingleObject(events[764], INFINITE);
for (i = 0; i < 22; i++) {
    WaitForSingleObject(semaphores[6], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[293], 3, NULL);
SetEvent(events[76]);
SetEvent(events[32]);
SetEvent(events[123]);
ReleaseSemaphore(semaphores[95], 2, NULL);
ReleaseSemaphore(semaphores[45], 2, NULL);
ReleaseSemaphore(semaphores[60], 4, NULL);
} else {
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[6], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[115], 3, NULL);
SetEvent(events[242]);
ReleaseSemaphore(semaphores[174], 2, NULL);
SetEvent(events[528]);
SetEvent(events[751]);
ReleaseSemaphore(semaphores[278], 3, NULL);
}
}
void WINAPI Thread_263(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[707], INFINITE);
WaitForSingleObject(events[679], INFINITE);
WaitForSingleObject(events[740], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[7], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[184], 2, NULL);
SetEvent(events[394]);
ReleaseSemaphore(semaphores[116], 1, NULL);
ReleaseSemaphore(semaphores[153], 1, NULL);
ReleaseSemaphore(semaphores[111], 4, NULL);
SetEvent(events[225]);
ReleaseSemaphore(semaphores[144], 2, NULL);
SetEvent(events[782]);
} else {
WaitForSingleObject(events[966], INFINITE);
WaitForSingleObject(events[128], INFINITE);
WaitForSingleObject(events[334], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[7], INFINITE);
}
// good checks done
SetEvent(events[827]);
ReleaseSemaphore(semaphores[297], 2, NULL);
SetEvent(events[598]);
SetEvent(events[7]);
SetEvent(events[609]);
ReleaseSemaphore(semaphores[132], 4, NULL);
ReleaseSemaphore(semaphores[28], 2, NULL);
}
}
void WINAPI Thread_264(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[281], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[192], INFINITE);
}
// bad checks done
SetEvent(events[584]);
SetEvent(events[31]);
SetEvent(events[274]);
SetEvent(events[554]);
SetEvent(events[990]);
ReleaseSemaphore(semaphores[38], 4, NULL);
} else {
WaitForSingleObject(events[50], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[192], INFINITE);
}
// good checks done
}
}
void WINAPI Thread_265(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[288], INFINITE);
WaitForSingleObject(events[124], INFINITE);
WaitForSingleObject(events[260], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[215], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[0], 1, NULL);
SetEvent(events[127]);
SetEvent(events[131]);
SetEvent(events[849]);
SetEvent(events[177]);
ReleaseSemaphore(semaphores[56], 2, NULL);
ReleaseSemaphore(semaphores[33], 3, NULL);
ReleaseSemaphore(semaphores[206], 2, NULL);
ReleaseSemaphore(semaphores[185], 4, NULL);
} else {
WaitForSingleObject(events[380], INFINITE);
WaitForSingleObject(events[808], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[215], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[87], 1, NULL);
SetEvent(events[578]);
SetEvent(events[50]);
}
}
void WINAPI Thread_266(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[495], INFINITE);
WaitForSingleObject(events[730], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[166], INFINITE);
}
// bad checks done
SetEvent(events[1030]);
SetEvent(events[312]);
SetEvent(events[784]);
SetEvent(events[905]);
ReleaseSemaphore(semaphores[285], 2, NULL);
SetEvent(events[609]);
} else {
WaitForSingleObject(events[574], INFINITE);
WaitForSingleObject(events[322], INFINITE);
WaitForSingleObject(events[269], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[166], INFINITE);
}
// good checks done
SetEvent(events[952]);
}
}
void WINAPI Thread_267(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[121], INFINITE);
WaitForSingleObject(events[316], INFINITE);
WaitForSingleObject(events[33], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[10], INFINITE);
}
// bad checks done
SetEvent(events[803]);
ReleaseSemaphore(semaphores[63], 4, NULL);
SetEvent(events[573]);
SetEvent(events[766]);
SetEvent(events[32]);
ReleaseSemaphore(semaphores[102], 1, NULL);
} else {
WaitForSingleObject(events[308], INFINITE);
WaitForSingleObject(events[286], INFINITE);
WaitForSingleObject(events[603], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[10], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[270], 2, NULL);
ReleaseSemaphore(semaphores[164], 3, NULL);
ReleaseSemaphore(semaphores[274], 2, NULL);
SetEvent(events[586]);
SetEvent(events[53]);
SetEvent(events[989]);
}
}
void WINAPI Thread_268(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[335], INFINITE);
WaitForSingleObject(events[797], INFINITE);
WaitForSingleObject(events[473], INFINITE);
WaitForSingleObject(events[742], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[245], INFINITE);
}
// good checks done
SetEvent(events[395]);
SetEvent(events[1009]);
SetEvent(events[764]);
} else {
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[245], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[204], 1, NULL);
SetEvent(events[939]);
}
}
void WINAPI Thread_269(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[165], INFINITE);
WaitForSingleObject(events[336], INFINITE);
WaitForSingleObject(events[405], INFINITE);
WaitForSingleObject(events[729], INFINITE);
WaitForSingleObject(events[632], INFINITE);
WaitForSingleObject(events[1009], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[149], INFINITE);
}
// good checks done
SetEvent(events[770]);
ReleaseSemaphore(semaphores[241], 1, NULL);
SetEvent(events[381]);
ReleaseSemaphore(semaphores[291], 1, NULL);
ReleaseSemaphore(semaphores[45], 2, NULL);
SetEvent(events[278]);
ReleaseSemaphore(semaphores[78], 2, NULL);
} else {
WaitForSingleObject(events[582], INFINITE);
WaitForSingleObject(events[588], INFINITE);
WaitForSingleObject(events[239], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[149], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[23], 1, NULL);
SetEvent(events[745]);
SetEvent(events[368]);
SetEvent(events[49]);
ReleaseSemaphore(semaphores[195], 4, NULL);
SetEvent(events[500]);
ReleaseSemaphore(semaphores[77], 4, NULL);
SetEvent(events[664]);
ReleaseSemaphore(semaphores[290], 4, NULL);
ReleaseSemaphore(semaphores[252], 4, NULL);
}
}
void WINAPI Thread_270(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[147], INFINITE);
}
// good checks done
} else {
WaitForSingleObject(events[647], INFINITE);
// bad checks done
SetEvent(events[876]);
SetEvent(events[570]);
SetEvent(events[833]);
ReleaseSemaphore(semaphores[274], 3, NULL);
ReleaseSemaphore(semaphores[215], 2, NULL);
ReleaseSemaphore(semaphores[73], 1, NULL);
ReleaseSemaphore(semaphores[185], 3, NULL);
SetEvent(events[520]);
ReleaseSemaphore(semaphores[296], 3, NULL);
}
}
void WINAPI Thread_271(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[522], INFINITE);
WaitForSingleObject(events[167], INFINITE);
WaitForSingleObject(events[217], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[184], INFINITE);
}
// bad checks done
SetEvent(events[321]);
ReleaseSemaphore(semaphores[136], 3, NULL);
SetEvent(events[352]);
SetEvent(events[149]);
ReleaseSemaphore(semaphores[122], 1, NULL);
} else {
WaitForSingleObject(events[45], INFINITE);
WaitForSingleObject(events[930], INFINITE);
WaitForSingleObject(events[791], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[184], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[88], 3, NULL);
SetEvent(events[378]);
SetEvent(events[924]);
SetEvent(events[255]);
SetEvent(events[38]);
SetEvent(events[736]);
ReleaseSemaphore(semaphores[296], 3, NULL);
ReleaseSemaphore(semaphores[220], 4, NULL);
SetEvent(events[801]);
ReleaseSemaphore(semaphores[13], 1, NULL);
SetEvent(events[940]);
SetEvent(events[495]);
}
}
void WINAPI Thread_272(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1023], INFINITE);
WaitForSingleObject(events[297], INFINITE);
WaitForSingleObject(events[245], INFINITE);
WaitForSingleObject(events[424], INFINITE);
WaitForSingleObject(events[193], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[131], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[213], 1, NULL);
ReleaseSemaphore(semaphores[97], 3, NULL);
SetEvent(events[661]);
SetEvent(events[481]);
} else {
WaitForSingleObject(events[750], INFINITE);
WaitForSingleObject(events[868], INFINITE);
WaitForSingleObject(events[734], INFINITE);
WaitForSingleObject(events[14], INFINITE);
WaitForSingleObject(events[370], INFINITE);
WaitForSingleObject(events[229], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[131], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[110], 1, NULL);
ReleaseSemaphore(semaphores[283], 3, NULL);
SetEvent(events[136]);
ReleaseSemaphore(semaphores[21], 3, NULL);
ReleaseSemaphore(semaphores[151], 4, NULL);
}
}
void WINAPI Thread_273(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[133], INFINITE);
WaitForSingleObject(events[1022], INFINITE);
WaitForSingleObject(events[911], INFINITE);
WaitForSingleObject(events[744], INFINITE);
for (i = 0; i < 20; i++) {
    WaitForSingleObject(semaphores[93], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[44], 4, NULL);
ReleaseSemaphore(semaphores[36], 1, NULL);
SetEvent(events[801]);
SetEvent(events[236]);
ReleaseSemaphore(semaphores[258], 2, NULL);
SetEvent(events[381]);
} else {
WaitForSingleObject(events[71], INFINITE);
WaitForSingleObject(events[1003], INFINITE);
WaitForSingleObject(events[915], INFINITE);
WaitForSingleObject(events[438], INFINITE);
WaitForSingleObject(events[843], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[93], INFINITE);
}
// good checks done
SetEvent(events[637]);
ReleaseSemaphore(semaphores[213], 2, NULL);
SetEvent(events[649]);
SetEvent(events[368]);
ReleaseSemaphore(semaphores[86], 3, NULL);
ReleaseSemaphore(semaphores[8], 3, NULL);
SetEvent(events[817]);
}
}
void WINAPI Thread_274(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[75], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[57], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[289], 3, NULL);
ReleaseSemaphore(semaphores[115], 2, NULL);
ReleaseSemaphore(semaphores[231], 2, NULL);
ReleaseSemaphore(semaphores[206], 3, NULL);
ReleaseSemaphore(semaphores[159], 2, NULL);
SetEvent(events[420]);
ReleaseSemaphore(semaphores[141], 4, NULL);
ReleaseSemaphore(semaphores[167], 3, NULL);
SetEvent(events[400]);
} else {
WaitForSingleObject(events[806], INFINITE);
WaitForSingleObject(events[821], INFINITE);
WaitForSingleObject(events[56], INFINITE);
WaitForSingleObject(events[435], INFINITE);
WaitForSingleObject(events[468], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[57], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[227], 2, NULL);
ReleaseSemaphore(semaphores[189], 2, NULL);
ReleaseSemaphore(semaphores[116], 4, NULL);
SetEvent(events[552]);
}
}
void WINAPI Thread_275(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[389], INFINITE);
WaitForSingleObject(events[748], INFINITE);
WaitForSingleObject(events[814], INFINITE);
WaitForSingleObject(events[283], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[99], INFINITE);
}
// good checks done
SetEvent(events[667]);
ReleaseSemaphore(semaphores[226], 1, NULL);
SetEvent(events[842]);
} else {
WaitForSingleObject(events[1027], INFINITE);
WaitForSingleObject(events[5], INFINITE);
WaitForSingleObject(events[489], INFINITE);
WaitForSingleObject(events[415], INFINITE);
WaitForSingleObject(events[67], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[99], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[91], 1, NULL);
ReleaseSemaphore(semaphores[153], 3, NULL);
SetEvent(events[411]);
ReleaseSemaphore(semaphores[55], 3, NULL);
SetEvent(events[260]);
ReleaseSemaphore(semaphores[147], 3, NULL);
SetEvent(events[828]);
}
}
void WINAPI Thread_276(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[49], INFINITE);
WaitForSingleObject(events[690], INFINITE);
WaitForSingleObject(events[922], INFINITE);
WaitForSingleObject(events[284], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[262], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[189], 4, NULL);
ReleaseSemaphore(semaphores[148], 1, NULL);
} else {
WaitForSingleObject(events[197], INFINITE);
WaitForSingleObject(events[836], INFINITE);
WaitForSingleObject(events[592], INFINITE);
WaitForSingleObject(events[883], INFINITE);
WaitForSingleObject(events[348], INFINITE);
WaitForSingleObject(events[805], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[262], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[47], 3, NULL);
ReleaseSemaphore(semaphores[153], 3, NULL);
SetEvent(events[401]);
SetEvent(events[671]);
ReleaseSemaphore(semaphores[294], 3, NULL);
SetEvent(events[432]);
ReleaseSemaphore(semaphores[100], 1, NULL);
ReleaseSemaphore(semaphores[37], 2, NULL);
}
}
void WINAPI Thread_277(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[56], INFINITE);
WaitForSingleObject(events[460], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[264], INFINITE);
}
// good checks done
SetEvent(events[523]);
ReleaseSemaphore(semaphores[77], 3, NULL);
SetEvent(events[665]);
ReleaseSemaphore(semaphores[3], 4, NULL);
SetEvent(events[693]);
SetEvent(events[169]);
SetEvent(events[138]);
SetEvent(events[799]);
ReleaseSemaphore(semaphores[146], 3, NULL);
ReleaseSemaphore(semaphores[112], 3, NULL);
} else {
WaitForSingleObject(events[742], INFINITE);
WaitForSingleObject(events[420], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[264], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[89], 3, NULL);
ReleaseSemaphore(semaphores[206], 4, NULL);
ReleaseSemaphore(semaphores[223], 2, NULL);
SetEvent(events[606]);
ReleaseSemaphore(semaphores[96], 2, NULL);
SetEvent(events[356]);
}
}
void WINAPI Thread_278(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[941], INFINITE);
WaitForSingleObject(events[724], INFINITE);
WaitForSingleObject(events[738], INFINITE);
WaitForSingleObject(events[689], INFINITE);
WaitForSingleObject(events[15], INFINITE);
WaitForSingleObject(events[522], INFINITE);
WaitForSingleObject(events[475], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[153], INFINITE);
}
// good checks done
SetEvent(events[434]);
SetEvent(events[562]);
ReleaseSemaphore(semaphores[179], 1, NULL);
ReleaseSemaphore(semaphores[17], 3, NULL);
SetEvent(events[628]);
ReleaseSemaphore(semaphores[124], 1, NULL);
ReleaseSemaphore(semaphores[242], 1, NULL);
ReleaseSemaphore(semaphores[279], 4, NULL);
} else {
WaitForSingleObject(events[556], INFINITE);
WaitForSingleObject(events[817], INFINITE);
WaitForSingleObject(events[534], INFINITE);
WaitForSingleObject(events[31], INFINITE);
// bad checks done
SetEvent(events[442]);
ReleaseSemaphore(semaphores[256], 4, NULL);
ReleaseSemaphore(semaphores[144], 1, NULL);
SetEvent(events[768]);
ReleaseSemaphore(semaphores[152], 1, NULL);
}
}
void WINAPI Thread_279(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[330], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[35], INFINITE);
}
// bad checks done
SetEvent(events[728]);
SetEvent(events[170]);
ReleaseSemaphore(semaphores[87], 2, NULL);
SetEvent(events[280]);
SetEvent(events[769]);
ReleaseSemaphore(semaphores[228], 1, NULL);
ReleaseSemaphore(semaphores[7], 2, NULL);
} else {
WaitForSingleObject(events[180], INFINITE);
WaitForSingleObject(events[13], INFINITE);
WaitForSingleObject(events[210], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[35], INFINITE);
}
// good checks done
SetEvent(events[216]);
SetEvent(events[162]);
ReleaseSemaphore(semaphores[289], 1, NULL);
ReleaseSemaphore(semaphores[161], 1, NULL);
ReleaseSemaphore(semaphores[159], 3, NULL);
SetEvent(events[702]);
}
}
void WINAPI Thread_280(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[361], INFINITE);
WaitForSingleObject(events[619], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[204], INFINITE);
}
// good checks done
SetEvent(events[661]);
SetEvent(events[921]);
ReleaseSemaphore(semaphores[66], 4, NULL);
ReleaseSemaphore(semaphores[180], 2, NULL);
SetEvent(events[180]);
SetEvent(events[121]);
ReleaseSemaphore(semaphores[276], 4, NULL);
ReleaseSemaphore(semaphores[301], 2, NULL);
ReleaseSemaphore(semaphores[185], 4, NULL);
ReleaseSemaphore(semaphores[255], 3, NULL);
ReleaseSemaphore(semaphores[69], 4, NULL);
SetEvent(events[891]);
} else {
WaitForSingleObject(events[594], INFINITE);
WaitForSingleObject(events[642], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[204], INFINITE);
}
// bad checks done
SetEvent(events[879]);
ReleaseSemaphore(semaphores[156], 1, NULL);
SetEvent(events[645]);
SetEvent(events[702]);
ReleaseSemaphore(semaphores[20], 4, NULL);
ReleaseSemaphore(semaphores[169], 3, NULL);
ReleaseSemaphore(semaphores[263], 4, NULL);
ReleaseSemaphore(semaphores[108], 4, NULL);
}
}
void WINAPI Thread_281(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[59], INFINITE);
WaitForSingleObject(events[770], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[96], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[66], 2, NULL);
ReleaseSemaphore(semaphores[298], 1, NULL);
ReleaseSemaphore(semaphores[180], 4, NULL);
ReleaseSemaphore(semaphores[273], 1, NULL);
ReleaseSemaphore(semaphores[32], 4, NULL);
ReleaseSemaphore(semaphores[301], 1, NULL);
ReleaseSemaphore(semaphores[125], 3, NULL);
ReleaseSemaphore(semaphores[230], 2, NULL);
ReleaseSemaphore(semaphores[74], 1, NULL);
} else {
WaitForSingleObject(events[1005], INFINITE);
WaitForSingleObject(events[487], INFINITE);
WaitForSingleObject(events[665], INFINITE);
WaitForSingleObject(events[697], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[96], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[282], 4, NULL);
SetEvent(events[191]);
ReleaseSemaphore(semaphores[143], 3, NULL);
ReleaseSemaphore(semaphores[261], 1, NULL);
SetEvent(events[26]);
SetEvent(events[121]);
SetEvent(events[180]);
ReleaseSemaphore(semaphores[121], 3, NULL);
SetEvent(events[61]);
ReleaseSemaphore(semaphores[161], 1, NULL);
}
}
void WINAPI Thread_282(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[129], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[213], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[71], 3, NULL);
ReleaseSemaphore(semaphores[107], 3, NULL);
ReleaseSemaphore(semaphores[181], 4, NULL);
SetEvent(events[644]);
} else {
WaitForSingleObject(events[360], INFINITE);
WaitForSingleObject(events[829], INFINITE);
WaitForSingleObject(events[983], INFINITE);
WaitForSingleObject(events[449], INFINITE);
WaitForSingleObject(events[629], INFINITE);
for (i = 0; i < 21; i++) {
    WaitForSingleObject(semaphores[213], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[241], 3, NULL);
SetEvent(events[472]);
}
}
void WINAPI Thread_283(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[564], INFINITE);
WaitForSingleObject(events[515], INFINITE);
// bad checks done
SetEvent(events[81]);
ReleaseSemaphore(semaphores[16], 2, NULL);
ReleaseSemaphore(semaphores[208], 4, NULL);
} else {
WaitForSingleObject(events[126], INFINITE);
WaitForSingleObject(events[649], INFINITE);
WaitForSingleObject(events[326], INFINITE);
WaitForSingleObject(events[57], INFINITE);
WaitForSingleObject(events[605], INFINITE);
WaitForSingleObject(events[73], INFINITE);
WaitForSingleObject(events[277], INFINITE);
WaitForSingleObject(events[404], INFINITE);
for (i = 0; i < 11; i++) {
    WaitForSingleObject(semaphores[281], INFINITE);
}
// good checks done
SetEvent(events[142]);
ReleaseSemaphore(semaphores[241], 3, NULL);
SetEvent(events[755]);
SetEvent(events[560]);
SetEvent(events[406]);
}
}
void WINAPI Thread_284(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[831], INFINITE);
WaitForSingleObject(events[862], INFINITE);
WaitForSingleObject(events[866], INFINITE);
WaitForSingleObject(events[147], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[279], INFINITE);
}
// good checks done
SetEvent(events[486]);
ReleaseSemaphore(semaphores[213], 1, NULL);
ReleaseSemaphore(semaphores[209], 3, NULL);
SetEvent(events[359]);
} else {
WaitForSingleObject(events[239], INFINITE);
WaitForSingleObject(events[863], INFINITE);
WaitForSingleObject(events[899], INFINITE);
// bad checks done
SetEvent(events[689]);
SetEvent(events[913]);
ReleaseSemaphore(semaphores[25], 4, NULL);
ReleaseSemaphore(semaphores[240], 1, NULL);
}
}
void WINAPI Thread_285(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[976], INFINITE);
WaitForSingleObject(events[939], INFINITE);
WaitForSingleObject(events[703], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[138], INFINITE);
}
// good checks done
SetEvent(events[539]);
SetEvent(events[839]);
ReleaseSemaphore(semaphores[271], 2, NULL);
SetEvent(events[902]);
ReleaseSemaphore(semaphores[13], 3, NULL);
ReleaseSemaphore(semaphores[54], 4, NULL);
} else {
WaitForSingleObject(events[267], INFINITE);
WaitForSingleObject(events[377], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[138], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[17], 2, NULL);
ReleaseSemaphore(semaphores[118], 2, NULL);
SetEvent(events[917]);
SetEvent(events[1009]);
ReleaseSemaphore(semaphores[1], 3, NULL);
ReleaseSemaphore(semaphores[144], 4, NULL);
}
}
void WINAPI Thread_286(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[50], INFINITE);
WaitForSingleObject(events[247], INFINITE);
WaitForSingleObject(events[813], INFINITE);
WaitForSingleObject(events[82], INFINITE);
// bad checks done
SetEvent(events[142]);
ReleaseSemaphore(semaphores[150], 4, NULL);
} else {
WaitForSingleObject(events[292], INFINITE);
WaitForSingleObject(events[945], INFINITE);
WaitForSingleObject(events[364], INFINITE);
WaitForSingleObject(events[239], INFINITE);
WaitForSingleObject(events[644], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[31], INFINITE);
}
// good checks done
SetEvent(events[810]);
SetEvent(events[286]);
SetEvent(events[77]);
ReleaseSemaphore(semaphores[218], 1, NULL);
SetEvent(events[1008]);
ReleaseSemaphore(semaphores[20], 4, NULL);
ReleaseSemaphore(semaphores[201], 4, NULL);
ReleaseSemaphore(semaphores[193], 1, NULL);
SetEvent(events[584]);
ReleaseSemaphore(semaphores[16], 1, NULL);
ReleaseSemaphore(semaphores[262], 3, NULL);
SetEvent(events[388]);
SetEvent(events[43]);
ReleaseSemaphore(semaphores[119], 4, NULL);
}
}
void WINAPI Thread_287(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[463], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[261], INFINITE);
}
// bad checks done
SetEvent(events[1020]);
ReleaseSemaphore(semaphores[187], 3, NULL);
SetEvent(events[786]);
ReleaseSemaphore(semaphores[4], 3, NULL);
SetEvent(events[634]);
ReleaseSemaphore(semaphores[244], 1, NULL);
SetEvent(events[218]);
ReleaseSemaphore(semaphores[292], 4, NULL);
ReleaseSemaphore(semaphores[26], 3, NULL);
} else {
WaitForSingleObject(events[593], INFINITE);
WaitForSingleObject(events[157], INFINITE);
WaitForSingleObject(events[991], INFINITE);
WaitForSingleObject(events[402], INFINITE);
WaitForSingleObject(events[512], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[261], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[105], 2, NULL);
}
}
void WINAPI Thread_288(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[795], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[101], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[72], 3, NULL);
SetEvent(events[243]);
ReleaseSemaphore(semaphores[273], 4, NULL);
ReleaseSemaphore(semaphores[237], 3, NULL);
SetEvent(events[942]);
SetEvent(events[679]);
ReleaseSemaphore(semaphores[168], 1, NULL);
ReleaseSemaphore(semaphores[196], 1, NULL);
ReleaseSemaphore(semaphores[230], 4, NULL);
SetEvent(events[683]);
} else {
WaitForSingleObject(events[955], INFINITE);
WaitForSingleObject(events[472], INFINITE);
WaitForSingleObject(events[319], INFINITE);
WaitForSingleObject(events[315], INFINITE);
WaitForSingleObject(events[959], INFINITE);
// bad checks done
SetEvent(events[549]);
SetEvent(events[958]);
SetEvent(events[656]);
SetEvent(events[623]);
}
}
void WINAPI Thread_289(int bit) {
int i = 0;
if (bit) {
// bad checks done
ReleaseSemaphore(semaphores[137], 2, NULL);
SetEvent(events[1009]);
ReleaseSemaphore(semaphores[51], 3, NULL);
ReleaseSemaphore(semaphores[265], 2, NULL);
ReleaseSemaphore(semaphores[234], 4, NULL);
SetEvent(events[359]);
ReleaseSemaphore(semaphores[296], 4, NULL);
} else {
// good checks done
ReleaseSemaphore(semaphores[63], 4, NULL);
ReleaseSemaphore(semaphores[288], 4, NULL);
}
}
void WINAPI Thread_290(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[92], INFINITE);
}
// bad checks done
SetEvent(events[742]);
SetEvent(events[693]);
SetEvent(events[702]);
ReleaseSemaphore(semaphores[139], 3, NULL);
} else {
WaitForSingleObject(events[867], INFINITE);
WaitForSingleObject(events[953], INFINITE);
WaitForSingleObject(events[726], INFINITE);
WaitForSingleObject(events[493], INFINITE);
WaitForSingleObject(events[100], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[92], INFINITE);
}
// good checks done
SetEvent(events[85]);
}
}
void WINAPI Thread_291(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[949], INFINITE);
WaitForSingleObject(events[158], INFINITE);
WaitForSingleObject(events[18], INFINITE);
WaitForSingleObject(events[187], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[217], INFINITE);
}
// bad checks done
SetEvent(events[269]);
SetEvent(events[336]);
ReleaseSemaphore(semaphores[190], 1, NULL);
ReleaseSemaphore(semaphores[68], 2, NULL);
ReleaseSemaphore(semaphores[186], 4, NULL);
SetEvent(events[743]);
SetEvent(events[844]);
SetEvent(events[100]);
} else {
WaitForSingleObject(events[385], INFINITE);
WaitForSingleObject(events[298], INFINITE);
WaitForSingleObject(events[422], INFINITE);
WaitForSingleObject(events[58], INFINITE);
WaitForSingleObject(events[463], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[217], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[275], 3, NULL);
ReleaseSemaphore(semaphores[20], 2, NULL);
ReleaseSemaphore(semaphores[29], 2, NULL);
ReleaseSemaphore(semaphores[219], 2, NULL);
SetEvent(events[314]);
}
}
void WINAPI Thread_292(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[924], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[83], 3, NULL);
ReleaseSemaphore(semaphores[145], 3, NULL);
ReleaseSemaphore(semaphores[19], 4, NULL);
} else {
WaitForSingleObject(events[461], INFINITE);
WaitForSingleObject(events[202], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[39], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[292], 1, NULL);
ReleaseSemaphore(semaphores[126], 4, NULL);
ReleaseSemaphore(semaphores[155], 2, NULL);
SetEvent(events[762]);
}
}
void WINAPI Thread_293(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[107], INFINITE);
WaitForSingleObject(events[823], INFINITE);
WaitForSingleObject(events[793], INFINITE);
WaitForSingleObject(events[111], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[134], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[88], 4, NULL);
SetEvent(events[529]);
SetEvent(events[422]);
SetEvent(events[837]);
SetEvent(events[515]);
ReleaseSemaphore(semaphores[43], 1, NULL);
ReleaseSemaphore(semaphores[0], 1, NULL);
ReleaseSemaphore(semaphores[54], 4, NULL);
SetEvent(events[711]);
} else {
WaitForSingleObject(events[164], INFINITE);
WaitForSingleObject(events[195], INFINITE);
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[134], INFINITE);
}
// bad checks done
}
}
void WINAPI Thread_294(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1001], INFINITE);
WaitForSingleObject(events[331], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[65], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[108], 4, NULL);
SetEvent(events[543]);
SetEvent(events[854]);
SetEvent(events[821]);
ReleaseSemaphore(semaphores[15], 1, NULL);
SetEvent(events[10]);
} else {
WaitForSingleObject(events[743], INFINITE);
WaitForSingleObject(events[827], INFINITE);
WaitForSingleObject(events[644], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[212], 3, NULL);
ReleaseSemaphore(semaphores[117], 1, NULL);
ReleaseSemaphore(semaphores[168], 3, NULL);
SetEvent(events[479]);
ReleaseSemaphore(semaphores[259], 1, NULL);
}
}
void WINAPI Thread_295(int bit) {
int i = 0;
if (bit) {
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[102], INFINITE);
}
// bad checks done
SetEvent(events[536]);
SetEvent(events[661]);
} else {
WaitForSingleObject(events[416], INFINITE);
WaitForSingleObject(events[61], INFINITE);
WaitForSingleObject(events[1027], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[102], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[39], 3, NULL);
ReleaseSemaphore(semaphores[163], 4, NULL);
SetEvent(events[403]);
SetEvent(events[1030]);
SetEvent(events[524]);
ReleaseSemaphore(semaphores[200], 4, NULL);
ReleaseSemaphore(semaphores[15], 4, NULL);
}
}
void WINAPI Thread_296(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[912], INFINITE);
WaitForSingleObject(events[718], INFINITE);
WaitForSingleObject(events[833], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[187], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[233], 3, NULL);
ReleaseSemaphore(semaphores[9], 4, NULL);
SetEvent(events[901]);
ReleaseSemaphore(semaphores[126], 4, NULL);
ReleaseSemaphore(semaphores[51], 3, NULL);
SetEvent(events[358]);
ReleaseSemaphore(semaphores[223], 3, NULL);
ReleaseSemaphore(semaphores[27], 2, NULL);
SetEvent(events[930]);
} else {
WaitForSingleObject(events[812], INFINITE);
// bad checks done
ReleaseSemaphore(semaphores[66], 3, NULL);
SetEvent(events[1018]);
SetEvent(events[730]);
SetEvent(events[144]);
SetEvent(events[1016]);
}
}
void WINAPI Thread_297(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[190], INFINITE);
WaitForSingleObject(events[479], INFINITE);
WaitForSingleObject(events[604], INFINITE);
WaitForSingleObject(events[616], INFINITE);
WaitForSingleObject(events[710], INFINITE);
WaitForSingleObject(events[667], INFINITE);
for (i = 0; i < 4; i++) {
    WaitForSingleObject(semaphores[154], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[14], 3, NULL);
ReleaseSemaphore(semaphores[286], 3, NULL);
ReleaseSemaphore(semaphores[30], 1, NULL);
} else {
WaitForSingleObject(events[387], INFINITE);
WaitForSingleObject(events[815], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[154], INFINITE);
}
// bad checks done
SetEvent(events[790]);
ReleaseSemaphore(semaphores[194], 4, NULL);
SetEvent(events[276]);
ReleaseSemaphore(semaphores[278], 2, NULL);
}
}
void WINAPI Thread_298(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[257], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[16], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[183], 4, NULL);
ReleaseSemaphore(semaphores[271], 2, NULL);
ReleaseSemaphore(semaphores[87], 2, NULL);
} else {
WaitForSingleObject(events[964], INFINITE);
WaitForSingleObject(events[659], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[16], INFINITE);
}
// good checks done
SetEvent(events[788]);
ReleaseSemaphore(semaphores[270], 3, NULL);
SetEvent(events[689]);
ReleaseSemaphore(semaphores[117], 4, NULL);
}
}
void WINAPI Thread_299(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[1018], INFINITE);
WaitForSingleObject(events[446], INFINITE);
WaitForSingleObject(events[756], INFINITE);
WaitForSingleObject(events[162], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[56], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[300], 3, NULL);
ReleaseSemaphore(semaphores[168], 2, NULL);
ReleaseSemaphore(semaphores[29], 2, NULL);
ReleaseSemaphore(semaphores[108], 2, NULL);
ReleaseSemaphore(semaphores[27], 1, NULL);
} else {
WaitForSingleObject(events[9], INFINITE);
WaitForSingleObject(events[115], INFINITE);
WaitForSingleObject(events[203], INFINITE);
WaitForSingleObject(events[768], INFINITE);
WaitForSingleObject(events[184], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[56], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[10], 3, NULL);
ReleaseSemaphore(semaphores[121], 4, NULL);
SetEvent(events[1011]);
SetEvent(events[482]);
ReleaseSemaphore(semaphores[300], 1, NULL);
SetEvent(events[645]);
ReleaseSemaphore(semaphores[212], 1, NULL);
SetEvent(events[514]);
}
}
void WINAPI Thread_300(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[650], INFINITE);
WaitForSingleObject(events[368], INFINITE);
WaitForSingleObject(events[712], INFINITE);
for (i = 0; i < 17; i++) {
    WaitForSingleObject(semaphores[94], INFINITE);
}
// good checks done
SetEvent(events[65]);
ReleaseSemaphore(semaphores[53], 3, NULL);
SetEvent(events[8]);
ReleaseSemaphore(semaphores[136], 1, NULL);
SetEvent(events[568]);
ReleaseSemaphore(semaphores[257], 3, NULL);
} else {
WaitForSingleObject(events[410], INFINITE);
WaitForSingleObject(events[596], INFINITE);
WaitForSingleObject(events[251], INFINITE);
WaitForSingleObject(events[47], INFINITE);
WaitForSingleObject(events[104], INFINITE);
// bad checks done
SetEvent(events[380]);
ReleaseSemaphore(semaphores[127], 2, NULL);
ReleaseSemaphore(semaphores[91], 2, NULL);
SetEvent(events[555]);
ReleaseSemaphore(semaphores[260], 2, NULL);
SetEvent(events[499]);
}
}
void WINAPI Thread_301(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[794], INFINITE);
WaitForSingleObject(events[410], INFINITE);
WaitForSingleObject(events[278], INFINITE);
WaitForSingleObject(events[295], INFINITE);
WaitForSingleObject(events[594], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[257], INFINITE);
}
// good checks done
SetEvent(events[696]);
ReleaseSemaphore(semaphores[5], 4, NULL);
SetEvent(events[800]);
SetEvent(events[425]);
ReleaseSemaphore(semaphores[255], 2, NULL);
ReleaseSemaphore(semaphores[74], 1, NULL);
} else {
WaitForSingleObject(events[403], INFINITE);
WaitForSingleObject(events[743], INFINITE);
WaitForSingleObject(events[184], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[257], INFINITE);
}
// bad checks done
SetEvent(events[354]);
ReleaseSemaphore(semaphores[231], 4, NULL);
SetEvent(events[795]);
}
}
void WINAPI Thread_302(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[773], INFINITE);
WaitForSingleObject(events[891], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[205], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 4, NULL);
SetEvent(events[790]);
ReleaseSemaphore(semaphores[104], 3, NULL);
ReleaseSemaphore(semaphores[206], 2, NULL);
SetEvent(events[367]);
SetEvent(events[872]);
} else {
// bad checks done
SetEvent(events[812]);
ReleaseSemaphore(semaphores[197], 1, NULL);
SetEvent(events[966]);
ReleaseSemaphore(semaphores[167], 1, NULL);
ReleaseSemaphore(semaphores[100], 2, NULL);
SetEvent(events[838]);
SetEvent(events[223]);
ReleaseSemaphore(semaphores[130], 4, NULL);
SetEvent(events[62]);
}
}
void WINAPI Thread_303(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[486], INFINITE);
WaitForSingleObject(events[779], INFINITE);
WaitForSingleObject(events[825], INFINITE);
WaitForSingleObject(events[1031], INFINITE);
// bad checks done
SetEvent(events[98]);
SetEvent(events[206]);
SetEvent(events[577]);
SetEvent(events[399]);
SetEvent(events[637]);
} else {
WaitForSingleObject(events[717], INFINITE);
WaitForSingleObject(events[49], INFINITE);
for (i = 0; i < 2; i++) {
    WaitForSingleObject(semaphores[52], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[114], 1, NULL);
SetEvent(events[772]);
ReleaseSemaphore(semaphores[289], 4, NULL);
ReleaseSemaphore(semaphores[104], 4, NULL);
SetEvent(events[566]);
ReleaseSemaphore(semaphores[231], 3, NULL);
SetEvent(events[363]);
SetEvent(events[158]);
ReleaseSemaphore(semaphores[240], 1, NULL);
ReleaseSemaphore(semaphores[254], 3, NULL);
}
}
void WINAPI Thread_304(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[468], INFINITE);
WaitForSingleObject(events[735], INFINITE);
WaitForSingleObject(events[391], INFINITE);
WaitForSingleObject(events[714], INFINITE);
WaitForSingleObject(events[645], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[36], INFINITE);
}
// good checks done
SetEvent(events[776]);
ReleaseSemaphore(semaphores[270], 4, NULL);
SetEvent(events[522]);
ReleaseSemaphore(semaphores[235], 1, NULL);
ReleaseSemaphore(semaphores[285], 3, NULL);
SetEvent(events[327]);
ReleaseSemaphore(semaphores[68], 1, NULL);
SetEvent(events[250]);
ReleaseSemaphore(semaphores[75], 2, NULL);
ReleaseSemaphore(semaphores[151], 2, NULL);
} else {
WaitForSingleObject(events[38], INFINITE);
WaitForSingleObject(events[121], INFINITE);
WaitForSingleObject(events[947], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[36], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[237], 1, NULL);
SetEvent(events[609]);
SetEvent(events[620]);
}
}
void WINAPI Thread_305(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[103], INFINITE);
WaitForSingleObject(events[268], INFINITE);
WaitForSingleObject(events[530], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[175], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[227], 1, NULL);
ReleaseSemaphore(semaphores[211], 1, NULL);
SetEvent(events[889]);
ReleaseSemaphore(semaphores[79], 3, NULL);
ReleaseSemaphore(semaphores[23], 3, NULL);
SetEvent(events[874]);
ReleaseSemaphore(semaphores[296], 3, NULL);
ReleaseSemaphore(semaphores[40], 3, NULL);
} else {
WaitForSingleObject(events[44], INFINITE);
WaitForSingleObject(events[688], INFINITE);
WaitForSingleObject(events[400], INFINITE);
WaitForSingleObject(events[696], INFINITE);
WaitForSingleObject(events[21], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[175], INFINITE);
}
// bad checks done
SetEvent(events[684]);
ReleaseSemaphore(semaphores[210], 2, NULL);
SetEvent(events[958]);
SetEvent(events[416]);
ReleaseSemaphore(semaphores[216], 1, NULL);
ReleaseSemaphore(semaphores[120], 3, NULL);
SetEvent(events[113]);
}
}
void WINAPI Thread_306(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[155], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[287], INFINITE);
}
// bad checks done
SetEvent(events[464]);
ReleaseSemaphore(semaphores[51], 2, NULL);
SetEvent(events[867]);
ReleaseSemaphore(semaphores[46], 3, NULL);
ReleaseSemaphore(semaphores[198], 4, NULL);
SetEvent(events[15]);
} else {
WaitForSingleObject(events[122], INFINITE);
WaitForSingleObject(events[253], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[287], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[213], 1, NULL);
ReleaseSemaphore(semaphores[2], 4, NULL);
SetEvent(events[212]);
}
}
void WINAPI Thread_307(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[351], INFINITE);
WaitForSingleObject(events[521], INFINITE);
WaitForSingleObject(events[905], INFINITE);
WaitForSingleObject(events[683], INFINITE);
WaitForSingleObject(events[659], INFINITE);
for (i = 0; i < 8; i++) {
    WaitForSingleObject(semaphores[117], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[222], 1, NULL);
ReleaseSemaphore(semaphores[85], 1, NULL);
ReleaseSemaphore(semaphores[249], 2, NULL);
ReleaseSemaphore(semaphores[182], 1, NULL);
SetEvent(events[69]);
} else {
WaitForSingleObject(events[7], INFINITE);
WaitForSingleObject(events[220], INFINITE);
WaitForSingleObject(events[265], INFINITE);
for (i = 0; i < 9; i++) {
    WaitForSingleObject(semaphores[117], INFINITE);
}
// good checks done
SetEvent(events[341]);
ReleaseSemaphore(semaphores[256], 2, NULL);
ReleaseSemaphore(semaphores[38], 2, NULL);
SetEvent(events[600]);
ReleaseSemaphore(semaphores[109], 3, NULL);
SetEvent(events[428]);
SetEvent(events[213]);
SetEvent(events[700]);
ReleaseSemaphore(semaphores[245], 2, NULL);
ReleaseSemaphore(semaphores[44], 2, NULL);
SetEvent(events[195]);
}
}
void WINAPI Thread_308(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[483], INFINITE);
WaitForSingleObject(events[208], INFINITE);
WaitForSingleObject(events[398], INFINITE);
WaitForSingleObject(events[482], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[299], INFINITE);
}
// good checks done
SetEvent(events[961]);
SetEvent(events[311]);
ReleaseSemaphore(semaphores[110], 2, NULL);
SetEvent(events[329]);
ReleaseSemaphore(semaphores[274], 4, NULL);
ReleaseSemaphore(semaphores[132], 1, NULL);
ReleaseSemaphore(semaphores[100], 3, NULL);
} else {
WaitForSingleObject(events[511], INFINITE);
WaitForSingleObject(events[793], INFINITE);
WaitForSingleObject(events[743], INFINITE);
WaitForSingleObject(events[938], INFINITE);
// bad checks done
SetEvent(events[771]);
ReleaseSemaphore(semaphores[9], 2, NULL);
SetEvent(events[478]);
ReleaseSemaphore(semaphores[100], 2, NULL);
ReleaseSemaphore(semaphores[121], 1, NULL);
SetEvent(events[652]);
ReleaseSemaphore(semaphores[226], 3, NULL);
SetEvent(events[763]);
ReleaseSemaphore(semaphores[26], 1, NULL);
SetEvent(events[897]);
}
}
void WINAPI Thread_309(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[86], INFINITE);
WaitForSingleObject(events[713], INFINITE);
WaitForSingleObject(events[195], INFINITE);
WaitForSingleObject(events[747], INFINITE);
WaitForSingleObject(events[440], INFINITE);
for (i = 0; i < 14; i++) {
    WaitForSingleObject(semaphores[135], INFINITE);
}
// good checks done
SetEvent(events[92]);
SetEvent(events[449]);
ReleaseSemaphore(semaphores[281], 4, NULL);
ReleaseSemaphore(semaphores[174], 4, NULL);
ReleaseSemaphore(semaphores[84], 2, NULL);
ReleaseSemaphore(semaphores[149], 2, NULL);
} else {
// bad checks done
ReleaseSemaphore(semaphores[270], 2, NULL);
ReleaseSemaphore(semaphores[100], 3, NULL);
SetEvent(events[149]);
}
}
void WINAPI Thread_310(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[48], INFINITE);
WaitForSingleObject(events[509], INFINITE);
WaitForSingleObject(events[770], INFINITE);
WaitForSingleObject(events[829], INFINITE);
WaitForSingleObject(events[680], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[179], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[104], 3, NULL);
ReleaseSemaphore(semaphores[69], 4, NULL);
SetEvent(events[7]);
ReleaseSemaphore(semaphores[127], 4, NULL);
} else {
WaitForSingleObject(events[865], INFINITE);
WaitForSingleObject(events[852], INFINITE);
WaitForSingleObject(events[652], INFINITE);
WaitForSingleObject(events[948], INFINITE);
WaitForSingleObject(events[777], INFINITE);
for (i = 0; i < 12; i++) {
    WaitForSingleObject(semaphores[179], INFINITE);
}
// good checks done
SetEvent(events[277]);
ReleaseSemaphore(semaphores[209], 3, NULL);
ReleaseSemaphore(semaphores[2], 1, NULL);
ReleaseSemaphore(semaphores[268], 4, NULL);
ReleaseSemaphore(semaphores[225], 4, NULL);
SetEvent(events[419]);
}
}
void WINAPI Thread_311(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[910], INFINITE);
WaitForSingleObject(events[484], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[90], INFINITE);
}
// bad checks done
SetEvent(events[354]);
ReleaseSemaphore(semaphores[238], 3, NULL);
SetEvent(events[212]);
ReleaseSemaphore(semaphores[122], 4, NULL);
SetEvent(events[660]);
SetEvent(events[774]);
ReleaseSemaphore(semaphores[66], 4, NULL);
} else {
WaitForSingleObject(events[874], INFINITE);
WaitForSingleObject(events[591], INFINITE);
WaitForSingleObject(events[902], INFINITE);
WaitForSingleObject(events[146], INFINITE);
WaitForSingleObject(events[885], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[90], INFINITE);
}
// good checks done
SetEvent(events[370]);
ReleaseSemaphore(semaphores[169], 2, NULL);
SetEvent(events[156]);
SetEvent(events[62]);
SetEvent(events[767]);
ReleaseSemaphore(semaphores[16], 3, NULL);
ReleaseSemaphore(semaphores[183], 4, NULL);
ReleaseSemaphore(semaphores[219], 1, NULL);
SetEvent(events[782]);
}
}
void WINAPI Thread_312(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[731], INFINITE);
WaitForSingleObject(events[382], INFINITE);
WaitForSingleObject(events[1007], INFINITE);
for (i = 0; i < 18; i++) {
    WaitForSingleObject(semaphores[27], INFINITE);
}
// good checks done
SetEvent(events[247]);
ReleaseSemaphore(semaphores[103], 4, NULL);
ReleaseSemaphore(semaphores[88], 2, NULL);
SetEvent(events[884]);
SetEvent(events[480]);
ReleaseSemaphore(semaphores[79], 1, NULL);
SetEvent(events[583]);
ReleaseSemaphore(semaphores[220], 2, NULL);
SetEvent(events[968]);
ReleaseSemaphore(semaphores[71], 1, NULL);
} else {
WaitForSingleObject(events[636], INFINITE);
WaitForSingleObject(events[250], INFINITE);
for (i = 0; i < 1; i++) {
    WaitForSingleObject(semaphores[27], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[194], 3, NULL);
}
}
void WINAPI Thread_313(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[608], INFINITE);
WaitForSingleObject(events[649], INFINITE);
WaitForSingleObject(events[954], INFINITE);
// bad checks done
SetEvent(events[165]);
ReleaseSemaphore(semaphores[287], 3, NULL);
ReleaseSemaphore(semaphores[130], 3, NULL);
ReleaseSemaphore(semaphores[11], 4, NULL);
ReleaseSemaphore(semaphores[208], 3, NULL);
ReleaseSemaphore(semaphores[168], 2, NULL);
} else {
// good checks done
ReleaseSemaphore(semaphores[120], 4, NULL);
}
}
void WINAPI Thread_314(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[130], INFINITE);
WaitForSingleObject(events[960], INFINITE);
WaitForSingleObject(events[234], INFINITE);
WaitForSingleObject(events[418], INFINITE);
WaitForSingleObject(events[132], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[146], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[103], 1, NULL);
ReleaseSemaphore(semaphores[79], 4, NULL);
ReleaseSemaphore(semaphores[186], 4, NULL);
SetEvent(events[298]);
ReleaseSemaphore(semaphores[171], 4, NULL);
ReleaseSemaphore(semaphores[54], 1, NULL);
SetEvent(events[151]);
ReleaseSemaphore(semaphores[25], 2, NULL);
SetEvent(events[640]);
ReleaseSemaphore(semaphores[71], 2, NULL);
} else {
WaitForSingleObject(events[587], INFINITE);
WaitForSingleObject(events[548], INFINITE);
WaitForSingleObject(events[480], INFINITE);
for (i = 0; i < 7; i++) {
    WaitForSingleObject(semaphores[146], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[104], 1, NULL);
}
}
void WINAPI Thread_315(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[436], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[78], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[156], 3, NULL);
SetEvent(events[925]);
SetEvent(events[708]);
SetEvent(events[377]);
ReleaseSemaphore(semaphores[282], 3, NULL);
SetEvent(events[187]);
ReleaseSemaphore(semaphores[185], 3, NULL);
SetEvent(events[944]);
} else {
for (i = 0; i < 16; i++) {
    WaitForSingleObject(semaphores[78], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[126], 4, NULL);
ReleaseSemaphore(semaphores[288], 4, NULL);
SetEvent(events[837]);
ReleaseSemaphore(semaphores[235], 3, NULL);
}
}
void WINAPI Thread_316(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[973], INFINITE);
WaitForSingleObject(events[584], INFINITE);
WaitForSingleObject(events[870], INFINITE);
for (i = 0; i < 6; i++) {
    WaitForSingleObject(semaphores[67], INFINITE);
}
// good checks done
SetEvent(events[260]);
ReleaseSemaphore(semaphores[137], 2, NULL);
ReleaseSemaphore(semaphores[270], 2, NULL);
SetEvent(events[150]);
SetEvent(events[577]);
ReleaseSemaphore(semaphores[285], 2, NULL);
ReleaseSemaphore(semaphores[68], 3, NULL);
SetEvent(events[1025]);
SetEvent(events[982]);
} else {
WaitForSingleObject(events[727], INFINITE);
WaitForSingleObject(events[974], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[67], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[209], 2, NULL);
ReleaseSemaphore(semaphores[153], 4, NULL);
ReleaseSemaphore(semaphores[91], 1, NULL);
SetEvent(events[142]);
ReleaseSemaphore(semaphores[114], 4, NULL);
SetEvent(events[859]);
ReleaseSemaphore(semaphores[120], 2, NULL);
SetEvent(events[214]);
SetEvent(events[989]);
SetEvent(events[261]);
}
}
void WINAPI Thread_317(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[851], INFINITE);
WaitForSingleObject(events[897], INFINITE);
WaitForSingleObject(events[1022], INFINITE);
WaitForSingleObject(events[163], INFINITE);
for (i = 0; i < 19; i++) {
    WaitForSingleObject(semaphores[289], INFINITE);
}
// good checks done
SetEvent(events[479]);
SetEvent(events[792]);
SetEvent(events[167]);
ReleaseSemaphore(semaphores[118], 4, NULL);
} else {
WaitForSingleObject(events[527], INFINITE);
WaitForSingleObject(events[609], INFINITE);
WaitForSingleObject(events[185], INFINITE);
WaitForSingleObject(events[519], INFINITE);
for (i = 0; i < 13; i++) {
    WaitForSingleObject(semaphores[289], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[162], 3, NULL);
ReleaseSemaphore(semaphores[192], 3, NULL);
}
}
void WINAPI Thread_318(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[226], INFINITE);
WaitForSingleObject(events[693], INFINITE);
for (i = 0; i < 15; i++) {
    WaitForSingleObject(semaphores[51], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[211], 4, NULL);
ReleaseSemaphore(semaphores[56], 1, NULL);
SetEvent(events[590]);
SetEvent(events[36]);
ReleaseSemaphore(semaphores[186], 3, NULL);
SetEvent(events[239]);
SetEvent(events[673]);
SetEvent(events[613]);
ReleaseSemaphore(semaphores[54], 2, NULL);
SetEvent(events[39]);
} else {
WaitForSingleObject(events[564], INFINITE);
for (i = 0; i < 5; i++) {
    WaitForSingleObject(semaphores[51], INFINITE);
}
// bad checks done
SetEvent(events[792]);
SetEvent(events[243]);
ReleaseSemaphore(semaphores[142], 2, NULL);
ReleaseSemaphore(semaphores[36], 2, NULL);
ReleaseSemaphore(semaphores[157], 3, NULL);
ReleaseSemaphore(semaphores[176], 4, NULL);
}
}
void WINAPI Thread_319(int bit) {
int i = 0;
if (bit) {
WaitForSingleObject(events[122], INFINITE);
WaitForSingleObject(events[179], INFINITE);
WaitForSingleObject(events[568], INFINITE);
for (i = 0; i < 3; i++) {
    WaitForSingleObject(semaphores[256], INFINITE);
}
// bad checks done
ReleaseSemaphore(semaphores[175], 4, NULL);
ReleaseSemaphore(semaphores[198], 4, NULL);
ReleaseSemaphore(semaphores[90], 4, NULL);
ReleaseSemaphore(semaphores[171], 1, NULL);
ReleaseSemaphore(semaphores[301], 4, NULL);
} else {
WaitForSingleObject(events[497], INFINITE);
WaitForSingleObject(events[351], INFINITE);
WaitForSingleObject(events[209], INFINITE);
WaitForSingleObject(events[937], INFINITE);
WaitForSingleObject(events[249], INFINITE);
WaitForSingleObject(events[117], INFINITE);
for (i = 0; i < 10; i++) {
    WaitForSingleObject(semaphores[256], INFINITE);
}
// good checks done
ReleaseSemaphore(semaphores[94], 2, NULL);
ReleaseSemaphore(semaphores[174], 1, NULL);
SetEvent(events[761]);
SetEvent(events[390]);
}
}
HANDLE threads[] = {
Thread_0, Thread_1, Thread_2, Thread_3, Thread_4, Thread_5, Thread_6, Thread_7, Thread_8, Thread_9, Thread_10, Thread_11, Thread_12, Thread_13, Thread_14, Thread_15, Thread_16, Thread_17, Thread_18, Thread_19, Thread_20, Thread_21, Thread_22, Thread_23, Thread_24, Thread_25, Thread_26, Thread_27, Thread_28, Thread_29, Thread_30, Thread_31, Thread_32, Thread_33, Thread_34, Thread_35, Thread_36, Thread_37, Thread_38, Thread_39, Thread_40, Thread_41, Thread_42, Thread_43, Thread_44, Thread_45, Thread_46, Thread_47, Thread_48, Thread_49, Thread_50, Thread_51, Thread_52, Thread_53, Thread_54, Thread_55, Thread_56, Thread_57, Thread_58, Thread_59, Thread_60, Thread_61, Thread_62, Thread_63, Thread_64, Thread_65, Thread_66, Thread_67, Thread_68, Thread_69, Thread_70, Thread_71, Thread_72, Thread_73, Thread_74, Thread_75, Thread_76, Thread_77, Thread_78, Thread_79, Thread_80, Thread_81, Thread_82, Thread_83, Thread_84, Thread_85, Thread_86, Thread_87, Thread_88, Thread_89, Thread_90, Thread_91, Thread_92, Thread_93, Thread_94, Thread_95, Thread_96, Thread_97, Thread_98, Thread_99, Thread_100, Thread_101, Thread_102, Thread_103, Thread_104, Thread_105, Thread_106, Thread_107, Thread_108, Thread_109, Thread_110, Thread_111, Thread_112, Thread_113, Thread_114, Thread_115, Thread_116, Thread_117, Thread_118, Thread_119, Thread_120, Thread_121, Thread_122, Thread_123, Thread_124, Thread_125, Thread_126, Thread_127, Thread_128, Thread_129, Thread_130, Thread_131, Thread_132, Thread_133, Thread_134, Thread_135, Thread_136, Thread_137, Thread_138, Thread_139, Thread_140, Thread_141, Thread_142, Thread_143, Thread_144, Thread_145, Thread_146, Thread_147, Thread_148, Thread_149, Thread_150, Thread_151, Thread_152, Thread_153, Thread_154, Thread_155, Thread_156, Thread_157, Thread_158, Thread_159, Thread_160, Thread_161, Thread_162, Thread_163, Thread_164, Thread_165, Thread_166, Thread_167, Thread_168, Thread_169, Thread_170, Thread_171, Thread_172, Thread_173, Thread_174, Thread_175, Thread_176, Thread_177, Thread_178, Thread_179, Thread_180, Thread_181, Thread_182, Thread_183, Thread_184, Thread_185, Thread_186, Thread_187, Thread_188, Thread_189, Thread_190, Thread_191, Thread_192, Thread_193, Thread_194, Thread_195, Thread_196, Thread_197, Thread_198, Thread_199, Thread_200, Thread_201, Thread_202, Thread_203, Thread_204, Thread_205, Thread_206, Thread_207, Thread_208, Thread_209, Thread_210, Thread_211, Thread_212, Thread_213, Thread_214, Thread_215, Thread_216, Thread_217, Thread_218, Thread_219, Thread_220, Thread_221, Thread_222, Thread_223, Thread_224, Thread_225, Thread_226, Thread_227, Thread_228, Thread_229, Thread_230, Thread_231, Thread_232, Thread_233, Thread_234, Thread_235, Thread_236, Thread_237, Thread_238, Thread_239, Thread_240, Thread_241, Thread_242, Thread_243, Thread_244, Thread_245, Thread_246, Thread_247, Thread_248, Thread_249, Thread_250, Thread_251, Thread_252, Thread_253, Thread_254, Thread_255, Thread_256, Thread_257, Thread_258, Thread_259, Thread_260, Thread_261, Thread_262, Thread_263, Thread_264, Thread_265, Thread_266, Thread_267, Thread_268, Thread_269, Thread_270, Thread_271, Thread_272, Thread_273, Thread_274, Thread_275, Thread_276, Thread_277, Thread_278, Thread_279, Thread_280, Thread_281, Thread_282, Thread_283, Thread_284, Thread_285, Thread_286, Thread_287, Thread_288, Thread_289, Thread_290, Thread_291, Thread_292, Thread_293, Thread_294, Thread_295, Thread_296, Thread_297, Thread_298, Thread_299, Thread_300, Thread_301, Thread_302, Thread_303, Thread_304, Thread_305, Thread_306, Thread_307, Thread_308, Thread_309, Thread_310, Thread_311, Thread_312, Thread_313, Thread_314, Thread_315, Thread_316, Thread_317, Thread_318, Thread_319
};
int main() {
CreateEvents();
CreateSemaphores();

char input[100];
printf("> ");
fgets(input, 100, stdin);
input[strcspn(input, "\n")] = 0;
                
if (strlen(input) != 40) {
    printf("Wrong");
    return 1;
}
                
HANDLE threadHandles[320];
for (int i = 0; i < 320; i++) {
    int bit = (input[i / 8] >> (i % 8)) & 1;
    threadHandles[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threads[i], (LPVOID)bit, 0, NULL);
}


    HANDLE finalHandles[7] = { threadHandles[270], threadHandles[6], threadHandles[256], threadHandles[30], threadHandles[10], threadHandles[214], threadHandles[264] };
    int res = WaitForMultipleObjects(7, finalHandles, TRUE, 5000); // 5 seconds


if (res == WAIT_TIMEOUT) {
    printf("Wrong");
    return 1;
}
                
printf("Correct");
return 0;
}