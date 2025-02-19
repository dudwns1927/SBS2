
#include <iostream>

using namespace std;

template <typename T>



class CircleLinkedList
{
private:
    struct Node 
    {
        T data;
        Node* next;
    };

    int size;
    Node* head;

public:
    CircleLinkedList() 
    {
        size = 0;
        head = nullptr;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {        
            newNode->next = head->next;

            head->next = newNode;

            head = newNode;
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
};

int main()
{
    CircleLinkedList<int> circleLinkedList;

    circleLinkedList.push_back(10);
    circleLinkedList.push_back(20);
    circleLinkedList.push_back(30);

    circleLinkedList.show();

    return 0;
}
