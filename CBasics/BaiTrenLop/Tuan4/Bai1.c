#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    double x;
    double y;
} point;

typedef struct
{
    point center;
    double radius;
} circle;

int check(point p, circle c)
{
    if(sqrt(((p.x - c.center.x) * (p.x - c.center.x)) + ((p.y - c.center.y) * (p.y - c.center.y))) < c.radius)
    {
        return 1;
    } 
    else return 0;
}

int main(int argc, char *argv[])
{
    point p; circle c;
    printf("Enter point's cordinate (x -> y): ");
    scanf("%lf %lf", &p.x, &p.y);
    printf("Enter circle center's cordinate: ");
    scanf("%lf %lf", &c.center.x, &c.center.y);
    printf("Enter circle's radius: ");
    scanf("%lf", &c.radius);
    printf("%d\n", check(p, c));
}