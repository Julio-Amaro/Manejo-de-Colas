
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct nodo{
    int info;
    string nombre, apellido, telefono, direccion;
    int cedula;
    struct nodo *sigte;
};

struct nodo *inicio = NULL;
struct nodo *fondo = NULL;

void insertar (string nom, string apell, string tlf, string dir, int cdl)
{
    struct nodo *nuevo;
    nuevo = new nodo;
    nuevo -> sigte = NULL;
    nuevo -> nombre = nom;
    nuevo -> apellido = apell;
    nuevo -> telefono = tlf;
    nuevo -> direccion = dir;
    nuevo -> cedula = cdl;

    if (inicio == NULL)
    {
        inicio = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo -> sigte = nuevo;
        fondo = nuevo;
    }

}

void extraer()
{   bool vacia = true;

    if(inicio != NULL)
    {   vacia = false;
        string informacion = inicio -> apellido;
        struct nodo *bor = inicio;

        if(inicio == fondo)
        {
            inicio == NULL;
            fondo == NULL;
        }
        else
        {
            inicio = inicio -> sigte;
        }
        free(bor);
        /*return informacion;*/
        cout<< "\nLos datos de "<<informacion<< " han sido eliminados de la cola\n";
    }

    if(vacia == true ) cout<<"\nNo hay elementos que extraer, la cola esta vacia \n";

}

void mostrarcola()
{   bool vacia=true;
    int i=0;
    struct nodo *reco = inicio;
    printf("\n\nListado de las personas en la cola: \n");

    while( reco != NULL)
    {
        cout<<++i<<"- "<<reco -> apellido;
        reco = reco -> sigte;
        printf("\n");
        vacia= false;
    }
    printf("\n");
    if(vacia == true) cout<<"La cola esta vacia\n";
}

void mostrardatos()
{   bool vacia=true;
    int i=0;
    struct nodo *reco = inicio;
    printf("\n\nListado de las personas en la cola: \n");

    while( reco != NULL)
    {
        cout<<++i<<"- "<<reco->nombre<<" "<<reco -> apellido<<"\n";
        cout<<"Direccion: "<<reco->direccion<<"\n";
        cout<<"Celefono: "<<reco->telefono<<"\n";
        cout<<"Cedula: "<<reco->cedula<<"\n";
        reco = reco -> sigte;
        printf("\n\n");
        vacia=false;
    }
    printf("\n");
    if(vacia == true) cout<<"La cola esta vacia\n";
}

void eliminar()
{   bool vacia = true;
    struct nodo *bor;

    if(inicio != NULL){

    while (inicio != NULL)
    {
        bor=inicio;
        inicio = bor->sigte;
        delete(bor);
        vacia = false;
    }

    }
    if(vacia == true) cout<<"\nLa cola ya estaba vacia\n";
    else cout<<"\nLa cola ha sido eliminada\n";
    inicio = NULL;
    fondo = NULL;
}

void menu()
{
     cout<<"\n1- Ingresar persona a la cola";
     cout<<"\n2- Extraer persona de la cola";
     cout<<"\n3- Mostrar cola";
     cout<<"\n4- Mostrar todos los datos de las personas en la cola";
     cout<<"\n5- Eliminar cola";
     cout<<"\n6- Salir";

     cout<<"\n\n ingrese opcion: ";
}

int main()
{
    int op;
    string nom, apell, tlf;
    char dir[40];
    int cedula;

    do{

     menu(); cin>>op;

     switch(op)
     {
    case 1: cout<<"\n Nombre de la persona: "; cin>>nom;
            cout<<"\n apellido de la persona: "; cin>>apell;
            cout<<"\n cedula de la persona: "; cin>>cedula;
            cout<<"\n direccion de la persona: "; cin>>dir;
            cout<<"\n telefono de la persona: "; cin>>tlf;
            insertar(nom, apell, tlf, dir, cedula);
            cout<<"\n\n Los datos de "<<apell <<" se han adjuntado a la cola...\n\n";
    break;

    case 2: extraer();

    break;

    case 3:
            mostrarcola();
    break;

    case 4:
            mostrardatos();
    break;

    case 5:
            eliminar();
    break;

    case 6: cout<< "\n\n Saliendo del programa... \n\n";
    break;

    default: cout<< "\n\n opcion invalida intente nuevamente \n\n";
     }
     cout<<"\n\nPresione una tecla para continuar\n\n";
    getch();
   }while(op != 6);

}
