#include"UserManagement.h"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET   "\033[0m"

UserManagement::UserManagement(){

}
UserManagement::~UserManagement(){
    cout << "HuyUserMana" << endl;
}
void UserManagement::Add_User(User* x){
    users.push_back(x);
}

void UserManagement::Register(){
    NormalUser* tmp = new NormalUser;
    string a,b,c;
    while(1){
        cout << "Nhap ten nguoi dung cua ban: ";
        cin >> a;
        int Name_check = 1;
        for (auto x : users){
            if (x->username == a){
                Name_check = 0;
                break;
            }
        }
        if (Name_check){
            tmp->username = a;
            break;
        }
        else{
            system("cls");
            cout << RED <<"Ten nguoi dung da ton tai, vui long chon ten khac!" << RESET << endl;
        }
        //system.cls();
    }
    while(1){
        cout << "Nhap mat khau cua ban: ";
        cin >> b;
        cout << "Nhap lai mat khau cua ban: ";
        cin >> c;
        if (b!=c){
            system("cls");
            cout << RED << "Mat khau khong trung khop, vui long thu lai!" << RESET << endl;
            cout << "Ten nguoi dung: " << a << endl;
        } 
        else{
            tmp->password = b;
            break;
        }
    }
    system("cls");
    Student* tmpstu = Stu_Create();
    tmp->data = tmpstu;
    users.push_back(tmp);
    cout << GRN << "Khoi tao tai khoan thanh cong!" << RESET << endl;
}

void UserManagement::Login(){
    string a,b;
    User* current_user;
    int check;
    while(1){
        check = 0;
        cout << "Ten nguoi dung: "; cin >> a;
        cout << "Mat khau: "; cin >> b;

        for(auto x : users){
            if(x->Check_Login(a,b)){
                current_user = x;
                check = 1;
                break;
            } 
        }
        system("cls");
        if (!check) cout << RED << "Dang nhap that bai! Vui long kiem tra va thu lai!" << RESET << endl;
        else break; 
    }
    cout << GRN << "Dang nhap thanh cong" << RESET << endl;
    if (current_user->role == 1) cout << CYN << "Quyen tai khoan cua ban la Hoc Sinh" << RESET << endl;
    else cout << CYN << "Quyen tai khoan cua ban la Quan Tri Vien" << RESET << endl;
    system("pause");

    Action(current_user);
    // NormalUserAction(current_user);

}


void UserManagement::Show_Users(){
    for (auto x : this->users){ 
        cout << x->username << endl;
        cout << x->password << endl;
    }
}