// 1st program to show that array and pointers are different 
#include <stdio.h> 

int main() 
{ 
int arr[] = {1, 2, 3, 4}; 
int *ptr = arr; 
	
// sizof(int) * (number of element in arr[]) is printed 
printf("Size of arr[] %ld\n", sizeof(arr)); 

// sizeof a pointer is printed which is same for all type 
// of pointers (char *, void *, etc) 
printf("Size of ptr %ld", sizeof(ptr)); 
return 0; 
} 
