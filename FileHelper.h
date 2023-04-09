#pragma once
#include "Library.h"

bool ImportParsingDataFromFile(map<string, vector<string>>& studentsMarks, string path) {
    ifstream file;
    file.open(path);
    if(file.is_open())
    {
        string line;
        while (getline(file, line)) {
            vector<string> marks;
            int position = line.find('|');
            string name = line.substr(0, position);
            line = line.substr(position + 1);
            string number = "";
            for (int i = 0; i < line.size(); ) {
                if (line[i] != '|')
                {
                    number += line[i];
                    ++i;
                }
                else
                {
                    marks.push_back(number);
                    number = "";
                    ++i;
                }
            }
            marks.push_back(number);
            studentsMarks.insert(pair<string, vector<string>>(name, marks));
        }
        file.close();
        return true;
    } else
    {
        file.close();
        return false;
    }
}

bool ExportParsingDataToFile(map<string, vector<string>>& studentsMarks, string path) {
    ofstream file;
    file.open(path, ios::trunc);
    if (!file.is_open())
    {
        file.close();
        return false;
    }
    else
    {
        for (auto item : studentsMarks)
        {
            file << item.first << "|";
            for (string s : item.second)
            {
                file << s << "|";
            }

            file << endl;
        }
        file.close();
        return true;
    }

}