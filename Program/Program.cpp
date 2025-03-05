#include <iostream>
#include <queue>

#define SIZE 8

using namespace std;

template<typename T>


class PriorityQueue
{
private:
    int index;
    T container[SIZE];

public:
    PriorityQueue()
    {
        index = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    ~PriorityQueue()
    {

    }
};

int main()
{
    priority_queue<int> priorityQueue;

    //priorityQueue.push(30);
    //priorityQueue.push(2);
    //priorityQueue.push(77);
    //priorityQueue.push(15);
    //
    //int size = priorityQueue.size();  
    //for (int i = 0; i < size; ++i) {
    //    std::cout << priorityQueue.top() << std::endl;
    //    priorityQueue.pop(); 
    //}
    //
    //while (priorityQueue.empty() == false)
    //{
    //    cout << priorityQueue.top() << endl;
    //
    //    priorityQueue.pop();
    //}

    return 0;
}
