#include"User.h"
#include"UserManagement.h"

TeacherUser::TeacherUser(string a, string b, Teacher* p) //thay bang Teacher
    : User(a,b,2), data(p)
{
    p->setAccount(this);
    UserManagement::ReturnUniqueObject()->Add_User(this);
}
//-----------------------------------------------------------
Teacher* TeacherUser::getData(){
    return data;
}
//-----------------------------------------------------------
void TeacherUser::Action_to_Stu(Student* x, Course* y){
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
                auto tmp = &x->Stu_Courses;
                tmp->erase(lower_bound(tmp->begin(),tmp->end(),y,Course::Crs_Cmp));
                return;
            }
            break;
        }
        case 4: exit = 1;
        }
        if (exit) break;
    }
}
//-----------------------------------------------------------
void TeacherUser::Action_to_Course1(Course* x){
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
                    Action_to_Stu(z.first, x);
                    break;
                }
                i++;
            }
        }
    }
}
//--------------------------------------------------------
void TeacherUser::Action_to_Course2(Course* x){
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
//-----------------------------------------------------------
void TeacherUser::Action_to_Class(Class* x){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin lop sinh hoat" << endl;
        cout << "2. Xem danh sach sinh vien cua lop" << endl;
        cout << "3. Them sinh vien vao lop" << endl;
        cout << "4. Xoa sinh vien khoi lop" << endl;
        cout << "5. Tro ve" << endl;

        char c = _getch();
        int choice = c-'0';
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
            Students_Display(x->getCls_List());
            getch();
            break;
        }
        case 3:
        {  
            while(1){
                system("cls");
                cout << CYN << "Hay chon sinh vien de them vao lop!" << RESET << endl;
                Student* tmp = Student_Select(StudentManagement::ReturnUniqueObject()->getStudent_List());
                if (tmp == nullptr) break;
                bool breaker = 1;
                //neu sinh vien da co lop
                if (tmp->getClass() != nullptr){
                    system("cls");
                    cout << RED << "Sinh vien da co lop! Vui long chon lai!" << RESET << endl;
                    getch();
                    continue;
                }
                x->Add_Student(tmp);
                system("cls");
                cout << GRN << "Them sinh vien thanh cong!" << RESET << endl;
                getch();
                break;
            }
            break;
        }
        case 4:
        {
            auto v = x->getCls_List();
            Student* tmp = Student_Select(x->getCls_List());
            if (tmp == nullptr) break;

            while(1){
                system("cls");
                cout << RED << "Ban co chac chan muon xoa sinh vien nay khoi lop?" << RESET << endl;
                cout << "1.Xoa sinh vien nay" << endl;
                cout << "2.Tro ve" << endl;
                char c = _getch();
                if (c!='1' && c!='2') continue;
                else{
                    if (c=='1'){
                        x->getCls_List().erase(lower_bound(x->getCls_List().begin(), x->getCls_List().end(),tmp,Student::Stu_Cmp));
                        // tmp->Stu_Courses.erase(lower_bound(tmp->Stu_Courses.begin(),tmp->Stu_Courses.end(),x))
                        cout << GRN << "Da xoa sinh vien thanh cong!" << RESET << endl;
                        getch();
                        break;
                    }
                    else break;
                }
            }
            break;
        }
        case 5:
        {
            Logout = true;
            break;
        }
        
        }
        if (Logout) break;
    }
}
//-----------------------------------------------------------
void TeacherUser::UserAction(){
    while(1){
        bool Logout = false;
        system("cls");
        cout << "1. Xem thong tin ca nhan" << endl;
        cout << "2. Chinh sua thong tin ca nhan" << endl;
        cout << "3. Thao tac voi lop chu nhiem" << endl;
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
                if (data->Tch_Class) Action_to_Class(data->Tch_Class);
                else{
                    system("cls");
                    cout << RED << "Giang vien nay chua chu nhiem lop nao!" << RESET << endl;
                    getch();
                }
                break;
            }
            case 4:
            {   
                
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
                            cout << "2. Xem va thao tac voi sinh vien cua lop " << endl;
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
