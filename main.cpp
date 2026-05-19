#include <iostream>

class CoreStats
{
private:
    int health = 100;
    int attackPoints = 0;

public:
    void modifyHealth(int val)
    {
        health = val;
    }
};

class PlayerClass
{
private:
    int instanceID = 0;

public:
    int getID()
    {
        return instanceID;
    }
};

class Hero : public PlayerClass
{
private:
    CoreStats stats;
};

int main(int, char **)
{
    std::cout << "Hello, from hero!\n";
}
