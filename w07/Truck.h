#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace seneca {

    class Truck : public MotorVehicle {
        double capacity;
        double cargo;

    public:
        Truck(const char* plate, int yearBuilt, double cap, const char* address);

        bool addCargo(double cargoWeight);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& t);
    std::istream& operator>>(std::istream& is, Truck& t);

}

#endif
