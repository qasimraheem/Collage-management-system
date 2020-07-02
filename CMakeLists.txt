cmake_minimum_required(VERSION 3.15)
project(collage_manage_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(collage_manage_system main.cpp Student.cpp Student.h Teacher.cpp Teacher.h Subject.cpp Subject.h Semester.cpp Semester.h StudentList.cpp StudentList.h TeacherList.cpp TeacherList.h SubjectList.cpp SubjectList.h)