//
//  orderFile.hpp
//  cpptest
//
//  Created by 孔秀志 on 2019/12/10.
//  Copyright © 2019 孔秀志. All rights reserved.
//

#ifndef orderFile_hpp
#define orderFile_hpp

#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <string>
#include <map>


class OrderFile
{
public:
    OrderFile();
    
    void updateOrder();
    
    int m_Size;
    
    std::map<int, std::map<std::string,std::string>> m_orderData;
    
};


#endif /* orderFile_hpp */
