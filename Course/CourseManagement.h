#pragma once
#include"Course.h"

class CourseManagement{
    private:
        vector<Course*> Course_List;
        CourseManagement();
    public:
        ~CourseManagement();
        void Add_Course(Course*);
        void Courses_Display();
        static CourseManagement* ReturnUniqueObject();
};