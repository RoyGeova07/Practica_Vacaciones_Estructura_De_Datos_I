#include <iostream>

//para insertar elementos en una cola, se siguen 3 pasos

//1. crear un espacio en memeoria para almacenar un nodo
//2. asignar ese nuevo nodo al dato que queremos insertar
//3. asginar los punteros frente y fin hacia el nuevo nodo
using namespace std;
struct Nodo{

    int dato;
    Nodo *siguiente;

};

//aqui ya no es por referencia, porque ya no se va a modificar el puntero frente, solo se va a leer
bool ColaVacia(Nodo *frente)
{

    return (frente==nullptr) ? true:false;

}

void InsertarCola(Nodo *&frente, Nodo *&fin, int n)
{

    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=nullptr;

    if(ColaVacia(frente)){

        frente=nuevo_nodo;

    }else{

        fin->siguiente=nuevo_nodo;

    }
    fin=nuevo_nodo;

    cout<<"Elemento "<<n<<" insertado a la cola correctamente."<<endl;

}

//para eliminar los elemento de una cola, se siguen 3 pasos
//1. obtener el valor del nodo
//2. crear un nodo auxiliar y asignarle el frente de la cola
//3. eliminar el nodo del frente de la cola
// el n es por tipo de referencia, porque lo vamos a eliminar
void EliminarElementosCola(Nodo *&frente,Nodo *&fin, int &n)
{

    n=frente->dato;
    Nodo *auxiliar=frente;

    if(frente==fin)
    {

        frente=nullptr;
        fin=nullptr;

    }else{

        frente=frente->siguiente;

    }
    delete auxiliar;

    

}

int main(){

    Nodo *frente=nullptr;
    Nodo *fin=nullptr;
    int dato;

    cout<<"Ingrese un numero: ";
    cin>>dato;
    InsertarCola(frente,fin,dato);

    
    cout<<"Ingrese un numero: ";
    cin>>dato;
    InsertarCola(frente,fin,dato);

    
    cout<<"Ingrese un numero: ";
    cin>>dato;
    InsertarCola(frente,fin,dato);

    cout<<"Eliminado los elementos de la cola: "<<endl;
    while(frente!=nullptr)
    {
        
        EliminarElementosCola(frente,fin,dato);
        if(frente!=nullptr)
        {

            cout<<dato<<" -> ";

        }else{

            cout<<dato<<" -> null";

        }

    }
    

    return 0;
}