#include <iostream>
#include <random>
#include "menu.h"
#include "placar.h"

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

using std::cout;
using std::cin;
using std::endl;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

enum {Pedra = 1, Papel, Tesoura};
enum {Perder = 1, Empate, Ganhar};

void Menu()
{
    int escolha;
    char resp = 'S';

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 3);
    int escolhaCPU = dis(gen);

    int resultado[3][3] = 
    {
        {Empate, Perder, Ganhar},
        {Ganhar, Empate, Perder},
        {Perder, Ganhar, Empate}
    };

    while(resp != 'n' && resp != 'N')
    {
        cout << "======================\n";
        cout << "\tJokenpo\n";
        cout << "======================\n\n";

        cout << "1) Pedra\n";
        cout << "2) Papel\n";
        cout << "3) Tesoura\n\n";

        cout << "Sua escolha: ";
        cin >> escolha;

        while(escolha != 1 && escolha != 2 && escolha != 3)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(100,'\n');
            }

            cout << "Digite novamente sua opcao: ";
            cin >> escolha;
        }

        cout << "Voce escolheu: ";
        switch (escolha)
        {
            case Pedra:
                cout << "Pedra" << endl;
                break;
            case Papel:
                cout << "Papel" << endl;
                break;
            case Tesoura:
                cout << "Tesoura" << endl;
                break;
        }

        cout << "A CPU escolheu: ";
        switch (escolhaCPU)
        {
            case Pedra:
                cout << "Pedra" << endl;
                break;
            case Papel:
                cout << "Papel" << endl;
                break;
            case Tesoura:
                cout << "Tesoura" << endl;
                break;
        }

        int res = resultado[escolha - 1][escolhaCPU - 1];

        Placar(res);

        cout << "Deseja continuar (S/N)? ";
        cin >> resp;

        while(resp != 'n' && resp != 'N' && resp != 's' && resp != 'S')
        {
            cout << "Digite novamente sua opcao: ";
            cin >> resp;
        }

        system(CLEAR_COMMAND);
    }
}