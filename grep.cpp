//=================================================================
//Hassan Shahzad
//18i-0441
//CS(A)
//Algorithms Assignment 3(b)
//=================================================================


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std::chrono;

using namespace std;

// Fills a_lps[] for given patttern a_pattern[0..n-1] 
void generateLPSArray(char* a_pattern, int n, int* a_lps) {
    int len = 0;
    a_lps[0] = 0;
    int i = 1;
    while (i < n) {
        if (a_pattern[i] == a_pattern[len]) {
            len++;
            a_lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = a_lps[len - 1];
            }
            else {
                a_lps[i] = 0;
                i++;
            }

        }
    }
}
void PatternSearch(char* a_pattern, char* text, int line_no)
{
    int n = strlen(a_pattern);
    int N = strlen(text);
    int a_lps[30];//It will hold the longest preffix suffex

    // Preprocess the pattern in 
    generateLPSArray(a_pattern, n, a_lps);//generates the a_lps array

    int i = 0;
    int j = 0; //index for a_pattern[]
    while (i < N) {
        if (a_pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == n) {
            printf("\nIndex = %d \t Line No =  %d", i - j, line_no);
            j = a_lps[j - 1];
        }
        else if (i < N && a_pattern[j] != text[i]) {

            if (j != 0)
                j = a_lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void grep(string filename)
{
    char a_textLine[1000];
    char a_pattern[] = "said";
    FILE* fptr;

    filename += ".txt";

    if ((fptr = fopen(filename.c_str(), "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    int i = 1;
    while (!feof(fptr)) {
        fgets(a_textLine, 150, fptr);
        //puts(a_textLine);


        PatternSearch(a_pattern, a_textLine, i);
        i++;
    }
    fclose(fptr);
    // Close the file
}

int main()
{
    string filenames[12] = { "01_the_ugly_duckling", "02_the_little_pine_tree", "03_the_little_match_girl", "04_little_red_riding_hood", "05_the_apples_of_idun", "06_how_thor_got_the_hammer", "07_the_hammer_lost_and_found", "08_the_story_of_the_sheep", "09_the_good_ship_argo", "10_jason_and_the_harpies", "11_the_brass_bulls", "12_jason_and_the_dragon" };
    cout << "String = 'said'\n" << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 12; i++)
    {
        cout << "File Number " << i+1 << " = " << filenames[i] << endl;
        cout << "========================================" << endl;
        grep(filenames[i]);
        cout <<endl<< "========================================"<<endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}