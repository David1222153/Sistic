#include <stdio.h>


int memcmp(const void* data1,const void*data2, size_t n){
	char *cast1 = (char *) data1;
	char *cast2 = (char *) data2;

	for(int i = 0; i < n; i++){
		if(cast1[i] != cast2[i])
		{
			return -1;
		}
	}

	return 0;
}


int main(){

	int data1[] = {1,2,3,4,5};
	int data2[] = {1,2,3,4,5};
	int data3[] = {1,3,2,4,5};
	char data4[] = {1,2,3,4,5};
	char data5[] = {1,2,3,4,5};
	char data6[] = {1,2,3};

	char equal = memcmp(data4,data6,sizeof(data6));
	if(equal == 0){
		printf("Iguais!\n");
	} else {
		printf("Diferentes!\n");
	}

	return 0;


}
