#include"User/UserManagement.h"
#include"Public/PublicFunction.h"
#include<iostream>
using namespace std;

int main(){
    StudentManagement* school = StudentManagement::ReturnUniqueObject();
    Student p1("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau");
    school->Add_Student(&p1);
    Student p2("Tran Duc Huy", "102220023", 0, "05022004", "1 cho deo nao do o Le Loi");
    school->Add_Student(&p2);
    Student p3("Nguyen Huu Hung Dung", "696969696", 0, "22112004", "deo biet nha thang nay");
    school->Add_Student(&p3);
    Student p4("Nguyen Van Thuong", "987654321", 1, "deo biet lun", "deo biet not");
    school->Add_Student(&p4);

    


    UserManagement* m = UserManagement::ReturnUniqueObject();
    // Student* tmp = new Student("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau", "22T_KHDL");
    NormalUser* us1 = new NormalUser("khoa", "khoa", &p1);

    Teacher* tmp2 = new Teacher("Nguyen Tan Khoi", "000000000", 1, "11111111", "uewqio");
    TeacherUser* us2 = new TeacherUser("khoi", "1", tmp2);

    TeacherManagement* tc = TeacherManagement::ReturnUniqueObject();
    tc->Add_Teacher(tmp2);

    Teacher* tmp3 = new Teacher("TOAA", "00000000000", 1, "10101999", "ko co nha");
    AdminUser* us3 = new AdminUser("admin", "admin", tmp3);

    Teacher* tmp4 = new Teacher("Dang Hoai Phuong", "111111111", 0, "31231231", "duahiedfa");
    TeacherUser* us4 = new TeacherUser("phuong", "1", tmp4);
    tc->Add_Teacher(tmp4);
    tc->Add_Teacher(tmp3);

    m->Add_User(us1);
    m->Add_User(us2);
    m->Add_User(us3);
    
    Class* tmpcls1 = new Class("22T_KHDL", tmp2);
    ClassManagement::ReturnUniqueObject()->Add_Class(tmpcls1);
    tmpcls1->Add_Student(&p1);
    tmpcls1->Add_Student(&p3);
    tmpcls1->Add_Student(&p4);
    Class* tmpcls2 = new Class("22T_DT5", tmp3);
    tmpcls2->Add_Student(&p2);
    ClassManagement::ReturnUniqueObject()->Add_Class(tmpcls2);


    CourseManagement* crsmn = CourseManagement::ReturnUniqueObject();
    Course crs1("Lap trinh huong doi tuong", tmp4);
    crsmn->Add_Course(&crs1);
    crs1.Add_Student(&p1);
    crs1.Add_Student(&p2);
    Course crs2("PLB1: Du an lap trinh tinh toan", tmp2);
    crsmn->Add_Course(&crs2);
    crs2.Add_Student(&p1);
    crs2.Add_Student(&p3);
    crs2.Add_Student(&p4);
    Course crs3("An ninh mang", tmp2);
    crsmn->Add_Course(&crs3);
    crs3.Add_Student(&p1);
    // crs1.Set_Result(&p1);
    // crs1.Show_Student();
    while(1){
        system("cls");
        cout << "1.Dang nhap" << endl;
        cout << "2.Thoat chuong trinh" << endl;
        char c = getch();
        int choice = c - '0';
        if (choice == 1) m->Login();
        else break;
    }

    // cout << p1.getAccount()->getData()->getName() << endl;
    // crs1.Set_Result(&p1);

    // tmp2->Tch_Delete();
    





    system("pause");

    
}