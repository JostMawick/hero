#include <iostream>

class GameObject
{
private:
    int entityID = 0;

public:
    GameObject(int id) : entityID(id) {}
    int getEntityID()
    {
        return entityID;
    }
};

class Hero : public GameObject
{
private:
    std::string heroName = "";
    int attackDamage = 0;

public:
    Hero(int id, std::string name, int damage) : GameObject(id), heroName(name), attackDamage(damage) {}
    std::string getName()
    {
        return heroName;
    }
};

class CoreStats
{
private:
    int health = 0;
    int mana = 0;

public:
    CoreStats(int h, int m)
    {
        health = h;
        mana = m;
    }
    void modifyHealth(int h)
    {
        health += h;
    }
    void modifyMana(int m)
    {
        mana += m;
    }
    int getHealth()
    {
        return health;
    }
    int getMana()
    {
        return mana;
    }
};

class Potion
{
private:
    int healthBoost = 0;
    int attackBoost = 0;

public:
    int getHealthBoost()
    {
        return healthBoost;
    }
    int getAttackBoost()
    {
        return attackBoost;
    }
};

class Weapon
{
protected:
    std::string name = "";
    int baseDamage = 0;

public:
    Weapon(std::string n, int d) : name(n), baseDamage(d) {}
    virtual void attack()
    {
        std::cout << "Attack\n";
    }
};

class Sword : public Weapon
{
private:
    int sharpness = 0;

public:
    Sword(std::string n, int d, int s) : Weapon(n, d), sharpness(s) {}
    void attack() override
    {
        std::cout << "Slash with " << name << "\n damage: " << (baseDamage + sharpness) << "\n";
    }
};

class Guild
{
private:
    std::string guildName = "";
    int memberCount = 0;

public:
    Guild(std::string name, int count) : guildName(name), memberCount(count) {}
    std::string getGuildName()
    {
        return guildName;
    }
    int getMemberCount()
    {
        return memberCount;
    }
    // Member logic still missing
};

class MysticalTattoo
{
private:
    std::string tattooName = "";
    int healthBoost = 0;

public:
    MysticalTattoo(std::string name, int boost) : tattooName(name), healthBoost(boost) {}
    std::string getTattooName()
    {
        return tattooName;
    }
    int getHealthBoost()
    {
        return healthBoost;
    }
};

int main(int, char **)
{
    std::cout << "Hello, from hero!\n";
}
