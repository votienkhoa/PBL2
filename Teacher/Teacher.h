#pragma once
#include"../User/User.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<conio.h>
using namespace std;

class StudentManagement;
class Class;
class Course;
class User;
class AdminUser;
class TeacherUser;

class Teacher{
    private:
        string Tch_Name;
        string Tch_ID;
        bool Tch_Sex;
        string Tch_BD;
        string Tch_Address;
        Class* Tch_Class;
        vector<Course*> Tch_Courses;
        TeacherUser* Tch_Account1 = nullptr;
        AdminUser* Tch_Account2 = nullptr;
    public:
        Teacher(string = "NULL", string = "NULL", bool = 0, string = "NULL", string = "NULL", Class* = nullptr);
        ~Teacher();
        string getName();
        Class* getClass();
        TeacherUser* getAccount1();
        AdminUser* getAccount2();
        int getRealAccount();
        void setAccount(User*);
        void setClass(Class*);
        void Courses_Display();
        void Tch_Display1();
        void Tch_Display2();
        void Tch_Edit();
        void Birthday_Conv();
        friend Course;
        // void Call_StudentManagement(StudentManagement*);
        // friend class TeacherManagement;
};