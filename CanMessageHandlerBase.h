﻿// CanMessageHandlerBase.h
#pragma once

#ifndef _CanMessageHandlerBase_h
    #define _CanMessageHandlerBase_h

#include "AbstractCanMessageSender.h"

class CanMessageHandlerBase
{
    int processInterval = 100;
    unsigned long previousTime = 0;

    AbstractCanMessageSender *canMessageSender;

    virtual void InternalProcess() = 0;

    protected:
    CanMessageHandlerBase(AbstractCanMessageSender * object, int interval)
    {
        processInterval = interval;
        canMessageSender = object;
    }

    public:

    void Process(unsigned long currentTime)
    {
        if (currentTime - previousTime > processInterval)
        {
            previousTime = currentTime;

            InternalProcess();
        }
    }
};

#endif
