#include<iostream>
using namespace std;

class StudentManagement;

class Teacher{
    private:
        string Tch_Name;
        string Tch_ID;
        bool Tch_Sex;
        string Tch_BD;
        string Tch_Address;
    public:
        Teacher(string = "NULL", string = "NULL", bool = 0, string = "NULL", string = "NULL");
        ~Teacher();
        void Tch_Display();
        void Tch_Edit();
        void Birthday_Conv();
        void Call_StudentManagement(StudentManagement*);
};