#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo *siguiente;
    Nodo *atras;

};


void InsertarDoble(Nodo *&lista, int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=nullptr;
    nuevo_nodo->atras=nullptr;

    Nodo *aux1=lista;//ambos apuntan null por ahora
    Nodo *aux2;

    //ordenamos la lista al insertar de menor a mayor
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
        nuevo_nodo->atras=aux2;

    }
    nuevo_nodo->siguiente=aux1;

    if(aux1!=nullptr)
    {

        aux1->atras=nuevo_nodo;

    }
    cout<<"\nElemento "<<n<<" insertado correctamente a la lista circular";

}

void MostrarLista(Nodo *lista)
{

    Nodo *actual=new Nodo();
    actual=lista;
    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" <-> ";
        actual=actual->siguiente;

    }
    cout<<"null";
    

}

void EliminarElemento(Nodo *&lista, int n) 
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia";

    }
    if(lista!=nullptr)
    {

        Nodo *aux1=new Nodo();
        Nodo *aux2=nullptr;
        aux1=lista;

        while ((aux1!=nullptr)&&(aux1->dato!=n))
        {
            
            aux2=aux1;
            aux1=aux1->siguiente;

        }
        if(aux1==nullptr)
        {

            cout<<"\nEl elemento no existe";

        }else if(aux2==nullptr){//si el nodo es el primero de la lista

            lista=lista->siguiente;
            delete aux1;
            cout<<"\nElemento eliminado"<<n<<" exitosamente";

        }else{//si el nodo es en la mitad o ultimo

            aux2->siguiente=aux1->siguiente;
            delete aux1;
            cout<<"\nElemento eliminado "<<n<<" exitosamente";

        }


    }

}

void BuscarElementosDoble(Nodo *lista,int n)
{

    Nodo *actual=new Nodo();
    actual=lista;
    bool bandera=false;
    while ((actual!=nullptr)&&(actual->dato<=n))
    {
        
        if(actual->dato==n){

            bandera=true;

        }
        actual=actual->siguiente;

    }
    if(bandera==true)
    {

        cout<<"\nElemento "<<n<<" EXISTE en la lista doble";

    }else{

        cout<<"\nElemento "<<n<<" NO EXISTE en la lista doble";

    }   
    

}

void RevertirLista(Nodo *&lista)
{

    if(lista==nullptr)
    {

        cout<<"\nLista vacia, no se puede revertir";
        return;

    }

    Nodo *actual=new Nodo();
    actual=lista;
    Nodo *aux2=nullptr;

}

int main()
{

    Nodo *lista=nullptr;
    int n,opcion;



    do{

        cout<<"\n======MENU DE OPCIONES======="<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista."<<endl;
        cout<<"3. Buscar elemento en la lista."<<endl;
        cout<<"4. Eliminar un elemento de la lista."<<endl;
        cout<<"5. Revertir lista."<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un numero: ";
            cin>>n;
            InsertarDoble(lista,n);

        }else if(opcion==2){

            MostrarLista(lista);
            cout<<endl;

        }else if(opcion==3){

                
            cout<<"Ingrese el numero buscar: ";
            cin>>n;
            BuscarElementosDoble(lista,n);

        }else if(opcion==4){

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            EliminarElemento(lista,n);
            
        }else if(opcion==5){

            RevertirLista(lista);

        }else if(opcion==6){

            cout<<"Termino"<<endl;
            break;

        }else{

            cout<<"Opcion no valida"<<endl;

        }

    }while(opcion!=5);


}