#include"PublicFunction.h"

Student* Stu_Create(){
    string a,b,c1,d,e,f;
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
    cout << "Lop cua ban: "; cin >> f;
    Student* tmp = new Student(a,b,c2,d,e,f);

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
    cout << setw(25) << left << "Ten" ;
    cout << setw(15) << left << "MSSV" ;
    cout << setw(15) << left << "Gioi tinh"; 
    cout << setw(15) << left << "Ngay sinh" ;
    cout << setw(15) << left << "Lop";
    cout << setw(30) << left << "Dia chi" ;
    cout << endl;
    for (auto x : v){
        x->Stu_Display2();
    }
}
void Teachers_Display(const vector<Teacher*> &v){
    cout << setw(25) << left << "Ten" ;
    cout << setw(15) << left << "MSSV" ;
    cout << setw(15) << left << "Gioi tinh"; 
    cout << setw(15) << left << "Ngay sinh" ;
    cout << setw(30) << left << "Dia chi" ;
    cout << endl;
    for (auto x : v){
        x->Tch_Display2();
    }
}