ll vis[N][N], dist[N][N], ways[N][N];
ll dx[4]={-1, +1, 0, 0};
ll dy[4]={0, 0, +1, -1};

void bfs(ll x, ll y, ll n, ll m)
{
	queue<pair<ll, ll> > q;
	q.push({x, y});
	ways[x][y]=1;
	vis[x][y]=1;
	dist[x][y]=0;
	while(!q.empty())
	{
		ll x=q.front().first;
		ll y=q.front().second;
		q.pop();
		for(ll dir=0;dir<4;dir++)
		{
			ll nx=x+dx[dir];
			ll ny=y+dy[dir];
			if(nx<1 || ny<1 || nx>n || ny>m)
				continue;
			if(!vis[nx][ny])
			{
				dist[nx][ny]=dist[x][y]+1;
				vis[nx][ny]=1;
				ways[nx][ny]+=ways[x][y];
				q.push({nx, ny});
			}
			else
			{
				if(dist[x][y] + 1 == dist[nx][ny])
					ways[nx][ny]+=ways[x][y];
			}
		}
	}
}

//Problem 1: https://www.spoj.com/problems/CLEANRBT/
//Solution 1: http://p.ip.fi/2fxO
