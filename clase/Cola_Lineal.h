#ifndef COLA_LINEAL_H
#define COLA_LINEAL_H
#include<stdexcept>
using namespace std;

typedef int Tipo;  
const int TAMCOLA=49;

class Cola_Lineal
{
protected:
int frente;//indice del elemento en la frente de la cola
int final;
Tipo listaCola[TAMCOLA];

public:
    
    Cola_Lineal(): frente(0),final(-1){};
    //funciones
    bool ColaVacia()const
    {

        return (frente>final)?true:false;

    }

    bool ColaLlena()const
    {

        return (final==TAMCOLA-1)?true:false;//-1 porque el arreglo empieza en 0

    }

    void InsertarCola(Tipo n)
    {

        if(ColaLlena())
        {

            throw overflow_error("Cola llena, no se puede insertar mas elemeentos.");

        }
        listaCola[++final]=n;//aqui aumentamos el final y asignamos el valor al arreglo

    }

    Tipo QuitarCola()
    {

        if(!ColaVacia())
        {

            return listaCola[frente++];//aqui devolvemos el valor de la frente y aumentamos la frente

        }else{

            throw runtime_error("Cola vacia, no se puede quitar elementos.");

        }

        

    }

    Tipo FrenteCola()const
    {

        if(!ColaVacia)
        {

            return listaCola[frente];//aqui devolvemos el valor de el frente

        }else{

            throw runtime_error("Cola vacia, no hay elemetos.");

        }

    }

    void BorrarCola()
    {

        frente=0;//aqui inicializamos la frente en 0, porque no hay elementos en la cola
        final=-1;//aqui inicializamos el final en -1, porque no hay elementos en la cola

    }

   
};



#endif // COLA_LINEAL_H