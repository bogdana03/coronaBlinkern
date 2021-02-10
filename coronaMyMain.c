#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "corona.h"
#include<time.h>

int main(void)
{
   int history_codes[1000];
   int count = 0;
   int menu_options;
   bool choise = true;
   struct dateCode_t *node;
   struct dateCode_t date_c;
   int count2 = 0;

   printf("\n");
   printf("====================================================\n");
   printf("====================================================\n");
   printf(" Welcome to The Coronablinker!\n");
   printf(" Main Menu\n");
   printf(" Please enter an option from the main menu: \n\n");
   printf("====================================================\n");
   printf("====================================================\n");
   printf("\n");
   while (choise)

   {

      printf("\n");
      printf("====================================================\n");
      printf("====================================================\n");
      printf("1. For positiv corona test code:\n");
      printf("2. Code and date of exposure!\n");
      printf("3. Corona alarm!\n");
      printf("4. Show history\n");
      printf("5. Save and quit\n");
      printf("\n");
      printf("====================================================\n");
      printf("====================================================\n");
      printf("Enter your choise :");

      scanf("%d", &menu_options);
      fflush(stdin);

      if (menu_options == 1)
      {
         printf("\n");
         printf("=====================================================\n");
         printf("1. Enter your corona code:");

         test_positiv();
         
         printf("=====================================================\n");
      }
      else if (menu_options == 2)
      {

         bool myDate = true;

         while (myDate)
         {
            count++;
            //dateCode_t date_c;
            int tel_id = code_id();
            date_c = id_date();

              stored[count2].day = date_c.day;
              stored[count2].month = date_c.month;
              stored[count2].year = date_c.year; 
              count2++;
            history_codes[count - 1] = tel_id;

            if (ceck_date(date_c))
            {
               printf("\n");
               printf("=====================================================\n");
               printf("\n");
               printf("Code an d date of exposure: [%d] %d.%d.%d\n", tel_id, date_c.day, date_c.month, date_c.year);
               printf("\n");
               printf("=====================================================\n");

               myDate = false;

            }
            else
            {
               printf("Eror!!\n");
            }
         }

         
      }
      else if (menu_options == 3)
      {
         corona_alarm();
      }
      else if (menu_options == 4)
      {

         
         print_pressentDate();
         

         printf("History list: \n");
         printf("\n=========================================\n");
         printf("| Registered Code |   Date of exposure  |\n");
         printf("\n=========================================\n");
         for (int i = 0; i < count; i++)
         {
            printf("| \t%d\t  |\t", history_codes[i]);
            
            myLinkedHistory(stored[i]);

            printf("-----------------------------------------\n");   
         }
         
      }
      else if (menu_options == 5)
      {
          choise = false;
      }
      
   }
   

   return 0;
}