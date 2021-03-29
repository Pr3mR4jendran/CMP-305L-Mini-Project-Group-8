#pragma once
#include<string>
using namespace std;
class Location
{
	Location* left, * right, * up, * down; //variables to store the neighboring locations
	int Xcord, Ycord; //coordinates of the location
	char status; //sets the status based on whether the location is visited
	int prevX, prevY; //stores the previous x and y values in a searching algorithm
	string name;
public:
};