#include "stdio.h"

//int main(){
//	short c = 'A';
//	switch(c){
//		case 'A':
//			printf("one\n");
//			break;
//		case 'B':
//			printf("two\n");
//			break;
//		case 'C':
//			printf("three\n");
//			
//		default:
//			printf("No one\n");
//	}
//}

//int main(){
//	int a,b;
//	scanf("%i\n %i",&a,&b);
//	while (a<=b){
//		printf("%i",a);
//		a++;
//	}
//}

//int main(){
//	int a,b;
//	scanf("%i\n %i",&a,&b);
//	while (a>=b){
//		printf("%i",a);
//		a--;
//	}
//}
	
////int main(){
////	int a,b;
////	scanf("%i\n %i",&a,&b);
////	for (;a<=b;a++){
////		printf("%i",a);
////	}
//	for (;a>=b;b++){
//		printf("%i",a);
//	}
////}

//	int main(){
//		int a,b;
//		scanf("%i\n %i",&a,&b);
//		for (;a>=b;a--){
//			printf("%i",a); 
//		}
//		for (;a<=b;b--){
//			printf("%i",b);
//		}
//	}

int main() {
  for (int i = 1; i <= 20; i++) {
    if (i % 2 == 0) {
      printf("%d ", i);
    }
  }
}
