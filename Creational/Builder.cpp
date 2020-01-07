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

class House{
public:
    int roof;
    int walls;
    int floor;
    int pool;
    int tree;
    House(){
        reset();
    }
    void reset(){
        roof = walls = floor = pool = tree = 0;
    }
    friend ostream& operator << (ostream& out, const House& H){
        out << "[ roof: " << H.roof << ", walls: " << H.walls << ", floor: " << H.floor << ", pool: " << H.pool << ", tree: " << H.tree << " ] " << endl; 
        return out;
    }
};

class builderInterface{
public:
    virtual void reset() = 0; 
    virtual void buildPool() = 0;
    virtual void buildRoof() = 0;
    virtual void buildTree() = 0;
    virtual void buildFloor() = 0;
    virtual void buildWalls() = 0;
};

class treeHouseBuilder : public builderInterface{
public:

    House currentBuild;

    void reset() override{
        currentBuild = House();
    }
    void buildPool() override{
        currentBuild.pool = 1;
    }
    void buildRoof() override{
        currentBuild.roof = 1;
    }
    void buildTree() override{
        currentBuild.tree = 1;
    }
    void buildFloor() override{
        currentBuild.floor = 1;
    }
    void buildWalls() override{
        currentBuild.walls = 1;
    }
};

class modernHouseBuilder : public builderInterface{
public:

    House currentBuild;

    void reset() override{
        currentBuild = House();
    }
    void buildPool() override{
        currentBuild.pool = 2;
    }
    void buildRoof() override{
        currentBuild.roof = 2;
    }
    void buildTree() override{
        currentBuild.tree = 2;
    }
    void buildFloor() override{
        currentBuild.floor = 2;
    }
    void buildWalls() override{
        currentBuild.walls = 2;
    }
};

class Director {
private:
    shared_ptr<builderInterface> currentBuilder;
public:
    Director(shared_ptr<builderInterface> builder) : currentBuilder(builder){ }
    void setBuilder(shared_ptr<builderInterface> builder){
        this->currentBuilder = builder;
    }
    void buildAbstract(){
        currentBuilder->buildFloor();
        currentBuilder->buildPool();
        currentBuilder->buildRoof();
    }
    void buildFull(){
        currentBuilder->buildTree();
        currentBuilder->buildPool();
        currentBuilder->buildRoof();
        currentBuilder->buildFloor();
        currentBuilder->buildWalls();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    shared_ptr<modernHouseBuilder> myBuilder(new modernHouseBuilder());
    Director myDirector = Director(shared_ptr<builderInterface>(myBuilder));
    myDirector.buildFull();
    cout << myBuilder->currentBuild << endl;
}