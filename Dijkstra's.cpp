#include<iostream>
#include<fstream>
#include<utility>
#include<queue>
#include<vector>
typedef std::pair<int,int> ip;
typedef std::pair<int,std::pair<int,int>> ix;
using namespace std;
int main()
{
    cout<<"***Dijkstra's Algorithm***"<<endl<<endl;
    std::fstream inputFile;
    inputFile.open("in.txt",ios::in);

    int u,v,d;
    int noOfEdges, noOfNodes;

    inputFile>>noOfNodes>>noOfEdges;
    int costOfNode[noOfNodes];
    int visited[noOfNodes];
    int parentOfNode[noOfNodes];
    std::vector<ix> vectorArray[noOfNodes];
    for(int i=0 ; i<noOfNodes ; i++)
    {
        costOfNode[i]=100000;
        visited[i]=0;
        parentOfNode[i]=i;

    }
    for(int i =0 ; i<noOfEdges ; i++)
    {
        inputFile>>u>>v>>d;
        ip pair1 = make_pair(u,v);

        vectorArray[u].push_back(make_pair(abs(d),pair1));
    }
    int source,destination;
    inputFile>>source>>destination;
    priority_queue<ip,vector<ip>,greater<ip>> pq;
    cout<<"Root node  : "<<source<<endl;
    cout<<"Destination node  : "<<destination<<endl;
    costOfNode[source]=0;
    pq.push(make_pair(costOfNode[source],source));

    while(!pq.empty())
    {
        ip value =pq.top();
        int vertex = value.second;
        pq.pop();
        visited[vertex]=1;
        {
            for(int i=0 ; i<vectorArray[vertex].size(); i++)
            {
                ix adjVertex = vectorArray[vertex].at(i);
                ip secondPair = adjVertex.second;
                int secondVertex= secondPair.second;
                if(visited[secondVertex]==0)
                {
                    if(adjVertex.first+costOfNode[vertex] < costOfNode[secondVertex])
                    {
                        costOfNode[secondVertex] = adjVertex.first+costOfNode[vertex];
                        pq.push(make_pair(costOfNode[secondVertex],secondVertex));
                        parentOfNode[secondVertex]=vertex;

                    }
                }

            }
        }

    }
    cout<<"Path : ";
    int target=destination;
    while(parentOfNode[target]!=target){
        cout<<target<<" <-";
        target=parentOfNode[target];
    }
    cout<<target<<endl;
    cout<<"Shortest path from node "<<source<<" to node "<<destination<<" is : "<<costOfNode[destination];

    return 0 ;




}
