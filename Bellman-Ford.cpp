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
    cout<<"***Bellman-Ford's Algorithm***"<<endl<<endl;
    std::fstream inputFile;
    inputFile.open("in.txt",ios::in);


    int u,v,d;
    int noOfEdges, noOfNodes;
    inputFile>>noOfNodes>>noOfEdges;

    int costOfNode[noOfNodes];
    int parentOfNode[noOfNodes];
    std::vector<ix> vectorArray;
    for(int i=0 ; i<noOfNodes ; i++)
    {
        costOfNode[i]=100000;
        parentOfNode[i]=i;

    }

    for(int i =0 ; i<noOfEdges ; i++)
    {
        inputFile>>u>>v>>d;
        ip pairOfEdge = make_pair(u,v);
        vectorArray.push_back(make_pair(d,pairOfEdge));

    }
    int flag=1;
    int source,destination;
    inputFile>>source>>destination;
    cout<<"Root node  : "<<source<<endl;
    cout<<"Destination node  : "<<destination<<endl;
    costOfNode[source]=0;
    for(int i=0 ; i<noOfNodes; i++)
    {
        for(int j=0 ; j<noOfEdges; j++)
        {
            ix pairInVector= vectorArray.at(j);
            ip pairOfEdge =  pairInVector.second;
            if(costOfNode[pairOfEdge.first]+pairInVector.first<costOfNode[pairOfEdge.second])
            {
                costOfNode[pairOfEdge.second] = costOfNode[pairOfEdge.first]+pairInVector.first;
                parentOfNode[pairOfEdge.second]= pairOfEdge.first;
            }
        }
    }
    for(int i=0 ; i<noOfEdges; i++)
    {
        ix pairInVector= vectorArray.at(i);
        ip pairOfEdge =  pairInVector.second;
        if(costOfNode[pairOfEdge.first]+pairInVector.first<costOfNode[pairOfEdge.second])
        {
            cout<<"Negative weight Cycle present "<<endl;
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<"Path : ";
        int target=destination;
        while(parentOfNode[target]!=target)
        {
            cout<<target<<" <-";
            target=parentOfNode[target];
        }
        cout<<target<<endl;
        cout<<"Shortest path from node "<<source<<" to node "<<destination<<" is : "<<costOfNode[destination];
    }
    return 0 ;

}
