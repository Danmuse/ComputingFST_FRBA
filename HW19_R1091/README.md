https://docs.kernel.org/filesystems/

## __Filesystem (Modes)__

"**r**"  - Open text file for reading. The stream is positioned at the
       beginning of the file.

"**r+**" - Open for reading and writing. The stream is positioned at the
       beginning of the file.

"**w**"  - Truncate file to zero length or create text file for writing.
       The stream is positioned at the beginning of the file.

"**w+**" - Open for reading and writing. The file is created if it does
       not exist, otherwise it is truncated. The stream is positioned
       at the beginning of the file.

"**a**"  - Open for appending (writing at end of file). The file is
       created if it does not exist. The stream is positioned at the end
       of the file.

"**a+**" - Open for reading  and appending (writing at end of file). The
       file is created if it does not exist. Output is always appended
       to the end of the file.
       
## __Filesystem (Return Value)__

> On success, *__fread()__* and *__fwrite()__* return the number of items read or
written. This number equals the number of bytes transferred only when size is 1. 
If an error occurs, or the end of the file is reached, the return value is a short item count (or zero).
*fread()* does not distinguish between end-of-file and error, and callers must use feof(3) and ferror(3) to determine which occurred.

## __Filesystem (Description)__

> The *__fseek()__* function sets the file position indicator for the stream pointed to by stream.
The new position, measured in bytes, is obtained by adding offset bytes to the position specified by whence.
If whence is set to __SEEK_SET__, __SEEK_CUR__, or __SEEK_END__, the offset is relative to respectively itself.

> The *__ftell()__* function obtains the current value of the file position indicator for the stream pointed to by stream.
	
> The *__rewind()__* function sets the file position indicator for the stream pointed to by stream to the beginning of the file. It is equivalent to:

`(void) fseek(stream, 0L, SEEK_SET)`
	
## __Makefile Distributions__

- __src__
	* main.c
	* utils_1.c
	* utils_2.c
	* utils_3.c
	* **Makefile**
- __inc__
	* utils_1.h
	* utils_2.h
	* utils_3.h
- __obj__
	* main.o
	* main.d
	* utils_1.o
	* utils_1.d
	* utils_2.o
	* utils_2.d
	* utils_3.o
	* utils_3.d
- __bin__
	* app.out
