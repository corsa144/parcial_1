/*
 * llamada.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef LLAMADA_H_
#define LLAMADA_H_
#define TEXT_SIZE 50
#define CUIT_SIZE 21
typedef struct{
	int idCliente;
	int isEmpty;
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	char nombreDeEmpresa[TEXT_SIZE];
	char cuit[CUIT_SIZE];

}eCliente;

typedef struct{
	int isEmpty;
	int idPedido;
	int idCliente;
	int estado;
	int tipo;
	int cantidadDeKilos;
	int cantidadPP;
	int cantidadHDPE;
	int cantidadLDPE;
}ePedido;

#endif /* LLAMADA_H_ */
int cliente_inicializar(eCliente clienteVector[], int size);
int pedido_inicializar(ePedido pedidoVector[], int size);
int cliente_buscarLibre(eCliente clienteVector[], int size, int* posicion);
int cliente_buscarId(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarId(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int pedido_buscarId(ePedido pedidoVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarInt(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarString(eCliente clienteVector[], int size, char* valorBuscado, int* indice);
int cliente_alta(eCliente clienteVector[], int size, int* contadorID);
int pedido_alta(ePedido pedidoVector[], int size, int* contadorIdPedido,eCliente clienteVector[],int sizeAsociado, int* contadorIdCliente);
int cliente_modificar(eCliente clienteVector[], int sizeArray);
int pedido_modificar(ePedido pedidoVector[], int sizeArray);
int cliente_baja(eCliente clienteVector[], int sizeArray);
int listarArray(ePedido pedidoVector[],int size);
int mostrarClientes(eCliente clienteVector[],int size,ePedido pedidoVector[],int sizePedido);
