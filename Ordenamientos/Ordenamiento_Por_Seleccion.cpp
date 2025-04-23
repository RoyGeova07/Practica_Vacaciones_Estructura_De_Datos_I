#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

//ordenamiento por seleccion
//Es un algoritmo que requiere un orden n al cuadrado de operaciones
//para ordenar una lista de n numeros. Su funcionamiento es el siguiente: 

//1. Buscar el minimo elemento de lista
//2. Intercambiar con el primer elemento
//3. Buscar el minimo del resto de la lista
//4. Intercambiar con el segundo 
//5. y asi sucesivamente

//ejemplo de arreglo
//4,3,1,5,2
//0,1,2,3,4

void MostrarArreglo(int numeros[],int tamanio,int paso)
{

    cout<<"Paso "<<paso<<": ";
    for (int i = 0; i < tamanio; i++)
    {
        
        cout<<numeros[i]<<" ";

    }
    cout<<endl;

    this_thread::sleep_for(chrono::milliseconds(1000));//pausa de un segundo
    

}


int main()
{

    int numeros[]={5,3,4,1,2};
    int tamanio=5;
    int paso=1;
    int aux,min;

    cout<<"Arreglo originial\n";
    MostrarArreglo(numeros,tamanio,0);

    //Algoritmo del ordenamiento por seleccion
    //este for primero recorrera todo mi arreglo, hasta que i sea mejor a 5 
    for (int i = 0; i < tamanio; i++)//el iterador i, representa la posicion en donde se va a colocar 
    //el siguiente numero mas pequeño
    //en cada vuelta del ciclo i, hace lo siguiente

    {
        
        min=i;//aqui se asume que el elemento mas pequeño es el menor, el actual
        cout<<"\nBuscando minimo desde la posicion "<<i<<"..\n";
        for (int j=i+1;j<tamanio;j++)//luego este iterador j busca los siguientes al indice i, buscando el menor elemento
        {
            cout<<"   comparando "<<numeros[j]<<" con "<<numeros[min];
            // 5    es menor a 3? si
            if(numeros[j]<numeros[min])//aqui esta condicional ordenara los elementos, empezara desde el segundo numero
            {

                min=j;//entonces ponemos a 3 como mimimo y asi seguir sucesivamente
                cout<<"     Nuevo minimo encontrado: "<<numeros[min]<<" en posicion "<<min;

            }
            cout<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));

        }
        if(min!=i)
        {

            cout<<" Intercambiando "<<numeros[i]<<" con "<<numeros[min]<<endl;
            
            //aqui haremos el intercambio 
            aux=numeros[i];//aqui guarda temporalmente el valor que esta en numeros[i] = aux = 5
            numeros[i]=numeros[min];//aqui sustituye el valor en la posicion i con el valor mas pequeño encontrado, numeros[0]=numeros[2]=1
            numeros[min]=aux;//con esto coloca el valor original de numeros[i] (guardado en aux) en la posicion donde estaba el minimo numeros[2]=5

        }else{

            cout<<" Ya esta en la posicion correcta: " <<numeros[i]<<endl;

        }
        MostrarArreglo(numeros,tamanio,paso);
        paso++;

    }
    cout<<"Orden ascendente: \n";
    for (int i = 0; i < 5; i++)
    {
        
        cout<<numeros[i]<<" ";

    }
    

    return 0;    
}