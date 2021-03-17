
#include "sesionlist.h"
#include<stdio.h>
#include<stdlib.h>
#include "debug.h" 



sessionlist list_create()
{
   return NULL;

}

bool list_is_empty(sessionlist list)
{
    if (list == NULL)
    {
       return true;
    }
    else{
        return false; 
    }
    
}
void list_insert( sessionlist * headptr, session_data data) 
{  
    sessionlist_node *new_node;
    sessionlist_node *temp_node;

    //aloc data for node.
    new_node = (sessionlist_node *) malloc(sizeof(sessionlist_node));
    //add data into list.
    new_node->data = data;
    

    //insert node into a list.
    //Case1: List is empty.
     if(*headptr ==NULL || is_before(data.date, (*headptr)->data.date))
     {
        DEBUG("list_insert, case 1 - empty list");

        new_node->next = *headptr;
        *headptr = new_node;
     }
       
      //Case2: List is populated.
      else
      {
           temp_node = *headptr;
           while (temp_node->next != NULL &&
                  is_before(temp_node->next->data.date, new_node->data.date))
           {
             temp_node = temp_node->next;  
           }
           
           DEBUG("list_insert, case 2 -  list has content");
          new_node->next = temp_node->next;
          temp_node->next = new_node;
      }
}
void print_sesion_data(session_data data, FILE *fileptr)
{
     //print_fi_std(data.date);
     fprintf(fileptr, "%d.%d.%d telepfone id %d\n",data.date.day, data.date.month, data.date.year,
                                                   data.codePhone);
}

void list_print_all(sessionlist list)
{
sessionlist_node * current_node;
DEBUG("list_print_all start");
current_node = list;

while (current_node != NULL)
{   DEBUG("list_print_all inside loop");
    //Print the content of the node
   print_sesion_data(current_node->data, stdout);
    
    //Go to next node
    current_node = current_node->next;
}
 
}

sessionlist list_read_from_file(FILE * fileptr, sessionlist list)
{   
    DEBUG("list_read_from_file begining of funktion");
    sessionlist new_list = list;
    session_data new_data;
    int fields_read = 0;
 
    do
    {
       fields_read = fscanf(fileptr, "%d.%d.%d telepfone id %d\n", &new_data.date.day, &new_data.date.month, &new_data.date.year, 
                                                  &new_data.codePhone);

       if (fields_read == 4)
       {
        DEBUG("list_read_from_file inserting new session");
        list_insert (&new_list, new_data);
       }
    }while(fields_read == 4);

    return new_list;
}

void list_write_to_file(FILE * fileptr, sessionlist list)
{
sessionlist_node * current_node;
DEBUG("list_write_to_file start");
current_node = list;

while (current_node != NULL)
{   DEBUG("list_write_to_file inside loop");
    //Print the content of the node
   print_sesion_data(current_node->data, fileptr);
    
    //Go to next node
    current_node = current_node->next;
} 
 
}

void remove_all_of_type(sessionlist * listptr, date_t cut_of_day)
{
   
   sessionlist_node * current_node;
   sessionlist_node * previous_node;
   
   current_node = *listptr;
   previous_node = NULL;
  
   cut_of_day= set_to_today(cut_of_day); 
   cut_of_day=get_n_days_previous(cut_of_day, 21);
   while (current_node != NULL)
   { 
       
       if(is_before(current_node->data.date, cut_of_day))
        {
           DEBUG("remove_all_of_type: found element to delete.");
           
           //This node should be deleted
           if(previous_node == NULL)
           {
              //First element deleted.
              
              DEBUG("remove_all_of_type: deleting firs element.");
              *listptr = current_node->next;
              free(current_node);
              current_node = *listptr;
           }
           else
           {
              //Other element deleted
              DEBUG("remove_all_of_type: deleting other element.");
              previous_node->next = current_node->next;
              free(current_node);
              current_node = previous_node->next;
           }   
       }
       else
       {
           //This node should no be deleted
           DEBUG("remove_all_of_type: element shod not be deleted.");
           previous_node = current_node;
           current_node = current_node->next;
       }
   }

}



  