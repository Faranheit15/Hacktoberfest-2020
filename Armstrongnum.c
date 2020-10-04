#include <stdio.h>
int main()
{
int num, original, rem, sum = 0;
printf("Enter a three-digit Number: ");
scanf("%d", &num);
original = num;
while(original != 0)
{
rem = original%10;
sum =sum + rem*rem*rem;
original=original/ 10;
}
if(sum == num)
printf("%d is an Armstrong number.",num);
else
printf("%d is not an Armstrong number.",num);
return 0;
}
