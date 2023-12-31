#pragma once
#include"Student.h"
#include"../Public/PublicFunction.h"


class StudentManagement{
    private:
        vector<Student*> Student_List;
    public:
        StudentManagement();
        ~StudentManagement();
        vector<Student*> getStudent_List();
        void Add_Student(Student*);
        static StudentManagement* ReturnUniqueObject();

        friend class Student;
};