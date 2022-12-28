#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

enum {SUCESS, FAIL};
float x1, x2;

//Solve Equation
int SolveE(float a, float b, float c)
{
    float delta = (b * b) - (4 * a * c);
    if(delta < 0)
    {
        x1 = x2 = 0.0;
        return 0;
    }
    else if(delta == 0)
    {
        x1 = x2 = -b/(2 * a);
        return 1;
    }
    else 
    {
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        return 2;
    }
}

int main(int argc, char *argv[])
{
    //int res = SUCCESS;
    if(argc != 5)
    {
        printf("SYNTAX ERROR!\n");
        printf("SYNTAX guide: sde [a] [b] [c].\n");
        return 1;
        //exit(1);
    }

    float a = atof(argv[2]);
    float b = atof(argv[3]);
    float c = atof(argv[4]);
    //printf("%f %f %f\n", a, b, c);

    if(a == 0) 
    {
        printf("Error! Cannot solve with a = 0.\n");
        return 1;
    }

    int res = SolveE(a, b, c);
    if(res == 0)
    {
        printf("The given equation has %d solution.\n", res);
    } 
    else if(res == 1)
    {
        //phan du
        float d = x1 - (int)x1;
        if(d != 0)
        {
            printf("The given equation has %d solution.\n", res);
            printf("x1 = x2 = %.4f", x1);
        }
        else 
        {
            printf("The given equation has %d solution.\n", res);
            printf("x1 = x2 = %d", (int)x1);
        }
    }
    else 
    {
        //phan du
        float d1 = x1 - (int)x1;
        float d2 = x2 - (int)x2;
        if(d1 != 0 && d2 != 0)
        {
            printf("The given equation has %d solutions.\n", res);
            printf("x1 = %.4f.\nx2 = %.4f.\n", x1, x2);
        }
        else if(d1 != 0 && d2 == 0)
        {
            printf("The given equation has %d solutions.\n", res);
            printf("x1 = %.4f.\nx2 = %d.\n", x1, (int)x2);
        }
        else if(d1 == 0 && d2 == 0)
        {
            printf("The given equation has %d solutions.\n", res);
            printf("x1 = %d.\nx2 = %d.\n", (int)x1, (int)x2);
        }
        else if(d1 == 0 && d2 != 0)
        {
            printf("The given equation has %d solutions.\n", res);
            printf("x1 = %d.\nx2 = %.4f.\n", (int)x1, x2);
        }
    }

    return 0;
}