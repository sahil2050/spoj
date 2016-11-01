//  Author           :   Sahil Aggarwal
//
//  Problem Name	:   MaxFlow 
//  Project Name    :   Learning
//  Date            :   01/11/2016
//
//  Algorithm       :   Ford Fulkerson and Edmond Karp Algorithm
//  Time/Space      :   O(EC),O(VE2)/O(V+E)
//
//  Copyright (c) 2015 Sahil Aggarwal.
//  All rights reserved.
//_____________________________________________

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int const N = 1e3; // max no of vertices
int const inf =1e9;
vector<int> G[N];
int M[N][N];
int P[N]; // parent array
int n,m,source,sink,maxflow; // no of vertices and edges respectively and sorce,sink

bool dfs(){
	memset(P,-1,sizeof(P));
	stack<int> s;
	s.push(source);
	P[source] = source;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];
			if(P[v] == -1 && M[u][v]>0){
				s.push(v);
				P[v] = u;
			}
		}
	}
	return P[sink]!=-1;
}

bool bfs(){
	memset(P,-1,sizeof(P));
	queue<int> q;
	q.push(source);
	P[source] = source;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];
			if(P[v] == -1 && M[u][v]>0){
				q.push(v);
				P[v] = u;
			}
		}
	}
	return P[sink]!=-1;
}

int maxFlow(int flag){ // 0-> ford fulkerson; 1-> edmond karp
	maxflow = 0;
	while(1){
		bool cont;
		if(flag == 0)cont = dfs();
		else cont = bfs();
		if(!cont)break;
		int v =sink,f = inf;
		while(v!=source){
			f = min(f,M[P[v]][v]);
			v = P[v];
		}
		maxflow+=f; // augment flow
		v =sink;
		while(v!=source){
			M[P[v]][v] -= f;
			M[v][P[v]] += f;
			v = P[v];
		}
	}
	return maxflow;
}
int main(){
	printf("Enter no of vertices and edges\n");
	scanf("%d %d",&n,&m);
	memset(M,0,sizeof(M));
	printf("Enter edges in format (from to cap)\n");
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[u].pb(v),G[v].pb(u);
		M[u][v] = w;
	}
	printf("Enter source and sink vertex separated by space\n");
	scanf("%d %d",&source,&sink);
	printf("Enter 0 for Ford Fulkerson or 1 for Edmond Karp\n");
	int flag;scanf("%d",&flag);
	printf("Maxflow is %d\n",maxFlow(flag&1));
}