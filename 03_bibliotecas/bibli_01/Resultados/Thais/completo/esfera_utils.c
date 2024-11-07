#include <stdio.h>
#include "esfera_utils.h"

float calcula_volume (float R){
    float volume;
    volume = 4/3 * PI * R * R * R;
    return volume;
}

float calcula_area (float R){
    float area;
    area = 4 * PI * R * R;
    return area;
}