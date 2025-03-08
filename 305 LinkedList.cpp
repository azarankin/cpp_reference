#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head = nullptr;

public:
    LinkedList() : head{ nullptr } {}

    void append(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void printList() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void deleteValue(int value)
    {
        if (head == nullptr) return;

        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    int pop() {
        if (head == nullptr)
        {
            throw std::runtime_error("Cannot pop from an empty list.");
        }

        if (head->next == nullptr)
        {
            int value = head->data;
            delete head;
            head = nullptr;
            return value;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        int value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;

        return value;
    }



    ~LinkedList() {
        while (head != nullptr)
        {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }
};
