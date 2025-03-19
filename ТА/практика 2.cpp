#include <stdio.h>

//int  razruadnost( int i ){
//	int x = 0;
//	while (i>0){	
//		i/=10;
//		x+=1;
//	}
//	return x;
//}
//
//int main(){
//	int chisl;
//	scanf ("%i", &chisl);
//	printf("%i", razruadnost(chisl));
//}



//int main () {
//	for (int x=1; x<=20; x+=2){
//		printf("%i\n" ,x);
//	}
//	
//}




//int rever(int x){
//	int a;
//	while (x>0){
//		a=a*10+x%10;
//		x/=10;	
//	}	
//	printf("%i",a);
//}
//int main(){
//	int z;
//	scanf("%i",&z);
//	rever(z);
//}

//void pyr(int x){
//	for (int i=0; i<=x;i++){
//		for(int j=0;j<i;j++){
//			printf("*");
//		}printf("\n");
//	}
//}
//
//int main(){
//	int x;
//	scanf("%i",&x);
//	pyr(x);
//}


//
//int palindr (int x){
//	int x0=x;
//	int x1=0;
//	while (x>0){
//		int a = x%10;
//		x1=x1*10+a;
//		x/=10;
//		
//	}
//	return x0==x1;
//}
//
//int main (){
//	int num;
//	scanf("%i",&num);
//	
//	if (palindr(num)){
//		printf("%d 1 \n", num);
//	} else {
//		printf("%d 0 \n",num);
//	}
//}
