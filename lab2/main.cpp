import std;
import LinkedList;

int main() {
    LinkedList<int> list;
    list.push_tail(10);
    list.push_head(5);
    list.push_tail(20);

    std::cout << "List: " << list << std::endl;
    std::cout << "Size: " << list.get_size() << std::endl;
    std::cout << "Element at index 1: " << list[1] << std::endl;

    list[1] = 99; // Меняем значение
    std::cout << "After list[1] = 99: " << list << std::endl;

    list.pop_head();
    std::cout << "After pop_head: " << list << std::endl;

    list.pop_tail();
    std::cout << "After pop_tail: " << list << std::endl;

    return 0;
}