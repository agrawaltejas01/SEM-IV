;----------------------------------------------------------------------------
;ATHARVA MAHAJAN
;2034
;STRING OPERATIONS IN ASSEMBLY LAUNGUAGE PROGRAMMING
;PROCEDURES IN FILE 2
;FILE1 LINKED TO FILE2
;----------------------------------------------------------------------------

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
	STR1 DB 32 DUP('$')
	STR2 DB 32 DUP('$')
	STR3 DB 32 DUP('$')
	GETSTRING1 DB "1ST STRING : $"
	GETSTRING2 DB "2ND STRING : $"
	MENU DB "SELECT : $"
	OPTION1 DB "1 >>> GET STRINGS$"
	OPTION2 DB "2 >>> COMPARE STRINGS$"
	OPTION3 DB "3 >>> CONCATINATE STRINGS$"
	OPTION4 DB "4 >>> EXIT$" 
	STRLEN1 DB ?
	STRLEN2 DB ?
.CODE
	MOV AX,@DATA
	MOV DS,AX
	
	MAINMENU:				;show available options to user
	LINEFEED
	OUTSTREAM MENU
	LINEFEED
	OUTSTREAM OPTION1
	LINEFEED
	OUTSTREAM OPTION2
	LINEFEED
	OUTSTREAM OPTION3
	LINEFEED
	OUTSTREAM OPTION4

	MOV AH,01H				;get choice from user
	INT 21H

	CMP AL,'1'
	JE OPT1					;option 1

	CMP AL,'2'
	JE OPT2					;option 2

	CMP AL,'3'
	JE OPT3					;option 3

	CMP AL,'4'
	JE EXIT					;exit program

	OPT1:
	CALL STRINGIO
	JMP MAINMENU	

	OPT2:
	JMP COMPARISION

	OPT3:
	JMP CONCATINATION	


;STRING I/O
;----------------------------------------------------------------------------
	STRINGIO PROC NEAR
	LINEFEED				;newline
	OUTSTREAM GETSTRING1
	INSTREAM STR1				;get str2
	LINEFEED				;newline
	OUTSTREAM GETSTRING2
	INSTREAM STR2				;get str2
	LINEFEED
	RET
	STRINGIO ENDP
;----------------------------------------------------------------------------

;STRING COMPARE
;-----------------------------------------------------------------------------
	COMPARISION:
	LINEFEED
	MOV CX,0
	LEA SI,STR1+1				;load adress of str1 in SI
	LEA DI,STR2+2				;load adress of str 2in DI
	MOV CL,BYTE PTR[SI]
	INC SI			
	MOV CH,0
	EXTRN STRINGCOMPARE:FAR			
	CALL STRINGCOMPARE			;external procedure call
	LINEFEED
	JMP MAINMENU
;-----------------------------------------------------------------------------

;STRING CONCAT
;-----------------------------------------------------------------------------
	CONCATINATION:
	LINEFEED
	LEA DI,STR3+2				;load str3 in DI
	LEA SI,STR1+2				;load str1 in SI
	LEA BX,STR2+2
	EXTRN STRCAT:FAR			
	CALL STRCAT				;call external procedure

	MOV AH,09H
	LEA DX,STR3+2
	INT 21H
	LINEFEED
	JMP MAINMENU
;-----------------------------------------------------------------------------

;END PROGRAM
;-----------------------------------------------------------------------------
	EXIT:
	MOV AH,04CH
	INT 21H
END