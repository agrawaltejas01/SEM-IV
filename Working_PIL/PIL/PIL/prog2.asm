;i/p o/p - done
;STRLEN - done
;reverse - done
;concat - NOT DONE
;compare - done
;input == atharva
;strlen == 7
.model small
.stack
.data
	string db "HELLO",'$'
	STR1 DB 32 DUP("$")
	STR2 DB 32 DUP("$")
	DOLLER DB 0H
	EQUAL DB "EQUAL$"
	NOTEQUAL DB "NOTEQUAL$"
	STRLEN1 DB ?
	STRLEN2 DB ?
.code
	MOV AX,@DATA
	MOV DS,AX
	
	;string i/o >>>---------------------------------------------------------------------
	MOV AH,0AH				;buffered keyboard input
	LEA DX,STR1				;load effective adress of str into DX
	INT 21H					;service number

	MOV AH,02H				;new line
	MOV DL,0AH				;new line
	INT 21H					;service number

	;MOV AH,09H				;display string
	;LEA DX,STR1+2				;load effective adress of str1 in DX
	;INT 21H					;service number

	MOV AH,02H				;newline
	MOV DL,0AH				;newline
	INT 21H					;service number

	MOV AH,0AH				;buffered keyboard input
	LEA DX,STR2				;load effective adress of str into DX
	INT 21H					;service number

	MOV AH,02H				;newline
	MOV DL,0AH				;newline
	INT 21H					;service number	
	;---------------------------------------------------------------------------------<<<	

	;string length >>>--------------------------------------------------------------------
	;string 1*****************************************************************************
	LEA SI,STR1+3				;move effective adress of str1 in SI register
	MOV CX,0H				;initialize CL with 0
	L1:					;jump position L1
	CMP BYTE PTR[SI],"$"			;compare contents of register SI with '$' (end of string)
	JE L2					;if end of string reached jump to L2
	INC CX					;increment CL register
	INC SI					;increment SI register
	JNZ L1					;jump if not zero
	
	L2:					;jump position L2
	MOV WORD PTR[STRLEN1],CX				;store string length in STRLEN
	ADD CX,30H				;add 30h ascii to contents CL

	;string 2*********************************************************************************
	;MOV SI,0
	LEA SI,STR2+3				;move effective adress of str1 in SI register
	MOV CX,0H				;initialize CL with 0
	L6:					;jump position L1
	CMP BYTE PTR[SI],"$"			;compare contents of register SI with '$' (end of string)
	JE L7					;if end of string reached jump to L2
	INC CX					;increment CL register
	INC SI					;increment SI register
	JNZ L6					;jump if not zero
	
	L7:					;jump position L2
	MOV WORD PTR[STRLEN2],CX				;store string length in STRLEN
	ADD CX,30H				;add 30h ascii to contents CL
	
	;---------------------------------------------------------------------------------<<<

	;string reverse----------------------------------------------------------------------
	;MOV CX,WORD PTR[STRLEN]
	;LEA SI,STR1+2
	;ADD SI,WORD PTR[STRLEN]
	;LEA DI,STR2+2

	;L3:
	;MOV AL,[SI]
	;MOV [DI],AL
	;DEC SI
	;INC DI
	;DEC CX
	;JNZ L3

	;MOV AL,[SI]
	;MOV [DI],AL
	;INC DI
	;MOV DL,"$"
	;MOV [DI],DL
	;MOV AH,02H				;newline
	;MOV DL,0AH				;newline
	;INT 21H					;service number
	;MOV AH,09H
	;LEA DX,STR2+2
	;INT 21H
	;---------------------------------------------------------------------------------<<<
	
	;concat >>>-------------------------------------------------------------------------
	;MOV CL,0
	;MOV CL,BYTE PTR[STRLEN1]
	;LEA SI,STR1+2
	;LEA DI,STR2+2
	;ADD DI,7
	;INC DI

	;L5:
	;CMP CL,0
	;JE L8
	;MOV DL,BYTE PTR[SI]
	;MOV BYTE PTR[DI],DL
	;INC SI
	;INC DI
	;DEC CL
	;JNZ L5

	;L8:
	;INC DI
	;MOV DL,"$"
	;MOV [DI],DL
	;MOV AH,02H
	;MOV DL,0AH
	;INT 21H
	;MOV AH,09H
	;LEA DX,STR2+2
	;INT 21H
	;--------------------------------------------------------------------------------<<<
		
	;compare >>>------------------------------------------------------------------------
	MOV CX,0
	LEA SI,STR1+2
	LEA DI,STR2+2
	MOV CX,WORD PTR[STRLEN1]
	MOV CH,0

	L11:
	CMP CX,0
	JE L9
	MOV DL,[SI]
	CMP [DI],DL
	JNE L10
	INC SI
	INC DI
	DEC CX
	JMP L11
	
	;CMP CX,0
	;JE L9
	;JNE L10

	L9:
	MOV AH,09H
	LEA DX,EQUAL
	INT 21H
	JMP OUTOFCOMPARE

	L10:
	MOV AH,09H
	LEA DX,NOTEQUAL
	INT 21H
	OUTOFCOMPARE:
	;--------------------------------------------------------------------------------<<<
	MOV AH,04CH				;terminate program
	INT 21H					;service numbers
END