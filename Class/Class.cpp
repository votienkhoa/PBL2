#include"Class.h"
#include"../Student/Student.h"
#include"../Teacher/Teacher.h"
#include"../Public/PublicFunction.h"

Class::Class(string a, Teacher* b)
    : Cls_Name(a), Cls_Teacher(b)
{
    b->setClass(this);
}

Class::~Class(){

}
//-------------------------------
vector<Student*> Class::getCls_List(){
    return Cls_List;
}

string Class::getName(){
    return Cls_Name;
}
//-------------------------------
void Class::Add_Student(Student* x){
    Cls_List.insert(lower_bound(Cls_List.begin(), Cls_List.end(), x, Student::Stu_Cmp), x);
    x->setClass(this);
}


void Class::Show_Student(){
    Students_Display(Cls_List);
}

