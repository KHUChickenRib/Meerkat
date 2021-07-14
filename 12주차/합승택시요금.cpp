#include <string>
#include <vector>
#include <queue>

#define INF 10000000

using namespace std;

// 인접행렬 초기화
void initGraph(vector<vector<int>>& fares, vector<pair<int, int>>* graph) {
    int src, dst, dist; // src: 출발점, dst: 도착점, dist: 가중치
    int i;
    
    for (i = 0; i < fares.size(); i++) {
        src = fares[i][0];
        dst = fares[i][1];
        dist = fares[i][2];
        
        graph[src].push_back({dst, dist});
        graph[dst].push_back({src, dist});
    }
}

// 다익스트라 알고리즘
vector<int> dijkstra(int n, int start, vector<pair<int, int>>* graph) {
    vector<int> result(n+1, INF);           // 결과 저장 vector (start에서 모든 곳)
    priority_queue<pair<int, int>> pq;      // 우선순위 큐
    int dst, dist;
    int next, nextdist;
    int i;
    
    pq.push({0, start});
    result[start] = 0;      // 출발지 비용은 0으로
    
    // 우선순위 큐에서 pop, push 반복하여 최소비용 개선
    while (!pq.empty()) {
        dist = -pq.top().first;
        dst = pq.top().second;
        
        pq.pop();
        
        if (result[dst] < dist)
            continue;
        
        for (i = 0; i < graph[dst].size(); i++) {
            next = graph[dst][i].first;
            nextdist = graph[dst][i].second;
            
            if (result[next] > result[dst] + nextdist) {
                result[next] = result[dst] + nextdist;
                pq.push({-result[next], next});
            }
        }
    }
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> dist;           // 각 출발지에서의 최소비용 저장
    vector<pair<int, int>> graph[201];  // 인접행렬
    vector<int> t;                      // 0번째 index 임시저장
    int temp, i;
    
    initGraph(fares, graph);

    // 0번째 임시저장
    for (i = 0; i < n; i++)
        t.push_back(0);
    dist.push_back(t);
    
    // 1번 출발지 ~ n번 출발지 최소비용 저장 (다익스트라 알고리즘)
    for (i = 1; i <= n; i++)
        dist.push_back(dijkstra(n, i, graph));
    

    // 최소비용계산
    answer = dist[s][1] + dist[1][a] + dist[1][b];
    for (i = 2; i <= n; i++) {
        temp = dist[s][i] + dist[i][a] + dist[i][b];
        
        if (answer > temp)
            answer = temp;
    }
    
    return answer;
}