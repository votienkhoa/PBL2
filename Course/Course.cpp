#include"Course.h"

Course::Course(string a, string b, Teacher* c)
    : Crs_ID(a), Crs_Name(b), Crs_Teacher(c)
{
    c->Tch_Courses.insert(lower_bound(c->Tch_Courses.begin(), c->Tch_Courses.end(), this, Crs_Cmp), this);
    CourseManagement::ReturnUniqueObject()->Add_Course(this);
}
Course::~Course(){

}
//----------------------------
string Course::getName(){
    return Crs_Name;
}
string Course::getID(){
    return Crs_ID;
}
string Course::getTeacherName(){
    return Crs_Teacher->getName();
}
int Course::getNumber(){
    return Res_List.size();
}

double Course::getTX(Student* x){
    return Res_List[x].TX;
}

double Course::getGK(Student* x){
    return Res_List[x].GK;
}

double Course::getCK(Student* x){
    return Res_List[x].CK;
}
void Course::setTX(Student* x, double a){
    Res_List[x].TX = a;
}
void Course::setGK(Student* x, double a){
    Res_List[x].GK = a;
}
void Course::setCK(Student* x, double a){
    Res_List[x].CK = a;
}
//----------------------------
void Course::Add_Student(Student* x){
    Result tmp;
    Res_List[x] = tmp;
    x->Stu_Courses.insert(lower_bound(x->Stu_Courses.begin(),  x->Stu_Courses.end(), this, Crs_Cmp), this);
}

void Course::Set_Result(Student* x){
    system("cls");
    
    while(1){
        system("cls");
        bool breaker = false;
        cout << "Hay chon cot diem muon nhap hoac sua!" << endl;
        cout << "1.Diem thuong xuyen" << endl;
        cout << "2.Diem giua ki" << endl;
        cout << "3.Diem cuoi ki" << endl;
        cout << "4.Thoat" << endl;
        char c = _getch();
        int choice = c - '0';

        system("cls");
        switch (choice)
        {
            case 1:
            {
                cout << "Diem thuong xuyen hien tai: " << Res_List[x].TX << endl;
                cout << "Diem thuong xuyen moi: ";
                double tmp; cin >> tmp;

                Res_List[x].TX = tmp;
                break;
            }
            case 2:
            {
                cout << "Diem giua ki hien tai: " << Res_List[x].GK << endl;
                cout << "Diem giua ki moi: ";
                double tmp; cin >> tmp;

                Res_List[x].GK = tmp;
                break;
            }
            case 3:
            {
                cout << "Diem cuoi ki hien tai: " << Res_List[x].CK << endl;
                cout << "Diem cuoi ki moi: ";
                double tmp; cin >> tmp;

                Res_List[x].CK = tmp;
                break;
            }
            case 4:
            {
                breaker = true;
                break;
            }
            
            default:
                break;
        }
        if (breaker) break;
    }
    
}

void Course::Show_Student(){
    int i = 1;
    cout << setw(8) << left << "STT";
    cout << setw(25) << left << "Ten hoc sinh";
    cout << setw(10) << left << "Diem TX";
    cout << setw(10) << left << "Diem GK";
    cout << setw(10) << left << "Diem CK";
    cout << endl << endl;
    for (auto x : Res_List){
        cout << setw(8) << left << i; i++;
        cout << setw(25) << left << x.first->getName();
        cout << setw(10) << left << x.second.TX;
        cout << setw(10) << left << x.second.GK;
        cout << setw(10) << left << x.second.CK;
        cout << endl;
    }
}

void Course::Course_Info(){
    cout << "1.Ten lop hoc phan: " << Crs_Name << endl;
    cout << "2.Ma HP: " << Crs_ID << endl;
    cout << "3.Giang vien: " << Crs_Teacher->getName() << endl;
    cout << "4.Si so: " << Res_List.size();
}
//-----------------------------------------------
bool Course::Crs_Cmp(const Course* a, const Course* b){
    return a->Crs_ID < b->Crs_ID;
}

void Course::Course_Delete(){
    auto crsptr = &CourseManagement::ReturnUniqueObject()->Course_List;
    crsptr->erase(lower_bound(crsptr->begin(), crsptr->end(), this, Crs_Cmp));

    for (auto x : Res_List){
        auto tmp = &x.first->Stu_Courses;
        tmp->erase(lower_bound(tmp->begin(), tmp->end(), this, Crs_Cmp));
    }

    auto tc = &Crs_Teacher->Tch_Courses;

    tc->erase(lower_bound(tc->begin(), tc->end(),this,Course::Crs_Cmp));
}