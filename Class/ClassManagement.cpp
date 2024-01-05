#include"ClassManagement.h"
#include"../Teacher/Teacher.h"
#include<iomanip>

ClassManagement::~ClassManagement(){

}
ClassManagement::ClassManagement(){

}
//-----------------------------
vector<Class*>& ClassManagement::getClass_List(){
    return Class_List;
}

ClassManagement* ClassManagement::ReturnUniqueObject(){
    static ClassManagement x;
    return &x;
}

void ClassManagement::Add_Class(Class* x){
    Class_List.insert(lower_bound(Class_List.begin(), Class_List.end(), x, Class::Cls_Cmp), x);
}