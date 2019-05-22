//Copyright (c) 2018 Ultimaker B.V.


#ifndef ANGLEDEGREES_H
#define ANGLEDEGREES_H

#include <cmath> //For fmod.

namespace arachne
{

/*
 * \brief Represents an angle in degrees.
 *
 * This is a facade. It behaves like a double, but this is using clock
 * arithmetic which guarantees that the value is always between 0 and 360.
 */
struct AngleDegrees
{
    /*
     * \brief Default constructor setting the angle to 0.
     */
    AngleDegrees() : value(0.0) {};

    /*
     * \brief Casts a double to an AngleDegrees instance.
     */
    AngleDegrees(double value) : value(std::fmod(std::fmod(value, 360) + 360, 360)) {};

    /*
     * \brief Casts the AngleDegrees instance to a double.
     */
    operator double() const
    {
        return value;
    }

    /*
     * Some operators implementing the clock arithmetic.
     */
    AngleDegrees operator +(const AngleDegrees& other) const
    {
        return std::fmod(std::fmod(value + other.value, 360) + 360, 360);
    }
    AngleDegrees operator +(const int& other) const
    {
        return operator+(AngleDegrees(other));
    }
    AngleDegrees& operator +=(const AngleDegrees& other)
    {
        value = std::fmod(std::fmod(value + other.value, 360) + 360, 360);
        return *this;
    }
    AngleDegrees operator -(const AngleDegrees& other) const
    {
        return std::fmod(std::fmod(value - other.value, 360) + 360, 360);
    }
    AngleDegrees& operator -=(const AngleDegrees& other)
    {
        value = std::fmod(std::fmod(value - other.value, 360) + 360, 360);
        return *this;
    }

    /*
     * \brief The actual angle, as a double.
     *
     * This value should always be between 0 and 360.
     */
    double value = 0;
};

}

#endif //ANGLEDEGREES_H