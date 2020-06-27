// Justin Gou
// jyg2qhc
// 04/20/20
// traveling.cpp

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// @headerfile "middleearth.h" middleearth.h
#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

	string start = dests[0];
	dests.erase(dests.begin());
	sort(dests.begin(),dests.end());

	float minDist = computeDistance(me,start,dests);
	vector<string> minPath = dests;

	do { 
		float temp = computeDistance(me,start,dests);
		if ( temp < minDist ){
			minDist = temp;
			minPath = dests;
		}
    } while (next_permutation(dests.begin(), dests.end()));

	cout << "Minimum path has distance " << minDist << ": ";
	printRoute(start,minPath);

    return 0;
}


/**
* @brief Computes the distance of a full path given
*
* This method will compute the full distance of the cycle that starts
* at the 'start' parameter, goes to each of the cities in the dests
* vector IN ORDER, and ends back at the 'start' parameter.
*
* @param me the middleearth object with all the city and distance information
* @param start starting and ending city name
* @param dests list of destinations to travel in order provided
*
* @return The distance/cost of the path given as a float
*
*/
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
	float dist = 0;
	string prev = start;
	dests.push_back(start);
	for (int i=0; i<dests.size(); i++) {
		dist += me.getDistance(prev,dests[i]);
		prev = dests[i];
	}
    return dist;
}


/**
* @brief Prints the route taken, starting and ending at the same city 
*
* This method will print the entire route, starting and ending at the
* 'start' parameter.
* The output should be similar to:
* Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
*
* @param start starting city name (also the ending city name)
* @param dests vector of city names in order of travel order
*
*/
void printRoute(const string& start, const vector<string>& dests) {
	cout << start << " -> ";
	for (int i=0; i<dests.size(); i++) {
		cout << dests[i] << " -> ";
	}
	cout << start << endl;
}

//Doxygen Documentation

/**
 *
 * \mainpage Documentation for Graph Lab in CS2150
 * 
 * \section middlearth MiddleEarth
 *
 * This is a class written by instructors that randomly 
 * generates a 2D world using city names from LoTR.
 * The distance between the cities is random, used as the weighting 
 * for edges between city vertices.
 *
 * \section traveling Traveling Saleperson Problem (TSP)
 *
 * traveling.cpp is my implementation of the TSP using a brute-force 
 * algorithm that uses next_permutation() to generate the permutations 
 * of the cities. 
 * 
 * \author Justin Gou
 * \date 4/20/2020
 *
 *
 */
