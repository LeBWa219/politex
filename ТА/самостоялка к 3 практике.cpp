#include <stdio.h>

//int main(){
//	int n=3;
//	int matr[n][n] = {
//		{6,7,8},
//		{6,7,8},
//		{6,7,8}
//	};
//	int sum = 0;
//	
//	for (int i=0; i<n; i++) {
//		sum += matr[i][i];
//	}
//	
//	double avg = (double) sum/n;
//	printf ("%lf", avg);
//}



//int main(){
//	int chsl = 3, ans = -1;
//	const int size = 5;
//	int arr [size] = {1,2,3,6,7};
//	for (int i=0; arr[i] != '\0'; i++){
//		if (arr[i] == chsl){
//			ans = i;
//		}
//	}
//	printf ("%i", ans);
//}


//int main(){
//	int x = 1223455;
//	char arr[10]={0};
//	while (x != 0){
//		arr[x%10] +=1;
//		x /= 10;
//	}
//	for (int i = 0; i<10; i++){
//		if (arr[i]>0){
//			printf ("%i - %i\n", i, arr[i]);
//		}
//	}
//}

int main(){
	char str1[] = "abcdefghij";
	char str2[] = "aybc";
	int answ = 0;
	for (int i = 0, j = 0; str1[i] != '\0';i++){
		if (str1[i]==str2[j]){
			j++;
		}
		else j=0;
		if (str2[j] == '\0'){
		answ=1;
		}	
	}
	printf("%i", answ);
}
