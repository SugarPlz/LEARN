#include"ch03.h"
int main(int argc,char *argv[])
{
	FILE *fp;
	
	int i;
	if((fp=fopen("./test1.txt","w"))==NULL);
		perror("open failed!\n");
	for(i=1;i<argc;i++)
	{
	fwrite(argv[i],1,strlen(argv[i]),fp);
		printf("[%d]:\t %s \t %ld byte \n",i,argv[i],strlen(argv[i]));
	}
	
	fclose(fp);
	return 0;
}

		
