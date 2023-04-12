#ifndef _INI_USER_H_
#define _INI_USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int leerUsuarios(Usuario usuarios[] {
    FILE *archivo;
    char linea[MAX_LONG_USER + MAX_LONG_PASSW + 2];
    int numUsuarios = 0;

    archivo = fopen("Usuarios.txt", "r");
    if (archivo == NULL) {
        return -1; // Error al abrir el archivo
    }

    int verificarUsuario(usuario, contrasena, usuarios, numUsuarios)
int i;

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(usuario, usuarios[i].usuario) == 0 && strcmp(contrasenia, usuaros[i].contrasena) == 0) {
            return usuarios[i].perfil;
        }
    }

    return -1; // Usuario no encontrado

    #endif // _INI_USER_H_
