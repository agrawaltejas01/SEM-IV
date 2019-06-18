INSTREAM MACRO STRNG
	MOV AH,0AH				;buffered keyboard input
	LEA DX,STRNG				;load effective address of str into DX
	INT 21H					;service number
ENDM

OUTSTREAM MACRO STRNG
	MOV AH,09H				;string print
	LEA DX,STRNG
	INT 21H
ENDM

LINEFEED MACRO 
	MOV AH,02H				;newline print
	MOV DL,0AH
	INT 21H
ENDM

.MODEL SMALL
.STACK
.DATA
	EQUAL DB "EQUAL$"
	NOTEQUAL DB "NOTEQUAL$"
.CODE
	MOV AX,@DATA
	MOV DS,AX


STRINGCOMPARE PROC FAR
PUBLIC STRINGCOMPARE
;-------------------------------------------------------------------------------------
	LSCM:
	CMP CL,0
	JE SCJ1
	MOV DL,BYTE PTR[SI]
	MOV DH,BYTE PTR[DI]
	CMP DH,DL				;compare str1[CX] and str2[CX]
	JNE SCJ2				;jump if not same
	INC SI
	INC DI
	DEC CL
	JMP LSCM				;loop
	
	SCJ1:
	MOV AH,09H
	LEA DX,EQUAL				;equal strings
	INT 21H
	LINEFEED
	JMP OUTOFCOMPARE

	SCJ2:
	MOV AH,09H
	LEA DX,NOTEQUAL				;unequal strings
	INT 21H
	LINEFEED
	RET	
	
	OUTOFCOMPARE:
	RET					;return control
;-------------------------------------------------------------------------------------
STRINGCOMPARE ENDP

STRCAT PROC FAR
PUBLIC STRCAT
;-------------------------------------------------------------------------------------
	SCATML1:
	CMP BYTE PTR[SI],"$"			;compare [SI] with char "$"
	JE SCATSL1				;if [SI] = $ then jump
	MOV DL,[SI]				;copy string 1 into string 2 char
	MOV [DI],DL				;by char		 
	INC DI
	INC SI
	JNE SCATML1
	
	SCATSL1:				;mov address stored in BX into SI
	LEA SI,[BX]
	DEC DI				

	SCATML2:
	CMP BYTE PTR[SI],"$"
	JE SCATSL2
	MOV DL,[SI]				;attach string 2 to end of string1
	MOV [DI],DL				;character by character
	INC DI
	INC SI
	JNE SCATML2

	SCATSL2:
	INC DI
	MOV DL,"$"				;append string terminator
	MOV BYTE PTR[DI], DL		
	LINEFEED
	RET
;-------------------------------------------------------------------------------------
STRCAT ENDP

END
	