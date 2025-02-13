
#include <iostream>

using namespace std;

template<typename T>

class SingleLinkedList
{

private:
    int size;
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;    

public:

    SingleLinkedList()
    {
        size = 0;
        head = nullptr;
    }


    ~SingleLinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
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
        else
        {
            newNode->data = data;
            newNode->next = head;

            head = newNode;
        }

        size++;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;
        
        if (head == nullptr)
        {
            head = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }

    }

    void printList() const
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};




int main()
{
    SingleLinkedList<int> slngleLinkedList;

    slngleLinkedList.push_front(10);
    slngleLinkedList.push_front(20);

    slngleLinkedList.push_back(10);
    slngleLinkedList.push_back(20);

    cout << "List: ";  slngleLinkedList.printList();
    cout << "Size: " << slngleLinkedList.getsize() << endl;
    

    return 0;
}
