#include <iostream>
#include <string>
#include <vector>
#include "identity.hpp"
#include "globalFile.h"
#include <fstream>
#include "student.hpp"
#include "teacher.hpp"
#include "manager.hpp"


void teacherMenu(Identity * &teacher)
{
    while (true)
    {
        teacher->operMenu();
        Teacher * tea = (Teacher *) teacher;
        
        int select = 0;
        std::cin >> select;
        
        if(select == 1)
        {
            tea->showAllOrder();
        }
        else if(select == 2)
        {
            tea->validOrder();
        }
        else
        {
            delete teacher;
            std::cout << "注销成功" << std::endl;
            return;
        }
    }
}

void studentMenu(Identity * &student)
{
    while (true) {
        student->operMenu();
        
        Student * stu = (Student *) student;
        
        int select = 0;
        std::cin >> select;
        
        if(select == 1)
        {
            stu->applyOrder();
        }
        else if(select == 2)
        {
            stu->showMyOrder();
        }
        else if(select == 3)
        {
            stu->showAllOrder();
        }
        else if(select == 4)
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            std::cout << "注销成功" << std::endl;
            return;
        }
    }
}

void managerMenu(Identity * &manager)
{
    while (true) {
        manager->operMenu();
        Manager * man = (Manager*)manager;
        
        int select = 0;
        
        std::cin >> select;
        
        if(select == 1)
        {
            man->addPerson();
        }
        
        else if(select == 2)
        {
            man->showPerson();
        }
        else if(select == 3)
        {
            man->showComputer();
        }
        else if(select == 4)
        {
            man->clearnFile();
        }
        
        else
        {
            delete manager;
            std::cout << "注销成功！" << std::endl;
            return;
        }
    }
}


void LoginIn(std::string fileName,int type)
{
    Identity * person = nullptr;
    
    std::ifstream ifs;
    ifs.open(fileName,std::ios::in);
    if(!ifs.is_open())
    {
        std::cout  << "文件不存在" << std::endl;
        ifs.close();
        return;
    }
    
    int id = 0;
    std::string name;
    std::string pwd;
    
    if(type == 1)
    {
        std::cout << "请输入你的学号：";
        std::cin >> id;
    }
    
    else if(type == 2)
    {
        std::cout << "请输入你的职工号：";
        std::cin >> id;
    }
    
    std::cout << "请输入用户名：" << std::endl;
    std::cin >> name;
    
    std::cout << "请输入密码：" << std::endl;
    std::cin >> pwd;
    
    if(type == 1)
    {
        int fId;
        std::string fName;
        std::string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && fName == name && fPwd == pwd)
            {
                std::cout << "student login successful!" << std::endl;
                std::cin.get();
                system("clear");
                person = new Student(id,name,pwd);
                studentMenu(person);
                return;
            }
        }
    }
    
    else if(type == 2)
    {
        int fId;
        std::string fName;
        std::string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && fName == name && fPwd == pwd)
            {
                std::cout << "teacher login successful!" << std::endl;
                std::cin.get();
                system("clear");
                person = new Teacher(id,name,pwd);
                teacherMenu(person);
                return;
            }
        }
    }
    else if(type == 3)
    {
        std::string fName;
        std::string fPwd;
        while(ifs >> fName && ifs >> fPwd)
        {
            if(fName == name && fPwd == pwd)
            {
                std::cout << "admin login successful!" << std::endl;
                person = new Manager(name,pwd);
                std::cout << person->m_Name ;
                managerMenu(person);
                return;
            }
        }
    }
    
    std::cout << "验证登陆失败！" << std::endl;
    std::cin.get();
    system("clear");
    return;
    
}


int main()
{
    int select = 0;
    int flagSysOut = 0;
    while(!flagSysOut)
    {
        std::cout << "===============机房预约系统==================" <<std::endl;
        std::cout << std::endl << "请输入您的身份：" << std::endl;
        std::cout << "\t\t----------------------------------\n";
        std::cout << "\t\t|                                 |\n";
        std::cout << "\t\t|         1.学生代表               |\n";
        std::cout << "\t\t|                                 |\n";
        std::cout << "\t\t|         2.老   师                |\n";
        std::cout << "\t\t|                                 |\n";
        std::cout << "\t\t|         3.管 理 员               |\n";
        std::cout << "\t\t|                                 |\n";
        std::cout << "\t\t|         0.退    出               |\n";
        std::cout << "\t\t|                                 |\n";
        std::cout << "\t\t|----------------------------------\n";
        std::cout << "输入您的选择：";
        std::cin >> select;
        switch (select) {
            case 1:
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:
                std::cout << "欢迎下次使用！"<<std::endl;
                flagSysOut = 1;
                break;
            default:
                std::cout << "输入有误，请输入任意键继续：" << std::endl;
                std::cin.get();
                system("clear");
                break;
        }
    }
    std::cin.get();
    return 0;
}
