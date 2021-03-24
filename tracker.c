#include <stdbool.h>
#include <stdio.h>
#include "sesionlist.h"
#include "date.h"
#include <string.h>
#include <stdlib.h>


sessionlist my_sessions;
session_data my_sessions1;
date_t my_cut_of_days;



void print_menu()
{  
    printf("1. Enter opening code and date of registration:\n");
    printf("2. Add a new date and a new phone ID\n");
    printf("3. Display all stored sessions\n");
    printf("4. Delete old date\n");
    printf("5. Corona alarm!\n");
    printf("6. Quit\n\n");
    
}

void clear_buffer()
{
    while (getchar() != '\n');
}

void print_prompt()
{
   printf("> ");
}

int prompt_user()
{
    int selection;
    print_prompt();
    while (scanf("%d", &selection) != 1)
    {
        printf("Incorrect input, please select a number from the menu.\n");
        clear_buffer();
        print_prompt();
    }
    return selection;
}

int read_phonecode()
{
    int exercise_type;
    printf("Phone ID : ");
    while (!scanf("%d", &exercise_type))
    {
        printf("Incorrect input, please input an integer for phone ID.\n");
        clear_buffer();
        printf("Phone ID : ");
    }
    return exercise_type;
}

date_t read_date()
{
    int day, month, year;
    date_t new_date;
    bool date_done = false;
      
    while (!date_done)
    {
        printf("Date : ");

        while ((scanf("%d.%d.%d", &day, &month, &year) < 3))
        {
            printf("Incoerent input, please input date in format dd.mm.yyyy\n");
            clear_buffer();
            printf("Date : ");
        }
        set_date(&new_date, day, month, year);
        if (!is_valid(new_date))
        {
            printf("incorect date, please input a valid date.\n");
        }
        else
        {
            date_done = true;
        }
        
    }
    
    return new_date;
}

void add_session()
{
    
    session_data new_session;

    new_session.date = read_date();
    new_session.codePhone = read_phonecode();
    list_insert(&my_sessions, new_session);
}

void print_session()
{
    char * header = "-------------------------\n";
    printf("%s       All sessions       \n%s", header, header);
    list_print_all(my_sessions);
    printf("%s", header);
}

void test_positiv()
{
   printf("Enter phone code:");
   scanf("%d", &my_sessions1.codePhone);
   my_sessions1.date = set_to_today(my_sessions1.date); 
   
   fflush(stdin);
   printf("\n");
   printf("=====================================================\n");
   printf("\n");
   printf("Your cod and date of registration is: [%d] %d.%d.%d\n", my_sessions1.codePhone, my_sessions1.date.day,
                                                                   my_sessions1.date.month, my_sessions1.date.year);
   printf("Telephone registered!\n");
   printf("\n");
   printf("=====================================================\n");
   printf("\n");

}

void corona_alarm()
{
   bool alarm_menu = true;
   int alarm;


   printf("\n");
   printf("=====================================================\n");
   printf("\n");
   printf("Enter 9 for corna exposed or 0 for no exposure: \n");
   printf("\n");
   printf("=====================================================\n");

   while (alarm_menu)
   {

      scanf("%d", &alarm);
      fflush(stdin);

      if (alarm == 9)
      {
         printf("\n");
         printf("=====================================================\n");
         printf("\n");
         printf("You have been exposed to corona virus!!! \nPlease contact the hospital to book time for Corona test.\n");
         printf("\n");
         printf("=====================================================\n");
         alarm_menu = false;
      }
      else if (alarm == 0)
      {
         printf("\n");
         printf("=====================================================\n");
         printf("\n");
         printf("You are safe!!!\n");
         printf("\n");
         printf("=====================================================\n");
         alarm_menu = false;
      }
      else
      {
         printf("Eror, enter 0 or 9\n");
         printf("\n");
      }
   }
}



int main(int argc, char const *argv[])
{
    bool done = false;
    int selection = 0;
    char *filename = "sessions.txt";
    FILE *fileptr;
    my_sessions = list_create();


    fileptr = fopen(filename, "r");
    if(fileptr != NULL)
    {
       my_sessions = list_read_from_file(fileptr, my_sessions);
       fclose(fileptr);
    }
    else
    {
      printf("WARINIG, could not open file %s for reading. Starting with empty session list.\n", filename);
    }

    if (selection == strcmp("Add", argv[1]))
    {
        session_data interactive;
        int day;
        int month;
        int year;
        int phoneId;
        //phoneId = atoi(argv[2]);
        sscanf(argv[2],"%d", &phoneId);
        sscanf(argv[3], "%d.%d.%d", &day, &month, &year);

        printf("New corona code: [%d]  Date: %d.%d.%d", phoneId, day, month, year);
        
        interactive.codePhone=phoneId;
        interactive.date.day=day;
        interactive.date.month=month;
        interactive.date.year=year;
        
        list_insert(&my_sessions, interactive);
        fileptr = fopen(filename, "w");
        if(fileptr != NULL)
        {
           list_write_to_file(fileptr, my_sessions);
           fclose(fileptr);
        }
        else
        {
           printf("WARINIG, could not open file %s for writing. Session data lost.\n", filename);
        }

        exit(0);
    }
    else if(selection == strcmp("History", argv[1]))
    {
      
      print_session();
      exit(0);
    }
    else if (selection == strcmp("Help", argv[1]))
    {
    
       printf("Commands: Add (code) (day.month.year)\n" 
                         "History (show history)\n"
                         "Interactive(Interactive mode)");
        exit(0);
    }
    else if (selection == strcmp("Interactive", argv[1]))
    {
         my_sessions = list_read_from_file(fileptr, my_sessions);
         print_session();
    
     while (!done)
        {
            print_menu();
            selection = prompt_user();

            switch (selection)
            {
            case 1:
                test_positiv();
            break;

            case 2:
                add_session();
            break;

            case 3:
                print_session();
            break;

            case 4:
                remove_all_of_type(&my_sessions, my_cut_of_days);           
            break;

            case 5:
                 corona_alarm();
             break;

            case 6:
                done = true;
            break;
        
            default:
                printf("Incorect input %d\n", selection);
            break;
        }

    fileptr = fopen(filename, "w");
    if(fileptr != NULL)
    {
       list_write_to_file(fileptr, my_sessions);
       fclose(fileptr);
    }
    else
    {
      printf("WARINIG, could not open file %s for writing. Session data lost.\n", filename);
    }
    }
    exit(0);
  }

    fileptr = fopen(filename, "w");
    if(fileptr != NULL)
    {
       list_write_to_file(fileptr, my_sessions);
       fclose(fileptr);
    }
    else
    {
      printf("WARINIG, could not open file %s for writing. Session data lost.\n", filename);
    }

   
  return 0;  
}