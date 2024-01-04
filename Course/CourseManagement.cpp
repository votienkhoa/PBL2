#include"CourseManagement.h"

CourseManagement::CourseManagement(){

}

CourseManagement::~CourseManagement(){

}
//-------------------------------------
vector<Course*>& CourseManagement::getCourse_List(){
    return Course_List;
}
void CourseManagement::Add_Course(Course* x){
    Course_List.insert(lower_bound(Course_List.begin(), Course_List.end(), x, Course::Crs_Cmp), x);
}

CourseManagement* CourseManagement::ReturnUniqueObject(){
    static CourseManagement x;
    return &x;
}