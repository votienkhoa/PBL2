class Student;
class Teacher;

class Class{
    private:
        string Cls_Name;
        Teacher* Cls_Teacher;
        vector<Student*> Cls_List;
    public:
        Class(string = "NULL", Teacher* = nullptr);
        ~Class();
        vector<Student*> getCls_List();
        void Add_Student(Student*);
};
