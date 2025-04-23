#include<iostream>
using namespace std;

struct Nodo
{
    
    Nodo*siguiente;
    int dato;

};

void InsertarDeMenorAMayor(Nodo*&lista,int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo*aux1=lista;
    Nodo*aux2;

    while ((aux1!=nullptr)&&(aux1->dato<n))
    {
        
        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1)
    {

        lista=nuevo_nodo;

    }else{

        aux2->siguiente=nuevo_nodo;

    }
    nuevo_nodo->siguiente=aux1;
    
}

void InsertarDeMayorAMenor(Nodo*&lista,int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo*aux1=lista;
    Nodo*aux2;

    while ((aux1!=nullptr)&&(aux1->dato>n))
    {
        
        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1)
    {

        lista=nuevo_nodo;

    }else{

        aux2->siguiente=nuevo_nodo;

    }
    nuevo_nodo->siguiente=aux1;
    

}

void MostrarLista(Nodo*lista)
{

    Nodo*actual=lista;

    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

void BuscarElemento(Nodo*lista,int n)
{

    Nodo*actual=lista;
    bool encontrado=false;
    while ((actual!=nullptr)&&(actual->dato<=n))
    {
        
        if(actual->dato==n)
        {

            encontrado=true;
          

        }
        actual=actual->siguiente;

    }
    if(encontrado==true)
    {

        cout<<"\nElemento "<<n<<" encontrado exitosamente\n";

    }else{

        cout<<"\nElemento "<<n<<" NO Existe en la lista\n";

    }
    

}

void RevertirLista(Nodo*&lista)
{

    Nodo*anterior=nullptr;
    Nodo*siguiente=nullptr;
    Nodo*actual=lista;

    while (actual!=nullptr)
    {
        
        siguiente=actual->siguiente;
        actual->siguiente=anterior;
        anterior=actual;
        actual=siguiente;

    }
    lista=anterior;
    cout<<"\nLista revertida\n";


}

int main()
{

    Nodo *lista=nullptr;
    Nodo *listamenor=nullptr;
    int n=0;
    int opcion=0;
    do{

        cout<<"\n======MENU DE OPCIONES======="<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista."<<endl;
        cout<<"3. Buscar elemento en la lista."<<endl;
        cout<<"4. Mostrar menor"<<endl;
        cout<<"5. Revertir lista"<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un numero: ";
            cin>>n;
            InsertarDeMayorAMenor(lista,n);
            InsertarDeMenorAMayor(listamenor,n);

        }else if(opcion==2){

            MostrarLista(lista);
            cout<<endl;

        }else if(opcion==3){

                
            cout<<"Ingrese el numero buscar: ";
            cin>>n;
            BuscarElemento(lista,n);

        }else if(opcion==4){

            MostrarLista(listamenor);
            cout<<endl;
            
        }else if(opcion==5){

            RevertirLista(lista);

        }else if(opcion==6){

           

        }else{


            
        }

    }while(opcion!=7);

}