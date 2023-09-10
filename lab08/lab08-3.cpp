#include <iostream>
#include <vector>

using namespace std;

vector<int> cityParent;
vector<int> citySize;

int findCity(int x) {
    if (cityParent[x] == x)
        return x;
    return cityParent[x] = findCity(cityParent[x]);
}

void uniteCities(int a, int b) {
    a = findCity(a);
    b = findCity(b);
    if (a != b) {
        if (citySize[a] < citySize[b])
            swap(a, b);
        cityParent[b] = a;
        citySize[a] += citySize[b];
    }
}

int main() {
    int numCities, numRoads;
    cin >> numCities >> numRoads;
    
    cityParent.resize(numCities + 1);
    citySize.resize(numCities + 1, 1);
    
    for (int i = 1; i <= numCities; i++) {
        cityParent[i] = i;
    }
    
    for (int i = 0; i < numRoads; i++) {
        int cityA, cityB;
        cin >> cityA >> cityB;
        uniteCities(cityA, cityB);
    }
    
    int minRoads = 0;
    for (int i = 1; i <= numCities; i++) {
        if (findCity(i) == i) {
            minRoads++;
        }
    }
    
    cout << minRoads - 1 << endl;
    
    return 0;
}
