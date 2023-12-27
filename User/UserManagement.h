#include"User.h"



class UserManagement{
    private:
        vector<User*> users;
    public:
        UserManagement();
        ~UserManagement();
        static UserManagement* ReturnUniqueObject();
        void Add_User(User*);
        void Register(int role);
        void Login();
        void Show_Users();
        
};
