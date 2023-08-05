#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> roadLengths(N);
    vector<int> roadSpeeds(N);
    vector<int> bessieLengths(M);
    vector<int> bessieSpeeds(M);

    // Read the road segments
    for (int i = 0; i < N; i++)
    {
        cin >> roadLengths[i] >> roadSpeeds[i];
    }

    // Read Bessie's journey segments
    for (int i = 0; i < M; i++)
    {
        cin >> bessieLengths[i] >> bessieSpeeds[i];
    }

    // Calculate cumulative lengths and speeds for both road and Bessie's journey
    vector<int> roadCumulativeLengths(N);
    vector<int> bessieCumulativeLengths(M);
    vector<int> bessieCumulativeSpeeds(M);

    roadCumulativeLengths[0] = roadLengths[0];
    for (int i = 1; i < N; i++)
    {
        roadCumulativeLengths[i] = roadCumulativeLengths[i - 1] + roadLengths[i];
    }

    bessieCumulativeLengths[0] = bessieLengths[0];
    bessieCumulativeSpeeds[0] = bessieSpeeds[0];
    for (int i = 1; i < M; i++)
    {
        bessieCumulativeLengths[i] = bessieCumulativeLengths[i - 1] + bessieLengths[i];
        bessieCumulativeSpeeds[i] = bessieSpeeds[i];
    }

    int maxOverSpeedLimit = 0;
    int roadIdx = 0;
    int bessieIdx = 0;

    // Compare the segments of road and Bessie's journey
    while (roadIdx < N && bessieIdx < M)
    {
        int roadLen = roadCumulativeLengths[roadIdx];
        int bessieLen = bessieCumulativeLengths[bessieIdx];
        int roadSpeedLimit = roadSpeeds[roadIdx];
        int bessieSpeed = bessieCumulativeSpeeds[bessieIdx];

        // Check if Bessie's speed exceeds the road's speed limit
        if (bessieLen <= roadLen)
        {
            maxOverSpeedLimit = max(maxOverSpeedLimit, bessieSpeed - roadSpeedLimit);
            bessieIdx++;
        }
        else
        {
            roadIdx++;
        }
    }

    cout << maxOverSpeedLimit << endl;

    return 0;
}
