#pragma once
#include "../Class/ClassManagement.h"
#include "../Student/StudentManagement.h"
#include "../Teacher/TeacherManagement.h"
#include "../Course/CourseManagement.h"
#include "../ANSI.h"

Student* Stu_Create();
Teacher* Tch_Create();
void Students_Display(const vector<Student*>&);
void Teachers_Display(const vector<Teacher*>&);
Student* Student_Select(const vector<Student*>&);
Teacher* Teacher_Select(const vector<Teacher*>&, bool status);
Class* Class_Select();
void Class_Create();
void Course_Create();
