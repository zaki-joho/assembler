# SIMPLEアーキテクチャアセンブラ変換くん

## 使い方

\# から始まる行はコメントアウト(空白文字不可)  
ADD r[Rd] r[Rs] みたいな感じで書くと機械語が出てきてほしい  
使わない桁は適当に 0 fill

## アセンブリ記述例

ADD r[0] r[1]  
SLL r[0] 0010  
LD  r[0] r[1] 00010000

## 命令セット

### R形式[11 Rs(3) Rd(3) op3(4) d(4)]

ADD Rd, Rs : op3 = 0000 : r[Rd] = r[Rd] + r[Rs]  
SUB Rd, Rs : op3 = 0001 : r[Rd] = r[Rd] - r[Rs]  
AND Rd, Rs : op3 = 0010 : r[Rd] = r[Rd] & r[Rs]  
OR  Rd, Rs : op3 = 0011 : r[Rd] = r[Rd] | r[Rs]  
XOR Rd, Rs : op3 = 0100 : r[Rd] = r[Rd] ^ r[Rs]  
CMP Rd, Rs : op3 = 0101 : r[Rd] = r[Rd] - r[Rs]  
MOV Rd, Rs : op3 = 0110 : r[Rd] = r[Rs]  

SLL Rd, d  : op3 = 1000 : r[Rd] = r[Rd] << d  
SLR Rd, d  : op3 = 1001 : r[Rd] = r[Rd] << d (rotate)  
SRL Rd, d  : op3 = 1010 : r[Rd] = r[Rd] >> d  
SRA Rd, d  : op3 = 1011 : r[Rd] = r[Rd] >> d (arithmetic)  
IN  Rd, d  : op3 = 1100 : r[Rd] = input  
OUT Rd, d  : op3 = 1101 : output = r[Rs]  
HLT        :            : HALT

### load[00 Ra(3) Rb(3) d(8)]

LD  Ra, d(Rb) : r[Ra] = *(r[Rb] + d)

### store[01 Ra(3) Rb(3) d(8)]

ST  Ra, d(Rb) : *(r[Rb] + d) = r[Ra]

### load_immediate[10 op2(3) Rb(3) d(8)]

LI  Rb, d  : op2 = 000 : r[Rb] = d  
BR   Rb, d  : op2 = 100 : PC = PC + 1 + d

### branch[10 111 cond(3) d(8)]

BE  d : cond = 000 : if(Z) PC = PC + 1 + d  
BLT d : cond = 001 : if(S ^ V) PC = PC + 1 + d  
BLE d : cond = 010 : if (Z || (S ^ V)) PC = PC + 1 + d  
BNE d : cond = 011 : if(!Z) PC = PC + 1 + d