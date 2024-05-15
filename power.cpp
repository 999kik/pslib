ll pw(ll a,ll b){
    ll r = 1;
    for(;b;b/=2){
        if(b%2) r = r*a%mod;
        a = a*a%mod;
    }
    return r;
}
