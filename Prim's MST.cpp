//Logic: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
const ll N = 1e5+9;

vector<pair<ll,ll>> tree[N];
bool vis[N];
ll dist[N];
ll parent[N];

ll primsMST(ll src)
{
	for(ll i = 1;i<=n;i++)
		dist[i] = inf;
	set<pair<ll,ll>> s;
	s.insert({0,src});
	dist[src] = 0;
	ll cost = 0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second] = 1;
		cost += x.first;
		ll u = parent[x.second];
		ll v = x.second;
		ll w = x.first;
		tree[u].push_back({v,w});
		tree[v].push_back({u,w});
		for(auto it:adj[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first]>it.second)
			{
				s.erase({dist[it.first],it.first});
				dist[it.first] = it.second;
				s.insert({dist[it.first],it.first});
				parent[it.first] = x.second;
			}
		}
	}
	return cost;
}
