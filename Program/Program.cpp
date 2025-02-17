
#include <iostream>

using namespace std;

template<typename T>


class DoubleLinkedList
{
private:
    int size;
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;

public:
    DoubleLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~DoubleLinkedList()
    {

    }

    int getsize() const
    {
        return size;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        if (head == nullptr)
        {
            head = newNode;

            newNode->data = data;
            newNode->next = nullptr; //시작주소를 가리킨다.
        }
        else if (tail == nullptr)
        {
            tail = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }
        else
        {
            Node* currentNode = head;
            Node* currentNode = tail;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }

        size++;
    }
};






int main()
{
    DoubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.push_front(10);
    doubleLinkedList.push_front(20);


    return 0;
}
