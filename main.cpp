#include"User/UserManagement.h"
#include"Public/PublicFunction.h"
#include<iostream>
using namespace std;

int main(){
    loadStudent();
    loadTeacher();
    loadClass();
    loadCourse();
    loadAdmin();
    
    while(1){
        system("cls");
        cout << "1.Dang nhap" << endl;
        cout << "2.Thoat chuong trinh" << endl;
        char c = getch();
        int choice = c - '0';
        if (choice == 1) UserManagement::ReturnUniqueObject()->Login();
        else break;
    }
}