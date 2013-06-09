//
//  main.cpp
//  GameTwo Server
//
//  Created by warjo on 6/8/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Server.h"

int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    TCP_Server *myServer = new TCP_Server;
    bool tempBool = myServer->InitServer();
    
    
    if (!tempBool)
    {
        std::cout << "Problem creating socket" << std::endl;
    }
    while (1)
    {
    
        myServer->CheckForIncomingConnections();
        
        
        myServer->CheckForIncomingMessages();
        
    }
    
    close(myServer->GetSocketIdentifier());
    
    
    
    return 0;
}

