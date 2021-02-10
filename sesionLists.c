#include "coronaTypeStructs.h"
#include<stdio.h>

sesionlist list_create()
{
   return NULL;

}

bool list_is_empty(sesionlist list)
{
    if (list == NULL)
    {
       return true;
    }
    else{
        return false; 
    }
    
}
void list_insert( sesionlist *headptr, sesion_struct data) 
{  
    list_node *new_node;
    //aloc data for node.
    new_node =(list_node*)malloc(sizeof(list_node));
    
    //add data into list.
    new_node->date_d = data;
    

    //insert node into a list.
    //Case1: List is empty.
      if (*headptr == NULL)
      {
          *headptr == new_node;
          new_node->next = NULL;
      }
      //Case2: List is populated.
      else
      {
           new_node->next = *headptr;
           *headptr = new_node;
      }


}