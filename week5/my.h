#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define err_exit(MESSAGE) (                \
    perror(MESSAGE),                       \
    exit(1)                                \
)

typedef struct USER{
    int id;
    char name[8];
    char htel[12];
    char tel[12];
}Record;


void MyInput(void);
void mySave(struct USER user);
int myCmp(const void *a,const void *b);
void MySort(int way);
void MyRanddat(struct USER user);
void MyOutput(struct USER user);

