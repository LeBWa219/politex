#include "stdio.h"

int main(){
	int a = 8; 
	int b = 5;
	int c = 0;
	if (a>b){
		int c = a-2;
		printf ("a>b");	
	} else if (a<b) {
		printf ("a<b");
	} else {
		printf ("a=b");	
	}
	printf("%i",c);
	
	
}
