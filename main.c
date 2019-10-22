#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_abm.h"
#include "ePedido.h"
#include "informes.h"

#define ESTADO_PENDIENTE 1
#define ESTADO_CUMPLIDO 2
#define QTY_TIPO 13
#define QTY_PEDIDO 21
#define LIMITE_MAXIMO 1000
#define LIMITE_MINIMO 100

int main()
{
    int opcion;
    int* contadorIdCliente=13;
    int* contadorIdPedido=21;
    int* clienteIdAux=0;
    int* posicionAux=0;
    float* cantidadDeKilosAux=0;
    eCliente  clienteVector[QTY_TIPO]={
    		{1,0,"AVENIDA BOEDO 1230","CABA","corsa SA","11-22233344-4"},
			{2,0,"avenida la plata 2700","CABA","pereyra hermanos","21-11133355-7"},
			{3,0,"lacroze 567","CABA","melos SA","33-55522299-9"},
			{4,0,"santa fe 2970 ","CABA","arcor ","22-11122233-4"},
			{5,0,"cordoba 3598","CABA","cuquets","15-33444999-7"},
			{6,0,"Las Heras 4805","CABA","El Rapido ","23-11444233-6"},
			{7,0,"las palmas 2557","CABA","Paty","30-11223344-5"},
			{8,0,"lima 1234","CABA","Telefonica","22-11133355-5"},
			{9,0,"Corrientes 2547","CABA","DATASOFT","30-44556677-6"},
			{10,0,"cucha cucha 555","LANUS","NESTLE ","30-88995521-9"},
			{11,0,"ROCHA 784","QUILMES","TERRABUSI","30-56791423-5"},
			{12,0,"Mitre 750","AVELLANEDA","DIA ","31-54581253-3"},
			{13,0,"ROCHA 741","QUILMES","QUILMES","30-51485759-6"}
    };

    ePedido pedidoVector[QTY_PEDIDO]={
    		{0,1,3 ,1,120.00,0,0,0},
			{0,2,2 ,2,200.00,50,100,50},
			{0,3,1 ,1,300.00,0,0,0},
			{0,4,1 ,1,140.00,0,0,0},
    		{0,5,3 ,1,180.00,0,0,0},
			{0,6,5 ,2,250.00,50,100,50},
			{0,7,4 ,1,380.00,0,0,0},
			{0,8,1 ,1,440.00,0,0,0},
    		{0,9,3 ,2,185.00,21,68,70},
			{0,10,5 ,1,150.00,0,0,0},
			{0,11,4 ,1,480.00,0,0,0},
			{0,12,1 ,2,460.00,100,200,100},
			{0,13,8 ,2,1000.00,200,145,230},
			{0,14,8 ,2,800.00,210,45,30},
			{0,15,9 ,1,100.00,50,100,50},
			{0,16,9 ,1,300.00,0,0,0},
			{0,17,10 ,2,1500.00,500,150,270},
    		{0,18,11 ,2,750.00,100,50,70},
			{0,19,8 ,1,200.00,0,0,0},
			{0,20,12 ,2,30.00,10,5,3},
			{0,21,13 ,1,456.00,0,0,0}

    };
   // cliente_inicializar(clienteVector,QTY_TIPO);
    //pedido_inicializar(pedidoVector, QTY_TIPO);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta cliente \n2) Modificar cliente\n3) Baja cliente\n"
        		"4) crear pedido de recoleccion:\n5) procesar residuos: \n6)imprmir clientes:\n"
        		"7)Imprimir pedidos pendientes:\n8)Imprimir pedidos cumplidos:\n"
        		"9)cliente con mas pedidos:\n"
        		"10)Cliente con mas pedidos pendientes:\n11)cliente con mas pedidos cumplidos:\n"
        		"12)cliente que reciclo mas kilos:\n13)cliente que reciclo menos kilos:\n"
        		"14)Cantidad de clientes que superan los mil kilos:\n15)Cantidad de clientes con menos de 100 kilos:"
        		"\n16)Mostrar porcentaje de plastico reciclado:\n17)Mostrar cantidad de pedidos por localidad:\n"
        		"18)Mostrar promedio de PP por cliente:\n19)Cantidad de kilos reciclados:\n20)Salir:",
                      "\nError",1,sizeof(int),1,14,1,&opcion);
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

            	listaClienteCon_masPedidos(pedidoVector,QTY_PEDIDO,&clienteIdAux,clienteVector,QTY_TIPO,&posicionAux);
            	break;
            case 10:
            	listaClienteCon_masPedidosPendientes( pedidoVector,QTY_PEDIDO,&clienteIdAux, clienteVector,QTY_TIPO,& posicionAux);
            	break;
            case 11:
            	listaClienteCon_masPedidosCumplidos( pedidoVector,QTY_PEDIDO,&clienteIdAux,clienteVector,QTY_TIPO,&posicionAux);
            	break;
            case 12:
            	listaClienteCon_masKilosPedidos(pedidoVector,QTY_PEDIDO,&clienteIdAux,clienteVector,
            			QTY_TIPO,&posicionAux,&cantidadDeKilosAux);
            	break;
            case 13:
            	listaClienteCon_menosKilosPedidos(pedidoVector,QTY_PEDIDO,&clienteIdAux,clienteVector,
            			QTY_TIPO,&posicionAux,&cantidadDeKilosAux);
            	break;
            case 14:
            	cantidad_clientesConMasDeMilKilosReciclados(pedidoVector,QTY_PEDIDO,LIMITE_MAXIMO);
            	break;
            case 15:
            	cantidad_clientesConMenosDeCienlKilosReciclados(pedidoVector,QTY_PEDIDO,LIMITE_MINIMO);
            	break;
            case 16:
            	listar_pedidosPorCompletados(clienteVector,
            			 pedidoVector,QTY_TIPO,QTY_PEDIDO,ESTADO_CUMPLIDO);
            	break;
            case 17:
            	listarPorLocalidad(clienteVector,QTY_TIPO,pedidoVector,QTY_PEDIDO,ESTADO_PENDIENTE);
            	break;
            case 18:
            	promedio_ppPorCliente(pedidoVector,QTY_PEDIDO, clienteVector,QTY_TIPO);
            	break;
            case 19:
            	listarPorCuitYTipo( clienteVector,QTY_TIPO,pedidoVector,QTY_PEDIDO,ESTADO_CUMPLIDO);
            	break;
            case 20:
            	break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=20);
    return 0;
}
