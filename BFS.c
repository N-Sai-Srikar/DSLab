#include <stdio.h>
#define N 5
void bfs(int adj[N][N], int start)
{
int visited[N] = {0}, q[N], f = 0, r = 0;
int i, node; // ? Declare before the loop
q[r++] = start;
visited[start] = 1;
while (f < r)
{
node = q[f++];
printf("%c\t", node + 65);
for (i = 0; i < N; i++)

{

if(adj[node][i] == 1 && visited[i] == 0)

{
q[r++] = i;
visited[i] = 1;
}
}
}
}
int main()
{
int adj[N][N];
int i, j; // ? Declare before the loop
printf("Enter adjacency matrix:\n");
for (i = 0; i < N; i++)
for (j = 0; j < N; j++)
scanf("%d", &adj[i][j]);
bfs(adj, 0);
return 0;
}
