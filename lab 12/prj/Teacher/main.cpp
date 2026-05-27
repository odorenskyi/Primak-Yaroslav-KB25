#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>
#include <thread>
#include <windows.h>

#include "ModulesPrimak.h"

bool isCorrectPath() {
    std::string compile_path = __FILE__;
    if (compile_path.find("\\Lab12\\prj") != std::string::npos ||
        compile_path.find("/Lab12/prj") != std::string::npos ||
        compile_path.find("\\lab 12\\prj") != std::string::npos) {
        return true;
    }
    return false;
}

int main() {
    std::setlocale(LC_ALL, "C");

    if (!isCorrectPath()) {
        std::ofstream errFile("TestResults.txt");
        if (errFile.is_open()) {
            errFile << "Âñòàíîâëåí³ âèìîãè ïîðÿäêó âèêîíàííÿ ëàáîðàòîðíî¿ ðîáîòè ïîðóøåíî!";
            errFile.close();
        }
        std::cout << "ERROR: Nepravilniy shlyah do papki proektu!" << std::endl;
        for (int i = 0; i < 100; ++i) {
            std::cout << "\a" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
        return 1;
    }

    std::string paths[] = {
        "TestSuite.txt",
        "../TestSuite/TestSuite.txt",
        "../../TestSuite/TestSuite.txt"
    };

    std::ifstream inFile;
    std::string currentSuitePath = "";

    for (const auto& p : paths) {
        inFile.open(p);
        if (inFile.is_open()) {
            currentSuitePath = p;
            break;
        }
        inFile.clear();
    }

    if (!inFile.is_open()) {
        std::cout << "==================================================" << std::endl;
        std::cout << "CRITICAL ERROR: Kumpilyator ne bachat fail s testami!" << std::endl;
        std::cout << "==================================================" << std::endl;
        std::cout << "\nNatisnit ENTER dlya vihodu...";
        std::cin.get();
        return 1;
    }

    std::string resultsPath = "TestResults.txt";
    std::ofstream outFile(resultsPath);
    if (!outFile.is_open()) {
        std::cout << "ERROR: Ne vdalosya stvoriti fail rezultativ!" << std::endl;
        return 1;
    }

    std::cout << "SUCCESS: Fail testiv znaydeno! Pochinaemo testuvannya..." << std::endl;

    outFile << "=== ÏÐÎÒÎÊÎË ÌÎÄÓËÜÍÎÃÎ ÒÅÑÒÓÂÀÍÍß ===" << std::endl;

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string tc_id, radius_str, expected_str;

        std::getline(ss, tc_id, '|');
        std::getline(ss, radius_str, '|');
        std::getline(ss, expected_str, '|');

        double radius = std::stod(radius_str);
        double expected_result = std::stod(expected_str);

        std::string action = "Create Object & setRadius(" + radius_str + ")";
        std::string test_result = "FAILED";

        try {
            ClassLab12_Primak sphere(radius);
            double actual_result = sphere.calculateSurfaceArea();

            if (std::abs(actual_result - expected_result) < 1e-4) {
                test_result = "PASSED";
            }
        } catch (const std::exception& e) {
            test_result = "ERROR (" + std::string(e.what()) + ")";
        }

        outFile << tc_id << " -> " << action << " -> Expected: " << expected_str << " -> Result: " << test_result << std::endl;
    }

    std::cout << "TESTING COMPLETE! Rezultati zberezheno u fail." << std::endl;
    std::cout << "Shlyah do faylu: " << resultsPath << std::endl;

    inFile.close();
    outFile.close();

    std::cout << "\nNatisnit ENTER dlya vihodu...";
    std::cin.get();
    return 0;
}
