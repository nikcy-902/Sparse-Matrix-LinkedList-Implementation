#include <iostream>
#include <vector>
using namespace std;

/*
  Sparse Matrix (Linked List representation)
  - Stores only non-zero entries as nodes: (row, col, val)
  - Keeps nodes in row-major order by appending during dense -> sparse conversion
*/

struct Node {
    int r, c, v;
    Node* next;
    Node(int row, int col, int val) : r(row), c(col), v(val), next(nullptr) {}
};

class SparseMatrixLL {
private:
    int rows, cols;
    int nonzeros;
    Node* head;
    Node* tail;

public:
    SparseMatrixLL(int R, int C) : rows(R), cols(C), nonzeros(0), head(nullptr), tail(nullptr) {}

    ~SparseMatrixLL() { clear(); }

    void clear() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
        tail = nullptr;
        nonzeros = 0;
    }

    void append(int r, int c, int v) {
        if (v == 0) return;
        Node* n = new Node(r, c, v);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        nonzeros++;
    }

    // Build from a dense matrix (vector of vectors)
    void fromDense(const vector<vector<int>>& A) {
        clear();
        rows = (int)A.size();
        cols = rows ? (int)A[0].size() : 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (A[i][j] != 0) append(i, j, A[i][j]);
            }
        }
    }

    // Print triplet form: header + (r, c, v) per non-zero
    void printTriplets() const {
        cout << "rows cols nonzeros: " << rows << " " << cols << " " << nonzeros << "\n";
        cout << "r c v\n";
        for (Node* p = head; p; p = p->next) {
            cout << p->r << " " << p->c << " " << p->v << "\n";
        }
    }

    // Reconstruct and print dense matrix
    void printDense() const {
        vector<vector<int>> A(rows, vector<int>(cols, 0));
        for (Node* p = head; p; p = p->next) {
            A[p->r][p->c] = p->v;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << A[i][j] << (j + 1 == cols ? '\n' : ' ');
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cout << "Enter rows and cols: ";
    if (!(cin >> R >> C) || R <= 0 || C <= 0) {
        cerr << "Invalid dimensions.\n";
        return 1;
    }

    cout << "Enter matrix values (" << R << "x" << C << "):\n";
    vector<vector<int>> dense(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> dense[i][j];
        }
    }

    SparseMatrixLL sm(R, C);
    sm.fromDense(dense);

    cout << "\nSparse (triplets):\n";
    sm.printTriplets();

    cout << "\nReconstructed dense matrix:\n";
    sm.printDense();

    return 0;
}
