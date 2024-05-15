#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct pst{
    struct nod{int l,r;ll sum;};
    vector<nod> t;
    vector<int> rt;
    int top = 0, MAX; // top : pst's top root , MAX : range max
    void init(int mx){MAX=mx;t.push_back({0,0,0});rt.push_back(0);}
    int push(int node,int s,int e,int p,ll v){
        int me = t.size();
        t.push_back(t[node]); 
        t[me].sum+=v;
        if(s==e) return me;
        int mid = s+e>>1;
        if(p<=mid) t[me].l = push(t[node].l,s,mid,p,v); 
        else t[me].r = push(t[node].r,mid+1,e,p,v);
        return me;
    }
    int find_kth(int t1,int t2,int s,int e,int k){
        if(s==e) return s;
        int mid = s+e>>1;
        ll cnt = t[t[t1].l].sum-t[t[t2].l].sum;
        if(k<=cnt) return find_kth(t[t1].l,t[t2].l,s,mid,k);
        else return find_kth(t[t1].r,t[t2].r,mid+1,e,k-cnt);
    }
    ll sum(int t1,int t2,int s,int e,int l,int r){
        if(e<l || r<s) return 0;
        if(l<=s && e<=r) return t[t1].sum-t[t2].sum;
        int mid = s+e>>1;
        return sum(t[t1].l,t[t2].l,s,mid,l,r)+sum(t[t1].r,t[t2].r,mid+1,e,l,r);
    }
    int find_kth(int t1,int t2,int k){
        return find_kth(rt[t1],rt[t2],1,MAX,k);
    }
    void insert(int p,ll v){
        rt.push_back(push(rt[top++],1,MAX,p,v));
    }
}seg;
