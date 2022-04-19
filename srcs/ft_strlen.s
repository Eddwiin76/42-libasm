section .text
	global ft_strlen

ft_strlen:
	xor rax, rax ; initialisation du return
	xor rcx, rcx ; initialisation du compteur

while:
	cmp [rdi + rcx], byte 0 ; comparaison de rdi[i] à 0 byte
	jz return ; si la compraraison est vrai, appel la fonction return
	inc rcx ; incrémente le compteur
	jmp while ; appel la fonction while

return:
	mov rax, rcx ; déplace le compteur dans le registre de sortie
	ret ; return rax
