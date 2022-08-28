#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef __UINT8_TYPE__ uint8_t;

typedef struct {
    char product[SIZE];
    uint8_t amount;
} Material_t;

Material_t fillStruct(char *, uint8_t);
void printStruct(Material_t);
uint8_t compareStructs(Material_t, Material_t);
void changeMemberStruct(Material_t *);

int main(void) {
    uint8_t stock;
    char material[SIZE];
    Material_t st_item, st_itemToCompare;
    
    // Assign values to "st_item":
    printf("\nIngrese un PRIMER material: ");
    // fgets(material, sizeof(st_item.product), stdin);
    scanf("%s", material);
    printf("Ingrese su stock: ");
    scanf("%hhu", &stock);
    st_item = fillStruct(material, stock);
    printStruct(st_item);
    
    // Assign values to "st_itemToCompare":
    printf("\nIngrese un SEGUNDO material: ");
    // fgets(material, sizeof(st_itemToCompare.product), stdin);
    scanf("%s", material);
    printf("Ingrese su stock: ");
    scanf("%hhu", &stock);
    st_itemToCompare = fillStruct(material, stock);
    printStruct(st_itemToCompare);
    
    if (!compareStructs(st_item, st_itemToCompare)) printf("\nLas estructuras son IGUALES\n");
    else printf("\nLas estructuras son DISTINTAS\n");
    
    printf("\nSe ha modificado un miembro!!");
    changeMemberStruct(&st_item);
    printStruct(st_item);
    
    if (!compareStructs(st_item, st_itemToCompare)) printf("\nLas estructuras son IGUALES\n");
    else printf("\nLas estructuras son DISTINTAS\n");
    
    return 0;
}

Material_t fillStruct(char *product, uint8_t amount) {
    Material_t aux;
    strcpy(aux.product, product);
    aux.amount = amount;
    return aux;
}

void printStruct(Material_t aux) {
    printf("\nMaterial: %s\n", aux.product);
    printf("Stock: %hhu\n", aux.amount);
}

uint8_t compareStructs(Material_t struct_FST, Material_t struct_SND) {
	uint8_t output = 0;
	if (strcmp(struct_FST.product, struct_SND.product)) output = 1;
	if (struct_FST.amount != struct_SND.amount) output = 1;
	return output;
}

void changeMemberStruct(Material_t *aux) {
	// char *newProduct = "Cebolla\n";
	// strcpy(aux -> product, newProduct);
	aux -> amount = aux -> amount + 1; // IDEM: *aux.amount --- aux -> amount
}
