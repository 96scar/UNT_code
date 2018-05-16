#include <stdio.h>
int main()
{
   char x, y, z;
   printf("Enter values for x, y and z : \n");
   scanf("%c%c%c", &x, &y, &z);
   printf("\nEntered values are :\nx=%c\ny=%c\nz=%c", x, y, z);
   return 0;
}
