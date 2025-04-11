#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*siguiente;
    Nodo*atras;

};

void Insertar(Nodo*&lista, int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    //caso 1: lista vacia 
    if(lista==nullptr)
    {

        lista=nuevo_nodo;
        nuevo_nodo->siguiente=lista;
        nuevo_nodo->atras=lista;
        cout<<"\nElemento "<<n<<" insertado correctamente a la lista doblemente circular\n";
        return;

    }

    //caso 2: insertar al inicio (n menor que el primero)
    Nodo*actual=lista;
    if(n<lista->dato)
    {

        Nodo*ultimo=lista->atras;

        nuevo_nodo->siguiente=nuevo_nodo;
        nuevo_nodo->atras=nuevo_nodo;

        ultimo->siguiente=nuevo_nodo;
        lista->atras=nuevo_nodo;

        lista=nuevo_nodo;//nuevo noodo pasa a ser el primero

        cout<<"\nElemento "<<n<<" insertado correctamente a la lista circular doblemente enlazada\n";
        return;

    }

    //caso 3: insertar al medio o al final
    Nodo*aux1=lista;
    while(aux1->siguiente!=lista&&aux1->siguiente->dato<n)
    {
        
        aux1=aux1->siguiente;

    }

    Nodo*siguiente=aux1->siguiente;

    aux1->siguiente=nuevo_nodo;
    nuevo_nodo->atras=aux1;
    nuevo_nodo->siguiente=siguiente;
    siguiente->atras=nuevo_nodo;
    cout<<"\nElemento "<<n<<" insertado correctamente a la lista circular doblemente enlazada\n";

}

void MostrarListaAdelante(Nodo*lista)
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia\n";
        return;

    }
    Nodo*actual=lista;

    cout<<"\nlista hacia adelante\n";
    do
    {
        
        cout<<"["<<actual->dato<<"] <->";
        actual=actual->siguiente;

    } while (actual!=lista);
    cout<<"(inicio)\n";
    

}

void MostrarListaAtras(Nodo*lista)
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia\n";
        return;

    }

    Nodo*ultimo=lista->atras;
    cout<<"\nLa lista hacia atras\n";
    Nodo*actual=ultimo;

    do
    {
        
        cout<<"["<<actual->dato<<"] <->";
        actual=actual->atras;

    } while (actual!=ultimo);
    cout<<"(fin)\n";
    

}

void EliminarElemento(Nodo*&lista,int n)
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia\n";

    }

    Nodo*actual=lista;
    bool encontrado=false;

    //buscamos el nodooooooooooooooooooooooo
    do
    {
        
        if(actual->dato==n)
        {

            encontrado=true;
            break;

        }
        actual=actual->siguiente;
    }while(actual!=lista);

    //si no se encuentraaa
    if(!encontrado)
    {

        cout<<"\nElemento "<<n<<" no encontrado en la lista circular doblemente enlazada\n";
        return;

    }

    //si es el unico nodo
    if(actual->siguiente==actual&&actual->atras==actual)
    {

        delete actual;
        cout<<"\nElemento "<<n<<" eliminado exitosamente de la lista doblemente circular\n";
        return;

    }

    //si es el primer nodo
    if(actual==lista)
    {

        Nodo*ultimo=lista->atras;

        lista=lista->atras;
        lista->atras=ultimo;
        ultimo->siguiente=lista;

        delete actual;
        cout<<"\nElemento "<<n<<" eliminado exitosamente de la lista doblemente circular (Era el primer nodo xd)\n";
        return;

    }

    //nodo si es que el medio o al final
    Nodo*anterior=actual->atras;
    Nodo*siguiente=actual->siguiente;

    anterior->siguiente=siguiente;
    siguiente->atras=anterior;

    delete actual;
    cout<<"\nElemento "<<n<<" eliminado exitosamente de la lista doblemente circular\n";
    return;
    

}
int main()
{

    Nodo *lista=nullptr;
    int n,opcion;



    do{

        cout<<"\n======MENU DE OPCIONES======="<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista inicio."<<endl;
        cout<<"3. Mostrar elementos de la lista fin"<<endl;
        cout<<"4. Eliminar un elemento de la lista."<<endl;
        cout<<"5. Revertir lista."<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un numero: ";
            cin>>n;
            Insertar(lista,n);

        }else if(opcion==2){

            MostrarListaAdelante(lista);
            cout<<endl;

        }else if(opcion==3){
                
            MostrarListaAtras(lista);

        }else if(opcion==4){

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            EliminarElemento(lista,n);
            
        }else if(opcion==5){

            cout<<"Termino"<<endl;
            break;

        }else{

            cout<<"Opcion no valida"<<endl;

        }

    }while(opcion!=5);


}