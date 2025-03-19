#include <stdio.h>

//int rever(int x){
//	int a;
//	while (x>0){
//		a=a*10+x%10;
//		x/=10;	
//	}
//	
//	printf("%i",a);
//	
//}
//
//
////int main(){
////	int z;
////	scanf("%i",&z);
////	rever(z);	 
////}
//
//int remove(int number, int index);{
//	int res=0;
//	for (int i=1;number>0; i++){
//		if (i==index){
//			
//			continue;
//		}
//		res = res*10;
//		res+= number % 10;
//		number/=10;	
//		
//	}
//	return res;
//}
//
//int main(){
//	int a;
//	scanf("%i",&a);
//	printf("%i",remove(123),2); //13
//	printf("%i",remove(1243),3); //123
//}

int palindr (int x){
	int x0=x;
	int x1=0;
	while (x>0){
		int a = x%10;
		x1=x1*10+a;
		x/=10;
		
	}
	return x0==x1;
}

int main (){
	int num;
	scanf("%i",&num);
	
	if (palindr(num)){
		printf("%d 1 \n", num);
	} else {
		printf("%d 0 \n",num);
	}
}
