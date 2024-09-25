#include <iostream>
#include <random>

int generateTemperature() {
    int minTemp = 95;
    int maxTemp = 105;
    return rand() % (maxTemp - minTemp + 1) + minTemp;
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
int main() {

    for (int i = 0; i < 50; ++i) {
        double temperature = generateTemperature();
        int pulseRate = generatePulseRate() ;
        int spo2 = generateSpO2();

        std::cout << temperature << ", " << pulseRate << ", " << spo2 << "\n";
    }
    return 0;
}

