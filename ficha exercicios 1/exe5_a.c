#include <stdio.h>
#include <stdlib.h>


int divide(int a, int b){
	if(b == 0) return 0;
	return a / b;
}

int resto(int a ,int b){
	if(b==0) return 0;
	return a%b;
}


int main(int argc, char **argcv){
	int a = 0, b = 0;
	while(1){
		printf("Introduza o dividendo\n");
		scanf("%d",&a);
		if(a == 0) break;
		printf("Introduza o divisor\n");
		scanf("%d",&b);

		printf("Divisao : %d\nResto : %d\n", divide(a,b), resto(a,b));
	}
	return 0;
}
