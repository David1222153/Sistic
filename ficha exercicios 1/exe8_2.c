#include <stdio.h>
#include <string.h>


#define VEHIC_MAXPLEN 81

typedef struct{
	char plate[6];
	char owner[VEHIC_MAXPLEN];
	double value;

} vehic_t;

void print_n_elements(char * str, size_t n);
void vehic_read(vehic_t *v){
	printf("Introduza nome: ");
	fgets(v->owner, sizeof(v->owner), stdin);
	for(int i = 0; i < sizeof(v->owner); i++){
		if(v->owner[i] == '\n'){
			v->owner[i] = '\0';
			break;
		}
	}

	char temp[100];
	printf("Introduza a matricula : ");
	fgets(temp, sizeof(temp) , stdin);
	memcpy(v->plate, temp, sizeof(v->plate));

	printf("Introduza o valor : ");
	scanf("%lf",&v->value);
	getchar();

}

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
	vehic_t v1;
	vehic_read(&v1);
	vehic_print(&v1);
	return 0;
}
