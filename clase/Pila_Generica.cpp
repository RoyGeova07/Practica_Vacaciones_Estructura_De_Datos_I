#include<iostream>
#include<stdexcept>
using namespace std;

const int MAX_ELEMENTOS=100;

template<typename T>
struct Pila
{
    
    T elementos[MAX_ELEMENTOS];
    int cima=-1;

};

template<typename T>
void Insertar(Pila<T>& pila,T valor)
{

    if(pila.cima>=MAX_ELEMENTOS-1)
    {

        throw underflow_error("Pila llena, no se puede insertar mas elementos.");
        return;

    }
    pila.elementos[++pila.cima]=valor;

}

template<typename T>
T Quitar(Pila<T>& pila)
{

    if(pila.cima<0)
    {

        throw underflow_error("Pila vacia, no se puede quitar elementos.");

    }
    return pila.elementos[pila.cima--];

}



