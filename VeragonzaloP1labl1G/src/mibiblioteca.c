#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int inicializarMicro(eMicro vec[], int tam) {
int todoOk = 0;
if (vec != NULL && tam > 0) {
	for (int i = 0; i < tam; i++) {
		vec[i].isEmpty = 1;
	}
	todoOk = 1;
}
return todoOk;
}

int menu() {
int opcion;
system("cls");
printf("     *** ABM MICROS ***     \n\n");
printf("1-A- Alta de Micro\n");
printf("2-B- Modificar Micro\n");
printf("3-C- Baja de Micro\n");
printf("4-D- Listar Micros\n");
printf("5-E- Listas Empresas\n");
printf("6-F- Listas Tipos\n");
printf("7-G- Listar Destinos\n");
printf("8-H- Alta de Viaje\n");
printf("9-I- Listar Viajes\n");
printf("10-J- Salir\n");
printf("Ingrese una Opcion: \n");
scanf("%d", &opcion);
return opcion;
}

int altaMicro(int *nextId, eMicro vec[], int tam) {
	int todoOk = 0;
	int indice;
	eMicro auxMicro;
	if (nextId != NULL && vec != NULL && tam > 0) {
		buscarVacio(&indice, vec, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {
			auxMicro.id = *nextId;
			printf("Ingrese nombre de la empresa: \n");
			fflush(stdin);
			scanf("%d",auxMicro.Empresa);

			printf("Ingrese tipo de micro: \n");
			fflush(stdin);
			scanf("%d", &auxMicro.Tipo);

			printf("Ingrese capacidad del micro: \n");
			scanf("%d", &auxMicro.capacidad);


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



int modificarMicros(eMicro vec[], int tam) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 's';
	char auxCad[25];
	char tipo;
	int capacidad;

	if (vec != NULL && tam > 0) {
		system("cls");
		printf("            *** Modificar Micros ***         \n");

		mostrarMicros(vec, tam, 0);

		printf("Ingrese id del micro: \n");
		scanf("%d", &id);

		buscarMicro(id, &indice, vec, tam);

		if (indice == 1) {
			printf("No existe un micro con el id: %d\n", id);
		} else {
			mostrarMicro(vec[indice]);
			printf("Confirma modificacion?: \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {

				switch (mostrarSubMenu()) {
				case 1:
					printf("Ingrese Nombre de Empresa:\n");
					fflush(stdin);
					gets(auxCad);
					strcpy(vec[indice].Empresa, auxCad);
					break;
				case 2:
					printf("Ingrese el tipo de micro: \n");
					fflush(stdin);
					scanf("%c", &tipo);
					vec[indice].Tipo = tipo;
					break;
				case 3:
					printf("Ingrese la capacidad del micro: \n");
					scanf("%d", &capacidad);
					vec[indice].capacidad = capacidad;
					break;
				case 4:
					printf("salir");

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

int mostrarSubMenu() {
	int opcion;
	system("cls");
	printf("     *** Seleccione opcion a modificar ***     \n\n");
	printf("1- empresa\n");
	printf("2- tipo de micro\n");
	printf("3- capacidad\n");
	printf("4- Salir\n");
	printf("Ingrese Opcion: \n");
	scanf("%d", &opcion);
	return opcion;
}

int buscarMicro(int id, int *pIndice, eMicro vec[], int tam) {
	int todoOk = 0;
	int indice = -1;
	if (pIndice != NULL && vec != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty ==0 && vec[i].id == id) {
				indice = i;
				break;
			}
		}
		*pIndice = indice;
		todoOk = 1;
	}
	return todoOk;

}

void mostrarMicro(eMicro a) {
	printf("id %d\nEmpresa: %c\nTipo: %c\ncapacidad: \n",
			a.id, a.Empresa, a.Tipo, a.capacidad);
}

int mostrarMicros(eMicro vec[], int tam, int clear) {
	int todoOk = 0;
	int flag;
	if (vec != NULL && tam > 0 && clear >=0 && clear <= 1) {
		if (clear) {
			system("cls");
		}
		printf("            *** Lista de Micros ***         \n");
		printf(
				"-------------------------------------------------------------\n");
		printf("   ip      Empresa       Tipo       Capacidad                 \n");
		printf(
				"-------------------------------------------------------------\n");

		for (int i = 0; i < tam; i++) {
			if (vec[i].isEmpty == 0) {
				printf(
						"%d       %-10c     %c          %d                    \n",
						vec[i].id, vec[i].Empresa, vec[i].Tipo, vec[i].capacidad);
				printf("---------------------------------------------------------\n");
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

int bajaMicro(eMicro vec[], int tam) {
	int todoOk = 0;
	int id;
	int indice;
	char confirma = 's';
	if (vec != NULL && tam > 0) {
		system("cls");
		printf("            *** Baja de Micro ***         \n");

		mostrarMicros(vec, tam, 0);

		printf("Ingrese id : \n");
		scanf("%d", &id);

		buscarMicro(id, &indice, vec, tam);

		if (indice == -1) {
			printf("No existe un micro con el id: %d\n", id);
		} else {
			mostrarMicro(vec[indice]);
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


int mostrarEmpresas(eEmpresa empresas[], int tam, int clear){
	int todoOk = 0;
	if (empresas!=  NULL && tam >0 && clear >= 0 && clear <= 1){

		if (clear){
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de empresas    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     nombre                |\n");
		printf("|-------------------------------------|\n");
		for(int i=0; i< tam ; i++){

		printf("  %d  |  %20s\n", empresas[i].id,empresas[i].descripcionEmpresa);
		printf("|-------------------------------------|\n");
		}
		printf("\n\n");
		todoOk =1;
	}
	return todoOk;

}

int mostrarTipos(eTipo tipos[], int tam, int clear){
	int todoOk = 0;
	if (tipos!=  NULL && tam >0 && clear >= 0 && clear <= 1){

		if (clear){
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de tipos    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     tipo               |\n");
		printf("|-------------------------------------|\n");
		for(int i=0; i< tam ; i++){

		printf("  %d  |  %20s\n", tipos[i].id,tipos[i].descripcionTipo);
		printf("|-------------------------------------|\n");
		}
		printf("\n\n");
		todoOk =1;
	}
	return todoOk;

}

int mostrarDestinos(eDestino destinos[], int tam, int clear){
	int todoOk = 0;
	if (destinos!=  NULL && tam >0 && clear >= 0 && clear <= 1){

		if (clear){
			system("cls");
		}
		printf("---------------------------------------\n");
		printf("|  ++++   Lista de destinos    ++++   |\n");
		printf("---------------------------------------\n");
		printf("| id      |     destino              |\n");
		printf("|-------------------------------------|\n");
		for(int i=0; i< tam ; i++){

		printf("  %d  |  %20s\n", destinos[i].id,destinos[i].descripcionDestino);
		printf("|-------------------------------------|\n");
		}
		printf("\n\n");
		todoOk =1;
	}
	return todoOk;

}

int confirmarSalida(char *pControl) {
	int todoOk = 0;
	char confirma;
	if (pControl != NULL) {
		printf("confirmar salir ingrese s o n?\n");
		fflush(stdin);
		scanf("%c", &confirma);
		if (confirma == 's') {
			*pControl = 's';
		}
		todoOk = 1;

	}
	return todoOk;

}

