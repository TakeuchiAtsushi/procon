int W,H,N;
bool fld[6100][6100];
int X1[1000],X2[1000],Y1[1000],Y2[1000];

//W = compress(x1, x2, W);
//H = compress(y1, y2, H); みたいに使って圧縮する
int compress(int *x1,int *x2,int w){
	vector<int> xs;
	for(int i=0;i<N;i++){
		for(int j=-1;j<=1;j++){
			int tx1=x1[i]+j,tx2=x2[i]+j;
			if(0<=tx1 && tx1<=w)xs.push_back(tx1);
			if(0<=tx2 && tx2<=w)xs.push_back(tx2);
		}
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	for(int i=0;i<N;i++){
		x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
		x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
	}
	return xs.size();
}

void solve(){
	W=compress(X1,X2,W);
	H=compress(Y1,Y2,H);
	memset(fld,0,sizeof(fld));
	for(int i=0;i<N;i++){
		for(int y=Y1[i];y<=Y2[i];y++){
			for(int x=X1[i];x<=X2[i];x++){
				fld[y][x]=true;
			}
		}
	}
}



// vectorで単純な実装をする場合
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()),v.end());