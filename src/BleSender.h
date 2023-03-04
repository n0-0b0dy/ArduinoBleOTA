#pragma once

class BleSender
{
public:
    virtual ~BleSender(){}
public:
    virtual void send(const uint8_t* data, size_t length)=0;
};