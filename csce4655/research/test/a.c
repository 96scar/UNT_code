#include <stdio.h>

int main()
{
	int a=1, b=2, c=3;
	char x='a', y='b', z='c';
	float d, e, f;
	double g, h, i;
	char *arr = "Hello World!";
	
	d = 1.23;
	e = 22.578;
	f = 354.23456;
	g = 234.4567885;
	h = 234.5676743234;
	i = 6858.2348294722839;
	int count;
	for(count=0; count<10; count++)
	{
		a = a+b+c;
		d = d + e + f;
		g = g+h+i;
	}

//	printf("%d\t%d\t%d\n%c\t%c\t%c\n%f\t%f\t%f\n%lf\t%lf\t%lf\n%s\n", a, b, c, x, y, z, d, e, f, g, h, i, arr);
		
//	printf("Addition: %d\n", a+b+c);
	
//	printf("Subtraction: %f\n", f-d-e);
	
//	printf("Multiplication: %lf\n", g*h*i);
	
//	printf("Division: %d\n", c/a);

	return 0;
}
