//
//  identity.hpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/10.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#ifndef identity_hpp
#define identity_hpp


#include<iostream>
#include<string>

class Identity
{
    
public:
    
    virtual void operMenu() = 0;//子类必须实现虚函数,否则子类无法实例化；
    
    std::string m_Name;
    std::string m_Pwd;
    virtual ~Identity() = 0;
};



#endif /* identity_hpp */
