#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> g[], vector<int> &vals, vector<int> &vis, int s, int &m){
	vis[s] = 1;
	if(m>vals[s])
		m = vals[s];
	for(auto i : g[s]){
		if(!vis[i]){
			dfs(g, vals, vis, i, m);		
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> vals(n, 0);
	for(int i=0;i<n;)
		cin>>vals[i++];
	int e;
	cin>>e;
	vector<int> g[n];
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int sum=0;
	vector<int> vis(n, 0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			int m=INT_MAX;
			dfs(g, vals, vis, i, m);
			sum+=m;
		}	
	}
	cout<<sum<<endl;
	return 0;
}
