#define NAME "prim"
#define ll long long
#define lli long long int

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100001;

int n,m,par[MaxN],a[MaxN][MaxN];
int key[MaxN];
bool added[MaxN];

void file(void) {
    if(fopen(NAME".inp","r")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

int minKey(int key[], bool added[]) {
    int minn = MaxN, min_index;

    for(int p=1;p<=n;p++) {
        if(added[p] == false && key[p] < minn) {
            minn = key[p]; min_index = p;
        }
    }

    return min_index;
}

void prim(void) {
    int u,v,t;

    cin >> n >> m;

    for(int i=1;i<=m;i++) {
        cin >> u >> v >> t;
        a[u][v] = t;
        a[v][u] = t;
    }

    par[1] = 1;

    for(int i=1;i<=n;i++) {
        key[i] = MaxN; added[i] = false;
    }

    for(int i=1;i<n;i++) {
        int u = minKey(key, added);

        added[u] = true;

        for(int v=1;v<=n;v++) {
            if(a[u][v] && added[v] == false && a[u][v] < key[v]) {
                par[v] = u; key[v] = a[u][v];
                cout << u << " " << v << "\n";
            }
        }
    }

    /*for(int i=1;i<=m;i++) {
        cout << a[i].fst << " " << a[i].scd << " " << a[i].ts << "\n";
    }*/
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    file();

    prim();

    return 0;
}
