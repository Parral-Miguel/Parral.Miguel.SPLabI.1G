#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "parser.h"
#include "entidades.h"
#include "informes.h"

int main()
{
    srand (time(NULL));
    int error;
    char archivo [50];
    char confirma = 'n';
    int flag = 0;

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesExito;
    LinkedList* listaPaisesHorno;

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo:\n");
            gets(archivo);
            fflush(stdin);

            FILE* pFile;
            ll_clear(listaPaises);
            pFile = fopen(archivo,"r");
            error = parsear_paises(pFile,listaPaises);

            if (!error)
            {
                printf("carga realizada con exito\n");
                flag = 1;

            }

            break;

        case 2:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }
            listar_paises(listaPaises);

            break;
        case 3:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }

            listaPaises = ll_map(listaPaises, asignar_estadisticas);
            printf("Asignacion realizada con exito");
            break;
        case 4:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }

            listaPaisesExito = ll_filter(listaPaises, filtrar_exito);
            listar_paises(listaPaisesExito);
            break;

        case 5:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }
            listaPaisesHorno = ll_filter(listaPaises, filtrar_horno);
            listar_paises(listaPaisesHorno);
            break;
        case 6:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }

            ordenarMasInfectados(listaPaises);
            break;
        case 7:
            if(!flag)
            {
                printf("debe realizarse la carga de paises primero");
                break;

            }
            ePaises* paisAux;
            int mayor = mas_castigado(listaPaises);
            for (int i = 0; i < ll_len(listaPaises); i++)
            {
                paisAux = ll_get(listaPaises, i);
                if (mayor == paisAux->muertos)
                {
                    printf("Pais o paises con mas muertos: \n");
                    printf("Pais: %s   Muertos: %d\n", paisAux->pais, paisAux->muertos);
                }
            }
            break;
        case 8:
            printf("esta seguro de salir? (s/n)");
            scanf("%c", &confirma);
            fflush(stdin);
            if (confirma == 's')
            {
                ll_deleteLinkedList(listaPaises);
                break;
            }
            break;
        default:

            printf("ingrese una opcion valida");
            break;
        }
        system("pause");
        system("cls");

    }
    while(confirma != 's');

    return 0;
}
