#include <iostream>
#include <algorithm>

using namespace std;

int canKill(int monster[100000], int n, long weaponDmg) {
    int count = upper_bound(monster, monster + n, weaponDmg) - monster;
    return count;
}

void hpMonster(int monster[100000], int n) {
    int hp;
    for (int i = 0; i < n; i++) {
        cin >> hp;
        monster[i] = hp;
    }

    sort(monster,monster + n);
}

int main() {
    int n, weapon, monster[100000];

    cin >> n;
    hpMonster(monster, n);

    cin >> weapon;
    for (int i = 0; i < weapon; i++) {
        long weaponDmg;
        cin >> weaponDmg;
        cout << canKill(monster, n, weaponDmg) << endl;
    }
}