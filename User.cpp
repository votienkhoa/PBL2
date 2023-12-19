#include"User.h"
using namespace std;

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET   "\033[0m"

User::User(string _username, string _password, int r)
    : username(_username), password(_password), role(r)
{ }

User::~User(){

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

void User::UserAction(){
    cout << "an cut" << endl;
}
//--------------------------------------

NormalUser::NormalUser(string a, string b, Student* p)
    : User(a,b,1), data(p)
{

}

void NormalUser::UserAction(){
    while(1){
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem cac lop hoc phan" << endl;
        cout << "4. Xem ket qua hoc tap" << endl;
        cout << "5. Doi mat khau" << endl;
        cout << "6. Dang xuat" << endl;

        int choice; cin >> choice;
        system("cls");
        switch (choice)
        {
            case 1:
            {
                this->data->Stu_Display();
                system("pause");
                break;
            }
            case 2:
            {
                this->data->Stu_Edit();
                break;
            }
            case 3:
            {
                cout << "Chua code xong dung co bam vo nua" << endl;
                break;
            }
            case 4:
            {
                cout << "Chua code xong dung co bam vo nua" << endl;
                break;
            }
            case 5:
            {
                ChangePassword();
                break;
            }
            
            default:
                break;
        }
    }
}

//-------------------------------------
AdminUser::AdminUser(string a, string b, Student* p) //thay bang Teacher
    : User(a,b,2), data(p)
{

}

void AdminUser::UserAction(){
    cout << "chua code xong" << endl;
}


//--------------------------------------
void Action(User* x){
    x->UserAction();
}