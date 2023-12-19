#include"StudentManagement.h"
#include"Teacher.h"
#include"ANSI.h"
// #include"StudentAction.cpp"
using namespace std;

class StudentManagement;
class UserManagement;

class User{
    private:
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

class AdminUser : public User{
    private:
        Teacher* data; //se la class teacher
    public:
        AdminUser(string = "NULL", string = "NULL", Teacher* = nullptr);
        void UserAction();
};

class TOAA : public User{ //Quan tri tat ca moi thu

};

void Action(User*);
