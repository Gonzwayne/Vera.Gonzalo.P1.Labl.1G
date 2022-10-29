

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_




int menu();
int mostrarSubMenu();
int confirmarSalida(char *pControl);
int getString(char *pBuffer, int limite);
int isValidNombre(char *pBuffer, int limite);
int utn_getNombre(  char *pNombre, int limite, char *mensaje,char *mensajeError, int reintentos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int mostrarSubMenuInformes();





#endif /* MIBIBLIOTECA_H_ */

