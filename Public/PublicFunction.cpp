#include"PublicFunction.h"
#include "../User/UserManagement.h"


Student* Stu_Create(){
    string a,b,c1,d,e;
    bool c2;
    cout << "Hay nhap thong tin ca nhan!" << endl;
    //nhap ten------------------
    cout << "Ho va ten: "; 
    fflush(stdin);  getline(cin, a);
    //nhap mssv-----------------
    while(1){
        cout << "MSSV: "; cin >> b;

        bool ID_Check = 0;
        auto v = StudentManagement::ReturnUniqueObject()->getStudent_List();
        for (auto x : v){
            if (x->getID() == b){
                ID_Check = 1;
                break;
            }
        }
        if (!ID_Check){
            system("cls");
            cout << "Hay nhap thong tin ca nhan!" << endl;
            cout << "Ho va ten: " << a << endl;
            cout << "MSSV: " << b << endl;
            break;
        }
        else{
            system("cls");
            cout << "Hay nhap thong tin ca nhan!" << endl;
            cout << "Ho va ten: "; cout << a << endl;
            cout << RED << "MSSV nay da ton tai! Vui long chon MSSV khac!" << RESET << endl;
        }
    }
    //nhap gt-----------------
    cout << "Gioi tinh: " << endl;
    cout << "1.Nu" << endl << "2.Nam" << endl;
    while(1){
        cout << "Lua chon cua ban: "; cin >> c1;
        if (c1 != "1" && c1!="2"){
            system("cls");
            cout << "Hay nhap thong tin ca nhan!" << endl;
            cout << "Ho va ten: " << a << endl;
            cout << "MSSV: " << b << endl;
            cout << "Gioi tinh: " << endl;
            cout << "1.Nu" << endl << "2.Nam" << endl;
            cout << RED << "Nhap sai! Vui long nhap lai!" << RESET << endl;
        }
        else{
            system("cls");
            cout << "Hay nhap thong tin ca nhan!" << endl;
            cout << "Ho va ten: " << a << endl;
            cout << "MSSV: " << b << endl;
            cout << "Gioi tinh: " << endl;
            cout << "1.Nu" << endl << "2.Nam" << endl;
            cout << "Lua chon cua ban: "; cout << c1 << endl;
            break;
        }
    }
    c2 = stoi(c1) - 1;
    //nhap ngay sinh--------------
    cout << "Ngay sinh: "; cin >> d;
    cout << "Dia chi: "; 
    fflush(stdin); getline(cin, e);
    system("cls");
    cout << "Hay chon lop cua hoc sinh nay: "; cout << endl;
    Class* f = Class_Select();
    Student* tmp = new Student(a,"SV"+b,c2,d,e,f);
    f->Add_Student(tmp);

    tmp->Stu_Edit();

    // StudentManagement::ReturnUniqueObject()->Add_Student(tmp);

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
    Teacher* tmp = new Teacher(a,"GV"+b,c2,d,e);

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
//----------------------------------------------------------------
void Teachers_Display(const vector<Teacher*> &v){
    system("cls");
    cout << setw(8) << left << "STT";
    cout << setw(25) << left << "Ten" ;
    cout << setw(15) << left << "MSGV" ;
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
//----------------------------------------------------------------
void Courses_Display(const vector<Course*> &v){
    int i = 1;
    cout << setw(8) << left << "STT";
    cout << setw(15) << left << "Ma HP";
    cout << setw(35) << left << "Ten lop hoc phan";
    cout << setw(25) << left << "Giang vien";
    cout << setw(10) << left << "Si so";
    cout << endl << endl;
    for (auto x : v){
        cout << setw(8) << left << i; i++;
        cout << setw(15) << left << x->getID();
        cout << setw(35) << left << x->getName();
        cout << setw(25) << left << x->getTeacherName();
        cout << setw(10) << left << x->getNumber();
        cout << endl;
    }
}
//----------------------------------------------------------------

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

Course* Course_Select(const vector<Course*>& v){
    int wrin = 0;
    int choice;
    string schoice;
    while(1){
        Courses_Display(v);

        cout << endl;
        if (wrin == 1) cout << RED << "Lua chon khong hop le, vui long nhap lai!" <<  RESET << endl;
        cout << "Hay nhap STT de thao tac voi lop hoc phan: ";
        fflush(stdin);
        getline(cin, schoice);
        if (schoice == "") return nullptr;
        else choice = stoi(schoice);

        if (choice < 1 || choice > v.size()) wrin = 1;
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
    string ID;
    cout << "Hay nhap ma HP: "; cin >> ID;
    string a;
    cout << "Hay nhap ten lop hoc phan: "; 
    fflush(stdin);
    getline(cin, a);
    system("cls");
    cout << "Chon giang vien cho lop hoc phan: "; cout << endl;
    Teacher* b = Teacher_Select(TeacherManagement::ReturnUniqueObject()->getTeacher_List(),0);

    Course* tmp = new Course("HP"+ID,a,b);

    system("cls");
    cout << GRN << "Tao lop thanh cong!" << RESET; getch();
}
//--------------------------------------------------------------------
void loadStudent(){
    ifstream f("Database/Student.csv");

    string line;
    while(getline(f,line)){
        stringstream element(line);
        string a,b,c,d,e,f,g, temp_str;
        getline(element, temp_str, ',');
        a = temp_str;
        getline(element, temp_str, ',');
        b = temp_str;
        getline(element, temp_str, ',');
        c = temp_str;
        getline(element, temp_str, ',');
        d = temp_str;
        getline(element, temp_str, ',');
        e = temp_str;
        getline(element, temp_str, ',');
        f = temp_str;
        getline(element, temp_str, '\n');
        g = temp_str;

        int c1 = stoi(c);
        
        Student* tmp = new Student(a,b,c1,d,e);
        NormalUser* tmp2 = new NormalUser(f,g,tmp);
    }
}

void loadTeacher(){
    ifstream f("Database/Teacher.csv");

    string line;
    while(getline(f,line)){
        stringstream element(line);
        string a,b,c,d,e,f,g, temp_str;
        getline(element, temp_str, ',');
        a = temp_str;
        getline(element, temp_str, ',');
        b = temp_str;
        getline(element, temp_str, ',');
        c = temp_str;
        getline(element, temp_str, ',');
        d = temp_str;
        getline(element, temp_str, ',');
        e = temp_str;
        getline(element, temp_str, ',');
        f = temp_str;
        getline(element, temp_str, '\n');
        g = temp_str;

        int c1 = stoi(c);
        
        Teacher* tmp = new Teacher(a,b,c1,d,e);
        TeacherUser* tmp2 = new TeacherUser(f,g,tmp);
    }
}

void loadAdmin(){
    ifstream f("Database/Admin.csv");

    string line;
    while(getline(f,line)){
        stringstream element(line);
        string a,b,c,d,e,f,g, temp_str;
        getline(element, temp_str, ',');
        a = temp_str;
        getline(element, temp_str, ',');
        b = temp_str;
        getline(element, temp_str, ',');
        c = temp_str;
        getline(element, temp_str, ',');
        d = temp_str;
        getline(element, temp_str, ',');
        e = temp_str;
        getline(element, temp_str, ',');
        f = temp_str;
        getline(element, temp_str, '\n');
        g = temp_str;

        int c1 = stoi(c);
        
        Teacher* tmp = new Teacher(a,b,c1,d,e);
        AdminUser* tmp2 = new AdminUser(f,g,tmp);
    }
}


void loadClass(){
    ifstream f("Database/Class.csv");
    auto tcmng = TeacherManagement::ReturnUniqueObject()->getTeacher_List();
    auto stumng = StudentManagement::ReturnUniqueObject()->getStudent_List();

    int turn = 1;
    string line;
    string id, classname, teacher;
    while(getline(f,line)){
        stringstream token(line);
        if (turn){
            getline(token, classname, ',');
            getline(token, teacher, '\n');
            turn = 0;
            continue;
        }
        Teacher virtc(teacher);
        Teacher* tmptc = *(lower_bound(tcmng.begin(), tcmng.end(),&virtc, Teacher::Tch_Cmp));
        Class* tmp = new Class(classname, tmptc);
        while(getline(token,id,',')){
            Student virstu(id);
            Student* tmp2 = *(lower_bound(stumng.begin(), stumng.end(),&virstu, Student::Stu_Cmp));
            cout << tmp2->getName();
            tmp->Add_Student(tmp2);
        }
        turn = 1;
        cout <<1;
    }
    cout << 2;
}

void loadCourse(){
    ifstream f("Database/Course.csv");
    auto tcmng = TeacherManagement::ReturnUniqueObject()->getTeacher_List();
    auto stumng = StudentManagement::ReturnUniqueObject()->getStudent_List();   

    string line,crsid,crsname,teacher;
    string student,a,b,c;
    Course* current_crs;
    while(getline(f,line)){
        stringstream token(line);
        string stat;
        getline(token,stat,',');
        if (stat == "Course"){
            getline(token, crsid, ',');
            getline(token, crsname, ',');
            getline(token, teacher, '\n');
            Teacher virtc(teacher);
            Teacher* tmptc = *(lower_bound(tcmng.begin(), tcmng.end(),&virtc, Teacher::Tch_Cmp));
            
            current_crs = new Course(crsid,crsname,tmptc);
        }
        else{
            getline(token, student, ',');
            getline(token, a, ',');
            getline(token, b, ',');
            getline(token, c, ',');
            Student virstu(student);
            Student* tmpstu = *(lower_bound(stumng.begin(), stumng.end(),&virstu, Student::Stu_Cmp));

            current_crs->Add_Student(tmpstu);
            current_crs->setTX(tmpstu, stod(a));
            current_crs->setGK(tmpstu, stod(b));
            current_crs->setCK(tmpstu, stod(c));
        }
    }
}

