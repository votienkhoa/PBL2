#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Student;
class Teacher;
class ClassManagement; //de friend

class Class{
    private:
        string Cls_Name;
        Teacher* Cls_Teacher;
        vector<Student*> Cls_List;
    public:
        Class(string = "NULL", Teacher* = nullptr);
        ~Class();
        string getName() const;
        string getTeacherName() const;
        vector<Student*> getCls_List();
        void Add_Student(Student*);
        void Show_Student();
        void Cls_Delete();
        static bool Cls_Cmp(const Class*, const Class*);
        friend ClassManagement;
        friend Student;
};
