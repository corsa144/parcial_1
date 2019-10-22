

int listarArray(ePedido pedidoVector[],eCliente clienteVector[],int size,int sizeCliente);
int listar_pedidosPorEstado(eCliente clienteVector[],ePedido pedidoVector[], int sizeCliente,int sizePedido,int estado);


int busca_cliente(ePedido pedidoVector[],int size,int* clienteId);
void listaClienteCon_masPedidos(ePedido pedidoVector[],int size,int* clienteId,eCliente clienteVector[],int sizeCliente,int* posicion);
void listaClienteCon_masPedidosPendientes(ePedido pedidoVector[],int size,int* clienteId,eCliente clienteVector[],int sizeCliente,int* posicion);
void listaClienteCon_masPedidosCumplidos(ePedido pedidoVector[],int size,int* idCliente,eCliente clienteVector[],int sizeCliente,int* posicion);
int busca_clienteConMasKilos(ePedido pedidoVector[],int size, int* idCliente, float* auxCantidad);
void listaClienteCon_masKilosPedidos(ePedido pedidoVector[],int size,int* clienteId,
eCliente clienteVector[],int sizeCliente,int* posicion,float* cantidadDeKilosMax);
int busca_clienteConMenosKilos(ePedido pedidoVector[],int size, int* idCliente,
		float* acumuladorMinCantKilos);
void listaClienteCon_menosKilosPedidos(ePedido pedidoVector[],int size,int* clienteId,
		eCliente clienteVector[],int sizeCliente,int* posicion,float* cantidadDeKilosMin);
int cantidad_clientesConMasDeMilKilosReciclados(ePedido pedidoVector[],int size,float limitMax);
int cantidad_clientesConMenosDeCienlKilosReciclados(ePedido pedidoVector[],int size,float limitMin);
int listar_pedidosPorCompletados(eCliente clienteVector[],ePedido pedidoVector[], int sizeCliente,int sizePedido,int estado);
int listarIdYKilos(ePedido pedidoVector[],int size,int posicion,int estado);
int listarCuitCliente(eCliente clienteVector[],int posicion);
int listarPorLocalidad(eCliente clienteVector[],int size, ePedido pedidoVector[],int sizePedido,int estado);
int promedio_ppPorCliente(ePedido pedidoVector[],int size,eCliente clienteVector[],int sizeCliente);
int listarPorCuitYTipo(eCliente clienteVector[],int size, ePedido pedidoVector[],int sizePedido,int estado);
