#include <stdio.h>
#include <math.h>
int CheckNT(int a);
int main()
{
    int i,a;
    printf("Nhap vao gia tri a\n");
    scanf("%d",&a);
    int Lim=a/2;
    // Vì a ch? chia h?t t?i da cho 1 n?a c?a nó
    // Ví d? 6 chia chia h?t t?i da là 3 k th? chia dc 4,5
    for(i=2;i<=Lim;i++)
    {
        // N?u a là s? nguyên t? thì vi?t ra và thoát
        if(CheckNT(a))
        {
           printf("%d ",a);
           break;
        }
        // N?u a chia h?t i và i là s? nguyên t? thì
        // Vi?t i và l?y a=a/i d? xet ti?p a m?i 
        while (a%i==0&&CheckNT(i))
        {
           printf("%d ",i);
           a/=i;
        }
        // N?u a==1 thì thoat vòng l?p nha
        if(a==1)
        break;
       
    }
   
return 0;
}

// Hàm ki?m tra s? nguyên t?
int CheckNT(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
    // N?u a chia hêt => nó không là s? nguyên t? => tra v? false
        if(a%i==0)
        return 0;
    }
    // N?u ch?y h?t vòng l?p mà nó không tr? v? false => là s? nguyên t?
    return 1;
}
