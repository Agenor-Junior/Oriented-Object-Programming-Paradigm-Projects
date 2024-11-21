#include "Truck.h"
#include <iomanip>

namespace seneca {

    Truck::Truck(const char* plate, int yearBuilt, double cap, const char* address)
        : MotorVehicle(plate, yearBuilt), capacity(cap), cargo(0) {
        moveTo(address);
    }

    bool Truck::addCargo(double cargoWeight) {
        if (cargo + cargoWeight > capacity) {
            double excess = (cargo + cargoWeight) - capacity;
            cargo = capacity;
            return excess < cargoWeight; // Retorna true se foi possível adicionar algum cargo
        }
        cargo += cargoWeight;
        return true;
    }

    bool Truck::unloadCargo() {
        if (cargo == 0) return false;
        cargo = 0;
        return true;
    }

    std::ostream& Truck::write(std::ostream& os) const {
        MotorVehicle::write(os);
        os << " | " << cargo << "/" << capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in) {
        MotorVehicle::read(in);
        std::cout << "Capacity: ";
        in >> capacity;
        std::cout << "Cargo: ";
        in >> cargo;
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& t) {
        return t.write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& t) {
        return t.read(is);
    }

}
