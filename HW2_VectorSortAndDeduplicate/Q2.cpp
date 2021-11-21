#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Elem {
public:
    friend ostream& operator << (ostream& out, const Elem& aElem);
    friend istream& operator >> (istream& in, Elem& aElem);

    bool operator == (const Elem& aElem) const;
    bool operator != (const Elem& aElem) const;
    bool operator < (const Elem& aElem) const;
    bool operator <= (const Elem& aElem) const;
    bool operator > (const Elem& aElem) const;
    bool operator >= (const Elem& aElem) const;
    
private:
    long x;
    long y;
};

ostream& operator << (ostream& out, const Elem& aElem) {
    out << aElem.x << " " << aElem.y;
    return out;
}

istream& operator >> (istream& in, Elem& aElem) {
    in >> aElem.x >> aElem.y;
    return in;
}

bool Elem::operator == (const Elem& aElem) const {
    if (x == aElem.x && y == aElem.y)
    {
        return true;
    }
    return false;
}

bool Elem::operator != (const Elem& aElem) const {
    return !operator == (aElem);
}

bool Elem::operator < (const Elem& aElem) const {
    if (x < aElem.x)
    {
        return true;
    }
    if (x > aElem.x)
    {
        return false;
    }
    if (x == aElem.x)
    {
        if (y < aElem.y)
        {
            return true;
        }
    } 
    return false;
}

bool Elem::operator <= (const Elem& aElem) const {
    return !operator > (aElem);
}

bool Elem::operator > (const Elem& aElem) const {
    if (x > aElem.x)
    {
        return true;
    }
    if (x < aElem.x)
    {
        return false;
    }
    if (x == aElem.x)
    {
        if (y > aElem.y)
        {
            return true;
        }
    }
    return false;
}

bool Elem::operator >= (const Elem& aElem) const {
    return !operator < (aElem);
}

int main (int argc, char* argv[]) {
    unsigned int num;
    Elem tmp;
    vector<Elem> Elems;
    Elems.clear();

    cin >> num;

    for (unsigned int i = 0; i < num; i++)
    {
        cin >> tmp;
        Elems.push_back(tmp);
    }
    
    sort(Elems.begin(), Elems.end());

    unsigned int i = 0;
    unsigned int j = 0;
    
    while (i < Elems.size())
    {
        while (++j < Elems.size() && Elems[i] == Elems[j]);
        if (i != j - 1)
        {
            Elems.erase(Elems.begin() + i + 1, Elems.begin() + j);
        }
        j = ++i;
    }
    
    for (unsigned int k = 0; k < Elems.size(); k++)
    {
        cout << Elems[k] << endl;
    }

    return 0;
}