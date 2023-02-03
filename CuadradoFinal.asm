(START)
@24576
D=M
@FILLORCLEAR	
D;JNE
@START
0;JMP
(FILLORCLEAR) // if key = c --> draw a square else if key = b --> clear
@j
M = D // save key
@67  // press c
D = D - A
@Fill
D;JEQ
@j
D = M
@66 // press b 
D = D - A
@CLEAR
D;JEQ
@START
0;JMP
(Fill)
@16391
D=A 
@16
M=D 
(LINE)
@7
D = A
@17
M = D
(DRAW)
@16
A=M
M=-1
@16
M=M+1
@17
M=M-1
D=M
@DRAW
D;JNE
@25
D=A
@16
M=D+M
@19591
D=A
@16
D=D-M
@LINE
D;JGT
@START
0;JMP
(CLEAR)
@19565
D = A 
@16
M = D
(LOOP)
@16
A = M
M = 0
@16
M = M - 1
D = M
@16391
D = D - A
@LOOP
D;JGE 
@START
0;JMP
