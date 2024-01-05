#pragma once
#include"Result.h"
#include"../Teacher/Teacher.h"
#include"../Student/Student.h"
#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

class TeacherUser;

class Course{
    private:
        string Crs_ID;
        string Crs_Name;
        Teacher* Crs_Teacher;
        map<Student*, Result> Res_List;
    public:
        Course(string = "NULL", string = "NULL",Teacher* = nullptr);
        ~Course();
        string getName() const;
        string getID() const;
        string getTeacherName() const;
        string getTeacherID() const;
        map<Student*,Result> getResult() const; //lấy ra danh sách học sinh và điểm tương ứng
        int getNumber();
        double getTX(Student*); //trả về điểm Thường xuyên của học sinh được truyền vào
        double getGK(Student*); //trả về điểm Giữa Kì của học sinh được truyền vào
        double getCK(Student*);//trả về điểm Cuối kì của học sinh được truyền vào
        void setTX(Student*,double); //thiết lập điểm thường xuyên của học sinh được truyền vào
        void setGK(Student*,double);//thiết lập điểm giữa kì của học sinh được truyền vào
        void setCK(Student*,double);//thiết lập điểm cuối kì của học sinh được truyền vào
        void Add_Student(Student*); //thêm học sinh vào lớp HP này
        void Set_Result(Student*); //chỉnh sửa điểm của học sinh được truyền vào
        void Course_Info(); //in ra thông tin lớp HP
        void Show_Student(); //in ra danh sách tất cả học sinh và điểm của lớp HP này
        void Course_Delete(); //xóa lớp HP này trên toàn database
        static bool Crs_Cmp(const Course*, const Course*); //comparator để sắp xếp danh sách các lớp HP theo mã HP
        friend Student;
        friend TeacherUser;
        friend AdminUser;

};