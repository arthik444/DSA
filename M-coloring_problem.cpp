bool isSafe(int j,bool graph[101][101],int color[],int c,int V)
{
	for(int i=0;i<V;i++)
	{
		if(graph[j][i]&&color[i]==c)return false;
	}
	return true;
}
bool find(bool graph[101][101],int m,int s,int V,int color[])
{
    if(s==V)return true;
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(s,graph,color,i,V))
        {
            color[s] = i;
            
            if(find(graph,m,s+1,V,color))return true;
            
            color[s] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101],int m,int V)
{
    int s = 0;
    int color[V] = {0};
    return find(graph,m,s,V,color);
}
