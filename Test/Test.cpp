#include <iostream>
#include <fstream>  
#include <string.h>    
#include <cstring>

using namespace std;

void createFile(char* name, ofstream& fout);
void readeFile(char* name, ifstream& fin);
void analys(char* firstName, char* secondName, ifstream& fin, ifstream& gfin);
void output(int countString, int countWord, int countSymbolOfWord, bool checkSymbol);

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream fout, gout;
    ifstream fin, gfin;
    char fileNameF[10], fileNameH[10], answer, userSymbol;
    cout << "Введите название файла f : ";
    cin >> fileNameF;
    cout << "Введите название файла g : ";
    cin >> fileNameH;
    cout << "Вы желаете создать файл? y/n : ";
    cin >> answer;
    if (answer == 'y') {
        createFile(fileNameF, fout);
        createFile(fileNameH, gout);
    }
    readeFile(fileNameF, fin);
    readeFile(fileNameH, gfin);
    analys(fileNameF, fileNameH, fin, gfin);
}

void createFile(char* name, ofstream& fout) {
    cout << "Введите ваши данные : " << endl;
    fout.open(name);
    char read[40];
    cin.getline(read, 40);
    while (read[0] != '*') {
        fout << read;
        fout << "\n";
        cin.getline(read, 40);
    }
    fout.close();
}


void readeFile(char* name, ifstream& fin) {
    cout << "Ваши данные : " << endl;
    fin.open(name);
    char st[40];
    if (fin.eof())
    {
        fin.clear();
        fin.seekg(0);
    }
    fin.seekg(0);
    while (!fin.eof()) {
        fin.getline(st, 40);
        cout << st << endl;
    }
    fin.close();
}

void analys(char* firstName, char* secondName, ifstream& fin, ifstream& gout) {
    fin.open(firstName);
    gout.open(secondName);

    int countString = 0, i = 0, countSymbolOfWord, countWord = 0;
    bool check = false;

    while (!gout.eof()) {
        countString++;
        countSymbolOfWord = 0;
        i = 0;
        char st[40], sts[40];

        st[0] = '\0';
        sts[0] = '\0';

        gout.getline(sts, 40);
        fin.getline(st, 40);
       

        while (i < strlen(sts) && sts[i] != ' ') {
            countSymbolOfWord++;
            if (sts[i] != st[i]) {
                check = true;
                output(countString, countWord, countSymbolOfWord, true);
                break;
            }
            i++;
        }
        if (check == true) {
            break;
        }

        

        countWord++;
        
    }

    fin.close();
    gout.close();
}

void output(int countString, int countWord, int countSymbolOfWord, bool checkSymbol) {
    cout << "Ваш номер строки : " << countString << endl;
    cout << "Ваш номер слова : " << countWord << endl;
    if (checkSymbol) {
        cout << "Ваш символ : " << countSymbolOfWord << endl;
    }

}