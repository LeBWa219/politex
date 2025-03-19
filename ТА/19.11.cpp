#include <stdio.h>

//int main(){
//	int x;
//	scanf ("%i", &x);
//	char str[x] = "abcd";
//	int y = 0;
//	
//	for (int i = 0; str[i] != '\0'  ; i++){
//		y++;
//	}
//	
//	printf ("%i", y);
////	puts(str); //# второй вариант вывода строки
//}

//int main(){
//	char str[100];
//	gets(str);
//	
//	for (int i = 0; str[i] != '\0'; i++){
//		if (str[i] >= 'A' && str[i]<='Z'){
//			str[i] += 'a' - 'A';
//		}
//		else if (str[i]>= 'a' && str[i]<='z'){
//			str[i] -= 'a' - 'A';
//		}
//	}
//	
//	puts(str);
//	
//}


//int main(){
//	int x;
//	char str[100] = "aaaaabab";
//	char str[100] = "ab"; 
//	
//	int count = 0;
//	
//	for (int i=0, j=0; str1[i] != '\0'; i++){
//		if(str1[i] == str2[j]){
//			j++;
//		} else {
//			j=0;
//		}
//		if (str2[j] == '\0'){
//			count++;
//			j=0;
//		}
//	}
//	printf("%i", count);
//}

int main(){
	char str1[100] = "ABCDEF";
	char str2[]="XYZ";
	int index = 3;
	
	int len1 = 0;
	int len2 = 0;
	
	for (; str1[len1] != '\0'; len1++)
	for (; str2[len2] != '\0'; len2++)
	
	int j = len2 - 1;
	
	for (int i = len 1; i>= index; i--){
		str1[i+len2] = str1[i];
		if (i < len2-1 + index){
			str1[i] = str2[i];
			j--; 
		}
	}
	puts(str);
}
