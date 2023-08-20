#include <iostream>
#include "placar.h"

void Placar(int ponto)
{
    static int CPU = 0;
    static int player = 0;
    static int empates = 0;
    static int tentativas = 1;

    switch (ponto)
    {
        case Empate: empates++; break;
        case Ganhar: player++; break;
        case Perder: CPU++; break;
    }

    cout << "======================\n";
    cout << "\tPlacar\n\n";
    cout << "Tentativas: " << tentativas << endl;
    cout << "Empates: " << empates << endl;
    cout << "Player: " << player << endl;
    cout << "CPU: " << CPU << endl;
    cout << "======================\n";

    tentativas++;
}
