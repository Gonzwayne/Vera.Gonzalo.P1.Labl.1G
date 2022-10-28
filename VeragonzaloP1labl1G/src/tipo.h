

#ifndef TIPO_H_
#define TIPO_H_


typedef struct {
	int id;
	char descripcionTipo[20];
	int isEmpty;

} eTipo;

int mostrarTipos(eTipo tipos[], int tam, int clear);
int asignarTipoPorId(eTipo listaTipo[], int tam, int idTipo,char descripcionTipo[]);

#endif


