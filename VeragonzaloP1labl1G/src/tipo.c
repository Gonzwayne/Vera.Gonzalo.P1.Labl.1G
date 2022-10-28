#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "tipo.h"


int mostrarTipos(eTipo tipos[], int tam, int clear) {
	int todoOk = 0;
	if (tipos != NULL && tam > 0 && clear >= 0 && clear <= 1) {

		if (clear) {
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de tipos    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     tipo               |\n");
		printf("|-------------------------------------|\n");
		for (int i = 0; i < tam; i++) {

			printf("  %d  |  %20s\n", tipos[i].id, tipos[i].descripcionTipo);
			printf("|-------------------------------------|\n");
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;

}

int asignarTipoPorId(eTipo listaTipo[], int tam, int idTipo,
		char descripcionTipo[]) {
	int todoOk = 0;
	if (listaTipo != NULL && tam > 0 && descripcionTipo) {
		for (int i = 0; i < tam; i++) {
			if (listaTipo[i].id == idTipo) {
				strcpy(descripcionTipo, listaTipo[i].descripcionTipo);
				break;
			}
		}

		todoOk = 1;
	}

	return todoOk;
}
