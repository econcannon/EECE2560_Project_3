#include "dictionary.hpp"


template <typename T>
void swap(T& word, T& other)
{
    T temp = word;
    word = other;
    other = temp;
}


void Dictionary::readFile()
{
    int word_size;
    ifstream myfile(dicFile);
    if (myfile.is_open())
    {
        string line;
        while(getline(myfile, line))
        {
            word_size = line.size();
            if (word_size > longest_word)
            {
                longest_word = word_size;
            }
            words.push_back(line);
        }
    }
    dict_size = words.size();
    myfile.close();
}


void Dictionary::printWords()
{
    for(int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
}


void Dictionary::printWordByNumber()
{
    cout << "size of words_by_letter_count: " << words_by_letter_count.size() << endl;
    for (int i = 0; i < words_by_letter_count.size(); i++)
    {
        for (int j = 0; j < words_by_letter_count[i].size(); j++)
        {
            if (i == 10){
            cout << words_by_letter_count[i][j] << " ";
            }
        }
    }
}


int Dictionary::searchWords(string word, int low, int high)
{
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (words[mid] == word)
      return mid;

    // Search the left half
    if (words[mid] > word)
      return searchWords(word, low, mid - 1);

    // Search the right half
    else
    {
    return searchWords(word, mid + 1, high);
    }
  }

  return -1;
}


void Dictionary::selectionSort()
{
    cout << endl << "sorting..." << endl;
    int min_idx;   
    for(int i = 0; i < words.size() - 1; i++)
    {
        min_idx = i;
        for(int j = i+1; j < words.size(); j++)
        {
            if (words[min_idx] > words[j]) {min_idx = j;}
        }
        swap(words[min_idx], words[i]);
    }
    cout << endl << "Done sorting..." << endl;
}


void Dictionary::split_by_letter_count()
{
    int max_word_length = 6;
    int popped_words = 0;
    int dict_size = words.size();
    cout << "dict_size: " << dict_size << endl;
    vector<string> vec;
    for (int j = 0; j < max_word_length - 5; j++)
    {
        vec.clear();
        for(int i = 0; i < dict_size - popped_words; i++)
        {
            if (words[i].size() > max_word_length) 
            {
                max_word_length = words[i].size(); 
                cout << "Longest_Word: " << max_word_length;
            }
            if (words[i].size() == j+5)
            {
            vec.push_back(words[i]);
            swap(words[i], words[dict_size-1-popped_words]);
            popped_words++;
            }
        }
        cout << "size of vec: " << vec.size() << endl;
        words_by_letter_count.push_back(vec);
        cout << "size of words_by_letter_count: " << words_by_letter_count.size() << endl;
    }
}