#include <stdio.h>

//void sum(int a, int b){
//	a+=b;
//}
//
//int main(){
//	int al=a;
//	al=10;
//	
//	
//	int a = 3;
//	int b = 5;
//	
//	int* aptr = &a;
//	int* bptr = &b;
//	(sum)a,b;	
//	printf("%p\n%p", *aptr, *bptr);
//}

//main(){
//	int arr[5] = {1,2,3,4,5};
//	
//	int*  arrptr = arr;
//	
//	for (int i = 0; i<5; i++){
//		printf("%i ",*(arr + i));
//	}
//}

//int dllen (char* str){
//	int len;
//	for(int i = 0; *(str+i) != '\0'; i++){
//		len++;
//	}
//	return len;
//	
//}
//int main(){
//	char* str = "zxc";
//	printf("%i", dllen(str));
//}

bool strstr (char* str1, char* str2){
	for(int i = 0 ; (*(str1+i) != '\0') || (*(str2+i) != '\0'); i++){
		if (*(str1+i) == *(str2+i)) return true;
		else return false;
	}
}
 int main(){
 	
 	printf("%c", strstr("abc", "abc"));
 	
}
