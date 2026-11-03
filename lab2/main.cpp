import std;
import LinkedList;

int main() {
    LinkedList<int> list1;
    list1.push_tail(10);
    list1.push_tail(20);

    std::cout << "List1: " << list1 << std::endl;

    // Тест
    LinkedList<int> list2 = list1;
    std::cout << "List2 (copy of List1): " << list2 << std::endl;

    // Тест 
    LinkedList<int> list3;
    list3.push_tail(99);
    list3 = list1;
    std::cout << "List3 (assigned List1): " << list3 << std::endl;

    return 0;
}