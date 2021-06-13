/*Space complexity:O(NlgN), Time Complexity:O(N) for dfs, O(NlgN) for precomputation 
	and O(lgN) for each query of the form (u,v)*/
const ll N = 1e5+5;
const ll LG = lg2(N)+1;

ll timer,level[N], parent[N][LG], tin[N], tout[N];

void dfs(ll k, ll par, ll lvl)
{
	tin[k] = ++timer;
	parent[k][0] = par;
	level[k] = lvl;
	for(auto it:g[k])
	{
		if(it!=par)
		{
			dfs(it,k,lvl+1);
		}
	}
	tout[k] = timer;
}

void precompute()				//dynamic programming step
{
	for(ll j = 1;j<LG;j++)
	{
		for(ll i = 1;i<=n;i++)
		{
			if(parent[i][j-1])
			{
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}
}

ll LCA(ll u, ll v)
{
	if(level[u]>level[v])
		swap(u,v);
	ll diff = level[v]-level[u];
	for(ll i = LG-1;i>=0;i--)
	{
		if((1<<i)&diff)
		{
			u = parent[u][i];
		}
	}
	//by this point, u and v are at same level
	if(u == v)
		return v;

	for(ll i = LG-1;i>=0;i--)
	{
		if(parent[u][i] && (parent[u][i]!=parent[v][i]))
		{
			u = parent[u][i], v = parent[v][i];
		}
	}
	return parent[u][0];
}

//Application of LCA - Finding distance between two vertices in a tree in O(lgN) time
ll dist(ll u, ll v)
{
	ll ans = level[u] + level[v] - 2*level[LCA(u,v)];
	return ans;
}


//Problem 1 (Dynamic Diameter): https://codeforces.com/problemset/problem/379/F
//Solution 1: https://codeforces.com/contest/379/submission/45960185