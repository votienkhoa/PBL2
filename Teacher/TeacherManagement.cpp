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
    Teacher_List.push_back(x);
}
//---------------------------------------
TeacherManagement* TeacherManagement::ReturnUniqueObject(){
    static TeacherManagement x;
    return &x;
}

