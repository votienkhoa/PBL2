#pragma once
#include"Course.h"

class Course;

class CourseManagement{
    private:
        vector<Course*> Course_List;
        CourseManagement();
    public:
        ~CourseManagement();
        vector<Course*>& getCourse_List(); //trả về tham chiếu đến danh sách tất cả lớp HP
        void Add_Course(Course*); //thêm mới một lớp HP vào danh sách tất cả lớp HP
        static CourseManagement* ReturnUniqueObject(); //trả về đối tượng CourseManagement duy nhất

        friend Course;
};