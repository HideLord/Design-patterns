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

class Handler{
public:
    virtual bool handle(string) const noexcept = 0;
    virtual Handler& operator>>(shared_ptr<Handler> next) {
        nextHandler = next;
        return *this;
    }

    friend shared_ptr<Handler>& operator>>(shared_ptr<Handler>& from, const shared_ptr<Handler>& to){
        from->nextHandler =  to;
        return from;
    }

    virtual ~Handler(){

    }
protected:
    shared_ptr<Handler> nextHandler;
};

class BaseHandler : public Handler{
public:
    bool handle(string newPassword) const noexcept override {
        return true;
    }
};

class CheckForSqlHandler final : public BaseHandler{
public:
    bool handle(string newPassword) const noexcept override {
        return newPassword.find(';') == string::npos?
         nextHandler->handle(newPassword) : false;
    }
};

class CheckForUpperCase final : public BaseHandler{
public:
    bool handle(string newPassword) const noexcept override{
        for(auto c: newPassword)
            if(isupper(c))
                return true;
        return nextHandler->handle(newPassword);
    }
};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    shared_ptr<Handler> HSQL = shared_ptr<CheckForSqlHandler>(new CheckForSqlHandler());
    shared_ptr<Handler> HUpper = shared_ptr<CheckForUpperCase>(new CheckForUpperCase());

    HSQL >> HUpper;
    cout << boolalpha << HSQL->handle("LolNo") << endl;
}