#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	double width, height;
	if(argc != 3)
	{
		printf("Error!");
		printf("CORRECT SYNTAX: RECT <WIDTH> <HEIGHT>\n\n");
		return 1;
	}
	width = atof(argv[1]);
	height = atof(argv[2]);
	printf("The retangle's area is: %f\n\n", width * height);
	printf("The retangle's perimeter is: %f\n\n", 2 * (width + height));
	return 0;
}
