#include "coronaTypeStructs.h"
#include<stdio.h>
#include<stdbool.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: the list is NOT empty.\n");

int main()
{
    sesionlist myList;
    sesion_struct session1;

    TEST_CASE("Create list\n");
    myList = list_create();
    
    VERIFY (list_is_empty(myList), "list_is_empty.")
   
    TEST_CASE("Insert element");

    session1.day = 
    session1.month = 
    session1.year=
    list_insert(&myList, session1)
}