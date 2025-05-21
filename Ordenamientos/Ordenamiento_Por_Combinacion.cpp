#include<iostream>
#include<vector>
using namespace std;

//Ordenamiento por combinacion
//es una solucion de tipo divide y venceras, esto tiene 3 partes 
//1. dividir nuestro problema en subproblemas para despues para despues 
//2. Conquistar resolver cada uno de esos subproblemas de forma recursiva y al final 
//3. combinar esas soluciones para obtener mi solucion del problema original, usando de forma recursiva 

void Combinar(vector<int>&arreglo,int inicio,int mitad,int final)
{

    int i,j,k;//estos nos va ayudar en los ciclos 
    //creare 2 variables enteras que almacenaran el numero de elementos en la parte izquierda y derecha
    int ElementosIzquierda=mitad-inicio+1;
    int ElementoDerecha=final-mitad;

    //a ambos vectores le vamos a indicar el numero de elementos q va a contener antes de asignarle 
    //los valores finales
    vector<int>Izquierda(ElementosIzquierda);
    vector<int>Derecha(ElementoDerecha);

    //ahora creamos 2 ciclos for van a recorrer los vectores izquierdo y derecho
    for (int i = 0; i <ElementosIzquierda; i++)
    {
        //con finalidad de asignarle los valores que corresponden del vector que queremos ordenar 
        Izquierda[i]=arreglo[inicio+i];

    }
    for (int j = 0; j <ElementoDerecha ; j++)
    {
        
        Derecha[j]=arreglo[mitad+1+j];

    }
    //una vez que se termina la asignacion a ambos vectores vamos a igualar nuestras variables
    // de iteradores a 0
    i=0;
    j=0;
    k=inicio;//k es a inicio que pasamos como parametro en la funcion

    //este ciclo while se va a encargar de mezclar los valores de los vectores izquierdo y derecho
    //en el vector que pasamos por referencia en nuestra funcion, para que se cumpla este ciclo while 
    //la variable j E i deben ser menores al numero de elementos en el vectorIzquierdo y derecho

    
    //la posicion k le correspondera
    while (i<ElementosIzquierda&&j<ElementoDerecha)
    {
        //en caso que el elemento del vector izquierdo se mas pequeño que el elemento del vector derecho    
        if(Izquierda[i]<=Derecha[j])
        {

           //la posicion k le correspondera al vector izquierdo,en la posicion i
           arreglo[k] =Izquierda[i];
           i++;

        }else{

            //en caso contrario, el arreglo en la posicion k, le correspondera al vector derecho en la posiciion[j]
            arreglo[k]=Derecha[j];
            //se aumentara los valores j E i en ambos casos
            j++;

        }
        //y al final de nuestro bloque if aumentaremos el valor de k
        k++;

    }   

    //por ultimo vamos a crear 2 ciclos while que van a vaciar los arreglos izquierdo y derecho,
    //en caso de ser necesario.
    //estos se ejecutaran siempre y cuando los indices i o j sean menores 
    while (j<ElementoDerecha)
    {
        arreglo[k]=Derecha[j];
        j++;
        k++;
    }

    //el numero de los elementos en los vectores
    //entre estos ciclos le aumentaremos los indices j e i y la variable k
    while (i<ElementosIzquierda)
    {
        
        arreglo[k]=Izquierda[i];
        i++;
        k++;

    }
    
    

    
    

}

void MergeSort(vector<int>&arreglo,int inicio,int final)
{

    //caso base 
    if(inicio<final)//este caso considerara si nuestro inicio es menor que nuestro final, si es asi 
    //se seguira llamas recursivas
    {

        //dentro de este caso base,vamos a declarar la variable mitad, que nos indicara, hasta donde dividir el 
        //arreglo 
        int mitad=inicio+(final-inicio)/2;
        //despues volvemos a llamar la misma funcion para dividir las partes izquierdas recursivamente 
        MergeSort(arreglo,inicio,mitad);//la diferencia es que aqui le pasaremos como parametro la variable mitad 
        //ahora la volvemos a llamar la funcion para ahora dividir la parte derecha 
        MergeSort(arreglo,mitad+1,final);

        Combinar(arreglo,inicio,mitad,final);

    }

}

void MostrarArreglo(vector<int>arreglo)
{

    for (int i = 0; i < arreglo.size(); i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    
    

}

int main()
{

    vector<int> prueba1= {5,4,3,1,2,6,8,9,10,7};
    MostrarArreglo(prueba1);
    MergeSort(prueba1,0,prueba1.size()-1);
    MostrarArreglo(prueba1);

    
    return 0;

}