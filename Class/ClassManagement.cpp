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

void ClassManagement::Classes_Display(){
    cout << setw(8) << left << "STT";
    cout << setw(15) << left << "Ten lop" ;
    cout << setw(8) << left << "Si so";
    cout << setw(25) << left << "GVCN" ;
    cout << endl;
    int i = 1;
    for (auto x : Class_List){
        cout << setw(8) << left << i; i++;
        cout << setw(15) << left << x->Cls_Name;
        cout << setw(8) << left << x->Cls_List.size();
        cout << setw(25) << left << x->Cls_Teacher->getName();
        cout << endl;
    }
    getch();
}