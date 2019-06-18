disp macro msg
 MOV AH,09H
 LEA DX,MAG
 INT 21H
ENDM

.model small
.data
ml DB 10,13,"The array is $"
arr DB 20H,10H,1H,2H,12H
m2 DB 10,13 ,"the sum of the array elements is : $"

.code
    MOV AX,@data
    MOV DS,AX
    MOV,BH,5
    LEA SI,arr

    disp ml
    DISP1:
		MOV AL,[SI]
		MOV BL,AL
		MOV CH 02H
		MOV CL,04H

		DISP2:
			ROL BL,CL
			MOV DL,BL
			AND DL,OFH
			CMP DL,09H
			JBE AD30
			ADD DL,07H

		AD30:
			ADD DL 30H

			MOV AH,02H 
			INT 21H 
			DEC CH
			JNZ DISP2
		MOV AH 02H
		MOV DL
		INT 21H
		INC SI
		DEC BH
		JNZ DISP1

    disp m2
	ADD1:
		MOV BX,0000H
		MOV CX,0000H
		MOV AX,0000H
		LEA SI,arr
		MOV BH,5

		ADD2:
			ADD AL,[SI]
			INC SI
			DEC BH
			JNZ ADD2

			MOV BL,AL
			MOV CL,04H
			MOV CH,02H

			ADD3:
				ROL BL,CL
				MOV DL,BL
				AND DL,0FH
				CMP DL,09H
				JBE AD_30
				ADD DL,07H
				AD_30:
					ADD DL,30H
				MOV AH,02H
				INT 21H
				DEC CH
				JNZ ADD3
	MOV AH,04CH
	INT 21H
END