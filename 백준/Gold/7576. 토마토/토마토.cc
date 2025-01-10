#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1002][1002];
int dist[1002][1002];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  queue<pair<int, int>> Q;

  //board, dist 초기화 및 시작점 큐에 저장
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];

      if(board[i][j]==0) dist[i][j] = -1;
      if(board[i][j]==1) Q.push({i, j});
    }
  }

  while(!Q.empty()){
    pair<int, int> cur = Q.front();
    Q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny]>=0) continue;

      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  int days = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      days = max(days, dist[i][j]);
    }
  }
  cout << days << '\n';
  return 0;
}