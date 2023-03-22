#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class SALESREC {
private:
	string date;
	string region;
	string rep;
	string item;
	int units;
	float unitCost;
	float total;

public:
	void setDate(string a) {
		date = a;
	}
	void setReg(string b) {
		region = b;
	}
	void setRep(string c) {
		rep = c;
	}
	void setItem(string d) {
		item = d;
	}
	void setUnits(int e) {
		units = e;
	}
	void setUnitCost(float f) {
		unitCost = f;
	}
	void setTotal() {
		total = unitCost * units;
	}

	string getDate() {
		return date;
	}
	string getReg() {
		return region;
	}
	string getRep() {
		return rep;
	}
	string getItem() {
		return item;
	}
	int getUnits() {
		return units;
	}
	float getUnitCost() {
		return unitCost;
	}
	float getTotal() {
		return total;
	}
};
int main() {
	SALESREC *k;

	if ((k = (SALESREC *)calloc(BUFFER_SIZE, sizeof(SALESREC))) == NULL) {
		printf("out of memory\n");
		exit(1);
	}

	streampos size;
	char memblock;
	int spot = 0;
	string line;
	int counter = 0;
	ifstream infile("SalesDataDyn.csv", ifstream::in);
	if (infile.is_open()) {
		while (infile.good()) {
			getline(infile, line);

			if (counter == 0) {
				counter++;
				cout << "Record: OrderDate, Region, Rep, Item, 0, 0, 0" << endl;
			} else {
				int commas = 0;
				string date = "";
				string reg = "";
				string rep = "";
				string item = "";
				string unit = "";
				string unitcost = "";
				float total = 0;
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ',') {
						commas++;
						if (commas <= 3)
							i++;

					} else if (commas == 0) {
						date += line[i];

					} else if (commas == 1) {
						reg += line[i];

					} else if (commas == 2) {
						rep += line[i];

					} else if (commas == 3) {
						item += line[i];

					} else if (commas == 4) {
						unit += line[i];

					} else if (commas == 5) {
						unitcost += line[i];

					} else {
					}
				}

				k[spot].setDate(date);
				k[spot].setReg(reg);
				k[spot].setRep(rep);
				k[spot].setItem(item);
				k[spot].setUnits((int)stoi(unit));
				k[spot].setUnitCost((float)stod(unitcost));
				k[spot].setTotal();

				spot++;
			}
		}

		spot = 0;
		for (int i = 0; i < 30; i++) {
			for (int j = i; j < 30; j++) {
				if (k[i].getTotal() > k[j].getTotal()) {
					SALESREC p = k[i];
					k[i] = k[j];
					k[j] = p;
				}
			}
		}
		for (int i = 0; i < 30; i++) {
			cout << "Record: " << k[spot].getDate() << ", " << k[spot].getReg()
				 << ", " << k[spot].getRep() << ", " << k[spot].getItem()
				 << ", " << k[spot].getUnits() << ", " << k[spot].getUnitCost()
				 << ", " << k[spot].getTotal() << endl;
			spot++;
		}
	} else {
		cout << "bad";
	}
	infile.close();
}
