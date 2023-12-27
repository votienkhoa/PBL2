#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<conio.h>
using namespace std;

class StudentManagement;


class Student{
    private:
        string Stu_Name;
        string Stu_ID;
        bool Stu_Sex;
        string Stu_BD;
        string Stu_Address;
        string Stu_Class;
        
    public:
        Student(string = "NULL", string = "NULL", bool = 0, string = "NULL", string = "NULL", string = "NULL");
        ~Student();
        void Stu_Display1();
        void Stu_Display2();
        void Stu_Edit();
        void Birthday_Conv();
        friend class StudentManagement;
        friend class UserManagement;
        // friend void Students_Display(vector<Student*>);
};




