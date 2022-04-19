section .text
	global ft_strcpy

ft_strcpy:
	xor rax, rax ; initialisation du return
	xor rcx, rcx ; initialisation du compteur
	cmp rsi, 0 ; comparaison de rsi à 0 byte
	jz return ; si la comparaision est vrai, appel la fonction return

while:
	mov dl, [rsi + rcx] ; déplace rsi[i] dans un tmp
	mov [rdi + rcx], dl ; déplace le tmp dans rdi[i]
	cmp dl, 0 ; comparaison de tmp à 0 byte
	jz return ; si la compraraison est vrai, appel la fonction exit
	inc rcx ; sinon on incrémente le compteur
	jmp while ; appel la fonction while

return:
	mov rax, rdi ; déplace rdi dans le registre de sortie
	ret ; return rax
