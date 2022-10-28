#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "destino.h"


int mostrarDestinos(eDestino destinos[], int tam, int clear) {
	int todoOk = 0;
	if (destinos != NULL && tam > 0 && clear >= 0 && clear <= 1) {

		if (clear) {
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de destinos    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     destino              |\n");
		printf("|-------------------------------------|\n");
		for (int i = 0; i < tam; i++) {
			if (destinos[i].isEmpty == 0) {
				printf("  %d  |  %20s\n", destinos[i].id,
						destinos[i].descripcionDestino);
				printf("|-------------------------------------|\n");
			}
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;

}
