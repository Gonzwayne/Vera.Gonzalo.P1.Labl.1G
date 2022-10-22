
#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

typedef struct {
	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct {
	int id;
	char descripcionEmpresa[20];

} eEmpresa;

typedef struct {
	int id;
	char descripcionTipo[20];

} eTipo;

typedef struct {
	int id;
	char Empresa;
	char Tipo;
	int capacidad;
	int isEmpty;
} eMicro;

typedef struct {
	int id;
	char descripcionDestino[25];
	int precio;

} eDestino;

typedef struct {
	int id;
	eMicro idMicro;
	eDestino idDestino;
	int fecha;

} eViaje;


#endif /* MIBIBLIOTECA_H_ */
int menu();
int mostrarSubMenu();
int inicializarMicro(eMicro vec[], int tam);
int altaMicro(int *nextId, eMicro vec[], int tam);
int buscarVacio(int *pIndice, eMicro vec[], int tam);
int modificarMicros(eMicro vec[], int tam);
int buscarMicro(int id, int *pIndice, eMicro vec[], int tam);
void mostrarMicro(eMicro a);
int mostrarMicros(eMicro vec[], int tam, int clear);
int mostrarEmpresas(eEmpresa empresas[], int tam, int clear);
int bajaMicro(eMicro vec[], int tam);
int mostrarTipos(eTipo tipos[], int tam, int clear);
int mostrarDestinos(eDestino destinos[], int tam, int clear);
int confirmarSalida(char *pControl);
