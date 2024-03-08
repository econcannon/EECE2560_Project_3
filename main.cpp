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
    string other_word;
    for (int i = 0; i < g.dim1; i++)
    {
        for (int j = 0; j < g.dim2; j++)
        {
            // Look Right
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (j+k < g.dim2)
                {
                    other_word += g.grid[i][j+k];
                    
                }
                else
                {
                    other_word += g.grid[i][j+k-g.dim2];
                }
                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }

            // Look Left
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (j-k >= 0)
                {
                    other_word += g.grid[i][j-k];
                    
                }
                else
                {
                    other_word += g.grid[i][j-k+g.dim2];
                }
                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }

            // Look Up
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i-k >= 0)
                {
                    other_word += g.grid[i-k][j];
                    
                }
                else
                {
                    other_word += g.grid[i-k+g.dim1][j];
                }
                
                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }

            // Look Down
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i+k < g.dim1)
                {
                    other_word += g.grid[i+k][j];
                    
                }
                else
                {
                    other_word += g.grid[i+k-g.dim1][j];
                }
                
                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }

            // Look Diagonal Down Right
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i+k < g.dim1 & j+k < g.dim2)
                {
                    other_word += g.grid[i+k][j+k];
                    
                }
                else if (i+k < g.dim1 & j+k >= g.dim2)
                {
                    other_word += g.grid[i+k][j+k-g.dim2];
                }
                else if (i+k >= g.dim1 & j+k < g.dim2)
                {
                    other_word += g.grid[i+k-g.dim1][j+k];
                }
                else if (i+k >= g.dim1 & j+k >= g.dim2)
                {
                    other_word += g.grid[i+k-g.dim1][j+k-g.dim2];
                }

                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }


            // Look Diagonal Down Left
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i+k < g.dim1 & j-k >= 0)
                {
                    other_word += g.grid[i+k][j-k];
                }
                else if (i+k < g.dim1 & j-k < 0)
                {
                    other_word += g.grid[i+k][j-k+g.dim2];
                }
                else if (i+k >= g.dim1 & j-k >= 0)
                {
                    other_word += g.grid[i+k-g.dim1][j-k];
                }
                else if (i+k >= g.dim1 & j-k < 0)
                {
                    other_word += g.grid[i+k-g.dim1][j-k+g.dim2];
                }

                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }

            // Look Diagonal Up Right
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i-k >= 0 & j+k < g.dim2)
                {
                    other_word += g.grid[i-k][j+k];
                    
                }
                else if (i-k >= 0 & j+k >= g.dim2)
                {
                    other_word += g.grid[i-k][j+k-g.dim2];
                }
                else if (i-k < 0 & j+k < g.dim2)
                {
                    other_word += g.grid[i-k+g.dim1][j+k];
                }
                else if (i-k < 0 & j+k >= g.dim2)
                {
                    other_word += g.grid[i-k+g.dim1][j+k-g.dim2];
                }

                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
                    }
                }
            }


            // Look Diagonal Up Left
            other_word = "";
            for (int k = 0; k < d.longest_word; k++)
            {
                if (i-k >= 0 & j-k >= 0)
                {
                    other_word += g.grid[i-k][j-k];
                }
                else if (i-k >= 0 & j-k < 0)
                {
                    other_word += g.grid[i-k][j-k+g.dim2];
                }
                else if (i-k < 0 & j-k >= 0)
                {
                    other_word += g.grid[i-k+g.dim1][j-k];
                }
                else if (i-k < 0 & j-k < 0)
                {
                    other_word += g.grid[i-k+g.dim1][j-k+g.dim2];
                }

                if (other_word.size() >= 5)
                {
                    result = d.searchWords(other_word, 0, d.dict_size);
                    if (result != -1)
                    {
                        found_words.push_back(other_word);
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
    g.gridFile = "input50-1-1";
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