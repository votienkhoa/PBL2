#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<conio.h>
using namespace std;

class StudentManagement;
class Class;
class Course;

class Teacher{
    private:
        string Tch_Name;
        string Tch_ID;
        bool Tch_Sex;
        string Tch_BD;
        string Tch_Address;
        Class* Tch_Class;
        vector<Course*> Tch_Courses;
    public:
        Teacher(string = "NULL", string = "NULL", bool = 0, string = "NULL", string = "NULL", Class* = nullptr);
        ~Teacher();
        string getName();
        Class* getClass();
        void setClass(Class*);
        void Courses_Display();
        void Tch_Display();
        void Tch_Display2();
        void Tch_Edit();
        void Birthday_Conv();
        friend Course;
        // void Call_StudentManagement(StudentManagement*);
        // friend class TeacherManagement;
};