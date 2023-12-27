#include"Class.h"
#include<vector>
using namespace std;

class ClassManagement{
    private:
        vector<Class*> Class_List;
    public:
        void Classes_Display();
        void Add_Class(Class*);
        void Delete_Class(Class*);

        


};