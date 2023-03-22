#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class SalesRep
{
   public:
      char  rep[30];		// A character array for ‘rep’ last name.
      char  region[30];		// A character array for the rep’s ‘region’
};

class ItemCatalog
{
   friend  class SalesRep;
   public:
      char     item[30];	// character array for ‘item’ name.
   protected:
      int    unitCost;	// a real number for ‘unitCost’.
     
};

class SALESREC: public SalesRep, public ItemCatalog
{
   public:
      char     date[12];
      int      units;
     
      void setUnitCost(float  a)
      {
         unitCost = a;
      }
     
      float getUnitCost()
      {
         return  unitCost;
      }

      float Total()
      {
         return   unitCost * units;
      }
     
      void displayRec()
      {
       cout << "Record: " << date <<", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost << ", " << Total() << endl;
      }
};

void simpleSortTotal(SALESREC* s[], int c);

int main()
{
   ifstream infile;
   int array[20];
   char cNum[16] ;
   SALESREC* salesArr[40];
   int   salesArrayCount;
   SALESREC* s[40];
  
    infile.open ("SalesDataP3.csv");
    if (infile.is_open())
    {
         int   c=0;
         float inputUnitCost;
         while (infile.good())
         {
                  salesArr[c] = new SALESREC();
                 infile.getline(salesArr[c]->date, 256, ',');
                 infile.getline(salesArr[c]->region, 256, ',');
                 infile.getline(salesArr[c]->rep, 256, ',');
                 infile.getline(salesArr[c]->item, 256, ',');
                 infile.getline(cNum, 256, ',');
                 salesArr[c]->units = atoi(cNum);
                 infile.getline(cNum, 256, '\n');
                 inputUnitCost = atof(cNum);
                 salesArr[c]->setUnitCost(inputUnitCost);  //store in salesArr[c]
                 
                 c++;
         }
         salesArrayCount = c;
         infile.close();
    }
    else
    {
         cout << "Error opening file";
    }
 
   for (int i=0; i < salesArrayCount; i++)
      s[i] = salesArr[i];

   cout << " Unsorted Sales Record Array\n" ;
   for (int i=0; i < salesArrayCount; i++)
      salesArr[i]->displayRec();

   simpleSortTotal (s, salesArrayCount);
   
   cout << " - - - - - - - - - - - -\n" ;
   cout << " Sorted Sales Record Array\n" ;
   
   for (int i=0; i < salesArrayCount; i++)
      s[i]->displayRec();
 
   //clean up (remove from memory) allocated sales records
   for (int i=0; i < salesArrayCount; i++)
      delete   salesArr[i];
  
}


void simpleSortTotal(SALESREC* s[], int c)
{
   SALESREC* temp;
   for (int i=0; i < c; i++)
      for (int j=i; j < c; j++)
         if (s[i]->Total() >s[j]->Total())
         {
           temp = s[i];
			s[i] = s[j];
			s[j] = temp;
         }
}

