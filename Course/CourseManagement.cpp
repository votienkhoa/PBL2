#include"CourseManagement.h"

CourseManagement::CourseManagement(){

}

CourseManagement::~CourseManagement(){

}
//-------------------------------------
void CourseManagement::Add_Course(Course* x){
    Course_List.push_back(x);
}

void CourseManagement::Courses_Display(){
    cout << setw(35) << left << "Ten lop hoc phan";
    cout << setw(25) << left << "Giang vien";
    cout << endl;
    for (auto x : Course_List){
        cout << setw(35) << left << x->getName();
        cout << setw(25) << left << x->getTeacherName();
        cout << endl;
    }
    getch();
}

CourseManagement* CourseManagement::ReturnUniqueObject(){
    static CourseManagement x;
    return &x;
}