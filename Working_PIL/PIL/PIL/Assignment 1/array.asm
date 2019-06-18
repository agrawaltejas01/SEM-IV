.model small
.stack
.data
    array db 0h,1h,4h,5h        ;declare array and initialize its cells as {0,1,3,5}
    sum db 0                    ;sum variable
.code                           ;start code
    STARTPOINT:                 ;define code start point
    mov ax,@data
    mov ds,ax
    
    mov cx,0                    ;initialize cx = 0
    mov ax,0                    ;initialize ax = 0
    mov bx,offset array         ;move array to register bx
    
    startloop:
    cmp cx,4                    ;compare with count of elements
    jge Endloop                 ;if cmp flag is set to zero then jump
    mov ax,[bx]                 ;move one element from bx to ax
    add sum,al                  ;add elements
    inc cx                      ;increment cx
    inc bx                      ;increment bx
    
    jmp startloop
    
    Endloop:        
    mov ah,02h                  ;display character command
    mov dl,sum                  ;display sum
    int 21h                     ;processor interupt
    
    mov al,[sum]
    mov ah,0
    mov dl,10
    div dl
    add ax,3030h
    mov dh,ah                    ;preserve ah
    mov dl,al
    mov ah,02h
    int 21h                      ;processor interupt
    mov dl,dh                    ;restore
    int 21h                      ;processor interupt
    
    mov ah,04ch                  ;terminate program
    int 21h                      ;processor interupt
    END STARTPOINT               ;code end point
end                              ;end code