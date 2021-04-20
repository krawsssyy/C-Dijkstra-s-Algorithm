#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("dijkstra2.in");
ofstream g("dijkstra2.out");

const int DMAX=250005;
const int INF=(1<<30);

int n,m,p,x,y,c;
int D[DMAX];
bool InCoada[DMAX];
vector < pair <int,int> > G[DMAX];

struct compara{
    bool operator()(int a,int b)
    {
        return D[a] > D[b];
    }
};

priority_queue<int, vector<int>, compara> Coada;

void Citire()
{
    f >> n >> m >> p;
    for(int i=0;i<m;i++)
    {f >> x >> y >> c;
     G[x].push_back(make_pair(y,c));
     G[y].push_back(make_pair(x,c));
    }
}

void Dijkstra(int nodP)
{
for(int i=1;i<=n;i++)
    D[i]=INF;
 D[nodP]=0;
    Coada.push(nodP);
    InCoada[nodP]=true;
    while(!Coada.empty())
    {
        int nodC=Coada.top();
        Coada.pop();
        InCoada[nodC]=false;
        for(size_t i=0;i<G[nodC].size();i++)
        {
            int Vecin=G[nodC][i].first;
            int Cost=G[nodC][i].second;
            if(D[nodC]+Cost < D[Vecin])
            {
                D[Vecin]=D[nodC]+Cost;
             if(InCoada[Vecin]==false)
                 {
                 Coada.push(Vecin);
                 InCoada[Vecin]=true;
                 }
            }
        }
    }
}

void Afisare()
{
    for(int i=1;i<=n;i++)
    {
       if(D[i]!=INF)
           g << D[i] << " ";
        else
           g << "-1 ";
    }
}

int main()
{
    Citire();
    Dijkstra(p);
    Afisare();
    return 0;
}
