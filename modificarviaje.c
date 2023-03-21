# include <stdio.h>

int main (){
	char opcion;
	printf("¿desea cambiar el estado del viaje?\n");
	scanf("$c",&opcion);
	if($opcion=="si"){
		printf("elija una se las siguientes opciones:\n Abierto=1 \n Cerrado \n Iniciado \n Finalizado \n Anulado");

		switch (opcion){
			case 'Abierto' :
				viaje[idviaje].estado="abierto";
				puts("El estado del viaje ahora es Abierto");
				break;

			case 'Cerrado' :
				viaje[idviaje].estado="Cerrado";
				puts("El estado del viaje ahora es Cerrado");
				break;
		
			case 'Iniciado' :
				viaje[idviaje].estado="Iniciado";		
				puts("El estado del viaje ahora es Iniciado");
				break;

			case 'Finalizado' :
				viaje[idviaje].estado="Finalizado";
				puts("El estado del viaje ahora es Finalizado");
				break;


			case 'Anulado' :
				viaje[idviaje].estado="Anulado";
				puts("El estado del viaje ahora es Anulado");
				break;

			case default :
				puts("Has escrito un estado que no esta en la lista asegurese de que esta bien escrito");
				break;
		}
	}
}
