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

    ~LinkedList() {}

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
        while (current != nullptr) {
            os << current->data;
            if (current->next != nullptr) os << " <-> ";
            current = current->next;
        }
        os << " ]";
        return os;
    }
};