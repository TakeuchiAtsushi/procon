ll gcd(ll a, ll b){
   if (a%b == 0){
       return(b);
   }else{
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b){
//    return a * b / gcd(a, b);
   return a / gcd(a, b) * b;
}



// 拡張ユークリッドの互除法
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}