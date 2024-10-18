#include "Sender.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

class HealthDataProcessor {
public:
    void processData() {
        std::string line;
        std::vector<double> temperatures;
        std::vector<int> pulseRates;
        std::vector<int> spo2Values;

        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);
            double temperature;
            int pulseRate, spo2;

            char comma; // To consume the commas in the input
            if (!(iss >> temperature >> comma >> pulseRate >> comma >> spo2)) {
                std::cerr << "Error reading data" << std::endl;
                continue;
            }

            temperatures.push_back(temperature);
            pulseRates.push_back(pulseRate);
            spo2Values.push_back(spo2);

            printStatistics(temperatures, "Temperature");
            printStatistics(pulseRates, "Pulse Rate");
            printStatistics(spo2Values, "SpO2");
        }
    }

private:
    template <typename T>
    void printStatistics(const std::vector<T>& values, const std::string& label) {
        if (values.empty()) return;

        T maxVal = *std::max_element(values.begin(), values.end());
        T minVal = *std::min_element(values.begin(), values.end());
        double avg = std::accumulate(values.begin(), values.end(), 0.0) / values.size();

        std::cout << label << " - Max: " << maxVal << ", Min: " << minVal << ", Avg: " << avg << std::endl;
    }
};

int main() {
    HealthDataProcessor processor;
    processor.processData();
    return 0;
}
