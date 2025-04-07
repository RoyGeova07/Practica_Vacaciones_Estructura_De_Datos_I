#include <iostream>
using namespace std;

struct Nodo{

    int dato;
    Nodo *siguiente;

};

void InsertarElementosALista(Nodo *&lista, int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;

    while((aux1!=nullptr)&&(aux1->dato<n))
    {
        
        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1)
    {

        lista=nuevo_nodo;

    }else{

        aux2->siguiente=nuevo_nodo;

    }
    
    

}

//para mostar elementos de la lista hay q seguir 3 pasos
//1. crear un nodo auxiliar 
//2. igular ese nodo a la lista
//3. recorrer la lista con un while y mostrar los elementos de la lista
// no es por referencia porque su valor no va a cambiar 
void MostrarLista(Nodo *lista)
{

    Nodo *actual=new Nodo();
    actual=lista;
    //ejemplo grafico:
    // lista y actual -> |5| -> |7| -> |9| -> null 
    //osea lista y actual los 2 esa apuntando a los elemento de la lista
    //ahora el while nos ayudara a recorrer la lista y mostrar los elementos de la lista

    //si actual es igual a null, significa q ya reccorrimos toda la lista y no hay nada mas q mostrar

    while (actual!=nullptr)
    {
        
        //ahora solamente se mostrara el dato del nodo actual
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;//ahora actual apunta al siguiente nodo de la lista

    }
    

}

int main()
{

    Nodo *lista=nullptr;
    int n;
    cout<<"ingrese un numero: ";
    cin>>n;
    InsertarElementosALista(lista,n);
    
    cout<<"ingrese un numero: ";
    cin>>n;
    InsertarElementosALista(lista,n);

    
    cout<<"ingrese un numero: ";
    cin>>n;
    InsertarElementosALista(lista,n);

    MostrarLista(lista);
    cout<<endl;

}