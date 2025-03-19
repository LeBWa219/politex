#include "stdio.h"
/*
int main(){
	unsigned a;
	scanf("%d",&a);
	int b;
	scanf("%i", &b);
	printf("%d",a>>b);
}


int main(){
	unsigned a;
	scanf("%d",&a);
	int b;
	scanf("%i", &b);
	printf("%d",ab);
}
*/
int main(){
	unsigned a;
	scanf("%d",&a);
	unsigned mn=1,wd=4;
	unsigned b1=a&mn,b2=a&wd;
	
	printf("%s\n",b1==mn? "yes":"no");
	printf("%s\n",b2==wd ? "yes":"no");
}


