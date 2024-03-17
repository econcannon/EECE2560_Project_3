#include <fstream>
#include <vector>
#include <iostream>

#ifndef GRID_HPP
#define GRID_HPP

using namespace std;
class Grid
{
    private:
    public:
        Grid(){};
        int dim1, dim2;
        string gridFile;
        vector<vector<char>> grid;
        void readLetters();
        void printLetters();
};

#endif