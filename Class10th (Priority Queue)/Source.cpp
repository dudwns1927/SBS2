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

    void push(T data)
    {
        if (index + 1 >= SIZE)
        {
            cout << "priorityz" << endl;

        }

        else
        {

            container[++index] = data;

            int child = index;
            int parent = child / 2;

            while (child > 1)
            {
                if (container[parent] < container[child])
                {
                    std::swap(container[parent], container[child]);

                }
                child = parent;
                parent = child / 2;
            }

        }
    }

    const T& top()
    {
        return container[1];
    }

    void pop()
    {
        if (index <= 0)
        {
            cout << "Priority Queue is Empty" << endl;
        }
        else
        {
            container[1] = container[index];

            container[index--] = NULL;

            int parent = 1;

            while (parent * 2 <= index)
            {
                int child = parent * 2;

                if (container[child] < container[child + 1])
                {
                    child++;
                }
                if (container[child] < container[parent])
                {
                    break;
                }

                else
                {
                    std::swap(container[parent], container[child]);

                    parent = child;
                }
            }
        }
    }
    const bool empty()
    {
        if (index <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{


    PriorityQueue<int> priorityQueue;

    // 우선순위 큐에 데이터 추가
    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(15);
    priorityQueue.push(30);
    priorityQueue.push(5);


    while (priorityQueue.empty() == false)
    {
        cout << priorityQueue.top() << endl;

        priorityQueue.pop();
    }

    /*
    // 가장 큰 값 출력
    cout << "Top element: " << priorityQueue.top() << endl; // 30

    // pop해서 가장 큰 값 제거
    priorityQueue.pop();

    // 새로운 top 출력
    cout << "Top element after pop: " << priorityQueue.top() << endl; // 20

    // 큐가 비어있는지 확인
    cout << "Is the queue empty? " << (priorityQueue.empty() ? "Yes" : "No") << endl;
    */

    /*
    priorityQueue.push(30);
    priorityQueue.push(2);
    priorityQueue.push(77);
    priorityQueue.push(15);

    int size = priorityQueue.size();
    for (int i = 0; i < size; ++i) {
        std::cout << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }

    while (priorityQueue.empty() == false)
    {
        cout << priorityQueue.top() << endl;

        priorityQueue.pop();
    }
    */

    return 0;
}
