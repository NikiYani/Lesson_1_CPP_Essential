#include <QCoreApplication>
#include <iostream>
#include <random>

using namespace std;

enum class VendorCodeWoodTable : int;

int getVendorCodeWoodTable(enum VendorCodeWoodTable &woodTable)
{
    return (int)woodTable;
}

enum Runers
{
    runer_1 = 1,
    runer_2,
    runer_3 = 16,
    runer_4
};

enum class VendorCodeWoodTable : int
{
    table_1 = 1,
    table_2,
    table_3 = 3,
    table_4 = 4
};

//struct

enum Effects
{
    healthRecovery,
    manaRecovery,
    staminaRecovery,
    speedUp,
    powerUp,
    agilityUp
};

struct Potion
{
    float mutation;
    Effects effPotion;
};

//union

union Bonus
{
    int plusHP;
    int plusMP;
    int plusAP;
    float plusMutationResist;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Пример использования enum

    cout << "Example using enum: \n\n";

    Runers runerTest = runer_1;

    cout << "runer_1 = " << runerTest << endl;

    runerTest = runer_4;

    cout << "runer_4 = " << runerTest << endl;

    cout << "\n\n";

    // Пример использования class enum

    cout << "Example using enum class: \n\n";

    VendorCodeWoodTable woodTables = VendorCodeWoodTable::table_1;

    cout << "woodTables = " << (int)woodTables << endl;

    woodTables = VendorCodeWoodTable::table_3;

    cout << "woodTables = " << (int)woodTables << endl;

    cout << "getVendorCodeWoodTable: " << getVendorCodeWoodTable(woodTables) << endl;

    cout << "\n\n";

    // Пример использования struct

    cout << "Example using struct: \n\n";

    srand(time(NULL));

    Potion healthPotion;

    healthPotion.effPotion = Effects::healthRecovery;
    healthPotion.mutation = (1 + rand() % 100) / 10.0;

    cout << "healthPotion: \nnumberType - " << healthPotion.effPotion
         << "\nmutationRandom - " << healthPotion.mutation
         << endl;

    Potion randomPotion;

    switch (0 + rand() % 5) {
        case 0: randomPotion.effPotion = Effects::agilityUp;
            break;
        case 1: randomPotion.effPotion = Effects::healthRecovery;
            break;
        case 2: randomPotion.effPotion = Effects::manaRecovery;
            break;
        case 3: randomPotion.effPotion = Effects::powerUp;
            break;
        case 4: randomPotion.effPotion = Effects::speedUp;
            break;
        case 5: randomPotion.effPotion = Effects::staminaRecovery;
            break;

    }

    randomPotion.mutation = (1 + rand() % 100) / 10.0;

    cout << "randomPotion: \nnumberType - " << randomPotion.effPotion
         << "\nmutationRandom - " << randomPotion.mutation;

    cout << "\n\n";

    cout << "sizeof (Potion) : " << sizeof (Potion) << endl;

    // Пример использования union

    cout << "Example using union: \n\n";

    Bonus bonus;
    bonus.plusMutationResist = 14.5;

    cout << "plusMutationResist: " << bonus.plusMutationResist
         << "\nsizeof(): " << sizeof (bonus.plusMutationResist)
         << endl;

    bonus.plusAP = 5;

    cout << "plusMutationResist: " << bonus.plusAP
         << "\nsizeof(): " << sizeof (bonus.plusAP)
         << endl;

    return a.exec();
}
