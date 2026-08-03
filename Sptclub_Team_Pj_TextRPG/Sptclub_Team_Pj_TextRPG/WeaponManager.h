#pragma once

#include <string>
#include "WeaponItem.h"

class WeaponManager
{
public:
    static WeaponItem CreateWeaponForJob(const std::string& job);
};