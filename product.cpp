#include <iostream>
#include "product.h"
using namespace std;


// Реализация конструктора класса Product
Product::Product(const string& name, double mass, double temperature, double maxTemperature, double minTemperature, double heatCapacity)
    : name(name), mass(mass), temperature(temperature), maxTemperature(maxTemperature), minTemperature(minTemperature), heatCapacity(heatCapacity) {
    state = NORMAL; // Устанавливаем начальное состояние продукта как "нормальное"
}

// Оператор присваивания
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        this->name = other.name;
        this->mass = other.mass;
        this->temperature = other.temperature;
        this->maxTemperature = other.maxTemperature;
        this->minTemperature = other.minTemperature;
        this->heatCapacity = other.heatCapacity;
    }
    return *this;
}

// Методы доступа к приватным полям класса
string Product::getName() const {
    return name;
}

double Product::getMass() const {
    return mass;
}

double Product::getTemperature() const {
    return temperature;
}

double Product::getMaxTemperature() const {
    return maxTemperature;
}

double Product::getMinTemperature() const {
    return minTemperature;
}

// Метод для получения текущего состояния продукта
string Product::getState() const {
    setlocale(LC_ALL, "Russian");
    if (state == FROZEN) {
        return "FROZEN";
    }
    else if (state == OVERHEATED) {
        return "OVERHEATED";
    }
    else {
        return "NORMAL";
    }
}

double Product::getHeatCapacity() const {
    return heatCapacity;
}

// Метод для передачи тепла продукту
void Product::transferHeat(double heat) {
    temperature += heat / (heatCapacity * mass); // Изменяем температуру продукта в зависимости от переданного тепла

    if (temperature > maxTemperature) { // Проверка на перегрев
        state = OVERHEATED;
    }
    else if (temperature < minTemperature) { // Проверка на замерзание
        state = FROZEN;
    }
}

// То же самое прописано в transferHeat
// Метод для вычисления конечной температуры после передачи тепла
string Product::getFinalStateAfterHeatTransfer(double heat) const {
    double finalTemp = temperature + heat / (heatCapacity * mass); // Вычисляем конечную температуру

    if (finalTemp > maxTemperature) { // Проверка на перегрев
        return "OVERHEATED";
    }
    else if (finalTemp < minTemperature) { // Проверка на замерзание
        return "FROZEN";
    }
    else {
        return "NORMAL";
    }
}
/*// деструктор
Product::~Product() {
    //Деструктор для класса Product не требует дополнительных действий по освобождению ресурсов, так как классе отсутствуют динамически выделенные ресурсы.
}*/
