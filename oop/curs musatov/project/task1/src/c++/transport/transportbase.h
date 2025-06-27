
#pragma once
#include <string>

class TransportBase {

public:
    explicit TransportBase(std::string name, std::string stamp, int maxCapacity);
    virtual ~TransportBase() = default;
    virtual auto out() -> void;
private:
    std::string m_name;
    std::string m_stamp;
    int m_maxCapacity;

};



