
bool dfs(int u)
{
	for(int v: adj[u])
	{
		if(vis[v])
		{
			if(col[v] == col[u]) 
			{
				return false;
			}
			else 
			{
				col[v] = !col[u];

				if(dfs(v) == false)
				{
					return false;
				}
			}

		}
	}

	return true;
}

int main()
{
	//read the graph
	col[1] = 0;
	dfs(1);
}