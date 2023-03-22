#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

struct SALESREC
{
	char     date[12];
	char     region[12];
	char     rep[12];
	char     item[12];
	int      units;
	float    unitCost;
	float    Total;
};

void simpleSortTotal(SALESREC* arr[], int c);

int main()
{
	ifstream infile;
	int i=0;
	char cNum[10] ;
	SALESREC salesArr[40];
	int   salesArrayCount = 0;
	SALESREC* s[40];

  cout << "start\n";
		infile.open ("SalesData.txt", ifstream::in);
		if (infile.is_open())
		{
		int   c=0;
		while (infile.good())
		{
			infile.getline(salesArr[c].date, 256, ',');
			infile.getline(salesArr[c].region, 256, ',');
			infile.getline(salesArr[c].rep, 256, ',');
			infile.getline(salesArr[c].item, 256, ',');
			infile.getline(cNum, 256, ',');
			salesArr[c].units = atoi(cNum);
			infile.getline(cNum, 256, ',');
			salesArr[c].unitCost = atof(cNum);
			infile.getline(cNum, 256, '\n');
			salesArr[c].Total = atof(cNum);

			i++ ;
			c++;
		}
		salesArrayCount = c-1;
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	
	// Initialize the sort array pointers
	for (int i=0; i < salesArrayCount; i++){
		s[i] = &salesArr[i];
	
		}

	simpleSortTotal (s, salesArrayCount);

	for (int i=0; i < salesArrayCount; i++)
		cout << "Record: " << s[i]->date <<", " << s[i]->region << ", " << s[i]->rep << ", " << s[i]->item << ", " << s[i]->units << ", " << s[i]->unitCost << ", " << s[i]->Total << endl;
		
}
 
// arguments will be an array of pointers and a count


void simpleSortTotal( SALESREC* arr[], int c)
{
				SALESREC* k;

	for (int i=0; i < c; i++){
		for (int j=i; j < c; j++){
		if (arr [i]->Total > arr[j]->Total)
		{
			k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
		}
		}
	}
} 


