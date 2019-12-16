//
//  manager.cpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include "manager.hpp"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <algorithm>


Manager::Manager()
{
    
}

Manager::Manager(std::string name,std::string Pwd)
{
    
    this->m_Name = name;
    this->m_Pwd = Pwd;
    
    std::ifstream ifs;
    ifs.open(COMPUTER_FILE,std::ios::in);
    
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
    {
        vCom.push_back(com);
    }
    
    ifs.close();
}

void Manager::operMenu()
{
    std::cout << "欢迎管理员：" << this->m_Name << "登陆！" <<std::endl;
    std::cout << "\t\t----------------------------------\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         1.添加账号               |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         2.查看账号                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         3.查看机房                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         4.清空预约                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         0.注销登录                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|----------------------------------\n";
    std::cout << "输入您的操作：" << std::endl;
}
void Manager::showAllOrder()
{
    
}

void printStudent(Student & s)
{
    std::cout << "学号： " << s.m_Id << " 姓名：" << s.m_Name << std::endl;
}

void printTeacher(Teacher & t)
{
    std::cout << "职工号： " << t.m_EmpId << " 姓名：" << t.m_Name << std::endl;
}

void Manager::showPerson()
{
    std::cout << "请选择查看的内容：" << std::endl;
    std::cout << "1.student" << std::endl;
    std::cout << "2.teacher" << std::endl;
    
    int select  = 0;
    std::cin >> select;
    this->initVector();
    if(select == 1)
    {
        std::cout << "all student information: " << std::endl;
        std::for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        std::cout << "all teacher information: " << std::endl;
        std::for_each(vTea.begin(), vTea.end(), printTeacher);
    }
}

void Manager::addPerson()
{
    this->initVector();
    std::cout << "请输入添加l账号的类型" << std::endl;
    std::cout << "1.student" << std::endl;
    std::cout << "2.teacher" << std::endl;
    
    std::string fileName;
    std::string tip;
    std::ofstream ofs;
    std::string errorTip;
    
    int select = 0;
    std::cin >> select;
    
    if(select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复";
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工号：";
        errorTip = "职工号重复";
    }
    
    ofs.open(fileName,std::ios::out|std::ios::app);
    
    int id;
    std::string name;
    std::string pwd;
    
    std::cout << tip << std::endl;
    std::cin >> id;
    
    while (true)
    {
        if(checkRepeat(id, select))
        {
            std::cout << errorTip << std::endl;
            std::cout << tip << std::endl;
            std::cin >> id;
        }
        else
        {
            break;
        }
    }
    
    std::cout << "请输入姓名：" << std::endl;
    std::cin >> name;
    
    std::cout << "请输入密码：" << std::endl;
    std::cin >> pwd;
    
    
    ofs << id << " " << name << " " << pwd << std::endl;
    std::cout << "添加成功" <<std::endl;
    
    system("clear");
    ofs.close();
    
}

void Manager::clearnFile()
{
    std::ofstream ofs(ORDER_FILE,std::ios::trunc);
    ofs.close();
    std::cout << "clear successful!" << std::endl;
}

void Manager::showComputer()
{
    std::cout << "机房信息如下：" << std::endl;
    
    for(std::vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
    {
        std::cout << "机房编号：" << it->m_ComId << " 计算机最大数量： " << it->m_MaxNum << std::endl;
    }
}

void Manager::initVector()
{
    vStu.clear();
    vTea.clear();
    std::ifstream ifs;
    ifs.open(STUDENT_FILE,std::ios::in);
    
    if(!ifs.is_open())
    {
        std::cout << "error" << std::endl;
        return;
    }
    
    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    
    ifs.close();
    
    ifs.open(TEACHER_FILE,std::ios::in);
    
    if(!ifs.is_open())
    {
        std::cout << "error" << std::endl;
        return;
    }
    
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    ifs.close();
    std::cout << vStu.size() << "-" << vTea.size() << std::endl;
}

bool Manager::checkRepeat(int id, int type)
{
    if(type == 1)
    {
        for(std::vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
        {
            if(id == it->m_Id)
            {
                return true;
            }
        }
    }
    else
    {
        for(std::vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
        {
            if(id == it->m_EmpId)
            {
                return true;
            }
        }
    }
    return false;
}
