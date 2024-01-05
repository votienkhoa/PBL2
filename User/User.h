#pragma once
// #include"UserManagement.h"
#include"../Student/StudentManagement.h"
#include"../Teacher/TeacherManagement.h"
#include"../Class/ClassManagement.h"
#include"../Course/CourseManagement.h"
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
        string getUsername() const;
        string getPassword() const;
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
        Student* getData();
        void UserAction();
        friend class AdminUser;
};

class TeacherUser : public User{
    private:
        Teacher* data; //se la class teacher
    public:
        TeacherUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        Teacher* getData();
        void UserAction();
        void Action_to_Course(Course*);
        void Action_to_Stu(Student*, Course*);
        friend class AdminUser;
};

class AdminUser : public User{ //Quan tri tat ca moi thu
    private:
        Teacher* data;
    public:
        AdminUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        Teacher* getData();
        void UserAction();
        void Action_to_Stu(NormalUser*);
        void Action_to_Teacher(TeacherUser*);
        void Action_to_Admin(AdminUser*);
        void Action_to_Course(Course*);
};
