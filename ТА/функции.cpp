#include<stdio.h>

int square (int a){
	return a*a;
	
}

float sum(float a, float b){
	return a+b;
}

float sub (float a, float b){
	return a-b;
}

float mult(float a, float b){
	return a*b;
}

float div (float a, float b){
	return a/b;
}

float abs(float a){
	if (a>0){
		return a;
	}else{
		return -a;
	}
}

int main(){
	float a,b,x1,x2,x3,x4,x5;
	scanf("%f %f",&a,&b);
	x1=sum(a,b);
	x2=sub(a,b);
	x3=mult(a,b);
	x4=div(a,b);
	x5=abs(a);
	printf("%f %f %f %f %f",x1,x2,x3,x4,x5);
}
