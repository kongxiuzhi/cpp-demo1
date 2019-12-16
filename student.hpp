//
//  student.hpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#ifndef student_hpp
#define student_hpp


#include <iostream>
#include "identity.hpp"
#include <string>
#include "computerRoom.h"
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "orderFile.hpp"

class Student:public Identity
{
public:
    Student();
    Student(int id,std::string name,std::string Pwd);
    virtual void operMenu();
    
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();
    std::vector<ComputerRoom> vCom;
    int m_Id;
};


#endif /* student_hpp */
