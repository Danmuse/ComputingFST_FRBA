Se desea crear dos aplicaciones, una cliente y otra servidor:

## Servidor:
**a.** Crear una base de datos de partes de automoviles que incluyen:
- *part number* (integer)
- *part name* (string max = 100)
- *part quantity* (integer)
- *part price*

La base de datos sera una lista enlazada, y la primera vez que se crea se hace desde un archivo .csv 
que se adjunta. 

El nombre del archivo sera argumento desde la linea de comandos.

**b.** Las API's a desarrollar son:
- __*Order*__   (descuenta un elemento del stock, siempre que sea posible)
- __*GetPart*__ (recive el part number y devuelve el resto de los campos)
	
Las mismas se consultaran por sockets desde los clientes.

**c.** El servidor sera concurrente implementado con threads.

**d.** Mediante alguna señal (la puede elegir usted), al recibirla, el servidor guardara la lista
que tiene en memoria en un archivo csv.

## Cliente:
**a.** Podrá ejecutar las API's por sockets al servidor, imprimiendo por pantalla el resultado.

Todos los datos no provistos en el enunciado, serán elegidos por el desarrollador.
