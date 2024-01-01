#pragma once
#include"Course.h"

class Course;

class CourseManagement{
    private:
        vector<Course*> Course_List;
        CourseManagement();
    public:
        ~CourseManagement();
        vector<Course*>& getCourse_List();
        void Add_Course(Course*);
        void Courses_Display();
        static CourseManagement* ReturnUniqueObject();

        friend Course;
};