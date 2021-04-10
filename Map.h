#pragma once
#include "Location.h"
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct Compare
{
	bool operator()(const Location* lhs, const Location* rhs)
	{
		return lhs->getCost() > rhs->getCost();
	}
};
class Map
{
	vector<vector<Location*>> grid; //matrix grid of locations
	int rows, cols; //dimensions of the grid
	Location* start, * goal;
public:
	Map(int r = 0, int c = 0)
	{
		rows = r;
		cols = c;
		start = nullptr;
		goal = nullptr;
	}
	Map(Map &M)
	{
		grid = M.grid;
		rows = M.rows;
		cols = M.cols;
		start = M.start;
		goal = M.goal;
	}
	void push_line(vector<Location*> line)
	{
		grid.push_back(line);
		rows++;
		cols = line.size();
	}
    int Rows()
    {
        return rows;
    }
    int Cols()
    {
        return cols;
    }
	void setStart()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j]->getStart())
				{
					start = grid[i][j];
				}
			}
		}
	}
	void setGoal()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j]->getGoal())
				{
					goal = grid[i][j];
				}
			}
		}
	}
	void setXY() //function to set coordinates for each location
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				grid[i][j]->setX(i);
				grid[i][j]->setY(j);
			}
		}
	}
	void display()
	{
        cout << '+';
        for (int i = 0; i < rows; i++)
            cout << "---+";
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << '|';
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j]->getStart())
                {
                    cout << "(" << grid[i][j]->getName() << ")";
                }
                else if (grid[i][j]->getGoal())
                {
                    cout << "{" << grid[i][j]->getName() << "}";
                }
                else
                {
                    cout << " " << grid[i][j]->getName() << " ";
                }

                if (!grid[i][j]->getRight())
                {
                    cout << '|';
                }
                else 
				{ 
					cout << ' '; 
				}
            }
            cout << endl;
            cout << '+';
            for (int j = 0; j < cols; j++)
            {
                if (!grid[i][j]->getDown())
                {
                    cout << "---+";
                }
                else
                {
                    cout << "   +";
                }
            }
            cout << endl;
        }
        cout << endl;
	}
	vector<vector<Location*>> getGrid()
	{
		return grid;
	}
	void DFS()
	{
		Location* curr;
		stack<Location*> search;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				grid[i][j]->setVisited(false);
				if (grid[i][j] == start)
				{
					grid[i][j]->setVisited(true);
					search.push(grid[i][j]);
				}
			}
		}
		while (!search.empty())
		{
			curr = search.top();
			search.pop();
			curr->setVisited();
			if (curr->getGoal())
			{
				return Success(curr);
			}
			if (curr->getDown() == true and ((grid[curr->getX() + 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() + 1][((curr->getY()))]);
				grid[curr->getX() + 1][(curr->getY())]->setPrev(curr);
			}
			if (curr->getRight() == true and ((grid[curr->getX()][(curr->getY() + 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() + 1)]);
				grid[curr->getX()][(curr->getY() + 1)]->setPrev(curr);
			}
			if (curr->getLeft() == true and ((grid[curr->getX()][(curr->getY() - 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() - 1)]);
				grid[curr->getX()][(curr->getY() - 1)]->setPrev(curr);
			}
			if (curr->getUp() == true and ((grid[curr->getX() - 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() - 1][(curr->getY())]);
				grid[curr->getX() - 1][(curr->getY())]->setPrev(curr);
			}
		}
		cout << "Depth first search yielded no results" << endl;
	}
	void BFS()
	{
		Location* curr;
		queue<Location*> search;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				grid[i][j]->setVisited(false);
				if (grid[i][j] == start)
				{
					grid[i][j]->setVisited(true);
					search.push(grid[i][j]);
				}
			}
		}
		while (!search.empty())
		{
			curr = search.front();
			search.pop();
			curr->setVisited();
			if (curr->getGoal())
			{
				return Success(curr);
			}
			if (curr->getDown() == true and ((grid[curr->getX() + 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() + 1][((curr->getY()))]);
				grid[curr->getX() + 1][(curr->getY())]->setPrev(curr);
			}
			if (curr->getRight() == true and ((grid[curr->getX()][(curr->getY() + 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() + 1)]);
				grid[curr->getX()][(curr->getY() + 1)]->setPrev(curr);
			}
			if (curr->getLeft() == true and ((grid[curr->getX()][(curr->getY() - 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() - 1)]);
				grid[curr->getX()][(curr->getY() - 1)]->setPrev(curr);
			}
			if (curr->getUp() == true and ((grid[curr->getX() - 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() - 1][(curr->getY())]);
				grid[curr->getX() - 1][(curr->getY())]->setPrev(curr);
			}
		}
		cout << "Breadth first search yielded no results" << endl;
	}
	void DA()
	{
		Location* curr;
		priority_queue<Location*, deque<Location *>, Compare> search;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				grid[i][j]->setVisited(false);
				if (grid[i][j] == start)
				{
					grid[i][j]->setVisited(true);
					search.push(grid[i][j]);
				}
			}
		}
		while (!search.empty())
		{
			curr = search.top();
			search.pop();
			curr->setVisited();
			if (curr->getGoal())
			{
				return SuccessDA(curr);
			}
			if (curr->getDown() == true and ((grid[curr->getX() + 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() + 1][((curr->getY()))]);
				grid[curr->getX() + 1][(curr->getY())]->setPrev(curr);
			}
			if (curr->getRight() == true and ((grid[curr->getX()][(curr->getY() + 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() + 1)]);
				grid[curr->getX()][(curr->getY() + 1)]->setPrev(curr);
			}
			if (curr->getLeft() == true and ((grid[curr->getX()][(curr->getY() - 1)])->Visited() == false))
			{
				search.push(grid[((curr->getX()))][(curr->getY() - 1)]);
				grid[curr->getX()][(curr->getY() - 1)]->setPrev(curr);
			}
			if (curr->getUp() == true and ((grid[curr->getX() - 1][(curr->getY())])->Visited() == false))
			{
				search.push(grid[curr->getX() - 1][(curr->getY())]);
				grid[curr->getX() - 1][(curr->getY())]->setPrev(curr);
			}
		}
		cout << "Dijkstra's Algorithm yielded no results" << endl;
	}
	void Success(Location* goal) 
	{
		stack<Location*> correctOrder;
		correctOrder.push(goal);
		goal = (goal->getPrev());

		if (goal == nullptr)
			cout << "Start and goal are in the same spot!" << endl;

		while (goal != nullptr) 
		{
			if (goal->getName() == '.')
			{
				goal->setName('O');
			}
			correctOrder.push(goal);
			goal = (goal->getPrev());
		}
		while (!correctOrder.empty()) 
		{
			cout << "(" << (correctOrder.top()->getX() + 1) << ", " << (correctOrder.top()->getY() + 1) << ") ";
			correctOrder.pop();
		}
		cout << endl << endl;
	}
	void SuccessDA(Location* goal)
	{
		stack<Location*> correctOrder;
		correctOrder.push(goal);
		goal = (goal->getPrev());
		int cost = 0;

		if (goal == nullptr) cout << "Start and goal are the same! ";
		while (goal != nullptr) 
		{
			goal->setName(std::to_string(goal->getCost())[0]);
			correctOrder.push(goal);
			goal = (goal->getPrev());
		}
		while (!correctOrder.empty()) 
		{
			cout << "(" << (correctOrder.top()->getX() + 1) << ", " << (correctOrder.top()->getY() + 1) << ") ";
			cost += correctOrder.top()->getCost();
			correctOrder.pop();
		}
		cout << "The Cost is: " << cost << endl;
		cout << endl;
	}
};