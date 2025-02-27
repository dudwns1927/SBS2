
#include <iostream>
#include <cstring>

using namespace std;



class String
{
private:
    int size;
    char* pointer;
    
public:    

    String()
    {   
        size = 0;        
        pointer = nullptr;
    }


    String(const char* str)
    {
        size = 0;
        pointer = nullptr;
        if (str != nullptr)
        {
            size = strlen(str);
            pointer = new char[size + 1];
            strcpy_s(pointer, size+1, str);
        }
    }

    ~String()
    {
        if (pointer != nullptr)
        {
            delete[] pointer;
        }
        
    }

    int length() const
    {
        return size;
    }

    void operator = (const char* word)
    {
        size = strlen(word) + 1;
        if (pointer == nullptr)
        {
            pointer = new char[size];
                
            for (int i = 0; i < size; i++)
            {
                pointer[i] = word[i];
            }
        }
        else
        {
            char* newPointer = new char[size];
            
            for (int i = 0; i < size; i++)
            {
                newPointer[i] = word[i];
            }

            delete[] pointer;

            pointer = newPointer;
        }
    }

    int Size() const
    {     
        return size - 1;
    }

    const char& operator [] (const int& index)
    {
        return pointer[index];
    }

    char& operator[](int index)
    {
        if (index >= 0 && index < size - 1)  // NULL 문자를 제외한 인덱스를 처리
        {
            return pointer[index];
        }
        throw out_of_range("Index out of range");
    }

   void print() const
   {
       if (pointer != nullptr)
       {
           cout << pointer << endl;
       }
       else
       {
           cout << "Empty String" << endl;
       }
   }
};

int main()
{
    
    String string;

    string = "Key";

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];        
    }

    cout << endl;
    
    string = "apple";

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];        
    }
    

    return 0;
}
