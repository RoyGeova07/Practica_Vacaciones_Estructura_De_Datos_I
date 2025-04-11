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

    //ahora vamos a insertar el primer elemento, por ahora la lista esta vacia va
    //quiero insertar 10 en la lista vacia, bueno primero verifica si aux1 es diferente de null, y no 
    //no es diferente de null por ende no entra al while, y pasa por la condicional donde verifica si 
    //lista y aux1 son iguales.

    //ahora quiero insertar  5 con la lista que ya no esta vaica porque ya tiene el 10, por ende aux1 que 
    //apuntaba a null, ahora apunta a lista, vuelve al ciclo, ahora esta asi =  lista y aux1 -> |10| -> null
    //como estamos insertando los elementos ordenados usaremos este while, aqui moveremos los punteros 
    //el nuevo_nodo q quiero insertar es el 5, como es menor que 10 debe ir al inicio de la lista 
    //aux1 es diferente de null?, si es diferente de null, y aux1 que es 10 es menor que 5? 10 no es menor que 5
    //por lo tanto no entra al while

    //ahora quiero insertar el 12 la lista esta asi lista y aux1 -> |10| -> null, comprobemos si entra a ciclo
    //aux1 es diferente de null? si, si es diferente de null y 10 es menor que 12?, si, si es menor q 12
    //por lo tanto entra al bucle , aux2 es igual a aux1 y aux1 lo corremos al siguiente. Quedaria asi
    // pasa de esto lista y aux1 -> |10| -> null a esto lista y aux2 -> 10 aux1-> null, y nuevamente recorre
    // el while aux1 es diferente de null? no aux1 ya es null, por lo tanto sale del while, por lo tanto queda
    //aux2 y aux1, por lo tanto el 12 va a ir en medio de aux2 y aux1, como queremos incluir el nuevo_nodo que es 12
    //despues del 10 para que nos quede la lista en forma ordenada, lo ponemos gracias al aux2, aux2 siguiente
    // es igual a nuevo_nodo que es 12 y nuevo_nodo siguiente es igual a aux1, osea aux1 apunta ahora a null
    // por lo tanto quedaria asi lista y aux2 -> 10 -> nuevo_nodo -> 12 -> aux1 -> null

    while((aux1!=nullptr)&&(aux1->dato<n))
    {

        aux2=aux1;
        aux1=aux1->siguiente;

    }
    // si la lista y aux1 son iguales, lista se igual al nuevo_nodo, por ende lista ahora apunta al dato
    if(lista==aux1)//sigamos con el 5, 
    {
//                                                                     _
        lista=nuevo_nodo;//lista es igual a 5 = lista y nuevo_nodo -> |5| 
 
    }else{

        aux2->siguiente=nuevo_nodo;

    }
    nuevo_nodo->siguiente=aux1;//y nuevo nodo se mueve al siguiente paso, en  este caso como no hay 
    //nada es null y por ende a aux1 es igual a null

    //esto siempre se cumplira = lista y nuevo_nodo -> |5| aux1 -> |10| -> null
    //como son variables locales cuando la funcion termine, estas variables se eliminaran 
    // por lo tanto la lista quedara asi = lista -> |5| -> |10| -> null

}

void MostrarLista(Nodo *lista)
{

    Nodo *actual=new Nodo();
    actual=lista;

    if(actual==nullptr)
    {

        cout<<"\nLa lista esa vacia"<<endl;
        return;

    }

    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

void BuscarElementos(Nodo *lista,int n)
{

    Nodo *actual=new Nodo();
    actual=lista;
    bool Banderita=false;

    while((actual!=nullptr)&&(actual->dato<=n))
    {

        if(actual->dato==n)
        {

            Banderita=true;

        }
        actual=actual->siguiente;

    }
    if(Banderita==true)
    {

        cout<<"\nEl elemento "<<n<<" se encuentra en la lista."<<endl;

    }else{

        cout<<"\nEl elemento "<<n<<" no se encuentra en la lista."<<endl;

    }
    

}

//para eliminar un elemento de la lista hay q seguir 5 pasos
//1,preguntar si la lista esta vacia
//2. crear un nodo auxiliar y anterior=null
//3. igualar auxiliar al inicio de la lista
//4. recorre la lista
//5. eliminar el elemento de la lista

void EliminarElemento(Nodo *&lista,int n)
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia."<<endl;
        return;

    }

    if(lista!=nullptr)
    {

        Nodo *auxiliar_borrar=new Nodo();
        Nodo *anterior=nullptr;
        auxiliar_borrar=lista;

        while ((auxiliar_borrar!=nullptr)&&(auxiliar_borrar->dato!=n))
        {
            
            anterior=auxiliar_borrar;
            auxiliar_borrar=auxiliar_borrar->siguiente;//esto hace que pase al siguiente nodo

        }
        if(auxiliar_borrar==nullptr)
        {

            cout<<"\nEl elemento no existe";

        //si esta condicional se cumple es porque no se cumplio el while
        }else if(anterior==nullptr){//si el elemento es el primero que queremos eliminar de la lista esta condicional se cumplira

            lista=lista->siguiente;
            delete auxiliar_borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }else{
            
            anterior->siguiente=auxiliar_borrar->siguiente;//esto hara que anterior pase al siguiente nodo, ya se si es un elemento o en null
            delete auxiliar_borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }
        

    }
    

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
        cout<<"5. Salir."<<endl;
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
            BuscarElementos(lista,n);

        }else if(opcion==4){

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            EliminarElemento(lista,n);
            
        }else if(opcion==5){

            cout<<"Saliendo del programa.";
            break;

        }else{

            cout<<"Opcion no valida."<<endl;

        }

    }while(opcion!=5);

}