-pipex-

This project aims to make you understand a bit deeper two concets that you already know: the redirections and the pipes.
This project is the discovery in detail and by programming of a UNIX mechanism that you already know.

Usage:

command : 				"./pipex infile "ls -l" "wc -l" outfile"
must be the same as :	"< infile ls -l | wc -l > outfile"

command : 				"./pipex infile "grep a1" "wc -w" outfile"
must be the same as :	"< infile grep a1 | wc -w > outfile"

command : 				"./pipex infile "grep part" "grep does" outfile"
must be the same as :	"< infile grep part | grep does > outfile"

command bonus: 			"./pipex_bonus here_doc EOF "cat" "grep privet" outfile"
must be the same as :	"cat << EOF | grep privet >> outfile"

exit cods

0	- all OK!
-1	- access rights
-2	- malloc error
-3	- pipe error
-4	- fork error
-5	- execvp error (invalid command)
-6	- close error
-7	- dup2 error
-8	- open error

You are allowed to use the following functions:

-- access -- (проверяет права доступа #include <unistd.h> )
https://www.opennet.ru/man.shtml?topic=access&category=2&russian=0
http://www.c-cpp.ru/content/access

-- unlink -- (удаляет указанный файл #include <dos.h>)
https://www.opennet.ru/man.shtml?topic=unlink&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/unlink

-- waitpid/wait -- (ожидает завершения процесса  #include <sys/wait.h>)
https://www.opennet.ru/man.shtml?topic=waitpid&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pipe -- (создает канал #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=pipe&category=2&russian=0

-- dup/dup2 -- (создать дубликат файлового дескриптора #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=dup&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/dup-dup2

-- execve -- (выполнить программу #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=execve&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- fork -- (создает дочерний процесс #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=fork&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- perror -- (выводит сообщение о системной ошибке #include <errno.h>)
https://www.opennet.ru/man.shtml?topic=perror&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/perror

-- strerror -- (возвращают строку, описывающую ошибку #include <string.h>)
https://www.opennet.ru/man.shtml?topic=strerror&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/strerror-0

-- exit -- (функция, завершающая работу программы #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=exit&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/books/exit

-- open --
https://www.opennet.ru/man.shtml?topic=open&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/open-rtlopen

-- close --
https://www.opennet.ru/man.shtml?topic=close&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/close-rtlclose

-- read --
https://www.opennet.ru/man.shtml?topic=read&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/read-rtlread

-- write --
https://www.opennet.ru/man.shtml?topic=write&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/write-rtlwrite

-- malloc --
https://www.opennet.ru/man.shtml?topic=malloc&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/write-rtlwrite

-- free --
http://www.c-cpp.ru/content/free


ft_chek_file = 1, 2, 4, 3, 5, 6, 7
1 - read
2 - write
4 - exe
3 - read + write
5 - read + exe
6 - write + exe
7 - read + write + exe


leaks - check

	char	cmd0_0[3] = "ls";
	char	cmd0_1[3] = "-l";
	char	*cmd0[3];
	cmd0[0] = cmd0_0;
	cmd0[1] = cmd0_1;
	cmd0[2] = NULL;
	char	cmd1_0[3] = "wc";
	char	cmd1_1[3] = "-l";
	char	*cmd1[3];
	cmd1[0] = cmd1_0;
	cmd1[1] = cmd1_1;
	cmd1[2] = NULL;
	char	**cmd[3];
	cmd[0] = cmd0;
	cmd[1] = cmd1;
	cmd[2] = NULL;



void	ft_print(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (data->envp[i])
		printf("env[%d] : |%s|\n", i, data->envp[i]), i++;
	i = 0;
	while (data->cmd[i])
	{
		j = 0;
		while (data->cmd[i][j])
			printf("cmd[%d][%d] : |%s|\t", i, j, data->cmd[i][j]), j++;
		printf("\n");
		i++;
	}
	printf("read_fd = %d\twrite_fd = %d\n", data->fd_inf, data->fd_out);
	printf("size = %d\n", data->size);
	printf("hd   = %d\n", data->here_doc);
	printf("EOF  = %s\n", data->eof);
	printf("len  = %d\n", data->hd_len);
}
