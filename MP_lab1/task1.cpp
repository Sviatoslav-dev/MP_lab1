#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int stop_words_lengh = 3;
    int N = 25;
    ifstream file("some_text.txt");
    string text = "";
    
    string s;
    read_file:
    if (!file.eof()) {
        s = "";
        getline(file, s);
        text += s + '\n';
        goto read_file;
    }

    int max_words = text.size() / 2;
    string* words = new string[max_words];
    string* unique_words = new string[max_words];
    int* words_count = new int[max_words];

    int i = 0;
    initilize_word_count:
    if (i < max_words) {
        words_count[i] = 0;

        i++;
        goto initilize_word_count;
    }

    int i1 = 0, word_i = 0;
    bool is_word = false;
    text_traversal:
    if (text[i1] != '\0') {
        if ((text[i1] >= 'a' && text[i1] <= 'z') || (text[i1] >= 'A' && text[i1] <= 'Z') || text[i1] == '\'') {
            is_word = true;
        }
        else {
            if (is_word) {
                word_i++;
                is_word = false;
            }
        }

        if (is_word) {
            if (text[i1] >= 'A' && text[i1] <= 'Z') {
                words[word_i] += text[i1] - 'A' + 'a';
            }
            else {
                words[word_i] += text[i1];
            }
        }

        i1++;
        goto text_traversal;
    }

    int i3 = 0;
    words_traversal:
    if (words[i3] != "") {
        int i4 = 0;
        if (words[i3].size() <= stop_words_lengh) {
            goto miss_word;
        }

        unique_words_traversal:
        if (unique_words[i4] != "") {
            if (words[i3] == unique_words[i4]) {
                words_count[i4]++;
                goto miss_word;
            }

            i4++;
            goto unique_words_traversal;
        }
        else {
            unique_words[i4] = words[i3];
            words_count[i4]++;
        }

        miss_word:

        i3++;
        goto words_traversal;
    }

    int i6 = 0;
    sort:
    if (i6 < N) {
        string max_unique_word;
        int max_word_count = 0;
        int max_i7 = 0;

        int i7 = 0;
        step:
        if (unique_words[i7] != "") {
            if (words_count[i7] > max_word_count) {
                max_unique_word = unique_words[i7];
                max_word_count = words_count[i7];
                max_i7 = i7;
            }
            i7++;
            goto step;
        }

        words_count[max_i7] = -words_count[max_i7];
        cout << max_unique_word << "   " << max_word_count << endl;
    
        i6++;
        goto sort;
    }

    delete[] words;
    delete[] unique_words;
    delete[] words_count;
    file.close();
}