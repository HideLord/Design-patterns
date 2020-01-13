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

template<typename T>
class Iterator{
public:
    virtual Iterator* next() = 0;
    virtual Iterator* operator++(int) = 0;
    virtual void operator++() = 0;
};

struct node{
    int val;
    node* left;
    node* right;
    node(int val) : val(val), left(NULL), right(NULL) {}
};

class BFSIterator : public Iterator<node>{
private:
    queue<node*> Q;
public:
    BFSIterator(node* root){
        Q.push(root);
    }
    BFSIterator(queue<node*> Q) : Q(Q){}
    Iterator* operator++(int){
        if(Q.empty()){
            throw 512;
        }
        auto temp = new BFSIterator(this->Q);
        node* root = Q.front();
        Q.pop();
        if(root->left)Q.push(root->left);
        if(root->right)Q.push(root->right);
        return temp;
    }
    void operator++(){
        if(Q.empty()){
            throw 512;
        }
        node* root = Q.front();
        Q.pop();
        if(root->left)Q.push(root->left);
        if(root->right)Q.push(root->right);
    }
    node operator*(){
        if(Q.empty()){
            throw 512;
        }
        return *Q.front();
    }
    node* operator->(){
        if(Q.empty()){
            throw 512;
        }
        return Q.front();
    }
    Iterator *next() override{
        if(Q.empty()){
            throw 512;
        }
        node* root = Q.front();
        Q.pop();
        if(root->left)Q.push(root->left);
        if(root->right)Q.push(root->right);
        auto res = new BFSIterator(Q);
        return res;
    }
    bool isEnd(){
        return Q.empty();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    node* root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7);
    BFSIterator it(root);
    while(!it.isEnd()){
        cout << it->val << endl;
        ++it;
    }
}