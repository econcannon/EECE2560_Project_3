#include "grid.hpp"
#include "dictionary.hpp"


/**
 * @brief This method was my first attempt, goes through every word in the dictionary and checks if it exists.
 * Was determined to be slower than the final method using complexity analysis since it is directly 
 * proportional to the length of the dictionary.
 * 
 * @param grid: The grid object containing the wordsearch letters
 * @param word: The current word being checked
 * @return true if word exists in wordsearch
 * @return false if word does not exist in word search
 */
bool searchWord(Grid grid, string word)
{
    int word_len = word.size();
    string other_word;
    //cout << "Checking " << word << "...\t";
    for (int i = 0; i < grid.dim1; i++)
    {
        for (int j = 0; j < grid.dim2; j++)
        {
            // Check first letter
            other_word = "";
            other_word += grid.grid[i][j];
            string first_letter(word, 0, 1);
            //cout << "first_letter: " << other_word << "\t";
            if (other_word != first_letter)
            {
                //cout << "skipped... \t";
                continue;
            }
            // Look Right
            //cout << "Looking Right... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (j+k < grid.dim2)
                {
                    other_word += grid.grid[i][j+k];
                    
                }
                else
                {
                    other_word += grid.grid[i][j+k-grid.dim2];
                }

                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << " Temp_word: " << temp_word << "\t";
        
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    //cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }

            // Look Left
            //cout << "Looking Left... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (j-k >= 0)
                {
                    other_word += grid.grid[i][j-k];
                    
                }
                else
                {
                    other_word += grid.grid[i][j-k+grid.dim2];
                }
                
                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    //cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }

            // Look Up
            //cout << "Looking Up... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i-k >= 0)
                {
                    other_word += grid.grid[i-k][j];
                    
                }
                else
                {
                    other_word += grid.grid[i-k+grid.dim1][j];
                }
                
                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }

            // Look Down
            //cout << "Looking Down... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i+k < grid.dim1)
                {
                    other_word += grid.grid[i+k][j];
                    
                }
                else
                {
                    other_word += grid.grid[i+k-grid.dim1][j];
                }
                
                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }

            // Look Diagonal Down Right
            //cout << "Looking Down Right... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i+k < grid.dim1 & j+k < grid.dim2)
                {
                    other_word += grid.grid[i+k][j+k];
                    
                }
                else if (i+k < grid.dim1 & j+k >= grid.dim2)
                {
                    other_word += grid.grid[i+k][j+k-grid.dim2];
                }
                else if (i+k >= grid.dim1 & j+k < grid.dim2)
                {
                    other_word += grid.grid[i+k-grid.dim1][j+k];
                }
                else if (i+k >= grid.dim1 & j+k >= grid.dim2)
                {
                    other_word += grid.grid[i+k-grid.dim1][j+k-grid.dim2];
                }

                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }


            // Look Diagonal Down Left
            //cout << "Looking Down Left... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i+k < grid.dim1 & j-k >= 0)
                {
                    other_word += grid.grid[i+k][j-k];
                    
                }
                else if (i+k < grid.dim1 & j-k < 0)
                {
                    other_word += grid.grid[i+k][j-k+grid.dim2];
                }
                else if (i+k >= grid.dim1 & j-k >= 0)
                {
                    other_word += grid.grid[i+k-grid.dim1][j-k];
                }
                else if (i+k >= grid.dim1 & j-k < 0)
                {
                    other_word += grid.grid[i+k-grid.dim1][j-k+grid.dim2];
                }

                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }


            // Look Diagonal Up Right
            //cout << "Looking Up Right... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i-k >= 0 & j+k < grid.dim2)
                {
                    other_word += grid.grid[i-k][j+k];
                    
                }
                else if (i-k >= 0 & j+k >= grid.dim2)
                {
                    other_word += grid.grid[i-k][j+k-grid.dim2];
                }
                else if (i-k < 0 & j+k < grid.dim2)
                {
                    other_word += grid.grid[i-k+grid.dim1][j+k];
                }
                else if (i-k < 0 & j+k >= grid.dim2)
                {
                    other_word += grid.grid[i-k+grid.dim1][j+k-grid.dim2];
                }

                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
            }


            // Look Diagonal Up Left
            //cout << "Looking Up Left... \t";
            other_word = "";
            for (int k = 0; k < word_len; k++)
            {
                if (i-k >= 0 & j-k >= 0)
                {
                    other_word += grid.grid[i-k][j-k];
                }
                else if (i-k >= 0 & j-k < 0)
                {
                    other_word += grid.grid[i-k][j-k+grid.dim2];
                }
                else if (i-k < 0 & j-k >= 0)
                {
                    other_word += grid.grid[i-k+grid.dim1][j-k];
                }
                else if (i-k < 0 & j-k < 0)
                {
                    other_word += grid.grid[i-k+grid.dim1][j-k+grid.dim2];
                }

                string temp_word(word, 0, other_word.size());
                //cout << "Other_word: " << other_word << "\t";
                if (temp_word != other_word)
                {
                    break;
                }
                if(other_word == word)
                {
                    cout << "located at: " << i << " " << j << endl;
                    return true;
                }
                
            }


        }
    }
    //cout << "Not Found \t";
    return false;
}



/**
 * @brief Finds every combination of letters between length 5 and the longest word in the dictionary. Checks
 * if it exists in the dictionary using binary search. Therefore, time complexity is proportional to log(n)
 * where n is the number of words in the dictionary. 
 * 
 * @param g: The grid object containing the wordsearch letters
 * @param d: The dictionary object containing every valid word
 * @return vector<string>: Contains the valid words found within the wordsearch
 */
vector<string> searchWord(Grid g, Dictionary d)
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


/**
 * @brief Auxillary function for the initial search method that iterates through the dictionary to check
 * every word.
 * 
 * @param g: The grid object containing the wordsearch letters
 * @param d: The dictionary object containing every valid word
 */
void findMatches(Grid& grid, Dictionary& dict)
{
    cout << endl << "Searching..." << endl;
    for (int i = 0; i < dict.words.size(); i++)
    {   
        if (dict.words[i].size() >= 5)
        {
            if (searchWord(grid, dict.words[i]))
            {
                cout << "FOUND " << dict.words[i] << " ";
            }
        }
    }
    cout << endl << "Done Searching..." << endl;
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
    //d.split_by_letter_count();
    //d.printWordByNumber();
    d.selectionSort();
    //d.printWords();
    //d.printWordByNumber();
    //findMatches(g, d);
    vector<string> found_words = searchWord(g, d);
    cout << "Found words: ";
    for(int i = 0; i < found_words.size(); i++)
    {
        cout << endl << found_words[i];
    }
    // int result = d.searchWords("livid", 0, d.words.size()-1);
    // cout << result << endl;
    // if (result != -1)
    // {
    //     cout << d.words[result];
    // }
    return 0;
}