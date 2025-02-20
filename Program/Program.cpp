
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


    ~CircleLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
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

    void push_front(T data)
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
        }

        size++;
    }

    void pop_back()
    {

    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {          
            Node* deleteNode = head->next;

            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                head->next = deleteNode->next;
            }
            
            size--;
        }
        

    }

    void show()
    {
        if (head != nullptr)
        {
            Node* currentNode = head->next;

            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << " ";

                currentNode = currentNode->next;
            }
        }       
    }


    const int& Size()
    {
        return size;
    }

};

int main()
{
    CircleLinkedList<int> circleLinkedList;

    circleLinkedList.push_back(10);
    circleLinkedList.push_back(20);
    circleLinkedList.push_back(30);

    circleLinkedList.push_front(5);
    circleLinkedList.push_front(1);

    //circleLinkedList.pop_front();
    //circleLinkedList.pop_front();

    
    
    circleLinkedList.show();

    return 0;
}
