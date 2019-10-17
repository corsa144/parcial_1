#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_abm.h"

#define TIPO_HDPE 1
#define TIPO_LDPE 2
#define TIPO_PP 3

#define ESTADO_PENDIENTE 1
#define ESTADO_CUMPLIDO 2
#define QTY_TIPO 7
#define QTY_PEDIDO 14

int main()
{
    int opcion;
    int* contadorIdCliente=7;
    int* contadorIdPedido=12;


    eCliente clienteVector[QTY_TIPO]={
    		{1,0,"AVENIDA BOEDO 1230","CABA","corsa SA"," 11-22233344-4"},
			{2,0,"avenida la plata 2700","CABA","pereyra hermanos","22-11133355-5"},
			{3,0,"lacroze 567","CABA","melos SA","33-55522299-9"},
			{4,0,"santa fe 2970 ","CABA ","arcor ","22-11122233-4 "},
			{5,0,"cordoba 3598","CABA","cuquets","15-33444999-7"},
			{6,0,"Las Heras 4805","CABA ","El Rapido ","23-11444233-6 "},
			{7,0,"las palmas 2557","CABA","Paty","25-11144999-6"}
    };
    ePedido pedidoVector[QTY_PEDIDO]={
    		{0,1,3,1,120.00,0,0,0},
			{0,2,2,2,200.00,50,100,50},
			{0,3,1,1,300.00,0,0,0},
			{0,4,1,1,140.00,0,0,0},
    		{0,5,3,1,180.00,0,0,0},
			{0,6,5,2,250.00,50,100,50},
			{0,7,4,1,380.00,0,0,0},
			{0,8,1,1,440.00,0,0,0},
    		{0,9,3,2,185.00,21,68,70},
			{0,10,5,1,150.00,0,0,0},
			{0,11,4,1,480.00,0,0,0},
			{0,12,1,2,460.00,100,200,100},
			{1,0,0,0,0.00,0,0,0},
			{1,0,0,0,0.00,0,0,0}
    };
   // cliente_inicializar(clienteVector,QTY_TIPO);
    //pedido_inicializar(pedidoVector, QTY_TIPO);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta cliente \n2) Modificar cliente\n3) Baja cliente\n"
        		"4) crear pedido de recoleccion:\n5) procesar residuos: \n6)imprmir clientes:\n"
        		"7)Imprimir pedidos pendientes:\n8)Imprimir pedidos cumplidos:\n9)Salir:",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
            	cliente_alta(clienteVector,QTY_TIPO,contadorIdCliente);
            	listarArrayCliente(clienteVector,QTY_TIPO);
                break;

            case 2: //Modificar
               cliente_modificar(clienteVector,QTY_TIPO);
                break;

            case 3: //Baja
                cliente_baja(clienteVector,QTY_TIPO);
                break;

            case 4://alta llamada
            	listarArrayPedido(pedidoVector,QTY_PEDIDO);
            	pedido_alta( pedidoVector,QTY_PEDIDO, contadorIdPedido, clienteVector,QTY_TIPO, contadorIdCliente);
                break;

            case 5://modificar llamada
            	pedido_modificar(pedidoVector,  QTY_PEDIDO);
                break;

            case 6:
            	listarArray(pedidoVector,clienteVector,QTY_PEDIDO,QTY_TIPO);
                break;
            case 7:
            	listar_pedidosPorEstado(clienteVector,pedidoVector,QTY_TIPO,QTY_PEDIDO,ESTADO_PENDIENTE);
            	break;
            case 8:
            	listar_pedidosPorEstado(clienteVector,pedidoVector,QTY_TIPO,QTY_PEDIDO,ESTADO_CUMPLIDO);
            	break;
            case 9:
            	break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=9);
    return 0;
}
