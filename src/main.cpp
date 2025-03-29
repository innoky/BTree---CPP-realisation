#include <iostream>
#include "BTree.hpp"

int main() {
    BTree t(3); 

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Обход дерева:\n";
    t.traverse();
    std::cout << std::endl;

    int key = 6;
    if (t.search(key))
        std::cout << "Ключ " << key << " найден\n";
    else
        std::cout << "Ключ " << key << " не найден\n";

    return 0;
}