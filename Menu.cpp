#include"Menu.h"

void ControlMenu(){
    loadStudent();
    loadTeacher();
    loadClass();
    loadCourse();
    loadAdmin();
    
    while(1){
        system("cls");
        cout << "1.Dang nhap" << endl;
        cout << "2.Thoat chuong trinh" << endl;
        char c = getch();
        int choice = c - '0';
        if (choice == 1) UserManagement::ReturnUniqueObject()->Login();
        else if (choice == 2){
            saveStudent();
            saveClass();
            saveTeacher();
            saveAdmin();
            saveCourse();
            break;
        }
        else continue;
    }
}