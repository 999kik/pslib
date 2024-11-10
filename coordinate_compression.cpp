struct coor{
    vector<int> X;
    coor(vector<int> &A){
        vector<int> X = A;
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        for(int &i : A) i = lower_bound(X.begin(),X.end(),i)-X.begin(); 
    };
};
/// v2
struct coor{
    vector<ll> X;
    coor(vector<ll> A){
        X = A; sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
    };
    int operator[](int x){
        return lower_bound(X.begin(),X.end(),x)-X.begin();
    }
};
