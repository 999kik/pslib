#define int long long
using tu = array<int,3>;
const int inf = 1e12; // if answer is bigger then inf. return inf+1
tu egcd(int a, int b) {
    if(!b) return {a, 1, 0};
    auto [g, x1, y1] = egcd(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}
tu crt_merge(int r1,int m1,int r2,int m2) {
    auto [g, p, q] = egcd(m1, m2);
    if ((r2 - r1) % g != 0) return {0, 0, 0};
    int lcm = m1/g*m2, dif = r2-r1, mul = dif/g*p%(m2/g);
    if(mul<0) mul += m2/g;
    int res = (r1+m1*mul)%lcm;
    if(res<0) res += lcm;
    return {1, res, lcm};
}
tu general_crt(vector<int> rems, vector<int> mods) {
    int n = rems.size();
    for(int i=0;i<n;i++) rems[i] = (rems[i]%mods[i]+mods[i])%mods[i];
    int r = rems[0], m = mods[0];
    for(int i=1;i<n;i++){
        auto [ok, nr, nm] = crt_merge(r, m, rems[i], mods[i]);
        if(!ok) return {0,0,0};
        if(r>inf) return {1,inf+1,inf+1};
        r = nr, m = nm;
    }
    return {1,r,m}; // answer is r+mx.
}
