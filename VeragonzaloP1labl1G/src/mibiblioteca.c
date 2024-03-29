#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mibiblioteca.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "destino.h"
#include "viaje.h"
#include "fecha.h"


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
	printf("11-K- Menu de Informes\n");
	utn_getNumero(&opcion, "Ingrese una opcion: \n",
			"Error reingrese opcion valida: \n", 1, 11, 100);
	return opcion;
}

int mostrarSubMenu() {
	int opcion;
	system("cls");
	printf("     *** Seleccione opcion a modificar ***     \n\n");
	printf("1- tipo de micro\n");
	printf("2- capacidad\n");
	fflush(stdin);
	utn_getNumero(&opcion, "Ingrese Opcion: \n",
			"Error Ingrese Opcion valida: \n", 1, 3, 4);
	return opcion;
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

int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;

}

int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer); // cambiar a atof
			retorno = 0;
		}

	}
	return retorno;
}

int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) < 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9'/* || cadena[i] != ','*/) // para flotante, contar las comas y que me ermita una sola
					{
				retorno = 0;
				break;
			}
			i++;

		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getNombre(char *pNombre, int limite, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -1;
	char buffer[4096];
	if (pNombre != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			reintentos--;
			printf("\n%s", mensaje);
			if (getString(buffer, limite) == 0
					&& isValidNombre(buffer, limite)) {
				strncpy(pNombre, buffer, limite);
				retorno = 0;
				break;
			} else {
				printf("\n%s", mensajeError);
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int isValidNombre(char *pBuffer, int limite) {
	int retorno = 0;
	if (pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0
			&& ((pBuffer[0] >= 'A' && pBuffer[0] <= 'Z')
					|| (pBuffer[0] >= 'a' && pBuffer[0] <= 'z')))

			{
		retorno = 1;
	}
	return retorno;
}

int getString(char *pBuffer, int limite) {
	int retorno = -1;
	int len;
	char bufferString[4096];
	if (pBuffer != NULL && limite > 0) {
		fflush(stdin);
		fgets(bufferString, 4096, stdin);
		len = strlen(bufferString);
		if (len <= limite) {
			if (len != limite - 1 || bufferString[limite - 2] == '\n') {
				bufferString[len - 1] = '\0';
			}
			strncpy(pBuffer, bufferString, limite);
			retorno = 0;
		} else {
			printf("Se admite un maximo de %d caracteres\n", limite - 1);
		}
	}
	return retorno;
}


int mostrarSubMenuInformes() {
	int opcion;
	system("cls");
	printf("     *** Seleccione opcion a informar ***     \n\n");
	printf("1- Mostrar Micros de la Empresa Seleccionada\n");
	printf("2- Mostrar Micros de un tipo seleccionado\n");
	printf("3- Informar Promedios de micros de tipo VIP sobre micros de una empresa\n");
	printf("4- Mostrar listado de micros separados por empresa\n");
	printf("5- Informar empresas que pueden transportar mas pasajeros\n");
	printf("6- Mostrar empresa con menor cantidad de Micros\n");
	fflush(stdin);
	utn_getNumero(&opcion, "Ingrese Opcion: \n",
			"Error Ingrese Opcion valida: \n", 1, 6, 4);
	return opcion;
}







