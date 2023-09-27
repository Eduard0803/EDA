#include <stdio.h>
#define ll long long int

ll lower_bound(ll *v, ll l, ll r, ll t){
    if(l == r)
        return v[l] >= t ? l : -1;

    ll m = l+(r-l)/2;
    if(v[m] >= t)
        return lower_bound(v, l, m, t);
    else
        return lower_bound(v, m+1, r, t);
}

int main(){
    ll c, t, count=0, x, y, circles[100010], u;
    scanf("%lld %lld", &c, &t);

    for(int i=0; i<c; ++i){
        scanf("%lld", &u);
        circles[i] = u*u;
    }
    
    for(int i=0; i<t; ++i){
        scanf("%lld %lld", &x, &y);
        if(x*x+y*y <= circles[c-1])
            count += c-lower_bound(circles, 0, c-1, x*x+y*y);
    }
    printf("%lld\n", count);
}
