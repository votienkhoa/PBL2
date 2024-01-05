#pragma once
#include"../Class/Class.h"
#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
#include<conio.h>
#include<algorithm>
using namespace std;

class StudentManagement;
class Course;
class UserManagement;
class NormalUser;


class Student{
    private:
        string Stu_Name;
        string Stu_ID;
        bool Stu_Sex;
        string Stu_BD;
        string Stu_Address;
        NormalUser* Stu_Account;
        Class* Stu_Class;
        vector<Course*> Stu_Courses;
    public:
        Student(string, string , bool, string, string , Class* = nullptr);
        Student(string);
        ~Student();
        string getName() const;
        string getID() const;
        bool getSex() const;
        string getBD() const;
        string getAddress() const;
        Class* getClass() const;
        NormalUser* getAccount();
        void setClass(Class*);
        void setAccount(NormalUser*);
        void Stu_Display1();
        void Stu_Display2();
        void Class_Students_List();
        void Stu_Edit();
        void Stu_Delete();
        void Birthday_Conv();
        void Courses_Display();
        static bool Stu_Cmp(const Student* a, const Student* b);
        friend class StudentManagement;
        friend class UserManagement;
        friend class Course;
        // friend void Students_Display(vector<Student*>);
};




