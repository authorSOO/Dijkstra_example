#include <vector>
#include <cstdio>
using namespace std;

struct Edge
{
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
    /* data */
};

vector<Edge> a[1001];
int dist[1001];
int inf = 1000000000;
bool check[1001];

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int start, to, cost;
        scanf("%d %d %d", &start, &to, &cost);
        a[start].push_back(Edge(to, cost));
    }

    for (int i = 1; i <= n; i++)
        dist[i] = inf;

    int start, end;
    scanf("%d %d", &start, &end);
    dist[start] = 0;
    for (int k = 0; k < n - 1; k++)
    {
        int m = inf + 1;
        int x = -1;
        for (int i = 1; i <= n; i++)
        {
            if (check[i] == false && m > dist[i])
            {
                m = dist[i];
                x = i;
            }
        }
        check[x] = true;
        for (int i = 0; i < a[x].size(); i++)
        {
            int y = a[x][i].to;
            if (dist[y] > dist[x] + a[x][i].cost)
                dist[y] = dist[x] + a[x][i].cost;
        }
    }
    printf("%d", dist[end]);
    return 0;
}
