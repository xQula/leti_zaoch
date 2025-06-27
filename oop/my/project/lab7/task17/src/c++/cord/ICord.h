//
// Created by dokto on 11.06.2024.
//

#pragma once

class ICordinate {

public:
    virtual ~ICordinate() = default;

    virtual void Print() const = 0;
};
