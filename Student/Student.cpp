#include"Student.h"
#include"../Course/Course.h"
#include"../Public/PublicFunction.h"
#include"../User/UserManagement.h"
using namespace std;


void Student::Birthday_Conv(){
    string res;
    string s = this->Stu_BD;
    for(int i = 0; i<8; i++){
        if ((i == 0 || i == 2) && s[i] == '0') continue;
        else res.push_back(s[i]);
        if (i == 1 || i==3) res.push_back('/');
    }
    this->Stu_BD = res;
}

Student::Student(string a, string b, bool c, string d, string e, Class* f )
 : Stu_Name(a), Stu_ID(b), Stu_Sex(c), Stu_BD(d), Stu_Address(e), Stu_Class(f)
{
    StudentManagement::ReturnUniqueObject()->Add_Student(this);
}
Student::Student(string id)
    : Stu_ID(id)
{}
Student::~Student(){

}

//----------------------------------------------------
string Student::getName() const{
    return Stu_Name;
}
string Student::getID() const{
    return Stu_ID;
}
bool Student::getSex() const{
    return Stu_Sex;
}
string Student::getBD() const{
    return Stu_BD;
}
string Student::getAddress() const{
    return Stu_Address;
}
Class* Student::getClass() const{
    return Stu_Class;
}
NormalUser* Student::getAccount(){
    return Stu_Account;
}

void Student::setClass(Class* x){
    Stu_Class = x;
}

void Student::setAccount(NormalUser* x){
    Stu_Account = x;
}

void Student::Stu_Display1(){
    cout << "1.Ho va ten: " << Stu_Name << endl;
    cout << "2.MSSV: " << Stu_ID << endl;
    //--------------------------------
    cout << "3.Ngay sinh: " << Stu_BD << endl;
    //-----------------------------
    cout << "4.Gioi tinh: ";
    cout <<(Stu_Sex ? "Nam" : "Nu") << endl;
    //-------------------------------
    cout << "5.Dia chi: " << Stu_Address << endl;
    //------------------------------
    cout << "6.Lop: " << (Stu_Class ? (Stu_Class->getName()) : "Chua co lop") << endl;
}

void Student::Stu_Display2(){
    cout << setw(25) << left << Stu_Name;
    cout << setw(15) << left << Stu_ID ;
    cout << setw(15) << left << (Stu_Sex ? "Nam" : "Nu");
    cout << setw(15) << left << Stu_BD ;
    cout << setw(15) << left << (Stu_Class ? (Stu_Class->getName()) : "Chua co lop");
    cout << setw(30) << left << Stu_Address;
    cout << endl;
}

void Student::Courses_Display(){
    cout << setw(15) << left << "Ma HP";
    cout << setw(35) << left << "Ten lop hoc phan";
    cout << setw(10) << left << "Diem TX";
    cout << setw(10) << left << "Diem GK";
    cout << setw(10) << left << "Diem CK";
    cout << endl;
    for (auto x : Stu_Courses){
        cout << setw(15) << left << x->getID();
        cout << setw(35) << left << x->getName();
        cout << setw(10) << left << x->getTX(this);
        cout << setw(10) << left << x->getGK(this);
        cout << setw(10) << left << x->getCK(this);
        cout << endl;
    }
}

void Student::Class_Students_List(){
    if (Stu_Class) Stu_Class->Show_Student();
    else cout << RED << "Hoc sinh nay hien chua co lop!" << RESET << endl;
}

void Student::Stu_Edit(){
    while(1){
        system("cls");
        cout << "Hay kiem tra va chon thong tin can sua!" << endl;
        Stu_Display1();
        cout << "7.Xac nhan va tro ve" << endl;
        cout << "Lua chon: ";
        char c = _getch(); 
        int choice = c - '0';
        system("cls");
        bool breaker = false;
        
        switch(choice){
            case 1:
            {
                cout << "Ho va ten cu: " << this->Stu_Name << endl;
                cout << "Ho va ten moi: ";
                fflush(stdin);
                string s; getline(cin, s);
                this->Stu_Name = s;
                break;
            }
            case 2:
            {
                cout << RED << "Thong tin nay khong the chinh sua!" << RESET << endl;
                getch();
                break;
            }
            case 3:
            {
                cout << "Ngay sinh cu: " << this->Stu_BD << endl;
                cout << "Ngay sinh moi (hay nhap duoi dang ddmmyyyy): ";
                string s; getline(cin, s);
                this->Stu_BD = s;
                Birthday_Conv();
                break;
            }
            case 4:
            {
                while(1){
                    cout << "Gioi tinh cu: " << (Stu_Sex ? "Nam" : "Nu") << endl;
                    cout << "1.Nu" << endl << "2.Nam" << endl;
                    cout << "Gioi tinh moi: ";
                    string b; cin >> b;
                    if (b != "1" && b!="2"){
                        system("cls");
                        cout << RED << "Nhap sai! Vui long nhap lai!" << RESET << endl;
                        continue;
                    }
                    Stu_Sex = abs(stoi(b)-1);
                    break;
                }
                break;
            }
            case 5:
            {
                cout << "Dia chi cu: " << this->Stu_Address << endl;
                cout << "Dia chi moi: ";
                fflush(stdin);
                string s; getline(cin, s);
                this->Stu_Address = s;
                break;
            }
            case 6:
            {
                cout << RED << "Thong tin nay khong the chinh sua!" << RESET << endl;
                getch();
                break;
            }
            case 7:
            {
                breaker = true;
                break;
            }
        }
        if (breaker) break;

    }
}


bool Student::Stu_Cmp(const Student* a, const Student* b){
    return a->Stu_ID < b->Stu_ID;
}

void Student::Stu_Delete(){
    //xoa trong ds lop
    auto clsptr = &this->Stu_Class->Cls_List;
    clsptr->erase(lower_bound(clsptr->begin(), clsptr->end(),this, Student::Stu_Cmp));
    
    //xoa trong stumng
    auto mnptr = &StudentManagement::ReturnUniqueObject()->Student_List;
    mnptr->erase(lower_bound(mnptr->begin(), mnptr->end(),this, Student::Stu_Cmp));

    // xoa user
    auto usptr = UserManagement::ReturnUniqueObject();

    int rm_index, cur_index = 0;
    User* rm_us; 
    for (auto x : usptr->getUsers()){
        if (NormalUser* tmp = dynamic_cast<NormalUser*>(x)){
            if(tmp->getData() == this){
                rm_index = cur_index;
                rm_us = tmp;
                break;
            }
        }
        cur_index++;
    }
    // cout << rm_index << " " << usptr->getUsers().size() << endl;
    usptr->getUsers().erase(usptr->getUsers().begin() + rm_index);
    delete rm_us;


    //xoa trong lop hp
    for (auto x : Stu_Courses){
        x->Res_List.erase(this);
    }


}




