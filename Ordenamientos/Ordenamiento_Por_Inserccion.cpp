#include<iostream>
using namespace std;

//ordenamiento por inserccion
//Es una manera muy natural de ordenar para un ser humano, y puede usarse facilmente para ordenar un mazo
//de cartas numeradas en forma arbitraria o sea aleatoria. Requiere un orden de o N al cuadrado de operaciones
//para ordenar una lista de n elementos

//Ejemplo 5,3,4,1,2
int main()
{

    int numeros[]={4,2,3,1,5};
    int posicion,aux;

    //ORDENAMIENTO POR INSERCCION
    for (int i = 0; i < 5; i++)
    {
        
        posicion=i;//posicion sera mi flechita
        aux=numeros[i];
        //se comparara siempre y cuando posicion sea mayor que 0 y ademas si numeroizquierda es mayoir a numeroactual aux
                            // numeros a us izquierda es mayor al numero actual
        while ((posicion>0)&&(numeros[posicion-1]>aux))
        {
            
            //aqui hacemos el cambio
            numeros[posicion]=numeros[posicion-1];//aqui ya estamos haciendo el intercambio de dichos numeros
            //son iteraciones hacia atras, por ende se decrementa la posicion
            posicion--;

        }
        numeros[posicion]=aux;//esto es para que vaya refrescando en cada iteracion del bucle, en que numero vamos
        

    }

    cout<<"Orden ascendente\n";
    for (int i = 0; i <5; i++)
    {
        
        cout<<numeros[i]<<" ";

    }
    
    

    return 0;
}