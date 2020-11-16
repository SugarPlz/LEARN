#include"ch08.h"
int main()
{
	void *fpt=dlopen("./libdlib.so",RTLD_NOW);
	if(!fpt)
	{
		p[rintf("dlopen failed!\n");
		exit(1);
	}
	void (*fp)(void)=dlsym(fpt,"dinamic_lib_fun_call");
	if(!fp)
	{
		printf("Dlsym Failed\n");
		exit(1);
	}
	fp();
	dlclose(fpt);
	return 0;
}
