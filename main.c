#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_abm.h"
#include "utn_informes.h"

#define TIPO_HDPE 1
#define TIPO_LDPE 2
#define TIPO_PP 3

#define ESTADO_PENDIENTE 1
#define ESTADO_CUMPLIDO 2
#define QTY_TIPO 5

int main()
{
    int opcion;
    int* contadorIdCliente=0;
    int* contadorIdPedido=0;

    eCliente clienteVector[QTY_TIPO]={
    		{1,0,"AVENIDA BOEDO","CABA","corsa sa"," 11222333444"},
			{2,0,"avenida la plata","CABA","pereyra hermanos","22111333555"},
			{3,0,"lacroze","CABA","melos sa","33555222999"}
    };
    ePedido pedidoVector[QTY_TIPO]={
    		{0,1,3,1,3,120},
			{0,2,2,2,2,130},
			{0,3,1,1,1,125}
    };
    cliente_inicializar(clienteVector,QTY_TIPO);
    pedido_inicializar(pedidoVector, QTY_TIPO);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta cliente \n2) Modificar cliente\n3) Baja cliente\n4) crear pedido de recoleccion:\n5) procesar residuos: \n6)imprmir clientes:\n7)salir:\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
            	cliente_alta(clienteVector,QTY_TIPO,&contadorIdCliente);
                break;

            case 2: //Modificar
               cliente_modificar(clienteVector,QTY_TIPO);
                break;

            case 3: //Baja
                cliente_baja(clienteVector,QTY_TIPO);
                break;

            case 4://alta llamada
            	listarArray(pedidoVector,QTY_TIPO);
            	pedido_alta( pedidoVector,QTY_TIPO, &contadorIdPedido, clienteVector,QTY_TIPO, &contadorIdCliente);
                break;

            case 5://modificar llamada
            	pedido_modificar(pedidoVector,  QTY_TIPO);
                break;

            case 6:
            	 mostrarClientes( clienteVector,QTY_TIPO,pedidoVector,QTY_TIPO);
                break;
            case 7:
            	break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=7);
    return 0;
}
