#include <bits/stdc++.h>
using namespace std;
 
#define ROW_1 6
#define COL_1 6
 
#define ROW_2 6
#define COL_2 6
 
void print(string display, vector<vector<int> > matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}
 
vector<vector<int> >
add_matrix(vector<vector<int> > A,
           vector<vector<int> > B, int s_index,
           int multiplier = 1)
{
    for (auto i = 0; i < s_index; i++)
        for (auto j = 0; j < s_index; j++)
            A[i][j]
                = A[i][j]
                  + (multiplier * B[i][j]);
    return A;
}
 
vector<vector<int> >
multiply_matrix(vector<vector<int> > A,
                vector<vector<int> > B)
{
    int col_1 = A[0].size();
    int row_1 = A.size();
    int col_2 = B[0].size();
    int row_2 = B.size();
 
    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix "
                "A  are not equal to the number of rows in "
                "Matrix B\n";
        return {};
    }
 
    vector<int> Res_row(col_2, 0);
    vector<vector<int> > Res(row_1,
                                       Res_row);
 
    if (col_1 == 1)
        Res[0][0]
            = A[0][0] * B[0][0];
    else {
        int s_index = col_1 / 2;
 
        vector<int> row_vector(s_index, 0);
 
        vector<vector<int> > a00(s_index, row_vector);
        vector<vector<int> > a01(s_index, row_vector);
        vector<vector<int> > a10(s_index, row_vector);
        vector<vector<int> > a11(s_index, row_vector);
        vector<vector<int> > b00(s_index, row_vector);
        vector<vector<int> > b01(s_index, row_vector);
        vector<vector<int> > b10(s_index, row_vector);
        vector<vector<int> > b11(s_index, row_vector);
 
        for (auto i = 0; i < s_index; i++)
            for (auto j = 0; j < s_index; j++) {
                a00[i][j] = A[i][j];
                a01[i][j] = A[i][j + s_index];
                a10[i][j] = A[s_index + i][j];
                a11[i][j] = A[i + s_index]
                                    [j + s_index];
                b00[i][j] = B[i][j];
                b01[i][j] = B[i][j + s_index];
                b10[i][j] = B[s_index + i][j];
                b11[i][j] = B[i + s_index]
                                    [j + s_index];
            }
 
        vector<vector<int> > p(multiply_matrix(
            a00, add_matrix(b01, b11, s_index, -1)));
        vector<vector<int> > q(multiply_matrix(
            add_matrix(a00, a01, s_index), b11));
        vector<vector<int> > r(multiply_matrix(
            add_matrix(a10, a11, s_index), b00));
        vector<vector<int> > s(multiply_matrix(
            a11, add_matrix(b10, b00, s_index, -1)));
        vector<vector<int> > t(multiply_matrix(
            add_matrix(a00, a11, s_index),
            add_matrix(b00, b11, s_index)));
        vector<vector<int> > u(multiply_matrix(
            add_matrix(a01, a11, s_index, -1),
            add_matrix(b10, b11, s_index)));
        vector<vector<int> > v(multiply_matrix(
            add_matrix(a00, a10, s_index, -1),
            add_matrix(b00, b01, s_index)));
 
        vector<vector<int> > Res_00(add_matrix(
            add_matrix(add_matrix(t, s, s_index), u,
                       s_index),
            q, s_index, -1));
        vector<vector<int> > Res_01(
            add_matrix(p, q, s_index));
        vector<vector<int> > Res_10(
            add_matrix(r, s, s_index));
        vector<vector<int> > Res_11(add_matrix(
            add_matrix(add_matrix(t, p, s_index), r,
                       s_index, -1),
            v, s_index, -1));
 
        for (auto i = 0; i < s_index; i++)
            for (auto j = 0; j < s_index; j++) {
                Res[i][j]
                    = Res_00[i][j];
                Res[i][j + s_index]
                    = Res_01[i][j];
                Res[s_index + i][j]
                    = Res_10[i][j];
                Res[i + s_index]
                             [j + s_index]
                    = Res_11[i][j];
            }
 
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
        p.clear();
        q.clear();
        r.clear();
        s.clear();
        t.clear();
        u.clear();
        v.clear();
        Res_00.clear();
        Res_01.clear();
        Res_10.clear();
        Res_11.clear();
    }
    return Res;
}
 
int main()
{
    vector<vector<int> > A = { { 1, 1, 1, 1, 4, 6 },
                                      { 2, 2, 2, 2, 7, 9 },
                                      { 3, 3, 3, 3, 8, 20 },
                                      { 2, 5, 7, 9, 5, 11 },
                                      { 5, 6, 3, 11, 6, 1 },
                                      { 2, 2, 2, 2, 50, 7 } };
 
    print("Array A", A, 0, 0, ROW_1 - 1, COL_1 - 1);
 
    vector<vector<int> > B = { { 1, 1, 1, 1, 4, 9 },
                                      { 2, 2, 2, 2, 7, 8 },
                                      { 4, 6, 7, 8, 10, 4 },
                                      { 2, 5, 7, 9, 5, 11 },
                                      { 3, 3, 3, 3, 14, 6 },
                                      { 2, 2, 2, 2, 7, 11 } };
 
    print("Array B", B, 0, 0, ROW_2 - 1, COL_2 - 1);
 
    vector<vector<int> > Res(
        multiply_matrix(A, B));
 
    print("Result Array", Res, 0, 0, ROW_1 - 1,
          COL_2 - 1);
}