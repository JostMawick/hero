#include <iostream>

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
    Potion(int h, int a) : healthBoost(h), attackBoost(a) {}
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
    virtual std::string getName()
    {
        return name;
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
    void incrementCount()
    {
        memberCount++;
    }
    void decrementCount()
    {
        if (memberCount > 0)
        {
            memberCount--;
        }
    }
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
    MysticalTattoo soulMark;
    CoreStats stats;
    Guild *guild = nullptr;
    Weapon *weapon = nullptr;

public:
    Hero(int id, std::string name, int damage, std::string tattoo, int boost, int h, int m)
        : GameObject(id),
          heroName(name),
          attackDamage(damage),
          soulMark(tattoo, boost),
          stats(h + boost, m)
    {
    }

    std::string getName()
    {
        return heroName;
    }

    void joinGuild(Guild *g)
    {
        guild = g;
        guild->incrementCount();
        std::cout << heroName << "joined guild" << guild->getGuildName() << "!\n";
    }

    void leaveGuild()
    {
        if (guild != nullptr)
        {
            std::cout << heroName << "left guild" << guild->getGuildName() << "!\n";
            guild->decrementCount();
            guild = nullptr;
        }
    }

    void equipWeapon(Weapon *w)
    {
        weapon = w;
        std::cout << heroName << "equipped " << weapon->getName() << "!\n";
    }

    void unequipWeapon()
    {
        if (weapon != nullptr)
        {
            std::cout << heroName << "unequipped " << weapon->getName() << "!\n";
            weapon = nullptr;
        }
    }

    void attack()
    {
        if (weapon != nullptr)
        {
            weapon->attack();
        }
        else
        {
            std::cout << heroName << "attacks with bare hands! damage: " << attackDamage << "\n";
        }
    }

    void usePotion(Potion p)
    {
        stats.modifyHealth(p.getHealthBoost());
        attackDamage += p.getAttackBoost();
        std::cout << heroName << " used a potion! Health: " << stats.getHealth() << " Attack: " << attackDamage << "\n";
    }
};

int main(int, char **)
{

    Guild myGuild("Dragon Slayers", 5);
    Sword mySword("Excalibur", 30, 15);
    Potion myPotion(50, 10);

    // Create hero on heap to show that guild lives after he dies
    Hero *hero = new Hero(1, "Arthas", 10, "Flamme", 20, 100, 50);

    hero->joinGuild(&myGuild);
    hero->equipWeapon(&mySword);

    hero->attack();
    hero->usePotion(myPotion);
    hero->attack();

    hero->leaveGuild();
    delete hero;
    hero = nullptr;

    std::cout << "\n--- After the heros death ---\n";
    std::cout << "Guild '" << myGuild.getGuildName()
              << "' guild has " << myGuild.getMemberCount() << " members!\n";
    std::cout << "Sword '" << mySword.getName()
              << "' lies still on the ground!\n";
}
