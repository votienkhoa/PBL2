#include"User.h"
#include"UserManagement.h"
#include"conio.h"

class UserManagement;


AdminUser::AdminUser(string a, string b, Teacher* p)
    : User(a,b,3), data(p)
{
}
//------------------------------------------------------
void AdminUser::Action_to_Stu(NormalUser* x){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem cac lop hoc phan va ket qua hoc tap" << endl;
        cout << "4. Xem danh sach lop hien tai" << endl;
        cout << "5. Doi mat khau" << endl;
        cout << "6. Xoa tai khoan cua sinh vien nay" << endl;
        cout << "7. Tro ve" << endl;

        int choice; cin >> choice;
        system("cls");
        switch (choice)
        {
            case 1:
            {
                x->data->Stu_Display1();
                system("pause");
                break;
            }
            case 2:
            {
                x->data->Stu_Edit();
                break;
            }
            case 3:
            {
                x->data->Courses_Display();
                system("pause");
                break;
            }
            case 4:
            {
                x->data->Class_Students_List();
                system("pause");
                break;
            }
            case 5:
            {
                ChangePassword();
                break;
            }
            case 6:
            {
                cout << RED << "Ban co chac chan muon xoa sinh vien nay?" << RESET << endl;
                cout << RED << "Luu y: Sau khi xoa thi toan bo thong tin ve sinh vien nay se khong the khoi phuc!" << RESET << endl;
                cout << "1. Xoa sinh vien nay" << endl;
                cout << "2. Tro ve" << endl;
                char c = _getch();
                int choice = c - '0';
                if (choice == 1){
                    x->data->Stu_Delete();
                    return;
                }

                break;            
            }
            case 7:
            {
                Logout = true;
            }
            
            default:
                break;
        }

        if (Logout) break;
    }
}


void AdminUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Tao tai khoan moi" << endl;
        cout << "4. Tao them lop" << endl;
        cout << "5. Tao lop hoc phan" << endl;
        cout << "6. Xem cac danh sach" << endl;
        cout << "7. Doi mat khau" << endl;
        cout << "8. Dang xuat" << endl;

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
                while(1){
                    system("cls");
                    cout << "1. Tao tai khoan cho hoc sinh" << endl;
                    cout << "2. Tao tai khoan cho giao vien" << endl;
                    cout << "3. Tao tai khoan quan tri vien" << endl;
                    char c2 = _getch();
                    int choice = c2 - '0';
                    system("cls");
                    if (choice == 1) UserManagement::ReturnUniqueObject()->Register(1);
                    else if (choice == 2) UserManagement::ReturnUniqueObject()->Register(2);
                    else if (choice == 3) UserManagement::ReturnUniqueObject()->Register(3);
                    else if (c2 == 13) break;
                }
                break;
            }
            case 4:
            {
                Class_Create();
                break;
            }
            case 5:
            {
                Course_Create();
                break;
            }
            case 6:
            {
                while(1){
                    system("cls");
                    cout << "1. Xem danh sach sinh vien toan truong" << endl;
                    cout << "2. Xem danh sach giao vien toan truong" << endl;
                    cout << "3. Xem danh sach cac lop hoc" << endl;
                    cout << "4. Xem danh sach cac lop hoc phan" << endl;
                    char c2 = _getch();
                    int choice = c2 - '0';
                    system("cls");
                    if (choice == 1){
                        while(1){
                            Student* tmp = Student_Select(StudentManagement::ReturnUniqueObject()->getStudent_List());
                            if (tmp) Action_to_Stu(tmp->getAccount());
                            else break;
                        }
                    }
                    else if (choice == 2) Teachers_Display(TeacherManagement::ReturnUniqueObject()->getTeacher_List()); 
                    else if (choice == 3) ClassManagement::ReturnUniqueObject()->Classes_Display(); 
                    else if (choice == 4) CourseManagement::ReturnUniqueObject()->Courses_Display(); 
                    else if (c2 == 13) break;
                }
                break;
            }
            case 7:
            {
                ChangePassword();
                break;
            }
            case 8:
            {
                Logout = true;
            }
            
            default:
                break;
        }

        if (Logout) break;
    }
}