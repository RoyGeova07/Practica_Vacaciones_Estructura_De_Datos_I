#ifndef PILA_LINEAL_H
#define PILA_LINEAL_H

//BUSCAR
typedef int Datos;
const int TAMPILA=49;
class Pila_Lineal
{
private:
    
    int cima;//indice del elemento en la cima de la pila
    Datos lisPila[TAMPILA];//arreglo que almacena los elementos de la pila

public:

    Pila_Lineal();//constructor
    //funciones
    void InsertarPila(Datos n);//insertar elemento en la pila
    Datos QuitarPila();//quitar elemento de la pila
    void LimpiarPila();//limpiar pila
    Datos CimaPila();//es para saber donde esta la cima de la pila
    bool pilaVacia();
    bool pilaLlena();
    
};







#endif // PILA_LINEAL_H