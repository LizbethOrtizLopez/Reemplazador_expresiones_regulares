//Lizbeth Ortiz L�pez
//A00227346
//Matem�ticas Computacionales. Proyecto 1
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

    for (int i=0;i<expresion_n;i++){ //Recorremos los n elementos de la expresi�n regular
        if (expresion[i]==elemento){ //Entramos si hay coincidencia entre la expresi�n y la cadena original
            if(i!=0 && expresion[i-1]!='+'){
                continue; //verifica que si existe coincidencia se trate de un nuevo patr�n, si no, se salta
            }
            int j = i;
            bool es_patron = false;
            while(expresion[j]!='+' && j<expresion_n){ //verifica todo el patr�n
                if (cadena_original[pos]==expresion[j]){ //aumenta la posici�n y sigue indicando que es patr�n
                    es_patron = true;
                    pos++;
                    cont++;
                }
                else if (expresion[j]=='*' || expresion[j+1]=='*'){ //entra si la expresi�n regular tiene una cerradura estrella
                    if (expresion[j]=='*') pos--;
                    char aux = cadena_original[pos];
                    while(cadena_original[pos]==aux) { //aumenta la posici�n mientras la ocurrencia sea igual a la cerradura
                        pos++;
                    }
                    cadena_final+=cadena_reemplazar; //a�ade el elemento a reemplazar a la cadena final
                    if (expresion[j]=='*'){
                        return pos;
                    }
                    return pos-1;
                }
                else if (cadena_original[pos]!=expresion[j]){ //entra si el patr�n se rompe
                    es_patron=false; //indica ya no es un patr�n
                    break;
                }
                j++;
            }
            if (es_patron){//entra si es un patr�n y nunca se top� con una cerradura
                cadena_final+=cadena_reemplazar; //a�ade el elemento a reemplazar a la cadena final
                return pos;
            }
        }
    }
    if (cont!=0){ //entra cuando se rompi� el patr�n y a�ade todos los elementos que no coincidieron al patr�n
        for (int k=pos-cont;k<pos;k++){
            cadena_final+=cadena_original[k];
        }
        return pos;
    }
    cadena_final+=elemento; //a�ade el elemento si el car�cter ni siquiera correponde a la expresi�n regular
    pos++;
    return pos;
}

void reemplazador()
{
    //busca cada elemento de la cadena original para checar si se pueden reemplazar
    for (int i=0;i<cadena_n;i++){
        //Busca patrones y regresa la nueva i donde ya no se cumpla el patr�n
        i = buscar_expresion(cadena_original[i],i);
        i--;
    }
    cout<<"Resultado del reemplazo: "<<cadena_final;
}

int main()
{
    //Mensajes de bienvenida e instrucciones+
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
