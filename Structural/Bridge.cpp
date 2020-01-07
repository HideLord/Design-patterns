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

// The interface
class Computer{
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void takeInput(char key) = 0;
};

// Implementation
class MyTower : public Computer{
private:
    bool isOn;
    void powerOn() override {
        isOn = true;
    }
    void powerOff() override {
        isOn = false;
    }
    void takeInput(char key) override {
        cout << "Read " << key << endl;
    }
};

// The abstraction in this case
class Keyboard{
public:
    unique_ptr<Computer> device;
    virtual void pressKey(char key){
        device->takeInput(key);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    Keyboard K;
    K.device = unique_ptr<Computer>(new MyTower);
    K.pressKey('p');
}