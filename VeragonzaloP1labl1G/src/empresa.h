

#ifndef EMPRESA_H_
#define EMPRESA_H_


typedef struct {
	int id;
	char descripcionEmpresa[20];
	int isEmpty;

} eEmpresa;

int mostrarEmpresas(eEmpresa empresas[], int tam, int clear);
int asignarEmpresaPorId(eEmpresa listaEmpresa[],int tam, int idEmpresa, char descripcionEmpresa[]);
#endif /* EMPRESA_H_ */


