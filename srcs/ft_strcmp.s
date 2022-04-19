section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax ; initialisation du return
	xor rcx, rcx ; initialisation du compteur

while:
	mov al, [rdi] ; déplace rdi[i] dans al
	mov cl, [rsi] ; déplace rsi[i] dans cl
	cmp al, cl ; compare al et cl
	jne comp ; si ils sont différent, appel la fonction comp
	cmp al, 0 ; compare al à 0
	je return ; si oui, appel la fonction return
	cmp cl, 0 ; compare cl à 0
	je return ; si oui, appel la fonction return
	inc rdi ; sinon incrémente rdi
	inc rsi ; incrémente rsi
	jmp while ; appel la fonction while


comp:
	sub rax, rcx ; soustraction rcx de rax
	ret ; return rax

return:
	ret ; return rax
