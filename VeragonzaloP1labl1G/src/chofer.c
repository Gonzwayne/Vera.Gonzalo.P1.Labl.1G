#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "chofer.h"

int asignarChoferPorId(eChofer listaChofer[], int tamChofer, int idChofer,char nombre[]) {
	int todoOk = 0;
	if (listaChofer != NULL && tamChofer > 0 && nombre) {
		for (int i = 0; i < tamChofer; i++) {
			if (listaChofer[i].id == idChofer) {
				strcpy(nombre, listaChofer[i].nombre);
				break;
			}
		}

		todoOk = 1;
	}

	return todoOk;
}
