#include<iostream>

using namespace std;

class Gold
{
private:
    int nume;
    int denom;
public:
    Gold()
    {
        nume = 1;
        denom = 1;
    }
    Gold(Gold const& obj)
    {
        nume = obj.nume;
        denom = obj.denom;
        int g = gcd();
        nume /= g;
        denom /= g;
    }
    Gold(int objNume , int objDenom)
    {
        nume = objNume;
        if(objDenom == 0)
        {
            denom = 1;
        }
        else
        {
            if(nume == 0)
            {
                denom = 0;
            }
            else denom = objDenom;
        }
        int g = gcd();
        nume /= g;
        denom /= g;
    }

    void setNume(int objNume)
    {
        nume = objNume;
    }
    void setDenom(int objDenom)
    {
        if(objDenom == 0)
        {
            denom = 1;
        }
        else
        {
            denom = objDenom;
        }

    }

    int getNume()const
    {
        return nume;
    }
    int getDenom()const
    {
        return denom;
    }

    void print()const
    {
        cout<<getNume()<<"/"<<getDenom()<<endl;
    }

    int gcd()const
    {
        int a = getNume();
        int b = getDenom();
        while (a != b)
            if (a > b)
                a -= b;
            else
                b -= a;
        return a;
        /*
        if(a<b)
        std::swap(a,b);
        if(b==0)
        return a;
        return (b,a%b);
        */
    }

    Gold& operator=(Gold const& obj)
    {
        if(this != &obj)
        {
            nume = obj.getNume();
            denom = obj.getDenom();
        }

        return *this;
    }
    Gold operator+(Gold const& obj)
    {
        return Gold(nume*obj.getDenom()+obj.getNume()*denom ,denom*obj.getDenom());
    }
    Gold operator-(Gold const& obj)
    {
        return Gold(nume*obj.getDenom()-obj.getNume()*denom , denom*obj.getDenom());
    }
    Gold operator/(Gold const& obj)
    {
        return Gold(nume*obj.getDenom() , denom*obj.getNume());
    }
    Gold operator*(Gold const& obj)
    {
        return Gold(nume*obj.getNume() , denom*obj.getDenom());
    }

    operator double()const
    {
        return (double)nume / (double)denom;
    }

    friend istream& operator>>(istream& is,Gold& gold)
    {
        is>>gold.nume;
        is>>gold.denom;
        return is;
    }
    friend ostream& operator<<(ostream& out , Gold& gold)
    {
        out<<gold.nume<<"/"<<gold.denom<<endl;
        return out;
    }
};

int main()
{
    Gold a;
    a.print();
    Gold b(1,3);
    b.print();
    Gold c(b);
    c.print();
    Gold d = a + c;
    d.print();
    cout<<double(d)<<endl;
    Gold e;
    cin>>e;
    cout<<e<<endl;



}
