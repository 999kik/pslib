ll pw(ll a,ll b){
    ll r = 1;
    for(;b;b/=2){
        if(b%2) r = r*a%mod;
        a = a*a%mod;
    }
    return r;
}

ll pw(ll a,ll b){
    ll r = b?pw(a,b/2):1;
    return (r*r%mod*(b%2?a:1))%mod;
}
