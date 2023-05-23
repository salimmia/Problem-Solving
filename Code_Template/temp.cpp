.model small
.stack 100h


.data
val db ?
val2 db ?
div_ans db ?
newline db 10, 13, '$'


.code

main proc
    mov ax, @data
    mov ds, ax

    mov ah, 1   ; for taking single char input
    int 21h     ; interupt calling for execution of the command

    mov bl, al  ; defult : input will save in al



    mov ah, 1
    int 21h

    mov cl, al


    ;output taken values

    mov ah, 2
    mov dl, bl
    int 21h

    mov ah, 2
    mov dl, cl
    int 21h



    sub bl, '0'
    mov val, bl



    sub cl, '0'
    mov val2, cl




    mov al, val;
    mul val2

    mov div_ans, al
    add div_ans, '0'
    mov ah, 2
    mov dl, div_ans
    int 21h
