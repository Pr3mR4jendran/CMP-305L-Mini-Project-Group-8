#pragma once
#include<string>
using namespace std;
class Location
{
	bool left, right, up, down; //variables to store the neighboring locations
	int Xcord, Ycord; //coordinates of the location
	int prevX, prevY; //stores the previous x and y values in a searching algorithm
	char name; //variable to hold the name and/or status of the location
	bool start, goal; //variables to hold whether the location is the start or goal
	int cost; //cost of traversing through the location
public:
	Location(bool l = false, bool r = false, bool u = false, bool d = false, char n = ' ', int c = 0)
		: left(l), right(r), up(u), down(d), name(n), cost(c) 
	{
		Xcord = 0;
		Ycord = 0;
		prevX = 0;
		prevY = 0;
		start = false;
		goal = false;
	}
	Location(const Location& L)
	{
		left = L.left;
		right = L.right;
		up = L.up;
		down = L.down;
		Xcord = L.Xcord;
		Ycord = L.Ycord;
		status = L.status;
		prevX = L.prevX;
		prevY = L.prevY;
		name = L.name;
		cost = L.cost;
		start = L.start;
		goal = L.goal;
	}
	bool getStart()
	{
		return start;
	}
	void setStart()
	{
		start = true;
	}
	bool getGoal()
	{
		return goal;
	}
	void setGoal()
	{
		goal = true;
	}
	char getName()
	{
		return name;
	}
	bool getUp()
	{
		return up;
	}
	bool getDown()
	{
		return down;
	}
	bool getLeft()
	{
		return left;
	}
	bool getRight()
	{
		return right;
	}
	friend ostream& operator<<(ostream& out, const Location& L)
	{
		cout << "+";
		if (L.up)
			cout << "   ";
		else
			cout << "---";
		cout << "+";
		cout << endl;
		if (L.left)
			cout << " ";
		else
			cout << "|";
		cout << L.name << "  ";
		if (L.right)
			cout << " ";
		else
			cout << "|";
		cout << endl;
		cout << "+";
		if (L.down)
			cout << "   ";
		else
			cout << "---";
		cout << "+";
		return out;
	}
};