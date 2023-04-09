//Сорокин Владислав Дмитриевич
/*
    ДЗ 2.
    Создать программу по учёту оценок студента. Данные хранятся в виде: <имя студента> - <список оценок>
    Имя студента не повторяется. Список оценок - набор чисел неопределённой размерности.
    Реализовать импорт и экспорт с/из файла, добавление данных, обновление данных, удаление данных, поиск данных.
 */

#pragma once
#include "Library.h"
#include "FileHelper.h"
#include "DisplayDataHelper.h"
#include "StudentsBook.h"


int main() {

    system("chcp 65001");

    map<string, vector<string>> studentsMarks;
    string path = "datastudents.psv";

    cout << "Import data from file and Display block" << endl;
    if(!ImportParsingDataFromFile(studentsMarks, path))
    {
        return -1;
    }

    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    cout << "Insert Student MAP and Display block" << endl;
    InsertStudent(studentsMarks, "Ваня", {"2", "2"});
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    cout << "Insert Student PAIR and Display block" << endl;
    InsertStudent(studentsMarks, pair<string, vector<string >>("Лось", {"1", "1"}));
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;


    cout << "Update NAME student and Display block" << endl;
    UpdateNameStudent(studentsMarks, "Иванов", "Иван");
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    cout << "Update MARKS student and Display block" << endl;
    UpdateMarkStudent(studentsMarks, "Петров", "1", "3");
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    cout << "FindByName student and Display block" << endl;
    DisplayDataStudents(FindByName(studentsMarks, "ddd"));
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    cout << "FindByMark students and Display block" << endl;
    DisplayDataStudents(FindByMark(studentsMarks, "5"));
    cout <<"*******************************************"<<endl;

    cout << "Delete student and Display block" << endl;
    Delete(studentsMarks, "Плюшкин");
    DisplayDataStudents(studentsMarks);
    cout <<"*******************************************"<<endl;

    /*cout << "Export data to file and Display block" << endl;
    if(ExportParsingDataToFile(studentsMarks, path))
    {
        return -2;
    }
    */

    return 0;
}
