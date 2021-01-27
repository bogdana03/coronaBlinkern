#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
  int day;
  int month;
  int year;
  

} dateCode_t;

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

    if(id_code == -1)
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
}

dateCode_t id_date()
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

bool ceck_year(dateCode_t real_date)
{ 
    
   
   // is a leap year if divisible by  4 
   if (real_date.year % 4 == 0) 
   {
      return true;
   }
   //year 2021 or later
   if (real_date.year < 2021)
   {
      false;
   }
   //not all years are leap years 
   else
   {
      return false;
   }

}


bool ceck_date(dateCode_t date_c)
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

int test_positiv()
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


 void corona_alarm()
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
     else
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

      codes = test_positiv();
      printf("=====================================================\n");
    }
    else if (menu_options == 2)
    {
       
       bool myDate = true;
        
     while (myDate)
     {  
       dateCode_t date_c;
       int tel_id = code_id();
       date_c = id_date();

       if(ceck_date(date_c))
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
      choise = false;
    }
  }

  return 0;
}
