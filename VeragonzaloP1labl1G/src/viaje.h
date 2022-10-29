

#ifndef VIAJE_H_
#define VIAJE_H_

#include "fecha.h"






typedef struct {
	int id;
	int idMicro;
	int idDestino;
	eFecha fecha;
	int isEmpty;

} eViaje;

int buscarViaje(int id, int *pIndice, eViaje vec[], int tam);
int altaViaje(int *nextIdViaje, eViaje vec[], int tam,eEmpresa listaEmpresas[],int tamEmp,eTipo listaTipos[],int tamTipo,eMicro listaMicros[],int tamMicros,eDestino listaDestinos[], int tamDestino,eChofer listaChofer[],int tamChofer);
int mostrarViajes(eViaje viajes[], int tam, int clear);
int buscarViajeVacio(int *pIndice, eViaje vec[], int tam);
int inicializarViaje(eViaje vec[], int tam);



#endif /* VIAJE_H_ */

