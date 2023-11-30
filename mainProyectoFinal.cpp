/*
Proyecto Sistema de una tienda de Electrónicos
Aksel Deneken Maldonado
A01711966
12/11/2023

Descripción: Este es el proyecto final para la clase de 
pensamiento computacional orientado a objetos. Es un programa
que captura distintos tipos de productos y clientes. 
Permite registrar compras que se realizan en la tienda y nos permite
calcular el total de ingreso que se ha obtenido de esas ventas. 
Dentro del programa podemos registrar o editar la informacion de 
productos nuevos, clientes nuevos y compras nuevas.
*/

//Agregamos las bibliotecas
#include <iostream>
#include "ProyectoEmpresa.h"   //Incluimos los archivo con las clases
#include "ProyectoClases.h"
#include <limits>

using namespace std;

//Imprime el menu
void menu(){ 

    cout << "\nMENU PRINCIPAL" << endl << endl;
    cout << "1. Mostrar Laptops" << endl;
    cout << "2. Mostrar Celulares" << endl;
    cout << "3. Mostrar Clientes" << endl;
    cout << "4. Mostrar Compras" << endl;
    cout << "5. Registrar Compra" << endl;
    cout << "6. Registrar Producto" << endl;
    cout << "7. Calcular Ganancias totales" << endl;
    cout << "8. Editar datos de Producto" << endl;
    cout << "9. Editar datos de Cliente" << endl;
    cout << "10. Consultar compras de un Cliente" << endl;
    cout << "11. Salir" << endl;

}


int main(){

    //crea un objeto de tipo empresa
    Empresa empresa;  

    //Manda a llamar a las funciones de ejemplo para que ya existan objetos al iniciar el programa    
    empresa.creaEjemplosLaps();
    empresa.creaEjemplosCel();
    empresa.creaEjemplosCli();

    //Inicializamos nuestras variables
    int opcion(0), opcionEdit(0), prodComprado(0);
    string temp_nombre(""), temp_direccion(""), temp_status(""), temp_espe(""), temp_pro(""), temp_cam(""), temp_nombreCli("");
    int temp_numero(0), temp_id(0);
    double temp_precio(0);


    //va a imprimir el menu hasta que el usuario ponga la opcion "salir"
    while (opcion != 11){    
        opcion = 0;
        menu();
        cout << "Elige una opcion: ";
        cin >> opcion;

        //cambia el input de opcion a diferentes casos para no usar if en todo el menu
        switch (opcion){   
        //El caso uno muestra todos los objetos de tipo Laptop
        case 1:
            empresa.muestraLaps();
            break;



        //El caso dos muestra todos los objetos de tipo Celular
        case 2:
            empresa.muestraCel();
            break;



        //El caso tres muestra todos los objetos de tipo Clientes
        case 3:
            empresa.muestraCli();
            break;




        //El caso cuatro muestra todas las compras que se han realizado
        case 4:
            empresa.muestraCompras();
            break;




        //El caso cinco registra una compra nueva
        case 5:

            //pide todos los datos del cliente nuevo y lo agrega
            cout << "\nIngrese el nombre: "; cin.ignore(); getline(cin, temp_nombre);
            cout << "\nIngresa la direccion: "; cin.ignore(); getline(cin, temp_direccion);
            cout << "\nIngresa el numero telefonico: "; cin >> temp_numero;
            cout << "\nQue tipo de producto es?(Laptop = 1, Celular = 2): "; cin >> prodComprado;

            //Pregunta si es laptop o celular para poder agregar el producto corectamente a los datos del cliente
            if (prodComprado == 1){ 
                cout << "\nIngresa el id del producto comprado: "; cin >> temp_id;
                empresa.agregaCliLap(empresa.generaIDCli(), temp_nombre, temp_direccion, temp_numero, temp_id);
                cout << "\nCliente agregado" << endl;
            }
            else if (prodComprado == 2){
                cout << "\nIngresa el id del producto comprado: "; cin >> temp_id;
                empresa.agregaCliCel(empresa.generaIDCli(), temp_nombre, temp_direccion, temp_numero, temp_id);
                cout << "\nCliente agregado" << endl;
            }
        break;



        
        //El caso seis registra un producto nuevo
        case 6:

            //Pide los datos del producto
            cout << "\nIngresa el nombre del producto: "; cin.ignore(); getline(cin, temp_nombre);
            cout << "\nIngresa el precio del producto: "; cin >> temp_precio;
            cout << "\nIngresa las especifiaciones del producto: "; cin.ignore(); getline(cin, temp_espe);
            cout << "\nEl producto es Laptop(1) o Celular(2): "; cin >> temp_id;

            //Pide el tipo de producto para agregarlo correctamente ya que tienen atributos diferentes
            if (temp_id == 1){
                cout << "\nIngresa el tipo de procesador: "; cin >> temp_pro;
                empresa.agregaLap(temp_precio, empresa.generaID(), temp_nombre, "Disponible", temp_espe, temp_pro);
                cout << "\nProducto Agregado" << endl;
            }
            else if (temp_id == 2){
                cout << "\nIngresa el tipo de camara: "; cin.ignore(); getline(cin, temp_cam);
                empresa.agregaCel(temp_precio, empresa.generaIDcel(), temp_nombre, "Disponible", temp_espe, temp_cam);
                cout << "\nProducto Agregado" << endl;
            }else{
                cout << "\nOpcion invalida" << endl;
            }
        break;




        //El caso siete calcula el total que se ha ganado con todas las compras realizadas
        case 7:
            empresa.calculaTotal();
        break;




        //El caso ocho permite editar los datos de un producto
        case 8:
            cout << "Desea edita una laptop(1) o un celular(2)?: "; cin >> opcionEdit;

            //Pide el tipo de producto para editarlo correctamente
            if (opcionEdit == 1){
                cout << "Cual es el id del producto?: "; cin >> temp_id;
                empresa.editarLap(temp_id);
            }
            else if(opcionEdit == 2){
                cout << "Cual es el id del producto: "; cin >> temp_id;
                empresa.editarCel(temp_id);
            }else{
                cout << "Opcion invalida" << endl;
            }
        break;



        //El caso nueve es para editar la informacion de un cliente
        case 9:
            cout << "Cual es el ID del cliente?: "; cin >> temp_id;
            empresa.editarCli(temp_id);
        break;


        //El caso diez permite al usuario conocer las compras que ha realizado un cliente específico
        case 10:
            cout << "\nNombre del cliente: "; cin.ignore(); getline(cin, temp_nombre);
            empresa.CalculaTotalCli(temp_nombre);
        break;

        }

                
    }
    //Una vez el usuario haya elegido la opcion de salir se imprime el mensaje y la ejecucion del programa termina
    cout << "Cerrando el programa" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
    return 0; 
} 
    



