#include "BinaryTree.hpp"
#include <conio.h>

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key - 48;
}

int main_menu()
{
    std::cout << "[1] Insert" << std::endl;
    std::cout << "[2] Delete" << std::endl;
    std::cout << "[3] Print" << std::endl;
    std::cout << "[4] Exit" << std::endl;

    while (true)
    {
        int key = get_key();
        if (key == 1 || key == 2 || key == 3 || key == 4)
            return key;
    }
}

int main()
{
    BinaryTree<int> tree;
    while (true)
    {
        int key = main_menu();
        system("cls");
        if (key == 4)
        {
            return 0;
        }
        else if (key == 1)
        {
            std::cout << "Add value: ";
            std::cin >> key;
            tree.insert(key);
        }
        else if (key == 2)
        {
            std::cout << "Delete value: ";
            std::cin >> key;
            tree.erase(key);
        }
        else if (key == 3)
        {
            tree.print();
            system("pause");
        }
        system("cls");
    }
}