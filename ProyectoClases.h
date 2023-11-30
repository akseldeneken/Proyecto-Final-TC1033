/*
Proyecto Sistema de una tienda de Electrónicos
Aksel Deneken Maldonado
A01711966
12/11/2023

Clases Producto que  
*/


#ifndef PROYECTOCLASES_H_
#define PROYECTOCLASES_H_
#include <iostream>
#include "ProyectoEmpresa.h"
using namespace std;

//definimos la clase padre "Producto" que va a llevar todos los parametros generales que un producto en la tienda tiene

class Producto{

    // definimos los atributos
    private:
    double precio;
    int idn;
    string nombre;
    string status;
    string especificaciones;

    //Definimos los metodos
    public:

    //constructor que asigna valores nulos a las variables
    Producto(): precio(0.0), idn(0), nombre(""), status(""), especificaciones(""){}; 

    //constructor que asigna los valores de las variables a otras variables para poder acceer a ellas
    Producto(double pre, int id, string nom, string sta, string espe): precio(pre),idn(id), nombre(nom), status(sta), especificaciones(espe){}; 
    double getPrecio();
    int getId();
    string getNombre();
    string getStatus();
    string getEspec();
    void setPrecio(double);     //getter y setters   
    void setId(int);
    void setNombre(string);
    void setStatus(string);
    void setEspec(string);
    void muestraDatos();
};

//getter y setters 

double Producto::getPrecio(){
    return precio;
}

int Producto::getId(){
    return idn;
}

string Producto::getNombre(){
    return nombre;
}

string Producto::getStatus(){
    return status;
}

string Producto::getEspec(){
    return especificaciones;
}

void Producto::setPrecio(double pre){
    precio = pre;
}

void Producto::setId(int id){
    idn = id;
}

void Producto::setNombre(string nom){
    nombre = nom;
}

void Producto::setStatus(string sta){
    status = sta;
}

void Producto::setEspec(string espe){
    especificaciones = espe;
}


//Permite Que se desplieguen en pantalla los datos de los productos
void Producto::muestraDatos(){
    cout << "\nNombre del Producto: " << nombre << endl;
    cout << "ID: " << idn << endl;
    cout << "Precio: " << precio << endl;
    cout << "Esatus: " << status << endl;
    cout << "Especificaciones: " << especificaciones << endl;
}







//Clase Laptop heredada de Producto 
class Laptop : public Producto{

    //Tiene los mismos atributos que un producto pero se le agrega el procesador
    private:
        string procesador; 


    //Definimos sus metodos
    public:
        //constructor para asignar valores nulos
        Laptop(): procesador(""){}; 

        //constructor para asignar a variables nuevas
        Laptop(double pre, int id, string nom, string sta, string espe, string pro): Producto(pre, id, nom, sta, espe), procesador(pro){}; 
        string getPro();
        void setPro(string);
        void muestraPro();
        
};

//getters y setters

string Laptop::getPro(){
    return procesador;
}

void Laptop::setPro(string pro){
    procesador = pro;
}

//imprime el dato extra de esta clase
void Laptop::muestraPro(){ 
    cout << "Procesador: " << procesador << endl;
}






//Clase Celular heredada de producto 
class Celular : public Producto{
    private:

        //esta clase tiene el atributo camara aparte de los atributos de un producto
        string camara; 

    public:

        //constructores y metodos
        Celular(): camara(""){}; 
        Celular(double pre, int id, string nom, string sta, string espe, string cam): Producto(pre, id, nom, sta, espe), camara(cam){};
        string getCam();
        void setCam(string);
        void muestraCam();
};


//getters y setters
string Celular::getCam(){
    return camara;
}

void Celular::setCam(string cam){
    camara = cam;
}

//Imprime la informacion de la camara
void Celular::muestraCam(){ 
    cout << "Camara: " << camara << endl;
}



//Clase clientes que tiene composicion con la clase producto ya que un cliente no puede existir si no ha comprado nada
class Clientes{

    //Definimos sus atributos
    private:
        int id;
        string nombre;
        string direccion;
        int numero;
        //Al cliente se le añade un atributo que es el producto o productos que compró
        Producto prodComprado;

    public:

        //constructores y metodos
        Clientes():id(0), nombre(""), direccion(""), numero(0){}; 
        Clientes(int idCli, string nom, string dir, int num, Producto prod) :id(idCli), nombre(nom), direccion(dir), numero(num), prodComprado(prod){};
        string getNombre();
        string getDireccion();
        int getNumero();
        Producto getProd();
        void setNombre(string);
        void setDireccion(string);
        void setNumero(int);
        void setProd(Producto);
        void muestraDatos();
        void muestraCompras();

};


//Getters y setters

string Clientes::getNombre(){
    return nombre;
}

string Clientes::getDireccion(){
    return direccion;
}

int Clientes::getNumero(){
    return numero;
}

Producto Clientes::getProd(){
    return prodComprado;
}

void Clientes::setNumero(int num){
    numero = num;
}

void Clientes::setNombre(string nom){
    nombre = nom;
}

void Clientes::setDireccion(string dir){
    direccion = dir;
}

void Clientes::setProd(Producto prod){
    prodComprado = prod;
}

//muestra los datos del cliente
void Clientes::muestraDatos(){ 
    cout << "\nID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Numero telefonico: " << numero << endl;
}

//Muestra los datos de las compras realizadas
void Clientes::muestraCompras(){
    cout << "\nID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Numero telefonico: " << numero << endl;
    cout << "Producto comprado: " << prodComprado.getNombre() << endl;
    cout << "Precio del producto comprado: " << prodComprado.getPrecio() << endl;
}






#endif // PROYECTOCLASES_H_