#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
set<long long> st;
int main(){
    pq.push(1);
    st.insert(1);
    int id = 1;
    while(id<1500){
        long long tmp = pq.top();
        pq.pop();
        if(!st.count(tmp*2)) st.insert(tmp*2), pq.push(tmp*2);
        if(!st.count(tmp*3)) st.insert(tmp*3), pq.push(tmp*3);
        if(!st.count(tmp*5)) st.insert(tmp*5), pq.push(tmp*5);
        ++id;
    }
    cout << "The 1500'th ugly number is " << pq.top() << "." << endl;
    return 0;
}
