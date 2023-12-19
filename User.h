#include"Student.h"
// #include"StudentAction.cpp"
using namespace std;

class UserFunction;
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
        friend class UserFunction;
};

class AdminUser : public User{
    private:
        Student* data; //se la class teacher
    public:
        AdminUser(string = "NULL", string = "NULL", Student* = nullptr);
        void UserAction();
};

void Action(User*);
