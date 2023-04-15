#include <stdio.h>
#include <stdlib.h>
#include "struct_ficheros.h"

int main (){
	char opcion;
	int opcion2;
	printf("¿desea cambiar el estado del viaje?\n");
	scanf("$c",&opcion);
	if($opcion=="si"){
		printf("elija una se las siguientes opciones:\n Abierto \n Cerrado \n Iniciado \n Finalizado \n Anulado");
	scanf("$i",&opcion2);
		switch (opcion2){
			case 'Abierto' :
				strcat((*viajes)[idviaje].estado,"Abierto");
				puts("El estado del viaje ahora es Abierto");
				break;

			case 'Cerrado' :
				strcat((*viajes)[idviaje].estado,"Cerrado");
				puts("El estado del viaje ahora es Cerrado");
				break;
		
			case 'Iniciado' :
				strcat((*viajes)[idviaje].estado,"Iniciado");		
				puts("El estado del viaje ahora es Iniciado");
				break;

			case 'Finalizado' :
				strcat((*viajes)[idviaje].estado,"Finalizado");
				puts("El estado del viaje ahora es Finalizado");
				break;


			case 'Anulado' :
				strcat((*viajes)[idviaje].estado,"Anulado");
				puts("El estado del viaje ahora es Anulado");
				break;

			case default :
				puts("Has escrito un estado que no esta en la lista asegurese de que esta bien escrito");
				break;
		}
	}
}
