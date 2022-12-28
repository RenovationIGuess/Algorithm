#include <stdio.h> 
int main(void) 
{ 
char ch1, ch2, ch3; /* three letters (all uppercase or all lowercase) */ 
char alpha_first; /* alphabetically first letter */ 
/* Get three letters. */ 
printf("Enter three uppercase or three lowercase letters> "); 
scanf("%c%c%c", &ch1, &ch2, &ch3); 
/* Save the alphabetically first of ch1 and ch2 in alpha_first. */
if (ch1 < ch2) 
alpha_first = ch1; /* ch1 comes before ch2 */ 
else 
alpha_first = ch2; /* ch2 comes before ch1 */ 
/* Save the alphabetically first of ch3 and alpha_first in alpha_first.*/
if (ch3 < alpha_first) 
alpha_first = ch3; /* ch3 comes before alpha_first */ 
/* Display result. */ 
printf("%c is the first letter alphabetically.\n", alpha_first); 
return (0); 
}
