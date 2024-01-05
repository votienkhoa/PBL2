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
        string getUsername() const; //trả về tên đăng nhập của user
        string getPassword() const; //trả về mật khẩu của user
        virtual void UserAction(); //hàm ảo để đa hình hàm gọi ra các thao tác của user
        bool Check_Login(string, string); //kiểm tra thông tin đăng nhập
        void ChangePassword(); //đổi mật khẩu
        friend class UserManagement;
};

class NormalUser : public User{
    private:
        Student* data;
    public:
        NormalUser(string = "NULL", string = "NULL", Student* = nullptr);
        Student* getData(); //trả về dữ liệu của người dùng học sinh
        void UserAction(); //các thao tác của người dùng học sinh
        friend class AdminUser;
};

class TeacherUser : public User{
    private:
        Teacher* data; 
    public:
        TeacherUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        Teacher* getData();
        void UserAction();
        void Action_to_Course1(Course*); //thao tác với các học sinh trong lớp hp
        void Action_to_Course2(Course*); //thao tác thêm hs mới vào lớp HP
        void Action_to_Stu(Student*, Course*); //thao tác với học sinh trong lớp HP
        void Action_to_Class(Class*); //thao tác với lớp CN
        friend class AdminUser;
};

class AdminUser : public User{ //Quan tri tat ca moi thu
    private:
        Teacher* data;
    public:
        AdminUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        Teacher* getData();
        void UserAction();
        void Action_to_Stu(NormalUser*); //thao tác với học sinh bất kì dưới quyền Admin
        void Action_to_Stu_inCourse(Student*, Course*); //thao tác với học sinh ở trong lớp hp đảm nhiệm dưới quyền Teacher
        void Action_to_Teacher(TeacherUser*); //thao tác với một giáo viên dưới quyền Admin
        void Action_to_Admin(AdminUser*); //thao tác với một Admin dưới quyền Admin
        void Action_to_Course(Course*); //thao tác với một lớp HP dưới quyền Admin
        void Action_to_Course1(Course*); //thao tac voi tu cach teacher
        void Action_to_Course2(Course*);  //thao tac voi tu cach teacher
        void Action_to_Class(Class*); //thao tác với lớp sinh hoạt bất kì dưới quyền admin
        void Action_to_Class1(Class*); //thao tac voi tu cach teacher
};
