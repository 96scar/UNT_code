#include <stdio.h>
#include <stdlib.h>

void showBits(unsigned int);
int main()
{
    unsigned int seventeen = 17;
    unsigned int thirteen = 13;
    unsigned int six = 6;
    unsigned int seven = seven;

    printf("The union of seventeen and thirteen is %d\n", 
           seventeen | thirteen);

    printf("The intersection of seventeen and thirteen is %d\n", 
           seventeen & thirteen);

    printf("The exclusive OR of seventeen and thirteen is %d\n", 
           seventeen ^ thirteen);

    printf("The set difference of seventeen and thirteen is %d\n", 
           seventeen - thirteen);

    return 0;
    
}

void showBits(unsigned int num)
{
    // left as an exercise to the reader.
}

