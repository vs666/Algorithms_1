#include<iostream>
#include<bits/stdc++.h>

// KOSARAJU Algorithm


using namespace std;
typedef long long ll;

const ll MAX = (ll) 1e5 + 10;
vector<ll> g[MAX], gR[MAX];
int ranking = 0 ;
vector<pair<ll,bool>> data(MAX,{-1,false});
vector<bool> visited(MAX,false);
void dfs(int node)
{
	visited[node] = true;
	for(auto x : gR[node])
	{
		if(data[x].first==-1 && visited[x] == false){
			dfs(x);
		}
	}
	data[node].first = ranking++;
}

void run(ll node)
{
	if(data[node].second)
	{
		return;
	}
	cout << node << " ";
	data[node].second = true;
	for(auto x : g[node])
	{
		run(x);
	}
}


int main()
{
	ll n,m;
	cin >> n >> m;
	for(int x=0;x<m;x++)
	{
		ll a,b;
		cin >> a >> b;
		g[a].push_back(b);
		gR[b].push_back(a);
	}
	for(int x=1;x<=n;x++)
	{
		if(data[x].first==-1){
			dfs(x);
		}
	}
	priority_queue<pair<ll,ll>> pq;
	for(int x=1;x<=n;x++)
	{
		pq.push({data[x].first,x});
	}
	ll count = 0;
	while(!pq.empty())
	{
		ll node = pq.top().second;
		run(node);
		cout << endl;	
		count++;
		while(!pq.empty() && data[pq.top().second].second){
			pq.pop();
		}
	}
	cout << "The graph has " << count << " strongly connected components in it " << endl;
}
