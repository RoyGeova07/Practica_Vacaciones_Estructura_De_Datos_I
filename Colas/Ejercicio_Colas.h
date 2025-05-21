#ifndef COLA_H
#define COLA_H
#include<iostream>
using namespace std;

template<typename T>
struct Nodo
{
    
    T dato;
    Nodo*siguiente;
    Nodo(T valor):dato(valor),siguiente(nullptr){}

};

template<typename T>
class Cola{

private: 
    Nodo<T>*frente;
    Nodo<T>*atras;

public:

    Cola():frente(nullptr),atras(nullptr){}

    bool Estavacio()const
    {

        return frente==nullptr;

    }

    ~Cola()
    {

        while(!Estavacio())
        {

            Desencolar();

        }

    }

    void Insertar(T valor)
    {

        Nodo<T>*nuevo=new Nodo<T>(valor);

        if(Estavacio())
        {

            frente=atras=nuevo;


        }else{

            atras->siguiente=nuevo;
            atras=nuevo;

        }

    }

    void Desencolar()
    {

        if(Estavacio())
        {

            cout<<"\nCola vacia\n";
            return;

        }
        Nodo<T>*aux=frente;
        frente=frente->siguiente;
        cout<<"Elemento eliminado "<<aux->dato<<endl;
        delete aux;
        if(frente==nullptr)atras=nullptr;


    }

    void Mostrar()const
    {

        if(Estavacio())
        {

            cout<<"\nCola vacia\n";
            return;

        }
        Nodo<T>*actual=frente;
        while (actual!=nullptr)
        {
            
            cout<<actual->dato<<" -> ";
            actual=actual->siguiente;

        }
        cout<<"nullptr"<<endl;
        

    }

};


#endif // COLA_H
