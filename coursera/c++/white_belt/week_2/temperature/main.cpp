#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int findMean(vector<int>& v) {
    int sum = accumulate(v.begin(), v.end(), 0);
    int mean = sum / v.size();
    return mean;
}

void findIndexMoreMean(vector<int>& v, int& mean) {
    int i = 0;
    vector<int> indexes;
    for(const auto& num : v) {
        if(num > mean) {
            indexes.push_back(i);
        }
        ++ i;
    }
    cout << indexes.size() << endl;
    for(const auto& index : indexes) {
        cout << index << ' ';
    }
}

int main() {
    int n, num;
    vector<int> v;
    cin >> n;

    while(n) {
        cin >> num;
        v.push_back(num);
        -- n;
    }

    int mean = findMean(v);
    findIndexMoreMean(v, mean);
    return 0;
}
