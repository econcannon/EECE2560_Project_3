#include "grid.hpp"
#include "dictionary.hpp"

/**
 * @brief Finds every combination of letters between length 5 and the longest word in the dictionary. Checks
 * if it exists in the dictionary using binary search. Therefore, time complexity is proportional to log(n)
 * where n is the number of words in the dictionary. 
 * 
 * @param g: The grid object containing the wordsearch letters
 * @param d: The dictionary object containing every valid word
 * @return vector<string>: Contains the valid words found within the wordsearch
 */
vector<string> findMatches(Grid g, Dictionary d)
{
    vector<string> found_words;
    int result;
    string other_word1, other_word2, other_word3, other_word4, other_word5, other_word6, other_word7, other_word8;
    for (int i = 0; i < g.dim1; i++)
    {
        for (int j = 0; j < g.dim2; j++)
        {
            other_word1 = other_word2 = other_word3 = other_word4 = other_word5 = other_word6 = other_word7 = other_word8 = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if ((k >= g.dim1) || (k >= g.dim2))
                {
                    break;
                }
                // Look Right   
                if (j+k < g.dim2)
                {
                    other_word1 += g.grid[i][j+k];
                }
                else
                {
                    other_word1 += g.grid[i][j+k-g.dim2];
                }
                if (k >= 4)
                {
                    if (d.searchWords(other_word1, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word1);
                    }
                }

                // Look Left
                if (j-k >= 0)
                {
                    other_word2 += g.grid[i][j-k];
                }
                else
                {
                    other_word2 += g.grid[i][j-k+g.dim2];
                }
                if (k >= 4)
                {
                    if (d.searchWords(other_word2, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word2);
                    }
                }

                // Look Up
                if (i-k >= 0)
                {
                    other_word3 += g.grid[i-k][j];    
                }
                else
                {
                    other_word3 += g.grid[i-k+g.dim1][j];
                }
                
                if (k >= 4)
                {
                    if (d.searchWords(other_word3, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word3);
                    }
                }

                // Look Down
                if (i+k < g.dim1)
                {
                    other_word4 += g.grid[i+k][j];
                }
                else
                {
                    other_word4 += g.grid[i+k-g.dim1][j];
                }
                
                if (k >= 4)
                {
                    if (d.searchWords(other_word4, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word4);
                    }
                }

                // Look Diagonal Down Right
                if (i+k < g.dim1 & j+k < g.dim2)
                {
                    other_word5 += g.grid[i+k][j+k];                   
                }
                else if (i+k < g.dim1 & j+k >= g.dim2)
                {
                    other_word5 += g.grid[i+k][j+k-g.dim2];
                }
                else if (i+k >= g.dim1 & j+k < g.dim2)
                {
                    other_word5 += g.grid[i+k-g.dim1][j+k];
                }
                else if (i+k >= g.dim1 & j+k >= g.dim2)
                {
                    other_word5 += g.grid[i+k-g.dim1][j+k-g.dim2];
                }

                if (k >= 4)
                {
                    if (d.searchWords(other_word5, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word5);
                    }
                }

                // Look Diagonal Down Left
                if (i+k < g.dim1 & j-k >= 0)
                {
                    other_word6 += g.grid[i+k][j-k];
                }
                else if (i+k < g.dim1 & j-k < 0)
                {
                    other_word6 += g.grid[i+k][j-k+g.dim2];
                }
                else if (i+k >= g.dim1 & j-k >= 0)
                {
                    other_word6 += g.grid[i+k-g.dim1][j-k];
                }
                else if (i+k >= g.dim1 & j-k < 0)
                {
                    other_word6 += g.grid[i+k-g.dim1][j-k+g.dim2];
                }

                if (k >= 4)
                {
                    if (d.searchWords(other_word6, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word6);
                    }
                }

                // Look Diagonal Up Right
                if (i-k >= 0 & j+k < g.dim2)
                {
                    other_word7 += g.grid[i-k][j+k];   
                }
                else if (i-k >= 0 & j+k >= g.dim2)
                {
                    other_word7 += g.grid[i-k][j+k-g.dim2];
                }
                else if (i-k < 0 & j+k < g.dim2)
                {
                    other_word7 += g.grid[i-k+g.dim1][j+k];
                }
                else if (i-k < 0 & j+k >= g.dim2)
                {
                    other_word7 += g.grid[i-k+g.dim1][j+k-g.dim2];
                }

                if (k >= 4)
                {
                    if (d.searchWords(other_word7, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word7);
                    }
                }

                // Look Diagonal Up Left
                if (i-k >= 0 & j-k >= 0)
                {
                    other_word8 += g.grid[i-k][j-k];
                }
                else if (i-k >= 0 & j-k < 0)
                {
                    other_word8 += g.grid[i-k][j-k+g.dim2];
                }
                else if (i-k < 0 & j-k >= 0)
                {
                    other_word8 += g.grid[i-k+g.dim1][j-k];
                }
                else if (i-k < 0 & j-k < 0)
                {
                    other_word8 += g.grid[i-k+g.dim1][j-k+g.dim2];
                }

                if (k >= 4)
                {
                    if (d.searchWords(other_word8, 0, d.dict_size) != -1)
                    {
                        found_words.push_back(other_word8);
                    }
                }
            }
        }
    }
    return found_words;
}

int main()
{
    Grid g = Grid();
    g.gridFile = "input15-2";
    g.readLetters();
    g.printLetters();

    Dictionary d = Dictionary();
    d.dicFile = "dictionary-2";
    d.readFile();
    d.selectionSort();
    //d.printWords();
    vector<string> found_words = findMatches(g, d);
    cout << "Found words: ";
    for(int i = 0; i < found_words.size(); i++)
    {
        cout << endl << found_words[i];
    }
    return 0;
}