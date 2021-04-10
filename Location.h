#pragma once
using namespace std;
class Location
{
	bool left, right, up, down; //variables to store the neighboring locations
	int Xcord, Ycord; //coordinates of the location
	int prevX, prevY; //stores the previous x and y values in a searching algorithm
	char name; //variable to hold the name and/or status of the location
	bool start, goal; //variables to hold whether the location is the start or goal
	int cost; //cost of traversing through the location
	Location* prev; //a pointer to the previous location
	bool visited;
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
		prev = nullptr;
		visited = false;
	}
	Location(const Location& L)
	{
		left = L.left;
		right = L.right;
		up = L.up;
		down = L.down;
		Xcord = L.Xcord;
		Ycord = L.Ycord;
		prevX = L.prevX;
		prevY = L.prevY;
		name = L.name;
		cost = L.cost;
		start = L.start;
		goal = L.goal;
		prev = L.prev;
		visited = L.visited;
	}
	bool getStart() const
	{
		return start;
	}
	void setStart(bool b = true)
	{
		start = b;
	}
	bool getGoal() const
	{
		return goal;
	}
	void setGoal(bool b = true)
	{
		goal = b;
	}
	char getName() const
	{
		return name;
	}
	void setName(char n = ' ')
	{
		name = n;
	}
	bool getUp() const
	{
		return up;
	}
	bool getDown() const
	{
		return down;
	}
	bool getLeft() const
	{
		return left;
	}
	bool getRight() const
	{
		return right;
	}
	void setPrev(Location* p)
	{
		prev = p;
	}
	Location* getPrev() const
	{
		return prev;
	}
	void setX(int x)
	{
		Xcord = x;
	}
	int getX() const
	{
		return Xcord;
	}
	void setY(int y)
	{
		Ycord = y;
	}
	int getY() const
	{
		return Ycord;
	}
	void setVisited(bool b = true)
	{
		visited = b;
		if (this->getName() == ' ')
			this->setName('.');
	}
	bool Visited() const
	{
		return visited;
	}
	int getCost() const
	{
		return cost;
	}
};