#include<iostream>
#include<stdio.h>
#include"Pila_Lineal.h"
#include<stdexcept>
using namespace std;

//constructor
Pila_Lineal::Pila_Lineal()
{

    cima=-1;//inicializamos la cima en -1, porque no hay elementos en la pila

}

bool Pila_Lineal::pilaVacia()
{

    return(cima==-1);

}

bool Pila_Lineal::pilaLlena()
{

    return(cima==TAMPILA-1);//si la cima es igual al tamaño de la pila -1,significa que la pila esta llena

}

//funcion para insertar elementos en la pila
void Pila_Lineal::InsertarPila(Datos n)
{

    if(pilaLlena())
    {

        throw overflow_error("Pila llena, no se puede insertar mas elementos.");

    }
    lisPila[++cima]=n;//aumentamos la cima y asignamos el valor al arreglo


}
Datos Pila_Lineal::QuitarPila()
{

    if(pilaVacia())
    {

        throw underflow_error("Pila vacia, no se puede quitar elementos.");

    }
    return lisPila[cima--];//devolvems el valor de la cima y disminuimos la cima

}

void Pila_Lineal::LimpiarPila()
{

    cima=-1;//aqui inicializamos la cim en -1, porque no hay elementos en la pila

}

Datos Pila_Lineal::CimaPila()
{

    if(pilaVacia())
    {

        throw underflow_error("Pila vacia, no hay elementos.");

    }
    return lisPila[cima];//



}

int main()
{

    Pila_Lineal pila;
    int opcion, dato;

    do
    {
        cout<<"\nMenu de opciones\n";
        cout<<"1. Insertar elemento en la pila\n";
        cout<<"2. Quitar elemento de la pila\n";
        cout<<"3. Ver cima de la pila\n";
        cout<<"4. limpiar pila\n";
        cout<<"5. salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese el elemento a insertar: ";
            cin>>dato;
            try
            {

                pila.InsertarPila(dato);
                cout<<"\tElemento "<<dato<<" insertado en la pila\n";
                

            }catch(exception &e)
            {

                cout<<e.what()<<endl;

            }

        }else if(opcion==2){

            
            try
            {
            
                cout<<"\tElemento "<<pila.QuitarPila()<<" quitado de la pila\n";

            }catch(exception &e){

                cout<<e.what()<<endl;

            }
            

        }else if(opcion==3){

            try
            {
                
                cout<<"\tElemento en la cima de la pila: "<<pila.CimaPila()<<endl;

            }catch(exception &e){
                
                cout<<e.what()<<endl;

            }
            

        }else if(opcion==4){

            pila.LimpiarPila();
            cout<<"\tPila limpiada\n";

        }else if(opcion==5){

            cout<<"\nSaliendo del programa\n";
            break;

        }else{

            cout<<"\tOpcion no valida\n";

        }


    } while (opcion!=5);
    

}