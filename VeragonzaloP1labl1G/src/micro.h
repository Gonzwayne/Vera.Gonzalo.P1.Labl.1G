

#ifndef MICRO_H_
#define MICRO_H_

#include "empresa.h"
#include "tipo.h"
#include "micro.h"
#include "chofer.h"



typedef struct {
	int id;
	int idEmpresa;
	int idTipo;
	int capacidad;
	int isEmpty;
	int idChofer;
} eMicro;

int inicializarMicro(eMicro vec[], int tam);
int altaMicro(int *nextId, eMicro vec[], int tam,eEmpresa vecEmpresa[], int tamEmp,eTipo vecTipos[], int tamTipo);
int buscarVacio(int *pIndice, eMicro vec[], int tam);
int modificarMicros(eMicro vec[], int tam,eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo,eChofer vecChofer[],int tamChofer);
int buscarMicro(int id, int *pIndice, eMicro vec[], int tam);
void mostrarMicro(eMicro a, eEmpresa listaEmpresa[], int tamEmp,eTipo listaTipo[], int tamTipo,eChofer listaChofer[],int tamChofer);
int mostrarMicros(eMicro vec[], int tam, eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo, int clear,eChofer vecChofer[],int tamChofer);
int bajaMicro(eMicro vec[], int tam, eEmpresa vecEmpresa[],int tamEmp,eTipo vecTipos[],int tamTipo,eChofer vecChofer[],int tamChofer);
int buscarLibre(int id,eMicro vec[],int tam);


#endif /* MICRO_H_ */
