#include"User.h"
using namespace std;


class UserManagement{
    private:
        vector<User*> users;
    public:
        UserManagement();
        ~UserManagement();
        void Add_User(User*);
        void Register();
        void Login();
        void Show_Users();
        
};