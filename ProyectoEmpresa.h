/*
Proyecto Sistema de una tienda de Electrónicos
Aksel Deneken Maldonado
A01711966
12/11/2023


Clase empresa que maneja todos los registros, cambios y compras
de los productos y de los clientes
*/


#ifndef PROYECTOEMPRESA_H_
#define PROYECTOEMPRESA_H_
#include <iostream>
#include "ProyectoClases.h"
using namespace std;


//La clase empresa que se compone de todas las clases definidas
class Empresa{
    private:
        Laptop lap[100];            //Permite que existan un maximo de 100 objetos laptop
        Celular cel[100];           //Permite que existan un maximo de 100 objetos celular
        Clientes cli[100];          //Permite que existan un maximo de 100 objetos clientes
        int laps, cels, clis; 
      //Contadores para saber el número de laptops, clientes, celulares



    //Constructor y metodos
    public:
        Empresa(): laps(0), cels(0), clis(0){};  
        int generaID();
        int generaIDcel();
        int generaIDCli();
        void creaEjemplosLaps();
        void muestraLaps();
        void creaEjemplosCel();
        void muestraCel();
        void creaEjemplosCli();
        void muestraCli();
        void agregaCliLap(int idCli, string nombre, string direccion, int numero, int id);
        void agregaCliCel(int idCli, string nombre, string direccion, int numero, int id);
        void agregaLap(double precio, int id, string nombre, string status, string especificaciones, string procesador);
        void agregaCel(double precio, int id, string nombre, string status, string especificaciones, string camara);
        void calculaTotal();
        void CalculaTotalCli(string);
        void muestraCompras();
        void editarLap(int);
        void editarCel(int);
        void editarCli(int);

        



};

//Funciones que generan un ID para identificar de forma mas facil los objetos
int Empresa::generaID(){
    int idnuevo;
    idnuevo = laps + 2;
    return idnuevo;
}

int Empresa::generaIDcel(){
    int idnuevocel;
    idnuevocel = cels + 2;
    return idnuevocel;
}

int Empresa::generaIDCli(){
    int idnuevoCli;
    idnuevoCli = clis + 2;
    return idnuevoCli;
}




//Crea ejemplos de objetos Laptops 
void Empresa::creaEjemplosLaps(){
    lap[0] = Laptop(1200.0, 1, "Laptop HP", "Disponible", "Especificaciones avanzadas", "Intel Core i7");
    laps += 1;
    lap[1] = Laptop(1000.0, 2, "Laptop Dell", "Disponible", "Especificaciones estandar", "AMD Ryzen 5");
    laps += 1;
    lap[2] = Laptop(1500.0, 3, "Laptop Lenovo", "Agotado", "Especificaciones premium", "Intel Core i9");
    laps += 1;
    lap[3] = Laptop(800.0, 4, "Laptop Acer", "Disponible", "Especificaciones basicas", "AMD Ryzen 3");
    laps += 1;
    lap [4] = Laptop(1300.0, 5, "Laptop Asus", "Disponible", "Especificaciones gamer", "Intel Core i5");

}




//Muestra todas las laptops existentes
void Empresa::muestraLaps(){
    for (int i = 0; i <= laps; i++){
        lap[i].muestraDatos();
        lap[i].muestraPro();
    }
}




//Permite agregar Laptops Nuevas
void Empresa::agregaLap(double precio, int id, string nombre, string status, string especificaciones, string procesador){
    laps += 1;
    Laptop lapnuevo(precio, id, nombre, status, especificaciones, procesador);
    lap[laps] = lapnuevo;
}




//Crea ejemplos de Celulares
void Empresa::creaEjemplosCel(){
    cel[0] = Celular(599.99, 1, "Celular Samsung", "Disponible", "Especificaciones estandar", "Cámara de 48 MP");
    cels += 1;
    cel[1] = Celular(720.99, 2, "Celular iPhone", "Agotado", "Especificaciones premium", "Cámara de 12 MP");
    cels += 1;
    cel[2] = Celular(300.0, 3, "Celular Xiaomi", "Disponible", "Especificaciones basicas", "Cámara de 16 MP");
    cels += 1;
    cel[3] = Celular(900.0, 4, "Celular Google Pixel", "Disponible", "Especificaciones avanzadas", "Cámara de 20 MP");
    cels += 1;
    cel[4] = Celular(600.0, 5, "Celular OnePlus", "Agotado", "Especificaciones gamer", "Cámara de 64 MP");
}



//Muestra todos los celulares existentes
void Empresa::muestraCel(){
    for (int i = 0; i <= cels; i++){
        cel[i].muestraDatos();
        cel[i].muestraCam();
    }
}



//Permite agregar celulares nuevos
void Empresa::agregaCel(double precio, int id, string nombre, string status, string especificaciones, string camara){
    cels += 1;
    Celular celnuevo(precio, id, nombre, status, especificaciones, camara);
    cel[cels] = celnuevo;
}



//Crea ejemplos de Clientes
void Empresa::creaEjemplosCli(){
    cli[0] = Clientes(1, "Juan Perez", "Calle A #123", 123456789, lap[0]);
    clis += 1;
    cli[1] = Clientes(2, "Maria Rodriguez", "Avenida B #456", 987654321, cel[1]);
    clis += 1;
    cli[2] = Clientes(3, "Carlos Gomez", "Carrera C #789", 456789012, lap[4]);
    clis += 1;
    cli[3] = Clientes(4, "Ana Martinez", "Calle D #1011", 345678901, lap[3]);
    clis += 1;
    cli[4] = Clientes(5, "Pedro Sanchez", "Avenida E #1213", 234567890, cel[2]);
}



//Permite que el usuario registre un cliente nuevo que compro una laptop
void Empresa::agregaCliLap(int idCli, string nombre, string direccion, int numero, int id){
    clis += 1;
    Clientes nuevo(idCli, nombre, direccion, numero, lap[id]);
    cli[clis] = nuevo;
}


//Permite que el usuario registre un cliente nuevo que compro un Celular
void Empresa::agregaCliCel(int idCli, string nombre, string direccion, int numero, int id){
    clis += 1;
    Clientes nuevo(idCli, nombre, direccion, numero, cel[id]);
    cli[clis] = nuevo;
}


//Muestra todos los clientes
void Empresa::muestraCli(){
    for (int i = 0; i <= clis; i++){
        cli[i].muestraDatos();
    }
}

//Muestra todos los clientes y sus compras
void Empresa::muestraCompras(){
    for (int i = 0; i <= clis; i++){
        cli[i].muestraCompras();
    }
}


//Suma el precio de las compras realizadas para obtener las ganancias totales
void Empresa::calculaTotal(){
    Producto prodCompra;
    double total(0.0);

    muestraCompras();

    for (int i = 0; i <= clis; i++){
        prodCompra = cli[i].getProd();
        total += prodCompra.getPrecio();

    }

    cout << "\nLas ganancias totales de la empresa son de: " << total << endl;
}


//Permite ver los productos que ha comprado un solo cliente y el total que ha gastado en la tienda
void Empresa::CalculaTotalCli(string nombre){
    Producto prodCompra;
    double total(0.0);

    for (int i = 0; i <= clis; i++){
        if (cli[i].getNombre() == nombre){
            prodCompra = cli[i].getProd();
            total += prodCompra.getPrecio();
            cout << "\nEl cliente " << nombre << " compro " << prodCompra.getNombre() << " a un precio de " << prodCompra.getPrecio() << endl;
        }

    }
    if (total != 0){
    cout << "\nEl cliente " << nombre << " ha gastado " << total << endl;
    }else{
        cout << "\nEl cliente no existe" << endl;
    }
}




//Permite editar la informacion de una Laptop registrada
void Empresa::editarLap(int id){

    //Inicializamos variables que se van a usar
    int opcionEdit;
    float precioNuevo;
    string nombreNuevo, statusNuevo, espeNueva, proNuevo;

    //Imprime un menu secundario y le pide al usuario una opcion
    cout << "1. Precio" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Status" << endl;
    cout << "4. Especificaciones" << endl;
    cout << "5. Procesador" << endl;
    cout << "6. Borrar Producto" << endl;
    cout << "Que dato desea cambiar?: "; cin >> opcionEdit;

    //Usamos el swiths para tner todo mejor organizado
    switch (opcionEdit){

        //El caso 1 permite editar el precio del producto
        case 1:
        cout << "Cual es el precio nuevo?: "; cin >> precioNuevo; 
        lap[id-1].setPrecio(precioNuevo);
        cout << "Precio cambiado" << endl;
        break;
        

        //El caso 2 permite editar el nombre del producto
        case 2:
        cout << "Cual es el nombre nuevo?: "; cin.ignore(); getline(cin, nombreNuevo);
        lap[id-1].setNombre(nombreNuevo);
        cout << "Nombre cambiado" << endl;
        break;


        //El caso 3 permite editar el estatus del producto
        case 3:
        cout << "Cual es el status nuevo?: "; cin.ignore(); getline(cin, statusNuevo);
        lap[id-1].setStatus(statusNuevo);
        cout << "Status Cambiado" << endl;
        break;


        //El caso 4 permite editar las especifiaciones del producto
        case 4:
        cout << "Cuales son las especifiaciones nuevas?: "; cin.ignore(); getline(cin, espeNueva);
        lap[id-1].setEspec(espeNueva);
        cout << "Especificaciones cambiadas" << endl;
        break;
        


        //EL caso 5 permite editar la informacion del procesador
        case 5:
        cout << "Cual es el procesador nuevo?: "; cin.ignore(); getline(cin, proNuevo);
        lap[id-1].setPro(proNuevo);
        cout << "Procesador Cambiado" << endl;
        break;


        //El caso 6 permite eliminar el producto
        case 6:
        lap[id-1] = Laptop();
        cout << "Producto Eliminado" << endl;
        break;
    }

}


//Es la misma funcion que la de arriba solo que edita la informaicon de un celular
void Empresa::editarCel(int id){
    int opcionEdit;
    float precioNuevo;
    string nombreNuevo, statusNuevo, espeNueva, camNueva;


    cout << "1. Precio" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Status" << endl;
    cout << "4. Especificaciones" << endl;
    cout << "5. Camara" << endl;
    cout << "6. Borrar Producto" << endl;
    cout << "Que dato desea cambiar?: "; cin >> opcionEdit;


    switch (opcionEdit){

        case 1:
        cout << "Cual es el precio nuevo?: "; cin >> precioNuevo; 
        cel[id-1].setPrecio(precioNuevo);
        cout << "Precio cambiado" << endl;
        break;
        

        case 2:
        cout << "Cual es el nombre nuevo?: "; cin.ignore(); getline(cin, nombreNuevo);
        cel[id-1].setNombre(nombreNuevo);
        cout << "Nombre cambiado" << endl;
        break;


        case 3:
        cout << "Cual es el status nuevo?: "; cin.ignore(); getline(cin, statusNuevo);
        cel[id-1].setStatus(statusNuevo);
        cout << "Status Cambiado" << endl;
        break;


        case 4:
        cout << "Cuales son las especifiaciones nuevas?: "; cin.ignore(); getline(cin, espeNueva);
        cel[id-1].setEspec(espeNueva);
        cout << "Especificaciones cambiadas" << endl;
        break;
        

        //Permite cambiar la informacion de la camara
        case 5:
        cout << "Cual es la camara nuevo?: "; cin.ignore(); getline(cin, camNueva);
        cel[id-1].setCam(camNueva);
        cout << "Camara Cambiado" << endl;
        break;


        case 6:
        cel[id-1] = Celular();
        cout << "Producto Eliminado" << endl;
        break;
    }

}


//Es igual que las anteriores solo que permite editar la informacion de un cliente
void Empresa::editarCli(int id){
    int opcionEdit, opcionEdit2, numeroNuevo, idProd;
    string nombreNuevo, direccionNuevo;
    Producto prodNuevo;  //Se puede editar tambien el producto que adquirio


    cout << "1. Nombre" << endl;
    cout << "2. Direccion" << endl;
    cout << "3. Numero telefonico" << endl;
    cout << "4. Producto Comprado" << endl;
    cout << "5º. Borrar Cliente" << endl;
    cout << "Que dato desea cambiar?: "; cin >> opcionEdit;


    switch (opcionEdit){

        case 1:
        cout << "Cual es el nombre nuevo?: "; cin.ignore(); getline(cin, nombreNuevo); 
        cli[id-1].setNombre(nombreNuevo);
        cout << "Nombre cambiado" << endl;
        break;
        

        case 2:
        cout << "Cual es la direccion nueva?: "; cin.ignore(); getline(cin, direccionNuevo);
        cli[id-1].setDireccion(direccionNuevo);
        cout << "Direccion cambiada" << endl;
        break;


        case 3:
        cout << "Cual es el numero de telefono nuevo?: "; cin >> numeroNuevo;
        cli[id-1].setNumero(numeroNuevo);
        cout << "Numero Cambiado" << endl;
        break;


        //El caso 4 permite editar el producto comprado por el cliente
        case 4:
        cout << "El producto es una Laptop(1) o un Celular(2)?: "; cin >> opcionEdit2;

        //Pide el tipo de Producto
        if (opcionEdit2 == 1){
        cout << "Cual es el id del producto nuevo?: "; cin >> idProd;
        cli[id-1].setProd(lap[idProd-1]);
        cout << "Producto comprado cambiado" << endl;
        }
        else if (opcionEdit2 == 2){
            cout << "Cual es el id del producto nuevo?: "; cin >> idProd;
            cli[id-1].setProd(cel[idProd-1]);
            cout << "Producto comprado cambiado" << endl;
        }
        
        break;
        

        case 6:
        cli[id-1] = Clientes();
        cout << "Cliente Eliminado" << endl;
        break;
    }

}



#endif // PROYECTOEMPRESA_H_