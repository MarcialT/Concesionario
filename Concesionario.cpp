#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct Carro{
int id;        //id
string maker;   //marca
string model;  //modelo
int year;     //ano
int sold_to;   //vendido a
int bought_to;  //comprado a
int sold_for;  //vendido por
int bought_for;  //comprado por
};

struct Clientes{
int id;              //id
string first_name;   //nombre
string last_name;    //apellido
string email;        //email
int age;            //edad
};

int main(){
ifstream archivo_cars("cars_data.csv", ios::in);
ifstream archivo_clients("clients.csv", ios::in);
string linea;
int Carros_comprados, Carros_vendidos;
int opcion;
int opcion_segundoswitch;
bool opcionvalida = false;
       do{
    cout<<"Que desea hacer?"<<endl
    <<"1. Ver la cantidad de carros comprados y vendidos por clientes."<<endl
    <<"2. Ver carros comprados por clientes."<<endl
    <<"3. Ver carros vendidos por clientes."<<endl
    <<"4. Ver datos del comprador de un carro."<<endl
    <<"5. Ver datos del vendedor de un carro."<<endl
    <<"6. Mostrar balance de un carro"<<endl
    <<"7. Modificar datos"<<endl;
    cin>>opcion;

if(opcion>=1 && opcion<=7){
opcionvalida = true;
}else{
    cout<<"Opcion invalida, por favor coloque una opcion dentro del rango dado"<<endl;
opcionvalida = false;
}
}while(!opcionvalida);

switch (opcion){

    case 1:
    cout<<"Cantidad de carros comprados y vendidos por clientes"<<endl;
    break;

    case 2:
    cout<<"Lista de carros comprados por clientes"<<endl;
    break;

    case 3:
    cout<<"Lista de carros vendidos por clientes:"<<endl;
    break;

    case 4:
    cout<<"Datos del comprador de un carro:"<<endl;
    break;

    case 5:
    cout<<"datos del vendedor de un carro:"<<endl;
    break;

    case 6:
    cout<<"Balance de un carro:"<<endl;
    break;

    case 7:
    cout<<"Editar datos:"<<endl;
    break;
}
}