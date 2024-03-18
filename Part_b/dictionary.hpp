#include <iostream>
#include <vector>
#include <fstream>

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

using namespace std;

class Dictionary
{
    public:
        vector<string> words;  
        string dicFile;
        int longest_word;
        int dict_size;
        vector<vector<string>> words_by_letter_count;

        void readFile();
        void printWords();
        void printWordByNumber();
        void selectionSort();
        void split_by_letter_count();
        int searchWords(string word, int low, int high);
        void quickSort(int left, int right);
        void heapSort();
    
    private:
        int partition(int left, int right);
};

#endif