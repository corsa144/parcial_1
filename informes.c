#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_abm.h"
#include "ePedido.h"
#include "informes.h"
/**\brief lista clientes con sus pedidos en estado pendiente
 * param estructura pedido
 * param estructura cliente
 * param tamaño pedido
 * param tamaño cliente
 * retorno retorna 0 en caso de que este ok y -1 en caso de error
 */

int listarArray(ePedido pedidoVector[],eCliente clienteVector[],int size,int sizeCliente)
{

	int retorno=-1;
	int i;
	if(clienteVector!=NULL&&size>0)
	{
		for(i=0;i<sizeCliente;i++)
		{
			if(clienteVector[i].isEmpty==0)
			{
			printf("\n***************************************\n"
					"El cliente es\nid de cliente: %d \n"
					" nombre de la emprersa:%s\ndireccion:%s\n"
					"localidad:%s\n"
					"cuit:%s\n ",clienteVector[i].idCliente,clienteVector[i].nombreDeEmpresa,
					clienteVector[i].direccion,clienteVector[i].localidad,clienteVector[i].cuit);
			 pedido_buscarPorIdCliente(pedidoVector, size, clienteVector[i].idCliente);
			}
			retorno=0;
		}
	}
	return retorno;
}

int listar_pedidosPorEstado(eCliente clienteVector[],ePedido pedidoVector[], int sizeCliente,int sizePedido,int estado)
{
	int retorno=-1;
	int i;
	int auxPosicion;

	if(clienteVector!=NULL&&pedidoVector!=NULL&&sizeCliente>0 && sizePedido>0)
	{
		for(i=0;i<sizePedido;i++)
		{
			if(pedidoVector[i].estado==estado)
			{
				listarUnPedido(pedidoVector,sizePedido,i);
				cliente_buscarId(clienteVector,sizeCliente,pedidoVector[i].idCliente,&auxPosicion);
				listarUnCliente(clienteVector,auxPosicion);
				printf("\n********************************\n");
				retorno=0;
			}
		}
	}
	return retorno;
}

int busca_cliente(ePedido pedidoVector[],int size,int* clienteId)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	int contadorCliente=0;
	int contadorMaxCantPedidos=0;
	int idClienteMax=0;

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0)
			{
				ultimoIdCliente=pedidoVector[i].idCliente;
				contadorCliente=0;
			}
			contadorCliente++;
			if(contadorCliente>contadorMaxCantPedidos)
			{
				contadorMaxCantPedidos=contadorCliente;
				idClienteMax=ultimoIdCliente;
			}
		}
		(*clienteId)=idClienteMax;
		printf("el id de cliente es:%d",(*clienteId));
	}
	return retorno;
}

void listaClienteCon_masPedidos(ePedido pedidoVector[],int size,int* clienteId,eCliente clienteVector[],int sizeCliente,int* posicion)
{
	busca_cliente(pedidoVector,size,clienteId);
	cliente_buscarId(clienteVector,sizeCliente, (*clienteId), posicion);
	listarUnCliente(clienteVector,(*posicion));
}

int busca_clienteConMasPendientes(ePedido pedidoVector[],int size, int valorBuscado, int* idCliente)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	int contadorCliente=0;
	int contadorMaxCantPedidos=0;
	int idClienteMax=0;

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==valorBuscado)
			{
				ultimoIdCliente=pedidoVector[i].idCliente;
				contadorCliente=0;
			}
			contadorCliente++;
			if(contadorCliente>contadorMaxCantPedidos)
			{
				contadorMaxCantPedidos=contadorCliente;
				idClienteMax=ultimoIdCliente;
			}
		}
		(*idCliente)=idClienteMax;
		printf("el id de cliente es:%d",(*idCliente));
	}
	return retorno;
}
void listaClienteCon_masPedidosPendientes(ePedido pedidoVector[],int size,int* idCliente,eCliente clienteVector[],int sizeCliente,int* posicion)
{
	busca_clienteConMasPendientes(pedidoVector,size,1,idCliente);
	cliente_buscarId(clienteVector,sizeCliente, (*idCliente), posicion);
	listarUnCliente(clienteVector,(*posicion));
}

void listaClienteCon_masPedidosCumplidos(ePedido pedidoVector[],int size,int* idCliente,eCliente clienteVector[],int sizeCliente,int* posicion)
{
	busca_clienteConMasPendientes(pedidoVector,size,2,idCliente);
	cliente_buscarId(clienteVector,sizeCliente, (*idCliente), posicion);
	listarUnCliente(clienteVector,(*posicion));
}
int busca_clienteConMasKilos(ePedido pedidoVector[],int size, int* idCliente,
		float* acumuladorMaxCantKilos)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	float auxCantidad=0;
	int idClienteMax=0;
	float kilosAux=0;
	(*acumuladorMaxCantKilos)=0;
	//ePedido auxVector[size];

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{

			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0)
			{
				ultimoIdCliente=pedidoVector[i].idCliente;
				auxCantidad=0;
			}
			if(pedidoVector[i].idCliente==ultimoIdCliente &&
					pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==2)
			{
				kilosAux=pedidoVector[i].cantidadHDPE+pedidoVector[i].cantidadLDPE
						+pedidoVector[i].cantidadPP;
				auxCantidad=kilosAux+auxCantidad;
			}

			if(auxCantidad>(*acumuladorMaxCantKilos) && pedidoVector[i].estado==2 && pedidoVector[i].isEmpty==0)
			{
				(*acumuladorMaxCantKilos)=auxCantidad;
				idClienteMax=ultimoIdCliente;

			}

		}
		(*idCliente)=idClienteMax;
		printf("La cantidad de kilos es: %.2f\n",(*acumuladorMaxCantKilos));
	}
	return retorno;
}
void listaClienteCon_masKilosPedidos(ePedido pedidoVector[],int size,int* clienteId,
		eCliente clienteVector[],int sizeCliente,int* posicion,float* cantidadDeKilosMax)
{
	busca_clienteConMasKilos( pedidoVector, size,clienteId,cantidadDeKilosMax);
	cliente_buscarId(clienteVector,sizeCliente, (*clienteId), posicion);
	listarUnCliente(clienteVector,(*posicion));
}

int busca_clienteConMenosKilos(ePedido pedidoVector[],int size, int* idCliente,
		float* acumuladorMinCantKilos)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	float auxCantidad=0;
	int idClienteMax=0;
	float kilosAux=0;
	int flagHayPedidoMin=0;

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{

			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0)
			{
				ultimoIdCliente=pedidoVector[i].idCliente;
				auxCantidad=0;
			}
			if(pedidoVector[i].idCliente==ultimoIdCliente &&
					pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==2)
			{
				kilosAux=pedidoVector[i].cantidadHDPE+pedidoVector[i].cantidadLDPE
						+pedidoVector[i].cantidadPP;
				auxCantidad=kilosAux+auxCantidad;
			}

			if((auxCantidad<(*acumuladorMinCantKilos) && pedidoVector[i].estado==2) || (pedidoVector[i].isEmpty==0
					&& pedidoVector[i].estado==2 && flagHayPedidoMin==0))
			{
				(*acumuladorMinCantKilos)=auxCantidad;
				idClienteMax=ultimoIdCliente;
				flagHayPedidoMin=1;

			}

		}
		(*idCliente)=idClienteMax;
		printf("La cantidad de kilos es: %.2f\n",(*acumuladorMinCantKilos));
	}
	return retorno;
}

void listaClienteCon_menosKilosPedidos(ePedido pedidoVector[],int size,int* clienteId,
		eCliente clienteVector[],int sizeCliente,int* posicion,float* cantidadDeKilosMin)
{
	busca_clienteConMenosKilos( pedidoVector, size,clienteId,cantidadDeKilosMin);
	cliente_buscarId(clienteVector,sizeCliente, (*clienteId), posicion);
	listarUnCliente(clienteVector,(*posicion));
}

int cantidad_clientesConMasDeMilKilosReciclados(ePedido pedidoVector[],int size,float limitMax)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	float auxCantidad=0;
	float kilosAux=0;
	int cantidadDeClientes=0;
	//(*acumuladorMaxCantKilos)=0;
	//ePedido auxVector[size];

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{

			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0  )
			{
				if(auxCantidad>limitMax)
				{
					cantidadDeClientes++;

				}
				ultimoIdCliente=pedidoVector[i].idCliente;
				auxCantidad=0;
			}
			if(pedidoVector[i].idCliente==ultimoIdCliente &&
					pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==2)
			{
				kilosAux=pedidoVector[i].cantidadHDPE+pedidoVector[i].cantidadLDPE
						+pedidoVector[i].cantidadPP;
				auxCantidad=kilosAux+auxCantidad;
			}

		}
		if(auxCantidad>limitMax)
		{
			cantidadDeClientes++;

		}
		printf("La cantidad de clientes que reciclaron mas de mil kilos:%d",cantidadDeClientes);
	}
	return retorno;
}

int cantidad_clientesConMenosDeCienlKilosReciclados(ePedido pedidoVector[],int size,float limitMin)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	float auxCantidad=0;
	float kilosAux=0;
	int cantidadDeClientes=0;
	int flagClienteAnterior=0;

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{

			if(pedidoVector[i].idCliente!=ultimoIdCliente && pedidoVector[i].isEmpty==0  )
			{
				if(auxCantidad<limitMin && flagClienteAnterior==1)
				{
					cantidadDeClientes++;

				}
				ultimoIdCliente=pedidoVector[i].idCliente;
				auxCantidad=0;
				flagClienteAnterior=0;
			}
			if(pedidoVector[i].idCliente==ultimoIdCliente &&
					pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==2 )
			{
				flagClienteAnterior=1;
				kilosAux=pedidoVector[i].cantidadHDPE+pedidoVector[i].cantidadLDPE
						+pedidoVector[i].cantidadPP;
				auxCantidad=kilosAux+auxCantidad;
			}

		}

		if(auxCantidad<limitMin && flagClienteAnterior==1)
		{
			cantidadDeClientes++;

		}
		printf("La cantidad de clientes que reciclaron menos de cien kilos:%d",cantidadDeClientes);
	}
	return retorno;
}

int listar_pedidosPorCompletados(eCliente clienteVector[],ePedido pedidoVector[], int sizeCliente,int sizePedido,int estado)
{
	int retorno=-1;
	int i;
	int auxPosicion;

	if(clienteVector!=NULL&&pedidoVector!=NULL&&sizeCliente>0 && sizePedido>0)
	{
		for(i=0;i<sizePedido;i++)
		{
			if(pedidoVector[i].estado==estado)
			{
				listarIdYKilos(pedidoVector,sizePedido,i,estado);
				cliente_buscarId(clienteVector,sizeCliente,pedidoVector[i].idCliente,&auxPosicion);
				listarCuitCliente(clienteVector,auxPosicion);
				printf("\n********************************\n");
				retorno=0;
			}
		}
	}
	return retorno;

}

int listarIdYKilos(ePedido pedidoVector[],int size,int posicion,int estado)
{
	int retorno=0;
	float resultadoSuma;
	float resultadoDivision;
	float resultadoTotal;
	resultadoSuma = pedidoVector[posicion].cantidadHDPE+
			pedidoVector[posicion].cantidadLDPE+pedidoVector[posicion].cantidadPP;
	resultadoDivision = resultadoSuma/pedidoVector[posicion].cantidadDeKilos;
	resultadoTotal = resultadoDivision*100;
	if(pedidoVector[posicion].estado==estado)
	{
		printf("El id de pedido es: %d ,el porcentaje de plastico reciclado es: %.2f %%",
			pedidoVector[posicion].idPedido,resultadoTotal);
	}
	return retorno;
}

int listarCuitCliente(eCliente clienteVector[],int posicion)
{
	int retorno=0;
	printf("\ncuit:%s\n "
			,clienteVector[posicion].cuit);
	return retorno;

}

int listarPorLocalidad(eCliente clienteVector[],int size, ePedido pedidoVector[],int sizePedido,int estado)
{
	int retorno = -1;
	int i,j;
	char localidadIngresada[TEXT_SIZE];
	int flagEncontrado=0;
	int cantidadDePendientes=0;

	if(clienteVector != NULL && size>0 && pedidoVector != NULL && sizePedido>0)
	{
		do{
		utn_getTexto("Ingrese localidad:\n","Error",1,TEXT_SIZE,2,localidadIngresada);
			for(i=0;i<size;i++)
			{
				if(strncmp(localidadIngresada,clienteVector[i].localidad,sizeof(localidadIngresada))==0)
				{
					for(j=0;j<sizePedido;j++)
					{
						if(clienteVector[i].idCliente == pedidoVector[j].idCliente &&
								pedidoVector[j].estado == estado)
						{
							cantidadDePendientes++;
						}
					}

					flagEncontrado = 1;
				}
			}
			if(flagEncontrado == 0)
			{
				printf("localidad invalidad!\n");
			}else{
				retorno=0;
				printf("localidad: %s\tcantidad de pedidos pendientes: %d\n",localidadIngresada,cantidadDePendientes);
			}

		}while(flagEncontrado == 0);

	}
	return retorno;
}

int promedio_ppPorCliente(ePedido pedidoVector[],int size,eCliente clienteVector[],int sizeCliente)
{
	int retorno=-1;
	int i;
	int ultimoIdCliente=0;
	float auxCantidad=0;
	float kilosAux=0;
	int cantidadDeClientes=0;
	int posicion;

	if(pedidoVector != NULL && size>0 )
	{
		retorno=0;
		ordenar_porEntero(pedidoVector,size);
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].idCliente!=ultimoIdCliente && cantidadDeClientes>0 )
			{

				auxCantidad=kilosAux/cantidadDeClientes;
				cliente_buscarId(clienteVector,sizeCliente,pedidoVector[i-1].idCliente,&posicion);
				printf("id: %d\t nombre de la empresa: %s\t promedio de PP: %.2f\n",
						pedidoVector[i-1].idCliente,clienteVector[posicion].nombreDeEmpresa,auxCantidad);

			}
			if(pedidoVector[i].idCliente!=ultimoIdCliente)
			{
				ultimoIdCliente=pedidoVector[i].idCliente;
				auxCantidad=0;
				kilosAux=0;
				cantidadDeClientes=0;
			}
			if(pedidoVector[i].idCliente==ultimoIdCliente &&
					pedidoVector[i].isEmpty==0 && pedidoVector[i].estado==2)
			{
				kilosAux+=pedidoVector[i].cantidadPP;
				cantidadDeClientes++;
			}

		}
		if(cantidadDeClientes>0 )
		{
			auxCantidad=kilosAux/cantidadDeClientes;
			cliente_buscarId(clienteVector,sizeCliente,pedidoVector[i-1].idCliente,&posicion);
			printf("id: %d\t nombre de la empresa: %s\t promedio de PP: %.2f\n",
					pedidoVector[i-1].idCliente,clienteVector[posicion].nombreDeEmpresa,auxCantidad);
		}
	}
	return retorno;
}

int listarPorCuitYTipo(eCliente clienteVector[],int size, ePedido pedidoVector[],int sizePedido,int estado)
{
	int retorno = -1;
	int i,j;
	char cuitIngresado[CUIT_SIZE];
	int flagEncontrado=0;
	float cantidadDeKilos=0;
	int tipo=0;
	int idAux;

	if(clienteVector != NULL && size>0 && pedidoVector != NULL && sizePedido>0)
	{
		do{
		utn_getCUIT("Ingrese CUIT:\n","Error",2,cuitIngresado);
		do{
		utn_getUnsignedInt("ingrese tipo:1-PP\t2-HDPE\t3-LDPE\n","ERROR",
				0,sizeof(tipo),1,10,2,&tipo);
		}while(tipo<1 || tipo >3);

			for(i=0;i<size;i++)
			{

				if((strncmp(cuitIngresado,clienteVector[i].cuit,sizeof(cuitIngresado))==0) && clienteVector[i].isEmpty==0)
				{
					idAux=clienteVector[i].idCliente;
					flagEncontrado = 1;
					break;
				}
			}
			if(flagEncontrado == 0)
			{
				printf("CUIT invalidad!\n");
			}


				for(j=0;j<sizePedido;j++)
				{

					if(idAux == pedidoVector[j].idCliente &&
							pedidoVector[j].estado == estado && pedidoVector[j].isEmpty==0)
					{
						switch(tipo)
						{
						case 1:
							cantidadDeKilos+=pedidoVector[j].cantidadPP;
							break;
						case 2:
							cantidadDeKilos+=pedidoVector[j].cantidadHDPE;
							break;
						case 3:
							cantidadDeKilos+=pedidoVector[j].cantidadLDPE;
							break;
						default:
							printf("opcion no valida\n");
						}
					}
				}
		printf("La cantidad de kilos es: %.2f",cantidadDeKilos);

		}while(flagEncontrado == 0);

	}
	return retorno;
}
