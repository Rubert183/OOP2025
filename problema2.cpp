#include <iostream> // pt a folosi cerr
#include <stdio.h> // pt scanf()
//se putea face de 10000 de ori mai eficient dar am vrut sa scriu prima solutie care mi-a venit in cap
// functia split_str va sparge o propozitie in cuvinte si va returna nr de cuvinte
int split_str(char str[], char words[][101]) // prespunem ca un cuvant nu va avea mai mult de 100 de caractere
{
    int poz = 0, nr_words = 0, ind = 0;
    while (str[ind] != '\0')
    {
        if (str[ind] != ' ')
        {
            words[nr_words][poz++] = str[ind]; 
        }
        else
        {
            words[nr_words][poz] = '\0';
            nr_words++;
            poz = 0;
        }
        ind++;
    }
    words[nr_words][poz] = '\0';
    nr_words++;
    return nr_words;
}

bool smaller_lex(char str1[], char str2[])
{
    int ind = 0;
    while (str1[ind] && str2[ind] && str1[ind] == str2[ind])
    {
        ind++;
    }
    return str1[ind] < str2[ind];
}

int lenght(char str[])
{
    int ind = 0;
    while (str[ind])
    {
        ind++;
    }
    return ind;
}

void sort_words(char words[][101], int nr_words)
{
    for (int ind1 = 0; ind1 < nr_words - 1; ind1++)
    {
        for (int ind2 = ind1 + 1; ind2 < nr_words; ind2++)
        {
            if ((lenght(words[ind1]) < lenght(words[ind2])) || (lenght(words[ind1]) == lenght(words[ind2]) &&
             smaller_lex(words[ind1], words[ind2])))
            {
                std::swap(words[ind1], words[ind2]);
            }
        }
    }
}

void show_words(char words[][101], int nr_words)
{
    for (int ind = 0; ind < nr_words; ind++)
    {
        printf("%s\n", words[ind]);
    }
}

int main()
{
    char str[101]; // propozitia va avea maxim 100 de caractere
    char words[101][101]; // max 101 cuvinte a cate 100 de caractere
    int nr_words;
    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        std::cerr << "Invalid Input!\n";
        return 1;
    }
    if (str[lenght(str)-1] == '\n')
    {  
        str[lenght(str)-1] = '\0';
    }
    nr_words = split_str(str, words);
    sort_words(words, nr_words);
    show_words(words, nr_words);
    return 0;
}
