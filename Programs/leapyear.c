#include<stdio.h>


void main()
{
    int year;

    printf("Enter a year : ");
    scanf("%d", &year);

    if (year % 400 == 0)
        printf("\n%d is a leap year.", year);
    else if (year % 100 == 0)
        printf("\n%d is not a leap year.", year);
    else if (year % 4 == 0)
        printf("\n%d is a leap year.", year);
    else
        printf("%d is not a leap year.", year);

}
