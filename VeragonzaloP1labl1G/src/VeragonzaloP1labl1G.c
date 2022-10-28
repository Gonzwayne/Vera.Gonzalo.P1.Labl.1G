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



#define TAM 10
#define TAM_C 4
#define TAMEMP 4
#define TAMTIPO 4
#define TAMVIAJE 10
#define TAMDESTINO 4

int main(void) {

	setbuf(stdout, NULL);
	int nextId = 104;
	int nextIdViaje = 2000;
	char seguir = 'n' ;



	eViaje listaViajes[TAMVIAJE] = { {2000,150,20000,{20,12,2022},0 },
								{2002,155,20001,{20,12,2022},0 },
								{2005,155,20001,{20,12,2022},0 },
								{2003,135,20002,{20,12,2022},0 },};

	eEmpresa listaEmpresas[TAMEMP] = { { 1000, "Plusmar" }, { 1001, "FlechaBus" }, {
			1002, "Tas" }, { 1003, "El Rapido" },};

	eTipo listaTipos[TAMTIPO] = { { 5000, "Comun" }, { 5001, "CocheCama" }, { 5002,
			"DobleCama" }, { 5003, "Vip" }, };

	eDestino listaDestinos[TAMDESTINO] = { { 20000, "Calafate: $22250" }, { 20001,
			"Bariloche: $103000" }, { 20002, "Salta: $84400" }, { 20003,
			"Mendoza: $95600)" }, };

	eMicro listaMicros[TAM] ={{100,1000,5000,30,0},
						{101,1001,5001,35,0},
						{102,1002,5002,40,0},
						{103,1003,5003,45,0},};

	inicializarMicro(listaMicros, TAM);
	inicializarViaje(listaViajes, TAMVIAJE);

	do {
		switch (menu()) {
		case 1:
			if (altaMicro(&nextId, listaMicros, TAM,listaEmpresas,TAMEMP,listaTipos,TAMTIPO)) {
				printf("Alta exitosa \n");
			} else {
				printf("No se pudo dar de alta \n");
			}
			break;
		case 2:
			mostrarMicros(listaMicros, TAM,listaEmpresas,TAMEMP, listaTipos,TAMTIPO,0);
			modificarMicros(listaMicros, TAM,listaEmpresas,TAMEMP,listaTipos,TAMTIPO);

			break;
		case 3:
			bajaMicro(listaMicros, TAM,listaEmpresas,TAMEMP,listaTipos,TAMTIPO);
			break;
		case 4:
			mostrarMicros(listaMicros, TAM,listaEmpresas,TAMEMP, listaTipos,TAMTIPO,0);
			break;
		case 5:
			mostrarEmpresas(listaEmpresas, TAMEMP, 0);

			break;
		case 6:
			mostrarTipos(listaTipos, TAMTIPO, 0);
			break;
		case 7:
			mostrarDestinos(listaDestinos, TAMDESTINO, 0);

			break;
		case 8:
			altaViaje(&nextIdViaje, listaViajes,  TAMVIAJE,listaEmpresas,TAMEMP,listaTipos,TAMTIPO,listaMicros,TAM,listaDestinos,TAMDESTINO);
			break;
		case 9:
			mostrarViajes(listaViajes,TAM,0);
			break;
		case 10:
			printf("Usted ingreso opcion 10 salir\n");
			confirmarSalida(&seguir);
			if (seguir == 's') {
			 printf("Usted salio del programa, Hasta pronto\n");
			}
			else
			{	printf("Usted continua en el programa\n");
			}
			break;
		default:
			printf("No es una opcion valida");
			break;
		}
		system("pause");
	} while (seguir == 'n');

	return 0;
}



