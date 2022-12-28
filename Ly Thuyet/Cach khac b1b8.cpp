#include<stdio.h>
#include<math.h>
int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}
int main() 
{
    int n, i, j, k, m, rs;
    printf("Enter n: ");
    scanf("%d", &n);
    m=n/2;
    for (k=2; k<=m; k++)
    {
        rs=check_prime(k);
        if ((n%k==0) && (rs==1))
        {
            printf("%d ", k);
            i=k;
            for (j=1; j<n; j++)
            {
                i*=k;
                if (n%i==0)
                {
                    printf("%d ", k);
                }
            }
        }
    }
    return 0;
}

