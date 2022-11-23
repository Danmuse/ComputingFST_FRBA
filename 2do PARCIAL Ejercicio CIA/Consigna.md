##Propuesta: 
En la CIA un empleado le debe enviar a un detective un mensaje encriptado con el nombre del sospechoso encubierto. Una vez recibido debe ser desencriptado

##Servidor: 
Realice un programa donde cree un archivo .txt cuyo contenido sea el mensaje recibido del cliente
En el paso siguiente deberá generar una copia del archivo dentro del mismo directorio con los siguientes cambios...
- En la primera línea los caracteres del String serán expresados en formato binario (Cada carácter representa un byte)
- La segunda línea será el resultado de operar a nivel de bits (mediante NAND) la línea anterior con el bit LSB activo
- La tercera línea se mostrará el String resultante convirtiendo los bytes de la segunda línea a sus respectivos caracteres en ASCII
- Finalmente el mensaje codificado deberá ser devuelto al cliente.

*NOTA:* Considere la utilización de archivos en bajo nivel y en caso de recibirse otro mensaje se tendrá que almacenar alfabeticamente en el archivo previamente creado.

##Cliente: 
Realice un programa que desencripte el mensaje recibido y sea mostrado por Consola
