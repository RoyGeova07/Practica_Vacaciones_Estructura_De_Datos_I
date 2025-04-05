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


int main(){

    Nodo *frente=nullptr;
    Nodo *fin=nullptr;
    int dato;


    cout<<"Digitte un numero: ";
    cin>>dato;
    InsertarCola(frente,fin,dato);

    return 0;
}