#pragma once
#include "Library.h"

void InsertStudent(map<string, vector<string>>& studentsMarks, string name, vector<string> marks = {""})
{
    studentsMarks.insert(pair<string, vector<string>>(name, marks));
}
void InsertStudent(map<string, vector<string>>& studentsMarks, pair<string, vector<string>> student = pair<string, vector<string>>("", {""}))
{
    studentsMarks.insert(student);
}


void UpdateNameStudent(map<string, vector<string>>& studentsMarks, string name, string newName)
{
    //Ошибка почему?
    /*for (auto& item : studentsMarks)
    {
        if(item.first == name)
        {
            item.first = newName;
            break;
        }
    }*/
    map<string, vector<string>> newStudentsMarks;
    for (const auto& item : studentsMarks) {
        if (item.first != name) {
            newStudentsMarks.insert(item);
        }
    }
    InsertStudent(newStudentsMarks, pair<string, vector<string>>(newName, studentsMarks[name]));
    studentsMarks = newStudentsMarks;
}
void UpdateMarkStudent(map<string, vector<string>>& studentsMarks, string name, string oldmark, string newmark)
{
    for (pair <string, vector<string>> item : studentsMarks)
    {
        if(item.first.size() != 0)
        {
            if(item.first == name)
            {
                for (int i = 0; i < item.second.size(); ++i) {
                    if(item.second[i] == oldmark)
                    {
                        (studentsMarks[item.first])[i] = newmark;
                        break;
                    }
                }
            }
        }
    }
}

pair<string, vector<string>> FindByName(map<string, vector<string>> studentsMarks, string name) {
    vector<string> element = studentsMarks[name];
    if(element.empty())
    {
        if(name.size() > 0)
        {

            return pair<string, vector<string>>(name, {"нет такого студента"});
        }
        else
        {
            return  pair<string, vector<string>>(name, {"нет такого студента"});
        }

    }
    else
    {
        return pair<string, vector<string>>(name, studentsMarks[name]);
    }
}
map<string, vector<string>> FindByMark(const map<string, vector<string>>& studentsMarks, string mark) {
    map<string, vector<string>> result;

    for (auto item : studentsMarks) {
        for (int i = 0; i < item.second.size(); ++i) {
            if(item.second[i] == mark)
            {
                result.insert(item);
            }
        }
    }
    return result;
}

void Delete(map<string, vector<string>>& studentsMarks, string name) {
    studentsMarks.erase(name);
}
