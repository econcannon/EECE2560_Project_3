#include "grid.hpp"

void Grid::readLetters()
{

    ifstream myfile(gridFile);
    if (myfile.is_open())
    {
        cout << "File is open" << endl;
        myfile >> dim1 >> dim2;
        cout << "dim1: " << dim1 << endl;
        cout << "dim2: " << dim2 << endl;

        char c;
        for (int i = 0; i < dim1; i++)
        {
            vector<char> rows;
            for (int j = 0; j < dim2; j++)
            {
                myfile >> c;
                rows.push_back(c);
            }
            grid.push_back(rows);
        }


        myfile.close();
        return;
    }
    return;
};


void Grid::printLetters()
{
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}