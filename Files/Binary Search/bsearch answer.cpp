bool check(int x){
	ld v=0;
	FOR(i,0,N){
		int y=a[i];
		v+=sqrt((ld)(x+y));
	}
	return (v>=M);
}

int32_t main() {
    boost; IO();
    
    cin>>N>>M; 
    FOR(i,0,N) cin>>a[i];

    int l=0,r=INF,ans;
    while(l<=r){
    	int m=(l+r)/2;
    	if(check(m)){
    		ans=m;
    		r=m-1;
    	}
    	else l=m+1;
    }
    cout << ans << endl;

    return 0;
}