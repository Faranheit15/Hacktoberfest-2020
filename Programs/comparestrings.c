
#include <stdio.h>
#include <string.h>
void main()
{
    char a[100], b[100];
   
    printf("\nEnter the first string : ");
    gets(a);
    printf("\nEnter the second string : ");
    gets(b);

    if (strcmp(a, b) == 0)
        printf("\nEntered strings are equal.");
    else
        printf("\nEntered strings are not equal.");
    
}
