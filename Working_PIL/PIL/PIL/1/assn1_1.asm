	.model small 

	.stack

	.data

n1 	db 	36H

n2 	db 	27H

sum 	db 	? 	; (instead of ? we write 00H)

	.code

	mov 	ax,@data

	mov 	ds,ax
	
	mov 	al, n1

	mov 	bl, n2

	add 	al, bl

	daa

	mov 	sum, al

	mov 	ah, 4ch

	int 	21H

	end