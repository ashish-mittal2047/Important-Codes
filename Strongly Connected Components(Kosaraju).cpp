
ll grp = 0;
vector<ll> g[N],rg[N],newg[N],todo;
ll comp[N],sz[N],indeg[N];
bool vis[N];
void dfs1(ll u)
{
	vis[u] = 1;
	for(auto it:g[u])
	{
		if(!vis[it])
			dfs1(it);
	}
	todo.push_back(u);
}

void dfs2(ll u,ll grp)
{
	comp[u] = grp;
	sz[grp]++;
	for(auto it:rg[u])
	{
		if(comp[it] == -1)
		{
			dfs2(it,grp);
		}
	}
}

void sccAddEdge(ll from, ll to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(ll i = 1;i<=n;i++)
		comp[i] = -1;
	for(ll i = 1;i<=n;i++)
	{
		if(!vis[i])
			dfs1(i);
	}
	reverse(todo.begin(),todo.end());
	for(auto i:todo)
	{
		if(comp[i] == -1)
			dfs2(i,++grp);
	}
	/*Uncomment if you want SCC tree(i.e condensed graph) and indegree of each scc
	for(ll i = 1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			if(comp[i] != comp[it])
			{
				newg[comp[i]].push_back(comp[it]);
				indeg[comp[it]]++;
			}
		}
	}
	*/
}

/* DFS corresponding to consdensed graph
void newdfs(ll u)
{
	vis[u] = 1;
	for(auto it:newg[u])
	{
		if(vis[u])
			newdfs(it);
	}
}
*/


// Sample Problem 1 (SCC Compression): http://codeforces.com/contest/999/problem/E
// Sample Solution 1: http://codeforces.com/contest/999/submission/39489910

//Sample Problem 2 (Detection of Directed Cycle in a connected component): http://codeforces.com/contest/505/problem/D
//Sample Solution 2: http://codeforces.com/contest/505/submission/39885530