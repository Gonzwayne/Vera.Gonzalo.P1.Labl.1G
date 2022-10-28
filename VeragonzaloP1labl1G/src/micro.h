

#ifndef MICRO_H_
#define MICRO_H_

#include "empresa.h"
#include "tipo.h"
#include "micro.h"



typedef struct {
	int id;
	int idEmpresa;
	int idTipo;
	int capacidad;
	int isEmpty;
} eMicro;

int inicializarMicro(eMicro vec[], int tam);
int altaMicro(int *nextId, eMicro vec[], int tam,eEmpresa vecEmpresa[], int tamEmp,eTipo vecTipos[], int tamTipo);
int buscarVacio(int *pIndice, eMicro vec[], int tam);
int modificarMicros(eMicro vec[], int tam,eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo);
int buscarMicro(int id, int *pIndice, eMicro vec[], int tam);
void mostrarMicro(eMicro a,eEmpresa listaEmpresa[],int tamEmp,eTipo listaTipo[],int tamTipo);
int mostrarMicros(eMicro vec[], int tam, eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo, int clear);
int bajaMicro(eMicro vec[], int tam, eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo);
int buscarLibre(int id,eMicro vec[],int tam);


#endif /* MICRO_H_ */
