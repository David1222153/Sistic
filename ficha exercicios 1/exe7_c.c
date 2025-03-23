
#include <stdio.h>


int strcmp(char* str1,char*str2){

	while(*str1 && (*str1==*str2)){
		str1++;
		str2++;
	}

	if(*str1 == *str2) {
		return 0;
	}
	return -1;
}

int main(int argc, char* argcv[]){

	if(argc != 3){
		printf("Introduza duas strings para comparar!\n");
		return -1;
	}

	char equal = 0;
	equal = strcmp(argcv[1],argcv[2]);
	if(equal == 0){
		printf("Iguais!\n");
	} else {
		printf("Diferentes!\n");
	}

	return 0;


}
