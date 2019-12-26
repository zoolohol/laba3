//Copyright 2019 <LinkIvan333>
#include <iostream>
#include "SharedPtr.h"

using std::cout;
using std::cin;

int main() {
    int x = 2;
    int y = 4;
    int z = 8;

    SharedPtr<int> ptr1(&x);
    SharedPtr<int> ptr2(&y);
    SharedPtr<int> ptr3(ptr2);
    SharedPtr<int> ptr4;
        cout << "\nx = " << x;
        cout << "\ny = " << y;
        cout << "\nz = " << z;
        cout << "\nPtr1 = " << *ptr1.get() << " cnt = " << *ptr1.use_count();
        cout << "\nPtr2 = " << *ptr2.get() << " cnt = " << *ptr2.use_count();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        cout << "\n\nPtr3 был скопирован из Ptr2. Теперь удалим "
                "Ptr2 для проверки"
        << " количества ссылок на y...\nУдаляем PTR2...";
        ptr2.reset();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        ptr1.swap(ptr3);
        cout << "\n\nСвапаем Ptr1 и Ptr3 :";
        cout << "\nPtr1 = " << *ptr1.get();
        cout << "\nPtr3 = " << *ptr3.get();

        cout << "\n\nОбъявляем Ptr3 для переменной Z:\n";
        ptr3.reset(&z);
        cout << "Ptr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        cout << "\n\nПрисваиваем Ptr4 значение Ptr3:";
        ptr4 = ptr3;
        cout << "\nPtr4 = " << *ptr4.get() << " cnt = " << *ptr4.use_count();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count()
        << std::endl;
    }

