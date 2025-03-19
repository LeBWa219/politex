#include "stdio.h"
int main(){
	unsigned a,b,c;
	scanf("%d",a,b,c);
	if (a<b){
		printf("a");
	} else if (a<c){
		printf ("min a");
	} else if (b<a){
		printf ("min b");
	}else if (b<c){
		printf ("min c");
	}
}	
