#include <bits/stdc++.h>
using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int totalUnits;
        cin >> totalUnits;

        vector<pair<int, int>> schedule(totalUnits);
        vector<int> effortValues(totalUnits);
        vector<list<int>> sequenceList(totalUnits);

        for (int x = 0; x < totalUnits; x++)
        {
                int initTime, finalTime, workload;
                cin >> initTime >> finalTime >> workload;

                schedule[x] = {initTime, finalTime};
                effortValues[x] = workload;
                sequenceList[x].push_back(x + 1);

                for (int y = 0; y < x; y++)
                {
                        if (schedule[y].second <= schedule[x].first)
                        {
                                if (effortValues[y] + workload > effortValues[x])
                                {
                                        effortValues[x] = effortValues[y] + workload;
                                        sequenceList[x] = sequenceList[y];
                                        sequenceList[x].push_back(x + 1);
                                }
                        }
                }
        }
        auto maxUnit = max_element(effortValues.begin(), effortValues.end());
        int peakIndex = distance(effortValues.begin(), maxUnit);
        int peakValue = *maxUnit;

        cout << peakValue << endl;

        cout << sequenceList[peakIndex].size() << endl;
        for (int each : sequenceList[peakIndex])
        {
                cout << each << " ";
        }
        cout << endl;

        return 0;
}
