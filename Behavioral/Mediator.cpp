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

class Mediator;

class Component{
protected:
    shared_ptr<Mediator> mediator;
public:
    Component(Mediator* mediator) : mediator(shared_ptr<Mediator>(mediator)){ }
};

class Button : public Component{
    string message;
public:
    Button(Mediator * mediator, string messageOnClick) 
    : Component(mediator), message(std::move(messageOnClick)){}
    void click();
};

class Printer{
public:
    static void print(const string& S){
        cout << S << endl;
    }
};

class Mediator{
public:
    virtual void notify(Component*, string event) = 0;
};

class Notifier: public Mediator{
    void notify(Component* obj, string event){
        Printer::print(event);
    }
};

void Button::click(){
    mediator->notify(this,message);
}



int main(){
    ios_base::sync_with_stdio(false);
    Button B(new Notifier(), "I am clicked");
    B.click();
}