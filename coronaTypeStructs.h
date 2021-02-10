#include "corona.h" 
#include<stdbool.h> 
 
typedef struct sesion_struct
{
   int day;
   int month;
   int year;

}sesion_struct; 

struct list_node_struct{
   struct sesion_struct date_d;
   struct list_node_struct * next;
};

typedef struct list_node_struct  list_node;

typedef list_node * sesionlist;


sesionlist list_create();

/**
 * function for testing if the list is empty.
 * @return true if empty false if otherwawise
 */
 bool list_is_empty(sesionlist list);

 /**
  * Function for storing session data in the list.
  * @param listptr pointer to a list.
  * @param data The data to be insertet.
  */
 void list_insert( sesionlist *listptr, sesion_struct data);  