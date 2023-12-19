#include"User.h"

AdminUser::AdminUser(string a, string b, Teacher* p) //thay bang Teacher
    : User(a,b,2), data(p)
{

}

void AdminUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem danh sach sinh vien toan truong" << endl;
        cout << "4. Xem ket qua hoc tap" << endl;
        cout << "5. Doi mat khau" << endl;
        cout << "6. Dang xuat" << endl;

        int choice; cin >> choice;
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
                StudentManagement* tmp = StudentManagement::ReturnUniqueObject();
                tmp->Display_Student();
            }
            case 4:
            {
                cout << "Chua code xong dung co bam vo nua" << endl;
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
