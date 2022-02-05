#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int i = 0;
//start_for:
//if (i < N) {
//
//
//    i++;
//    goto start_for;
//}

//start_while:
//if (true) {
//
//    goto start_while;
//}

/*
int main()
{
    int N = 10, file_size;
    char* chars;
    char** words;
    ifstream file("some_text.txt");
    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    cout << file_size << endl;
    chars = new char[file_size];

    int max_words = file_size / 4;
    words = new char* [max_words];

    int i1 = 0;
    start_for1:
    if (i1 < max_words) {
        words[i1] = new char[file_size];

        int j1 = 0;
        start_for2:
        if (j1 < file_size) {
            words[i1][j1] = '$';
            j1++;
            goto start_for2;
        }

        i1++;
        goto start_for1;
    }

    file.read(chars, file_size);

    int i2 = 0, word_i = 0, word_char_i = 0;
    bool is_word = false;
    start_for3:
    if (i2 < file_size) {
        if ((chars[i2] >= 'a' && chars[i2] <= 'z') || (chars[i2] >= 'A' && chars[i2] <= 'Z') || chars[i2] == '\'') {
            is_word = true;
        }
        else {
            if (is_word) {
                word_i++;
                word_char_i = 0;
                is_word = false;
            }
        }

        if (is_word) {
            if (chars[i2] >= 'A' && chars[i2] <= 'Z') {
                words[word_i][word_char_i] = chars[i2]  - 'A' + 'a';
            }
            else {
                words[word_i][word_char_i] = chars[i2];
            }
            word_char_i++;
        }
    
        i2++;
        goto start_for3;
    }

    int i3 = 0;
    start_for4:
    if (i3 < max_words) {
        cout << words[i3][0] << words[i3][1] << words[i3][2] << words[i3][3] << words[i3][4] << words[i3][5] << words[i3][6] << words[i3][7] << endl;
    
        i3++;
        goto start_for4;
    }
    
    int i = 0;
    start_for:
    if (i < file_size) {
        cout << chars[i];
        i++;
        goto start_for;
    }

    delete[] chars;
    file.close();
}*/

int main() {
    int N = 10, file_size;
    ifstream file("some_text.txt");
    string text = "";

    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    int max_words = file_size / 4;
    string* words = new string[max_words];
    string* unique_words = new string[max_words];
    int* word_count = new int[max_words];

    int i = 0;
    start_for:
    if (i < max_words) {
        word_count[i] = 0;
    
        i++;
        goto start_for;
    }

    start_while:
    if (!file.eof()) {
        string s = "";
        getline(file, s);
        text += s + '\n';
        goto start_while;
    }

    int i1 = 0, word_i = 0;
    bool is_word = false;
    start_for1:
    if (i1 < text.size()) {
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
        goto start_for1;
    }

    int i3 = 0;
    start_while1:
    if (words[i3] != "") {
        int i4 = 0;
        if (words[i3].size() < 4) {
            goto word_exist;
        }

        start_while2:
        if (unique_words[i4] != "") {
            if (words[i3] == unique_words[i4]) {
                word_count[i4]++;
                goto word_exist;
            }

            i4++;
            goto start_while2;
        }
        else {
            unique_words[i4] = words[i3];
            word_count[i4]++;
        }

        word_exist:

        i3++;
        goto start_while1;
    }

    /*int i2 = 0;
    start_for2:
    if (i2 < max_words) {
        cout << words[i2] << endl;

        i2++;
        goto start_for2;
    }*/

    int i6 = 0;
    start_for4:
    if (i6 < N) {
        string max_unique_word;
        int max_word_count = 0;
        int max_i7 = 0;

        int i7 = 0;
        start_while5:
        if (unique_words[i7] != "") {
            if (word_count[i7] > max_word_count) {
                max_unique_word = unique_words[i7];
                max_word_count = word_count[i7];
                max_i7 = i7;
            }
            i7++;
            goto start_while5;
        }

        word_count[max_i7] = -word_count[max_i7];
        cout << max_unique_word << "   " << max_word_count << endl;
    
        i6++;
        goto start_for4;
    }

    /*int i5 = 0;
    start_while3:
    if (unique_words[i5] != "") {
        cout << unique_words[i5] << "   " << word_count[i5] << endl;
        i5++;
        goto start_while3;
    }*/

    //cout << text << endl;

    file.close();
}