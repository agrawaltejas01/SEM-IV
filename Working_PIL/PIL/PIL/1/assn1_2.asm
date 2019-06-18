	.model 	small 					; selection of standard memory model for ALP

	.stack 						; initialize stack segment

	.data 						; initialize data segment

array 	db 	01,02,03,04,05,06,07,08,09,0ah 		; accept an array

count 	db 	0ah 					; initialze counter

R 	dw 	? 					; store the result in R

	.code 						; beginning of program code

	

	mov 	ax,@data 				; initialize data section

	mov 	ds,ax 					; assign data to data segment

	mov 	ax,0000h 				; set ax=0000h

	cld 						; to clear direction flag

	lea 	si,array 				; load effective address of array in si

	mov 	cl,count 				; initialize counter to 0ah

up: 	add 	al,[si] 				; add al and contents of si

	inc 	si 					; increment si

	dec 	cl 					; decrement counter

	jnz 	up 					; jump if not zero to up

	mov 	R,ax 					; move result into R

	mov 	ah,4ch 					; normal termination to DOS

	int 	21h 					; normal program termination

	end 						; end of program