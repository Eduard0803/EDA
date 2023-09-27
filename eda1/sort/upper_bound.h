int upper_bound(int *v, int l, int r, int t){
    if(l == r)
        return v[l] >= t ? l : -1;

    int m = l+(r-l)/2;
    if(v[m] <= t)
        return upper_bound(v, m+1, r, t);
    else
        return upper_bound(v, l, m, t);
}
