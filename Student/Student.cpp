#include"Student.h"
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

Student::Student(string a, string b, bool c, string d, string e, string f )
 : Stu_Name(a), Stu_ID(b), Stu_Sex(c), Stu_BD(d), Stu_Address(e), Stu_Class(f)
{
    Birthday_Conv();
}
Student::~Student(){
    
}

//----------------------------------------------------
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
    cout << "6.Lop: " << Stu_Class << endl;
}

void Student::Stu_Display2(){
    cout << setw(25) << left << Stu_Name;
    cout << setw(15) << left << Stu_ID ;
    cout << setw(15) << left << (Stu_Sex ? "Nam" : "Nu");
    cout << setw(15) << left << Stu_BD ;
    cout << setw(15) << left << Stu_Class;
    cout << setw(30) << left << Stu_Address ;
    cout << endl;
}

void Student::Stu_Edit(){
    while(1){
        int choice;
        system("cls");
        cout << "Hay kiem tra va chon thong tin can sua!" << endl;
        Stu_Display1();
        cout << "7.Tro ve" << endl;
        cout << "Lua chon: "; cin >> choice;
        fflush(stdin);
        system("cls");
        bool breaker = false;
        
        switch(choice){
            case 1:
            {
                cout << "Ho va ten cu: " << this->Stu_Name << endl;
                cout << "Ho va ten moi: ";
                string s; getline(cin, s);
                this->Stu_Name = s;
                break;
            }
            case 2:
            {
                cout << "MSSV cu: " << this->Stu_ID << endl;
                cout << "MSSV moi: ";
                string s; getline(cin, s);
                this->Stu_ID = s;
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
                cout << "Gioi tinh cu: " << (this->Stu_Sex ? "Nam" : "Nu") << endl;
                cout << "1.Nu" << endl << "2.Nam" << endl;
                cout << "Gioi tinh moi: ";
                int b; cin >> b;
                this->Stu_Sex = abs(b-1);
                break;
            }
            case 5:
            {
                cout << "Dia chi cu: " << this->Stu_Address << endl;
                cout << "Dia chi moi: ";
                string s; getline(cin, s);
                this->Stu_Address = s;
                break;
            }
            case 6:
            {
                cout << "Lop cu: " << this->Stu_Class << endl;
                cout << "Lop moi: ";
                string s; getline(cin, s);
                this->Stu_Class = s;
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





