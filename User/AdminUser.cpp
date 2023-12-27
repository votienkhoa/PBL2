#include"User.h"
#include"UserManagement.h"
#include"conio.h"

class UserManagement;


AdminUser::AdminUser(string a, string b, Teacher* p)
    : User(a,b,3), data(p)
{
}

void AdminUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Tao tai khoan cho hoc sinh" << endl;
        cout << "4. Tao tai khoan cho giao vien" << endl;
        cout << "5. Tao tai khoan quan tri vien" << endl;
        cout << "6. Tao them lop" << endl;
        cout << "7. Xem danh sach sinh vien toan truong" << endl;
        cout << "8. Xem danh sach giao vien toan truong" << endl;
        cout << "9. Doi mat khau" << endl;
        cout << "10. Dang xuat" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
            case 1:
            {
                this->data->Tch_Display();
                system("pause");
                break;
            }
            case 2:
            {
                this->data->Tch_Edit();
                break;
            }
            case 3:
            {  
                UserManagement::ReturnUniqueObject()->Register(1);
                break;
            }
            case 4:
            {
                UserManagement::ReturnUniqueObject()->Register(2);
                break;
            }
            case 5:
            {
                UserManagement::ReturnUniqueObject()->Register(3);
                break;
            }
            case 6:
            {
                cout << "Chua code xong dung co bam vo nua" << endl;
                system("pause");
                break;
            }
            case 7:
            {
                Students_Display(StudentManagement::ReturnUniqueObject()->getStudent_List());
                system("pause");
                break;
            }
            case 8:
            {
                
                Teachers_Display(TeacherManagement::ReturnUniqueObject()->getTeacher_List());
                system("pause");
                break;
            }
            case 9:
            {
                ChangePassword();
                break;
            }
            case 10:
            {
                Logout = true;
            }
            
            default:
                break;
        }

        if (Logout) break;
    }
}