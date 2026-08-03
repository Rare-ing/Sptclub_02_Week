#pragma once

#include "Jwado.h"

class Yos : public Jwado
{
public:
    Yos(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;
};
