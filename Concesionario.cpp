#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>

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

void LeerDatosClientes(const string &filename, Clientes catalog[], int &catalogSize);
void LeerDatosCarros(const string &filename, Carro catalog[], int &catalogSize);

void LeerDatosClientes(const string &filename, Clientes catalog[], int &catalogSize)
{
    ifstream clientFile(filename);
    string line;
    catalogSize = 0;

    getline(clientFile, line);

    while (getline(clientFile, line))
    {
        stringstream ss(line);

        ss >> catalog[catalogSize].id;
        ss.ignore();
        getline(ss, catalog[catalogSize].first_name, ';');
        getline(ss, catalog[catalogSize].last_name, ';');
        getline(ss, catalog[catalogSize].email, ';');
        ss >> catalog[catalogSize].age;
        ss.ignore();

        catalogSize++;
    }
}

void LeerDatosCarros(const string &filename, Carro catalog[], int &catalogSize)
{
    ifstream carFile(filename);
    string line;
    catalogSize = 0;

    getline(carFile, line);

    while (getline(carFile, line))
    {
        stringstream ss(line);

        ss >> catalog[catalogSize].id;
        ss.ignore();
        getline(ss, catalog[catalogSize].maker, ';');
        getline(ss, catalog[catalogSize].model, ';');
        ss >> catalog[catalogSize].year;
        ss.ignore();
        ss >> catalog[catalogSize].sold_to;
        ss.ignore();
        ss >> catalog[catalogSize].bought_to;
        ss.ignore();
        ss >> catalog[catalogSize].sold_for;
        ss.ignore();
        ss >> catalog[catalogSize].bought_for;
        ss.ignore();

        catalogSize++;
    }
}

void AgregarDatosCarros();
void EliminarDatosCarros();
void ModificarDatosCarros();

void AgregarDatosClientes();
void EliminarDatosClientes();
void ModificarDatosClientes();

void AgregarDatosCarros(){
ofstream archivo_carros("cars_data.csv" , ios::app);
Carro c;

cout<<"Ingrese el id: ";
cin>>c.id;
cout<<"Ingrese la marca del carro: ";
cin>>c.maker;
cout<<"Ingrese el modelo del carro: ";
cin>>c.model;
cout<<"Ingrese el ano del carro: ";
cin>>c.year;
cout<<"Ingrese a quien fue comprado el carro: ";
cin>>c.sold_to;
cout<<"Ingrese a quien fue vendido el carro: ";
cin>>c.bought_to;
cout<<"Ingrese por cuanto fue comprado el carro: ";
cin>>c.sold_for;
cout<<"Ingrese por cuanto fue vendido el carro: ";
cin>>c.bought_for;

archivo_carros<< c.id<< ";"<<c.maker<<";"<<c.model<<";"<<c.year<<";"<<c.sold_to<<";"<<c.bought_to<<";"<<c.sold_for<<";"<<c.bought_for<<endl;
archivo_carros.close();
}

void EliminarDatosCarros(){
    Carro c;
    cout<<"Ingrese el id para saber que carro desea eliminar: ";
    cin>>c.id;
    ofstream temp("temp.csv");
    ifstream archivo_carro("cars_data.csv");
    string linea;

    while(getline(archivo_carro,linea)){
        int id_actual= atoi(linea.substr(0,linea.find(';')).c_str());
        if(id_actual != c.id){
            temp<<linea<<endl;
        }
    }
archivo_carro.close();
temp.close();

remove("cars_data.csv"); 
rename("temp.csv", "cars_data.csv");
cout<<"los datos fueron borrados exitosamente"<<endl;
}

void ModificarDatosCarros(){
Carro c;
cout<<"Ingrese el id del carro que desea modificar: ";
cin>>c.id;

ofstream temp("temp.csv");
ifstream archivo_carros("cars_data.csv");
string linea;

while(getline(archivo_carros,linea)){
    int id_actual = atoi(linea.substr(0,linea.find(';')).c_str());
    if(id_actual==c.id){
cout<<"Ingrese el id: ";
cin>>c.id;
cout<<"Ingrese la marca del carro: ";
cin>>c.maker;
cout<<"Ingrese el modelo del carro: ";
cin>>c.model;
cout<<"Ingrese el ano del carro: ";
cin>>c.year;
cout<<"Ingrese a quien fue comprado el carro: ";
cin>>c.sold_to;
cout<<"Ingrese a quien fue vendido el carro: ";
cin>>c.bought_to;
cout<<"Ingrese por cuanto fue comprado el carro: ";
cin>>c.sold_for;
cout<<"Ingrese por cuanto fue vendido el carro: ";
cin>>c.bought_for;
    }else{
        temp<<linea<<endl;
    }
}
archivo_carros.close();
temp.close();

remove("cars_data.csv");
rename("temp.csv","cars_data.csv");
cout<<"Los datos se modificaron correctamente"<<endl;
}

void AgregarDatosClientes(){
    ofstream archivo_clientes("clients.csv", ios::app);
    Clientes cl;

    cout<<"Ingrese el id: ";
    cin>>cl.id;
    cout<<"Ingrese el nombre del cliente: ";
    cin>>cl.first_name;
    cout<<"Ingrese el apellido del cliente: ";
    cin>>cl.last_name;
    cout<<"Ingrese el email del cliente: ";
    cin>>cl.email;
    cout<<"Ingrese la edad del cliente: ";
    cin>>cl.age;

    archivo_clientes<<cl.id<<";"<<cl.first_name<<";"<<cl.last_name<<";"<<cl.email<<";"<<cl.age<<endl;
    archivo_clientes.close();
}

void EliminarDatosClientes(){
    Clientes cl;

    cout<<"Ingrese el id para saber que cliente desea eliminar: ";
    cin>>cl.id;
    ofstream temp("temp.csv");
    ifstream archivo_clientes("clients.csv");
    string linea;

    while(getline(archivo_clientes,linea)){
        int id_actual= atoi(linea.substr(0,linea.find(';')).c_str());
        if(id_actual != cl.id){
            temp<<linea<<endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("clients.csv");
    rename("temp.csv","clients.csv");
    cout<<"Los datos fueron eliminaros"<<endl;
}

void ModificarDatosClientes(){
    Clientes cl;
    cout<<"Ingrese el id del cliente que desea modificar: ";
    cin>>cl.id;

    ofstream temp("temp.csv");
    ifstream archivo_clientes("clients.csv");
    string linea;
    
    while(getline(archivo_clientes,linea)){
        int id_actual = atoi(linea.substr(0,linea.find(';')).c_str());
    if(id_actual==cl.id){
        cout<<"Ingrese el id: ";
        cin>>cl.id;
        cout<<"Ingrese el nombre: ";
        cin>>cl.first_name;
        cout<<"Ingrese el apellido: ";
        cin>>cl.last_name;
        cout<<"Ingrese el email: ";
        cin>>cl.email;
        cout<<"Ingrese la edad: ";
        cin>>cl.age;
    }else{
        temp<<linea<<endl;
    }
    }
    archivo_clientes.close();
    temp.close();

    remove("clients.csv");
    rename("temp.csv","clients.csv");
    cout<<"Los datos se modificaron de manera exitosa"<<endl;
}

int main(){
    string linea;
    int opcion;
     Carro carsCatalog[2000];
     int carCatalogSize;
    Clientes clientCatalog[250];
    int clientCatalogSize;
    bool opcionvalida = false;
       do{
    cout<<"Que desea hacer?"<<endl
    <<"1. Ver la cantidad de carros comprados y vendidos por clientes."<<endl
    <<"2. Ver cuales carros fueron comprados por clientes."<<endl
    <<"3. Ver cuales carros fueron vendidos por clientes."<<endl
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