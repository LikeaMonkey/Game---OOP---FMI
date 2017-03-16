#include<iostream>

using namespace std;

class Rune
{
private:
    int strength;
    int speed;
    int intellect;
public:
    Rune()
    {
        strength = 0;
        speed = 0;
        intellect = 0;
    }
    Rune(int runeStrength , int runeSpeed , int runeIntellect)
    {
        strength = runeStrength;
        speed = runeSpeed;
        intellect = runeIntellect;
    }
    Rune(Rune const &runeCopy)
    {
        strength = runeCopy.strength;
        speed = runeCopy.speed;
        intellect = runeCopy.intellect;
    }

    void setStrength(int runeStrength)
    {
        strength = runeStrength;
    }
    void setSpeed(int runeSpeed)
    {
        speed = runeSpeed;
    }
    void setIntellect(int runeIntellect)
    {
        intellect = runeIntellect;
    }

    int getStrength()const
    {
        return strength;
    }
    int getSpeed()const
    {
        return speed;
    }
    int getIntellect()const
    {
        return intellect;
    }

    void print()
    {
        cout<<"Strength : "<< getStrength()<<endl;
        cout<<"Speed : "<< getSpeed()<<endl;
        cout<<"Intellect : "<< getIntellect()<<endl;
    }

    Rune& operator=(const Rune &obj)
    {
        this->strength = obj.strength;
        this->speed = obj.speed;
        this->intellect = obj.intellect;

        return *this;
    }
};

class Inventory
{
private:
    Rune* runes;
    unsigned current;
    int capacity;
public:
    Inventory()
    {
        runes = new Rune[10];
        current = 0;
        capacity = 10;
    }
    Inventory(Rune * invRunes,unsigned invCurrent,int invCapacity)
    {
        delete runes;
        runes = new Rune[invCapacity];

        for(int i = 0; i < invCurrent;i++)
        {
            runes[i] = invRunes[i];
        }

        current = invCurrent;
        capacity = invCapacity;
    }
    Inventory(Inventory const & invCopy)
    {
        delete runes;
        runes = new Rune[invCopy.capacity];
        for(int i = 0; i < invCopy.current;i++)
        {
            runes[i] = invCopy.runes[i];
        }

        current = invCopy.current;
        capacity = invCopy.capacity;
    }

    void invResize()
    {
        Rune* _runes = new Rune[capacity];
        for(int i = 0; i < current ;i++)
        {
            _runes[i] = runes[i];
        }
        delete runes;
        capacity = capacity*2;
        Rune* runes = new Rune[capacity];
        for(int i = 0; i < current ;i++)
        {
            runes[i] = _runes[i];
        }
        delete _runes;
    }
    void add(Rune const& newRune)
    {
        runes[current+1] = newRune;
    }

    ~Inventory()
    {
        delete runes;
    }
};

int main()
{
    Rune blackSnake(10,10,40);
    blackSnake.print();

    Rune * redDanger = new Rune[3];

    redDanger[0].setStrength(20);
    redDanger[0].setSpeed(15);
    redDanger[0].setIntellect(5);

    redDanger[1].setStrength(30);
    redDanger[1].setSpeed(25);
    redDanger[1].setIntellect(10);

    redDanger[2].setStrength(40);
    redDanger[2].setSpeed(35);
    redDanger[2].setIntellect(15);

    Inventory pouch;
    Inventory bag(redDanger,3,10);
    Inventory bigBag(bag);

    bag.invResize();
    bag.add(blackSnake);

    return 0;
}
