#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*izquierda;
    Nodo*derecha;

};

Nodo*Arbol=nullptr;

Nodo*CrearNodo(int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->derecha=nullptr;
    nuevo_nodo->izquierda=nullptr;

    return nuevo_nodo;

}

void InsertarNodoAArbol(Nodo*&arbol,int n)
{

    if(arbol==nullptr)
    {

        Nodo*nuevo_nodo=CrearNodo(n);
        arbol=nuevo_nodo;

    }else{

        int ValorRaiz=arbol->dato;

        if(n<ValorRaiz)
        {

            InsertarNodoAArbol(arbol->izquierda,n);

        }else{

            InsertarNodoAArbol(arbol->derecha,n);

        }

    }

}

void MostrarArbol(Nodo*arbol,int contador)
{

    if(arbol==nullptr)
    {
        
        return;

    }else{

        MostrarArbol(arbol->derecha,contador+1);

        for(int i=0;i<contador;i++)
        {

            cout<<"   ";

        }
        cout<<arbol->dato<<endl;
        
        MostrarArbol(arbol->izquierda,contador+1);

    }

}

bool BuscarElementoArbol(Nodo*arbol,int n)
{

    if(arbol==nullptr)//primer caso, si el arbol esta vacio
    {

        cout<<"\nNo hay elementos en el arbol\n";
        return false;

    }else if(arbol->dato==n){//segundo caso si el elemento es el primero

        return true;

    }else if(n<arbol->dato){//si el elemento es menor al primer nodo busca a la izquierda

        return BuscarElementoArbol(arbol->izquierda,n);//recurisividad

    }else{//si el elemento es mayor al primer nodo busca a la derecha

        return BuscarElementoArbol(arbol->derecha,n);

    }

    
}

void Menu()
{

    int dato,opcion,contador=0;
    do
    {
        
        cout<<"\n=====Menu====\n";
        cout<<"1. Insertar un nuevo nodo\n";
        cout<<"2. Mostrar Arbol\n";
        cout<<"3. Buscar elemento dentro del arbol\n";
        cout<<"4. Salir\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        if (opcion==1)
        {
            
            cout<<"\nDigite un numero: ";
            cin>>dato;
            InsertarNodoAArbol(Arbol,dato);
            cout<<"\n";
            

        }
        else if (opcion==2)
        {
            cout<<"\n===Mostrando Arbol====\n";
            MostrarArbol(Arbol,contador);
            cout<<"\n";

        }
        else if(opcion==3)
        {
            cout<<"Ingrese el elemento a buscar dentro del arbol: ";
            cin>>dato;
            if(BuscarElementoArbol(Arbol,dato)==true)
            {

                cout<<"\nEl elemento "<<dato<<" SI EXISTE en el arbol\n";

            }else{

                cout<<"\nEl elemento "<<dato<<" NO EXISTE en el arbol\n";                

            }   
            cout<<"\n";
            

        }else if(opcion==4)
        {
            cout<<"\nTermino\n";
            break;
        }else
        {
            cout<<"\nOpcion no valida\n";
        }
        
        
        

    }while(opcion!=4);
    

}

int main()
{

    Menu();

}
