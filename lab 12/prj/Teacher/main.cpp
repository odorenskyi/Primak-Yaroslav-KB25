#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#include "../ModulesPrimak.h"

bool isCorrectPath() {
    std::string compile_path = __FILE__;
    if (compile_path.find("\\Lab12\\prj") != std::string::npos ||
        compile_path.find("/Lab12/prj") != std::string::npos) {
        return true;
    }
    return false;
}

int main() {
    std::setlocale(LC_ALL, "Ukranian");

    if (!isCorrectPath()) {
        std::ofstream errFile("TestResults.txt");
        if (errFile.is_open()) {
            errFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            errFile.close();
        }
        // 100 звукових сигналів у разі порушення структури папок
        for (int i = 0; i < 100; ++i) {
            std::cout << "\a" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
        return 1;
    }

    std::cout << "Перевірку шляху пройдено. Готові до тестів." << std::endl;
    return 0;
}
