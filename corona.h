#ifndef coronah
#define coronah
#include<stdio.h>
#include<stdbool.h>

 struct dateCode_t
{
   int day;
   int month;
   int year;
   struct dateCode_t *next;
}; 

struct dateCode_t date_c;
struct dateCode_t stored[1000];



//struct dateCode_t date_c;

//struct dateCode_t myLocalTime;

//struct dateCode_t *node;

int code_id();

struct dateCode_t id_date();

bool ceck_year(struct dateCode_t real_date);

bool ceck_date(struct dateCode_t date_c);

void test_positiv();

void corona_alarm();

void print_pressentDate();

void myLinkedHistory(struct dateCode_t my);

#endif