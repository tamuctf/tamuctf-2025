000010 IDENTIFICATION DIVISION.
000020 PROGRAM-ID. BankingWeb.
000030
000040 ENVIRONMENT DIVISION.
000050
000060 INPUT-OUTPUT SECTION.
000070
000100 FILE-CONTROL.
000110   SELECT OPTIONAL USERS
000120   ASSIGN TO '/var/banking/users.dat'
000130   SORT STATUS IS FileErrorUsers
000140   LOCK MODE IS AUTOMATIC
000150   ORGANIZATION INDEXED
000160   ACCESS MODE RANDOM
000170   RECORD IS Username IN UserRecord
000200   ALTERNATE RECORD IS Cookie IN UserRecord.
000210
000220   SELECT OPTIONAL ACCOUNTS
000230   ASSIGN TO '/var/banking/accounts.dat'
000240   SORT STATUS IS FileErrorAccounts
000250   LOCK MODE IS AUTOMATIC
000260   ORGANISATION IS INDEXED
000270   ACCESS IS RANDOM
000300   RECORD KEY Account OF AccountRecord.
000310
000320   SELECT OPTIONAL PENDING
000330   ASSIGN TO '/var/banking/pending.dat'
000340   LOCK MODE IS AUTOMATIC
000350   ORGANIZATION IS LINE SEQUENTIAL
000360   ACCESS SEQUENTIAL.
000370
000400 DATA DIVISION.
000410
000420 FILE SECTION.
000430
000440 FD USERS.
000450 01 UserRecord.
000460   05 Username PIC X(32).
000470   05 Password PICTURE X(32).
000500   05 Cookie   PICTURE 9(32).
000510   05 IsAdmin  PIC 9(1).
000520   05 AccountList.
000530     10 AccountCount PIC 9(1) VALUE 0.
000540     10 Account OCCURS 8 TIMES PIC 9(12).
000550
000560 FD ACCOUNTS.
000570 01 AccountRecord.
000600   05 Account PICTURE 9(12) VALUE 0.
000610   05 Balance PIC 9(18)V99 VALUE 0.
000620
000630 FD PENDING.
000640 01 PendingRecord.
000650   05 Info PIC X(110).
000660
000670 WORKING-STORAGE SECTION.
000700
000710 01 FileErrorUsers    PIC XX.
000720 01 FileErrorAccounts PIC XX.
000730
000740 01 secrets PIC X(64).
000750 01 flags PIC X(64).
000760
000770 01 AccountSrc PIC 9(12) VALUE 0.
001000 01 AccountDst PICTURE 9(12) VALUE 0.
001010 01 Credit     PICTURE 9(20) VALUE 0.
001020 01 Memo       PICTURE X(64).
001030
001040 01 EnvVar  PIC X(4096).
001050 01 VarLen  USAGE BINARY-LONG.
001060 01 QueryString  PIC X(4096).
001070 01 QueryLen     USAGE BINARY-LONG VALUE 0.
001100 01 DATAA.
001110   05 DATAV OCCURS 8 TIMES PIC X(128).
001120 01 ReqData          PIC X(128).
001130 01 ReqCookieString  PIC X(64).
001140 01 ReqCookieName    PIC X(64).
001150 01 ReqCookieVal     PIC X(64).
001160 01 ARGS.
001170   05 ARG OCCURS 8 TIMES PIC X(128).
001200 01 ARGMAX PIC 9(3) VALUE 32.
001210 01 TestArg   PIC X(128).
001220
001230 01 Argind    USAGE BINARY-LONG VALUE 0.
001240 01 Argdone   USAGE BINARY-LONG VALUE 0.
001250 01 Argtarget PIC X(63).
001260 01 Argkey    PIC X(63).
001270 01 Argval    PIC X(64).
001300
001310 01 Dataind    USAGE BINARY-LONG VALUE 0.
001320 01 Datadone   USAGE BINARY-LONG VALUE 0.
001330 01 Datatarget PIC X(63).
001340 01 Datakey    PIC X(63).
001350 01 Dataval    PIC X(64).
001360
001370 01 Readdone     USAGE BINARY-LONG.
001400 01 Loginuser    PIC X(32).
001410 01 Loginpass    PIC X(32).
001420 01 Loginattempt PIC 9(1) VALUE 0.
001430 01 Loginsuccess PIC 9(1) VALUE 0.
001440
001450 01 SetCookie   PIC 9(1).
001460 01 Cookielen USAGE BINARY-LONG VALUE 0.
001470 01 Tmp PIC 9(1)V9.
001500 01 TmpS PIC X(3).
001510 01 Cookietarget PIC X(63).
001520
001530 01 AccountFnd PIC 9(1).
001540 01 Accountlen USAGE BINARY-LONG VALUE 0.
001550 01 AccountInd PIC 9(1).
001560 01 StatusCode PIC 9(3) VALUE 200.
001570 01 AccountDel PIC 9(1).
001600
001610 01 UrlHex PIC X(16) VALUE "0123456789ABCDEF".
001620 01 UrlTmp1 PIC 9(2).
001630 01 UrlTmp2 PIC 9(2).
001640 01 TmpU PIC X(2).
001650 01 TmpU2 PIC X(3).
001660
001670 01 Userexists      USAGE BINARY-LONG.
001700 01 CreateUsers     USAGE BINARY-LONG.
001710 01 Registersuccess USAGE BINARY-LONG.
001720
001730 01 file-info.
001740   05 File-Size-In-Bytes PIC 9(18) COMP.
001750   05 Mod-DD PIC 9(2) COMP.
001760   05 Mod-MO PIC 9(2) COMP.
001770   05 Mod-YYYY PIC 9(4) COMP.
002000   05 Mod-HH PIC 9(2) COMP.
002010   05 Mod-MM PIC 9(2) COMP.
002020   05 Mod-SS PIC 9(2) COMP.
002030   05 FILLER PIC 9(2) COMP.
002040
002050
002060 PROCEDURE DIVISION.
002070 GO TO 000-Route.
002100
002110 100-Parse-Args.
002120   MOVE 1 TO Argind
002130   MOVE 0 TO Argdone
002140   PERFORM UNTIL Argind > 8 OR Argdone = 1
002150     UNSTRING ARG(Argind) DELIMITED BY "=" INTO Argkey Argval
002160     IF Argkey IS EQUAL TO Argtarget
002170       MOVE 1 TO Argdone
002200     END-IF
002210     COMPUTE Argind = Argind + 1
002220   END-PERFORM
002230   .
002240
002250 100-Parse-Data.
002260   MOVE 1 TO Dataind
002270   MOVE 0 TO Datadone
002300   PERFORM UNTIL Dataind > 8 OR Datadone = 1
002310     UNSTRING DATAV(Dataind) DELIMITED BY "=" INTO Datakey
002320     Dataval
002330     IF Datakey IS EQUAL TO Datatarget
002340       MOVE 1 TO Datadone
002350     END-IF
002360     COMPUTE Dataind = Dataind + 1
002370   END-PERFORM
002400   .
002410
002420 101-Parse-Cookie.
002430   UNSTRING ReqCookieString DELIMITED BY "=" INTO ReqCookieName
002440   ReqCookieVal
002450   .
002460
002470
002500 102-Decode.
002510   MOVE 1 TO UrlTmp1
002520   MOVE 1 TO UrlTmp2
002530   PERFORM UNTIL UrlTmp1 > 8
002540     PERFORM UNTIL UrlTmp2 > 16
002550       STRING UrlHex (UrlTmp1:1) UrlHex (UrlTmp2:1) INTO TmpU
002560       STRING '  ' FUNCTION HEX-TO-CHAR (TmpU) INTO TmpS
002570       STRING '%' TmpU INTO TmpU2
002600       INSPECT Dataval REPLACING ALL TmpU2 BY TmpS
002610       COMPUTE UrlTmp2 = UrlTmp2 + 1
002620     END-PERFORM
002630     MOVE 1 TO UrlTmp2
002640     COMPUTE UrlTmp1 = UrlTmp1 + 1
002650   END-PERFORM
002660   .
002670
002700 000-Route.
002710   ACCEPT QueryString FROM ENVIRONMENT 'QUERY_STRING'.
002720   INSPECT QueryString TALLYING QueryLen FOR CHARACTERS BEFORE
002730   INITIAL SPACE
002740   ACCEPT ReqCookieString FROM ENVIRONMENT 'HTTP_COOKIE'.
002750   ACCEPT ReqData FROM SYSIPT.
002760   UNSTRING QueryString DELIMITED BY "&" INTO ARG (1) ARG (2)
002770   ARG (3) ARG (4) ARG (5) ARG (6) ARG (7) ARG (8)
003000   UNSTRING ReqData DELIMITED BY "&" INTO DATAV (1) DATAV (2)
003010   DATAV (3) DATAV (4) DATAV (5) DATAV (6) DATAV (7) DATAV (8)
003020   PERFORM 101-Parse-Cookie
003030   MOVE "page" to Argtarget
003040   PERFORM 100-Parse-Args
003050   IF Argdone = 1
003060     IF Argval = "login"
003070       PERFORM 001-Login-Page
003100     ELSE IF Argval = "register"
003110       PERFORM 002-Register-Page
003120     ELSE IF Argval = "home"
003130       PERFORM 003-Home-Page
003140     ELSE IF Argval = "manage"
003150       PERFORM 004-Manage-Page
003160     ELSE IF Argval = "transact"
003170       PERFORM 005-Transact-Page
003200     ELSE IF Argval = "flag"
003210       PERFORM 006-Flag-Page
003220     ELSE IF Argval = "admin"
003230       PERFORM 007-Admin-Page
003240     ELSE IF Argval = "batch"
003250       PERFORM 103-DB-BatchProcess
003260     ELSE
003270       PERFORM 000-Redirect-Home
003300     END-IF
003310   ELSE
003320     PERFORM 000-Redirect-Home
003330   END-IF
003340   STOP RUN
003350   .
003360
003370 200-HTTP-Header.
003400   DISPLAY 'Content-type: text/html'
003410   IF SetCookie NOT = 0
003420     DISPLAY 'Set-Cookie: session=' WITH NO ADVANCING
003430     DISPLAY Cookie
003440   END-IF
003450   DISPLAY 'Status: ' WITH NO ADVANCING
003460   DISPLAY StatusCode
003470   .
003500
003510 200-HTML-Header.
003520   PERFORM 200-HTTP-Header
003530   DISPLAY X'0A'
003540   DISPLAY '<html>'
003550   .
003560
003570 201-HTML-Footer.
003600   DISPLAY '</html>'
003610   .
003620
003630 101-DB-Login.
003640   MOVE Loginuser to Username
003650   MOVE 0 TO Loginsuccess
003660   OPEN INPUT USERS
003670     READ USERS INTO UserRecord KEY IS Username
003700     IF FileErrorUsers = "00"
003710       IF Password = Loginpass
003720         MOVE 1 To Loginsuccess
003730       END-IF
003740     ELSE
003750       DISPLAY FileErrorUsers
003760     END-IF
003770   CLOSE USERS
004000   IF Loginsuccess = 1
004010     PERFORM 103-DB-CookieGen
004020     MOVE 1 TO SetCookie
004030     OPEN I-O USERS
004040       REWRITE UserRecord
004050     CLOSE USERS
004060   END-IF
004070   .
004100
004110 102-DB-Register.
004120   MOVE 0 TO Userexists
004130   MOVE 0 TO Registersuccess
004140   MOVE Loginuser to Username
004150   OPEN INPUT USERS
004160     READ USERS INTO UserRecord KEY IS Username
004170     IF FileErrorUsers = "00"
004200       MOVE 1 To Userexists
004210     END-IF
004220   CLOSE USERS
004230
004240   if Userexists NOT = 1
004250     MOVE Loginpass to Password
004260     MOVE Loginuser to Username
004270     MOVE 0 to AccountCount
004300     PERFORM 103-DB-CookieGen
004310     MOVE 0 TO IsAdmin
004320
004330     OPEN I-O USERS
004340       WRITE UserRecord
004350     CLOSE USERS
004360     IF FileErrorUsers = "00"
004370       MOVE 1 To Registersuccess
004400     Else
004410       Display FileErrorUsers
004420     END-IF
004430   END-IF
004440   .
004450
004460 103-DB-CookieGen.
004470   MOVE 0 TO Cookielen
004500   PERFORM UNTIL Cookielen = 32
004510     MOVE FUNCTION RANDOM TO Tmp
004520     MULTIPLY 10 BY Tmp
004530     ADD 1 TO Cookielen
004540     MULTIPLY 10 BY Cookie
004550     ADD Tmp TO Cookie
004560   END-PERFORM
004570   .
004600
004610 103-DB-CookieCheck.
004620   MOVE ReqCookieVal to Cookie
004630   MOVE 0 TO Loginsuccess
004640   OPEN INPUT USERS
004650     READ USERS INTO UserRecord KEY IS Cookie
004660     IF FileErrorUsers = "00"
004670       MOVE 1 TO Loginsuccess
004700     END-IF
004710   CLOSE USERS
004720     .
004730
004740 103-DB-AdminCheck.
004750   MOVE 0 TO Loginsuccess
004760   IF IsAdmin = 1
004770     MOVE 1 TO Loginsuccess
005000   END-IF
005010   MOVE "secret" to Datatarget
005020   PERFORM 100-Parse-Data
005030
005040   ACCEPT secrets FROM ENVIRONMENT 'SECRET'.
005050   IF Datadone = 1 AND Dataval = secrets
005060     MOVE 1 TO Loginsuccess
005070   END-IF
005100   .
005110
005120 104-DB-GetAccount.
005130   MOVE 0 TO AccountFnd
005140   OPEN INPUT ACCOUNTS
005150     READ ACCOUNTS INTO AccountRecord KEY IS Account OF
005160     AccountRecord
005170     IF FileErrorAccounts = "00"
005200       MOVE 1 TO AccountFnd
005210     END-IF
005220   CLOSE ACCOUNTS
005230   .
005240
005250 105-DB-Transact.
005260   MOVE AccountSrc TO Info (1:)
005270   MOVE AccountDst TO Info (14:)
005300   MOVE Credit TO Info (27:)
005310   MOVE Memo TO Info (48:)
005320   OPEN EXTEND PENDING
005330     WRITE PendingRecord
005340   CLOSE PENDING
005350   .
005360
005370 103-DB-BatchProcess.
005400   IF ReqCookieName NOT = "session"
005410     PERFORM 000-Redirect-Login
005420     EXIT SECTION
005430   END-IF
005440
005450   PERFORM 103-DB-CookieCheck
005460   IF Loginsuccess NOT = 1
005470     PERFORM 000-Redirect-Login
005500     EXIT SECTION
005510   END-IF
005520
005530   PERFORM 103-DB-AdminCheck
005540   IF Loginsuccess NOT = 1
005550     PERFORM 000-Redirect-Login
005560     EXIT SECTION
005570   END-IF
005600
005610
005620   PERFORM 200-HTML-Header
005630   DISPLAY '<form action="" method="post"><input type="hidden" n'
005640   'ame="action" value="batch"><button type="submit">Run transac'
005650   'tion batch</button></form><p><table>'
005660
005670   MOVE "action" to Datatarget
005700     PERFORM 100-Parse-Data
005710
005720     IF Datadone = 1 AND Dataval = "batch"
005730       DISPLAY '<tr><th>Status</th><th>Memo</th><th>Sending Acco'
005740       'unt</th><th>Receiving Account</th><th>Amount</th></tr>'
005750         OPEN INPUT PENDING
005760           PERFORM FOREVER
005770             READ PENDING INTO PendingRecord AT END EXIT
006000             PERFORM NOT AT END
006010             MOVE Info (1:12) TO AccountSrc
006020             MOVE Info (14:12) TO AccountDst
006030             MOVE Info (27:20) TO Credit
006040             MOVE Info (48:) TO Memo
006050
006060             MOVE 0 TO Readdone
006070             MOVE AccountSrc TO Account OF AccountRecord
006100             PERFORM 104-DB-GetAccount
006110             IF AccountFnd = 1 AND Credit <= Balance
006120               MOVE AccountDst TO Account OF AccountRecord
006130               PERFORM 104-DB-GetAccount
006140               DISPLAY 'Accounthasmoney'
006150               IF AccountFnd = 1
006160                 MOVE 1 TO Readdone
006170               END-IF
006200             END-IF
006210             DISPLAY '<tr><td>' WITH NO ADVANCING
006220             IF Readdone NOT = 1
006230               DISPLAY 'Denied' WITH NO ADVANCING
006240             ELSE
006250               DISPLAY 'Confirmed' WITH NO ADVANCING
006260               COMPUTE Balance = Balance + Credit
006270               OPEN I-O ACCOUNTS
006300                 REWRITE AccountRecord
006310               CLOSE ACCOUNTS
006320               MOVE AccountSrc TO Account OF AccountRecord
006330               PERFORM 104-DB-GetAccount
006340               COMPUTE Balance = Balance - Credit
006350               OPEN I-O ACCOUNTS
006360                 REWRITE AccountRecord
006370               CLOSE ACCOUNTS
006400             END-IF
006410             DISPLAY '</td><td>' WITH NO ADVANCING
006420             DISPLAY Memo WITH NO ADVANCING
006430             DISPLAY '</td><td>' WITH NO ADVANCING
006440             DISPLAY AccountSrc
006450             DISPLAY '</td><td>' WITH NO ADVANCING
006460             DISPLAY AccountDst
006470             DISPLAY '</td><td>' WITH NO ADVANCING
006500             DISPLAY Credit
006510             DISPLAY '</td></tr>'
006520
006530           END-PERFORM
006540         CLOSE PENDING
006550       DISPLAY '</table></p>'
006560       OPEN OUTPUT PENDING CLOSE PENDING
006570     END-IF
006600   PERFORM 201-HTML-Footer
006610   .
006620
006630 000-Redirect-Login.
006640   MOVE 302 TO StatusCode
006650   PERFORM 200-HTTP-Header
006660   DISPLAY 'Location: /?page=login'
006670   DISPLAY X'0A'
006700   .
006710
006720 000-Redirect-Home.
006730   MOVE 302 TO StatusCode
006740   PERFORM 200-HTTP-Header
006750   DISPLAY 'Location: /?page=home'
006760   DISPLAY X'0A'
006770   .
007000
007010 001-Login-Page.
007020   IF ReqCookieName = "session"
007030     PERFORM 103-DB-CookieCheck
007040     IF Loginsuccess = 1
007050       PERFORM 000-Redirect-Home
007060       EXIT SECTION
007070     END-IF
007100   END-IF
007110
007120   MOVE "action" to Datatarget
007130   PERFORM 100-Parse-Data
007140
007150   IF Datadone = 1
007160     IF Dataval = "login"
007170       MOVE 1 TO Loginattempt
007200
007210       MOVE "username" TO Datatarget
007220       PERFORM 100-Parse-Data
007230       IF Datadone = 1
007240         MOVE Dataval TO Loginuser
007250       END-IF
007260
007270       MOVE "password" to Datatarget
007300       PERFORM 100-Parse-Data
007310       IF Datadone = 1
007320         MOVE Dataval TO Loginpass
007330       END-IF
007340
007350       MOVE 0 TO Readdone
007360
007370       PERFORM 101-DB-Login
007400
007410     END-IF
007420   END-IF
007430
007440   if Loginsuccess = 1 AND Loginattempt = 1
007450     PERFORM 000-Redirect-Home
007460     EXIT SECTION
007470   END-IF
007500
007510   PERFORM 200-HTML-Header
007520
007530   if Loginsuccess NOT = 1
007540     IF Loginattempt = 1
007550       DISPLAY '<strong>Failed to login!</strong>'
007560     END-IF
007570   END-IF
007600
007610   DISPLAY '<title>Bank site - Login</title><body><h1>Online Ban'
007620   'king login</h1><form action="" method="post"><input type="hi'
007630   'dden" name="action" value="login"><p><label for="username">U'
007640   'sername</label><input type="text" id="username" name="userna'
007650   'me" required></p><p><label for="password">Password</label><i'
007660   'nput type="password" id="password" name="password" required>'
007670   '</p><p><button type="submit">Submit</button></p><hr><p>New t'
007700   'o online banking? <a href="/?page=register">register here</a'
007710   '>.</body>'
007720   PERFORM 201-HTML-Footer
007730   .
007740
007750 002-Register-Page.
007760   IF ReqCookieName = "session"
007770     PERFORM 103-DB-CookieCheck
010000     IF Loginsuccess = 1
010010       PERFORM 000-Redirect-Home
010020       EXIT SECTION
010030     END-IF
010040   END-IF
010050
010060
010070   MOVE "action" to Datatarget
010100   PERFORM 100-Parse-Data
010110
010120   PERFORM 200-HTML-Header
010130   IF Datadone = 1
010140     IF Dataval = "register"
010150
010160       MOVE "username" TO Datatarget
010170       PERFORM 100-Parse-Data
010200       IF Datadone = 1
010210         MOVE Dataval TO Loginuser
010220       END-IF
010230
010240       MOVE "password" to Datatarget
010250       PERFORM 100-Parse-Data
010260       IF Datadone = 1
010270         MOVE Dataval TO Loginpass
010300       END-IF
010310
010320       PERFORM 102-DB-Register
010330       if Registersuccess NOT = 1
010340         IF Userexists = 1
010350            DISPLAY '<strong>User already exists</strong>'
010360         ELSE
010370            DISPLAY '<strong>Failed to register!</strong>'
010400         END-IF
010410       ELSE
010420         DISPLAY '<strong>Registered! Log in <a href="?page=logi'
010430         'n">here</a></strong>'
010440       END-IF
010450     END-IF
010460   END-IF
010470
010500   DISPLAY '<title>Bank site - Registration</title><body><h1>R'
010510   'egister for online banking</h1><form action="" method="pos'
010520   't"> <input type="hidden" name="action" value="register"><p'
010530   '><label for="username">Username</label><input type="text" '
010540   'id="username" name="username" required></p><p><label for="'
010550   'password">Password</label><input type="password" id="passw'
010560   'ord" name="password" required></p><p><button type="submit"'
010570   '>Submit</button></p><hr><p>Already have an account? <a hre'
010600   'f="/?page=login">log in here</a>. </body>'
010610   PERFORM 201-HTML-Footer
010620   .
010630
010640 010-Auth-Navbar.
010650   DISPLAY '<h1>Online Banking</h1><nav><ul><li><a href="?page'
010660   '=home">Home</a></li><li><a href="?page=manage">Manage acco'
010670   'unts</a></li><li><a href="?page=transact">Make a transacti'
010700   'on</a></li></ul></nav>'
010710   .
010720
010730 003-Home-Page.
010740   IF ReqCookieName NOT = "session"
010750     PERFORM 000-Redirect-Login
010760     EXIT SECTION
010770   END-IF
011000
011010   PERFORM 103-DB-CookieCheck
011020   IF Loginsuccess NOT = 1
011030     PERFORM 000-Redirect-Login
011040     EXIT SECTION
011050   END-IF
011060
011070   PERFORM 200-HTML-Header
011100   DISPLAY '<title>Bank site - Home</title><body>'
011110
011120   PERFORM 010-Auth-Navbar
011130
011140   DISPLAY '<h2>Home page</h2>'
011150   DISPLAY '<h3>Your accounts ( ' WITH NO ADVANCING
011160   DISPLAY AccountCount
011170   DISPLAY ')</h3><p><table><tr><th>Account</th><th>Balance</th>'
011200   '<td></td></tr>'
011210
011220   MOVE 1 TO AccountInd
011230   PERFORM UNTIL AccountInd > AccountCount
011240     MOVE Account IN AccountList (AccountInd) TO Account OF
011250     AccountRecord
011260     PERFORM 104-DB-GetAccount
011270     DISPLAY '<tr><td>' WITH NO ADVANCING
011300     DISPLAY Account IN AccountRecord
011310     DISPLAY '</td><td> $' WITH NO ADVANCING
011320     DISPLAY Balance
011330     DISPLAY '</td></tr>'
011340     COMPUTE AccountInd = AccountInd + 1
011350   END-PERFORM
011360
011370   DISPLAY '</table></p><marquee>Limited time offer! <a href="/?'
011400   'page=flag">Buy a flag</a> for only $99,999,999.99!</marquee>'
011410   '</body>'
011420   PERFORM 201-HTML-Footer
011430   .
011440
011450 004-Manage-Page.
011460   IF ReqCookieName NOT = "session"
011470     PERFORM 000-Redirect-Login
011500     EXIT SECTION
011510   END-IF
011520
011530   PERFORM 103-DB-CookieCheck
011540   IF Loginsuccess NOT = 1
011550     PERFORM 000-Redirect-Login
011560     EXIT SECTION
011570   END-IF
011600
011610   MOVE "action" to Datatarget
011620   PERFORM 100-Parse-Data
011630   IF Datadone = 1
011640     IF Dataval = "new"
011650       IF AccountCount < 8
011660         COMPUTE AccountCount = AccountCount + 1
011670         MOVE 0 TO Accountlen
011700         PERFORM UNTIL Accountlen = 12
011710           MOVE FUNCTION RANDOM TO Tmp
011720           MULTIPLY 10 BY Tmp
011730           ADD 1 TO Accountlen
011740           MULTIPLY 10 BY Account OF AccountList
011750           (AccountCount)
011760           ADD Tmp TO  Account OF AccountList (AccountCount)
011770         END-PERFORM
012000         OPEN I-O USERS
012010           REWRITE UserRecord
012020         CLOSE USERS
012030         MOVE 1 TO Balance IN AccountRecord
012040         MOVE Account IN AccountList (AccountCount) TO Account
012050         OF AccountRecord
012060           OPEN I-O ACCOUNTS
012070             WRITE AccountRecord
012100           CLOSE ACCOUNTS
012110       END-IF
012120     END-IF
012130   END-IF
012140
012150   MOVE "action" to Datatarget
012160   PERFORM 100-Parse-Data
012170   IF Datadone = 1
012200     IF Dataval = "delete"
012210       MOVE "id" to Datatarget
012220       PERFORM 100-Parse-Data
012230       MOVE 0 TO AccountDel
012240       IF Datadone = 1 AND FUNCTION NUMVAL (Dataval) <=
012250         AccountCount AND FUNCTION NUMVAL (Dataval) >= 0
012260         MOVE Account IN AccountList (FUNCTION NUMVAL (Dataval))
012270         TO Account OF AccountRecord
012300
012310         OPEN I-O ACCOUNTS
012320           DELETE ACCOUNTS RECORD
012330         CLOSE ACCOUNTS
012340
012350         MOVE FUNCTION NUMVAL(Dataval) to AccountInd
012360         PERFORM UNTIL AccountInd + 1 > AccountCount
012370           MOVE Account OF AccountList (AccountInd + 1) TO
012400             Account OF AccountList (AccountInd)
012410           COMPUTE AccountInd = AccountInd + 1
012420         END-PERFORM
012430         COMPUTE AccountCount = AccountCount - 1
012440
012450         OPEN I-O USERS
012460           REWRITE UserRecord
012470         CLOSE USERS
012500       END-IF
012510     END-IF
012520   END-IF
012530
012540
012550   PERFORM 200-HTML-Header
012560   DISPLAY '<title>Bank site - Manage Accounts</title><body>'
012570
012600   PERFORM 010-Auth-Navbar
012610   DISPLAY '<h2>Account management</h2>'
012620   DISPLAY '<h3>Your accounts ( ' WITH NO ADVANCING
012630   DISPLAY AccountCount
012640   DISPLAY ')</h3>'
012650   DISPLAY '<p><table>'
012660   DISPLAY '<tr><th>Account</th><th>Balance</th><td></td>'
012670             '</tr>'
012700
012710   MOVE 1 TO AccountInd
012720   PERFORM UNTIL AccountInd > AccountCount
012730       MOVE Account IN AccountList (AccountInd) TO Account OF
012740       AccountRecord
012750       PERFORM 104-DB-GetAccount
012760       DISPLAY '<tr><td>' WITH NO ADVANCING
012770       DISPLAY Account IN AccountRecord
013000       DISPLAY '</td><td> $' WITH NO ADVANCING
013010       DISPLAY Balance
013020       DISPLAY '</td><td>'
013030       DISPLAY '<form action="" method="post"><button type="sub'
013040       'mit" name="action" value="delete"/>Delete</button><inpu'
013050       't type="hidden" name="id" value="' WITH NO ADVANCING
013060       DISPLAY AccountInd WITH NO ADVANCING
013070       DISPLAY '"/></form>'
013100       COMPUTE AccountInd = AccountInd + 1
013110   END-PERFORM
013120
013130   DISPLAY '</table></p>'
013140   IF AccountCount < 8
013150     DISPLAY '<form action="" method="post"><button type="sub'
013160     'mit" name="action" value="new"/>Create a new account</b'
013170     'utton</form>'
013200   END-IF
013210   DISPLAY '</body>'
013220   PERFORM 201-HTML-Footer
013230   .
013240
013250 005-Transact-Page.
013260   IF ReqCookieName NOT = "session"
013270     PERFORM 000-Redirect-Login
013300     EXIT SECTION
013310   END-IF
013320
013330   PERFORM 103-DB-CookieCheck
013340   IF Loginsuccess NOT = 1
013350     PERFORM 000-Redirect-Login
013360     EXIT SECTION
013370   END-IF
013400
013410  MOVE "action" to Datatarget
013420  PERFORM 100-Parse-Data
013430  IF Datadone = 1 AND Dataval = "send"
013440    MOVE "send_account" to Datatarget
013450    PERFORM 100-Parse-Data
013460
013470    IF Datadone = 1 AND Dataval > 0 AND Dataval <= AccountCount
013500      MOVE Dataval TO AccountInd
013510      MOVE Account OF AccountList (AccountInd) TO AccountSrc
013520
013530
013540      MOVE "receive_account" to Datatarget
013550      PERFORM 100-Parse-Data
013560      IF Datadone = 1 AND Dataval > 100000000000 AND
013570        Dataval <= 999999999999
013600        MOVE Dataval TO Account IN AccountRecord
013610        PERFORM 104-DB-GetAccount
013620        IF AccountFnd = 1
013630          MOVE Dataval TO AccountDst
013640          MOVE "amount" to Datatarget
013650          PERFORM 100-Parse-Data
013660          IF Datadone = 1 AND Dataval > 0
013670            MOVE Dataval TO Credit
013700            MOVE "memo" to Datatarget
013710            PERFORM 100-Parse-Data
013720            IF Datadone = 1
013730              PERFORM 102-Decode
013740              MOVE Dataval TO Memo
013750              PERFORM 105-DB-Transact
013760            END-IF
013770          END-IF
014000        END-IF
014010      END-IF
014020    END-IF
014030  END-IF
014040
014050
014060  PERFORM 200-HTML-Header
014070  DISPLAY '<title>Bank site - Make a transaction</title><body>'
014100  PERFORM 010-Auth-Navbar
014110  DISPLAY '<h2>Make a transaction</h2>'
014120
014130  DISPLAY '<form action="/?page=transact" method="post"><input t'
014140  'ype="hidden" name="action" value="send"><p><label for="send_a'
014150  'ccount">Sending account</label><select required name="send_ac'
014160  'count" id="send_account">'
014170
014200  MOVE 1 TO AccountInd
014210  PERFORM UNTIL AccountInd > AccountCount
014220    MOVE Account IN AccountList (AccountInd) TO Account OF
014230    AccountRecord
014240    PERFORM 104-DB-GetAccount
014250    DISPLAY '<option value="' WITH NO ADVANCING
014260    DISPLAY AccountInd WITH NO ADVANCING
014270    DISPLAY '">'
014300    DISPLAY Account IN AccountRecord
014310    DISPLAY '</option>'
014320    COMPUTE AccountInd = AccountInd + 1
014330  END-PERFORM
014340
014350  DISPLAY '</select></p><p><label for="receive_account">Receivin'
014360  'g account</label><input required type="number" name="receive_'
014370  'account" id="receive_account" min=1000000000.00 max=999999999'
014400  '9.99 step=1></p><p><label for="amount">Amount to send</lab'
014410  'el><input required type="number"  step=0.01 min=1 max=9999999'
014420  '9999999999999></p><p><label for="memo">Notes</label><input re'
014430  'quired id="memo" name="memo"></p><p><button type="submit">Sen'
014440  'd money</button></p></form>'
014450
014460  PERFORM 201-HTML-Footer
014470  .
014500
014510 006-Flag-Page.
014520   IF ReqCookieName NOT = "session"
014530     PERFORM 000-Redirect-Login
014540     EXIT SECTION
014550   END-IF
014560
014570   PERFORM 103-DB-CookieCheck
014600   IF Loginsuccess NOT = 1
014610     PERFORM 000-Redirect-Login
014620     EXIT SECTION
014630   END-IF
014640
014650  PERFORM 200-HTML-Header
014660  MOVE "action" to Datatarget
014670  PERFORM 100-Parse-Data
014700  IF Datadone = 1 AND Dataval = "buy"
014710    MOVE "account" to Datatarget
014720    PERFORM 100-Parse-Data
014730
014740    IF Datadone = 1 AND Dataval > 0 AND Dataval <= AccountCount
014750      MOVE Dataval TO AccountInd
014760      MOVE Account OF AccountList (AccountInd) TO
014770      Account OF AccountRecord
015000      PERFORM 104-DB-GetAccount
015010
015020      IF Balance >= 99999999.99
015030          COMPUTE Balance = Balance - 99999999.99
015040          OPEN I-O ACCOUNTS
015050              REWRITE AccountRecord
015060          CLOSE ACCOUNTS
015070          ACCEPT flags FROM ENVIRONMENT 'FLAG'
015100          DISPLAY flags
015110          PERFORM 201-HTML-Footer
015120          EXIT SECTION
015130      ELSE
015140          DISPLAY '<strong>Failed to purchase! Insufficient fund'
015150          's</strong>'
015160      END-IF
015170    END-IF
015200  END-IF
015210
015220
015230   DISPLAY '<title>Bank site - Buy a flag</title><body>'
015240   PERFORM 010-Auth-Navbar
015250   DISPLAY '<h2>Buy a flag, only $99,999,999.99 for a limited '
015260   'time!</h2>'
015270
015300   DISPLAY '<form action="/?page=flag" method="post"><input type'
015310   '="hidden" name="action" value="buy"><p><label for="account">'
015320   'Purchase account</label><select required name="account"id="a'
015330   'ccount">'
015340
015350   MOVE 1 TO AccountInd
015360   PERFORM UNTIL AccountInd > AccountCount
015370     MOVE Account IN AccountList (AccountInd) TO Account OF
015400     AccountRecord
015410     PERFORM 104-DB-GetAccount
015420     DISPLAY '<option value="' WITH NO ADVANCING
015430     DISPLAY AccountInd WITH NO ADVANCING
015440     DISPLAY '">'
015450     DISPLAY Account IN AccountRecord
015460     DISPLAY '</option>'
015470     COMPUTE AccountInd = AccountInd + 1
015500   END-PERFORM
015510
015520   DISPLAY '</select></p><p><button type="submit">Submit</button'
015530   '></p></form>'
015540
015550   PERFORM 201-HTML-Footer
015560   .
015570
015600
015610 007-Admin-Page.
015620   IF ReqCookieName NOT = "session"
015630     PERFORM 000-Redirect-Login
015640     EXIT SECTION
015650   END-IF
015660
015670   PERFORM 103-DB-CookieCheck
015700   IF Loginsuccess NOT = 1
015710     PERFORM 000-Redirect-Login
015720     EXIT SECTION
015730   END-IF
015740
015750   PERFORM 200-HTML-Header
015760   MOVE 'administrator' to Username
015770   MOVE 0 TO Loginsuccess
016000   OPEN INPUT USERS
016010     READ USERS
016020       INTO UserRecord
016030       KEY IS Username
016040     END-READ
016050   CLOSE USERS
016060   DISPLAY '<!--'
016070   DISPLAY '<h3>Your accounts ( ' WITH NO ADVANCING
016100   DISPLAY AccountCount
016110   DISPLAY ')</h3><p><table><tr><th>Account</th><th>Balance</th>'
016120   '<td></td></tr>'
016130
016140   MOVE 1 TO AccountInd
016150   PERFORM UNTIL AccountInd > AccountCount
016160       MOVE Account IN AccountList (AccountInd) TO Account OF
016170       AccountRecord
016200       PERFORM 104-DB-GetAccount
016210       DISPLAY '<tr><td>' WITH NO ADVANCING
016220       DISPLAY Account IN AccountRecord
016230       DISPLAY '</td><td> $' WITH NO ADVANCING
016240       DISPLAY Balance
016250       DISPLAY '</td></tr>'
016260       COMPUTE AccountInd = AccountInd + 1
016270   END-PERFORM
016300
016310   DISPLAY '</table></p>'
016320   DISPLAY '-->'
016330
016340   PERFORM 103-DB-AdminCheck
016350   IF Loginsuccess NOT = 1
016360       EXIT SECTION
016370   END-IF
016400
016410   MOVE "action" to Datatarget
016420   PERFORM 100-Parse-Data
016430   IF Datadone = 1 AND Dataval = "refresh"
016440     MOVE "account" to Datatarget
016450     PERFORM 100-Parse-Data
016460
016470     IF Datadone = 1 AND Dataval > 0 AND Dataval <=
016500       AccountCount
016510       MOVE Dataval TO AccountInd
016520       MOVE Account IN AccountList (AccountInd) TO Account OF
016530       AccountRecord
016540       PERFORM 104-DB-GetAccount
016550
016560       MOVE 999999999999999999.99 TO Balance
016570       OPEN I-O ACCOUNTS
016600         REWRITE AccountRecord
016610       CLOSE ACCOUNTS
016620     END-IF
016630   END-IF
016640
016650
016660   DISPLAY '<title>Bank site - Admin page</title><body>'
016670   PERFORM 010-Auth-Navbar
016700   DISPLAY '<h2>Admin page</h2><form action="/?page=admin" metho'
016710   'd="post"><input type="hidden" name="action" value="refresh">'
016720   '<p><label for="account">Account to grant money</label><selec'
016730   't required name="account"id="account">'
016740
016750   MOVE 1 TO AccountInd
016760   PERFORM UNTIL AccountInd > AccountCount
016770       MOVE Account IN AccountList (AccountInd) TO Account OF
017000       AccountRecord
017010       PERFORM 104-DB-GetAccount
017020       DISPLAY '<option value="' WITH NO ADVANCING
017030       DISPLAY AccountInd WITH NO ADVANCING
017040       DISPLAY '">'
017050       DISPLAY Account IN AccountRecord
017060       DISPLAY '</option>'
017070       COMPUTE AccountInd = AccountInd + 1
017100   END-PERFORM
017110
017120   DISPLAY '</select></p><p><button type="submit">Submit</button'
017130   '></p></form>'
017140
017150   PERFORM 201-HTML-Footer
017160   .
