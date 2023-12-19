#include"StudentManagement.h"

StudentManagement::StudentManagement(){

}

StudentManagement::~StudentManagement(){
    
}

void StudentManagement::Add_Student(Student* x){
    this->Student_List.push_back(x);
}

void StudentManagement::Display_Student(){
    Students_Display(this->Student_List);
}