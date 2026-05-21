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
    PlayerClass(int id) : instanceID(id) {}
};

class Hero : public PlayerClass
{
private:
    CoreStats stats;

public:
    Hero(int id) : PlayerClass(id) {}
};

int main(int, char **)
{
    std::cout << "Hello, from hero!\n";
}
