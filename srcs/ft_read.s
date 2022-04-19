section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rax, 0 ; initialisation de rax à 0 qui est le syscall de read sur linux
	syscall ; appel system pour read (0)
	cmp rax, 0 ; comparaison de rax à 0
	jl error ; si inférieur, appel la fonction error
	ret ; sinon return rax

error:
	neg rax ;rend rax positif
	mov rdi, rax ; déplace rax dans rdi
	call __errno_location wrt ..plt ; appel la fonction errno_location
	mov [rax], rdi ; déplace rdi (return du syscall par rax) dans le pointeur sur rax (return de error_location)
	mov rax, -1 ; met rax à -1
	ret ; return rax
