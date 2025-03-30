#include "linkedList.cpp"
#include <iostream>

int main()
{
    LList<int> list;
    list.insert(12, list.zeroth());
    Node<int> *p = list.first();

    for (int i = 0; i < 10; i++)
    {
        list.insert(i + 1, p);
        p = p->next;
    }
    list.print();

    Node<int> *sondan2 = list.nthToLas(2);

    std::cout << "sondan ikinci:\t" << sondan2->element << std::endl;

    bool hasLoop = list.hasLoop();
    std::cout << "Bu listede döngü " << (hasLoop ? "var" : "yok") << std::endl;

    list.reverse();
    std::cout << std::endl
              << "liste ters çevrildi:" << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << std::endl;

    LList<int> list2;
    list2.insert(31, list2.zeroth());
    Node<int> *p2 = list2.first();
    for (int i = 0; i < 5; i++)
    {
        list2.insert(i + 20, p2);
        p2 = p2->next;
    }
    list2.print();
    std::cout << std::endl;

    list.alternateWith(list2);
    list.print();

    

    return 0;
}