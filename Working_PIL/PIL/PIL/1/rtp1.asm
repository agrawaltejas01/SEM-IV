.model small
.386p
.code

mov ax,0003h
int 10h

mov ax,cs
mov ds,ax

mov ah,09h
lea dx,cs:m1
int 21h

mov eax,0000
mov ebx,0000
mov ax,cs

shl eax,4
lea ebx,gdt
add eax,ebx
mov cs:BA,eax

lgdt cs:GDTR
cli
mov eax,cr0
or al,01h
mov cr0,eax
jmp pmode

pmode: mov ax,8
       mov ds,ax
       mov ah,7
       mov bx,200
       lea si,cs:m2
print:
       mov al,cs:[si]
       cmp al,0
       jz end_print
       mov ds:[bx],ax
       inc si
       add bx,2
       jmp print

end_print:mov eax,cr0
and al,0FEh
mov cr0,eax
jmp r_mode

r_mode: mov ax,cs
mov ds,ax

mov ah,09h
lea dx,cs:m3
int 21h

mov ah,4ch
int 21h
m1 db 10,13,"real mode$"
m2 db 10,13, "protected mode$",0
m3 db 10,13, "back in real mode$"

gdt  dq 0000H
     dw 0FFFFh
     dw 8000h
     dw 920Bh
     dw 0000h

gdtr label fword
lim dw 0Fh
BA  dd ?


end 

               
