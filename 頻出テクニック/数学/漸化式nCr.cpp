map<LP,modint> mp;
modint nCr(ll n, ll r){
  auto key = make_pair(n,r);
  if(mp.count(key)) return mp[key];
  
  if(r==0 || r==n){
    modint mt = 1;
    return mt;
  }
  if(r==1 || r==n-1){
    modint mt = n;
    return mt;
  }
  //return mp[key] = nCr(n,r-1) * (n-r+1) / r; // rを減らすVer
  return mp[key] = nCr(n-1,r) * modint(n) / modint(n-r); // nを減らすVer
}