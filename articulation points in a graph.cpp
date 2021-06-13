const ll N = 1e5+5;

vector<bool> vis(N);
vector<ll> adj[N];
vector<ll> low(N);
vector<ll> tin(N);
vector<bool> isArticulation(N);
ll timer = 0;

void dfs(ll u, ll par)
{
	vis[u] = 1;
	tin[u] = ++timer;
	low[u] = tin[u];
	ll children = 0;
	for(auto it:adj[u])
	{
		if(par == it)
			continue;
		else if(vis[it])
		{
			low[u] = min(low[u],tin[it]);
		}
		else
		{
			dfs(it,u);
			low[u] = min(low[u],low[it]);
			if(par != -1 && low[it]>=tin[u])
				isArticulation[u] = 1;
			children++;
		}
	}
	if(par == -1 && children>1)
		isArticulation[u] = 1;
}


void articulationPoints()
{
	fill(vis.begin(),vis.end(),0);
	fill(low.begin(),low.end(),-1);
	fill(tin.begin(),tin.end(),-1);
	fill(isArticulation.begin(),isArticulation.end(),0);
	for(ll i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1);
		}
	}
}