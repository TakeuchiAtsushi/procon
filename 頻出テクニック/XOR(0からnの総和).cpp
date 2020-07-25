ll f(ll n){
    if(n%2){
        return (n+1)/2%2;
    }else{
        return (n/2%2)^n;
    }
}

// AからBの総和の場合はf(A-1)とf(B)を排他的論理和する(交換則とx^x=0から)
void solve() {
    ll A, B; cin >> A >> B;
    ll res = f(A-1)^f(B);

    cout << res << endl;
}