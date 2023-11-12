#include <iostream>
#include <string>
#include <vector>

class MyCollection;

class MyPair
{
private:
    int id;
    std::string value;

public:
    MyPair(int i, const char *v) : id(i), value(v){};
    void Print() { std::cout << "id=" << id << " ,Value=" << value << std::endl; }
};

class MyCollection
{
private:
    std::vector<MyPair> vector;

public:
    void Add(MyPair &&other)
    {
        vector.insert(vector.end(), other);
    } // good

    void Add(int id, const char *value)
    {
        vector.insert(vector.end(), MyPair(id, value));
    } // bad

    void Print()
    {
        for (auto i : vector)
            i.Print();
    } // good
};

int main()
{
    MyCollection collection;
    collection.Add(1, "This is 1");         // Ask, don't tell;
    collection.Add(MyPair(2, "This is 2")); // Tell, don't ask
    collection.Print();
    return 0;
}