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

class STLFacade{
public:
    template<class T>
    static void print(vector<T> V){
        if(!V.empty())cout << "[";
        for(int i = 0; i < sz(V); i++)cout << V[i] << (i+1==sz(V)?"]\n":", "); 
    }
    template<class U,class T>
    static void print(pair<U,T> P){
        cout << "{" << P.first << ", " << P.second << "}\n";
    }
    static void binary(int t){
        string S;
        while(t)S.push_back(t&1?'1':'0'), t>>=1;
        reverse(S.begin(),S.end());
        cout << S << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    STLFacade::print(vector<int>({1,2,3,4,5,6,7}));
    STLFacade::print(make_pair(2,4));
    STLFacade::binary(11);
}