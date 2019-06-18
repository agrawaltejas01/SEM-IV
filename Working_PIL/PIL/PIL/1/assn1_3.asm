	.model 	small 			; selection of standard memory model for ALP

	.stack 				; initialize stack segment

	.data 				; initialize data segment

array 	db 	99,92,94,95 		; accept an array

ms1 	db 	10,13,09,'Array elements are:$'
	
	.code 				; beginning of program code


	mov 	ax,@data 		; initialize data section

	mov 	ds,ax 			; assign data to data segment

	lea 	dx,ms1

	mov 	ah,09h

	int 	21h

	mov 	ax,0000h

	mov 	dh,04h

	lea 	si,array

a12: 	mov 	al,[si]

	mov 	bl,al 			; move contents of ax to bx

	mov 	ch,02h 			; no.of digits to be displayed

	mov 	cl,04h 			; count to roll by 4 bits

a11: 	rol 	bl,cl 			; rotate left bx through cl no. of bits

	mov 	dl,bl 			; move contents of bl to dl

	and 	dl,0fh 			; get LSB

	cmp 	dl,09h 			; check if digit 0-9 or letter A-F

	jbe 	ad300 			; jump if below or equal

	add 	dl,07h 			; add 37/07h if letter A-F

ad300:	add 	dl,30h 			; add 30h if digit 0-9

	mov 	ah,02h 			; outputs a single character to monitor

	int 	21h

	dec 	ch 			; decrement counter

	jnz 	a11 			; jump if not zero to a1

	mov 	ah,02h

	mov 	dl,' '

	int 	21h

	inc 	si

	dec 	dh

	jnz 	a12

	mov 	ah,4ch 			; normal termination to DOS

	int 	21h 			; normal program termination

	end 				; end of program