#include <stdio.h>
#include "readBin.h"
#include <stdlib.h>
#include "date.h"
#include "sesionlist.h"

void openfile_my_file(date datum, int numid)

{
    FILE *filePointer;
    //så att filen kan öppnas, Look.txt är namnet på filen
    filePointer = fopen("Look.txt", "a+"); // a+=om sätta till flera saker, skriva till fil och sätta in mer saker

    if (filePointer == NULL)
    {
        printf("Open file ERROR\n");
    }
    else
    {
        char buffer[50];
        sprintf(buffer, "%d.%d.%d %d\n", datum.day, datum.month, datum.year, numid); // funkar som scanf
        printf("%s", buffer);
        fprintf(filePointer, "%s", buffer);
        printf("Open file SUCCESS\n");
        fclose(filePointer); // stäng!!
    }
}

struct node* get_my_data(struct node *head)
{
    FILE *filePointer;
    filePointer = fopen("Look.txt", "r"); //Läser fil//r+???

    if (filePointer == NULL)

    {
        printf("Error\n");
        return NULL;
    }
    else
    {
        // läs in data med hjälp av fgets

        char line[1000];
        date datum;
        int numid = 0;

        while (fgets(line, sizeof line, filePointer) != NULL) // läs "a line from a file"
        {

            sscanf(line, "%d.%d.%d %d", &datum.day, &datum.month, &datum.year, &numid); // läser in från filen
            //printf("%d.%d.%d %d\n", datum.day,datum.month, datum.year, numid);
            head = add_node(head, datum, numid);
        }
        fclose(filePointer); // stäng!!!
        return head;
    }
}