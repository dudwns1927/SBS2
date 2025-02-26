﻿
#include <iostream>

//#define SIZE 4

using namespace std;
template <typename T>


class Vector
{
private:
    int size;
    int capacity;

    T* container;


public:
    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }

    ~Vector()
    {
        delete[] container;
    }
    
    void resize(int newSize)
    {
        // 1. capacity에 새로운 size 값을 저장합니다.
        capacity = newSize;

        // 2. 새로운 포이널 변수를 생성해서 새롭게 만들어진
        //    메모리 공간을 가리키도록 합니다.
        T* newContainer = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화 합니다.
        for (int i = 0; i < capacity; i++)
        {
            newContainer[i] = NULL;
        }

        // 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줍니다.
        for (int i = 0; i < size; i++)
        {
            newContainer[i] = container[i];
        }

        // 5. 기존 배열의 메모리 해제합니다.
        if (container != nullptr)
        {
            delete[] container;
        }
        
        // 6. 기존에 배열을 가리키던 포인터 변수의 값을
        //    새로운 배열의 시작 주소로 가리킵니다.
        container = newContainer;

    }

    void push_back(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (size >= capacity)
        {
            resize(capacity * 2);
        }
        container[size++] = data;
    }

    void pop_back()
    {
        if (size <= 0)
        {
            cout << "vector is empty" << endl;
        }
        else
        {
            container[--size] = NULL;
           
        }
    }

    


    const int& Size()
    {
        return size;
    }

    const T& operator [] (const int& index)
    {
        return container[index];
    }
};

int main()
{
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);
    vector.push_back(50);

    for (int i = 0; i < vector.Size(); i++)
    {
        cout << vector[i] << " ";

    }



    return 0;
}
