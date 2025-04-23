#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Nodo
{
    
    char letra;
    Nodo*siguiente;

};


void InsertarLetra(Nodo*&lista,char c)
{

    Nodo *nueva_letra=new Nodo();
    nueva_letra->letra=c;
    nueva_letra->siguiente=nullptr;

    if(lista==nullptr)
    {

        lista=nueva_letra;

    }else{

        Nodo*aux1=lista;
        while(aux1->siguiente!=nullptr)
        {
            
            aux1=aux1->siguiente;
          
        }
        aux1->siguiente=nueva_letra;
        

    }

}

bool EsPalindromo(Nodo *lista)
{

    string Palabra;
    string inversa;
    Nodo*aux1=lista;
    while(aux1!=nullptr)
    {
        
        Palabra+=aux1->letra;
        aux1=aux1->siguiente;

    }
    inversa=Palabra;
    reverse(inversa.begin(),inversa.end());
    return Palabra==inversa;
    

}   

void Revertir(Nodo*&lista)
{


    Nodo*actual=lista;
    Nodo*anterior=nullptr;
    Nodo*siguiente=nullptr;
    while (actual!=nullptr)
    {
        
        siguiente=actual->siguiente;
        actual->siguiente=anterior;
        anterior=actual;
        actual=siguiente;

    }
    lista=anterior; 
    


}

int main()
{

    Nodo*lista=nullptr;
    string palabra;

    cout<<"Ingrese una palabra: ";
    cin>>palabra;

    for(char c:palabra){

        InsertarLetra(lista,c);

    }

    if(EsPalindromo(lista))
    {

        cout<<"La palabra SI ES un palindromo\n";

    }else{

        cout<<"La palabra NO ES un palindromo\n";

    }

}