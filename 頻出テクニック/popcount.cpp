// 2進数表記で1の数をカウントする
ll popcount(ll x){
	ll popc = 0;
	while(x > 0){
		if(x % 2 == 1) popc++;
		x /= 2;
	}
	return popc;
}