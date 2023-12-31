#include"StudentManagement.h"
#include<algorithm>

StudentManagement::StudentManagement(){

}

StudentManagement::~StudentManagement(){
    
}

vector<Student*> StudentManagement::getStudent_List(){
    return Student_List;
}

void StudentManagement::Add_Student(Student* x){
    Student_List.insert(lower_bound(Student_List.begin(), Student_List.end(), x, Student::Stu_Cmp), x);
}

StudentManagement* StudentManagement::ReturnUniqueObject(){
    static StudentManagement x;
    return &x;
}