/*******************************************************************************************************************************
 Implementar un programa utilizando thread que liste un directorio, cuyo path se pasa por la linea de comandos, por cada archivo
 encontrado, que se supone que son todos archivos de texto, se tendra que:
 * Eliminar todos los espacios duplicados en cada archivo de texto
 * Luego moverlo a un directorio en path/output. Este directorio podra o no existir. En caso de no existir se debera crear
 * Al finalizar, mostrar por pantalla un resumen indicando:
   * Cantidad de archivos movidos
   * Cantidad de espacios duplicados eliminados por cada uno de los archivos
   
 Modificar el programa de manera que no finalice el thread principal, excepto con Ctrl+C. Cada vez que se agregue un archivo
 nuevo al directorio, debera procesarse segun el ejercicio anterior. Analice la necesidad o no de que los threas sean 
 joinabled o detached.
 *******************************************************************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_THREADS 100

void writeFileContentIntoBuffer(FILE *, char **);
void writeBufferIntoFile(char *, FILE *);
int removeDoubleWhiteSpaces(char *);
void copyFileToDirectory(FILE *, char *, char *);
void *copyFile(void *);

int movedFiles = 0;

int main(int argc, char *args[]) {
    DIR *dir;
    struct dirent *dirEntry;
    char *fileNameWithPath;
    pthread_t threadIds[MAX_THREADS];

    if (argc == 2) {
    	while (1) {
       	 dir = opendir(args[1]);
       	 if (dir) {
       	     while ((dirEntry = readdir(dir)) != NULL) {
                    if (strcmp(".", dirEntry->d_name) && strcmp("..", dirEntry->d_name)) {
                        fileNameWithPath = malloc(strlen(args[1]) + strlen(dirEntry->d_name) + 2);
                        if (!fileNameWithPath) exit(-1);
                        strcpy(fileNameWithPath, args[1]);
                        strcat(fileNameWithPath, "/");
                        strcat(fileNameWithPath, dirEntry->d_name);

                        pthread_create(&threadIds[movedFiles], NULL, copyFile, fileNameWithPath);
                        pthread_detach(threadIds[movedFiles]);
                        movedFiles++;
                    }
                }
                closedir(dir);
            }
            else {
                printf("El directorio no existe\n");
                exit(-2);
            }
            sleep(1);
        }
    }
    else printf("Cantidad de argumentos errónea\n");
}

// NEEDS an already opened file, if buffer is empty assign it NULL
void writeFileContentIntoBuffer(FILE *fp, char **buffer) {
    int index = 0, buffSize = 0, realSize = 0;
    __int8_t bytesRead = 10;

    fseek(fp, 0, SEEK_SET);
    while (bytesRead == 10) { // malloc al buff
        *buffer = realloc(*buffer, buffSize += 10);
        if (!buffer) exit(-1);

        bytesRead = fread((*buffer) + index, 1, 10, fp);
        realSize += bytesRead;
        index += 10;
    }
    (*buffer)[realSize] = 0;
}

// NEEDS an already opened file
void writeBufferIntoFile(char *buffer, FILE *fp) {
    size_t index;
    for (index = 0; index < strlen(buffer); index++) fwrite(buffer + index, 1, 1, fp);
}

// Returns amount of blank spaces removed
int removeDoubleWhiteSpaces(char *str) {
    size_t index;
    int amountRemoved = 0;

    while (*str) {
        while (*str == 32 && *(str + 1) == 32) {
            index = 0;
            while (*(str + index)) {
                *(str + index) = *(str + index + 1);
                index++;
            }
            amountRemoved++;
        }
        str++;
    }
    return amountRemoved;
}

void copyFileToDirectory(FILE *fp, char *filename, char *outDir) {
    char *filenameWithPath = malloc(strlen(outDir) + 1 + strlen(filename) + 1);
    char *buffer = NULL;
    FILE *destFp;

    writeFileContentIntoBuffer(fp, &buffer);
    strcpy(filenameWithPath, outDir);
    strcat(filenameWithPath, "/");
    strcat(filenameWithPath, filename);

    struct stat st = {0};

    if (stat(outDir, &st) == -1) mkdir(outDir, 0777);
    destFp = fopen(filenameWithPath, "w");
    if (!destFp) printf("NO SE PUDO ABRIR EL ARCHIVO\n");
    else {
        writeBufferIntoFile(buffer, destFp);
        fclose(destFp);
    }
    free(buffer);
}

void *copyFile(void *fullFilename) {
    FILE *fp;
    char *buff;
    int *blankSpacesRemoved = malloc(sizeof(int));

    fp = fopen(fullFilename, "r");
    if (!fp) printf("EL ARCHIVO NO SE ABRIÓ AL PRINCIPIO\n");

    buff = NULL;
    writeFileContentIntoBuffer(fp, &buff);
    *blankSpacesRemoved = removeDoubleWhiteSpaces(buff);
    fclose(fp);

    fp = fopen(fullFilename, "w+");

    writeBufferIntoFile(buff, fp);

    copyFileToDirectory(fp, strrchr(fullFilename, '/') + 1, "./output");
    fclose(fp);

    free(blankSpacesRemoved);
    remove(fullFilename);
    movedFiles--;
    printf("En el archivo %s: se eliminaron: %d espacios en blanco\n", (char* )fullFilename, *blankSpacesRemoved);
    return NULL;
}
