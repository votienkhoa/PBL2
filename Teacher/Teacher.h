#pragma once
#include"../User/User.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<conio.h>
using namespace std;

class StudentManagement;
class TeacherManagement;
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
        Teacher(string , string , bool , string , string , Class* = nullptr);
        Teacher(string);
        ~Teacher();

        string getName() const;
        string getID() const;
        bool getSex() const;
        string getBD() const;
        string getAddress() const;
        Class* getClass();
        TeacherUser* getAccount1();
        AdminUser* getAccount2();
        int getRealAccount();

        void setAccount(User*);
        void setClass(Class*);
        
        void Courses_Show();
        void Tch_Display1();
        void Tch_Display2();
        void Tch_Edit();
        void Tch_Delete();
        void Birthday_Conv();
        static bool Tch_Cmp(const Teacher*, const Teacher*);
        friend Course;
        friend TeacherManagement;
        friend class TeacherUser;
        friend class AdminUser;
};