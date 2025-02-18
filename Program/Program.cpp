
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
        Node* current = head, tail;
        
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    /*
    ~DoubleLinkedList()
    {    
        while (head != nullptr)
        {
            pop_front()
        }
    }*/

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;
        }

        size++;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next - newNode;
            newNode->previous = tail;
            
            tail = newNode;
        }

        size++;
    }

    void show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";

            currentNode = currentNode->next;
        }
    }


    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                deleteNode->next->previous = nullptr;

                head = head->next;
            }

            delete deleteNode;

            size--;
        }
    }

};






int main()
{
    DoubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.push_front(30);
    doubleLinkedList.push_front(20);
    doubleLinkedList.push_front(10);

    doubleLinkedList.pop_front();
    doubleLinkedList.pop_front();
    doubleLinkedList.pop_front();
    doubleLinkedList.pop_front();

    doubleLinkedList.push_back(10);
    doubleLinkedList.push_back(20);
    doubleLinkedList.push_back(30);
    

    doubleLinkedList.show();


    return 0;
}
