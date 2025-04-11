#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo
{
    
    char letra;
    Nodo*siguiente;
    Nodo*atras;

};

void InsertarLetra(Nodo*&lista,char c)
{

    Nodo*nueva_letra=new Nodo();
    nueva_letra->letra=c;
    nueva_letra->siguiente=nueva_letra->atras=nullptr;

    if(lista==nullptr)
    {

        lista=nueva_letra;
        nueva_letra->siguiente=nueva_letra;
        nueva_letra->atras=nueva_letra;

    }else{

        Nodo*ultimo=lista->atras;
        ultimo->siguiente=nueva_letra;
        nueva_letra->atras=ultimo;
        nueva_letra->siguiente=lista;
        lista->atras=nueva_letra;

    }

}

bool EsPalindromooo(Nodo*lista)
{

    if(lista==nullptr)return false;

    Nodo*inicio=lista;
    Nodo*fin=lista->atras;

    while(inicio!=fin&&inicio->siguiente!=fin)
    {
        
        if(inicio->letra!=fin->letra){

            return false;

        }
        

        inicio=inicio->siguiente;
        fin=fin->atras;

    }
    return true;
    

}

void MostrarLista(Nodo*lista)
{

    Nodo*actual=lista;
    do
    {
        
        cout<<actual->letra<<" <-> ";
        actual=actual->siguiente;

    } while (actual!=lista);
    cout<<"(inicio)\n";
    

}

int main()
{

    Nodo*lista=nullptr;
    string palabra;
    cout<<"Ingrese una palabra: ";
    cin>>palabra;

    for(char c:palabra)
    {

        InsertarLetra(lista,c);

    }

    MostrarLista(lista);

    if(EsPalindromooo(lista))
    {

        cout<<"\nLa palabra "<<palabra<<" ES PALINDROMO\n";

    }else{

        cout<<"\nLa palabra "<<palabra<<" NO ES UN PALINDROMO\n";

    }

}