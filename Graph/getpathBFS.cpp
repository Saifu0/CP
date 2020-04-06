#include<bits/stdc++.h>
using namespace std;
vector<int> print(int **edge,int V, bool *visit,int x,int y)
{
   // int start=x;
    int flag=0;
    queue<int>q;
    q.push(x);
    visit[x]=true;
    map<int ,int>m;
    //cout<<start;
    while(!q.empty())
    {
        int start=q.front();
        for(int i=0;i<V;i++)
        {
            if(edge[start][i]==1 && visit[i]==false)
            {
               q.push(i);
               visit[i]=true;
                m[i]=start;
                if (i == y) 
                {
                    flag = 1;
                    break;       
                }
                
            }       
        //cout<<start<<" ";
        
       }
        q.pop();
        
    }
    if(flag==0)
        return vector<int>();
    vector<int>v;
    v.push_back(y);
    int t=y;
    while(t!=x)
    {
        v.push_back(m.at(t));
        t=m.at(t);
    }
    return v;
    
}

int main() {
    int V, E;
    cin >> V >> E;
    int x,y;
    int **edge= new int*[V];
    for(int i=0;i<V;i++)
    {
        edge[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edge[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int s,f;
        cin>>s>>f;
        edge[s][f]=1;
        edge[f][s]=1;
    }
    cin>>x>>y;
    
    bool *visit=new bool[V];
    for(int i=0;i<V;i++)
        visit[i]=false;
    
    vector<int>v=print(edge,V,visit,x,y);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}


