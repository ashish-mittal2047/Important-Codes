const ll N = 1e5 + 5;

class edge
{
	public:
		ll u,v,w;
		edge(ll _u, ll _v,ll _w)
		{
			u = _u, v = _v, w = _w;
		}
};

ll n,m;
ll connected;
ll root[N], sz[N];
vector<pair<ll,ll>> adj[N];
vector<edge> edges;

void init()
{
	for(ll i = 0;i<n;i++)
	{
		root[i] = i;
		sz[i] = 1;
	}
	connected = n;
}

ll rt(ll k)
{
	while(root[k]!=k)
	{
		k = root[k];
	}
	return k;
}

void merge(ll u, ll v)
{
	ll rt1 = rt(u);
	ll rt2 = rt(v);
	if(rt1 == rt2)
		return;

	connected--;
	if(sz[rt1]>sz[rt2])
		swap(rt1,rt2);

	sz[rt2] += sz[rt1];
	sz[rt1] = 0;
	root[rt1] = root[rt2];
}

bool comp(edges &e1,edges &e2)
{
	return e1.w < e2.w;
}

ll kruskalMST()
{
	init();
	ll cost = 0;
	sort(edge.begin(),edge.end(),comp);
	for(ll i = 0;i<m;i++)
	{
		ll u = edges[i].u, v = edges[i].v, w = edges[i].w;
		ll rt1 = rt(u), rt2 = rt(v);
		if(rt1 == rt2)
		{
			continue;
		}
		else
		{
			cost += w;
			merge(u,v);
		}
	}
	return cost;
}


//Problem 1 (Kruskal + Flow): https://codeforces.com/gym/101667 : Problem E
//Solution 1: http://p.ip.fi/HHLC

//Problem 2: https://www.spoj.com/problems/KOICOST/
//Solution 2:https://ide.geeksforgeeks.org/6jIgKO84dn


