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

//reads map and loads it into an appropriate data structure
void readFile(Map& M) 
{
    string fname;
    cout << "\nEnter the name of the map you wish to open : ";
    cin.ignore();
    getline(cin, fname);
    ifstream in(fname);
    if (in.fail()) 
    {
        cout << "\nError: Couldn't open" << fname << "!!" << endl;
        return;
    }
    else 
    {
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
            //cout << "line " << line << endl;

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

                //cout << "cell = " << cell++ << endl;
                //cout << "above: " << up << "\t";
                //cout << "below: " << down << endl;
                //cout << "right: " << right << "\t";
                //cout << "left: " << left << endl;
                //cout << "cost: " << cost << endl;
                //cout << "name: " << name << endl;
                //cout << endl << endl;

            }

            M.push_line(rows);
            rows.clear();
            //cout << str1 << endl;
            //cout << str2 << endl;
            //cout << str3 << endl;

            line++;
        }
        cout << "\nMap read successfully\n" << endl;
    }
}

void setStart(Map& M)
{
    char set;
    cout << "\nPlease enter the location you would like to set as the start : ";
    cin >> set;
    for (int i = 0; i < M.Rows(); i++)
    {
        for (int j = 0; j < M.Cols(); j++)
        {
            if (M.getGrid()[i][j]->getName() == set)
            {
                M.getGrid()[i][j]->setStart();
            }
        }
    }
    cout << endl;
}

void setGoal(Map& M)
{
    char set;
    cout << "\nPlease enter the location you would like to set as the goal : ";
    cin >> set;
    for (int i = 0; i < M.Rows(); i++)
    {
        for (int j = 0; j < M.Cols(); j++)
        {
            if (M.getGrid()[i][j]->getName() == set)
            {
                M.getGrid()[i][j]->setGoal();
            }
        }
    }
    cout << endl;
}

int main()
{
	int ch;
    Map map;
	do
	{
		menu();
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
        case 1: readFile(map);
			break;
        case 2: map.display();
            break;
        case 3: setStart(map);
            break;
        case 4: setGoal(map);
            break;
        case 8: map.display();
            break;
        case 9: cout << "Terminating the program!";
            break;
		}
	} while (ch != 9);
}