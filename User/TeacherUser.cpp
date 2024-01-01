#include"User.h"

TeacherUser::TeacherUser(string a, string b, Teacher* p) //thay bang Teacher
    : User(a,b,2), data(p)
{
    p->setAccount(this);
}
//-----------------------------------------------------------
Teacher* TeacherUser::getData(){
    return data;
}
//-----------------------------------------------------------

void TeacherUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem danh sach sinh vien toan truong" << endl;
        cout << "4. Xem danh sach lop hoc phan dang dam nhiem" << endl;
        cout << "5. Doi mat khau" << endl;
        cout << "6. Dang xuat" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
            case 1:
            {
                this->data->Tch_Display1();
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
                Students_Display(StudentManagement::ReturnUniqueObject()->getStudent_List());
                system("pause");
                break;
            }
            case 4:
            {
                data->Courses_Display();
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
                Logout = true;
            }
            
            default:
                break;
        }

        if (Logout) break;
    }
}
