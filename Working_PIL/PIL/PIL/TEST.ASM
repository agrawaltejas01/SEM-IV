.MODEL SMALL                            ;model
.STACK                                  ;stack segment
.DATA                                   ;data segment
        STRING1 DB 16 DUP('$')
        STRING2 DB 16 DUP("$")
        MESSAGE DB "YOUR STRING IS : $"
.CODE                                   ;code segment
        MOV AX,@DATA                    ;mov address of data segment
        MOV DS,AX                           
                
        MOV AH,0AH
        LEA DX,STRING1
        INT 21H

        MOV AH,09H
        LEA DX,MESSAGE
        INT 21H

        MOV AH,09H
        LEA DX,STRING1+1
        INT 21H

        MOV AH,04CH                     ;end program
        INT 21H                         ;inturrept service
END
