#include"Teacher.h"
#include"../Class/Class.h"
#include"../Course/Course.h"
// #include"../Teacher/TeacherManagement.h"
#include"../User/UserManagement.h"
#include"../Public/PublicFunction.h"
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
    TeacherManagement::ReturnUniqueObject()->Add_Teacher(this);
}
Teacher::Teacher(string id)
    : Tch_ID(id)
{}

Teacher::~Teacher(){

}
//------------------------------------------------
string Teacher::getName() const{
    return Tch_Name;
}
string Teacher::getID() const{
    return Tch_ID;
}
bool Teacher::getSex() const{
    return Tch_Sex;
}
string Teacher::getBD() const{
    return Tch_BD;
}
string Teacher::getAddress() const{
    return Tch_Address;
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
    cout << "2.MSGV: " << Tch_ID << endl;
    //--------------------------------
    cout << "3.Ngay sinh: " << Tch_BD << endl;
    //-----------------------------
    cout << "4.Gioi tinh: ";
    cout <<(Tch_Sex ? "Nam" : "Nu") << endl;
    //-------------------------------
    cout << "5.Dia chi: " << Tch_Address << endl;
    //------------------------------
    cout << "6.Lop chu nhiem: " << (Tch_Class == nullptr ? "Chua co lop" : Tch_Class->getName()) << endl;
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

void Teacher::Courses_Show(){
    Courses_Display(Tch_Courses);
}

void Teacher::Tch_Edit(){
    while(1){
        system("cls");
        cout << "Hay kiem tra va chon thong tin can sua!" << endl;
        Tch_Display1();
        cout << "7.Tro ve" << endl;
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
                fflush(stdin);
                string s; getline(cin, s);
                this->Tch_Name = s;
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
                cout << "Ngay sinh cu: " << this->Tch_BD << endl;
                cout << "Ngay sinh moi (hay nhap duoi dang ddmmyyyy): ";
                string s; getline(cin, s);
                this->Tch_BD = s;
                Birthday_Conv();
                break;
            }
            case 4:
            {
                while(1){
                    cout << "Gioi tinh cu: " << (this->Tch_Sex ? "Nam" : "Nu") << endl;
                    cout << "1.Nu" << endl << "2.Nam" << endl;
                    cout << "Gioi tinh moi: ";
                    string b; cin >> b;
                    if (b != "1" && b!="2"){
                        system("cls");
                        cout << RED << "Nhap sai! Vui long nhap lai!" << RESET << endl;
                        continue;
                    }
                    this->Tch_Sex = abs(stoi(b)-1);
                    break;
                }
                break;
            }
            case 5:
            {
                cout << "Dia chi cu: " << this->Tch_Address << endl;
                cout << "Dia chi moi: ";
                fflush(stdin);
                string s; getline(cin, s);
                this->Tch_Address = s;
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
//-------------------------------------
bool Teacher::Tch_Cmp(const Teacher* a, const Teacher* b){
    return a->Tch_ID < b->Tch_ID;
}

void Teacher::Tch_Delete(){
    //xoa trong mana
    auto mnptr = &TeacherManagement::ReturnUniqueObject()->Teacher_List;
    mnptr->erase(lower_bound(mnptr->begin(), mnptr->end(), this, Tch_Cmp));

    //xoa trong user
    int current_index = 0, rm_index;

    auto usptr = UserManagement::ReturnUniqueObject();
    for (auto x : usptr->getUsers()){
        if (TeacherUser* tmp = dynamic_cast<TeacherUser*>(x)){
            if (tmp->getData() == this){
                rm_index = current_index;
                break;
            }
        }
        else if (AdminUser* tmp = dynamic_cast<AdminUser*>(x)){
            if (tmp->getData() == this){
                rm_index = current_index;
                break;
            }
        }
        current_index++;
    }
    usptr->getUsers().erase(usptr->getUsers().begin() + rm_index);

    if (Tch_Account1) delete Tch_Account1;
    else delete Tch_Account2;


    //xoa lop
    if (Tch_Class) Tch_Class->Cls_Delete();
    // delete Tch_Class;

    //xoa loi hoc phan
    for (auto x : Tch_Courses){
        x->Course_Delete();
    }

}


