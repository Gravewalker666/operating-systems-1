bits 16
org 0x7c00

mov ah, 0x0e

mov bx, boot_string
call print_string
mov bx, boot_string_sub
call print_string

print_string:
	mov al, [bx]
	cmp al, 0
	je end
	int 0x10
	add bx, 1
	jmp print_string

boot_string: 
	db 'GraveLoader!!!', 0xA, 0xD, 0 
	
boot_string_sub:
	db 'by Gravewalker666', 0

end: ret

times 510 - ($ - $$) db 0
dw 0xAA55

