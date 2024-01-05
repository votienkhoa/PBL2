#pragma once
#include "../Class/ClassManagement.h"
#include "../Student/StudentManagement.h"
#include "../Teacher/TeacherManagement.h"
#include "../Course/CourseManagement.h"
#include "../ANSI.h"
#include<fstream>
#include<algorithm>

Student* Stu_Create();
Teacher* Tch_Create();
void Students_Display(const vector<Student*>&);
void Teachers_Display(const vector<Teacher*>&);
void Courses_Display(const vector<Course*>&);
void Classes_Display(const vector<Class*>&);
Student* Student_Select(const vector<Student*>&);
Teacher* Teacher_Select(const vector<Teacher*>&, bool status);
Course* Course_Select(const vector<Course*>&);
Class* Class_Select(const vector<Class*>&);
void Class_Create();
void Course_Create();
void loadStudent();
void loadTeacher();
void loadAdmin();
void loadClass();
void loadCourse();
void saveStudent();
void saveTeacher();
void saveAdmin();
void saveClass();
void saveCourse();
