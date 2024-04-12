#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Carro
{
public:
    int id;         // id
    string maker;   // marca
    string model;   // modelo
    int year;       // ano
    int sold_to;    // vendido a
    int bought_to;  // comprado a
    int sold_for;   // vendido por
    int bought_for; // comprado por

    Carro() : id(0), maker(""), model(""), year(0), sold_to(0), bought_to(0), sold_for(0), bought_for(0) {}

    void LeerDatosCarros(const string &filename, Carro catalog[], int &catalogSize);
    void AgregarDatosCarros();
    void EliminarDatosCarros();
    void ModificarDatosCarros();
};

class Clientes
{
public:
    int id;            // id
    string first_name; // nombre
    string last_name;  // apellido
    string email;      // email
    int age;           // edad

    Clientes() : id(0), first_name(""), last_name(""), email(""), age(0) {}

    void LeerDatosClientes(const string &filename, Clientes catalog[], int &catalogSize);
    void AgregarDatosClientes();
    void EliminarDatosClientes();
    void ModificarDatosClientes();
};

void Clientes::LeerDatosClientes(const string &filename, Clientes catalog[], int &catalogSize)
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

void Carro::LeerDatosCarros(const string &filename, Carro catalog[], int &catalogSize)
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

void Carro::AgregarDatosCarros()
{
    ofstream archivo_carros("data/cars_data.csv", ios::app);
    ifstream archivo_carros2("data/cars_data.csv");
    string linea;
    Carro c;
    int nuevo_id = 0;

    while (getline(archivo_carros2, linea))
    {
        nuevo_id++;
    }

    cout << "Ingrese la marca del carro: ";
    getline(cin, c.maker);
    cout << "Ingrese el modelo del carro: ";
    getline(cin, c.model);
    cout << "Ingrese el ano del carro: ";
    cin >> c.year;
    cout << "Ingrese a quien fue comprado el carro: ";
    cin >> c.sold_to;
    cout << "Ingrese a quien fue vendido el carro: ";
    cin >> c.bought_to;
    cout << "Ingrese por cuanto fue comprado el carro: ";
    cin >> c.sold_for;
    cout << "Ingrese por cuanto fue vendido el carro: ";
    cin >> c.bought_for;

    archivo_carros << c.id << ";" << c.maker << ";" << c.model << ";" << c.year << ";" << c.sold_to << ";" << c.bought_to << ";" << c.sold_for << ";" << c.bought_for << endl;
    archivo_carros.close();
    archivo_carros2.close();
}

void Carro::EliminarDatosCarros()
{
    Carro c;
    cout << "Ingrese el id para saber que carro desea eliminar: ";
    cin >> c.id;
    ofstream temp("data/temp.csv");
    ifstream archivo_carro("data/cars_data.csv");
    string linea;

    while (getline(archivo_carro, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual != c.id)
        {
            temp << linea << endl;
        }
    }
    archivo_carro.close();
    temp.close();

    remove("data/cars_data.csv");
    rename("data/temp.csv", "data/cars_data.csv");
    cout << "los datos fueron borrados exitosamente" << endl;
}

void Carro::ModificarDatosCarros()
{
    Carro c;
    cout << "Ingrese el id del carro que desea modificar: ";
    cin >> c.id;

    ofstream temp("data/temp.csv");
    ifstream archivo_carros("data/cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual == c.id)
        {
            cout << "Ingrese la marca del carro: ";
            getline(cin, c.maker);
            cout << "Ingrese el modelo del carro: ";
            getline(cin, c.model);
            cout << "Ingrese el ano del carro: ";
            cin >> c.year;
            cout << "Ingrese a quien fue comprado el carro: ";
            cin >> c.sold_to;
            cout << "Ingrese a quien fue vendido el carro: ";
            cin >> c.bought_to;
            cout << "Ingrese por cuanto fue comprado el carro: ";
            cin >> c.sold_for;
            cout << "Ingrese por cuanto fue vendido el carro: ";
            cin >> c.bought_for;
        }
        else
        {
            temp << linea << endl;
        }
    }
    archivo_carros.close();
    temp.close();

    remove("data/cars_data.csv");
    rename("data/temp.csv", "data/cars_data.csv");
    cout << "Los datos se modificaron correctamente" << endl;
}

void Clientes::AgregarDatosClientes()
{
    ofstream archivo_clientes("data/clients.csv", ios::app);
    ifstream archivo_clientes2("data/clients.csv");
    string linea;
    Clientes cl;
    int nuevo_id = 0;

    while (getline(archivo_clientes2, linea))
    {
        nuevo_id++;
    }

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, cl.first_name);
    cout << "Ingrese el apellido del cliente: ";
    getline(cin, cl.last_name);
    cout << "Ingrese el email del cliente: ";
    getline(cin, cl.email);
    cout << "Ingrese la edad del cliente: ";
    cin >> cl.age;

    archivo_clientes << cl.id << ";" << cl.first_name << ";" << cl.last_name << ";" << cl.email << ";" << cl.age << endl;
    archivo_clientes.close();
    archivo_clientes2.close();
}

void Clientes::EliminarDatosClientes()
{
    Clientes cl;

    cout << "Ingrese el id para saber que cliente desea eliminar: ";
    cin >> cl.id;
    ofstream temp("data/temp.csv");
    ifstream archivo_clientes("data/clients.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual != cl.id)
        {
            temp << linea << endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("data/clients.csv");
    rename("data/temp.csv", "data/clients.csv");
    cout << "Los datos fueron eliminaros" << endl;
}

void Clientes::ModificarDatosClientes()
{
    Clientes cl;
    cout << "Ingrese el id del cliente que desea modificar: ";
    cin >> cl.id;

    ofstream temp("data/temp.csv");
    ifstream archivo_clientes("data/clients.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual == cl.id)
        {
            cout << "Ingrese el nombre: ";
            getline(cin, cl.first_name);
            cout << "Ingrese el apellido: ";
            getline(cin, cl.last_name);
            cout << "Ingrese el email: ";
            getline(cin, cl.email);
            cout << "Ingrese la edad: ";
            cin >> cl.age;
        }
        else
        {
            temp << linea << endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("data/clients.csv");
    rename("data/temp.csv", "data/clients.csv");
    cout << "Los datos se modificaron de manera exitosa" << endl;
}

int main()
{
    string linea;

    Clientes clientes;
    Carro carros;

    int carros_totales_comprados = 0;
    int carros_totales_vendidos = 0;
    int balance_ganancia = 0;
    int balance_perdida = 0;
    int opcion, opcion2, opcion3, opcion4;
    Carro carsCatalog[2000];
    int carCatalogSize;
    Clientes clientCatalog[250];
    int clientCatalogSize;
    int id, id2, id3, id4, id5, id6, id7;
    string Nombre_cliente, Apellido_cliente, Email_cliente;
    int edad_cliente = 0;
    bool opcionvalida = false;
    while (opcion != 8)
    {
        do
        {
            cout << "\nQue desea hacer?" << endl
                 << "1. Ver la cantidad de carros comprados y vendidos por clientes." << endl
                 << "2. Ver cuales carros fueron comprados por clientes." << endl
                 << "3. Ver cuales carros fueron vendidos por clientes." << endl
                 << "4. Ver datos del comprador de un carro." << endl
                 << "5. Ver datos del vendedor de un carro." << endl
                 << "6. Mostrar balance de un carro" << endl
                 << "7. Modificar datos" << endl
                 << "8. Salir" << endl;
            cin >> opcion;

            if (opcion >= 1 && opcion <= 8)
            {
                opcionvalida = true;
            }
            else
            {
                cout << "Opcion invalida, por favor coloque una opcion dentro del rango dado" << endl;
                opcionvalida = false;
            }
        } while (!opcionvalida);

        switch (opcion)
        {

        case 1:
        {
            cout << "\nIngrese el id del cliente: ";
            cin >> id;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].bought_to == id)
                {
                    carros_totales_comprados++;
                }
            }
            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id)
                {
                    Nombre_cliente = clientCatalog[i].first_name;
                    Apellido_cliente = clientCatalog[i].last_name;
                }
            }
            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].sold_to == id)
                {
                    carros_totales_vendidos++;
                }
            }

            cout << "El cliente " << Nombre_cliente << " " << Apellido_cliente << " "
                 << "Compro " << carros_totales_comprados << " carros"
                 << " "
                 << "y vendio " << carros_totales_vendidos << " carros" << endl;

            carros_totales_comprados = 0;
            carros_totales_vendidos = 0;
            break;
        }
        case 2:
            cout << "\nIngrese el id del cliente:";
            cin >> id2;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id2)
                {
                    Nombre_cliente = clientCatalog[i].first_name;
                    Apellido_cliente = clientCatalog[i].last_name;
                }
            }
            cout << "\n"
                 << Nombre_cliente << " " << Apellido_cliente << " "
                 << "compro los siguientes carros:\n"
                 << endl;

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].bought_to == id2)
                {
                    cout << carsCatalog[i].maker << " " << carsCatalog[i].model << "," << carsCatalog[i].year << endl;
                }
            }

            break;

        case 3:
            cout << "\nIngrese el id del cliente:";
            cin >> id3;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id3)
                {
                    Nombre_cliente = clientCatalog[i].first_name;
                    Apellido_cliente = clientCatalog[i].last_name;
                }
            }
            cout << "\n"
                 << Nombre_cliente << " " << Apellido_cliente << " "
                 << "vendio los siguientes carros:\n"
                 << endl;

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].sold_to == id3)
                {
                    cout << carsCatalog[i].maker << " " << carsCatalog[i].model << "," << carsCatalog[i].year << endl;
                }
            }

            break;

        case 4:
        {
            cout << "\nIngrese el id del carro:";
            cin >> id4;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].id == id4)
                {
                    for (int j = 0; j < clientCatalogSize; j++)
                    {
                        if (carsCatalog[i].sold_to == clientCatalog[j].id)
                        {
                            Nombre_cliente = clientCatalog[j].first_name;
                            Apellido_cliente = clientCatalog[j].last_name;
                            Email_cliente = clientCatalog[j].email;
                            edad_cliente = clientCatalog[j].age;
                            cout << "\nLos datos del comprador son:\n"
                                 << Nombre_cliente << "," << Apellido_cliente << "," << Email_cliente << "," << edad_cliente;
                        }
                    }
                }
            }
        }
        break;

        case 5:
            cout << "\nIngrese el id del carro:";
            cin >> id5;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].id == id5)
                {
                    for (int j = 0; j < clientCatalogSize; j++)
                    {
                        if (carsCatalog[i].bought_to == clientCatalog[j].id)
                        {
                            Nombre_cliente = clientCatalog[j].first_name;
                            Apellido_cliente = clientCatalog[j].last_name;
                            Email_cliente = clientCatalog[j].email;
                            edad_cliente = clientCatalog[j].age;
                            cout << "\nLos datos del comprador son:\n"
                                 << Nombre_cliente << "," << Apellido_cliente << "," << Email_cliente << "," << edad_cliente;
                        }
                    }
                }
            }
            break;

        case 6:
        {
            cout << "\nIngrese el id del cliente: ";
            cin >> id6;

            clientes.LeerDatosClientes("data/clients.csv", clientCatalog, clientCatalogSize);
            carros.LeerDatosCarros("data/cars_data.csv", carsCatalog, carCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carsCatalog[i].id == id6)
                {

                    balance_ganancia = carsCatalog[i].sold_for - carsCatalog[i].bought_for;
                    balance_perdida = carsCatalog[i].bought_for - carsCatalog[i].sold_for;

                    if (carsCatalog[i].sold_for > carsCatalog[i].bought_for)
                    {
                        cout << "Se tuvo una ganancia de " << balance_ganancia << endl;
                    }
                    else
                    {
                        cout << "Se tuvo una perdida de " << balance_perdida << endl;
                    }
                }
            }
        }
        break;

        case 7:
            cout << "Que desea hacer?" << endl
                 << "1-Agregar datos" << endl
                 << "2-Eliminar datos" << endl
                 << "3-Modificar datos" << endl;
            cin >> opcion2;
            if (opcion2 == 1)
            {
                cout << "A que archivo desea agregarle datos?" << endl
                     << "1-Clients" << endl
                     << "2-Cars_data" << endl;
                cin >> opcion3;
                if (opcion3 == 1)
                {
                    clientes.AgregarDatosClientes();
                }
                else if (opcion3 == 2)
                {
                    carros.AgregarDatosCarros();
                }
            }
            else if (opcion2 == 2)
            {
                cout << "A que archivo desea eliminarle datos?" << endl
                     << "1-Clients" << endl
                     << "2-Cars_data" << endl;
                cin >> opcion3;
                if (opcion3 == 1)
                {
                    clientes.EliminarDatosClientes();
                }
                else if (opcion3 == 2)
                {
                    carros.EliminarDatosCarros();
                }
            }
            if (opcion2 == 3)
            {
                cout << "A que archivo desea modificarle datos?" << endl
                     << "1-Clients" << endl
                     << "2-Cars_data" << endl;
                cin >> opcion3;
                if (opcion3 == 1)
                {
                    clientes.ModificarDatosClientes();
                }
                else if (opcion3 == 2)
                {
                    carros.ModificarDatosCarros();
                }
            }
            break;

        case 8:
            cout << "Gracias por preferir nuestra concesionaria:)" << endl;
            exit;
        }
    }
}