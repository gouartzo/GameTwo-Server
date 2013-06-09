//
//  Server.h
//  GameTwo Server
//
//  Created by warjo on 6/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef GameTwo_Server_Server_h
#define GameTwo_Server_Server_h

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <errno.h>

#include <vector>




const int SERVER_PORT = 2153;


class TCP_Server
{
public:
    //Starts our server. Creates, binds and listens to our socket.
    bool                InitServer();
    
    void                CheckForIncomingConnections();
    
    void                CheckForIncomingMessages();
    
    const int           GetSocketIdentifier();
    
    
     TCP_Server();
    ~TCP_Server();

private:
    //our sockets unique identifier.
    int         socket_id;
    char        buffer[1024];
    
    //list of socket identifiers accepted.
    std::vector<int> socket_list;
    
    
    
    
};




#endif
