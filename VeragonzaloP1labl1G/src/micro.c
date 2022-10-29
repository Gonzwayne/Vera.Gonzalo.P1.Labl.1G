#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "empresa.h"
#include "tipo.h"
#include "micro.h"
#include  "chofer.h"


int inicializarMicro(eMicro vec[], int tam) {
	int todoOk = 0;
	if (vec != NULL && tam > 0) {
		for (int i = 4; i < tam; i++) {
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int altaMicro(int *nextId, eMicro vec[], int tam, eEmpresa vecEmpresa[],
		int tamEmp, eTipo vecTipos[], int tamTipo) {
	int todoOk = 0;
	int indice;
	eMicro auxMicro;
	if (nextId != NULL && vec != NULL && tam > 0) {
		buscarVacio(&indice, vec, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {
			auxMicro.id = *nextId;

			mostrarEmpresas(vecEmpresa, tamEmp, 0);
			utn_getNumero(&auxMicro.idEmpresa, "Ingrese id de la empresa \n",
					"Error reingrese id de la empresa \n", 1000, 1003, 3);

			mostrarTipos(vecTipos, tamTipo, 0);
			utn_getNumero(&auxMicro.idTipo, "Ingrese id tipo de micro: \n",
					"Error reingrese id tipo de micro\n", 5000, 5003, 3);

			utn_getNumero(&auxMicro.capacidad,
					"Ingrese capacidad del micro: maximo 50\n",
					"Error reingrese capacidad del micro\n", 1, 50, 3);

			auxMicro.isEmpty = 0;
			vec[indice] = auxMicro;
			(*nextId)++;

			todoOk = 1;
		}

	}
	return todoOk;
}

int buscarVacio(int *pIndice, eMicro vec[], int tam) {
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

int modificarMicros(eMicro vec[], int tam, eEmpresa vecEmpresa[], int tamEmp,
		eTipo vecTipos[], int tamTipo,eChofer vecChofer[],int tamChofer) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 's';

	if (vec != NULL && tam > 0 && vecEmpresa != NULL && tamEmp > 0
			&& vecTipos != NULL && tamTipo > 0) {
		system("cls");
		printf("            *** Modificar Micros ***         \n");

		utn_getNumero(&id, "Ingrese id del micro: \n",
				"Error reingrese id del micro: \n", 150, 200, 3);

		indice = buscarLibre(id, vec, tam);

		if (indice == -1) {
			printf("No existe un micro con el id: %d\n", id);
		} else {
			mostrarMicro(vec[indice], vecEmpresa, tamEmp, vecTipos, tamTipo,vecChofer,tamChofer);
			void mostrar(eMicro a, eEmpresa listaEmpresa[], int tamEmp,eTipo listaTipo[], int tamTipo,eChofer listaChofer[],int tamChofer);
			printf("Confirma modificacion? :ingrese (s o n) \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {

				switch (mostrarSubMenu()) {
				case 1:
					mostrarTipos(vecTipos, tamTipo, 0);
					utn_getNumero(&vec[indice].idTipo,
							"Ingrese id tipo de micro: \n",
							"Error reingrese id tipo de micro\n", 5000, 5003,
							3);
					break;
				case 2:
					utn_getNumero(&vec[indice].capacidad,
							"Ingrese capacidad del micro: \n",
							"Error reingrese capacidad del micro\n", 1, 50, 3);
					break;
				default:
					printf("No es una opcion valida\n");
					break;
				}

				todoOk = 1;
			} else {
				printf("Modificacion cancelada por el usuario\n");
			}
		}
	}

	return todoOk;
}

int buscarMicro(int id, int *pIndice, eMicro vec[], int tam) {
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

void mostrarMicro(eMicro a, eEmpresa listaEmpresa[], int tamEmp,eTipo listaTipo[], int tamTipo,eChofer listaChofer[],int tamChofer) {
	char descEmp[50];
	char descTip[50];
	char descCho[50];
	asignarEmpresaPorId(listaEmpresa, tamEmp, a.idEmpresa, descEmp);
	asignarTipoPorId(listaTipo, tamTipo, a.idTipo, descTip);
	asignarChoferPorId(listaChofer, tamChofer, a.idChofer, descCho);
	printf("  %d        %s         %s         %d       %s \n", a.id, descEmp, descTip,
			a.capacidad,descCho);
}

int mostrarMicros(eMicro vec[], int tam, eEmpresa vecEmpresa[], int tamEmp,eTipo vecTipos[], int tamTipo, int clear,eChofer vecChofer[],int tamChofer) {
	int todoOk = 0;
	int flag = 1;
	if (vec != NULL && tam > 0 && clear >= 0 && clear <= 1) {
		if (clear) {
			system("cls");
		}
		printf("            *** Lista de Micros ***         \n");
		printf(
				"-------------------------------------------------------------\n");
		printf(
				"   id      Empresa       Tipo       Capacidad        chofer  \n");
		printf(
				"-------------------------------------------------------------\n");

		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty == 0) {
				mostrarMicro(vec[i], vecEmpresa, tamEmp, vecTipos, tamTipo,vecChofer,tamChofer);
				flag = 0;

			}
		}
		if (flag) {
			printf("No hay micros para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;

}

int bajaMicro(eMicro vec[], int tam, eEmpresa vecEmpresa[], int tamEmp,
		eTipo vecTipos[], int tamTipo,eChofer vecChofer[],int tamChofer) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 's';
	if (vec != NULL && tam > 0) {
		system("cls");
		printf("            *** Baja de Micro ***         \n");

		mostrarMicros(vec, tam, vecEmpresa, tamEmp, vecTipos, tamTipo, 0,vecChofer,tamChofer);

		utn_getNumero(&id, "Ingrese id : \n", "ERROR Ingrese id : \n", 1, 99999,
				3);

		buscarMicro(id, &indice, vec, tam);

		if (indice == -1) {
			printf("No existe un micro con el id: %d\n", id);
		} else {
			mostrarMicro(vec[indice], vecEmpresa, tamEmp, vecTipos, tamTipo,vecChofer,tamChofer);
			printf("Confirma Baja?: \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				vec[indice].isEmpty = 1;
				printf("Baja exitosa\n");
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario\n");
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(int id, eMicro vec[], int tam) {
	int libre = -1;
	if (vec != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty == 0 && vec[i].id == id) {
				libre = i;
			}
		}
	}
	return libre;
}
