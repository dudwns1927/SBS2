
#include <iostream>
#include <cstring>
#define SIZE 6

using namespace std;


template <typename KEY, typename VALUE>

class HashTable
{
private:
    struct node
    {
        KEY key;;
        VALUE value;

        node* next;
    };

    struct Bucket
    {
        int count;
        node* head;
    };

    Bucket bucket[SIZE];

public:    
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }
    
    template<typename T>
    int HashFuction(T key)
    {
        unsigned int hashIndex = (int)key % SIZE;


        return hashIndex;
    }

    template<>
    const int& HashFuction(const char* key)
    {
        int hash = 0;

        for (int i = 0; i < strlen(key); i++)
        {
            hash += key[i];
        }

        int hashIndex = hash % SIZE;

        return hashIndex;
    }
};

int main()
{
    

    return 0;
}
