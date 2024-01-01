#include"PublicFunction.h"

Student* Stu_Create(){
    string a,b,c1,d,e;
    bool c2;
    cout << "Hay nhap thong tin ca nhan!" << endl;
    cout << "Ho va ten: "; 
    fflush(stdin);  getline(cin, a);
    cout << "MSSV: "; cin >> b;
    cout << "Gioi tinh: " << endl;
    cout << "1.Nu" << endl << "2.Nam" << endl;
    cout << "Lua chon cua ban: "; cin >> c1;
    c2 = stoi(c1) - 1;
    cout << "Ngay sinh: "; cin >> d;
    cout << "Dia chi: "; 
    fflush(stdin); getline(cin, e);
    system("cls");
    cout << "Hay chon lop cua ban: "; cout << endl;
    Class* f = Class_Select();
    Student* tmp = new Student(a,b,c2,d,e,f);
    f->Add_Student(tmp);

    tmp->Stu_Edit();

    StudentManagement::ReturnUniqueObject()->Add_Student(tmp);

    //----------------
    return tmp;

    
}

Teacher* Tch_Create(){
    string a,b,c1,d,e;
    bool c2;
    cout << "Hay nhap thong tin ca nhan cua giao vien!" << endl;
    cout << "Ho va ten: "; 
    fflush(stdin);  getline(cin, a);
    cout << "MSGV: "; cin >> b;
    cout << "Gioi tinh: " << endl;
    cout << "1.Nu" << endl << "2.Nam" << endl;
    cout << "Lua chon cua ban: "; cin >> c1;
    c2 = stoi(c1) - 1;
    cout << "Ngay sinh: "; cin >> d;
    cout << "Dia chi: "; 
    fflush(stdin); getline(cin, e);
    Teacher* tmp = new Teacher(a,b,c2,d,e);

    tmp->Tch_Edit();

    TeacherManagement::ReturnUniqueObject()->Add_Teacher(tmp);

    //----------------
    return tmp;
}

void Students_Display(const vector<Student*> &v){
    system("cls");
    cout << setw(8) << left << "STT";
    cout << setw(25) << left << "Ten" ;
    cout << setw(15) << left << "MSSV" ;
    cout << setw(15) << left << "Gioi tinh"; 
    cout << setw(15) << left << "Ngay sinh" ;
    cout << setw(15) << left << "Lop";
    cout << setw(30) << left << "Dia chi" ;
    cout << endl;
    int i = 1;
    for (auto x : v){
        cout << setw(8) << left << i; i++;
        x->Stu_Display2();
    }
}
void Teachers_Display(const vector<Teacher*> &v){
    system("cls");
    cout << setw(8) << left << "STT";
    cout << setw(25) << left << "Ten" ;
    cout << setw(15) << left << "MSSV" ;
    cout << setw(15) << left << "Gioi tinh"; 
    cout << setw(15) << left << "Ngay sinh" ;
    cout << setw(30) << left << "Dia chi" ;
    cout << setw(15) << left << "Lop chu nhiem";
    cout << endl;
    int i = 1;
    for (auto x : v){
        cout << setw(8) << left << i; i++;
        x->Tch_Display2();
    }
}
Student* Student_Select(const vector<Student*> &v){
    int wrin = 0;
    int choice;
    string schoice;
    while(1){
        Students_Display(v);

        cout << endl;
        if (wrin == 1) cout << RED << "Lua chon khong hop le, vui long nhap lai!" <<  RESET << endl;
        cout << "Hay nhap STT de thao tac voi sinh vien: ";
        fflush(stdin);
        getline(cin, schoice);
        if (schoice == "") return nullptr;
        else choice = stoi(schoice);

        if (choice < 1 || choice > v.size()) wrin = 1;
        else return v[choice-1];
    }
}

Teacher* Teacher_Select(const vector<Teacher*> &v, bool status){
    int wrin = 0;
    string schoice;
    int choice;
    while(1){
        Teachers_Display(v);

        cout << endl;
        if (wrin == 1) cout << RED << "Lua chon khong hop le, vui long nhap lai!" <<  RESET << endl;
        else if (wrin == 2) cout << RED << "Giao vien nay da co lop chu nhiem, vui long chon giao vien khac!" << RESET << endl;
        cout << "Hay nhap STT de chon giao vien: "; 
        fflush(stdin);
        getline(cin, schoice);
        if (schoice == "") return nullptr;
        else choice = stoi(schoice);

        if (choice < 1 || choice > v.size()) wrin = 1;
        else if (v[choice-1]->getClass() != nullptr && status) wrin = 2;
        else return v[choice-1];
    }
    

}

Class* Class_Select(){
    int wrin = 0;
    int choice;
    while(1){
        ClassManagement* x =ClassManagement::ReturnUniqueObject();
        x->Classes_Display();

        cout << endl;
        if (wrin == 1) cout << RED << "Lua chon khong hop le, vui long nhap lai!" <<  RESET << endl;
        cout << "Hay nhap lua chon cua ban: "; cin >> choice;

        if (choice < 1 || choice > x->getClass_List().size()) wrin = 1;
        else return x->getClass_List()[choice-1];
    }
}

void Class_Create(){
    string a; 
    cout << "Hay nhap ten lop hoc: "; cin >> a;
    system("cls");
    cout << "Chon giao vien chu nhiem "; cout << endl;
    Teacher* b = Teacher_Select(TeacherManagement::ReturnUniqueObject()->getTeacher_List(),1);
    
    Class* tmp = new Class(a,b);
    ClassManagement::ReturnUniqueObject()->Add_Class(tmp);

    system("cls");
    cout << GRN << "Tao lop thanh cong!" << RESET; getch();
}

void Course_Create(){
    string a;
    cout << "Hay nhap ten lop hoc phan: "; 
    fflush(stdin);
    getline(cin, a);
    system("cls");
    cout << "Chon giang vien cho lop hoc phan: "; cout << endl;
    Teacher* b = Teacher_Select(TeacherManagement::ReturnUniqueObject()->getTeacher_List(),0);

    Course* tmp = new Course(a,b);
    CourseManagement::ReturnUniqueObject()->Add_Course(tmp);

    system("cls");
    cout << GRN << "Tao lop thanh cong!" << RESET; getch();
}