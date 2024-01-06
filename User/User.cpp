#include"User.h"
using namespace std;


User::User(string _username, string _password, int r)
    : username(_username), password(_password), role(r)
{ }

User::~User(){

}
//--------------------------------
string User::getUsername() const{
    return username;
}
string User::getPassword() const{
    return password;
}

bool User::Check_Login(string username, string password){
    return (username == this->username && password == this->password);
}

void User::ChangePassword(){
    while (1){
        system("cls");
        cout << "Vui long nhap mat khau cu: ";
        string password;
        cin >> password;
        if (password != this->password){
            cout << RED << "Mat khau sai! Vui long thu lai" << RESET << endl;
            system("pause");
        }
        else{
            cout << "Nhap mat khau moi: ";
            cin >> password;
            string checkPassword;
            cout << "Nhap lai mat khau moi: ";
            cin >> checkPassword;
            if (password != checkPassword){
                cout << RED << "Mat khau khong trung khop! Vui long thu lai!" << RESET << endl;
                system("pause");
            }
            else{
                system("cls");
                this->password = password;
                cout << GRN << "Doi mat khau thanh cong.\n" << RESET;
                system("pause");
                return;
            }
        }
    }
}

void User::UserAction()
{
    
}

void Action(User* x){
    x->UserAction();
}
//--------------------------------------


//-------------------------------------


//--------------------------------------
