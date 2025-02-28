
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

    const int Size() const
    {     
        return size - 1;
    }

    const char& operator [] (const int& index)
    {
        return pointer[index];
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

   void Append(const char* word)
   {
       int resize = size;

       size = size + strlen(word) + 1;

       char* newPointer = new char[size];

       for (int i = 0; i < resize; i++)
       {
           newPointer[i] = pointer[i];
       }

       for (int i = 0; i < strlen(word) + 1; i++)
       {
           newPointer[resize + i] = word[i];
       }
       
       if (pointer != nullptr)
       {
           delete[] pointer;
       }
       pointer = newPointer;      
   }

   long long Find(const char* word)
   {

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

    cout << endl;

    

    string.Append(" Four");
    string.Append(" x");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;
    cout << "string Size : " << string.Size() << endl;

    std::string name;
    name = "Alistar";
    cout << name.find("ar");

    return 0;
}
