

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct {
	int id;
	char descripcionDestino[25];
	int precio;
	int isEmpty;

} eDestino;

int mostrarDestinos(eDestino destinos[], int tam, int clear);

#endif /* DESTINO_H_ */


