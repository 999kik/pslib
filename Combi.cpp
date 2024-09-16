ll pw(ll a,ll b){
    if(b==0) return 1;
    ll r = pw(a,b/2);
    return r*r%mod*(b%2?a:1)%mod;
}
ll C(int n,int k){
    return fect[n]*pw(fect[k],mod-2)%mod*pw(fect[n-k],mod-2)%mod;
}
