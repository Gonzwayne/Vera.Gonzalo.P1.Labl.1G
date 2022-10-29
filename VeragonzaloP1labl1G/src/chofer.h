

#ifndef CHOFER_H_
#define CHOFER_H_

typedef struct {
	int id;
	char nombre[20];
	char sexo;

} eChofer;

int asignarChoferPorId(eChofer listaChofer[], int tamChofer, int idChofer,char nombre[]);


#endif /* CHOFER_H_ */
