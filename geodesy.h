//
// Created by admin on 2021/6/11.
//

#ifndef CPP_CODE_GEODESY_H
#define CPP_CODE_GEODESY_H



#include <cmath>
#include "mathematics/math_common.h"

template<typename T>
double HaversineFunction(T theta)
{
    double hav;
    hav = pow(sin(theta/2.0), 2);
    return hav;
}

template<typename T>
double GreatCircleDistanceHaversine(T lon1, T lat1, T lon2, T lat2, T radius)
{
    double d, hav_lat, hav_lon, sq;
    double lon1_rad, lat1_rad, lon2_rad, lat2_rad;

    lon1_rad = degree_to_radiance(lon1), lat1_rad = degree_to_radiance(lat1);
    lon2_rad = degree_to_radiance(lon2), lat2_rad = degree_to_radiance(lat2);

    hav_lat = HaversineFunction(lat2_rad - lat1_rad);
    hav_lon = HaversineFunction(lon2_rad - lon1_rad);
    sq = sqrt(hav_lat + cos(lat1_rad)*cos(lat2_rad)*hav_lon);
    d = 2*radius*asin(sq);
    return d;
}

template<typename T>
double GreatCircleDistance(T lon1, T lat1, T lon2, T lat2, T radius)
{
    double delta_lon_rad, central_angle, d;
    lon1_rad = degree_to_radiance(lon1), lat1_rad = degree_to_radiance(lat1);
    lon2_rad = degree_to_radiance(lon2), lat2_rad = degree_to_radiance(lat2);

    delta_lon_rad = lon2_rad - lon1_rad;
    central_angle = acos(sin(lat1_rad)*sin(lat2_rad) + cos(lat1_rad)*cos(lat2_rad)*cos(delta_lon_rad));
    d = radius*central_angle;
    return d;
}


#endif //CPP_CODE_GEODESY_H