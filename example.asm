ADD r[0] r[1]
SUB r[0] r[1]
AND r[0] r[1]
OR r[0] r[1]
XOR r[0] r[1]
CMP r[0] r[1]
MOV r[0] r[1]
#comment_test
SLL r[0] 0001
SLR r[0] 0001
SRL r[0] 0001
SRA r[0] 0001

IN r[0] 0001
OUT r[0]

HLT

LD r[0] r[1] 00000001
ST r[0] r[1] 00000001

LI r[0] 00000001
BR r[0] 00000001

BE 00000001
BLT 00000001
BLE 00000001
BNE 00000001
