#include <stdio.h>

struct viaje
{
	int idviaje;
	int idusuario;
	char matricula[8];
	int plazalibre;
	int idavuel;
	char estado[];
	char fecha[11];
	char horasal[6];
	char horalle[6];
	float totalprec;
}

struct viaje *crearvi;

crearvi=(struct viaje *)realloc(sizeof(struct viaje )* 1);

{

$crearvi[idviaje].plazas="campo plazar del fichero vehiculos"; # estableze el numero de plazas disponibles

printf("ida o vuelta"); #pide que el usuario indique si el viaje es de ida o vuelta
scanf("$c",&idvuelt);
if($idavuelt=="ida"){
    $crearvi[idviaje].idavuel=1;
}else{
    $crearvi[idviaje].idavuel=0;
}

$crearvi[idviaje].estado="abierto"; # estabece por defecto el viaje como abierto

print("introduzca fecha"); #pide la fecha que el viaje !! hay que controlar que la fecha no sea del pasado!!
scanf("$c",&crearvi[idviaje].fecha);

print("introduzca hora de salida"); #pide la hora de salida !! hay que controlar que la hora no haya pasado
scanf("$c",&crearvi[idviaje].horasal);

print("introduzca hora de llegada"); # pide la hora de llegada !! hay que controlar que sea mayor que la de salida
scanf("$c",&crearvi[idviaje].horalle);

printf("introduce precio total del viaje persona"); # pide el precio total del viaje
scanf("$f",&crearvi[idviaje].totalprecio);

}
//
