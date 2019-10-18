#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int g[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>g[i][j];
  int s;
  cin>>s;
  int d;
  cin>>d;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> dist(n,123456789);
  dist[s]=0;
  pq.push(make_pair(0,s));
  while (!pq.empty()) {
    int s1=pq.top().second;
    pq.pop();
    for(int i=0;i<n;i++){
      if(g[s1][i]==1 && dist[i]>dist[s1]+1){
        dist[i]=dist[s1]+1;
        pq.push(make_pair(dist[i],i));
      }
    }
  }
  vector<int> dist2(n,123456789);
  pq.push(make_pair(0,d));
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          int t1=g[i][j];
          g[i][j]=g[j][i];
          g[j][i]=t1;
      }
  }
  dist2[d]=0;
  while (!pq.empty()) {
    int s1=pq.top().second;
    pq.pop();
    for(int i=0;i<n;i++){
      if(g[s1][i]==1 && dist2[i]>dist2[s1]+1){
        dist2[i]=dist2[s1]+1;
        pq.push(make_pair(dist2[i],i));
      }
    }
  }
  int mind=dist[d];
  for(int i=0;i<n;i++){
    if(dist[i]+dist2[i]==mind && dist[i]!=123456789 && dist2[i]!=123456789){
      printf("%d ",i);
    }
  }
  return 0;
}
