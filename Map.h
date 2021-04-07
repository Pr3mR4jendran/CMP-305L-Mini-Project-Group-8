#pragma once
#include "Location.h"
#include<vector>
using namespace std;
class Map
{
	vector<vector<Location*>> grid; //matrix grid of locations
	int rows, cols; //dimensions of the grid
public:
	Map(int r = 0, int c = 0)
	{
		rows = r;
		cols = c;
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
	void display()
	{
        cout << '+';
        for (int i = 0; i < rows; i++)
            cout << "---+";
        cout << endl;
        //Middle rows:
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
                else { cout << ' '; }
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
};