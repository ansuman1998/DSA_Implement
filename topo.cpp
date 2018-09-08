#include<bits/stdc++.h>
using namespace std;
void explore_node(int i,unordered_set<int> &visited, vector<int> *adj,stack<int>&ans)
{
	for(int j=0;j<adj[i].size();j++)
		if(visited.find(adj[i][j])==visited.end())
			{
				visited.insert(adj[i][j]);
				explore_node(adj[i][j],visited,adj,ans);
			}
	ans.push(i);

}
int main()
{
	int n,e,u,v;
	cin>>n>>e;
	vector<int>adj[n];
	stack<int> ans;
	unordered_set<int> visited;
	while(e!=0)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		e--;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		
		if(visited.find(i)==visited.end())
			{
				cout<<"Entering "<<i<<endl;
				visited.insert(i);
				explore_node(i,visited,adj,ans);
			}
	}
	while(!ans.empty())
	{
		cout<<ans.top()<<endl;
		ans.pop();
	}
}