import std;
import LinkedList;

int main() {
    std::cout << "=== LinkedList demonstration ===" << std::endl << std::endl;

    // 1. Конструктор по умолчанию + push_tail и push_head
    std::cout << "1. Default constructor, push_tail, push_head:" << std::endl;
    LinkedList<int> list1;
    list1.push_tail(10); // Добавляем в конец
    list1.push_tail(30); // Добавляем в конец
    list1.push_head(5);  // Добавляем в начало
    std::cout << "list1 = " << list1 << std::endl;
    std::cout << "Size = " << list1.get_size() << std::endl << std::endl;

    // 2. Конструктор с параметрами (генерация случайных чисел)
    std::cout << "2. Random constructor:" << std::endl;
    LinkedList<int> randList(5, 1, 10); // 5 чисел от 1 до 10
    std::cout << "randList = " << randList << std::endl << std::endl;

    // 3. Перегруженный push_tail (добавление списка)
    std::cout << "3. push_tail(LinkedList):" << std::endl;
    LinkedList<int> list2;
    list2.push_tail(40);
    list2.push_tail(50);
    list1.push_tail(list2); // Добавляем list2 в конец list1
    std::cout << "list1 after push_tail(list2) = " << list1 << std::endl << std::endl;

    // 4. Перегруженный push_head (добавление списка)
    std::cout << "4. push_head(LinkedList):" << std::endl;
    LinkedList<int> list3;
    list3.push_head(1);
    list3.push_head(2);
    list1.push_head(list3); // Добавляем list3 в начало list1
    std::cout << "list1 after push_head(list3) = " << list1 << std::endl << std::endl;

    // 5. pop_heads и pop_tails
    std::cout << "5. pop_heads and pop_tails:" << std::endl;
    list1.pop_heads(); // Удаляем начало
    list1.pop_tails(); // Удаляем конец
    std::cout << "list1 after pop_heads and pop_tails = " << list1 << std::endl << std::endl;

    // 6. delete_node (удаление всех элементов с заданным значением)
    std::cout << "6. delete_node:" << std::endl;
    LinkedList<int> list4;
    list4.push_tail(7);
    list4.push_tail(8);
    list4.push_tail(7);
    list4.push_tail(9);
    std::cout << "list4 = " << list4 << std::endl;
    list4.delete_node(7); // Удаляем все семерки
    std::cout << "list4 after delete_node(7) = " << list4 << std::endl << std::endl;

    // 7. operator[] (доступ по индексу)
    std::cout << "7. operator[]:" << std::endl;
    std::cout << "list4[0] = " << list4[0] << std::endl; // Чтение
    list4[0] = 100; // Запись
    std::cout << "list4 after list4[0] = 100: " << list4 << std::endl << std::endl;

    // 8. Проверка исключений
    std::cout << "8. Exception check:" << std::endl;
    try {
        std::cout << "Trying list4[100]..." << std::endl;
        std::cout << list4[100] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    // 9. Правило Трёх (конструктор копирования и оператор присваивания)
    std::cout << "9. Copy and assignment:" << std::endl;
    LinkedList<int> copyList = list1; // Конструктор копирования
    std::cout << "copyList = " << copyList << std::endl;

    LinkedList<int> assignList;
    assignList.push_tail(999);
    assignList = list1; // Оператор присваивания
    std::cout << "assignList = " << assignList << std::endl << std::endl;

    // 10. Задача 1: Проверка на цикл (Алгоритм Флойда)
    std::cout << "10. Task 1: Cycle check:" << std::endl;
    std::cout << "Has cycle in list1? " << (has_cycle(list1) ? "Yes" : "No") << std::endl;

    return 0;
}