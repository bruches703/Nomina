#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define X 30
#define TAM 2
#define OCUPADO 1
#define VACIO 0


typedef struct
{
    char nombre[X];
    char sexo;
    float salario;
    int legajo;
    int estado;

}Eempleado;

int menuOption (void);
void validationEmp (Eempleado emp[], int cant);
void loadWorkers (Eempleado emp);
void showFile (Eempleado emp[],int cant);

int main()
{
    Eempleado empleados[TAM];
    //char auxChar [100];
    int exit=0;


    for (int i=0;i<TAM;i++)
    {
        empleados[i].estado=VACIO;
    }


    do
    {
    switch (menuOption())
    {
        case 1:
            validationEmp(empleados,TAM);
            break;
        case 2:
            showFile (empleados, TAM);
            for(int i=0;i<TAM;i++)
            {
                printf("\n%d\t%s\t\t%c\t%.2f\n\n", empleados[i].legajo,empleados[i].nombre,empleados[i].sexo,empleados[i].salario);
            }
                system("pause");

            break;
        case 3:
            printf("%s %s",empleados[0].nombre,empleados[1].nombre);
            system("pause");
            break;
        case 4:
            printf("Organizar");
            break;
        case 5:
            printf("\nGracias por utilizar nuestro programa\n");
            exit=1;
            break;
        default:
            printf("Error al ingresar");
            break;

    }
    }while(exit==0);
    return 0;
}

int menuOption (void)
{
    int opc;
    system("cls");
    printf("\t******Menu de opciones*****");
    printf("\n\n1-Ingresar nuevo legajo");
    printf("\n2-Mostrar todos por orden de legajos");
    printf("\n3-Mostrar un legajo");
    printf("\n4-Organizar lista de empleados");
    printf("\n5-Salir");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&opc);

    return opc;
}

void validationEmp (Eempleado emp[], int cantidad)
{
    for (int i=0;i<cantidad;i++)
    {
        if (emp[i].estado==VACIO)
        {
            loadWorkers(emp[i]);
            break;
        }
        else
        {
                printf("\n***No hay legajos vacios***\n");
                system("pause");
        }
    }

}

void loadWorkers (Eempleado emp)
{
    char auxEmp[100];

    system("cls");
    printf("Ingrese legajo: ");
    scanf("%d",&emp.legajo);
        while (emp.legajo<1000 ||emp.legajo>9999)
        {
            printf("Error, el legajo debe ser de cuatro cifras. Reingrese: ");
            scanf("%d",&emp.legajo);
        }
    printf("\nIngrese nombre del empleado: ");
    fflush(stdin);
    gets(auxEmp);
        while (strlen(auxEmp)>X-1)
        {
            printf("Los caracteres sobrepasan lo tolerable, Reingrese: ");
            fflush(stdin);
            gets(auxEmp);
        }

    strcpy(emp.nombre, auxEmp);

    printf("\nIngrese el sexo del empleado (M-Masculino / F-Femenino): ");
    fflush(stdin);
    scanf("%c",&emp.sexo);
    emp.sexo=toupper(emp.sexo);
        while(emp.sexo!='M' && emp.sexo!='F')
        {
            printf("Error incorrecto. Ingrese el sexo del empleado (M-Masculino / F-Femenino): ");
            fflush(stdin);
            scanf("%c",&emp.sexo);
            emp.sexo=toupper(emp.sexo);
        }
    printf("\nIngrese salario: ");
    scanf("%f", &emp.salario);
        while(emp.salario<0)
        {
            printf("El salario no puede ser de valor menor a cero, reingrese salario: ");
            scanf("%f", &emp.salario);
        }
    emp.estado=OCUPADO;

}

void showFile (Eempleado emp[],int cant)
{

    printf("-----Lista de empleados------");
    printf("\n\nLegajo\tNombre\t\tSexo\tSalario\n");

    for(int i=0;i<TAM;i++)
    {
   //     if(emp[i].estado==OCUPADO)
    //        {
            printf("\n%d\t%s\t\t%c\t%.2f\n\n", emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].salario);
  //          }
    }
    system("pause");
}
