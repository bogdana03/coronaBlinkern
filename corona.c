#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
  int day;
  int month;
  int year;
  

} dateCode_t;

int code_id()//funktion för att matta in en id för en tel vi simulerar att vi har en sever
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

    if(id_code == -1)//verifiera att  telefons id har rätt format
    {
       printf("\n");
       printf("=====================================================\n");
       printf("\n");
       printf("Eror rong id!: ");
       printf("Enter id again!");
       printf("\n");
       printf("=====================================================\n");
    }else
    {
        ceck = false;
    }
    
  }
   
   return id_code;
}//returnerar id (koden)

dateCode_t id_date()//funktion som mattar in datumet om man har varit exponerat
{ 
   
   dateCode_t date;
    
    printf("\n");
    printf("=====================================================\n");
    printf("\n");
    printf("Date of exposure! (dd.mm.yyyy): ");
    int scan =scanf("%d.%d.%d", &date.day, &date.month, &date.year);
    fflush(stdin);
    printf("\n");
    printf("=====================================================\n");

   return date;
}

bool ceck_year(dateCode_t real_date)//funktion för att verifiera om året är skot rätt
{ 
    
   
   // om det är skott år dividerar med  4 
   if (real_date.year % 4 == 0) 
   {
      return true;
   }
   //år 2021 eller senare
   if (real_date.year < 2021)
   {
      false;
   }
   //alla år är inte skott år
   else
   {
      return false;
   }

}


bool ceck_date(dateCode_t date_c)//verifierar om datumet är rätt skott år månad dag
{
   
  /* if (date_c.year < 2021)
   {
      return false;
   }*/
   
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
    if (ceck_year(date_c))//man kallar funktionen ceck year för att god känna om det är rätt år
     {
        return(date_c.day <= 29);    
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

int test_positiv()//funktion som skapar corona koden och skikar den i väg
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
  

  return code;
}


 void corona_alarm()//alarm om man har varit exponerat till corona
 {
    bool alarm_menu=true; 
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
    
     if (alarm ==9)
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
        alarm_menu =false;
        
     }
     else//om man har mattat in fel kod format 
     {
       printf("Eror, enter 0 or 9\n");
       printf("\n");
     }
     }  
   
 }
int main(void)
{
  int menu_options;
  int codes;
  int phone_code;
  bool choise = true;
  

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
    printf("4. Save and quit\n");
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

      codes = test_positiv();//positiv för corona
      printf("=====================================================\n");
    }
    else if (menu_options == 2)
    {
       
       bool myDate = true;
        
     while (myDate)
     {  
       dateCode_t date_c;
       int tel_id = code_id();//frågar efter coronakod om man har varit exponerad
       date_c = id_date();

       if(ceck_date(date_c))//verifierar att det rätt datum
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
      corona_alarm();//alarm att man har varit exponerat och skulle kontakta sjukuset
    }
    else if (menu_options == 4)
    {
      choise = false;
    }
  }

  return 0;
}
