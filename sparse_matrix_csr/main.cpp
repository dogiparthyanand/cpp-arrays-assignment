#include <iostream>
#include <vector>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    vector<int> valArray;
    vector<int> colPos;
    vector<int> rowStart;

public:
    SparseMatrix(const vector<vector<int>>& dense) {
        rows = dense.size();
        cols = rows ? dense[0].size() : 0;
        build(dense);
    }

    void build(const vector<vector<int>>& dense) {
        rowStart.assign(rows + 1, 0);
        valArray.clear();
        colPos.clear();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dense[i][j] != 0) {
                    valArray.push_back(dense[i][j]);
                    colPos.push_back(j);
                }
            }
            rowStart[i + 1] = valArray.size();
        }
    }

    void showCSR() const {
        cout << "Values: ";
        for (int v : valArray) cout << v << " ";
        cout << "\nColPos: ";
        for (int c : colPos) cout << c << " ";
        cout << "\nRowStart: ";
        for (int r : rowStart) cout << r << " ";
        cout << endl;
    }

    vector<int> multiply(const vector<int>& vec) const {
        if (vec.size() != cols) throw invalid_argument("Vector size mismatch");

        vector<int> result(rows, 0);
        for (int i = 0; i < rows; i++) {
            // debug: cout << "Row " << i << " starts at " << rowStart[i] << " ends at " << rowStart[i+1] << endl;
            for (int idx = rowStart[i]; idx < rowStart[i+1]; idx++) {
                result[i] += valArray[idx] * vec[colPos[idx]];
            }
        }
        return result;
    }

    int countNonZero() const { return valArray.size(); }
};

int main() {
    vector<vector<int>> dense = {
        {5, 0, 0, 8},
        {0, 0, 7, 0},
        {0, 2, 0, 0},
        {4, 0, 0, 0}
    };

    SparseMatrix sm(dense);
    cout << "CSR form:\n";
    sm.showCSR();

    vector<int> x = {1, 2, 3, 4};
    vector<int> res = sm.multiply(x);

    cout << "\nMultiply result:\n";
    for (int v : res) cout << v << " ";
    cout << "\n\nNon-zeros counted: " << sm.countNonZero() << endl;

    return 0;
}
