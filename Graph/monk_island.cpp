#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n , m, x, y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector< int >g[n+1];
        for(int i = 0 ; i < m ; i ++){
            cin>>x>>y;
            g[y].push_back(x);
            g[x].push_back(y);
        }
        queue < int > q;
        bool visitados[n+1];
        int distancia[n+1];
        int start = 1;
        distancia[start]=0;
        q.push(start);
        memset(visitados, false, sizeof visitados);
        visitados[start]=true;
        int flag=0;
        while(!q.empty()&&flag==0){
                int nodo=q.front();
                //cout<<"fila = "<<nodo<<endl;
                //cout<<"tam = "<<g[nodo].size()<<endl;
                for(int i = 0 ; i < g[nodo].size(); i++){
                    //cout<<"analizando a "<<g[nodo][i]<<" ban "<<visitados[g[nodo][i]]<<endl;
                    if(visitados[g[nodo][i]]==true&&nodo!=n)continue;
                    distancia[g[nodo][i]]=distancia[nodo]+1;
                    if(g[nodo][i]==n){
                        cout<<distancia[g[nodo][i]]<<endl;
                        flag=1;
                        break;
                    }
                    //cout<<"se metio a la fila "<<g[nodo][i]<<endl;
                    q.push(g[nodo][i]);
                    //cout<<"se baneo "<<g[nodo][i]<<endl;
                    visitados[g[nodo][i]]=true;
                }
                q.pop();
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n , m, x, y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector< int >g[n+1];
        for(int i = 0 ; i < m ; i ++){
            cin>>x>>y;
            g[y].push_back(x);
            g[x].push_back(y);
        }
        queue < int > q;
        bool visitados[n+1];
        int distancia[n+1];
        int start = 1;
        distancia[start]=0;
        q.push(start);
        memset(visitados, false, sizeof visitados);
        visitados[start]=true;
        int flag=0;
        while(!q.empty()&&flag==0){
                int nodo=q.front();
                //cout<<"fila = "<<nodo<<endl;
                //cout<<"tam = "<<g[nodo].size()<<endl;
                for(int i = 0 ; i < g[nodo].size(); i++){
                    //cout<<"analizando a "<<g[nodo][i]<<" ban "<<visitados[g[nodo][i]]<<endl;
                    if(visitados[g[nodo][i]]==true&&nodo!=n)continue;
                    distancia[g[nodo][i]]=distancia[nodo]+1;
                    if(g[nodo][i]==n){
                        cout<<distancia[g[nodo][i]]<<endl;
                        flag=1;
                        break;
                    }
                    //cout<<"se metio a la fila "<<g[nodo][i]<<endl;
                    q.push(g[nodo][i]);
                    //cout<<"se baneo "<<g[nodo][i]<<endl;
                    visitados[g[nodo][i]]=true;
                }
                q.pop();
        }
    }
}
