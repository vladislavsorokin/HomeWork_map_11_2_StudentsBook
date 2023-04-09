#pragma once
#include "Library.h"

void DisplayDataStudents(const map<string, vector<string>>& studentsMarks)
{
    int count = 1;
    for(pair <string, vector<string>> item : studentsMarks)
    {
        cout << count << ".\t";
        cout << item.first + "\t| ";
        for (int i = 0; i < item.second.size(); ++i)
        {
            cout << item.second[i] + " | ";
        }
        cout << endl;
        cout<<"-----------------------------------------"<<endl;
        ++count;
    }
}
void DisplayDataStudents(const pair<string, vector<string>>& studentsMarks)
{
    int count = 1;
    cout << count << ".\t";
    cout << studentsMarks.first + "\t| ";
    for (int i = 0; i < studentsMarks.second.size(); ++i)
    {
        cout << studentsMarks.second[i] + " | ";
    }
    cout << endl;
    cout<<"-----------------------------------------"<<endl;
    ++count;
}