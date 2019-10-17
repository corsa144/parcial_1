#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_abm.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cliente_inicializar(eCliente clienteVector[], int size)
{
    int retorno=-1;
    if(clienteVector!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            clienteVector[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int pedido_inicializar(ePedido pedidoVector[], int size)
{
    int retorno=-1;
    if(pedidoVector!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pedidoVector[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int cliente_buscarLibre(eCliente clienteVector[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(clienteVector!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(clienteVector[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pedido_buscarLibre(ePedido pedidoVector[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(pedidoVector!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pedidoVector[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarId(eCliente clienteVector[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(clienteVector!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(clienteVector[i].isEmpty==1)
                continue;
            else if(clienteVector[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pedido_buscarId(ePedido pedidoVector[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pedidoVector!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pedidoVector[i].isEmpty==1)
            {
                continue;
            }
            else if(pedidoVector[i].idPedido==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int pedido_buscarPorIdCliente(ePedido pedidoVector[], int size, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(pedidoVector!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pedidoVector[i].isEmpty==1)
            {
                continue;
            }
            else if(pedidoVector[i].idCliente==valorBuscado && pedidoVector[i].estado==1)
            {
                retorno=0;
                listarUnPedido(pedidoVector,size,i);
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarInt(eCliente clienteVector[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(clienteVector!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(clienteVector[i].isEmpty==1)
            {
                continue;
            }
            else if(clienteVector[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarString(eCliente clientVector[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(clientVector!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(clientVector[i].isEmpty==1)
                continue;
            else if(strcmp(clientVector[i].nombreDeEmpresa,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Abm
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int cliente_alta(eCliente clienteVector[], int size, int* contadorIdCliente)
{
    int retorno=-1;
    int posicion;
    if(clienteVector!=NULL && size>0 && contadorIdCliente!=NULL)
    {
        if(cliente_buscarLibre(clienteVector,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorIdCliente)++;
            clienteVector[posicion].idCliente=*contadorIdCliente;
            clienteVector[posicion].isEmpty=0;
            utn_getCUIT("\ningrese cuit: ","\nError",2,clienteVector[posicion].cuit);
            utn_getTexto("\ningrese nombre de la empresa: ","\nError",1,TEXT_SIZE,1,clienteVector[posicion].nombreDeEmpresa);
            utn_getTexto("\ningrese direccion: ","\nError",1,TEXT_SIZE,1,clienteVector[posicion].direccion);
            utn_getTexto("\ningrese localidad: ","\nError",1,TEXT_SIZE,1,clienteVector[posicion].localidad);
            printf("\n Posicion: %d\n ID: %d\n cuit: %s\n nombre de la empresa: %s\n direccion: %s\n localidad: %s",
                   posicion, clienteVector[posicion].idCliente,clienteVector[posicion].cuit,clienteVector[posicion].nombreDeEmpresa,clienteVector[posicion].direccion,clienteVector[posicion].localidad);
            retorno=0;
        }
    }
    return retorno;
}
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Abm
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pedido_alta(ePedido pedidoVector[], int size, int* contadorIdPedido,eCliente clienteVector[],int sizeCliente, int* contadorIdCliente)
{
    int retorno=-1;
    int posicion;
    int i;
    int auxId=0;
    int encontroId=0;
    if(pedidoVector!=NULL && size>0 && contadorIdPedido!=NULL&&sizeCliente>0)
    {
        if(pedido_buscarLibre(pedidoVector,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorIdPedido)++;
            pedidoVector[posicion].idPedido=*contadorIdPedido;                                                       //campo ID
            pedidoVector[posicion].isEmpty=0;
            pedidoVector[posicion].estado=1;
            utn_getFloat("\ningrese cantidad de kilos: ","\nError",0,sizeof(float),1,2,2,&pedidoVector[posicion].cantidadDeKilos);
            do{
            	 utn_getUnsignedInt("\ningrese ID cliente: ","\nError",0,sizeof(int),1,2,2,&auxId);
            for(i=0;i<sizeCliente;i++)
            {
            	if(auxId==clienteVector[i].idCliente)
            	{
            		pedidoVector[posicion].idCliente=clienteVector[i].idCliente;
            		encontroId=1;
            	}
            }
            if(encontroId==0)
            {
            	printf("\nNo Encontro el id\n");
            }
            }while(encontroId==0);
            printf("\n Posicion: %d\n ID pedido: %d\n estado: %d\n cantidad de kilos: %.2f\n ID cliente: %d\n" ,
                   posicion, pedidoVector[posicion].idPedido,pedidoVector[posicion].estado,pedidoVector[posicion].cantidadDeKilos,pedidoVector[posicion].idCliente);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Abm
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int cliente_modificar(eCliente clienteVector[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(clienteVector!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(cliente_buscarId(clienteVector,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n -nombre de la empresa: %s\n -cuit: %s\n C-direccion: %s\n D-localidad: %s",
                       posicion, clienteVector[posicion].idCliente,clienteVector[posicion].nombreDeEmpresa,clienteVector[posicion].cuit,clienteVector[posicion].direccion,clienteVector[posicion].localidad);
                utn_getChar("\nModificar: C  D  S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {

                    case 'C':
                    	utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,clienteVector[posicion].direccion);
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,clienteVector[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int pedido_modificar(ePedido pedidoVector[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    float auxCantidadKilos;
    float* resultado;
    int id=0;
    char opcion;

    if(pedidoVector!=NULL && sizeArray>0)
    {
    	listarArrayPedido(pedidoVector,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(pedido_buscarId(pedidoVector,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	pedidoVector[posicion].cantidadPP=0.00;
        	pedidoVector[posicion].cantidadHDPE=0.00;
        	pedidoVector[posicion].cantidadLDPE=0.00;

            do
            {       //copiar printf de alta


                printf("\n Posicion: %d\n ID pedido: %d\n -cantidad de kilos: %.2f\n"
                		" -estado: %d\n A-cantidadPP: %.2f\n"
                		" B-cantidadHDPE: %.2f\n C-cantidadLDPE: %.2f",
                       posicion, pedidoVector[posicion].idPedido,pedidoVector[posicion].cantidadDeKilos,
					   pedidoVector[posicion].estado,pedidoVector[posicion].cantidadPP,
					   pedidoVector[posicion].cantidadHDPE,pedidoVector[posicion].cantidadLDPE);
                utn_getChar("\nModificar: A B C S(salir)","\nError",'A','Z',2,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	auxCantidadKilos=pedidoVector[posicion].cantidadHDPE+pedidoVector[posicion].cantidadLDPE;
                        if(cargarCantidad(pedidoVector[posicion].cantidadDeKilos,auxCantidadKilos,resultado)==0)
                        {
                        	pedidoVector[posicion].cantidadPP=(*resultado);
                        }
                        break;
                    case 'B':
                    	auxCantidadKilos=pedidoVector[posicion].cantidadPP+pedidoVector[posicion].cantidadLDPE;
                        if(cargarCantidad(pedidoVector[posicion].cantidadDeKilos,auxCantidadKilos,resultado)==0)
                        {
                        	pedidoVector[posicion].cantidadHDPE=(*resultado);
                        }
                        break;
                    case 'C':
                    	auxCantidadKilos=pedidoVector[posicion].cantidadHDPE+pedidoVector[posicion].cantidadPP;
                        if(cargarCantidad(pedidoVector[posicion].cantidadDeKilos,auxCantidadKilos,resultado)==0)
                        {
                        	pedidoVector[posicion].cantidadLDPE=(*resultado);
                        }
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                pedidoVector[posicion].estado=2;
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int cargarCantidad(float cantidadTotal,float sumaDeCantidades,float* resultado)
{
	int retorno=-1;
	float aux;
	utn_getFloat("\n: ","\nError",0,sizeof(float),1,2,2,resultado);
	aux = sumaDeCantidades+(*resultado);
	if(cantidadTotal<aux)
	{
		printf("Error:La suma de las cantidades de plastico no puede ser mayor a la cantidad total\n");
	}else{
		retorno=0;
	}
		return retorno;
}
//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Abm
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_baja(eCliente clienteVector[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char seguir;
    if(clienteVector!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        do{
        utn_getChar("\n esta seguro de que desea eliminar cliente[S/N]","\n Error", 'A', 'Z', 2, &seguir);
        }while(seguir!='S');
        if(cliente_buscarId(clienteVector,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            clienteVector[posicion].isEmpty=1;
            clienteVector[posicion].idCliente=0;                                                                   //cambiar campo id
            strncpy(clienteVector[posicion].nombreDeEmpresa,"",sizeof(clienteVector[posicion].nombreDeEmpresa));
            strncpy(clienteVector[posicion].cuit,"",sizeof(clienteVector[posicion].cuit));
            strncpy(clienteVector[posicion].direccion,"",sizeof(clienteVector[posicion].direccion));
            strncpy(clienteVector[posicion].localidad,"",sizeof(clienteVector[posicion].localidad));
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************

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

int listarArrayCliente(eCliente clienteVector[],int size)
{

	int retorno=-1;
	int i;
	if(clienteVector!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if(clienteVector[i].isEmpty==0)
			{
				listarUnCliente(clienteVector,i);
			}
			retorno=0;
		}
	}
	return retorno;
}

int listarUnCliente(eCliente clienteVector[],int posicion)
{
	int retorno=0;
	printf("\nEl cliente es\nid de cliente: %d \n"
			" nombre de la emprersa:%s\ndireccion:%s\n"
			"localidad:%s\n"
			"cuit:%s\n ",clienteVector[posicion].idCliente,clienteVector[posicion].nombreDeEmpresa,
			clienteVector[posicion].direccion,clienteVector[posicion].localidad,clienteVector[posicion].cuit);
	return retorno;

}
int listarArrayPedido(ePedido pedidoVector[],int size)
{

	int retorno=-1;
	int i;
	if(pedidoVector!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].isEmpty==0)
			{
				listarUnPedido(pedidoVector,size,i);
			}
			retorno=0;
		}
	}
	return retorno;
}

int listarUnPedido(ePedido pedidoVector[],int size,int posicion)
{
	int retorno=0;
	if(pedidoVector[posicion].estado==1)
	{
		printf("\nEl pedido esta PENDIENTE");
	}
	if(pedidoVector[posicion].estado==2)
	{
		printf("\nEl pedido esta CUMPLIDO\n");
	}
	printf("\nid de cliente: %d \n"
			" id de pedido:%d\nestado:%d\n"
			"cantidad de kilos:%.2f\n"
			,pedidoVector[posicion].idCliente,pedidoVector[posicion].idPedido,
			pedidoVector[posicion].estado,pedidoVector[posicion].cantidadDeKilos);
	if(pedidoVector[posicion].estado==2)
	{
		printf("cantidad de PP:%.2f\ncantidad de HDPE:%.2f\ncantidad de LPDE:%.2f\n",
				pedidoVector[posicion].cantidadPP,pedidoVector[posicion].cantidadHDPE,
				pedidoVector[posicion].cantidadLDPE);
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

/**\brief ordena por criterio
 * param estructura
 * param tamaño
 * retorno retorna 0 si todo esta bien y -1 en caso de error
 */
int ordenar_porEntero(ePedido pedidoVector[],int size)
{
	int retorno=-1;
	int i;
	int estaOrdenado=0;
	ePedido auxVector[size];
	if(pedidoVector != NULL && size>0)
	{
		retorno=0;
		while(estaOrdenado==0)
		{
			estaOrdenado=1;
			for(i=1;i<size;i++)
			{
				if(pedidoVector[i].cantidadDeKilos<pedidoVector[i-1].cantidadDeKilos)
				{
					auxVector[i]=pedidoVector[i];
					pedidoVector[i]=pedidoVector[i-1];
					pedidoVector[i-1]=auxVector[i];
					estaOrdenado=0;
				}
			}
		}
	}
	return retorno;
}

int ordenar_porString(eCliente clienteVector[],int size)
{
	int retorno=-1;
	int i;
	int estaOrdenado=0;
	eCliente auxVector[size];
	if(clienteVector != NULL && size>0)
	{
		retorno=0;
		while(estaOrdenado==0)
		{
			estaOrdenado=1;
			for(i=1;i<size;i++)
			{
				if(clienteVector[i].nombreDeEmpresa<clienteVector[i-1].nombreDeEmpresa)
				{
					auxVector[i]=clienteVector[i];
					clienteVector[i]=clienteVector[i-1];
					clienteVector[i-1]=auxVector[i];
					estaOrdenado=0;
				}
			}
		}
	}
	return retorno;
}


int ordenamiento_insercionEntero (ePedido pedidoVector[], int size)
{
	int i, j;
	int retorno=-1;
	ePedido auxVector[size];
	if(pedidoVector != NULL && size>0)
	{
		retorno=0;
		for (i = 1; i < size; i++)
		{
			auxVector[i] = pedidoVector[i];
			j = i - 1;
				while ((j >= 0) && (auxVector[j].cantidadDeKilos < pedidoVector[j].cantidadDeKilos))
				{
					pedidoVector[j + 1] = pedidoVector[j];
					j--;
				}
			pedidoVector[j + 1] = auxVector[i];
		}
	}
	return retorno;
}
/**\brief busca valor minimo o maximo
 * param estructura
 * param tamaño de la estructura
 * param puntero donde se guardara lo buscado
 * retorno retorna 0 si todo esta bien y -1 en caso de error
 */
int busca_valorMinimo(ePedido pedidoVector[],int size,float* valorBuscado )
{
	int retorno=-1;
	int i;
	float auxMin;
	int bandera=0;
	if( pedidoVector != NULL && size>0 )
	{
		retorno=0;
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].isEmpty==0 && bandera==0)
			{
				auxMin=pedidoVector[i].cantidadDeKilos;
				bandera=1;
			}

			if(pedidoVector[i].cantidadDeKilos<auxMin && pedidoVector[i].isEmpty==0 && bandera==1)
			{
				auxMin=pedidoVector[i].cantidadDeKilos;
			}
		}
		(*valorBuscado)=auxMin;
	}
	return retorno;
}

int busca_valorMaximo(ePedido pedidoVector[],int size,float* valorBuscadoMax)
{
	int retorno=-1;
	int i;
	float auxMax;
	int bandera=0;
	if( pedidoVector != NULL && size>0 )
	{
		retorno=0;
		for(i=0;i<size;i++)
		{
			if(pedidoVector[i].isEmpty==0 && bandera==0)
			{
				auxMax=pedidoVector[i].cantidadDeKilos;
				bandera=1;
			}

			if(pedidoVector[i].cantidadDeKilos<auxMax && pedidoVector[i].isEmpty==0 && bandera==1)
			{
				auxMax=pedidoVector[i].cantidadDeKilos;
			}
		}
		(*valorBuscadoMax)=auxMax;
	}
	return retorno;
}
