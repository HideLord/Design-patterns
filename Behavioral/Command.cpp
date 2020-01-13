#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T,U> &P){
    return out << "{" << P.first << ", " << P.second << "}";
}

template<class T>
ostream& operator<<(ostream& out, const vector<T> &V){
    if(!V.empty())cout << '[';
    for(int i(0); i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}
class Person;

class Command
{
    shared_ptr<Person> object;   
    void(Person:: *method)();
  public:
    Command(Person *obj = 0, void(Person:: *meth)() = 0){
        object = shared_ptr<Person>(obj);
        method = meth;
    }
    void execute(){
        (object.get()->*method)();
    }
};

class Person
{
    string name;
    Command cmd; 
  public:
    Person(string n, Command c): cmd(c){
        name = n;
    }
    void talk(){
        cout << name << " is talking" << endl;
        cmd.execute();
    }
    void passOn(){
        cout << name << " is passing on" << endl;
        cmd.execute(); 
    }
    void gossip(){
        cout << name << " is gossiping" << endl;
        cmd.execute();
    }
    void listen(){
        cout << name << " is listening" << endl;
    }
};

int main(){
    Person wilma("Wilma", Command());
    Person betty("Betty", Command(&wilma, &Person::listen));
    Person barney("Barney", Command(&betty, &Person::gossip));
    Person fred("Fred", Command(&barney, &Person::passOn));
    fred.talk();
}