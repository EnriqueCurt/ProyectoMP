#ifndef _CARGAR_FICHEROS_H_
#define _CARGAR_FICHEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void cargar_usuarios_desde_archivo(const char* archivo, usuario* usuarios, int* num_usuarios);

#endif
