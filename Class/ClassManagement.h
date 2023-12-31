#pragma once
#include"Class.h"

class Class;
class AdminUser;

class ClassManagement{
    private:
        vector<Class*> Class_List;
        ClassManagement();
    public:
        ~ClassManagement();
        vector<Class*>& getClass_List(); 
        void Classes_Display();
        void Add_Class(Class*);
        static ClassManagement* ReturnUniqueObject();
        friend Class;
        friend AdminUser;

};