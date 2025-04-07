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
    nuevo_nodo->siguiente=nullptr;
    nuevo_nodo->anterior=nullptr;

    Nodo *auxiliar=lista;
    Nodo *auxiliar2;

    while((auxiliar!=nullptr)&&(auxiliar->dato<n))
    {

        auxiliar2=auxiliar;
        auxiliar=auxiliar->siguiente;

    }
    if(lista==auxiliar)
    {

        lista=nuevo_nodo;

    }else{

        auxiliar2->siguiente=nuevo_nodo;
        nuevo_nodo->anterior=auxiliar2;

    }
    nuevo_nodo->siguiente=auxiliar;

    if(auxiliar!=nullptr)
    {

        auxiliar->anterior=nuevo_nodo;

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

        cout << "Digite un nimero: ";
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