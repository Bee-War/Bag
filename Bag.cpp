#include "product.h"
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    Bag backpack (0); // задаём начальные данные рюкзака

    int cickle = 1;
    while (cickle)
    {
        cout << "1- Изменить размер сумки \n2- Добавить продукт \n3- Узнать массу продуктов \n4- Забрать продукт \n5- Узнать количество продуктов в сумке\n6- Узнать кол-во испорченых продуктов \n7- Узнать сколько продуктов испортится при помещении нового \n8- Узнать температуру продуктов \n0- завершить программу\n:";
        cin >> cickle;

        switch (cickle)
        {
        case 1: // Изменить размер сумки
        {
            double tw = backpack.getCurrentWeight(); // контроль что бы размер не изменили на меньший чем продуктов в сумке
            cout << "Введите размер сумки : ";
            double newtw;
            cin >> newtw;

            backpack.BagWeight(newtw,tw);// указываем новый размер сумки
            system("pause"); // удержание консоли для удобства чтения
        }
        break;

        case 2: // Добавить продукт
            backpack.addProduct();
            backpack.StabilizathionHeat();
            break;
        case 3: // узнать массу всех продуктов
            cout << "Масса всех продуктов : " << backpack.getCurrentWeight() << endl;
            system("pause"); // удержание консоли для удобства чтения
            
            break;
        case 4: // забрать продукт из сумки
            backpack.DellProduct();
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 5:
            cout << "Всего : " << backpack.getProductCount() <<" продуктов в сумке." << endl;
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 6:
            cout << "Всего : " << backpack.countSpoiledProducts() << " испорченых продуктов в сумке." << endl;
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 7:
            cout << "Всего : " << backpack.countWouldSpoilProducts() << " может быть испорчено при помещении данного в сумку." << endl;
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 8:
            cout << "Температура продуктов : " << backpack.GetTemp() << endl;
            system("pause"); // удержание консоли для удобства чтения
            break;
        default:
            break;
        }

    }
    return 0;
}
