#pragma once
#include"Result.h"
#include"../Teacher/Teacher.h"
#include"../Student/Student.h"
#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

class TeacherUser;

class Course{
    private:
        string Crs_ID;
        string Crs_Name;
        Teacher* Crs_Teacher;
        map<Student*, Result> Res_List;
    public:
        Course(string = "NULL", string = "NULL",Teacher* = nullptr);
        ~Course();
        string getName();
        string getID();
        string getTeacherName();
        int getNumber();
        double getTX(Student*);
        double getGK(Student*);
        double getCK(Student*);
        void setTX(Student*,double);
        void setGK(Student*,double);
        void setCK(Student*,double);
        void Add_Student(Student*);
        void Set_Result(Student*);
        void Show_Student();
        void Course_Delete();
        static bool Crs_Cmp(const Course*, const Course*);
        friend Student;
        friend TeacherUser;

};