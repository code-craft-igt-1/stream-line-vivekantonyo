#include "Sender.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

double generateTemperature() {
    double minTemp = 36.0;
    double maxTemp = 37.5;
    return minTemp + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (maxTemp - minTemp)));
}

int generatePulseRate() {
    int minPulse = 60;
    int maxPulse = 100;
    return rand() % (maxPulse - minPulse + 1) + minPulse;
}

int generateSpO2() {
    int minSpo2 = 90;
    int maxSpo2 = 100;
    return rand() % (maxSpo2 - minSpo2 + 1) + minSpo2;
}

int generateReadings() {
    for (int i = 0; i < 50; ++i) {
        double temperature = generateTemperature();
        int pulseRate = generatePulseRate();
        int spo2 = generateSpO2();

        std::cout << temperature << ", " << pulseRate << ", " << spo2 << "\n";
    }
    return 0;
}

int main() {
    std::srand(std::time(0)); // Seed for random number generation
    generateReadings();
    return 0;
}
