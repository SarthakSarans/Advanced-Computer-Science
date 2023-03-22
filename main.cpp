
#include "slist.cpp"
#include "slist.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void simpleSortTotal(linked_list *s, int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {
	ifstream infile;
	int i = 0;
	char cNum[1000];
	linked_list *airportArr =
		new linked_list(); // Replace array with Linked List
	int airportCount = 0;
	 Airport* a[13500];
	int c = 0;

	infile.open("airport-codes_US.csv", ifstream::in);
	if (infile.is_open()) {
		infile.getline(cNum, 256, '\n');
		Airport *ab = new Airport();

		while (infile.good()) {
			infile.getline(ab->code, 256, ',');
			infile.getline(cNum, 256, ',');
			infile.getline(cNum, 256, ',');

			infile.getline(cNum, 256, ',');
			ab->longitude = atof(cNum);

			infile.getline(cNum, 256, ',');
			ab->latitude = atof(cNum);
			airportArr->add_node(*ab);
			infile.getline(cNum, 256, '\n');

			// if (!(c % 1000))
			// {
			//     cout << airportArr->getNode(c)->data.code << " long: " <<
			//     airportArr->getNode(c)->data.longitude << " lat: " <<
			//     airportArr->getNode(c)->data.latitude <<  endl; cout <<
			//     airportArr->getNode(c)->data.code << " long: " <<
			//     airportArr->getNode(c)->data.longitude << " lat: " <<
			//     airportArr->getNode(c)->data.latitude <<  endl;
			// }

			i++;
			c++;
			
		}
		
		airportCount = c - 1;
		infile.close();
		simpleSortTotal(airportArr, airportCount);

		
	} else {
		cout << "Error opening file";
	}
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
	return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lon2d, double lat2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm *
		asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
	Provide sort routine on linked list
*/

void simpleSortTotal(linked_list *arr, int c) {
	double maxD = 0;
    string max = "";
		int count = 0;
    for (int i = 0; i < 22338; i++) {

        double distance = distanceEarth( 30.27104167, -97.7449757, arr->getNode(i)->data.longitude, arr->getNode(i)->data.latitude)/1.609;
        if (distance < 100) {
             cout << arr->getNode(i)->data.code << " " << distance 
 << endl;
			count++;
			
        }
		
        if (distance > maxD) {
            maxD = distance;
            max = arr->getNode(i)->data.code;
        }

        
    }
cout << "Total airports within 100 miles " << count << endl;
    cout << "Farthest airport from bergstrom " << max << " " << maxD << endl;
    
   
        
}
	
