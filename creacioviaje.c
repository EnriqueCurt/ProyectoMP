//esto lo ha realizado jose luis ramirez tocino
#include <stdio.h>
#include <time.h> // libreria de control del tiempo

/* esto es una guia del formato del struct
struct viaje
{
	int idviaje;
	char idusuario;
	char matricula[TamMatri];
	int plazalibre;
	int idavuel;
	char estado[TamEstado];
	char fecha[tamFecha];
	char horasal[TamHora];
	char horalle[TamHora];
	float totalprec;
}
*/
char hora;
int idavuelt;
time_t now;
struct viaje *crearvi;

crearvi=(struct viaje *)realloc(sizeof(struct viaje )* 1);

{ #comienzo del realloc

&crearvi[idviaje].idviaje=idviaje; # establece el idviaje
	
&crearvi[idviaje].idusuario=idusuario; # estable el idusuario igual que el id del usuario que he creado el viaje
	
&crearvi[idviaje].plazas="campo plaza del fichero vehiculos"; # establece el numero de plazas disponibles segun el vehiculo selecionado

printf("pulse 1 para ida, pulse 2 para vuelta"); #pide que el usuario indique si el viaje es de ida o vuelta
scanf("$i",&crearvi[idviaje].idavuel);


&crearvi[idviaje].estado="abierto"; # estabece por defecto el viaje como abierto

print("introduzca fecha"); #pide la fecha que el viaje !! hay que controlar que la fecha no sea del pasado!!
scanf("$c",&crearvi[idviaje].fecha);
	if(&crearvi[idviaje].fecha< 

print("introduzca hora de salida"); #pide la hora de salida !! hay que controlar que la hora no haya pasado
scanf("$c",hora);
	   while(stringcmp (hora,time(%now)!=1){ # controlador hora salida 
	   printf("hora no posible"); 
	   scanf("%s",hora);
	   }
&crearvi[idviaje].horasal=hora;
		 
print("introduzca hora de llegada"); # pide la hora de llegada !! hay que controlar que sea mayor que la de salida
scanf("%s",hora);
	   while(stringcmp (hora,crearvi[idviaje].horasal)!=1){ # controlador hora llegada
	   printf("hora no posible"); 
	   scanf("%s",hora);
	   }
&crearvi[idviaje].horalle=hora;
	      

printf("introduce precio total del viaje persona"); # pide el precio total del viaje
scanf("$f",&crearvi[idviaje].totalprecio);

} #fin del realoc		
//
