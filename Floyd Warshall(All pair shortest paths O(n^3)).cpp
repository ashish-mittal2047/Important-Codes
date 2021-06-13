
/*It uses adjacency matrix*/
ll d[N][N];
ll g[N][N]; 	//adjacency matrix g[i][j] = wt of edge b/w vertex i and j

for(ll i = 1;i<=n;i++)
{
	for(ll j = 1;j<=n;j++)
	{
		if(g[i][j]!=0)
			d[i][j] = g[i][j];
		else g[i][j] = inf;
	}
}

for(ll k = 1;k<=n;k++)
{
	for(ll i = 1;i<=n;i++)
	{
		for(ll j = 1;j<=n;j++)
		{
			if(d[i][k]<inf && d[k][j]<inf)			//to avoid using paths that don't exist, which may accidentally contribute in case of negative edge weights
			d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}


//Problem 1: https://codeforces.com/contest/189/problem/D
//Solution 1: https://codeforces.com/contest/189/submission/48938763
