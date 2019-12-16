//
//  orderFile.cpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/10.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#include "orderFile.hpp"

OrderFile::OrderFile()
{
    std::ifstream ifs;
    ifs.open(ORDER_FILE,std::ios::in);
    
    std::string date;
    std::string interval;
    std::string stuId;
    std::string stuName;
    std::string roomId;
    std::string status;
    
    this->m_Size = 0;
    
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs
           >> stuName && ifs >> roomId && ifs >> status)
    {
        std::string key;
        std::string value;
        
        std::map<std::string, std::string> m;
        int pos = (int)date.find(":");
        if(pos != -1)
        {
            key = date.substr(0,pos);
            value = date.substr(pos+1,date.size() - pos -1);
            
            m.insert(make_pair(key,value));
        }
        
        pos = (int)interval.find(":");
        if(pos != -1)
        {
            key = interval.substr(0,pos);
            value = interval.substr(pos+1,interval.size() - pos -1);
            
            m.insert(make_pair(key,value));
        }
        
        pos = (int)stuId.find(":");
        if(pos != -1)
        {
            key = stuId.substr(0,pos);
            value = stuId.substr(pos+1,stuId.size() - pos -1);
            
            m.insert(make_pair(key,value));
        }
        
        pos = (int)stuName.find(":");
        if(pos != -1)
        {
            key = stuName.substr(0,pos);
            value = stuName.substr(pos+1,stuName.size() - pos -1);
            
            m.insert(make_pair(key,value));
        }
        
        pos = (int)roomId.find(":");
        if(pos != -1)
        {
            key = roomId.substr(0,pos);
            value = roomId.substr(pos+1,roomId.size() - pos -1);//字符串分割
            
            m.insert(make_pair(key,value));
        }
        pos = (int)status.find(":");
        if(pos != -1)
        {
            key = status.substr(0,pos);
            value = status.substr(pos+1,status.size() - pos -1);
            
            m.insert(make_pair(key,value));
        }
        
        this->m_orderData.insert(make_pair(this->m_Size,m));//键值
        this->m_Size++;
    }
    
    ifs.close();
}

void OrderFile::updateOrder()
{
    if(this->m_Size == 0)
    {
        return;
    }
    
    std::ofstream ofs(ORDER_FILE,std::ios::out | std::ios::trunc);
    for(int i = 0;i < m_Size;i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] <<" ";
        ofs << "interval:" << this->m_orderData[i]["interval"] <<" ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] <<" ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] <<" ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] <<" ";
        ofs << "status:" << this->m_orderData[i]["status"] << std::endl;
    }
    
    ofs.close();
    
}
