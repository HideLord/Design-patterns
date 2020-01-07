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

class Shape{
public:
    Shape(){

    }
    virtual double area() const = 0;
private:
};
class Rectangle : public Shape{
public:
    double area() const override{
        return 40;
    }
};
class Triangle : public Shape{
    double area() const override {
        return 30;
    }
};
enum class SHAPE_TYPE: int{
    RECTANGLE,
    TRIANGLE
};
class ShapeFactory{
private:
    ShapeFactory(){};
public:
    static Shape * getShape(SHAPE_TYPE T){
        switch(T){
        case SHAPE_TYPE::RECTANGLE:
            return new Rectangle();
        case SHAPE_TYPE::TRIANGLE:
            return new Triangle();
        default:
            throw 1;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    Shape *S = ShapeFactory::getShape(SHAPE_TYPE::RECTANGLE);
    cout << S->area() << endl;
}