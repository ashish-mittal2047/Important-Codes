const ll N = 1e5+5;

vector<bool> vis(N);
vector<pair<ll,ll>> adj[N];	// {vertex, edge index}
vector<ll> low(N);
vector<ll> tin(N);
vector<bool> isBridge(N);
ll timer = 0;

void dfs(ll u, ll par)
{
	vis[u] = 1;
	tin[u] = ++timer;
	low[u] = tin[u];
	for(auto it:adj[u])
	{
		if(par == it.first)
			continue;
		else if(vis[it.first])
		{
			low[u] = min(low[u],tin[it.first]);
		}
		else
		{
			dfs(it.first,u);
			low[u] = min(low[u],low[it.first]);
			if(low[it.first]>tin[u])
				isBridge[it.second] = 1;
		}
	}
}


void bridges()
{
	fill(vis.begin(),vis.end(),0);
	fill(low.begin(),low.end(),-1);
	fill(tin.begin(),tin.end(),-1);
	fill(isBridge.begin(),isBridge.end(),0);
	for(ll i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1);
		}
	}
}


//Sample Problem 1: https://codeforces.com/contest/118/problem/E
//Sample Solution 1: https://codeforces.com/contest/118/submission/39888563

//Sample Problem 2: https://www.spoj.com/problems/EC_P/
//Sample Solution 2: http://p.ip.fi/shDA