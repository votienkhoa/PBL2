#include"Class.h"
#include"Student.h"
#include"Teacher.h"

Class::Class(string a, Teacher* b)
    : Cls_Name(a), Cls_Teacher(b)
{
    
}

Class::~Class(){

}
//-------------------------------
void Class::Add_Student(Student* x){
    Cls_List.push_back(x);
}

vector<Student*> Class::getCls_List(){
    return Cls_List;
}

