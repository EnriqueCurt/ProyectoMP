#include <stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include "Cargar_ficheros.c"
#include "volcar_datos_ficheros.h"
#include "volcar_datos_ficheros.c"
#include "creacioviaje.c"
#include "creacioviaje.h"
#include "InicioSesion.h"
#include "InicioSesion.c"
#include "Registro.h"
#include "Registro.c"
#include "m_menu.h"
#include "m_menu.c"
#include "modificar.c"
#include "modificar.h"
#include "listar_menu.h"
#include "listar_menu.c"

int main()
{
    usuario* usuarios = (usuario*)malloc(sizeof(usuario));
    vehiculo* vehiculos =(vehiculo*)malloc(sizeof(vehiculo));
    viaje* viajes = (viaje*)malloc(sizeof(viaje));
    paso* pasos =( paso*)malloc(sizeof(paso));
    int num_usuarios = 0;
    int num_vehiculos = 0;
    int num_viajes = 0;
    int num_pasos = 0;

    cargar_ficheros(&usuarios,&num_usuarios,&vehiculos,&num_vehiculos,&viajes,&num_viajes,&pasos,&num_pasos);
    menuInicio(&usuarios,&num_usuarios,&vehiculos,&num_vehiculos,&viajes,&num_viajes,&pasos,&num_pasos);
    volcar_ficheros(usuarios,&num_usuarios,vehiculos,&num_vehiculos,viajes,&num_viajes,pasos,&num_pasos);
    return 0;
}
