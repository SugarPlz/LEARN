#include"ch08.h"
static void func1(void);
static void func1(void);
static jmp_buf g_stack_env;
int main()
{
	if(setjmp(g_stack_env)==0)
	{
		printf("Main Normal flow!\n");
		func1();
		printf("Normal flow back from func1!\n");
	}
	else
	{
		printf("Back from long jump");
	}	
}
