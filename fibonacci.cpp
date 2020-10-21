#include <iostream>
using namespace std;

int main()
{
	
	int a = 0, b = 1, c;
	
	for(int i = 0; i < 9; i++){
		if(i == 0){
			cout << a << "," << b << ",";
		} else {
			c = a + b;
			a = b;
			b = c;
			
			cout << c << ",";
		}
	}
	
	return 0;
}
