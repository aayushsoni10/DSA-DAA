#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  vector<unordered_map<int,int>> adj(n);
  int m;
  scanf("%d",&m);
  unordered_map<int,int>::iterator it;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    if(u!=v){
        it=adj[u-1].find(v-1);
        if(it!=adj[u-1].end()){
                it->second=0;
        }else
            adj[u-1].insert(make_pair(v-1,0));
        it=adj[v-1].find(u-1);
        if(it!=adj[v-1].end()){
            if(it->second!=0){
                it->second=1;
            }
        }
        else
            adj[v-1].insert(make_pair(u-1,1));
    }
  }
  int s,d;
  s=0;
  d=n-1;
  deque<pair<int,int>> pq;
  vector<int> vis(n,0);
  pq.push_front(make_pair(0,s));
  int f=0;
  while(!pq.empty()){
    int s1=pq.front().second;
    int s1_w=pq.front().first;
    pq.pop_front();
    if(s1==d){
      printf("%d\n",s1_w);
      f=1;
      break;
    }
	if(vis[s1])
		continue;	
	vis[s1]=1;
    for(auto it=adj[s1].begin();it!=adj[s1].end();it++){
      if(!vis[it->first]){
        if(it->second==0){
          pq.push_front(make_pair(s1_w,it->first));
        }else{
          pq.push_back(make_pair(s1_w+1,it->first));
        }
      }
    }
  }
  if(f==0)
    printf("%d",-1);
  return 0;
}
