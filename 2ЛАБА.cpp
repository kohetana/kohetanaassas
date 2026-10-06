// 2ЛАБА.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/* Автор: Кучина М.А.*
 * Дата : 06.10.2026 *
 * Вариант 12        *
 * Название : 2 лаба *
 *********************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Блок объявления переменных
    double initialTemperature;
    double solidificationTemperature;
    double coolingCoefficient;
    double linearCoefficient;

    double solidificationTime;
    double currentTime;
    double averageTemperature;

    // Блок ввода данных
    cout << "Enter initial temperature (t_zh): ";
    cin >> initialTemperature;

    cout << "Enter solidification temperature (t_tv): ";
    cin >> solidificationTemperature;

    cout << "Enter cooling coefficient (0.021): ";
    cin >> coolingCoefficient;

    cout << "Enter linear coefficient (0.0151): ";
    cin >> linearCoefficient;

    // Блок расчетов
    solidificationTime = (1.0 / coolingCoefficient) * log(initialTemperature / solidificationTemperature);

    cout << "\nSolidification time: " << solidificationTime << " min" << endl;
    cout << "Time\tAverage Temperature" << endl;

    // Первый участок: цикл с постусловием (do-while)
    // Время меньше времени затвердевания
    currentTime = 10.0;
    do {
        averageTemperature = initialTemperature * exp(-coolingCoefficient * currentTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += 10.0;
    } while (currentTime < solidificationTime);

    // Второй участок: цикл с предусловием (while)
    // Время больше времени затвердевания
    // Начинаем с 50, так как 10, 20, 30 уже обработаны, а 40 может быть близко к границе
    currentTime = 50.0;
    while (currentTime <= 100.0) {
        averageTemperature = solidificationTemperature - linearCoefficient * (currentTime - solidificationTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += 50.0; // Шаг 50, чтобы попасть в 100
    }

    return 0;
}