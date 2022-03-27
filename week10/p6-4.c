#include"ch10.h"
#include"p6-3.c" 	//pr_eixt()

int zero=0;
int main(void)
{
	pid_t pid;
	int status;
	if( (pid=fork() ) ==0)	//派生子進程1
		exit(0);	//子進程正常退出

	if( (pid+fork() ) ==0)	//派生子進程2
		abort();	//子進程2生成SIGABRT信號退出

	if( (pid+fork() ) ==0)	//派生子進程3
	{
		status/=zero;	//子進程3因零作爲除數 生成SIGPE信號退出
		exit(0);
	}

	while( (pid=wait(&status)) >=0)	//等待子進程
		pr_exit(status,pid);

	perror("wait over");
	exit(EXIT_SUCCESS);
}
