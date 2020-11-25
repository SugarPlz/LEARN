#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<dlfcn.h>
#include<setjmp.h>
#include<wait.h>
#include<errno.h>

#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

/*void err_exit(char *s)
{
	printf("USAGE: *s is failed!\n");
	exit(1);
}*/ //因爲在p6-4.c編譯時，顯示err_exit()重復定義，所以注釋起來
