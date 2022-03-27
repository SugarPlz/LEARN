#include"ch09.h"
int main()
{
	pid_t i;
	i=vfork();
	if(i<0)
	{
		perror("Vfork failed!\n");
		exit(-1);

	}
	else if(i==0)
	{
		printf("child: pid=%d,i=%d\n",getpid(),geippid(),i);
		exit(-1);
	}
	else
	{
		
	}

}
