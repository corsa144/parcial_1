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
	float cantidadDeKilos;
	float cantidadPP;
	float cantidadHDPE;
	float cantidadLDPE;
}ePedido;

#endif /* LLAMADA_H_ */
int cliente_inicializar(eCliente clienteVector[], int size);
int pedido_inicializar(ePedido pedidoVector[], int size);
int cliente_buscarLibre(eCliente clienteVector[], int size, int* posicion);
int cliente_buscarId(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int pedido_buscarPorIdCliente(ePedido pedidoVector[], int size, int valorBuscado);
int pedido_buscarId(ePedido pedidoVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarInt(eCliente clienteVector[], int size, int valorBuscado, int* posicion);
int cliente_buscarString(eCliente clienteVector[], int size, char* valorBuscado, int* indice);
int cliente_alta(eCliente clienteVector[], int size, int* contadorIdCliente);
int pedido_alta(ePedido pedidoVector[], int size, int* contadorIdPedido,eCliente clienteVector[],int sizeAsociado, int* contadorIdCliente);
int cliente_modificar(eCliente clienteVector[], int sizeArray);
int pedido_modificar(ePedido pedidoVector[], int sizeArray);
int cargarCantidad(float cantidadTotal,float sumaDeCantidades,float* resultado);
int cliente_baja(eCliente clienteVector[], int sizeArray);
int listarArray(ePedido pedidoVector[],eCliente clienteVector[],int size,int sizeCliente);
int listarArrayCliente(eCliente clienteVector[],int size);
int listarArrayPedido(ePedido pedidoVector[],int size);
int listarUnCliente(eCliente clienteVector[],int posicion);
int listarUnPedido(ePedido pedidoVector[],int size,int posicion);
int listar_pedidosPorEstado(eCliente clienteVector[],ePedido pedidoVector[], int sizeCliente,int sizePedido,int estado);
int ordenar_porEntero(ePedido pedidoVector[],int size);
int ordenar_porString(eCliente clienteVector[],int size);
int ordenamiento_insercionEntero (ePedido pedidoVector[], int size);
int busca_valorMinimo(ePedido pedidoVector[],int size,float* valorBuscado);
int busca_valorMaximo(ePedido pedidoVector[],int size,float* valorBuscadoMax);
int busca_cliente(ePedido pedidoVector[],int size,int* clienteId);
void listaClienteCon_masPedidos(ePedido pedidoVector[],int size,int* clienteId,eCliente clienteVector[],int sizeCliente,int* posicion);
void listaClienteCon_masPedidosPendientes(ePedido pedidoVector[],int size,int* clienteId,eCliente clienteVector[],int sizeCliente,int* posicion);
void listaClienteCon_masPedidosCumplidos(ePedido pedidoVector[],int size,int* idCliente,eCliente clienteVector[],int sizeCliente,int* posicion);
int busca_clienteConMasKilos(ePedido pedidoVector[],int size, int* idCliente, float* auxCantidad);
void listaClienteCon_masKilosPedidos(ePedido pedidoVector[],int size,int* clienteId,
		eCliente clienteVector[],int sizeCliente,int* posicion,float* cantidadDeKilosMax);
