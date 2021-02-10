#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "corona.h"
#include<time.h>

int count = 0;


int code_id()
{
   int id_code;
   bool ceck = true;

   while (ceck)
   {
      printf("\n");
      printf("=====================================================\n");
      printf("\n");
      printf("Enter id code: ");
      scanf("%d", &id_code);
      printf("\n");
      printf("=====================================================\n");

      if (id_code == -1)
      {
         printf("\n");
         printf("=====================================================\n");
         printf("\n");
         printf("Eror rong id!: ");
         printf("Enter id again!");
         printf("\n");
         printf("=====================================================\n");
      }
      else
      {
         ceck = false;
      }
   }

   return id_code;
}

struct dateCode_t id_date()
{
   

   printf("\n");
   printf("=====================================================\n");
   printf("\n");
   printf("Date of exposure! (dd.mm.yyyy): ");
   scanf("%d.%d.%d", &date_c.day, &date_c.month, &date_c.year);
   fflush(stdin);
   printf("\n");
   printf("=====================================================\n");

   return date_c;
}

bool ceck_year(struct dateCode_t real_date)
{

   // is a leap year if divisible by  4
   if (real_date.year % 4 == 0)
   {
      return true;
   }
   //year 2021 or later
   if (real_date.year < 2021)
   {
      return false;
   }
   //not all years are leap years
   else
   {
      return false;
   }
}

bool ceck_date(struct dateCode_t date_c)
{

   if (date_c.year < 2021)
   {
      return false;
   }

   if (date_c.month < 1 || date_c.month > 12)
   {
      return false;
   }
   else if (date_c.day < 1 || date_c.day > 31)
   {
      return false;
   }
   else if (date_c.month == 2)
   {
      if (ceck_year(date_c))
      {
         return (date_c.day <= 29);
      }
      else
      {
         return date_c.day <= 28;
      }
   }
   else if (date_c.month == 4 || date_c.month == 6 ||
            date_c.month == 9 || date_c.month == 11)
   {
      return date_c.day <= 30;
   }
   else
   {
      return date_c.month <= 31;
   }

   return true;
}

void test_positiv()
{
   int code;
   scanf("%d", &code);
   fflush(stdin);
   printf("\n");
   printf("=====================================================\n");
   printf("\n");
   printf("Your cod is [%d]\n", code);
   printf("Corona code recieved! Sendning the information to the server!\n");
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

void print_pressentDate()
{
   struct dateCode_t myLocalTime;
   time_t pressent;

   time(&pressent);

   struct tm *location = localtime(&pressent);

   myLocalTime.day = location->tm_mday;
   myLocalTime.month = location->tm_mon + 1;
   myLocalTime.year = location->tm_year + 1900;

   printf("\nCurent date : %02d.%02d.%d \n", myLocalTime.day, myLocalTime.month, myLocalTime.year );
   
}


void myLinkedHistory(struct dateCode_t stored)
{

   struct dateCode_t *node;
   struct dateCode_t date_c;
   struct dateCode_t *myNode = NULL;
   myNode = (struct dateCode_t*)malloc(sizeof(struct dateCode_t));

   if (myNode == NULL)
   {
      printf("Error empty!!");
   }

   myNode->day = stored.day;
   myNode->month = stored.month;
   myNode->year = stored.year;
   myNode->next = node;
   node = myNode;
   printf("%02d.%02d.%d\n", node->day, node->month, node->year);
   free(myNode);
}