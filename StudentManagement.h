#include"Student.h"


using namespace std;

class StudentManagement{
    private:
        vector<Student*> Student_List;
    public:
        StudentManagement();
        ~StudentManagement();
        void Add_Student(Student*);
        void Display_Student();
        static StudentManagement* ReturnUniqueObject();
};