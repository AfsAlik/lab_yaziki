#include <iostream>
#include <string>

using namespace std;

// Шаблон узла односвязного списка
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

// Шаблон класса односвязного списка
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Добавление элемента в конец списка
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Удаление элемента по значению
    bool remove(const T& value) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    // Поиск элемента
    bool contains(const T& value) const {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // Вывод всех элементов
    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Получение размера списка
    int getSize() const { return size; }

    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Структура для хранения данных об автобусе
struct Bus {
    string number;
    string driver;
    int route;

    bool operator==(const Bus& other) const {
        return number == other.number;
    }

    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Bus " << bus.number  
           << "\nDriver: " << bus.driver 
           << "\nRoute: " << bus.route << "\n";
        return os;
    }
};

// Функции для работы с автобусами
void moveBus(SinglyLinkedList<Bus>& from, SinglyLinkedList<Bus>& to) {
    string number;
    cout << "Enter bus number (e.g., A1): ";  
    cin >> number;

    Bus target{number, "", 0};
    if (from.contains(target)) {
        from.remove(target);
        to.push_back(target);
        cout << "Bus moved!\n";  
    } else {
        cout << "Bus not found!\n";  
    }
}

int main() {
    SinglyLinkedList<Bus> inDepot;
    SinglyLinkedList<Bus> onRoute;

    // Initial data
    inDepot.push_back({"A1", "Ivanov A.A.", 5});  
    inDepot.push_back({"B2", "Petrov B.B.", 12});

    while (true) {
        cout << "\n1 - Departure\n"          
             << "2 - Return\n"               
             << "3 - List in depot\n"       
             << "4 - List on route\n"       
             << "0 - Exit\n> ";             

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                moveBus(inDepot, onRoute);
                break;
            case 2:
                moveBus(onRoute, inDepot);
                break;
            case 3:
                cout << "\nIn depot (" << inDepot.getSize() << "):\n";  
                inDepot.print();
                break;
            case 4:
                cout << "\nOn route (" << onRoute.getSize() << "):\n";  
                onRoute.print();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid input!\n";  
        }
    }
}