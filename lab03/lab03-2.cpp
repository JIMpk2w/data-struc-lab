#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    double sumScore1 = 0, sumScore2 = 0, sumScore3 = 0;
    double score1[num+1], score2[num+1], score3[num+1];

    for (int i = 0; i < num; i++) {
        cin >> score1[i] >> score2[i] >> score3[i];
        sumScore1 += score1[i];
        sumScore2 += score2[i];
        sumScore3 += score3[i];
    }

    double totalMean = (sumScore1 + sumScore2 + sumScore3) / num;

    for (int i = 0; i < num; i++) {
        int count = 0;

        if (score1[i] >= sumScore1 / num) {
            count++;
        } if (score2[i] >= sumScore2 / num) {
            count++;
        } if (score3[i] >= sumScore3 / num) {
            count++;
        }

        if (count > 1 && (score1[i] > 0 && score2[i] > 0 && score3[i] > 0) && score1[i] + score2[i] + score3[i] >= totalMean) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}