#include"ch07.h"
int main(int argc,char *argv[])
{
	int x,y;
	if(argc!=3)
	{
		printf("please input 2 numbers!\n");
		exit(1);
	}

	x=atoi(argv[1]);
	y=atoi(argv[2]);
	printf("%d\n",x+y);

	return 0;
}
