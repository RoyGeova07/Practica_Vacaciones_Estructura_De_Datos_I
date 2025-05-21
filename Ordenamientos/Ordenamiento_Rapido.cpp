#include<iostream>
using namespace std;

void Intercambiar(int& a,int&b)
{

    int aux=a;
    a=b;
    b=aux;

}

void QuickSort(int arr[],int izq,int der)
{

    int i=izq,j=der;
    int pivote=arr[(izq+der)/2];
    while(i<=j)
    {
        while(arr[i]<pivote)i++;
        while(arr[j]>pivote)j--;

        if(i<=j)
        {

            Intercambiar(arr[i],arr[j]);
            i++;
            j--;

        }

       
    }

    if(izq<j)
    QuickSort(arr,izq,j);
    if(i<der)
    QuickSort(arr,i,der);

}

int main()
{

    int arr[]={56,4,78,9,77,22,88,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Arreglo original: \n";
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";

    }
    cout<<endl;
    QuickSort(arr,0,n-1);
    cout<<"Arreglo ordenado: \n";
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";

    }
    cout<<endl;

    return 0;


}