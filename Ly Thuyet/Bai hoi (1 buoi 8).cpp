#include <stdio.h>
#include <math.h>
int CheckNT(int a);
int main()
{
    int i,a;
    printf("Nhap vao gia tri a\n");
    scanf("%d",&a);
    int Lim=a/2;
    // V� a ch? chia h?t t?i da cho 1 n?a c?a n�
    // V� d? 6 chia chia h?t t?i da l� 3 k th? chia dc 4,5
    for(i=2;i<=Lim;i++)
    {
        // N?u a l� s? nguy�n t? th� vi?t ra v� tho�t
        if(CheckNT(a))
        {
           printf("%d ",a);
           break;
        }
        // N?u a chia h?t i v� i l� s? nguy�n t? th�
        // Vi?t i v� l?y a=a/i d? xet ti?p a m?i 
        while (a%i==0&&CheckNT(i))
        {
           printf("%d ",i);
           a/=i;
        }
        // N?u a==1 th� thoat v�ng l?p nha
        if(a==1)
        break;
       
    }
   
return 0;
}

// H�m ki?m tra s? nguy�n t?
int CheckNT(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
    // N?u a chia h�t => n� kh�ng l� s? nguy�n t? => tra v? false
        if(a%i==0)
        return 0;
    }
    // N?u ch?y h?t v�ng l?p m� n� kh�ng tr? v? false => l� s? nguy�n t?
    return 1;
}
