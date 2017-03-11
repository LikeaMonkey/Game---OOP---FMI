#include<iostream>
#include<cstring>

using namespace std;

class Hero
{
private:
    char name[101];
    unsigned int health;
    unsigned int level;
    unsigned int experience;
    int strength;
    int speed;
    int intellect;

public:
    Hero()    {

        health = 0;
        level = 0;
        experience = 0;
        strength = 0;
        speed = 0;
        intellect = 0;
    }
    Hero(char heroName[] , unsigned int heroHealth , unsigned int heroLevel , unsigned int heroExperience , int heroStrength , int heroSpeed , int heroIntellect)
    {
        strcpy(name,heroName);
        health = heroHealth;
        level = heroLevel;
        experience = heroExperience;
        strength = heroStrength;
        speed = heroSpeed;
        intellect = heroIntellect;
    }
    Hero(const Hero& h_copy)
    {
        strcpy(name , h_copy.getName());
        health = h_copy.getHealth();
        level = h_copy.getLevel();
        experience = h_copy.getExperience();
        strength = h_copy.getStrength();
        speed = h_copy.getSpeed();
        intellect = h_copy.getIntellect();
    }

    void setName(char heroName[])
    {
        strcpy(name,heroName);
    }
     void setHealth(unsigned int heroHealth)
    {
        health = heroHealth;
    }
     void setLevel(unsigned int heroLevel)
    {
        level = heroLevel;
    }
     void setExperience(unsigned int heroExperience)
    {
        experience = heroExperience;
    }
     void setStrength(int heroStrength)
    {
        strength = heroStrength;
    }
     void setSpeed(int heroSpeed)
    {
        speed = heroSpeed;
    }
     void setIntellect(int heroIntellect)
    {
        intellect = heroIntellect;
    }

    const char* getName()const
    {
        return name;
    }
    unsigned int getHealth()const
    {
        return health;
    }
    unsigned int getLevel()const
    {
        return level;
    }
    unsigned int getExperience()const
    {
        return experience;
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
        cout<<"Name:"<<name<<endl;
        cout<<"Health:"<<getHealth()<<endl;
        cout<<"Level:"<<getLevel()<<endl;
        cout<<"Experience:"<<getExperience()<<endl;
        cout<<"Strength:"<<getStrength()<<endl;
        cout<<"Speed:"<<getSpeed()<<endl;
        cout<<"Intellect:"<<getIntellect()<<endl;
    }
};

int main()
{
    Hero h_1;

    h_1.setName("Vayne");
    h_1.setHealth(450);
    h_1.setLevel(1);
    h_1.setExperience(1);
    h_1.setStrength(25);
    h_1.setSpeed(375);
    h_1.setIntellect(1000);

    cout<<"Name:"<<h_1.getName()<<endl;
    cout<<"Health:"<<h_1.getHealth()<<endl;
    cout<<"Level:"<<h_1.getLevel()<<endl;
    cout<<"Experience:"<<h_1.getExperience()<<endl;
    cout<<"Strength:"<<h_1.getStrength()<<endl;
    cout<<"Speed:"<<h_1.getSpeed()<<endl;
    cout<<"Intellect:"<<h_1.getIntellect()<<endl;
    cout<<endl;
    h_1.print();

    Hero h_2("Evelyn",380,1,1,30,400,550);

    cout<<endl;
    h_2.print();

    Hero h_3(h_2);
    cout<<endl;
    h_3.print();

    return 0;
}
