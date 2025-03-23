#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copy_vectors(char* src_char, int* src_int,char* dst_char,int* dst_int,size_t n_elements){
	dst_char = stpcpy(dst_char, src_char);
	dst_int = memcpy(dst_int,src_int,n_elements);
}

void print_vectors(char * str, int* data, size_t nStr,size_t nData){

	for(int i = 0; i < nStr;i++){
		printf("Valor em str : %c\n",str[i]);
	}
	for(int i = 0; i < nData;i++){
		printf("Valor em data : %d\n",data[i]);
	}

}




int main(){

	char str1[] = {"Teste!"};
	int data1[] = {0,1,2,3,4,5,6,7,8,9};
	char str2[1000];
	int data2[1000];

	copy_vectors(str1, data1, str2, data2,sizeof(data1));
	printf("Size of str1 : %ld\n",sizeof(str1));
	printf("Size of data1 : %ld\n",sizeof(data1));
	printf("Size of str2 : %ld\n", sizeof(str2));
	printf("Size of data2 : %ld\n", sizeof(data2));

	print_vectors(str2, data2, sizeof(str1) / sizeof(*str1),sizeof(data1)/sizeof(*data1));
}
