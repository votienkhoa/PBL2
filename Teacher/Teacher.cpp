#include"Teacher.h"
#include"../Class/Class.h"
#include"../Course/Course.h"
#include"../User/User.h"
void Teacher::Birthday_Conv(){
    string res;
    string s = Tch_BD;
    for(int i = 0; i<8; i++){
        if ((i == 0 || i == 2) && s[i] == '0') continue;
        else res.push_back(s[i]);
        if (i == 1 || i==3) res.push_back('/');
    }
    Tch_BD= res;
}

Teacher::Teacher(string a, string b, bool c, string d, string e, Class* f)
    : Tch_Name(a), Tch_ID(b), Tch_Sex(c), Tch_BD(d), Tch_Address(e), Tch_Class(f)
{
    Birthday_Conv();
}

Teacher::~Teacher(){

}
//------------------------------------------------
string Teacher::getName(){
    return Tch_Name;
}

Class* Teacher::getClass(){
    return Tch_Class;
}

TeacherUser* Teacher::getAccount1(){
    return Tch_Account1;
}

AdminUser* Teacher::getAccount2(){
    return Tch_Account2;
}

int Teacher::getRealAccount(){
    if (Tch_Account1 == nullptr) return 2;
    else return 1;
}

void Teacher::setClass(Class* x){
    Tch_Class = x;
}

void Teacher::setAccount(User* x){
    if (AdminUser* tmp = dynamic_cast<AdminUser*>(x)){
        Tch_Account2 = tmp;
    }
    else{
        Tch_Account1 = dynamic_cast<TeacherUser*>(x);
    }
}
//----------------------------------------------

void Teacher::Tch_Display1(){
    cout << "1.Ho va ten: " << Tch_Name << endl;
    cout << "2.MSSV: " << Tch_ID << endl;
    //--------------------------------
    cout << "3.Ngay sinh: " << Tch_BD << endl;
    //-----------------------------
    cout << "4.Gioi tinh: ";
    cout <<(Tch_Sex ? "Nam" : "Nu") << endl;
    //-------------------------------
    cout << "5.Dia chi: " << Tch_Address << endl;
    //------------------------------
    // cout << "6.Lop chu nhiem: " << Tch_Class->getName() << endl;
}
void Teacher::Tch_Display2(){
    cout << setw(25) << left << Tch_Name;
    cout << setw(15) << left << Tch_ID ;
    cout << setw(15) << left << (Tch_Sex ? "Nam" : "Nu");
    cout << setw(15) << left << Tch_BD;
    cout << setw(30) << left << Tch_Address ;
    cout << setw(15) << left << (Tch_Class == nullptr ? "Chua co lop" : Tch_Class->getName());
    cout << endl;
}

void Teacher::Courses_Display(){
    for (auto x : Tch_Courses){
        cout << x->getName() << endl;
    }
}

void Teacher::Tch_Edit(){
    while(1){
        system("cls");
        cout << "Hay kiem tra va chon thong tin can sua!" << endl;
        Tch_Display1();
        cout << "6.Tro ve" << endl;
        cout << "Lua chon: ";   char c = _getch();
        fflush(stdin);
        system("cls");
        bool breaker = false;
        
        int choice = c - '0';
        switch(choice){
            case 1:
            {
                cout << "Ho va ten cu: " << this->Tch_Name << endl;
                cout << "Ho va ten moi: ";
                string s; getline(cin, s);
                this->Tch_Name = s;
                break;
            }
            case 2:
            {
                cout << "MSSV cu: " << this->Tch_ID << endl;
                cout << "MSSV moi: ";
                string s; getline(cin, s);
                this->Tch_ID = s;
                break;
            }
            case 3:
            {
                cout << "Ngay sinh cu: " << this->Tch_BD << endl;
                cout << "Ngay sinh moi (hay nhap duoi dang ddmmyyyy): ";
                string s; getline(cin, s);
                this->Tch_BD = s;
                Birthday_Conv();
                break;
            }
            case 4:
            {
                cout << "Gioi tinh cu: " << (this->Tch_Sex ? "Nam" : "Nu") << endl;
                cout << "1.Nu" << endl << "2.Nam" << endl;
                cout << "Gioi tinh moi: ";
                int b; cin >> b;
                this->Tch_Sex = abs(b-1);
                break;
            }
            case 5:
            {
                cout << "Dia chi cu: " << this->Tch_Address << endl;
                cout << "Dia chi moi: ";
                string s; getline(cin, s);
                this->Tch_Address = s;
                break;
            }
            case 6:
            {
                breaker = true;
                break;
            }
        }
        if (breaker) break;

    }
}
//-------------------------------------

