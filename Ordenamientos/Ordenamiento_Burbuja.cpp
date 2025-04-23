#include<iostream>
using namespace std;

//Metodo Burbuja
//Es un sencillo algoritmo de ordenamiento. Funciona revisando cada elemento de la lista que va ser
//ordenada con el siguiente intercambiandolos de posicion si estan en el orden equivocado. Es necesario
//revisar varias veces toda la lista hasta que no se necesiten mas intercamiarlos, lo cual significa 
//que la lista esta ordenada

//hace que los numeros mas livianos, suban hasta arriba como una busbuja en una gaseosa 

int main(){

    int numeros[]={4,1,2,3,5};

    int aux;

    for (int i = 0; i < 5; i++)
    {
        
        for (int j = 0; j < 5; j++)
        {
                        //siguiente
            if(numeros[j]>numeros[j+1])
            {

                //aqui intercambio con aux
                aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux; 

            }

        }
        

    }

    cout<<"Muestra Ascendente\n";
    for (int i = 0; i < 5; i++)
    {
        
        cout<<numeros[i]<<" ";

    }
    
    

    return 0;
}