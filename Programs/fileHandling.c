#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fptr;

    char c;
  int i,upper = 0, lower = 0, number = 0, special = 0;


    // Open file
    fptr = fopen("Shaun.txt", "r");
    if (fptr == NULL)
    {
	printf("Cannot open file \n");
	exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
	 if(c>='A' && c <='Z')
upper++;
  else if(c>='a' && c <='z')
lower++;
  else if(c>='0' && c <='9')
number++;
else special++;
c = fgetc(fptr);
    }
    printf("%d %d %d %d",upper,lower,number,special);
    fclose(fptr);
}
