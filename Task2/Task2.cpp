#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int page_size = 45;
    ifstream file("some_book.txt");
    string text = "";

    string s;
    read_file:
    if (!file.eof()) {
        s = "";
        getline(file, s);
        text += s + '\n';
        goto read_file;
    }

    int max_words = text.size();
    string* words = new string[max_words];
    string* unique_words = new string[max_words];

    int* words_pages = new int[max_words];

    int i = 0;
    initialize_words_pages:
    if (i < max_words) {
        words_pages[i] = 0;
        i++;
        goto initialize_words_pages;
    }

    int* words_count = new int[max_words];

    int i2 = 0;
    initialize_words_count:
    if (i2 < max_words) {
        words_count[i2] = 0;

        i2++;
        goto initialize_words_count;
    }

    int line = 0;
    int i1 = 0, word_i = 0;
    bool is_word = false;
    text_traversal:
    if (i1 < text.size()) {
        if ((text[i1] >= 'a' && text[i1] <= 'z') || (text[i1] >= 'A' && text[i1] <= 'Z')) {
            is_word = true;
        }
        else {
            if (is_word) {
                words_pages[word_i] = line / page_size + 1;
                word_i++;
                is_word = false;
            }
        }

        if (text[i1] == '\n') {
            line++;
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

    bool was_replased = true;
    string temp_word = "";
    int temp_count = 0;
    sort:
    if (was_replased) {
        was_replased = false;
        int i5 = 0;
        step:
        if (words_count[i5 + 1] > 0 && i5 + 1 < max_words) {
            if (unique_words[i5] > unique_words[i5 + 1]) {
                temp_word = unique_words[i5];
                unique_words[i5] = unique_words[i5 + 1];
                unique_words[i5 + 1] = temp_word;

                temp_count = words_count[i5];
                words_count[i5] = words_count[i5 + 1];
                words_count[i5 + 1] = temp_count;
                was_replased = true;
            }

            i5++;
            goto step;
        }
        goto sort;
    }

    int i6 = 0;
    print_words_and_pages:
    if (i6 < 20) {
        if (words_count[i6] < 100) { 
            cout << unique_words[i6] << " - ";
            int i7 = 0;
            print_pages:
            if (words[i7] != "") {
                
                if (words[i7] == unique_words[i6]) {
                    cout << words_pages[i7] << ' ';
                }

                i7++;
                goto print_pages;
            }
            cout << endl;
        }

        i6++;
        goto print_words_and_pages;
    }

    file.close();
}

