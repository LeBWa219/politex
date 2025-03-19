#include <stdio.h>
int main() {
	const int xsize = 2, ysize = 3;
	int arr1 [ysize][xsize] ={{1,2}
							{3,4};
							{5,6}};
	int arr2 [xsize][ysize];
	for (int i=0; i<xsize; i++){
		for (int j=0;j<ysize; j++){
			printf("%i", arr2[i][j]);
		}
	}
	
}
