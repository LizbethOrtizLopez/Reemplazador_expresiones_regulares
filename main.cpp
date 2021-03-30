//Lizbeth Ortiz López
//A00227346
//Matemáticas Computacionales. Proyecto 1
//Reemplazador con expresiones regulares

#include <bits/stdc++.h>

using namespace std;


//variables de cadenas y expresiones
char cadena_original[10002];
char expresion[10002];
string cadena_reemplazar;
string cadena_final;


//variables de longitud
int cadena_n, expresion_n;


int buscar_expresion(char elemento, int pos)
{
    int cont = 0;

    for (int i=0;i<expresion_n;i++)
    {
        if (expresion[i]==elemento)
        {
            if(i!=0 && expresion[i-1]!='+') continue;
            int j = i;
            while(expresion[j]!='+')
            {
                if (cadena_original[pos]==expresion[j])
                {
                    pos++;
                    cont++;
                }
                else if (expresion[j]=='*' || expresion[j+1]=='*')
                {
                    if (expresion[j]=='*') pos--;
                    char aux = cadena_original[pos];
                    while(cadena_original[pos]==aux)
                    {
                        pos++;
                    }
                    cadena_final+=cadena_reemplazar;
                    if (expresion[j]=='*') return pos;
                    return pos-1;
                }
                else if (cadena_original[pos]!=expresion[j])
                {
                    for (int k=pos-cont;k<pos;k++)
                    {
                        cadena_final+=cadena_original[k];
                    }
                    return pos;
                }
                j++;
            }
            cadena_final+=cadena_reemplazar;
            return pos;
        }
    }
    cadena_final+=elemento;
    pos++;
    return pos;
}

void reemplazador()
{
    //busca cada elemento de la cadena original para checar si se pueden reemplazar
    for (int i=0;i<cadena_n;i++)
    {
        //Busca patrones y regresa la nueva i donde ya no se cumpla el patrón
        i = buscar_expresion(cadena_original[i],i);
        i--;
    }
    cout<<"Resultado del reemplazo: "<<cadena_final;
}

int main()
{
    //Mensajes de bienvenida e instrucciones
    cout<< "Bienvenido al Reemplazador de expresiones regulares" << endl;
    cout<< "Debera ingresar \n1. Una cadena original" << '\n';
    cout<< "2. Una expresion regular " <<'\n';
    cout<< "3. Una cadena que reemplazara las ocurrencias de la expresion regular en la cadena original. " <<'\n';

    //Ingreso de datos
    cout<< "Inserte la cadena original: "<< '\n';
    gets(cadena_original);
    cout<< "Inserte la expresion regular: "<<'\n';
    gets(expresion);
    cout<< "Inserte la cadena que reemplazara las ocurrencias: "<<'\n';
    getline(cin,cadena_reemplazar);


    //obtener longitudes de las entradas
    cadena_n = strlen(cadena_original);
    expresion_n = strlen(expresion);

    //reemplazar
    reemplazador();

    return 0;
}
