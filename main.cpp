#include <iostream>
#include <fstream>
#include"Map.h"
#include <stack>
#include <queue>
#include <string>

using namespace std;

void menu()
{
	cout << "Main Menu" << endl;
	cout << "1. Load Map" << endl;
	cout << "2. Display Map" << endl;
	cout << "3. Set start" << endl;
	cout << "4. Set goal" << endl;
	cout << "5. Find path with DFS" << endl;
	cout << "6. Find path with BFS" << endl;
	cout << "7. Find path with DA" << endl;
	cout << "8. Display path" << endl;
	cout << "9. Quit" << endl;
}

bool readFile(Map& M) 
{
    string fname;
    cout << "\nEnter the name of the map you wish to open : ";
    cin.ignore();
    getline(cin, fname);
    ifstream in(fname);
    if (in.fail()) 
    {
        cout << "\nError: Couldn't open " << fname << "!!" << endl;
        return false;
    }
    else 
    {
        for (int i = 0; i < M.Rows(); i++)
        {
            for (int j = 0; j < M.Cols(); j++)
            {
                delete M.getGrid()[i][j];
            }
        }
        vector<Location*> rows;
        char str1[100], str2[100], str3[100];
        in.getline(str1, 100);
        in.getline(str2, 100);
        in.getline(str3, 100);
        int line = 1, cell = 1;

        while (!in.eof()) 
        {
            int i = 0, j = 0, k = 1, cost = -1, cell = 0, row = 0, col = 0;
            char name = ' ';
            bool up, down, right, left;

            if (line != 1) 
            {
                strcpy(str1, str3);
                in.getline(str2, 100);
                in.getline(str3, 100);
            }

            while (i < strlen(str1) - 1)
            {
                up = down = right = left = true;
                name = ' ';
                if (str1[i] == '+') i++;
                if (str1[i] == '-') up = false;
                else if (str1[i] == ' ') up = true;
                i = i + 3;


                if (str2[j] == '|') left = false;
                else if (str2[j] == ' ') left = true;

                j = j + 2;
                if (str2[j] != ' ')
                    if (isdigit(str2[j])) 
                        cost = (str2[j] - '0');
                    else
                    {
                        cost = 0;
                        name = str2[j];
                    }
                else 
                    cost = 0;

                j = j + 2;
                if (str2[j] == '|') 
                    right = false;
                else if (str2[j] == ' ') 
                    right = true;


                if (str3[k] == ' ') down = true;
                else if (str3[k] == '-') down = false;
                k = k + 4;

                Location *temp = new Location(left, right, up, down, name, cost);
                rows.push_back(temp);
            }

            M.push_line(rows);
            rows.clear();
            line++;
        }
        cout << "\nMap read successfully\n" << endl;
        return true;
    }
}

bool setStart(Map& M)
{
    char set;
    cout << "\nPlease enter the location you would like to set as the start : ";
    cin >> set;
    for (int i = 0; i < M.Rows(); i++)
    {
        for (int j = 0; j < M.Cols(); j++)
        {
            if (M.getGrid()[i][j]->getStart())
            {
                M.getGrid()[i][j]->setStart(false);
            }
            if (M.getGrid()[i][j]->getName() == set)
            {
                M.getGrid()[i][j]->setStart(true);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    cout << endl;
}

bool setGoal(Map& M)
{
    char set;
    cout << "\nPlease enter the location you would like to set as the goal : ";
    cin >> set;
    for (int i = 0; i < M.Rows(); i++)
    {
        for (int j = 0; j < M.Cols(); j++)
        {
            if (M.getGrid()[i][j]->getGoal())
            {
                M.getGrid()[i][j]->setGoal(false);
            }
            if (M.getGrid()[i][j]->getName() == set)
            {
                M.getGrid()[i][j]->setGoal(true);
                return true;
            }
            else 
            {
                return false;
            }
        }
    }
    cout << endl;
}

int main()
{
	int ch;
    Map map;
    bool start_set = false, goal_set = false, path_found = false, file_loaded = false;
	do
	{
		menu();
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
        case 1: file_loaded = readFile(map);
            map.setXY();
			break;
        case 2: 
            if (file_loaded)
            {
                cout << endl;
                map.display();
            }
            else
            {
                cout << "\nNo file has been loaded!" << endl;
            }
            break;
        case 3: 
            if (file_loaded)
            {
                start_set = setStart(map);
                map.setStart();
            }
            else
            {
                cout << "\nNo file has been loaded!" << endl;
            }
            break;
        case 4: 
            if (file_loaded)
            {
                goal_set = setGoal(map);
                map.setGoal();
            }
            else
            {
                cout << "\nNo file has been loaded!" << endl;
            }
            break;
        case 5: 
            if (start_set and goal_set)
            {
                cout << endl;
                map.DFS();
                path_found = true;
            }
            else
            {
                cout << "\nNo starting and/or goal location has been set!" << endl;
            }
            break;
        case 6: 
            if (start_set and goal_set)
            {
                cout << endl;
                map.BFS();
                path_found = true;
            }
            else
            {
                cout << "\nNo starting and/or goal location has been set!" << endl;
            }
            break;
        case 7: 
            if (start_set and goal_set)
            {
                cout << endl;
                map.DA();
                path_found = true;
            }
            else
            {
                cout << "\nNo starting and/or goal location has been set!" << endl;
            }
            break;
        case 8: 
            if (path_found)
            {
                cout << endl;
                map.display();
            }
            else
            {
                cout << "\nNo path has been found!" << endl;
            }
            break;
        case 9: cout << "\nTerminating the program!" << endl;
            break;
        default:cout << "\nInvalid choice!! Please re-enter!!" << endl;
		}
	} while (ch != 9);
}