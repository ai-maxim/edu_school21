#include "libasm.h"

	char *tmp = "test";
	char *empty = "";
	char dest[100];
	char *src = "pereday meny polnostuy";

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

// ======FT_STRLEN=========
void	check_strlen()
{
	printf("===== FT_STRLEN ====\n");
	// printf("%s\n", tmp);
	printf("or - %lu\n", strlen(tmp));
	printf("my - %zu\n", ft_strlen(tmp));

	char *a = "0";
	char *b = "\0";
	printf("\n111 orig - %lu\n", strlen(a));
	printf("\n111 my - %zu\n", ft_strlen(a));
	printf("\n111 orig - %lu\n", strlen(b));
	printf("\n111 my - %zu\n", ft_strlen(b));
}

// =====FT_STRCPY=========
void	check_strcpy()
{
	printf("===== FT_STRCPY =====\n");
	printf("\n");
	printf("or - %s\n", strcpy(dest, src));
	printf("my - %s\n", strcpy(dest, "\0"));
			printf("my - %s\n", strcpy(dest, "0"));
	dest[0] = 0;
	printf("my - %s\n", ft_strcpy(dest, src));
	printf("my - %s\n", ft_strcpy(dest, "\0"));
	printf("my - %s\n", ft_strcpy(dest, "0"));
	printf("\n");

}

void	check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";

	printf("====== FT_STRCMP ======\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-2s: \"%d\"\n", "or", strcmp(hello_world, hello_human));
	printf("%-2s: \"%d\"\n", "my", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-2s: \"%d\"\n", "or", strcmp(hello_world, hello_world2));
	printf("%-2s: \"%d\"\n", "my", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-2s: \"%d\"\n", "or", strcmp(hello_world2, empty));
	printf("%-2s: \"%d\"\n", "my", ft_strcmp(hello_world2, empty));
	printf("%-2s: \"%d\"\n", "or", strcmp(empty, hello_world2));
	printf("%-2s: \"%d\"\n", "my", ft_strcmp(empty, hello_world2));
	printf("\n");
}

void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("===== FT_WRITE =====\n");
	printf("%-2s: \"%s\"\n", "char *", hello_world);
	printf("%-2s: \"%zu\"", "or", write(1, hello_world, 7));
	printf("\n");
	printf("%-2s: \"%zu\"\n", "my", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-2s: \"%s\"\n", "char *", empty);
	printf("%-2s: \"%zu\"", "or", write(1, empty, 0));
	printf("\n");
	printf("%-2s: \"%zu\"\n", "my", ft_write(1, empty, 0));
	printf("\n");
	printf("%-2s: \"%s\"\n", "char *", hello_world);
	printf("%-2s: \"%zu\"", "or", write(-7, NULL, 7));
	printf("\n  errno - %d\n", errno);
	printf("\n");
	printf("%-2s: \"%zu\"\n", "my", ft_write(-7, NULL, 7));
	printf("\n");

}

// ===== FT_READ =====

void check_read()
{
	int fd = open("main.c", O_RDONLY);
	char buf[1001];
	int rax;
	char *str;

	str = (char *)malloc(10001);
	printf("Тестируем ft_read:\n\n");
	fd = open("Makefile", O_RDONLY);
	rax = read(fd, buf, 15);
	str[rax] = '\0';
	printf("read    Makefile %d - %s\n", rax, strncpy(str, buf, 15));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	rax = ft_read(fd, buf, 15);
	str[rax] = '\0';
	printf("ft_read Makefile %d - %s\n", rax, strncpy(str, buf, 15));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	rax = read(fd, buf, 5);
	str[rax] = '\0';
	printf("read    test.txt %d - %s\n", rax, strncpy(str, buf, 5));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	rax = ft_read(fd, buf, 5);
	str[rax] = '\0';
	printf("ft_read test.txt %d - %s\n", rax, strncpy(str, buf, 5));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	rax = read(fd, NULL, 5);
	printf("read    test.txt NULL buf read = %d ", rax);
	printf("\n                             errno %d\n", errno);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	rax = ft_read(fd, NULL, 5);
	printf("ft_read test.txt NULL buf ft_read = %d ", rax);
	printf("\n                             errno %d\n", errno);
	close(fd);
	rax = read(100, buf, 5);
	printf("read  fd = 100 read  = %d", rax);
	printf("\n                 errno %d\n", errno);
	rax = ft_read(fd, buf, 5);
	printf("ft_read fd = 100 ft_read = %d", rax);
	printf("\n                 errno %d\n", errno);
	fd = open("lol.txt", O_RDONLY);
	rax = read(fd, buf, 5);
	printf("read    lol.txt read  = %d\n", rax);
	close(fd);
	fd = open("lol.txt", O_RDONLY);
	rax = ft_read(fd, buf, 5);
	printf("ft_read lol.txt ft_read = %d\n", rax);
	close(fd);
	printf("\n\nInput\n");
	rax = read(0, buf, 200);
	buf[rax] = '\0';
	printf("read %d\n", rax);
	printf("buf %s\n", buf);
	rax = ft_read(0, buf, 200);
	buf[rax] = '\0';
	printf("ft_read %d\n", rax);
	printf("buf %s\n", buf);

}

// ===== FT_STRDUP =====

void check_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *zer = "\0";
	char *save;
	char *save2;
	printf("===== FT_STRDUP =====\n");
	printf(" 1 - %s\n", ft_strdup(zer));
	printf(" 1 - %s\n", strdup(zer));

	printf(" 2 - %s\n", ft_strdup("09876543"));
	printf(" 2 - %s\n", strdup("09876543"));

	printf("===== FT_STRDUP =====\n");
	printf("%-2s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-2s: \"%s\"\n", "or", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-2s: \"%s\"\n", "my", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-2s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-2s: \"%s\"\n", "or", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-2s: \"%s\"\n", "my", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

}

int main()
{
	check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
	check_read();
	check_strdup();
	return (0);

}


