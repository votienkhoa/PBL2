#pragma once
// #include"UserManagement.h"
#include"../Student/StudentManagement.h"
#include"../Teacher/TeacherManagement.h"
#include"../Public/PublicFunction.h"
#include"../ANSI.h"
using namespace std;

// class StudentManagement;

class User{
    protected:
        string username;
        string password;
        int role;
    public:
        User(string = "NULL", string = "NULL", int = 1);
        ~User();
        virtual void UserAction();
        bool Check_Login(string, string);
        void ChangePassword();
        friend class UserManagement;
};

class NormalUser : public User{
    private:
        Student* data;
    public:
        NormalUser(string = "NULL", string = "NULL", Student* = nullptr);
        void UserAction();
        friend class UserManagement;
};

class TeacherUser : public User{
    private:
        Teacher* data; //se la class teacher
    public:
        TeacherUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        void TeacherReg();
        void UserAction();
};

class AdminUser : public User{ //Quan tri tat ca moi thu
    private:
        Teacher* data;
    public:
        AdminUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        void TeacherReg();
        void UserAction();
};
