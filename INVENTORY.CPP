#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Inventory
{
    vector<string> name, brand;

    string inserter;
    int choice;
    int num, num1, num2;
    vector<int> amount, id_code;
    int id = 0, id_confirm;
    int iterator = 0;
    vector<int> unreturned, missing, damaged, actual_amount;
    int randomizer;
    bool on_off;
    bool not_repeat = false;

  public:
    void stored()
    {
        if (not_repeat == false)
        {
            cout << "           [ WELCOME TO MY INVENTORY SYSTEM ]\n\n";
        }
        else
        {
            cout << "           [ WELCOME BACK TO MY INVENTORY SYSTEM ]\n\n";
        }
        id++;
        if (not_repeat == false)
        {
            cout << "press [ ENTER ] to continue: ";
        }
        //We need to clear the buffer input because it caused a lot of trouble if i dont use this
        clearInputBuffer();
        cout << "\nadd the brand name here: ";
        getline(cin, inserter);
        brand.push_back(inserter);
        cout << "\npress [ ENTER ] to continue: ";
        clearInputBuffer();
        cout << "\nadd the item name here: ";
        getline(cin, inserter);
        name.push_back(inserter);
        cout << "Enter how many amount you want to store: ";
        cin >> num;
        amount.push_back(num);
        actual_amount.push_back(num);
        //We need to use rand for randomized ID
        //But some people suggest me to use a specific library for randomizer, but meh idc.
        srand(time(NULL));

        randomizer = rand();
        id_code.push_back(randomizer);

        randomizer = rand() & amount[iterator];
        unreturned.push_back(randomizer);

        amount[iterator] = amount[iterator] - unreturned[iterator];

        randomizer = rand() & amount[iterator];
        missing.push_back(randomizer);

        amount[iterator] = amount[iterator] - missing[iterator];

        randomizer = rand() & amount[iterator];
        damaged.push_back(randomizer);
        amount[iterator] = amount[iterator] - damaged[iterator];

        modification();
    }
    void modification()
    {
        if (id >= iterator)
        {
            cout << "\n\n";
            for (int i = 1; i <= 65; i++)
            {
                cout << "*";
            }
            cout << "\n\n";
            iterator = id;
        }
        iterating();
        cout << "\n\n                            [ CHOOSE ]\n\n";
        cout << "1.) Fill the missing amount of items.\n";
        cout << "2.) Ask people to return all the items they barrowed.";
        cout << "\n3.) Fix all the Damaged items.";
        cout << "\n4.) Add more Products\n";
        cout << "5.) modify the brand name, item name, and add or remove the quantity of the product";
        cout << "\n\nwhat item do you want to modify: ";
        cin >> choice;

        cout << "\n\n";
        for (int i = 1; i <= 65; i++)
        {
            cout << "*";
        }
        cout << "\n\n";
        //We will use "Linear Search Algorithm" in here
        switch (choice)
        {
        case 1:
            on_off = false;
            do
            {
                iterating2();
                cout << "\nenter the item ID you want to refill: ";
                cin >> id_confirm;

                for (int i = 0; i <= iterator; i++)
                {
                    if (id_confirm == id_code[i])
                    {
                        on_off = true;
                        cout << "\n The quantity before: [ " << amount[i] << " ]";
                        amount[i] = missing[i] + amount[i];
                        cout << "\n\n The quantity now: [ " << amount[i] << " ]\n";
                    }
                }
                if (on_off == false)
                {
                    cout << "\nInvalid Number! please insert the available ID";
                }
            } while (on_off == false);

            cout << "\n\n";
            for (int i = 1; i <= 65; i++)
            {
                cout << "*";
            }
            cout << "\n\n";

            break;
        case 2:
            on_off = false;
            do
            {
                iterating2();
                cout << "Enter the ID you want to return all the barrowed item: ";
                cin >> id_confirm;

                for (int i = 0; i <= iterator; i++)
                {
                    if (id_confirm == id_code[i])
                    {
                        on_off = true;
                        cout << "\n The quantity before: [ " << amount[i] << " ]";
                        amount[i] = missing[i] + amount[i];
                        cout << "\n\n The quantity now: [ " << amount[i] << " ]\n";
                    }
                }
                if (on_off == false)
                {
                    cout << "\nInvalid Number! please insert the available ID";
                }
            } while (on_off == false);

            cout << "\n\n";
            for (int i = 1; i <= 65; i++)
            {
                cout << "*";
            }
            cout << "\n\n";

            break;

        case 3:
            on_off = false;
            do
            {
                for (int i = 0; i < iterator; i++)
                {
                    iterating2();
                }
                cout << "\nenter the damaged item ID you want to fix: ";
                cin >> id_confirm;

                for (int i = 0; i <= iterator; i++)
                {
                    if (id_confirm == id_code[i])
                    {
                        on_off = true;
                        cout << "\n The quantity before: [ " << amount[i] << " ]";
                        amount[i] = missing[i] + amount[i];
                        cout << "\n\n The quantity now: [ " << amount[i] << " ]\n";
                    }
                }
                if (on_off == false)
                {
                    cout << "\nInvalid Number! please insert the available ID";
                }
            } while (on_off == false);

            cout << "\n\n";
            for (int i = 1; i <= 65; i++)
            {
                cout << "*";
            }
            cout << "\n\n";

            break;
        case 4:
            cout << "\n\n";
            for (int i = 1; i <= 65; i++)
            {
                cout << "*";
            }
            cout << "\n\n";
            not_repeat = true;
            return stored();
            break;
        case 5:
            on_off = false;
            do
            {
                iterating2();
                cout << "\n1.) modify the brand name ";
                cout << "\n2.) modify the item name ";
                cout << "\n3.) modify the ID number ";
                cout << "\n\nYour choices: ";
                cin >> choice;
                switch (choice)
                {
                case 1:

                    on_off = false;
                    do
                    {
                        iterating2();
                        cout << "\nenter the item ID you want to edit: ";
                        cin >> id_confirm;

                        for (int i = 0; i <= iterator; i++)
                        {
                            if (id_confirm == id_code[i])
                            {
                                on_off = true;
                                cout << "Enter the new [ Brand ] name: ";
                                cin >> inserter;
                                brand[i] = inserter;
                            }
                        }
                        if (on_off == false)
                        {
                            cout << "\nInvalid Number! please insert the available ID";
                        }
                    } while (on_off == false);
                    cout << "\n\n";
                    for (int i = 1; i <= 65; i++)
                    {
                        cout << "*";
                    }
                    cout << "\n\n";
                    break;
                case 2:
                    on_off = false;
                    do
                    {
                        iterating2();
                        cout << "\nenter the item ID you want to edit: ";
                        cin >> id_confirm;

                        for (int i = 0; i <= iterator; i++)
                        {
                            if (id_confirm == id_code[i])
                            {
                                on_off = true;
                                cout << "Enter the new [ Item ] name: ";
                                cin >> inserter;
                                name[i] = inserter;
                            }
                        }
                        if (on_off == false)
                        {
                            cout << "\nInvalid Number! please insert the available ID";
                        }
                    } while (on_off == false);
                    cout << "\n\n";
                    for (int i = 1; i <= 65; i++)
                    {
                        cout << "*";
                    }
                    cout << "\n\n";
                    break;

                case 3:
                    on_off = false;
                    do
                    {
                        iterating2();
                        cout << "\nenter the ID you want to edit: ";
                        cin >> id_confirm;

                        for (int i = 0; i <= iterator; i++)
                        {
                            if (id_confirm == id_code[i])
                            {
                                on_off = true;
                                cout << "Enter the new [ ID ] code: ";
                                cin >> num;
                                id_code[i] = num;
                            }
                        }
                        if (on_off == false)
                        {
                            cout << "\nInvalid Number! please insert the available ID";
                        }
                    } while (on_off == false);
                    cout << "\n\n";
                    for (int i = 1; i <= 65; i++)
                    {
                        cout << "*";
                    }
                    cout << "\n\n";

                    break;
                default:
                    cout << "\n\n[ INVALID INPUT, PLEASE TRY AGAIN ] \n\n";
                    cout << "\n\n";
                    for (int i = 1; i <= 65; i++)
                    {
                        cout << "*";
                    }
                    cout << "\n\n";
                    on_off = false;
                    break;
                }

            } while (on_off == false);
            not_repeat = true;
            return modification();
        }
    }

    void clearInputBuffer()
    {
        //this is where we need to remove or clear the buffer input
        int c;
        while ((c = getchar()) != '\n' && c != false /* or EOF */)
            ;
    }

    void iterating()
    {
        //i separate this completely because i dont know... LOL

        for (int i = 0; i < iterator; i++)
        {
            cout << "\n\n**************************PRODUCT [ " << i << " ]************************** \n\n";
            cout << "Brand Name:: [ " << brand[i] << " ] ";
            cout << "\n Product Name:: [ " << name[i] << " ] ";
            cout << "\nThe Actual Amount of the Product/Item:: [ " << actual_amount[i] << " ] ";
            cout << "\nMissing Amount of the Product/Items:: [ " << missing[i] << " ] ";
            cout << "\nUnreturned/Barrowed Amount of the Product/Items:: [ " << unreturned[i] << " ] ";
            cout << "\nDamaged Amounts of the Product/Items:: [ " << damaged[i] << " ] ";
            cout << "\nThe Current Amount of The Product/Item:: [ " << amount[i] << " ] \n";
            cout << "ID Code:: [ " << id_code[i] << " ] \n\n";
            for (int j = 1; j <= 65; j++)
            {
                cout << "*";
            }
            cout << "\n\n";
        }
    }
    void iterating2()
    {
        //i made this function for reusable purposes
        for (int i = 0; i < iterator; i++)
        {
            cout << "\n------------------------------------------\n";
            cout << "\n\nID number: [ " << id_code[i] << " ] \n";
            cout << "Product/Item Brand: [ " << brand[i] << " ] \n";
            cout << "Product/Item Name: [ " << name[i] << " ] \n";
            cout << "Product/Item Quantity:: [ " << amount[i] << " ] \n";
            cout << "\n------------------------------------------\n";
        }
    }
};

int main(int argc, char *argv[])
{
    Inventory storage;
    storage.stored();
}