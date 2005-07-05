// **********************************************************************
//
// Copyright (c) 2003-2005 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef ICEE_TRANSPORT_CONNECTOR_H
#define ICEE_TRANSPORT_CONNECTOR_H

#include <IceE/ConnectorF.h>
#include <IceE/TransceiverF.h>
#include <IceE/InstanceF.h>
#include <IceE/TraceLevelsF.h>
#include <IceE/LoggerF.h>
#include <IceE/Shared.h>

#ifndef _WIN32
#   include <netinet/in.h> // For struct sockaddr_in
#endif

namespace IceEInternal
{

class Endpoint;

class ICEE_API Connector : public ::IceE::Shared
{
public:
    
    TransceiverPtr connect(int);
    std::string toString() const;
    
private:
    
    Connector(const InstancePtr&, const std::string&, int);
    virtual ~Connector();
    friend class Endpoint;

    InstancePtr _instance;
    TraceLevelsPtr _traceLevels;
    ::IceE::LoggerPtr _logger;
    struct sockaddr_in _addr;
};

}

#endif
