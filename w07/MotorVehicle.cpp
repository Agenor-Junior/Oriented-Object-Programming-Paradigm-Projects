#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    MotorVehicle::MotorVehicle(const char* plate, int yearBuilt) : year(yearBuilt) {
        strncpy(licensePlate, plate, 8);
        licensePlate[8] = '\0';
        strcpy(address, "Factory");
    }

    void MotorVehicle::moveTo(const char* newAddress) {
        if (strcmp(address, newAddress) != 0) {
            std::cout << "|" << std::setw(8) << std::right << licensePlate << "| |"
                << std::setw(20) << std::right << address << " ---> "
                << std::setw(20) << std::left << newAddress << "|" << std::endl;
            strncpy(address, newAddress, 63);
            address[63] = '\0';
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << year << " | " << licensePlate << " | " << address;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in) {
        std::cout << "Built year: ";
        in >> year;
        std::cout << "License plate: ";
        in >> licensePlate;
        std::cout << "Current location: ";
        in >> address;
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {
        return mv.write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& mv) {
        return mv.read(is);
    }

}
