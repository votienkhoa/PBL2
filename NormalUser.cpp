#include"User.h"

NormalUser::NormalUser(string a, string b, Student* p)
    : User(a,b,1), data(p)
{

}

void NormalUser::UserAction(){
    while(1){
        bool Logout = false;
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
                this->data->Stu_Display1();
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
                system("pause");
                break;
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
