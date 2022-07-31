#include <stdio.h>
#include <string.h>

#define MAX 30

void generar_mail(char *, char *);

int main(){
	char nombre[MAX];
	char mail[MAX];
	
	printf ("Ingrese su nombre y apellido\n");
	fgets(nombre, sizeof(nombre) , stdin);
	generar_mail(nombre, mail);
	printf("%s\n", mail);
	return 0;
}

void generar_mail(char *in, char *out){
	int i, j, h = 0;
	char fin[17] = "@frba.utn.edu.ar";
	
	out[0] = in[0];
	for(i=0; i < strlen(in); i++) {
		if(in[i] == ' ') {
			for(j = i + 1; i < strlen(in); j++) {	
				if(h < 8) {
					out[h+1] = in[j];
					h++;			
				}
				else break;
			}
		}
	}
	out[h] = '\0';
	strcat(out, fin);
}
