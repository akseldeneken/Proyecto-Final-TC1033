# Proyecto-Final-TC1033
Con este proyecto lo que se quiere buscar es crear un programa que despliegue el inventario de distintos productos. Que le permita al usuario conocer el precio y las caracteristicas de los productos electronicos que busca. Si se encuentran disponibles en tienda, sus componentes, el costo. Te permite tambien registrar productos, clientes o compras nuevas, así como editar la información de los mimsos. Además, despliega el total que un cliente ha comprado en la tienda y el total de ingresos que la tienda ha tenido.
# Contexto
Una empresa de venta de productos mantiene un inventario con distintas clases para facilitar el acceso a la información de dichos articulos. También se necesita tener un registro de los clientes que han comprado productos, el precio que se pagó, los productos disponibles y los productos, clientes y compras nuevas que se han realizado.
# Funcionalidad
Se pueden registrar productos nuevos.

Se puede editar la información de un producto o de un cliente.

Se pueden registrar clientes nuevos.

El programa puede calcular el total de las compras realizadas.

El programa puede calcular el total que un cliente en especifico a comprado.

El programa permite registrar una compra nueva.

El programa despliega la información de los productos.

El programa despliega la información de los clientes.

Contiene un menu.

# Correciones
Se hizo compatible para todos los sistemas operativos.
Se arregló un error que había al elegir la opcion de registro (se imprimia basura infinitamente) con la linea de codigo cin.ignore(); getline(cin, temp_direccion);
Se agregaron comentarios
Se mejoró la sintaxis.
Se agrego una clase Empresa que guarda la información de los productos y clientes.
Se agregó la clase Productos de las que heredan Laptops y Celulares para tener una mejor funcionalidad.
El main se simplificó para que solo mandara a llamar a las demas funciones.
