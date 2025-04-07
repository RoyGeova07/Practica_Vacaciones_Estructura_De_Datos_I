#include <iostream>
using namespace std;

struct Nodo
{

    int dato;
    Nodo *siguiente;

};


void Insertar(Nodo *&lista,int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;

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

    cout<<"\t Elemento "<<n<< " insertado correctamente ";
    

}

void MostrarLista(Nodo *lista){

    if(lista==nullptr)
    {

        cout<<"\nLista vacia bro.";

    }

    Nodo *actual=new Nodo();
    actual=lista;

    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

void BuscarElementoEnLaLista(Nodo *lista,int n)
{

    Nodo *actual=new Nodo();
    actual=lista;
    bool messi=false;

    while ((actual!=nullptr)&&(actual->dato<=n))
    {
        
        if(actual->dato==n)
        {

            messi=true;

        }
        actual=actual->siguiente;

    }
    if(messi==true)
    {

        cout<<"\nEl elemento "<<n<<" se encuentra en la lista."<<endl;

    }else{

        cout<<"\nEl elemento "<<n<<" no se encuentra en la lista."<<endl;

    }
    
}

void EliminarElementoEnLaLista(Nodo *lista, int n)
{

    if(lista!=nullptr)
    {

        Nodo *borrar=new Nodo();
        Nodo *anterior=nullptr;
        borrar=lista;

        while ((borrar!=nullptr)&&(borrar->dato!=n))
        {
            
            anterior=borrar;
            borrar=borrar->siguiente;

        }
        if(borrar==nullptr)
        {

            cout<<"\nEl elemento no existe";

        }else if(anterior==nullptr){

            lista=lista->siguiente;
            delete borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }else{

            anterior->siguiente=borrar->siguiente;
            delete borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }
        
    }

}

//para eliminar todos los elementos de las pilas 
//para dejar vacia una lista, solo seguir 4 pasos
//1. crear un nodo *aux e igualarlo a la lista
//2. guardar el dato que queremos eliminar dentro de *aux
//3. pasar lista a siguiente nodo
//4. eliminar aux
void EliminarTodaLaLista(Nodo *&lista,int &n)//es igual a la funcion para eliminar los elementos de la pila xd
{

    //esto hara qeu se elimine el primer elemento de la lista
    Nodo *aux=lista;
    n=aux->dato;//aqui guardamos el dato dentro de n ----- lista y aux -> |5| -> |10| -> null
    lista=aux->siguiente;// aux -> |5| -> lista ->|10| -> null
    delete aux;

}

int main()
{

    Nodo *lista=nullptr;
    int n=0;
    int opcion=0;
    do{

        cout<<"\n======MENU DE OPCIONES======="<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista."<<endl;
        cout<<"3. Buscar elemento en la lista."<<endl;
        cout<<"4. Eliminar un elemento de la lista."<<endl;
        cout<<"5. Eliminar la lista"<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un numero: ";
            cin>>n;
            Insertar(lista,n);

        }else if(opcion==2){

            MostrarLista(lista);
            cout<<endl;

        }else if(opcion==3){

                
            cout<<"Ingrese el numero buscar: ";
            cin>>n;
            BuscarElementoEnLaLista(lista,n);

        }else if(opcion==4){

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            EliminarElementoEnLaLista(lista,n);
            
        }else if(opcion==5){

            while (lista!=nullptr)//mientras no sea el final de la lista 
            {
                //seguira sacando todos los elementos de la lista hata llegar null osea vacia
                EliminarTodaLaLista(lista,n);
                cout<<"\nEliminando lista......";
                cout<<n<<" -> ";//se muestra lo que se elimino

            }
            

        }else if(opcion==6){

            cout<<"Saliendo del programa.";
            break;

        }else{

            cout<<"Opcion no valida."<<endl;

        }

    }while(opcion!=6);


}