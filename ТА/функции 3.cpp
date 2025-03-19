#include<stdio.h>

void drawPyramid(int a){
	for (int b=1; b<=a; b++){
		for (int i=0; i<b;i++){
			printf ("*");
		}
		printf("\n");
	}
	
}

int main(){
	int a;
	scanf("%d",&a);
	drawPyramid(a);
}
