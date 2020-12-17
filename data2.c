/*
 * In this program, I am calculating the integer constant 2 raised to various powers.
 * I compare for loop multiplication and the use of the pow() function in math.h
 * to find out how they compare in their return values.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Function prototype*/
unsigned long get_power(int x, int y);

int main(void)
{
	int i; //The exponent we will work with.
	printf("We're going to raise 2 to a given power.\n");
	printf("Enter the number you want to raise 2 to its power.\n");
	scanf("%d", &i);
	if (i > 64 || i < 0)
	{
		printf("You need to enter a value that is not above 64. 64 is the upper limit and 0 the lower limit.\n");
		exit(1);
	}
	else{
		printf("unsigned long has the following upper limit: %d bytes. ", 
				(sizeof(unsigned long)));
		printf("This translates to %llu.\n", 
				(unsigned long long)pow(2.0, 8 * sizeof(unsigned long)));
		printf("You entered %d.\n", i);
		double res = get_power(2, i);
		printf("2 to the power of %d is == %lu\n", i, get_power(2,i));
		printf("Let us now use the math.h header\\library file.\n");
		double d = (double) i;
		res = pow(2.0, d);
		printf("2.0 to the power of %lf is == %lf.\n", d, res);
		return 0;
	}
}
unsigned long get_power(int base, int exponent)
{
	unsigned long y = (unsigned long) base;
	if (exponent == 1)
		return y;
	else if (exponent == 0)
		return 1;
	else if (exponent > 32)
	{
		printf("We're actually only working with values up to 32.\n");
		exit(1);
	}
	else
	{
		for (int i = 1; i < exponent; i++)
		{
			printf("%lu x %lu == ", y, y);
			y *= 2;
			printf("%lu\n", y);
		}
		return y;
	}
}
