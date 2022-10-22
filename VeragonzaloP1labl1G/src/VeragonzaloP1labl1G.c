
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 4
#define TAM_C 4





int main(void) {

	setbuf(stdout, NULL);
	int nextId = 1000;
	char seguir = 's';

	eMicro lista[TAM];
	eEmpresa Empresas[TAM_C] = { { 1000, "Plusmar" }, { 1001, "FlechaBus" },
			{ 1002, "Tas" }, { 1003, "El Rapido" },

	};

	eTipo Tipos[TAM_C] = { { 5000, "Comun" }, { 5001, "CocheCama" }, {
			5002, "DobleCama" }, { 5003, "Vip" }, };

	eDestino Destinos[TAM_C] = { { 20000, "Calafate: $22250" }, { 20001,
			"Bariloche: $103000" }, { 20002, "Salta: $84400" }, { 20003,
			"Mendoza: $95600)" }, };

	inicializarMicro(lista, TAM);


	do {
		switch (menu()) {
		case 1:
			if (altaMicro(&nextId, lista, TAM)) {
			printf("Alta exitosa \n");
			} else {
			printf("No se pudo dar de alta \n");
			}
			break;
		case 2:
			modificarMicros(lista, TAM);

			break;
		case 3:
			 bajaMicro(lista, TAM);
			break;
		case 4:
				mostrarMicros(lista, TAM, 1);
			break;
		case 5:
			mostrarEmpresas(Empresas, TAM_C, 1);

			break;
		case 6:
			mostrarTipos(Tipos, TAM_C, 1);
			break;
		case 7:
			mostrarDestinos(Destinos, TAM_C, 1);

			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
						printf("Usted ingreso opcion 5 salir\n");
						confirmarSalida(&seguir);
						if (seguir == 's') {
						printf("Usted salio del programa, Hasta pronto\n");}
			break;
		default:
			printf("Opcion Invalida!!!\n");
			break;
		}
		system("pause");
	} while (seguir == 's');

	return 0;
}



