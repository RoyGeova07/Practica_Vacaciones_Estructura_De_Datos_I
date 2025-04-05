#include <iostream>

struct Nodo{

    int dato;
    Nodo *siguiente;

};

//para poder insertar elementos en una lista solo hay q seguir 4 pasos
//1. crear un nuevo nodo
//2. asginar un nuevo nodo -> dato el elemento que queremos incluuir a la lista
//3. crear 2 nodos auxiliares y asginar la lista al primero de ellos 
//4. insertar elemento a la lista

void InsertarALista(Nodo *&lista,int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;//aux1 ->null y lista ->null
    Nodo *aux2;

    //tambien esto nos sirve para agregar los elementos ordenadamente a la lista
    lista=nuevo_nodo;//ahora la lista apunta al nuevo nodo lista-> n que es el dato que queremos insertar
    //ahora pasamos a aux1 a null
    nuevo_nodo->siguiente=aux1;// y ahora el nuevo nodo lo pasamos a siguiente que seria null

    //ejemplo: si la lista solo tiene un elemento y es 5 y el nuevo nodo es 3
    //ahora la lista apunta al nuevo nodo lista-> n que es el dato que queremos insertar
    
    //como no entra un numero menor al dato que ya tenemos al while, se insertara al inicio de la lista 

    //como es un numero menor se insertara al inicio de la lista

    //ejemplo grafico:s
    //lista y aux1 -> |5| quiero insertar 3
    //  
    //  como no entra al while, se insertara al inicio de la lista
    //lista y nuevo_nodo -> |3|  aux1 -> |5| -> null
    
    //ahora un ejemplo con para insertar un numero en medio de la lista o al final de la lista 

    //ejemplo: si la lista solo tiene un elemento y es 5 y el nuevo nodo es 7
    // este entrara al while!!!!

    //el while nos servira para nosotros tener en orden a nuestro elementos  al momento de insertarlos
    //se insertaran de menor a mayor
    while((aux1!=nullptr)&&(aux1->dato<n))//con este while moveremos un par de punteros
    {

        //aqui entra el nodo auxiliar2
        aux2=aux1;//aux2 apunta a aux1 que es el nodo que tiene el dato 5
        aux1=aux1->siguiente;//ahora aux1 apunta al siguiente nodo que es null

        //ejemplo grafico:

        //lista y aux1 -> |5| -> null ----- quiero insertar 7
        //lista y aux2 -> |5| aux1->  null

        //ahora este hace que recorra de nuevo el while y como aux1 es null, se saldra del while
    }
    //ahora este condicional se cumplira siempre y cuando el elemento vaya al principio de la lista
    if(lista==aux1)//si este condicional se cumple, significa que no entro al while y 
    //el nuevo nodo que queremos insertar es menor al primer elemento de la lista, por lo tanto se insertara al inicio de la lista
    {

        lista=nuevo_nodo;

    }else{//si este else se cumple, significa que el elemento que queremos insertar es mayor al primer elemento de la lista
        //por ende si se cumple esto significa que ha entrado al while y el nuevo nodo se insertara entre los nodos de la lista
        aux2->siguiente=nuevo_nodo;
       
    }
    nuevo_nodo->siguiente=aux1;


}