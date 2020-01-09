#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

// Interface
class FireAction{
public:
    double bulletSpeed = 1.0;
    double sound = 1.0;
    double accuracy = 0.5;
public:
    virtual void fire() = 0;
    virtual void playSound() = 0;
};

// Base decorator
class BaseSuppressor : public FireAction{
public:
    shared_ptr<FireAction> action;
public:
    virtual void fire(){
        action->fire();
    }
    virtual void playSound(){
        action->playSound();
    }
};

class RimfireSuppressor final : public BaseSuppressor{
public:
    RimfireSuppressor(shared_ptr<FireAction> action){this->action = action;}
    void fire() final {
        action->bulletSpeed *= 0.95;
        action->fire();
    }
    void playSound() final{
        action->sound *= 0.2;
        action->playSound();
    }
};

class Sight final : public BaseSuppressor{
public:
    Sight(shared_ptr<FireAction> action){this->action = action;}
    void fire() final {
        cout << "Pew" << endl;
        action->fire(); 
    }
};

class Gun final : public FireAction{
public:
    void fire() final{
        cout << "    Accuracy: " << accuracy << endl;
        cout << "Bullet Speed: " << bulletSpeed << endl;
    }
    void playSound() final{
        cout << "\a Sound level: " << sound << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    FireAction* myGun = new Gun();
    auto temp = myGun;
    myGun = new RimfireSuppressor(shared_ptr<FireAction>(myGun));
    myGun = new Sight(shared_ptr<FireAction>(myGun));
    myGun->fire();
    myGun->playSound();
    cout << endl;
    temp->fire();
    temp->playSound();
}