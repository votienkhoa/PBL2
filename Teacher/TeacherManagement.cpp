#include"TeacherManagement.h"

TeacherManagement::TeacherManagement(){

}
TeacherManagement::~TeacherManagement(){

}
//------------------------------------------
vector<Teacher*> TeacherManagement::getTeacher_List(){
    return Teacher_List;
}
//-------------------------------------------
void TeacherManagement::Add_Teacher(Teacher* x){
    Teacher_List.insert(lower_bound(Teacher_List.begin(), Teacher_List.end(), x, Teacher::Tch_Cmp), x);
}
//---------------------------------------
TeacherManagement* TeacherManagement::ReturnUniqueObject(){
    static TeacherManagement x;
    return &x;
}

