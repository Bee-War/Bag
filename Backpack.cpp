#include <iostream>
#include <vector>
#include "product.h"
#include <sstream>

using namespace std;

// Функция для преобразования строки в вектор чисел типа double
vector<double> stringToDoubleArray(const string& inputString) {
    vector<double> result;
    stringstream ss(inputString);
    double num;
    // Читаем числа из stringstream и добавляем их в вектор
    while (ss >> num) {
        result.push_back(num); //1 2 5 6 7
        // Пропускаем пробел после числа, если есть
        if (ss.peek() == ' ') { // считываем следующий символ
            ss.ignore();        // отбрасывает следующий символ если он пробел
        }
    }
    return result;
}

Bag::Bag(double maxWeight) : maxWeight(maxWeight)
{
    vector<Product> products;
}   

void Bag::BagWeight(double Weight, double tw)
{
    if (Weight >= tw)
        maxWeight = Weight;
    else
        cout << "Вес не изменён, так как сумка мала для продуктов";
}

double Bag::getCurrentWeight() { // рассчитываем общую массу в сумке
    double totalWeight = 0.0;
    for (const auto& prod : products) {
        totalWeight += prod.getMass();
    }
    return totalWeight;
}

void Bag::addProduct() { // метод добавления продукта
    
        string name, str; // сохранение имени продукта и строки его данных
        vector<double> data; // создадим вектор, для передачи данных
        bool check = true; // проверка на корректность ввода
        cout << "Введите наименование продукта:";
        cin >> name;
        cout << "Введите данные продукта в формате:\nмасса температура макс.темп мин.темп теплоёмкость\n";
        cout << "Или введите -1 для выхода из раздела\n:";
        cin.ignore(); // пропуск потока данных, что бы не захватывалась пустая строка
        getline(cin, str); // ввод строки данных продукта
        data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double

        while (check) // цикл для множества попыток ввода данных
        {
            if (data[0] != -1)
            {
                if ((data[0] > 0) && (data[2] > data[3]) && (data[4] > 0) && (data[1] > data[3]) && (data[1] < data[2]) && (getCurrentWeight() + data[0] <= maxWeight))
                {
                    check = false;
                    Product eda(name, data[0], data[1], data[2], data[3], data[4]); // создание записи данных продукта
                    products.push_back(eda); // запись данных продукта в вектор
                    cout << "Продукт добавлен.\n";
                }
                else
                {
                    if ((getCurrentWeight() + data[0]) > maxWeight) // проверка вместимости
                    { 
                        cout << "Сумка переполнена, продукт не помещен." << endl;
                        cout << "Поместите продукт поменьше или измените размер сумки(Введите -1).\n";
                        cout << "Введите данные продукта в формате:\n";
                        cout << "масса температура макс.темп мин.темп теплоёмкость\n:";
                        getline(cin, str); // ввод строки данных продукта
                        data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double
                    }
                    else
                    {
                        cout << "введены неккоректные данные, введите корректные данные снова, или введите -1, для выхода из раздела\n";
                        cout << "Введите данные продукта в формате:\n";
                        cout << "масса температура макс.темп мин.темп теплоёмкость\n:";
                        getline(cin, str); // ввод строки данных продукта
                        data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double
                    }
                }
            }
            else
                break;
        }
}      

void Bag::DellProduct() { // метод удаления продукта
    if (products.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < products.size(); i++) {
                    cout << i + 1 << "-" << products[i].getName() << endl;
                }
                cout << "Введите номер продукта, который вы хотели бы забрать:" << endl;
                cin >> j;
                if (j > 0 && j < products.size() + 1)
                {
                    j = j - 1;
                    string name = products[j].getName();
                    products.erase(products.begin() + j);
                    cout << "Продукт " << name << " убран из сумки. " << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
}

int Bag::countSpoiledProducts() { // метод подсчёта испорченных продуктов в сумке
    int count = 0;
    for (const auto& prod : products) {
        if (prod.getState() != "NORMAL") { // считаем сколько продуктов испорчено
            count++;
        }
    }
    return count;
}

int Bag::countWouldSpoilProducts() { // метод подсчёта сколько продуктов может испортиться при помещении нового
    int count = 0; // счётчик испорченых продуктов

    // стандартный ввод, вставил для удобства чтения, чуть изменил в 154 строке
    string name, str; // сохранение имени продукта и строки его данных
    vector<double> data; // создадим вектор, для передачи данных
    bool check = true; // проверка на корректность ввода
    cout << "Введите наименование продукта:";
    cin >> name;
    cout << "Введите данные продукта в формате:\nмасса температура макс.темп мин.темп теплоёмкость\n";
    cout << "Или введите -1 для выхода из раздела\n:";
    cin.ignore(); // пропуск потока данных, что бы не захватывалась пустая строка
    getline(cin, str); // ввод строки данных продукта
    data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double

    while (check) // цикл для множества попыток ввода данных
    {
        if (data[0] != -1)
        {
            if ((data[0] > 0) && (data[2] > data[3]) && (data[4] > 0) && (data[1] > data[3]) && (data[1] < data[2]) && (getCurrentWeight() + data[0] <= maxWeight))
            {
                check = false;
            }
            else
            {
                if ((getCurrentWeight() + data[0]) > maxWeight) // проверка вместимости
                {
                    cout << "Сумка переполнена, продукт не может быть помещен." << endl;
                    cout << "Поместите продукт поменьше или измените размер сумки(Введите -1).\n";
                    cout << "Введите данные продукта в формате:\n";
                    cout << "масса температура макс.темп мин.темп теплоёмкость\n:";
                    getline(cin, str); // ввод строки данных продукта
                    data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double
                }
                else
                {
                    cout << "введены неккоректные данные, введите корректные данные снова, или введите -1, для выхода из раздела\n";
                    cout << "Введите данные продукта в формате:\n";
                    cout << "масса температура макс.темп мин.темп теплоёмкость\n:";
                    getline(cin, str); // ввод строки данных продукта
                    data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double
                }
            }
        }
        else
            break;
    }

    if (!check)
    {
        double TotalHeat = data[1] * data[0] * data[4]; // тепло добавляемого продукта
        double TotalCapacity = data[4] * data[0]; // теплоёмкость добавляемого продукта
        for (int i = 0; i < products.size(); i++) {
            TotalHeat += products[i].getTemperature() * products[i].getHeatCapacity() * products[i].getMass(); // сумируем общее кол-во тепла
            TotalCapacity += products[i].getHeatCapacity() * products[i].getMass(); // сумируем общее кол-во теплоёмкости
        }
        for (int i = 0; i < products.size(); i++) {
            double prodQ = products[i].getTemperature() * products[i].getMass() * products[i].getHeatCapacity(); // тепло до обмена
            double Q = ((TotalHeat) * (products[i].getHeatCapacity() * products[i].getMass() / TotalCapacity)); // сколько должно быть передано тепла 
            string state = "";

            if (prodQ > Q) // если продукт имеет больше тепла, чем должен после теплообмена
                state = products[i].getFinalStateAfterHeatTransfer(Q - prodQ); // забираем тепло
            else
                state = products[i].getFinalStateAfterHeatTransfer(Q); // передаём тепло

            if (state != "NORMAL")
                count++;
        }
        return count;
    }
    else
        return 0;
}

size_t Bag::getProductCount() { // метод получения количества продуктов в сумке
    return products.size();
}

void Bag::StabilizathionHeat() // метод стабилизации тепла
{
    double TotalHeat = 0, TotalCapacity = 0;
    for (int i = 0; i < products.size(); i++) {
        TotalHeat += products[i].getTemperature() * products[i].getHeatCapacity() * products[i].getMass(); // сумируем общее кол-во тепла
        TotalCapacity += products[i].getHeatCapacity() * products[i].getMass(); // сумируем общее кол-во теплоёмкости
    }
    for (int i = 0; i < products.size(); i++) {
        double prodQ = products[i].getTemperature() * products[i].getMass() * products[i].getHeatCapacity(); // тепло до обмена
        double Q = ((TotalHeat) * (products[i].getHeatCapacity() * products[i].getMass() / TotalCapacity)); // сколько должно быть тепла после обмена

       // if (prodQ > Q) // если продукт имеет больше тепла, чем должен после теплообмена     
            products[i].transferHeat(Q - prodQ); // забираем тепло
       // else
       //     products[i].transferHeat(prodQ - Q); // передаём тепло
    }
};

string Bag::GetTemp()
{
    if (products.size() != 0)
        return to_string(products[0].getTemperature());
    else
        return "В рюкзаке нет продуктов\n";

}
