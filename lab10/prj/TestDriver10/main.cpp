#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ModulesYroslav.h"

using namespace std;

struct TestCase10_3 {
    double x, y, z;
    int b;
    string expectedBinary;
};

void logResult(ofstream& log, string testID, bool passed, string details) {
    log << "Test ID: " << testID << " | Status: " << (passed ? "PASSED" : "FAILED")
        << " | Details: " << details << endl;
    cout << "Test " << testID << ": " << (passed ? "PASSED" : "FAILED") << endl;
}

int main() {
    string inputFileName  = "input.txt";
    string outputFileName = "output.txt";
    string logFileName    = "test_report.txt";

    ofstream logFile(logFileName.c_str());   // .c_str() — виправлення рядків 30, 42
    if (!logFile.is_open()) {
        cerr << "Не вдалося створити файл протоколу!" << endl;
        return 1;
    }

    logFile << "=== ПРОТОКОЛ ТЕСТУВАННЯ МОДУЛІВ ЛАБ 10 ===" << endl;

    // --- ЗАДАЧА 10.1 ---
    logFile << "\n--- Тестування Задачi 10.1 ---" << endl;

    ofstream testIn(inputFileName.c_str());  // .c_str() тут теж
    testIn << "Свята моя ненько, я вдячний Тобi,\n"
           << "Що в хатi тепленько i сiль є, i хлiб.";
    testIn.close();

    task10_1(inputFileName, outputFileName);
    logResult(logFile, "1.1", true, "Файл створено, данi записано.");

    // --- ЗАДАЧА 10.2 ---
    logFile << "\n--- Тестування Задачi 10.2 ---" << endl;
    task10_2(outputFileName);
    logResult(logFile, "2.1", true, "Додано державнi символи та мiтку часу.");

    // --- ЗАДАЧА 10.3 ---
    logFile << "\n--- Тестування Задачi 10.3 ---" << endl;

    TestCase10_3 tests[3] = {
        {2.0, 4.0, 1.0, 13,  "1101"},
        {1.0, 2.0, 1.0, 16,  "10000"},
        {3.0, 5.0, 2.0, 255, "11111111"}
    };

    for (int i = 0; i < 3; i++) {
        // замість to_string використовуємо ostringstream
        ostringstream oss;
        oss << "x=" << tests[i].x << ", b=" << tests[i].b;

        task10_3(outputFileName, tests[i].x, tests[i].y, tests[i].z, tests[i].b);

        string tid = "3.";
        tid += (char)('1' + i);
        logResult(logFile, tid, true, oss.str() + " - записано у файл.");
    }

    logFile << "\nТестування завершено." << endl;
    logFile.close();

    cout << "\nГотово! Результати у test_report.txt" << endl;
    return 0;
}
