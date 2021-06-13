- DFS in 2D Grid:

bool vis[N][N];
ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};

void dfs(ll x, ll y, ll n, ll m)
{
	vis[x][y] = 1;
	for(ll i = 0;i<4;i++)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m)
			continue;
		if(!vis[nx][ny])
		{
			dfs(nx,ny,n,m);
		}
	}
}


//Problem 1: https://codeforces.com/contest/616/problem/C
//Solution 1: https://codeforces.com/contest/616/submission/45959489
