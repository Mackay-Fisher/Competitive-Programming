#include "AlgorithimHelp.h"

void dijkstra(const unordered_map<ll, vector<pair<ll, ll> > > &graph, ll startNode, ll endNode, vector<ll> &distanceVec)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    distanceVec[startNode] = 0;
    pq.push(make_pair(0, startNode));

    while (!pq.empty())
    {
        ll current_vertex = pq.top().second;
        cout << "Current vertex: " << current_vertex << endl;
        pq.pop();

        // If we've reached the target, we can stop early
        if (current_vertex ==  endNode)
            break;

        for (const auto &edge : graph.at(current_vertex))
        {
            ll next_vertex = edge.first;
            ll weight = edge.second;
            cout << "Next vertex: " << next_vertex << " Weight: " << weight << endl;
            if (distanceVec[current_vertex] + weight <= distanceVec[next_vertex])
            {
                distanceVec[next_vertex] = distanceVec[current_vertex] + weight;
                pq.push(make_pair(distanceVec[next_vertex], next_vertex));
            }
        }
    }
}