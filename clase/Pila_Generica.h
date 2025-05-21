#ifndef PILA_GENERICA_H
#define PILA_GENERICA_H

template<typename T>
class Pila_Generica
{
private:
    
    T* elementos;
    int cima;
    int capacidad;

    void Redimensionar();//aqui funcion interna para aumentar la capacidad 

public:
    Pila_Generica();
    ~Pila_Generica();
};

template<typename T>
Pila_Generica<T>::Pila_Generica()
{

    capacidad=10;//capacidad inicial
    elementos=new T[capacidad];//aqui reservamos el espacio en memoria para los elementos
    cima=-1;//aqui inicializamos la cima en -1, porque no ha elementos en la pila   

}

template<typename T>
Pila_Generica<T>::~Pila_Generica()
{

    delete[] elementos;//aqui liberamos el espacio en memoria reservado para los elementos
    cout<<"Pila destruida\n";

}



#endif // PILA_GENERICA_H