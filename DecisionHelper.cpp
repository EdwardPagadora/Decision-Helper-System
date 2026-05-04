#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int numOptions, numCriteria;

    cout << "=== DecisionHelper ===\n\n";

    // INPUT OPTIONS
    cout << "Enter number of options: ";
    cin >> numOptions;

    vector<string> options(numOptions);
    cin.ignore();

    for (int i = 0; i < numOptions; i++) {
        cout << "Option " << i + 1 << ": ";
        getline(cin, options[i]);
    }

    // INPUT CRITERIA + WEIGHTS
    cout << "\nEnter number of criteria: ";
    cin >> numCriteria;

    vector<string> criteria(numCriteria);
    vector<float> weights(numCriteria);

    cin.ignore();

    for (int i = 0; i < numCriteria; i++) {
        cout << "Criterion " << i + 1 << ": ";
        getline(cin, criteria[i]);

        cout << "Weight for " << criteria[i] << ": ";
        cin >> weights[i];
        cin.ignore();
    }

    // INPUT RATINGS
    vector<vector<float>> ratings(numOptions, vector<float>(numCriteria));

    cout << "\nEnter ratings:\n";

    for (int i = 0; i < numOptions; i++) {
        cout << "\n" << options[i] << ":\n";

        for (int j = 0; j < numCriteria; j++) {
            cout << "  " << criteria[j] << ": ";
            cin >> ratings[i][j];
        }
    }

    // CALCULATE SCORES
    vector<float> scores(numOptions, 0);

    for (int i = 0; i < numOptions; i++) {
        for (int j = 0; j < numCriteria; j++) {
            scores[i] += ratings[i][j] * weights[j];
        }
    }

    // DISPLAY RESULTS
    cout << "\n===== RESULTS =====\n";

    int bestIndex = 0;

    for (int i = 0; i < numOptions; i++) {
        cout << options[i] << " - Score: "
             << fixed << setprecision(2)
             << scores[i] << endl;

        if (scores[i] > scores[bestIndex]) {
            bestIndex = i;
        }
    }

    cout << "\nBest Option: " << options[bestIndex] << endl;

    return 0;
}