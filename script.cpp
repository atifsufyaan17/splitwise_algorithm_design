#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<list>
#define loop(i,a,n) for (int i=a;i<n;i++)
#define loopRev(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll mod=1000000007;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    ios
    ll transactions=0,amount=0,no_of_transactions=0; cin>>transactions;
    unordered_map<string,ll> m;
    string u,v;

    loop(i,0,transactions){
        cin>>u>>v>>amount;  

        if(m.find(u)==m.end()){
            m[u]=0;
        }
        if(m.find(v)==m.end()){
            m[v]=0;
        }

        m[u]-=amount;
        m[v]+=amount;
    }

    multiset< pair<ll,string> > st;

    for(auto i:m){
        string name = i.first;
        ll netAmount = i.second;

        if(netAmount!=0){
            st.insert(mp(netAmount,name));
        }
    }

    while(!st.empty()){
        auto debit = st.begin();
        ll debitAmt = (*debit).first;
        string debitName = (*debit).second;

        auto credit = prev(st.end());
        ll creditAmt = (*credit).first;
        string creditName = (*credit).second;
        
        st.erase(debit);
        st.erase(credit);

        ll settledAmt = min(abs(debitAmt),creditAmt);
        
        debitAmt+=settledAmt;
        creditAmt-=settledAmt;

        if(debitAmt!=0){
            st.insert(mp(debitAmt,debitName));
        }
        if(creditAmt!=0){
            st.insert(mp(creditAmt,creditName));
        }

        cout<<debitName<<" will pay "<<settledAmt<<" to "<<creditName<<endl;
        no_of_transactions++;
    }

    cout<<"No of transactions = "<<no_of_transactions<<endl;
}
