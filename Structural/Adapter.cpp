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

enum RF_TIER{
    LOW,
    MID,
    HIGH
};

class RFOutput{
public:
    double value;
    RF_TIER tier;

    virtual bool canUse(RF_TIER T) const{
        return static_cast<int>(T) >= static_cast<int>(tier); 
    }

};

class IEOutput{
public:
    double value;
    //...
};

class IEToRFAdapter : public RFOutput{
    shared_ptr<IEOutput> output;
    IEToRFAdapter(){}
    IEToRFAdapter(shared_ptr<IEOutput> out) : output(out){}
    void setOutput(shared_ptr<IEOutput> out){ output = out; }
    bool canUse(RF_TIER T) const override {
        RF_TIER myTier;
        if(output->value > 10000.00) myTier = HIGH;
        else if(output->value > 1000.00) myTier = MID;
        else if(output->value > 100.00) myTier = LOW;
        return static_cast<int>(T) >= static_cast<int>(myTier); 
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    
}