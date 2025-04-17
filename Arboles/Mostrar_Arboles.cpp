#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*derecho;
    Nodo*izquierdo;

};

Nodo*Arbol=nullptr;

Nodo*CrearNodo(int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->derecho=nullptr;
    nuevo_nodo->izquierdo=nullptr;

    return nuevo_nodo;

}

void InsertarNodo(Nodo*&arbol,int n)
{

    if(arbol==nullptr)
    {

        Nodo *nuevo_nodo=CrearNodo(n);
        arbol=nuevo_nodo;

    }else{

        int ValorRaiz=arbol->dato;

        if(n<ValorRaiz)
        {

            InsertarNodo(arbol->izquierdo,n);
           

        }else{

            InsertarNodo(arbol->derecho,n); 
            

        }

        
    }

}

//el contador nos va ayudar mucho para ordenar el arbol de manera correcta, OJO el contador no va almacenar
//el numero de nodos que tiene el arbol
void MostrarArbol(Nodo*arbol,int contador)
{

    //primero vemos si el arbol no esta vacio
    if(arbol==nullptr)
    {

        return;

    }else{

        //si no esta vacio mostraremos el arbol del lado derecho
        //aqui se usara recursividad
        MostrarArbol(arbol->derecho,contador+1);//se le suma 1 porque empieza desde cero
        //entonces lo primero que va hacer es imprimir el nodo de la derecha, empezando desde la raiz
        //una vez que tenga ese nodo, el siguiente va a tener un espacio mas de separacion y el siguiente
        //2 mas de separacion 

        //aqui viene el contador 
        for(int i=0;i<contador;i++)
        {

            //aqui daremos espacios 
            cout<<"   ";

        }
        cout<<arbol->dato<<endl;//el elemento de cada nodo vamos a imprimirlo

        //despues de imprimir todo el lado derecho, imprimimos todo el lado izquierdo
        MostrarArbol(arbol->izquierdo,contador+1);

    }

}

void Menu()
{

    int dato,opcion,contador=0;
    do
    {
        
        cout<<"\n=====Menu====\n";
        cout<<"1. Insertar un nuevo nodo\n";
        cout<<"2. Mostrar Arbol\n";
        cout<<"3.Salir\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        if (opcion==1)
        {
            
            cout<<"\nDigite un numero: ";
            cin>>dato;
            InsertarNodo(Arbol,dato);
            cout<<"\n";
            

        }
        else if (opcion==2)
        {
            cout<<"\n===Mostrando Arbol====\n";
            MostrarArbol(Arbol,contador);
            cout<<"\n";

        }
        else if(opcion==3)
        {
            cout<<"\nTermino\n";
            break;
        }else
        {
            cout<<"\nOpcion no valida\n";
        }
        
        

    } while (opcion!=3);
    

}

int main()
{

    Menu();

}
