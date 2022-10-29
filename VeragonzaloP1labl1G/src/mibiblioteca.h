

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_



/// @fn int menu()
/// @brief muestra un menu de opciones
///
/// @return devuelve la opcion seleccionada
int menu();
/// @fn int mostrarSubMenu()
/// @brief muestra un menu de opciones
///
/// @return devuelve la opcion seleccionada
int mostrarSubMenu();
/// @fn int confirmarSalida(char*)
/// @brief confirma con una pregunta si quieres salir o no
///
/// @param pControl recibe un caracter s o n
/// @return el caracter seleccionado
int confirmarSalida(char *pControl);
/// @fn int getString(char*, int)
/// @brief El usuario ingresa una cadena con fgets
///
/// @param pBuffer Recibe el texto ingresado en caso de exito
/// @param limite Es el tamano maximo del string
/// @return En caso de exito retorna 0, si no -1
int getString(char *pBuffer, int limite);
/// @fn int isValidNombre(char*, int)
/// @brief Evalua si es un nombre, solo puede tener un espacio
///
/// @param pBuffer Es la cadena que evaluamos
/// @param limite Es el tamano maximo del string
/// @returnEn caso de exito retorna 1, si no 0
int isValidNombre(char *pBuffer, int limite);
/// @fn int utn_getNombre(char*, int, char*, char*, int)
/// @brief Toma una cadena y evalua si es un nombre, solo puede tener un espacio
///
/// @param pNombre Recibe el texto ingresado en caso de exito
/// @param limite Es el tamano maximo del string
/// @param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
/// @param mensajeError  Es el mensaje que se muestra en caso de error
/// @param reintentos Veces que el usuario podra volver a introducir el dato
/// @return En caso de exito retorna 0, si no -1
int utn_getNombre(  char *pNombre, int limite, char *mensaje,char *mensajeError, int reintentos);
/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
/// @fn int mostrarSubMenuInformes()
/// @brief muestra un submenu de opciones
///
/// @return devuelve la opcion int seleccionada
int mostrarSubMenuInformes();





#endif /* MIBIBLIOTECA_H_ */

