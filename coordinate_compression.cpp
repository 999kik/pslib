struct coor{
    vector<int> X;
    coor(vector<int> &A){
        vector<int> X = A;
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        for(int &i : A) i = lower_bound(X.begin(),X.end(),i)-X.begin(); 
    };
};
