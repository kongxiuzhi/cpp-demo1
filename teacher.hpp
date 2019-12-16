//
//  teacher.hpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#pragma once
#include <iostream>
#include "identity.hpp"
#include <string>
#include <vector>
#include "orderFile.hpp"

class Teacher:public Identity
{
public:
    Teacher();
    Teacher(int empId,std::string name,std::string Pwd);
    
    virtual void operMenu();
    
    void showAllOrder();
    void validOrder();
    
    
    int m_EmpId;
};
