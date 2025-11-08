#include <bits/stdc++.h>
using namespace std;

void printArrayInWaveForm(vector<vector<int>> &vec)
{
    for (int cols = 0; cols < vec[0].size(); cols++)
    {
        if (cols % 2 == 0)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i][cols] << " ";
            }
        }
        else
        {
            for (int i = vec.size() - 1; i >= 0; i--)
            {
                cout << vec[i][cols] << " ";
            }
        }
    }
}

// using additional array
void transposeMatrix1(vector<vector<int>> &vec)
{
    int rows = vec.size(), cols = vec[0].size();

    vector<vector<int>> v(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v[j][i] = vec[i][j];
        }
    }

    for (auto val : v)
    {
        for (auto res : val)
        {
            cout << res << " ";
        }
        cout << endl;
    }
}

void matrixMultiplication(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
{
    int cols = matrix1[0].size();
    int rows = matrix2.size();
    if (cols != rows)
    {
        cout << "The two matrices cannot be multiplied";
        return;
    }

    vector<vector<int>> vec2D(matrix1.size(), vector<int>(matrix2[0].size()));

    for (int i = 0; i < vec2D.size(); i++)
    {
        for (int j = 0; j < vec2D[i].size(); j++)
        {
            int sum = 0;
            for (int k = 0; k < cols; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            vec2D[i][j] = sum;
        }
    }

    for (auto res : vec2D)
    {
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void setImageZeroes(vector<vector<int>> &matrix)
{
    bool setRow = false, setCol = false;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;

                if (i == 0)
                    setRow = true;
                if (j == 0)
                    setCol = true;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (setRow)
    {
        for (int i = 0; i < setCol; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (setCol)
    {
        for (int i = 0; i < setRow; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

// Inplace -> constant space
void transposeMatrix(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0 + i; j < matrix[i].size(); j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void rotateImage(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int col = 0; col < rows; col++)
    {
        int i = 0;
        int j = rows - 1;
        while (i <= j)
        {
            int temp = matrix[i][col];
            matrix[i][col] = matrix[j][col];
            matrix[j][col] = temp;
            i++;
            j--;
        }
    }
    transposeMatrix(matrix);
}

void spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = rows * cols;
    int sr = 0, sc = 0;
    int er = rows - 1, ec = cols - 1;

    while (count > 0)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout << matrix[sr][i] << " ";
            count--;
        }
        sr++;
        if (count == 0)
            break;

        for (int i = sr; i <= er; i++)
        {
            cout << matrix[i][ec] << " ";
            count--;
        }
        ec--;
        if (count == 0)
            break;

        for (int i = ec; i >= sc; i--)
        {
            cout << matrix[er][i] << " ";
            count--;
        }
        er--;
        if (count == 0)
            break;

        for (int i = er; i >= sr; i--)
        {
            cout << matrix[i][sc] << " ";
            count--;
        }
        sc++;
        if (count == 0)
            break;
    }
}

int main()
{
    vector<vector<int>> matrix1 = {{1, 3}, {4, 5}};
    vector<vector<int>> matrix2 = {{1, 3}, {4, 5}};
    // matrixMultiplication(matrix1, matrix2);

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    // setImageZeroes(matrix);
    // transposeMatrix(matrix);
    spiralOrder(matrix);
    // for (auto res : matrix)
    // {
    //     for (auto val : res)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}