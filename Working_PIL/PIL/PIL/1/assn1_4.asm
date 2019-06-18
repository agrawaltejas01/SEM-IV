	.model 	small 					; selection of standard memory model for ALP

	.stack 						; initialize stack segment

	.data 						; initialize data segment

array 	db 	01,02,03,04,05,06,07,08,09,0ah 		; accept an array

msg 	db 	10,13,' RESULT OF ARRAY ADDITION IS: $'

ms1 	db 	10,13,'Array elements are:$'

	.code 						; beginning of program code


	mov 	ax,@data 				; initialize data section

	mov 	ds,ax 					; assign data to data segment

	lea 	dx,ms1

	mov 	ah,09h

	int 	21h

	mov 	ax,0000h

	mov 	dh,0ah

	lea 	si,array

a12: 	mov 	al,[si]

	mov 	bl,al 					; move contents of ax to bx

	mov 	ch,02h 					; no.of digits to be displayed

	mov 	cl,04h 					; count to roll by 4 bits

a11: 	rol 	bl,cl 					; rotate left bx through cl no. of bits

	mov 	dl,bl 					; move contents of bl to dl

	and 	dl,0fh 					; get LSB

	cmp 	dl,09h 					; check if digit 0-9 or letter A-F

	jbe 	ad300 					; jump if below or equal

	add 	dl,07h 					; add 37/07h if letter A-F

ad300:	add 	dl,30h 					; add 30h if digit 0-9

	mov 	ah,02h 					; outputs a single character to monitor

	int 	21h

	dec 	ch 					; decrement counter

	jnz 	a11 					; jump if not zero to a1

	mov 	ah,02h

	mov 	dl,' '

	int 	21h

	inc 	si

	dec 	dh

	jnz 	a12



	lea 	dx,msg

	mov 	ah,09h

	int 	21h

	mov 	ax,0000h 				; set ah=0



	lea 	si,array 				; load effective address of array in si

	mov 	dl,0Ah 					; initialize counter

up: 	add 	al,[si] 				; add al and contents of si

	inc 	si 					; increment si

	dec 	dl 					; decrement counter

	jnz 	up 					; jump if not zero to up

	mov 	bl,al 					; move contents of ax to bx

	mov 	ch,02h 					; no.of digits to be displayed
	mov 	cl,04h 					; count to roll by 4 bits

a1: 	rol 	bl,cl 					; rotate left bx through cl no. of bits

	mov 	dl,bl 					; move contents of bl to dl

	and 	dl,0fh 					; get LSB

	cmp 	dl,09h 					; check if digit 0-9 or letter A-F

	jbe 	ad30 					; jump if below or equal

	add 	dl,07h 					; add 37/07h if letter A-F

ad30:	add 	dl,30h 					; add 30h if digit 0-9

	mov 	ah,02h 					; outputs a single character to monitor

	int 	21h

	dec 	ch 					; decrement counter

	jnz 	a1 					; jump if not zero to a1

	mov 	ah,4ch 					; normal termination to DOS

	int 	21h 					; normal program termination

	end 						; end of program
