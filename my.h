#include<stdio.h>
#include<stdlib.h>

typedef struct user
{
	int id;
	char name[8];
	char htel[12];
	char tel[12];
}Record;

void input();
void save();
void mySort();
void output();
