import std;
import LinkedList;

int main() {
    // 1. Тест обычного списка
    LinkedList<int> list;
    list.push_tail(10);
    list.push_tail(20);
    list.push_tail(30);

    std::cout << "List: " << list << std::endl;
    std::cout << "Has cycle? " << (has_cycle(list) ? "Yes" : "No") << std::endl;

    // 2. Тест копирования (Правило Трёх)
    LinkedList<int> list2 = list;
    std::cout << "Copy: " << list2 << std::endl;

    return 0;
}