export module LinkedList;
import std;

// Узел списка
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

export template <typename T>
class LinkedList {
private:
    Node<T>* head; //первый элемент
    Node<T>* tail; //последний элемент
    int size;      // Количество элементов

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования 
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->data);
            current = current->next;
        }
    }

    // Оператор присваивания 
    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this; 

        // 1. Очищаем текущий список
        while (head != nullptr) {
            pop_head();
        }

        // 2. Копируем элементы из другого списка
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->data);
            current = current->next;
        }
        return *this;
    }

    // Деструктор 
    ~LinkedList() {
        while (head != nullptr) {
            pop_head();
        }
    }

    int get_size() const {
        return size;
    }

    // Добавление элемента в конец списка
    void push_tail(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Добавление элемента в начало списка
    void push_head(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Удаление элемента из начала списка
    void pop_head() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; // Если список стал пустым
        }
        delete temp;
        size--;
    }

    // Удаление элемента из конца списка
    void pop_tail() {
        if (tail == nullptr) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr; // Если список стал пустым
        }
        delete temp;
        size--;
    }

    // Удаление всех элементов с заданным значением 
    void delete_node(const T& value) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                Node<T>* toDelete = current;
                if (current->prev) current->prev->next = current->next;
                else head = current->next;

                if (current->next) current->next->prev = current->prev;
                else tail = current->prev;

                current = current->next;
                delete toDelete;
                size--;
            }
            else {
                current = current->next;
            }
        }
    }

    // Доступ по индексу
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Доступ по индексу 
    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Вывод списка на печать
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        os << "[ ";
        Node<T>* current = list.head;
        int count = 0;

        // Выводим ровно size элементов, чтобы не зависнуть при цикле
        while (current != nullptr && count < list.size) {
            os << current->data;
            if (count < list.size - 1) os << " <-> ";
            current = current->next;
            count++;
        }

        // Если после вывода size элементов current всё ещё не nullptr - значит, есть цикл
        if (current != nullptr) {
            os << " <-> ... (cycle detected)";
        }

        os << " ]";
        return os;
    }

    // Добавление другого списка в конец текущего
    void push_tail(const LinkedList<T>& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->data);
            current = current->next;
        }
    }

    // Добавление другого списка в начало текущего
    void push_head(const LinkedList<T>& other) {
        // Идем с конца другого списка, чтобы сохранить правильный порядок
        Node<T>* current = other.tail;
        while (current != nullptr) {
            push_head(current->data); 
            current = current->prev;
        }
    }

    // Конструктор случайных значений 
    LinkedList(int count, T min, T max) : head(nullptr), tail(nullptr), size(0) {
        if (count < 0) throw std::invalid_argument("Count cannot be negative");
        if (min > max) throw std::invalid_argument("Min cannot be greater than max");

        static std::random_device rd;
        static std::mt19937 gen(rd());

        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dist(min, max);
            for (int i = 0; i < count; i++) {
                push_tail(dist(gen));
            }
        }
        else if constexpr (std::is_floating_point<T>::value) {
            std::uniform_real_distribution<T> dist(min, max);
            for (int i = 0; i < count; i++) {
                push_tail(dist(gen));
            }
        }
    }

    // Метод для получения головы списка (нужен для внешних функций)
    Node<T>* get_head() const {
        return head;
    }

};

// Задача 1
export template <typename T>
bool has_cycle(const LinkedList<T>& list) {
    // Получаем голову через публичный метод
    Node<T>* slow = list.get_head();
    Node<T>* fast = list.get_head();

    if (slow == nullptr) return false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Есть цикл
        }
    }
    return false; // Нет цикла
}