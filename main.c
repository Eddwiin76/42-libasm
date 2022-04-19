/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:00:36 by tpierre           #+#    #+#             */
/*   Updated: 2020/10/23 16:23:15 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_exit(char *str)
{
	printf("\033[31m%s\033[0m\n", str);
	exit (0);
}

void	ft_good(int nb)
{
	if (nb == 0)
		printf("\033[31m[FAIL] \033[0m");
	if (nb == 1)
		printf("\033[32m[OK] \033[0m");
	if (nb == 2)
		printf("\n");
}

void	ft_strlen_test(char *str)
{
	strlen(str) == ft_strlen(str) ? ft_good(1) : ft_good(0);
}

void	ft_strcpy_test(char *dst1, char *dst2, char *src)
{
	strcpy(dst1, src);
	ft_strcpy(dst2, src);
	strcmp(dst1, dst2) == 0 ? ft_good(1) : ft_good(0);
}

void	ft_strcmp_test(char *dst1, char *dst2, char *src)
{
	strcmp(dst1, src) == ft_strcmp(dst2, src) ? ft_good(1) : ft_good(0);
}

void	ft_strdup_test(char *str)
{
	char *tmp = strdup(str);
	char *tmp_ft = ft_strdup(str);
	strcmp(tmp, tmp_ft) == 0 ? ft_good(1) : ft_good(0);
	free(tmp);
	free(tmp_ft);
}

void	ft_read_test(int size, size_t count)
{
	int		fd1 = 1;
	int		fd2 = 1;
	char	buf1[size];
	char	buf2[size];
	ssize_t	result1;
	ssize_t	result2;

	if ((fd1 = open("test_fonction.txt", O_RDONLY)) == -1)
		ft_exit("Open failed on ft_read_test");
	if ((fd2 = open("test_fonction.txt", O_RDONLY)) == -1)
		ft_exit("Open failed on ft_read_test");
	while ((result1 = ft_read(fd1, buf1, count)) > 0)
		buf1[result1] = '\0';
	while ((result2 = read(fd2, buf2, count)) > 0)
		buf2[result2] = '\0';
	strcmp(buf1, buf2) == 0  ? ft_good(1) : ft_good(0);
	close(fd1);
	close(fd2);
}

void	ft_write_test(char *buf, int size, size_t count)
{
	int		fd1;
	int		fd2;
	char	buf1[size];
	char	buf2[size];
	ssize_t	result1;
	ssize_t	result2;

	if ((fd1 = open("test_fonction2.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == -1)
		ft_exit("Open failed on ft_write_test");
	if ((fd2 = open("test_fonction3.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)) == -1)
		ft_exit("Open failed on ft_write_test");
	ft_write(fd1, buf, count);
	write(fd2, buf, count);
	close(fd1);
	close(fd2);
	if ((fd1 = open("test_fonction2.txt", O_RDONLY)) == -1)
		ft_exit("Open failed on ft_write_test");
	if ((fd2 = open("test_fonction3.txt", O_RDONLY)) == -1)
		ft_exit("Open failed on ft_write_test");
	while ((result1 = read(fd1, buf1, count)) > 0)
		buf1[result1] = '\0';
	while ((result2 = read(fd2, buf2, count)) > 0)
		buf2[result2] = '\0';
	strcmp(buf1, buf2) == 0  ? ft_good(1) : ft_good(0);
	close(fd1);
	close(fd2);
}

int		main()
{
	printf("FT_STRLEN : ");

	ft_strlen_test("zef4ezf4zefzef4");
	ft_strlen_test("994846");
	ft_strlen_test("{#~|[#~#{}]}");
	ft_strlen_test("234fzz#~{#{~#()");
	ft_strlen_test("");
	ft_strlen_test("bon");
	ft_strlen_test("bonjour");
	ft_strlen_test("asdfasdf''///##!!@");
	ft_strlen_test("the\0hidden");
	ft_strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.");
	ft_good(2);

	printf("FT_STRCPY : ");

	char s1[1000];
	char s2[1000];
	ft_strcpy_test(s1, s2, "zef4ezf4zefzef4");
	ft_strcpy_test(s1, s2, "994846");
	ft_strcpy_test(s1, s2, "{#~|[#~#{}]}");
	ft_strcpy_test(s1, s2, "234fzz#~{#{~#()");
	ft_strcpy_test(s1, s2, "");
	ft_strcpy_test(s1, s2, "bon");
	ft_strcpy_test(s1, s2, "bonjour");
	ft_strcpy_test(s1, s2, "asdfasdf''///##!!@");
	ft_strcpy_test(s1, s2, "the\0hidden");
	ft_strcpy_test(s1, s2, "Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.");
	ft_good(2);

	printf("FT_STRCMP : ");

	ft_strcmp_test("zef4ezf4zefzef4", "zef4ezf4zefzef4", "zef4ezf4zefzef4");
	ft_strcmp_test("994846", "994846", "994846");
	ft_strcmp_test("{#~|[#~#{}]}", "{#~|[#~#{}]}", "{#~|[#~#{}]}");
	ft_strcmp_test("234fzz#~{#{~#()", "234fzz#~{#{~#()", "234fzz#~{#{~#()");
	ft_strcmp_test("", "", "");
	ft_strcmp_test("bon", "bon", "bon");
	ft_strcmp_test("bonjour", "bonjour", "bonjour");
	ft_strcmp_test("asdfasdf''///##!!@", "asdfasdf''///##!!@", "asdfasdf''///##!!@");
	ft_strcmp_test("the\0hidden", "the\0hidden", "the\0hidden");
	ft_strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.", "Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.", "Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.");
	ft_good(2);

	printf("FT_READ   : ");

	ft_read_test(2048, 2);
	ft_read_test(2048, 5);
	ft_read_test(2048, 50);
	ft_read_test(2048, 500);
	ft_read_test(2048, 1000);
	ft_read_test(2048, 2047);
	ft_good(2);

	printf("FT_WRITE  : ");

	ft_write_test("zef4ezf4zefzef4", 2048, 1 + strlen("zef4ezf4zefzef4"));
	ft_write_test("994846", 2048, 1 + strlen("994846"));
	ft_write_test("{#~|[#~#{}]}", 2048, 1 + strlen("{#~|[#~#{}]}"));
	ft_write_test("234fzz#~{#{~#()", 2048, 1 + strlen("234fzz#~{#{~#()"));
	ft_write_test("", 2048, 1 + strlen(""));
	ft_write_test("bon", 2048, 1 + strlen("bon"));
	ft_write_test("bonjour", 2048, 1 + strlen("bonjour"));
	ft_write_test("asdfasdf''///##!!@", 2048, 1 + strlen("asdfasdf''///##!!@"));
	ft_write_test("the\0hidden", 2048, 1 + strlen("the\0hidden"));
	ft_write_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.", 2048, 1 + strlen("Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet."));
	ft_good(2);

	printf("FT_STRDUP : ");

	ft_strdup_test("zef4ezf4zefzef4");
	ft_strdup_test("994846");
	ft_strdup_test("{#~|[#~#{}]}");
	ft_strdup_test("234fzz#~{#{~#()");
	ft_strdup_test("");
	ft_strdup_test("bon");
	ft_strdup_test("bonjour");
	ft_strdup_test("asdfasdf''///##!!@");
	ft_strdup_test("the\0hidden");
	ft_strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
		elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
		bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
		volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
		felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
		ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
		tortor, sit amet consequat amet.");
	ft_good(2);

	return (0);
}
