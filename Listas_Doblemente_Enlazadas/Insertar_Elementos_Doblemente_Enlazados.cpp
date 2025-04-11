#include <iostream>
using namespace std;

//cuando se habla de una lista enlazada, son como vagones de trenes, donde en la lista enlazada simple
//cada vagon dividido en dos partes,  la inforamcion y el puntero -> {info|puntero} que apunta al siguiente vagon

//cuando se habla de listas doblemente enlazadas, hablamos que tenemos 2 punteros, uno que apunta al siguiente
//y otro que apunta al anterior

struct Nodo
{

    int dato;
    Nodo *siguiente; //puntero al siguiente nodo
    Nodo *anterior;  //puntero al nodo anterior

};

void Insertar(Nodo *&lista, int n)
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
        nuevo_nodo->anterior=aux2;

    }
    nuevo_nodo->siguiente=aux1;

    if(aux1!=nullptr)
    {

        aux1->anterior=nuevo_nodo;

    }

    cout<<"\n\tElemento "<<n<<" insertado correctamente a la lista doble"<<endl;

}

void MostrarLista(Nodo *lista)
{

    Nodo *actual=lista;
    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" <-> ";
        actual=actual->siguiente;

    }
    cout<<"null";
    

}

void Menu()
{

    Nodo *lista=nullptr;
    int dato;
    char respuesta;

    do {

        cout << "Digite un numero: ";
        cin >> dato;
        Insertar(lista, dato);

        cout << "Desea insertar otro numero? (s/n): ";
        cin >> respuesta;

    } while (respuesta=='s'||respuesta=='S');

    MostrarLista(lista);

}

int main()
{

    Menu();

    return 0;
}