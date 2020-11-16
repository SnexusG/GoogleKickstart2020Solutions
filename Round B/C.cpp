//gives WA on 2nd test set

#include<bits/stdc++.h>
using namespace std;
template <typename T> void print(T t) { cout<<t<<endl; }    
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);cout<<fixed; cout<<setprecision(10);
#define loop0(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)
#define printVec(vec) for(int i = 0; i < vec.size(); ++i)cout<<vec[i]<<" "; cout<<endl
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,lla>>
#define get(a, n)    for(ll it = 0; it < n; it++)    cin>>a[it];
//creating a 2d vector containing n vectors of size m each : vector<vll> vec(n, vll(m,0));
//ascii of a is 97
//creating a vector with elements : vector<long long> arr{1,2,3,4};

ll n = 0, t = 0;
ll small = -1e18, big = 1e18;
const ll mod=1000000007;
map<ll,ll> occ;
const ll N = 2e5;
map<pair<ll,ll>,ll> occP;
// vector<vector<ll>> path(N);
//global variables end  

ll factorial(int n){
    long long ans = 1;
    for(int i = 1; i <= n; ++i){
        ans*=i;
    }
    return ans;
}

ll findGCD(ll a, ll b){
    ll ans = 1;
    for(int i = 1; i <= min(a,b); ++i){
        if(a%i == 0 && b%i == 0){
            ans = i;
        }
    }
    return ans;
}

bool sortVec( const vector<ll>& v1, const vector<ll>& v2 ) { 
//change 0 to 1 to sort as per second column
//change < sign to > sign to sort in descending 
 return v1[0] < v2[0]; 
} 

bool isprime(ll p){
    for(int i = 2; i < pow(p,1.5); ++i){
        if(p%i==0 && p != i){
            return false;
        }
    }
    return true;
}

void print2dVec(vector<vector<ll>> v){
    FOR(i, 0, v.size()){
        cout<<i<<" : ";
        FOR(j, 0, v[i].size()){
            cout<<v[i][j]<<" ";
        }
        print("");
    }
}

//gives all factors for a number (including non prime)
void seive(set<ll>&v, ll n){
         v.insert(n);
         for(int i=2;i*i<=n;i++){
            if(n%i==0) {
                v.insert(i);
                if(i!=n/i) v.insert(n/i);
         }
     }
} 

// void dfs(int curr, int par){
//     for(int child : path[curr]){
//         if(child == par)continue;
//         dfs(child,curr);
//     }
// }
//useful functions end

bool check(ll val){
    return false;
}
ll binsearch(ll low, ll high){
    while(low < high){
        ll mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low; //change this to high for upper bound (if element found then low and high both are correct)
}

void correct(ll &i, ll &j){
    if(i < 1){
        i = 1e9 + i;
    }  
    if(i > 1e9){
        i = (i-1e9);
    }
    if(j < 1){
        j = 1e9 + j;
    }
    if(j > 1e9){
        j = (j - 1e9);
    }
}

void solve(string& s, ll &x, ll &y){
    ll mult = 1;
    int i = 0;
    stack<int> stk;
    while(i < s.size()){
        if(s[i]-'0' >= 2 && s[i] - '0' <= 9){
            stk.push(s[i] - '0');
            mult*=stk.top();
            i+=2;
            continue;
        }
        if(s[i] == ')'){
            mult/=stk.top();
            stk.pop();
            i+=1;
            continue;
        }
        if(s[i] == 'N'){
            y-=(mult*1);
        }
        if(s[i] == 'S'){
            y+=(mult*1);
        }
        if(s[i] == 'W'){
            x-=(mult*1);
        }
        if(s[i] == 'E'){
            x+=(mult*1);
        }
        i+=1;
        correct(x,y);
    }

}

int main(){
    IOS;   
    cin>>t;
    ll ogT = t;
    while(t--){
        string s; 
        cin>>s;
        ll x = 1,y=1;
        solve(s,x,y);
        cout<<"Case #"<<ogT-t<<": "<<x<<" "<<y<<endl;
    }
    return 0;
}