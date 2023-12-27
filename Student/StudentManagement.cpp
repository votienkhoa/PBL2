#include"StudentManagement.h"

StudentManagement::StudentManagement(){

}

StudentManagement::~StudentManagement(){
    
}

vector<Student*> StudentManagement::getStudent_List(){
    return Student_List;
}

void StudentManagement::Add_Student(Student* x){
    this->Student_List.push_back(x);
}

StudentManagement* StudentManagement::ReturnUniqueObject(){
    static StudentManagement x;
    return &x;
}