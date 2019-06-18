;Atharva Mahajan
;roll no. 2034
;f10

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

.model small
.stack
.data
	string db "HELLO",'$'
	STR1 DB 32 DUP("$")
	STR2 DB 32 DUP("$")
	STR3 DB 32 DUP("$")
	MENU DB "1.Enter string | 2.Find Length | 3.Display Reverse | 4. Check if Palindrome | 5.Compare | 6.Exit : $"
	CHOICE DB ?
	GETSTRING DB "Enter your string : $"
	GETSTRING2 DB "Enter second string : $"
	LENGTHOFSTRING DB "Length of your string is : $"
	REVERSEOFSTRING DB "Reverse string of your string is : $"
	EQUAL DB "Identical strings$"
	NOTEQUAL DB "Different strings$"
	PNP DB "Is string palindrome ? : $"
	PALINDROME DB "String is a palindrome$"
	NOTPALINDROME DB "String is not a palidrome$"	
	STRLEN1 DB ?
	STRLEN2 DB ?
	STRLEN3 DB ?
.code
	MOV AX,@DATA
	MOV DS,AX
	
;menu >>>
;-------------------------------------------------------------------------------------
MAINMENU:	
	OUTSTREAM MENU
	LINEFEED
	MOV AH,01H				;get character
	INT 21H					;service number
	CMP AL,'1'				;get string
	JE CHOICE1
	CMP AL,'2'				;display length
	JE CHOICE2
	CMP AL,'3'				;display reverse of string
	JE CHOICE3
	CMP AL,'4'				;check if palindrome
	JE CHOICE4
	CMP AL,'5'				;compare with other string
	JE CHOICE5
	CMP AL,'6'
	JE CHOICE6				;exit

	CHOICE1: 
	CALL STRINGIO				;call procedure stringio
	JMP MAINMENU

	CHOICE2:
	CALL STRINGLENGTH			;call perocedure stringlength
	JMP MAINMENU
	
	CHOICE3:
	CALL STRINGREVERSE			;call procedure stringreverse
	JMP MAINMENU
	
	CHOICE4:					
	CALL ISPALINDROME			;call perocedure ispalindrome
	JMP MAINMENU
	
	CHOICE5:
	CALL STRINGCOMPARE			;call peroecdure stringcompare
	JMP MAINMENU
	
	CHOICE6: JMP EXIT
;-------------------------------------------------------------------------------------

;string i/o >>>
STRINGIO PROC NEAR
;-------------------------------------------------------------------------------------
	OUTSTREAM GETSTRING			;print string
	INSTREAM STR1				;getstring
	LINEFEED				;newline
	RET					;return control
;-------------------------------------------------------------------------------------	
ENDP


;string length >>>
STRINGLENGTH PROC NEAR
;-------------------------------------------------------------------------------------
	LEA SI,STR1				;load adress of str1 in SI
	ADD SI,1				;add 1 to SI
	MOV CX,0000				;initialize CX to 0
	MOV CL,BYTE PTR[SI]				
	MOV BYTE PTR[STRLEN1], CL
	ADD CL,30H				;CL + ascii 30h gives required number 
	LINEFEED
	OUTSTREAM LENGTHOFSTRING
	MOV AH,02H				;print length
	MOV DL,CL
	INT 21H
	LINEFEED
	RET					;return control
;-------------------------------------------------------------------------------------
ENDP


;string reverse >>>
STRINGREVERSE PROC NEAR
;-------------------------------------------------------------------------------------
	MOV CL,BYTE PTR[STRLEN1]		;load string length in CL
	MOV CH,0
	LEA SI,STR1+2				;load address of str1 in SI
	ADD SI,CX				;take SI to end of str1
	LEA DI,STR3+2				;load adress of str3 in di			
	
	L3:
	MOV AL,[SI]				;get char from [SI]
	MOV [DI],AL				;move it in [DI]
	DEC SI					;decrement SI
	INC DI					;increment DI
	DEC CX					;decrement CX
	JNZ L3					;loop

	MOV AL,[SI]
	MOV [DI],AL
	INC DI
	MOV DL,"$"				;add terminating character to str2
	MOV [DI],DL
	LINEFEED
	OUTSTREAM REVERSEOFSTRING		;print reverse of string
	LINEFEED
	MOV AH,09H
	LEA DX,STR3+2
	INT 21H
	LINEFEED
	RET					;return control
;-------------------------------------------------------------------------------------
ENDP


;concat >>>
;-------------------------------------------------------------------------------------
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
;-------------------------------------------------------------------------------------
	
;palindrome
ISPALINDROME PROC NEAR
;-------------------------------------------------------------------------------------
	MOV CX,0				;initialize CX with 0
	MOV CL,BYTE PTR[STRLEN1]		;load string length in CX
	MOV CH,0	
	LEA SI,STR1+2				;load adress of string 1 in SI
	LEA DI,STR1+2				;load adress of string 1 in DI
	ADD DI,CX				;take DI to end of str1
	DEC DI

	MOV AX,CX					
	MOV CL,2
	DIV CL						;CL = CL/2
	MOV CL,AL
	MOV CH,0

	CHKP:
	MOV DL,BYTE PTR[SI]			;compare str[stringlength-CX] and str[CX]
	MOV DH,BYTE PTR[DI]
	CMP DH,DL
	JNE NOTP				;break loop if not equal
	INC SI
	DEC DI
	DEC CX
	JNZ CHKP				;loop
		
	LINEFEED
	OUTSTREAM PNP
	LINEFEED
	MOV AH,09H				;is palindrome
	LEA DX,PALINDROME
	INT 21H
	LINEFEED
	JMP ISP

	NOTP:
	LINEFEED				;is not palindrome
	OUTSTREAM PNP
	LINEFEED
	MOV AH,09H
	LEA DX,NOTPALINDROME
	INT 21H	
	LINEFEED
RET	

	ISP:RET					;return
;-------------------------------------------------------------------------------------
ENDP


;compare >>>
STRINGCOMPARE PROC NEAR
;-------------------------------------------------------------------------------------
	LINEFEED				;newline
	OUTSTREAM GETSTRING2
	INSTREAM STR2				;get str2
	LINEFEED
	MOV CX,0
	LEA SI,STR1+2				;load adress of str1 in SI
	LEA DI,STR2+2				;load adress of str 2in DI
	MOV CL,BYTE PTR[STRLEN1]			
	MOV CH,0

	L11:
	CMP CL,0
	JE L9
	MOV DL,BYTE PTR[SI]
	MOV DH,BYTE PTR[DI]
	CMP DH,DL				;compare str1[CX] and str2[CX]
	JNE L10					;jump if not same
	INC SI
	INC DI
	DEC CL
	JMP L11					;loop
	
	L9:
	MOV AH,09H
	LEA DX,EQUAL				;equal strings
	INT 21H
	LINEFEED
	JMP OUTOFCOMPARE

	L10:
	MOV AH,09H
	LEA DX,NOTEQUAL				;unequal strings
	INT 21H
	LINEFEED
	RET	
	
	OUTOFCOMPARE:
	RET					;return control
;-------------------------------------------------------------------------------------
ENDP
	EXIT:
	MOV AH,04CH				;terminate program
	INT 21H					;service numbers
END