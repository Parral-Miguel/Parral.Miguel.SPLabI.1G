#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "LinkedList.h"


int menu ()
{
    int option;
    printf("Bienvenido. Ingrese una opcion:\n ");
    printf("1 - CARGAR ARCHIVO:\n "); //
    printf("2 - IMPRIMIR LISTA:\n "); //
    printf("3 - ASIGNAR ESTADISTICAS:\n ");   //
    printf("4 - FILTRAR POR PAISES EXITOSOS\n ");  //
    printf("5 - FILTRAR POR PAISES EN EL HORNO\n "); //
    printf("6 - ORDENAR POR NIVEL DE INFECCION\n "); //
    printf("7 - MOSTRAR EL MAS CASTIGADO\n ");  //
    printf("8 - SALIR   :\n ");    //sale del menu
    scanf("%d", &option);
    system("cls");
    fflush(stdin);
    return option;
}

void paises_listarUno(LinkedList* listaPaises,ePaises* pais, int index)
{

    pais = ll_get(listaPaises, index);

    printf("ID   NOMBRE   HORAS   SUELDO\n");
    printf("%d, %s, %d, %d, %d\n\n", pais->id, pais->pais, pais->recuperados, pais->infectados, pais->muertos);
}

int listar_paises(LinkedList* listaPaises)
{
    printf("ID   PAIS   RECUPERADOS   INFECTADOS    MUERTOS\n");
    ePaises paisAux;
    ePaises* direccionPais;
    direccionPais = &paisAux;
    int tam = ll_len(listaPaises);
    for (int i = 0; i < tam; i++)
    {
        direccionPais = ll_get(listaPaises, i);
        if(direccionPais != NULL && direccionPais->id != 0)
        {

            printf("%d, %10s, %6d, %6d, %6d\n",
                   direccionPais->id,
                   direccionPais->pais,
                   direccionPais->recuperados,
                   direccionPais->infectados,
                   direccionPais->muertos);
        }
    }
    return 1;
}

int mas_castigado(LinkedList* listaPaises)
{
    ePaises* paisAux;
    int mayor = 0;

    for (int i = 0; i < ll_len(listaPaises); i++)
    {
        paisAux = ll_get(listaPaises, i);
        if (paisAux->muertos > mayor)
        {
           mayor = paisAux->muertos;
        }

    }
    return mayor;
}

int ordenarMasInfectados(LinkedList* listaPaises)
{
    ll_sort(listaPaises, ordenar_infectados, 0);
    printf("Paises ordenados por mayor infectividad\n");
    listar_paises(listaPaises);
    return 0;
}
