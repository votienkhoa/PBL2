#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

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
        void Stu_Display();
        void Stu_Edit();
        void Birthday_Conv();
        friend class StudentManagement;
        friend void Students_Display(vector<Student*>);
};
Student* Stu_Create();



