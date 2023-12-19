#pragma once
// #include"StudentManagement.h"
#include"UserManagement.h"
// #include"UserManagement.cpp"
#include<iostream>
using namespace std;

int main(){
    // StudentManagement school;
    // Student p1("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau", "22T_KHDL");
    // school.Add_Student(&p1);
    // Student p2("Tran Duc Huy", "102220023", 0, "05022004", "1 cho deo nao do o Le Loi", "22T_DT5");
    // school.Add_Student(&p2);
    // Student p3("Nguyen Huu Hung Dung", "102220000", 0, "22112004", "deo biet nha thang nay", "nghi hoc me r");
    // school.Add_Student(&p3);


    UserManagement m;
    Student* tmp = new Student("Vo Tien Khoa", "102220028", 1, "24052004", "K76/5F Thanh Son, Hai Chau", "22T_KHDL");
    NormalUser* us = new NormalUser("khoa", "khoa", tmp);

    m.Add_User(us);
    // m.Register();
    m.Login();

    system("pause");

    
}