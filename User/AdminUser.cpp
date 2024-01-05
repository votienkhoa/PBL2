#include"User.h"
#include"UserManagement.h"
#include"conio.h"

class UserManagement;


AdminUser::AdminUser(string a, string b, Teacher* p)
    : User(a,b,3), data(p)
{
    p->setAccount(this);
    UserManagement::ReturnUniqueObject()->Add_User(this);
}
//-------------------------------------------------
Teacher* AdminUser::getData(){
    return data;
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
        cout << "6. Xem thong tin dang nhap cua tai khoan nay" << endl;
        cout << "7. Xoa tai khoan cua sinh vien nay" << endl;
        cout << "8. Tro ve" << endl;

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
                x->ChangePassword();
                break;
            }
            case 6:
            {
                cout << "Ten dang nhap: " << x->getUsername() << endl;
                cout << "Mat khau: " << x->getPassword() << endl;
                getch();
                break;
            }
            case 7:
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


void AdminUser::Action_to_Teacher(TeacherUser* x){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem danh sach lop hoc phan dang dam nhiem" << endl;
        cout << "4. Xoa giao vien nay" << endl;
        cout << "5. Xem thong tin dang nhap cua tai khoan nay" << endl;
        cout << "6. Doi mat khau" << endl;
        cout << "7. Tro ve" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
            case 1:
            {
                x->data->Tch_Display1();
                system("pause");
                break;
            }
            case 2:
            {
                x->data->Tch_Edit();
                break;
            }
            case 3:
            {
                x->data->Courses_Show();
                system("pause");
                break;
            }
            case 4:
            {
                cout << RED << "Ban co chac chan muon xoa giao vien nay?" << RESET << endl;
                cout << RED << "Luu y: Khi xoa giao vien nay thi toan bo thong tin ve lop hoc phan va lop chu nhiem do giao vien nay dam nhiem se bi xoa" << RESET << endl;
                cout << "1. Xoa giao vien nay" << endl;
                cout << "2. Tro ve" << endl;
                char c = _getch();
                int choice = c - '0';
                if (choice == 1){
                    x->data->Tch_Delete();
                    return;
                }
                return;
            }
            case 5:
            {
                cout << "Ten dang nhap: " << x->getUsername() << endl;
                cout << "Mat khau: " << x->getPassword() << endl;
                getch();
                break;
            }
            case 6:
            {
                x->ChangePassword();
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

void AdminUser::Action_to_Admin(AdminUser* x){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Xem danh sach lop hoc phan dang dam nhiem" << endl;
        cout << "4. Xoa giao vien nay" << endl;
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
                data->Courses_Show();
                system("pause");
                break;
            }
            case 4:
            {
                cout << RED << "Giao vien nay la quan tri vien, khong the xoa!"; cout << endl;
                cout << "Luu y: Neu muon xoa, hay truy cap vao danh sach quan tri vien!" << RESET << endl;
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

void AdminUser::Action_to_Course(Course* x){
    while (1)
    {
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin lop hoc phan" << endl;
        cout << "2. Chinh sua ten lop hoc phan" << endl;
        cout << "3. Xem danh sach sinh vien lop nay" << endl;
        cout << "4. Xoa lop hoc phan nay" << endl;
        cout << "5. Thoat" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
            case 1:
            {
                x->Course_Info();
                getch();
                break;
            }
            case 2:
            {
                cout << "chua code";
                break;
            }
            case 3:
            {
                x->Show_Student();
                getch();
                break;
            }
            case 4:
            {
                x->Course_Delete();
                return;
            }
            case 5:
            {
                Logout = true;
            }
        }

        if (Logout) break;
    }
    
}
//-----------------------------------------------
void AdminUser::Action_to_Stu1(Student* x, Course* y){
    while(1){
        bool exit = 0;
        system("cls");
        cout << "1. Xem thong tin sinh vien nay" << endl;
        cout << "2. Chinh sua diem cua sinh vien nay" << endl;
        cout << "3. Xoa sinh vien nay khoi lop hoc phan nay" << endl;
        cout << "4. Tro ve" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
        case 1:
        {
            x->Stu_Display1();
            getch();
            break;
        }
        case 2:
        {
            y->Set_Result(x);
            break;
        }
        case 3:
        {
            cout << RED << "Ban co chac chan muon xoa sinh vien nay ra khoi lop hoc phan?" << RESET << endl;
            cout << RED << "Luu y: Khi xoa sinh vien nay thi toan bo ket qua cua sinh vien nay se bi xoa!" << RESET << endl;
            cout << "1. Xoa sinh vien nay" << endl;
            cout << "2. Tro ve" << endl;
            char c = _getch();
            int choice = c - '0';
            if (choice == 1){
                y->Res_List.erase(x);
                return;
            }
            break;
        }
        case 4: exit = 1;
        }
        if (exit) break;
    }
}
//-----------------------------------------------
void AdminUser::Action_to_Course1(Course* x){
    if (x->Res_List.size() == 0){
        system("cls");
        cout << RED << "Lop hoc phan nay chua co sinh vien!" << RESET << endl;
        getch();
        return;
    }
    bool wrin = 0;
    string schoice;
    int choice;
    while(1){
        system("cls");
        x->Show_Student();

        cout << endl;
        if (wrin == 1) cout << RED << "Lua chon khong hop le, vui long nhap lai!" <<  RESET << endl;
        cout << "Hay nhap STT de thao tac voi sinh vien: ";
        fflush(stdin);
        getline(cin, schoice);
        if (schoice == "") return;
        else choice = stoi(schoice);

        if (choice < 1 || choice > x->getNumber()) wrin = 1;
        else{
            int i = 1;
            for (auto z : x->Res_List){
                if (i == choice){
                    Action_to_Stu1(z.first, x);
                    break;
                }
                i++;
            }
        }
    }
}
//-----------------------------------------------
void AdminUser::Action_to_Course2(Course* x){
    while(1){
        Student* tmp = Student_Select(StudentManagement::ReturnUniqueObject()->getStudent_List());
        if (tmp == nullptr) return;

        bool breaker = 1;
        for (auto z : x->Res_List){
            if (z.first == tmp){
                system("cls");
                cout << RED << "Sinh vien nay da ton tai trong lop hoc phan" << RESET << endl;
                breaker = 0;
                getch();
                break;
            }
        }
        if (breaker){
            x->Add_Student(tmp);
            break;
        }
    }
}
//----------------------------------------------

void AdminUser::Action_to_Class(Class* x){
    while (1)
    {
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin lop sinh hoat" << endl;
        cout << "2. Chinh sua ten lop sinh hoat" << endl;
        cout << "3. Xem danh sach sinh vien lop nay" << endl;
        cout << "4. Xoa lop sinh hoat nay" << endl;
        cout << "5. Thoat" << endl;

        char c = _getch();
        int choice = c - '0';
        system("cls");
        switch (choice)
        {
            case 1:
            {
                x->Class_Info();
                getch();
                break;
            }
            case 2:
            {
                cout << "chua code";
                getch();
                break;
            }
            case 3:
            {
                x->Show_Student();
                getch();
                break;
            }
            case 4:
            {
                x->Cls_Delete();
                return;
            }
            case 5:
            {
                Logout = true;
            }
        }

        if (Logout) break;
    }
}
//------------------------------------------------------------------------



void AdminUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Tao tai khoan moi" << endl;
        cout << "4. Tao lop sinh hoat" << endl;
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
                    cout << "5. Xem danh sach sinh vien cua lop chu nhiem" << endl;
                    cout << "6. Xem danh sach cac lop hoc phan dang dam nhiem" << endl;
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
                    else if (choice == 2){
                        while(1){
                            Teacher* tmp = Teacher_Select(TeacherManagement::ReturnUniqueObject()->getTeacher_List(),0);
                            if (tmp == nullptr) break;
                            else if (tmp->getRealAccount() == 1) Action_to_Teacher(tmp->getAccount1());
                            else Action_to_Admin(tmp->getAccount2());
                        }
                    }
                    else if (choice == 3){
                        while(1){
                            Class* tmp = Class_Select();
                            if (tmp == nullptr) break;
                            else Action_to_Class(tmp);
                        }
                    }
                    else if (choice == 4){
                        while(1){
                            Course* tmp =Course_Select(CourseManagement::ReturnUniqueObject()->getCourse_List());
                            if (tmp) Action_to_Course(tmp);
                            else break;
                        }
                    }
                    else if (choice == 5){
                        cout << "chua code";
                        getch();
                    }
                    else if (choice == 6){
                        if (data->Tch_Courses.size() == 0){
                            cout << RED << "Giao vien nay chua dam nhiem lop hoc phan nao" << RESET << endl;
                            getch();
                            break;
                        }
                        while(1){
                            system("cls");
                            Course* tmp = Course_Select(data->Tch_Courses);
                            if (tmp){
                                while(1){
                                    system("cls");
                                    cout << "1. Them sinh vien vao lop" << endl;
                                    cout << "2. Xem sinh vien cua lop " << endl;
                                    cout << "3. Tro ve" << endl;
                                    char c = _getch();

                                    system("cls");
                                    if (c == '1') Action_to_Course2(tmp);
                                    else if (c == '2') Action_to_Course1(tmp);
                                    else if (c == '3') break;
                                }
                            }
                            else break;
                        }
                
                break;
                    }
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