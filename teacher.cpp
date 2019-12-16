//
//  teacher.cpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include "teacher.hpp"


Teacher::Teacher()
{
    
}

Teacher::Teacher(int empId,std::string name,std::string Pwd)
{
    this->m_Pwd = Pwd;
    this->m_EmpId = empId;
    this->m_Name = name;
}

void Teacher::validOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        std::cout << "无预约记录" << std::endl;
        return;
    }
    
    std::cout << "审核中或预约成功的记录可以取消！"  << std::endl;
    
    int index = 1;
    std::vector<int> v;
    for (int i = 0; i < of.m_Size; i++)
    {
            if(of.m_orderData[i]["status"] == "1")
            {
                v.push_back(i);
                std::cout << index++ << "、";
                std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
                std::cout << " 时间段："  << (of.m_orderData[i]["interval"] == "1"?"上午":"下午");
                std::cout << " 学号："  << of.m_orderData[i]["stuId"];
                std::cout << " 姓名："  << of.m_orderData[i]["stuName"];
                std::cout << " 机房号："  << of.m_orderData[i]["roomId"];
                std::string status = " 状态: ";
                status += "审核中";
                std::cout << status << std::endl;
             }

    }
    std::cout << "请输入审核的记录，0代表返回" << std::endl;
    int select = 0;
    int ret = 0;
    while (true)
    {
        std::cin >> select;
        
        if(select >= 0 && select <= v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                std::cout << "输入审核结果：" << std::endl;
                std::cout << "1、通过" << std::endl;
                std::cout << "2、不通过" << std::endl;
                std::cin >> ret;
                if(ret == 1)
                    of.m_orderData[v[select-1]]["status"] = "2";
                else
                    of.m_orderData[v[select-1]]["status"] = "-1";
                of.updateOrder();
                std::cout << "审核成功" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "重新输入" << std::endl;
        }
    }
}

void Teacher::operMenu()
{
    std::cout << "欢迎教师：" << this->m_Name << "登陆！" <<std::endl;
    std::cout << "\t\t----------------------------------\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         1.查看所有预约            |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         2.审核预约                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         0.注销登录                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|----------------------------------\n";
    std::cout << "输入您的操作：" << std::endl;
}

void Teacher::showAllOrder()
{
    OrderFile of;
       if(of.m_Size == 0)
       {
           std::cout << "无预约记录" << std::endl;
           return;
       }
       
       for(int i = 0; i < of.m_Size; i++)
       {
           std::cout << i + 1 << " 、";
           std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
                      std::cout << " 时间段："  << (of.m_orderData[i]["interval"] == "1"?"上午":"下午");
                      std::cout << " 学号："  << of.m_orderData[i]["stuId"];
                      std::cout << " 姓名："  << of.m_orderData[i]["stuName"];
                      std::cout << " 机房号："  << of.m_orderData[i]["roomId"];
                      std::string status = " 状态: ";
                      if(of.m_orderData[i]["status"] == "1")
                      {
                          status += "审核中";
                      }
                      else if(of.m_orderData[i]["status"] == "2")
                      {
                          status += "预约成功";
                      }
                      else if(of.m_orderData[i]["status"] == "-1")
                      {
                          status += "预约失败";
                      }
                      else
                      {
                          status += "预约已取消";
                      }
                      std::cout << status << std::endl;
           
       }
       

       
}




