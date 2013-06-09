//
//  Server.cpp
//  GameTwo Server
//
//  Created by warjo on 6/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>


#include "Server.h"













void TCP_Server::CheckForIncomingMessages()
{
    for (int i=0; i<this->socket_list.size(); i++)
    {
        std::cout << "CALLED" << std::endl;
        char tempBuffer[1024];
        //recv(this->socket_list[i], tempBuffer, 1024, 0);
        
        send(this->socket_list[i], tempBuffer, recv(this->socket_list[i], tempBuffer, 1024, 0), 0);
        
    }
    
}







void TCP_Server::CheckForIncomingConnections()
{
    int temp_client;
    
    struct sockaddr_in client_address;
    int address_len = sizeof(client_address);
    
    
    temp_client = accept(this->socket_id, (struct sockaddr*)&client_address, (socklen_t*)&address_len);
    
    if (temp_client >= 0)
    {
        this->socket_list.push_back(temp_client);
        
        std::cout << inet_ntoa(client_address.sin_addr) << " : " << ntohs(client_address.sin_port);
        std::cout << " CONNECTED!" << std::endl;
    }
    
}




bool TCP_Server::InitServer()
{
    bool temp_return = true;
    
    struct sockaddr_in  server;
                        server.sin_family       = AF_INET;
                        server.sin_port         = htons(SERVER_PORT);
                        server.sin_addr.s_addr  = INADDR_ANY;
    
    
    
    this->socket_id = socket(AF_INET, SOCK_STREAM, 0);
    socket_id<0?temp_return=false:NULL;
    
    
    
    bind(this->socket_id, (struct sockaddr*)&server, sizeof(server));
    listen(this->socket_id, 20);
    
    
    
    
    return temp_return;
}










const int TCP_Server::GetSocketIdentifier() {
    return this->socket_id; 
}








TCP_Server::TCP_Server()
{
    
}

TCP_Server::~TCP_Server()
{
    close(this->socket_id);
    
}
