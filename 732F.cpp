#include<bits/stdc++.h>
using namespace std;
const int MAX=4e5+9;
int n,m,mark[MAX],d[MAX],f[MAX];
vector<pair<int,int> > g[MAX];
vector<pair<pair<int,int>,pair<int,int> > > h[MAX];
pair<int,int> ans[MAX];
int root(int v){return f[v]<0?v:f[v]=root(f[v]);}
void merge(int v,int u)
{
	if ((v=root(v))==(u=root(u))) return ;
	f[v]+=f[u],f[u]=v;
}
int dfs(int v,int p=-1)
{
	mark[v]=1;
	int ret=d[v];
	for (auto u:g[v])
		if (!mark[u.first])
		{
			d[u.first]=d[v]+1;
			int k=dfs(u.first,v);
			if (k<=d[v]) merge(v,u.first),ans[u.second]={v,u.first},ret=min(ret,k);
		} 
		else 
		if (u.first!=p && d[u.first]<d[v]) ret=min(ret,d[u.first]),merge(v,u.first),ans[u.second]={v,u.first};
	return ret;
}	
int sz[MAX],be[MAX];
set<pair<int,int> > s;
int main()
{
	memset(f,-1,sizeof f);
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=0,v,u;i<m;i++) cin>>v>>u,v--,u--,g[v].push_back({u,i}),g[u].push_back({v,i});
	dfs(0);
	for (int i=0;i<n;i++)
		for (auto u:g[i])
			if (root(i)!=root(u.first))
				h[root(i)].push_back({{root(u.first),u.second},{i,u.first}});
	for (int i=0;i<n;i++) if (f[i]<0) sz[i]=-f[i],s.insert({sz[i],i});
	while (s.size())
	{
		auto v=(*s.rbegin());
		s.erase(v),be[v.second]=1;
		for (auto u:h[v.second])
			if (!be[u.first.first])	
				s.erase({sz[u.first.first],u.first.first}),sz[u.first.first]+=sz[v.second],s.insert({sz[u.first.first],u.first.first}),ans[u.first.second]={u.second.second,u.second.first};
	}
	int res=1e9;
	for (int i=0;i<n;i++) res=min(res,sz[root(i)]);
	cout<<res<<'\n';
	for (int i=0;i<m;i++) cout<<ans[i].first+1<<" "<<ans[i].second+1<<'\n';
}