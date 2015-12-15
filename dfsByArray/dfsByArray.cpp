#include <iostream>
#define SIZE 6
int visited[SIZE] = {0};
int graph[SIZE][SIZE] = {
	{0,1,1,1,0,0},
	{1,0,0,0,1,0},
	{1,0,0,0,1,0},
	{1,0,0,0,0,1},
	{0,1,1,0,0,0},
	{0,0,0,1,0,0}
};

void dfs(int N)
{
	std::cout<<N<<"->";
	visited[N] = 1;
	for (int i = 0; i < SIZE; ++i)
	{
		if (graph[N][i] && !visited[i])
		{
			dfs(i);		
		}
	}
}
int main(int argc, char const *argv[])
{
	dfs(0);
	return 0;
}