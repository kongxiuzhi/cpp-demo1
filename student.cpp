//
//  student.cpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include "student.hpp"


Student::Student()
{
    
}

Student::Student(int id,std::string name,std::string Pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = Pwd;
    
    std::ifstream ifs;
    
    ifs.open(COMPUTER_FILE,std::ios::in);
    
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum )
    {
        vCom.push_back(com);
    }
    
    ifs.close();
    
}

void Student::operMenu()
{
    std::cout << "欢迎学生代表：" << this->m_Name << "登陆！" <<std::endl;
    std::cout << "\t\t----------------------------------\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         1.申请预约               |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         2.查看我的预约            |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         3.查看所有预约            |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         4.取消预约                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|         0.注销登录                |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|----------------------------------\n";
    std::cout << "输入您的操作：" << std::endl;
}

void Student::applyOrder()
{
    std::cout << "机房开放时间为周一至周五！" << std::endl;
    std::cout << "请输入申请预约的时间：" << std::endl;
    
    std::cout << "1,周一" << std::endl;
    std::cout << "2,周二" << std::endl;
    std::cout << "3,周三" << std::endl;
    std::cout << "4,周四" << std::endl;
    std::cout << "5,周五" << std::endl;
    
    int date = 0;
    int interval = 0;
    int room = 0;
    
    while (true)
    {
        std::cin >> date;
        if(date >= 1 && date <=5)
        {
            break;
        }
        else
        {
            std::cout << "输入有误，请重新输入" << std::endl;
        }
    }
    
    std::cout << "请输入预约的时间段：" << std::endl;
    std::cout << "1,上午" << std::endl;
    std::cout << "2,下午" << std::endl;
    
    while (true)
    {
        std::cin >> interval;
        if(interval >= 1 && interval <= 2)
        {
            break;
        }
        else
        {
            std::cout << "输入有误，请重新输入" << std::endl;
        }
    }
    
    std::cout << "请输入机房：" << std::endl;
    for(int i = 0;i < vCom.size(); i++)
    {
        std::cout << vCom[i].m_ComId << "号机房容量为： " << vCom[i].m_MaxNum << std::endl;
    }
    
    
     while (true)
     {
         std::cin >> room;
         if(room >= 1 && room <= 3)
         {
             break;
         }
         else
         {
             std::cout << "输入有误，请重新输入" << std::endl;
         }
     }
    
    std::cout << "预约成功！审核中" << std::endl;
    
    std::ofstream ofs;
    ofs.open(ORDER_FILE,std::ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << std::endl;
    
    ofs.close();
    
}

void Student::showMyOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        std::cout << "无记录" << std::endl;
        return;
    }
    std::cout << of.m_Size << std::endl;
    for(int i = 0; i < of.m_Size; i++)
    {
        std::cout << of.m_orderData[i]["stuId"] << std::endl;
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//c_str() string -> char *
        {
            std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
            std::cout << " 时间段："  << (of.m_orderData[i]["interval"] == "1"?"上午":"下午");
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
    
    
}

void Student::cancelOrder()
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
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
        {
            if(of.m_orderData[i]["status"] == "1" ||of.m_orderData[i]["status"] == "2")
            {
                v.push_back(i);
                std::cout << index++ << "、";
                std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
                           std::cout << " 时间段："  << (of.m_orderData[i]["interval"] == "1"?"上午":"下午");
                           std::cout << " 机房号："  << of.m_orderData[i]["roomId"];
                           std::string status = " 状态: ";
                           if(of.m_orderData[i]["status"] == "1")
                           {
                               status += "审核中";
                           }
                           else
                           {
                               status += "预约成功";
                           }
                           std::cout << status << std::endl;
            }

        }
    }
    
    std::cout << "请输入取消的记录，0代表返回" << std::endl;
    int select = 0;
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
                of.m_orderData[v[select-1]]["status"] = "0";
                of.updateOrder();
                std::cout << "取消成功" << std::endl;
                break;
            }
        }
    }
    
}


void Student::showAllOrder()
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




