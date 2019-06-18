INSTREAM MACRO STRNG
	MOV AH,0AH					;buffered keyboard input
	LEA DX,STRNG					;load effective address of str into DX
	INT 21H						;service number
ENDM

OUTSTREAM MACRO STRNG
	MOV AH,09H					;string pri
	LEA DX,STRNG
	INT 21H
ENDM

LINEFEED MACRO 
	MOV AH,02H
	MOV DL,0AH
	INT 21H
ENDM

CMPSTR MACRO S2, S1
	MOV CX,0
	LEA SI,S1+2
	LEA DI,S2+2
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
ENDM

GETREV MACRO S2,S1,SL1
	MOV CX,WORD PTR[SL1]
	LEA SI,S1+2
	ADD SI,WORD PTR[SL1]
	LEA DI,S2+2
	
	L3:
	MOV AL,[SI]
	MOV [DI],AL
	DEC SI
	INC DI
	DEC CX
	JNZ L3

	MOV AL,[SI]
	MOV [DI],AL
	INC DI
	MOV DL,"$"
	MOV [DI],DL
	MOV AH,02H				;newline
	MOV DL,0AH				;newline
	INT 21H					;service number
	MOV AH,09H
	LEA DX,STR2+2
	INT 21H
ENDM

;i/p o/p - done
;STRLEN - done
;reverse - done
;concat - NOT DONE
;compare - done
.model small
.stack
.data
	string db "HELLO",'$'
	STR1 DB 32 DUP("$")
	STR2 DB 32 DUP("$")
	STR3 DB 32 DUP("$")
	DOLLER DB 0H
	EQUAL DB "EQUAL$"
	NOTEQUAL DB "NOTEQUAL$"
	STRLEN1 DB ?
	STRLEN2 DB ?
.code
	MOV AX,@DATA
	MOV DS,AX
	
;string i/o >>>
;_____________________________________________________________________________________
	INSTREAM STR1	
	LINEFEED
	;INSTREAM STR2
	;LINEFEED
;_____________________________________________________________________________________	


;string length >>>
;_____________________________________________________________________________________

	; STRING 1 ==========================================================================
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


	; STRING 2 ==========================================================================
	MOV SI,0
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
;___________________________________________________________________________________<<<


;string reverse >>>
;_____________________________________________________________________________________
	
	MOV CX,WORD PTR[STRLEN1]
	LEA SI,STR1+2
	ADD SI,WORD PTR[STRLEN1]
	LEA DI,STR3+2
	
	L3:
	MOV AL,[SI]
	MOV [DI],AL
	DEC SI
	INC DI
	DEC CX
	JNZ L3

	MOV AL,[SI]
	MOV [DI],AL
	INC DI
	MOV DL,"$"
	MOV [DI],DL
	MOV AH,02H				;newline
	MOV DL,0AH				;newline
	INT 21H					;service number
	MOV AH,09H
	LEA DX,STR3+2
	INT 21H
;_____________________________________________________________________________________
	

;concat >>>
;_____________________________________________________________________________________
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
;_______________________________________________________________________________________
	
	

;compare >>>
;_______________________________________________________________________________________
	LINEFEED
	INSTREAM STR2
	LINEFEED
	CMPSTR STR2,STR1
;_______________________________________________________________________________________

	MOV AH,04CH				;terminate program
	INT 21H					;service numbers
END