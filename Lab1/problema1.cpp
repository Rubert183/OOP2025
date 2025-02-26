#include <stdio.h> // imi trebuie pt a folosi fopen
#include <iostream> // imi trebuie pentru a folosi cerr

int str_to_int(char str_nr[])
{
    int nr=0, ind=0;
    while (str_nr[ind] != '\0') // trec prin cifrele numarului
    {
        if (str_nr[ind] >= '0' && str_nr[ind] <= '9') // verfic asta deoarece pot sa am la final de sir un \n
        {
            nr = nr * 10 + (str_nr[ind] - '0');
        }
        ind++;
    }
    return nr;
}

int main()
{
    FILE *fileptr = fopen("in.txt", "r"); // deschid fisierul
    int sum = 0;
    char current_nr[11]; 
    if (fileptr == NULL) // daca au aparut erori la deschiderea fisierului
    {
        std::cerr << "Eroare la deschiderea fisierului";
        return 1;
    }
    while (fgets(current_nr, 11, fileptr)) // trec prin numerele din fisier, am presupus ca nu o am numere de mai mult de 10 cifre + \n
    {
        sum += str_to_int(current_nr);
    }
    printf("Suma numerelor din fisierul in.txt este: %d", sum);
    return 0;
}