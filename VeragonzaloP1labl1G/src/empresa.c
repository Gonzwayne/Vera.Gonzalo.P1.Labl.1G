#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "empresa.h"


int mostrarEmpresas(eEmpresa empresas[], int tam, int clear) {
	int todoOk = 0;
	if (empresas != NULL && tam > 0 && clear >= 0 && clear <= 1) {

		if (clear) {
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de empresas    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     nombre                |\n");
		printf("|-------------------------------------|\n");
		for (int i = 0; i < tam; i++) {

			printf("  %d  |  %20s\n", empresas[i].id,
					empresas[i].descripcionEmpresa);
			printf("|-------------------------------------|\n");
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;

}

int asignarEmpresaPorId(eEmpresa listaEmpresa[], int tam, int idEmpresa,
		char descripcionEmpresa[]) {
	int todoOk = 0;
	if (listaEmpresa != NULL && tam > 0 && descripcionEmpresa !=NULL) {
		for (int i = 0; i < tam; i++) {
			if (listaEmpresa[i].id == idEmpresa) {
				strcpy(descripcionEmpresa, listaEmpresa[i].descripcionEmpresa);
				break;
			}
		}

		todoOk = 1;
	}

	return todoOk;
}




