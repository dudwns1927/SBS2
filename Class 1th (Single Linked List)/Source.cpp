
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
            Node* currentNode = head;

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

    void push_back(T data)
    {
        Node* newNode = new Node;

        if (head == nullptr)
        {
            head = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }
        else
        {
            Node* currentNode = head;

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

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            size--;
        }
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

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;


            if (size == 1)
            {
                head = deleteNode->next;

                delete deleteNode;
            }
            else
            {
                while (deleteNode->next != nullptr)
                {
                    previousNode = deleteNode;
                    deleteNode = deleteNode->next;
                }

                previousNode->next = deleteNode->next;

                delete deleteNode;
            }
        }
        size--;
    }

    const int size()
    {
        return size;
    }

    ~SingleLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

};




int main()
{
    SingleLinkedList<int> singleLinkedList;

    singleLinkedList.push_front(10);
    singleLinkedList.push_front(20);
    singleLinkedList.push_back(5);
    singleLinkedList.push_back(30);

    singleLinkedList.pop_front();
    singleLinkedList.pop_back();

  //  cout << "Linked List is Size : " << singleLinkedList.size() << endl;

    singleLinkedList.show();


    return 0;
}
