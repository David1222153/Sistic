#include <stdio.h>


#define VEHIC_MAXPLEN 81

typedef struct{
	char plate[6];
	char owner[VEHIC_MAXPLEN];
	double value;

} vehic_t;

void print_n_elements(char * str, size_t n){
	for(int i = 0; i < n; i++){
		if(!str[i]){
			return;
		}
		printf("%c",str[i]);
	}
	printf("\n");
}

void vehic_print(vehic_t *v){
	printf("Plate number : ");
	print_n_elements(v->plate,  sizeof(v->plate));
	printf("Owner : %s\n", v->owner);
	printf("Value : %.2lf\n",v->value);
}


int main(){
	vehic_t v1 = {{'1','4','7','9','H','P'},"Carlos Reis Salvador Almada",2999999.99};
	vehic_print(&v1);
	return 0;
}
