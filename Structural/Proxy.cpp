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


class ICar {
public:
    virtual ~ICar() { std::cout << "ICar destructor!" << std::endl; }

    virtual void DriveCar() = 0;
};

class Car : public ICar {
public:
    void DriveCar() override { std::cout << "Car has been driven!" << std::endl; }
};

class ProxyCar : public ICar {
public:
    ProxyCar(int driver_age) : driver_age_(driver_age), real_car_(new Car()) {}

    void DriveCar() override {
        if (driver_age_ > 16) {
            real_car_->DriveCar();
        } else {
            std::cout << "Sorry, the driver is too young to drive." << std::endl;
        }
    }

private:
    std::unique_ptr<ICar> real_car_;
    int driver_age_;
};

int main() {
    ios_base::sync_with_stdio(false);
    std::unique_ptr<ICar> car = unique_ptr<ProxyCar>(new ProxyCar(16));
    car->DriveCar();

    car = unique_ptr<ProxyCar>(new ProxyCar(25));
    car->DriveCar();
}