#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimal_cut_cost(int m, int n, vector<int>& vertical_costs, vector<int>& horizontal_costs) {
    // Sort the costs in descending order
    sort(vertical_costs.rbegin(), vertical_costs.rend());
    sort(horizontal_costs.rbegin(), horizontal_costs.rend());

    int vertical_cuts = 1; // Initially there is one vertical piece
    int horizontal_cuts = 1; // Initially there is one horizontal piece
    int total_cost = 0;

    int i = 0, j = 0;

    // Process the cuts by prioritizing the highest costs
    while (i < vertical_costs.size() && j < horizontal_costs.size()) {
        if (vertical_costs[i] >= horizontal_costs[j]) {
            total_cost += vertical_costs[i] * horizontal_cuts;
            vertical_cuts++;
            i++;
        } else {
            total_cost += horizontal_costs[j] * vertical_cuts;
            horizontal_cuts++;
            j++;
        }
    }

    // Add the remaining vertical cuts
    while (i < vertical_costs.size()) {
        total_cost += vertical_costs[i] * horizontal_cuts;
        i++;
    }

    // Add the remaining horizontal cuts
    while (j < horizontal_costs.size()) {
        total_cost += horizontal_costs[j] * vertical_cuts;
        j++;
    }

    return total_cost;
}

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore(); // To consume the newline after the number of test cases

    while (test_cases--) {
        int m, n;
        cin >> m >> n;

        vector<int> vertical_costs(m - 1);
        vector<int> horizontal_costs(n - 1);

        for (int i = 0; i < m - 1; i++) {
            cin >> vertical_costs[i];
        }

        for (int i = 0; i < n - 1; i++) {
            cin >> horizontal_costs[i];
        }

        // Calculate the minimal cost of breaking the chocolate
        cout << minimal_cut_cost(m, n, vertical_costs, horizontal_costs) << endl;

        // Consume the blank line between test cases
        if (test_cases > 0) {
            cin.ignore();
            cin.ignore();
        }
    }

    return 0;
}
