

// para insertar elementos en una pila, hay q seguir 4 pasos

//1. crear el espacio en memoria para almacenar un nodo
//2. cargar el valor dentro del nodo
//3. cargar el puntero pila dentro del nodo(*siguiente)
//4. asignar el nuevo nodo a la pila

#include <iostream>
#include <stdlib.h>//pa new
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo *siguiente;

};

//lo ponemos por referencia porq esta pila va a estar cambiando constantemente
//el n es el dato que se va a insertar en la pila
void AgregarPila(Nodo *&Pila,int n)
{

    //aqui creamos el espacio en memoria para almacenar un nodo
    Nodo *nuevo_nodo=new Nodo();

    //ahora cargamo el valor dentro del nodo
    nuevo_nodo->dato=n;

    //ahora cargamos el puntero pila dentro del nodo siguiente
    nuevo_nodo->siguiente=Pila;

    //ahora asignamos el nuevo nodo a pila
    //lo hacemos porque, nuestra variable debe estar siempre señalando la cima
    Pila=nuevo_nodo;

    cout<<"Elemento "<<n<<" agregado a la pila exitosamente"<<endl;

}

int main()
{

    Nodo *pila=nullptr;
    int n1,n2;
    cout<<"Ingrese un numero: ";
    cin>>n1;
    AgregarPila(pila,n1);

    cout<<"Ingrese otro numero: ";
    cin>>n2;
    AgregarPila(pila,n2);


    return 0;
}

