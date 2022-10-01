#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX_LEN    100

typedef struct st_data {
    int id;
    char name[NAME_MAX_LEN];
    char gender;
} DATA;

typedef struct st_node {
    DATA data;
    struct st_node *next;
} NODE;

void insert_top(NODE **TOP, DATA *data);
void print_list(NODE *ptr);

int main(void){
    NODE *TOP = NULL;

    DATA d1 = {3,"Nadia Eyers",'F'};
    DATA d2 = {1,"Cully Poundsford",'M'};
    // DATA d3 = {2,"Hortense Voaden",'F'};
    // DATA d4 = {20,"Juana Perez",'F'};
    // DATA d5 = {7,"Juan Rodriguez",'M'};
    // DATA d6 = {0,"Alberto Fernandez",'M'};

    insert_top(&TOP, &d1);
    insert_top(&TOP, &d2);
    print_list(TOP);
}


//insert link at the first location (top)
void insert_top(NODE **TOP, DATA *data) {
   //create a node
   NODE n = (NODE) malloc(sizeof(NODE));
   //NODE *n = malloc(sizeof(NODE));
	
   // asign data
   n->data = *data;
	
   //point it to old first node
   n->next = *TOP;
	
   //point first to new first node
   *TOP = n;
}

//display the list
void print_list(NODE *ptr) {
   printf("[\n");
	
   while(ptr != NULL) {
      printf("\t(%d,%s,%c)\n",ptr->data.id,ptr->data.name, ptr->data.gender);
      ptr = ptr->next;
   }
	
   printf("]\n");
}
