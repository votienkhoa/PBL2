#pragma once
#include"Teacher.h"

class TeacherManagement{
    private:
        vector<Teacher*> Teacher_List;
    public:
        TeacherManagement();
        ~TeacherManagement();
        vector<Teacher*> getTeacher_List();
        void Add_Teacher(Teacher*);
        static TeacherManagement* ReturnUniqueObject();

};