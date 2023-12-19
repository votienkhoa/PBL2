#include"UserManagement.h"
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

    UserManagement m;
    Student* tmp = new Student("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau", "22T_KHDL");
    NormalUser* us1 = new NormalUser("khoa", "khoa", tmp);

    Teacher* tmp2 = new Teacher("Nguyen Tan Khoi", "000000000", 1, "11111111", "uewqio");
    AdminUser* us2 = new AdminUser("khoi", "1", tmp2);

    m.Add_User(us1);
    m.Add_User(us2);
    // m.Register();
    m.Login();

    


    system("pause");

    
}