#include"../ch08.h"
extern void dynamic_lib_fun_call(void);
extern void mySort(void);
int main()
{	
	dynamic_lib_fun_call();
	int a,b,c,d;
	scanf("%d",&a);
	scanf("%d %d %d",&b,&c,&d);
	printf("123\n");
	return 0;
}

