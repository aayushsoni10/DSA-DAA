#include<bits/stdc++.h>
using namespace std;
bool isSafe(int x,int y,int n,int m){
  return (x<n && y<m && x>=0 && y>=0);
}
int main(){
  int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    int dx[]={-1,0,0,1};
    int dy[]={0,1,-1,0};
    queue<pair<int,int>> pq;
  while(t-->0){
    vector<pair<int,int>> pes;
      vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
        if(arr[i][j]=='E'){
          pq.push(make_pair(i,j));
          dist[i][j]=0;
        }else if(arr[i][j]=='P'){
          pes.push_back(make_pair(i,j));
        }
      }
    }
    while(!pq.empty()){
      int x=pq.front().first;
      int y=pq.front().second;
      pq.pop();
      if(vis[x][y])
          continue;
      vis[x][y]=1;
      for(int i=0;i<4;i++){
          int x1=x+dx[i];
          int y1=y+dy[i];
        if(isSafe(x1,y1,n,m) && !vis[x1][y1] && arr[x1][y1]!='O' && dist[x1][y1]>dist[x][y]+1){
            dist[x1][y1]=dist[x][y]+1;
          pq.push(make_pair(x1,y1));
        }
      }
    }
    int min=0;
    for(int i=0;i<(int)pes.size();i++){
        if(dist[pes[i].first][pes[i].second]==INT_MAX){
            min=-1;
            break;
        }else if(dist[pes[i].first][pes[i].second]>min){
            min=dist[pes[i].first][pes[i].second];
        }
    }
    printf("%d\n",min);
  }
  return 0;
}
