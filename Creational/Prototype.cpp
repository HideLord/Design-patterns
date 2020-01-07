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

class Appetizer {
    public:
        virtual Appetizer* clone() const = 0;
};

class Entree {
    public:
        virtual Entree* clone() const = 0;
};

class Dessert {
    public:
        virtual Dessert* clone() const = 0;
};

class MozzarellaSticksWithKetchup : public Appetizer {
    public:
        virtual Appetizer* clone() const override { return new MozzarellaSticksWithKetchup(*this); }
};

class HockeyPuckHamburgerWithSoggyFries : public Entree {
    public:
        virtual Entree * clone() const override { return new HockeyPuckHamburgerWithSoggyFries(*this); }
};

class FreezerBurnedIceCream : public Dessert {
    public:
        virtual Dessert * clone() const override { return new FreezerBurnedIceCream(*this); }
};


struct Meal{
    unique_ptr<Dessert> D;
    unique_ptr<Entree> E;
    unique_ptr<Appetizer> A;
    string review = "Absolutely fabulous";
};

class Chef {
    private:
        Meal myMeal;
    public:
        void prepareMeal(Appetizer* appetizer_prototype, Entree* entree_prototype, Dessert* dessert_prototype) {
            myMeal.A = unique_ptr<Appetizer>(appetizer_prototype->clone());
            myMeal.E = unique_ptr<Entree>(entree_prototype->clone());
            myMeal.D = unique_ptr<Dessert>(dessert_prototype->clone());
            myMeal.review = "Lol no. But it's edible.";
        }
        string reviewMeal(){
            return myMeal.review;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    Chef GordonRamses;
    GordonRamses.prepareMeal(new MozzarellaSticksWithKetchup(), new HockeyPuckHamburgerWithSoggyFries(), new FreezerBurnedIceCream());
    cout << GordonRamses.reviewMeal() << endl;
}