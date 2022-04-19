section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	xor rax, rax ; initialisation du return
	push rdi ; ajoute rdi (str) au sommet de la stack
	cmp rdi, 0 ; comparaison de str à 0
	jz return ; si oui, return rax
	call ft_strlen ; appel ft_strlen
	inc rax ; ajoute 1 au retour de ft_strlen pour le '\0'
	mov rdi, rax ; déplace la len dans l'argument envoyé à malloc (rdi)
	call malloc wrt ..plt ; malloc rax de la taille de rdi
	cmp rax, 0 ; compare le retour de malloc à 0
	jz return ; si oui, return rax
	pop rdi ; retire rdi (str) qui se trouve au sommet de la stack
	mov rsi, rdi ; déplace rdi (str) dans src (rsi)
	mov rdi, rax ; déplace le retour de malloc (rax) dans rdi (dst)
	call ft_strcpy ; appel ft_strcpy avec rdi et rsi en paramètre (dst et src)
	ret ; return rax

return:
	mov rax, 0
	pop rdi ; retire rdi (str) qui se trouve au sommet de la stack
	ret ; return rax
