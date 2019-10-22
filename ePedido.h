
#ifndef PEDIDO_H_

#define PEDIDO_H_

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

#endif

int pedido_inicializar(ePedido pedidoVector[], int size);
int pedido_buscarPorIdCliente(ePedido pedidoVector[], int size, int valorBuscado);
int pedido_buscarId(ePedido pedidoVector[], int size, int valorBuscado, int* posicion);
int pedido_alta(ePedido pedidoVector[], int size, int* contadorIdPedido,eCliente clienteVector[],int sizeAsociado, int* contadorIdCliente);
int pedido_modificar(ePedido pedidoVector[], int sizeArray);
int cargarCantidad(float cantidadTotal,float sumaDeCantidades,float* resultado);
int listarArrayPedido(ePedido pedidoVector[],int size);
int listarUnPedido(ePedido pedidoVector[],int size,int posicion);
int ordenar_porEntero(ePedido pedidoVector[],int size);
