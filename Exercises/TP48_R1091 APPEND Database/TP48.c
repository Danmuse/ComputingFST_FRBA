#include <stdio.h> 
#include <string.h> 

typedef struct { 
	int id; 
	char name[6]; 
	char genre; 
} REGISTER; 

void Write(void); 
void Read(void);
void SeekByID(int);

int main(void) { 
	Write(); 
	Read(); 
	SeekByID(2); 
} 

void Write(void) { 
	REGISTER a = {1, "Juan", 'M'}; 
	REGISTER b = {2, "Maria", 'F'}; 
	REGISTER c = {3, "Pedro", 'M'}; 
	REGISTER arr[3] = {a, b, c}; 
	FILE *fp; fp = fopen("list.bin", "w"); 
	fwrite(arr, sizeof(REGISTER), 3, fp); 
	fclose(fp); 
} 

void Read(void) {
	size_t i;
	FILE *fp;
	REGISTER arr[3];
	fp = fopen("list.bin", "r");
	fread(arr, sizeof(REGISTER), 3, fp);
	fclose(fp);
	for (i = 0; i < 3; i++) printf("%d | %s | %c\n", arr[i].id, arr[i].name, arr[i].genre);
}

void SeekByID(int ID) {
	int response;
	FILE *fp;
	REGISTER a;
	fp = fopen("list.bin", "r");
	// SEEK_SET (First content pointer by "fp")
	// SEEK_CUR (Current content pointer by "fp")
	// SEEK_END (Last content pointer by "fp")
	fseek(fp, sizeof(REGISTER)*(ID - 1), SEEK_SET);
	response = fread(&a, sizeof(REGISTER), 1, fp);
	if (!response) printf("#%d ID Missed\n", ID);
	else printf("%d | %s | %c\n", a.id, a.name, a.genre);
	fclose(fp);
}
