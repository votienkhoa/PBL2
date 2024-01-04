#pragma once
#include"UserManagement.h"
#include"../Public/PublicFunction.h"

UserManagement::UserManagement(){

}
UserManagement::~UserManagement(){
}
//-----------------------------------------------------------
UserManagement* UserManagement::ReturnUniqueObject(){
    static UserManagement x;
    return &x;
}

vector<User*>& UserManagement::getUsers(){
    return users;
}
//---------------------------------------------------------------
void UserManagement::Add_User(User* x){
    users.push_back(x);
}

void UserManagement::Delete_User(User* x){
    
}
//---------------------------------------------------------------
void UserManagement::Register(int role){
    if (role == 1)  cout << CYN << "Tao tai khoan Sinh Vien" << RESET << endl;
    else if (role == 2) cout << CYN << "Tao tai khoan Giao Vien" << RESET << endl;
    else cout << CYN << "Tao tai khoan Quan Tri Vien" << RESET << endl;
    //--------
    User* tmp;
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
        if (Name_check) break;
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
        else break;
    }
    system("cls");
    // Student* tmpstu = Stu_Create();
    // tmp->data = tmpstu;
    // users.push_back(tmp);

    if (role == 1){
        Student* tmpdata = Stu_Create();
        tmp = new NormalUser(a,b,tmpdata);
    }
    else if (role == 2){
        Teacher* tmpdata = Tch_Create();
        tmp = new TeacherUser(a,b,tmpdata);
    }
    else{
        Teacher* tmpdata = Tch_Create();
        tmp = new AdminUser(a,b,tmpdata);
    }
    users.push_back(tmp);
    cout << GRN << "Khoi tao tai khoan thanh cong!" << RESET << endl;

}
//-------------------------------------------------------------------------
void UserManagement::Login(){
    system("cls");
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
    else if (current_user->role == 2) cout << CYN << "Quyen tai khoan cua ban la Giao Vien" << RESET << endl;
    else cout << CYN << "Quyen tai khoan cua ban la Quan Tri Vien" << RESET << endl;
    system("pause");

    current_user->UserAction();
    // NormalUserAction(current_user);

}

//----------------------------------------------------------------------
void UserManagement::Show_Users(){
    for (auto x : this->users){ 
        cout << x->username << endl;
        cout << x->password << endl;
    }
}