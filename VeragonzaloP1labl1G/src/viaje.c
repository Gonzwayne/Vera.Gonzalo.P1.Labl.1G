#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"



int buscarViaje(int id, int *pIndice, eViaje vec[], int tam) {
	int todoOk = 0;
	int indice = -1;
	if (pIndice != NULL && vec != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty == 0 && vec[i].id == id) {
				indice = i;
				break;
			}
		}
		*pIndice = indice;
		todoOk = 1;
	}
	return todoOk;

}

int altaViaje(int *nextIdViaje, eViaje vec[], int tam, eEmpresa listaEmpresas[],int tamEmp, eTipo listaTipos[], int tamTipo, eMicro listaMicros[],int tamMicros, eDestino listaDestinos[], int tamDestino)
{
	int todoOk = 0;
	int indice;
	eViaje auxViaje;
	if (nextIdViaje != NULL && vec != NULL && tam > 0 && listaEmpresas !=NULL && tamEmp >0 && listaTipos !=NULL && tamTipo >0 && listaMicros !=NULL && tamMicros >0 && listaDestinos !=NULL && tamDestino >0) {
		buscarViajeVacio(&indice, vec, tam);
		if (indice == 1) {
			printf("No hay viaje \n");
		} else {
			auxViaje.id = *nextIdViaje;
			mostrarMicros(listaMicros, tamMicros,listaEmpresas,tamEmp,listaTipos,tamTipo, 0);

			utn_getNumero(&auxViaje.idMicro, "Ingrese id del micro: \n",
					"Error reingrese id del micro \n", 100, 200, 3);
			if (buscarMicro(auxViaje.idMicro,&indice,listaMicros,tamMicros) != -1)
			{
				mostrarDestinos(listaDestinos, tamDestino, 0);
				utn_getNumero(&auxViaje.idDestino, "Ingrese id del destino: \n",
						"Error reingrese id destino\n", 0, 99999, 3);

				printf("Ingrese fecha de viaje: \n");
				utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: \n",
						"Error Ingrese dia: \n", 0, 31, 4);
				utn_getNumero(&auxViaje.fecha.mes, "Ingrese mes: \n",
						"Error Ingrese mes: \n", 0, 12, 4);
				utn_getNumero(&auxViaje.fecha.anio, "Ingrese anio: \n",
						"Error Ingrese anio: \n", 0, 2999, 4);

				auxViaje.isEmpty = 0;
				vec[indice] = auxViaje;
				(*nextIdViaje)++;

			}



			auxViaje.isEmpty = 0;
			vec[indice] = auxViaje;
			(*nextIdViaje)++;

			todoOk = 1;
		}

	}
	return todoOk;
}

int mostrarViajes(eViaje viajes[], int tam, int clear) {
	int todoOk = 0;
	if (viajes != NULL && tam > 0 && clear >= 0 && clear <= 1) {

		if (clear) {
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de viajes    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     Viaje               |\n");
		printf("|-------------------------------------|\n");
		for (int i = 0; i < tam; i++) {
			if (viajes[i].isEmpty == 0) {

				printf("  %d  |  %20d\n", viajes[i].id, viajes[i].idMicro);
				printf("|-------------------------------------|\n");
			}
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;

}

int buscarViajeVacio(int *pIndice, eViaje vec[], int tam) {
	int todoOk = 0;
	int indice = -1;
	if (pIndice != NULL && vec != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty) {
				indice = i;
				break;
			}
		}
		*pIndice = indice;
		todoOk = 1;
	}
	return todoOk;
}

int inicializarViaje(eViaje vec[], int tam) {
	int todoOk = 0;
	if (vec != NULL && tam > 0) {
		for (int i = 4; i < tam; i++) {
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
