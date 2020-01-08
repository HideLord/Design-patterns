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


class Drawable {
public:
    virtual void draw() = 0;
};

class Point : public Drawable{
private:
    double x, y;
public:
    friend ostream& operator<<(ostream& out, const Point& p){
        return out << '{' << p.x << ", " << p.y << '}';
    }
    void draw() override{
        cout << "drawing: {" << x << ", " << y << '}' << endl; 
    }
    ~Point() {}
};

class Triangle : public Drawable{
private:
    Point A,B,C;
public:
    void draw() override{
        A.draw();
        B.draw();
        C.draw();
    }
    ~Triangle() {}
};

class Polygon : public Drawable{
private:
    vector<Triangle> polygon;
public:
    void draw() override{
        for(auto &t:polygon){
            t.draw();
        }
    }
    ~Polygon() {}
};

class Bundle : public Drawable{
private:
    vector<shared_ptr<Drawable>> shapes;
public:
    void draw() override{
        for(auto &obj:shapes){
            obj->draw();
        }
    }
    void add(Drawable* obj){
        shapes.push_back(shared_ptr<Drawable>(obj));
    }
    void add(shared_ptr<Drawable> obj){
        shapes.push_back(obj);
    }
    ~Bundle() {}
};

int main(){
    ios_base::sync_with_stdio(false);
    Bundle B;
    B.add(new Triangle());
    B.add(new Polygon());
    B.add(new Point());
}