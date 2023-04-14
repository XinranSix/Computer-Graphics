//
// Created by yaojie on 2023/4/14.
//

#ifndef MATERIAL_H
#define ATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material {
public:
    virtual bool scatter(
            const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered
            ) const = 0;
};

#endif
