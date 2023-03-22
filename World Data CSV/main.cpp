#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct country {
	int index;
	string variant;
	string Marea;
	string region;
	int area, notes, code, y1950, y1955, y1960, y1965, y1970, y1975, y1980,
		y1985, y1990, y1995, y2000, y2005, y2010;
};
int main() {
	streampos size;
	char memblock;
	string line;
	ifstream file("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
	int count = 0;
	int total = 227;
	int spot = 0;
	country list[total];
	if (file.is_open()) {
		while (getline(file, line)) {
			if (count < 31)
				count++;

			else {
				int inde = 0;
				int einde = 0;
				/*
					einde = line.find(',');
					list[spot].index = stoi(line.substr(inde, einde));
					cout << list[spot].index << endl;
					inde = einde +1;
					einde = line.find("\"", inde);
					cout << einde << endl;

					list[spot].variant = (line.substr(inde, einde-4));
					cout << list[spot].variant << endl;
					inde = einde ;
					einde = line.find(',', inde);
					list[spot].Marea = (line.substr(inde +1, einde));
					cout << list[spot].Marea << endl;

*/
				einde = line.find(',');
				list[spot].index = stoi(line.substr(0, einde));
				line.erase(0, einde);

				einde = line.find('"', 2);
				list[spot].variant = (line.substr(0, einde));
				line.erase(0, einde);
				einde = line.find('"', 3);
				list[spot].Marea = (line.substr(3, einde - 3));
				line.erase(0, einde);
				einde = line.find(',', 2);
				list[spot].region = (line.substr(1, einde));
				line.erase(0, einde);
				einde = line.find(',', 1);
				list[spot].area = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].notes = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].code = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				// y1950, y1955, y1960, y1965, y1970, y1975, y1980, y1985,
				// y1990, y1995, y2000, y2005, y2010

				einde = line.find(',', 1);
				list[spot].y1950 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1955 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1960 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1965 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1970 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1975 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1980 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1985 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y1990 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y2000 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				einde = line.find(',', 1);
				list[spot].y2005 = stoi(line.substr(1, einde - 1));
				line.erase(0, einde);

				spot++;
			}
		}
		/*for (int i = 0; i < total; i++) {
			for (int j = i; j < total; j++) {
				if (list[i].y2000 < list[j].y2000) {
					country k = list[i];
					list[i] = list[j];
					list[j] = k;
				}
			}
		}
		*/
		int asd =0;
		for (int i = 0; i < total; i++) {
			
			cout << asd << ". " << list[i].notes << endl;
				
		}

		file.close();
	} else
		cout << "bad";
	return 0;
}
