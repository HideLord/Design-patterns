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

struct City final{
    const int population;
    const string name;
    const string country;

    City(string name, string country, int population) : population(population), name(name), country(country){}

    bool operator==(const City C){
        return C.population == population && C.name == name && C.country == country;
    }

    friend ostream& operator<<( ostream& out, const City& c){
        return out << c.name << " " << c.country << " " << c.population;
    }
    friend bool operator==(const shared_ptr<City> & A, const shared_ptr<City> & B){
        return *A == *B;
    }
};

struct CityHasher{
    size_t operator()(const shared_ptr<City>& C) const{
        size_t result = hash<string>{}(C->name);
        result ^= hash<string>{}(C->country);
        result ^= C->population;
        return result;
    }
};

class CityFactory final{
    static unordered_set<shared_ptr<City>, CityHasher> citySet;
public:
    static shared_ptr<City> getCity(int population, string name, string country){
        shared_ptr<City> temp( new City(name,country,population) );
        
        if(citySet.count(temp))return *citySet.find(temp);
        return citySet.insert(temp),temp;
    }
    static size_t size(){
        return citySet.size();
    }
    static void print(){
        for(auto c:citySet){
            cout << *c << endl;
        }
    }
};

unordered_set<shared_ptr<City>, CityHasher> CityFactory::citySet;

class Person{
public:
    string firstName;
    string  lastName;
    shared_ptr<City> city;
    Person(string firstName, string lastName, string cityName, string country, int cityPopulation){
        this->firstName = firstName;
        this->lastName = lastName;
        this->city = CityFactory::getCity(cityPopulation, cityName, country);
    }
    friend ostream& operator << (ostream& out, const Person& p){
        return out << p.firstName << " " << p.lastName << " lives in " << p.city->name;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    Person P("Alexander", "Hristov", "Sofia", "Bulgaria", 25e5);
    Person P1("Alexander1", "Hristov1", "Sofia", "Bulgaria", 25e5);
    Person P2("Alexander2", "Hristov2", "Sofia", "Bulgaria", 25e5);
    Person P3("Alexander3", "Hristov3", "Sofia", "Bulgaria", 25e5);
    cout << P << endl;
    cout << P1 << endl;
    cout << P2 << endl;
    cout << P3 << endl;
    cout << CityFactory::size() << endl;
    CityFactory::print();
}