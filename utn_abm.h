/*
 * llamada.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_

#define CLIENTE_H_
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


#endif
int cliente_inicializar(eCliente clienteVector[], int size);
int cliente_buscarLibre(eCliente clienteVector[], int size, int* posicion);
int cliente_buscarId(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarInt(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarString(eCliente clienteVector[], int size, char* valorBuscado, int* indice);
int cliente_alta(eCliente clienteVector[], int size, int* contadorIdCliente);
int cliente_modificar(eCliente clienteVector[], int sizeArray);
int cliente_baja(eCliente clienteVector[], int sizeArray);
int listarArrayCliente(eCliente clienteVector[],int size);
int listarUnCliente(eCliente clienteVector[],int posicion);
//int ordenar_porString(eCliente clienteVector[],int size);
//int ordenamiento_insercionEntero (ePedido pedidoVector[], int size);
//int busca_valorMinimo(ePedido pedidoVector[],int size,float* valorBuscado);
//int busca_valorMaximo(ePedido pedidoVector[],int size,float* valorBuscadoMax);

