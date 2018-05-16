#include <stdio.h>

void setint(int *ip, int i);

int main(void) 
{
    int a;
    setint(&a, 10);
    printf("a= %d\n",a);
    int *b;

    /*Had to add this line to make the program work. You must first initialize a pointer to point to an address. In the GDB, the value of b was large and not initialized.*/
    b = &a;

    setint(b, 10);
    printf("*b= %d\n",*b);
    return 0;
}

void setint(int *ip, int i) 
{
    *ip = i;
} 
