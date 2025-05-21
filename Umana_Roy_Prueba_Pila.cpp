//ROY UMAÑA '

#include<iostream>
using namespace std;

const int MAX = 1000;

template <typename T>
struct Pila {
    T datos[MAX];
    int tope;

    Pila() 
    {

        tope = -1;

    }

    void Insertar(T valor) 
    {

        if(tope<MAX-1)
        {

            datos[++tope]=valor;

        }

    }

    T Quitar() 
    {

        if(tope>=0)
        {

            return datos[tope--];

        }
        return T(); //aqui si valor por defecto si la pila esta vacia
        
    }

    bool vacia()
    {

        return tope==-1;

    }

    T cima() 
    {

        if(tope>=0)
        {

            return datos[tope];

        }
        return T();

    }
};


bool EsAlfanumerico(char c) 
{

    return (c>='A'&&c<='Z')||(c >='a'&& c<='z')||(c>='0'&&c<='9');

}

bool esPalindromo(char frase[]) {
    Pila<char> pila;
    char filtrada[MAX];
    int len=0;

    for (int i=0;frase[i]!='\0';i++) 
    {

        if (EsAlfanumerico(frase[i])) 
        {

            char c=tolower(frase[i]);
            filtrada[len++]=c;
            pila.Insertar(c);

        }

    }

    for(int i=0;i<len;i++) 
    {

        if (filtrada[i]!=pila.Quitar())
        {

            return false;

        }
    }

    return true;
}

int main() {
    char linea[MAX];

    cout<<"\nDeje el espacio en blanco y le da enter para terminar el programa.\n";
    cout<<"=========================================================================\n";

    while(true)
    {

        cout << "Frase: ";
        cin.getline(linea, MAX);

        if(linea[0]=='\0') 
        {

            cout << "\nTermina el programa.\n";
            break;

        }

        if(esPalindromo(linea)) 
        {

            cout << "La frase es un palindromo.\n\n";

        }else{

            cout << "La frase no es un palindromo.\n\n";

        }

    }

    return 0;
}