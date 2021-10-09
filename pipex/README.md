# -Pipex-

This project aims to make you understand a bit deeper two concets that you already know: the redirections and the pipes.
This project is the discovery in detail and by programming of a UNIX mechanism that you already know.

## Usage:
Compile program with ```make bonus```
```
command : 				"./pipex infile "ls -l" "wc -l" outfile"
must be the same as :	"< infile ls -l | wc -l > outfile"

command : 				"./pipex infile "grep a1" "wc -w" outfile"
must be the same as :	"< infile grep a1 | wc -w > outfile"

command : 				"./pipex infile "grep part" "grep does" outfile"
must be the same as :	"< infile grep part | grep does > outfile"

command bonus: 			"./pipex_bonus here_doc EOF "cat" "grep privet" outfile"
must be the same as :	"cat << EOF | grep privet >> outfile"
```

## You are allowed to use the following functions:

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
