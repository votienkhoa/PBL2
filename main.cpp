#include"User/UserManagement.h"
#include<iostream>
using namespace std;

int main(){
    StudentManagement* school = StudentManagement::ReturnUniqueObject();
    Student p1("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau", "22T_KHDL");
    school->Add_Student(&p1);
    Student p2("Tran Duc Huy", "102220023", 0, "05022004", "1 cho deo nao do o Le Loi", "22T_DT5");
    school->Add_Student(&p2);
    Student p3("Nguyen Huu Hung Dung", "696969696", 0, "22112004", "deo biet nha thang nay", "nghi hoc me r");
    school->Add_Student(&p3);
    Student p4("Nguyen Van Thuong", "987654321", 1, "deo biet lun", "sap tot nghiep me r");
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

    m->Add_User(us1);
    m->Add_User(us2);
    m->Add_User(us3);
    // m.Register();
    m->Login();

    


    system("pause");

    
}