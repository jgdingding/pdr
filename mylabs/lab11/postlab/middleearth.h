#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:
	/**
 	* @brief Constructor for MiddleEarth
 	*
 	* This function initializes a random graph of Middle Earth world
 	*
 	* @param xsize size of horizontal axis 
 	* @param ysize size of vertical axis
	* @param num_cities number of cities to generate
	* @param seed seed used for random generation
 	*/
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);

	/**
	 * @brief Displays information for MiddleEarth object
	 *
	 * This function prints out the total number of cities, number of cities used, and the coordinates of each city through standard output
	 *
	 */
    void print();

	/**
	 * @brief Prints the world information in table format
	 *
	 * This function prints out a tab-separated table, which can be loaded into Excel
	 * 
	 */
    void printTable();

	/**
	 * @brief Returns the distance between two cities
	 *
	 * This function returns the distance between two passed cities using the hash table
	 *
	 * @param city1 the first city name
	 * @param city2 the second city name
	 *
	 * @return The distance between the two cities as a float
	 *
	 */
    float getDistance(const string& city1, const string& city2);

	/**
	 * @brief Returns a random list of cities to travel to
	 * 
	 * This function returns a random list of the generated cities of a specified length
	 * 
	 * @param length The length of the itinerary
	 *
	 * @return The list of cities to travel to
	 *
	 */
    vector<string> getItinerary(unsigned int length);

private:
    int num_city_names, xsize, ysize;
    unordered_map<string, float> xpos, ypos;
    vector<string> cities;
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
