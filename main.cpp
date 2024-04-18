#include <bits/stdc++.h>
#include <conio.h>
// #include "functii.h"

using namespace std;

int main()
{
    // alegere cuvant random din lista de cuvinte cheie a modulului
    srand(time(0));
    int numar_random = rand() % 2309; // inlocuieste 2309 cu nr de linii din cuvinte.txt

    ifstream fin("cuvinte.txt");
    string linie, cuvant_corect;
    int numar_lini = 0;
    while (fin >> linie)
    {
        numar_lini++;
        if (numar_lini == numar_random)
        {
            cuvant_corect = linie;
            break;
        }
    }

    cout << "             HangMan            \n\n";
    //cuvant_corect="abnkab";//test
    int lungime_cuvant = cuvant_corect.length();
    //cout << cuvant_corect << endl; // test
    //declar ca vector si iau doar [0] dar citesc tot vectoru, asa ia doar prima;
    string litera;
    int litere_ghicite[cuvant_corect.length()], nr_greseli = 0, gasit = 0;
    vector<char> litere_gresite;
    int game_over = 0;
    int suma;
    // prima si ultima apar de la joc
    for (int i = 0; i < cuvant_corect.length(); i++)
    {
        if (cuvant_corect[0] == cuvant_corect[i])
        {
            litere_ghicite[i] = 1;
        }
    }
    for (int i = 0; i < cuvant_corect.length(); i++)
    {
        if (cuvant_corect[cuvant_corect.length() - 1] == cuvant_corect[i])
        {
            litere_ghicite[i] = 1;
        }
    }
    cout << "_______" << endl;
    cout << "|     |" << endl;
    cout << "|     " << endl;
    cout << "|     " << endl;
    cout << "|     " << endl;
    cout << "|     " << endl;
    for (int i = 0; i < cuvant_corect.length(); i++)
        {
            if (litere_ghicite[i] == 1)
                cout << cuvant_corect[i] << " ";
            else
                cout << "_ ";
        }


    // cat timp nu se sfarseste jocul
    while (!game_over)
    {   
        cout << "\nIntrodu litera: ";
        cin>>litera;
        system("cls");
        cout << "\n";
        gasit = 0;
        suma = 0;
        // verific daca litera apare in cuvant_corect
        for (int i = 0; i < cuvant_corect.length(); i++)
        {
            if (litera[0] == cuvant_corect[i])
            {
                litere_ghicite[i] = 1;
                gasit = 1;
            }
        }

        if (gasit == 0)
        {
            nr_greseli++;
            litere_gresite.push_back(litera[0]);
        }

        switch (nr_greseli)
        {
        case 0:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            break;
        case 1:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            break;
        case 2:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|     |" << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            break;
        case 3:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|" << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            break;
        case 4:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|     " << endl;
            cout << "|     " << endl;
            break;
        case 5:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|    / " << endl;
            cout << "|     " << endl;
            break;
        case 6:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|    / \\" << endl;
            cout << "|     " << endl;
            break;
        default:
            cout << "Game Over!" << endl;
            game_over = 1;
            break;
        }

        for (int i = 0; i < cuvant_corect.length(); i++)
        {
            if (litere_ghicite[i] == 1)
                cout << cuvant_corect[i] << " ";
            else
                cout << "_ ";
        }
        cout << "\nLitere Gresite: ";
        for (int i = 0; i < litere_gresite.size(); i++)
            cout << litere_gresite[i] << " ";
        cout << "\n";

        for (int i = 0; i < cuvant_corect.length(); i++)
        {
            suma += litere_ghicite[i];
        }

        if (suma == cuvant_corect.length())
            game_over = 2;
    }
    if (game_over== 2)
        cout << "\nFelicitari! Ai Castigat!";

            char ch;
      cout<<endl<<"\nApasati Enter pentru a iesi din program";
    do
     {
      ch = getch();
     }while( ch != char(13) );//13 cod ASCII pt Enter

    return 0;
}
