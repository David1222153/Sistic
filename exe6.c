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

void minha_divisao(int dividendo,int divisor,int *ptr_quociente,int *ptr_resto){
	*ptr_quociente = divide(dividendo, divisor);
	*ptr_resto = resto(dividendo,divisor);
}



int main(int argc, char **argcv){
	int a = 0, b = 0, quociente = 0, resto = 0;
	if(argc == 3){
		a = atoi(argcv[1]);
		b = atoi(argcv[2]);
		minha_divisao(a, b, &quociente, &resto);
		printf("Divisao : %d\nResto : %d\n",quociente,resto);
		return 0;
	}

	while(1){
		printf("Introduza o dividendo\n");
		scanf("%d",&a);
		if(a == 0) break;
		printf("Introduza o divisor\n");
		scanf("%d",&b);
		minha_divisao(a, b, &quociente, &resto);

		printf("Divisao : %d\nResto : %d\n",quociente,resto);

	}

	return 0;
}
