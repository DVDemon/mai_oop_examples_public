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

struct PairGenerator {
    MyPair createPair(){
        return MyPair(1,"some value");
    }
};

class MyCollection
{
private:
    std::vector<MyPair> vector;

public:
    void Add(MyPair &&other)
    {
        vector.push_back( other);
    } // good

    void Add(PairGenerator& pg)
    {
        vector.push_back(pg.createPair());
    } // bad

    void Print()
    {
        for (auto i : vector)
            i.Print();
    } // good
};

int main()
{
    PairGenerator pg;
    MyCollection collection;
    collection.Add(pg);         // Ask, don't tell;
    collection.Add(MyPair(2, "This is 2")); // Tell, don't ask
    collection.Print();
    return 0;
}