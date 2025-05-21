#include<iostream>
#include<vector>
using namespace std;

//el ordenamiento rapido
//trata de dividir 1. dividir
//2. conquistar
//3. combinar

// al dividir en un lado izquierdo, se mueven los elementos mas pequeños y al lado derecho los elementos
// derechos

//este ejemplo se hara con vectores

int Particion(vector<int>&arreglo,int inicio,int final)
{

    int pivote=arreglo[inicio];
    int i=inicio+1;
    for (int j = i; j <=final ; j++)
    {
        
        if(arreglo[j]<pivote)
        {

            //el swap intercambia el valor de 2 valores 
            swap(arreglo[i],arreglo[j]);
            i++;

        }

    }
    swap(arreglo[inicio],arreglo[i-1]);
    return i-1;
    

}

//un entero representa el inicio de nuestro arreglo y el otro al final 
void QuickSort(vector<int>&array,int inicio,int final)
{

    //caso base
    //nuestro caso base evaluara en cada llamada recursiva si, nuestro inicio el vector, es menor que el final
    if(inicio<final)//lo que se quiere lo grar con esto es que se seleccione un pivote de particion en el
    //arreglo dejando los elementos mas chicos del pivote al izquierda y los mas grande a la derecha 
    {

        int pivote=Particion(array,inicio,final);
        QuickSort(array,inicio,pivote-1);
        QuickSort(array,pivote+1,final);

    }

}

void Imprimir(vector<int>arreglo)
{

    for (int i = 0; i < arreglo.size(); i++)
    {

        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    

}

int main()
{

    vector<int>arreglo={15,0,2,10,20,17,5};
    Imprimir(arreglo);
    //el 0 representa el indice del arreglo, por donde se inicia
    QuickSort(arreglo,0,arreglo.size()-1);
    Imprimir(arreglo);


    return 0;

}




