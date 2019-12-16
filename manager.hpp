//
//  manager.hpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/9.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include <string>
#include "identity.hpp"
#include <vector>
#include "student.hpp"
#include "teacher.hpp"
#include "computerRoom.h"

class Manager:public Identity
{
public:
    Manager();
    Manager(std::string name,std::string Pwd);
    
    virtual void operMenu();
    
    void showAllOrder();
    void addPerson();
    void showPerson();
    void showComputer();
    void clearnFile();
    void initVector();
    bool checkRepeat(int id, int type);
    std::vector<Student> vStu;
    std::vector<Teacher> vTea;
    std::vector<ComputerRoom> vCom;
};

#endif /* manager_hpp */
