#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char matrizPrincipal[4][4] =
        {
            {'1', '4', '5', '2'},
            {'7', '2', '8', '7'},
            {'3', '6', '1', '4'},
            {'6', '5', '3', '8'}};

    char matrizGabarito[4][4];
    int numeroAleatorio;
    int linha1, linha2, col1, col2;
    char valor1, valor2;
    char opc;
    bool jogo = true;

    // Inicialização da semente para números aleatórios
    srand(time(NULL));

    // Laço principal do jogo
    while (jogo)
    {
        // Sorteia uma das transformações da matriz
        numeroAleatorio = rand() % 4;

        // Criação da matrizGabarito com base no número sorteado
        switch (numeroAleatorio)
        {
        case 0:
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[i][j];
                }
            }
            break;

        case 1:
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[j][i];
                }
            }
            break;

        case 2:
            for (int i = 0, k = 3; i < 4; i++, k--)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[k][j];
                }
            }
            break;

        case 3:
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0, k = 3; j < 4; j++, k--)
                {
                    matrizGabarito[i][j] = matrizPrincipal[i][k];
                }
            }
            break;
        }

        // Inicializa a matriz visível ao jogador com '?'
        char matrizJogo[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                matrizJogo[i][j] = '?';
            }
        }

        // Controle de pares encontrados e quantidade de jogadas
        int paresEncontrados = 0, jogadasRealizadas = 0, jogadasRestantes = 24;

        // Loop das jogadas do usuário
        while (jogadasRestantes > 0 && paresEncontrados < 8)
        {
            cout << "\n========BEM VINDO========\n";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    cout << matrizJogo[i][j] << '\t';
                }
                cout << "\n";
            }

            // Leitura das coordenadas escolhidas pelo jogador
            cout << "\nAdvinhe as pecas";
            cout << "\nPrimeira peca\n";
            cout << "Linha: ";
            cin >> linha1;
            linha1--;

            cout << "Coluna: ";
            cin >> col1;
            col1--;

            cout << "\nSegunda peca\n";
            cout << "Linha: ";
            cin >> linha2;
            linha2--;

            cout << "Coluna: ";
            cin >> col2;
            col2--;

            if (linha1 < 0 || linha1 > 3 || linha2 < 0 || linha2 > 3 || col1 < 0 || col1 > 3 || col2 < 0 || col2 > 3) // Validação dos índices informados
            {
                cout << "Valores Invalidos!\n";
                system("pause");
                system("cls");
                continue;
            }
            else if (matrizJogo[linha1][col1] != '?' || matrizJogo[linha2][col2] != '?') // Verifica se a posição já foi descoberta anteriormente
            {
                cout << "Posicao ja encontrada!\n";
                system("pause");
                system("cls");
                continue;
            }
            else if (linha1 == linha2 && col1 == col2) // Impede que o jogador escolha a mesma posição duas vezes
            {
                cout << "Escolhas posicoes diferentes!\n";
                system("pause");
                system("cls");
                continue;
            }

            // Obtém os valores correspondentes às posições escolhidas
            valor1 = matrizGabarito[linha1][col1];
            valor2 = matrizGabarito[linha2][col2];

            // Verifica se as peças escolhidas formam um par
            if (valor1 == valor2)
            {
                cout << "Pecas escolhidas: " << valor1 << " e " << valor2 << "\n";
                cout << "JOGADA OK" << "\n";
                paresEncontrados++;
                matrizJogo[linha1][col1] = valor1;
                matrizJogo[linha2][col2] = valor2;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Pecas escolhidas: " << valor1 << " e " << valor2 << "\n";
                cout << "JOGADA NOK" << "\n";
                system("pause");
                system("cls");
            }

            jogadasRealizadas++;
            jogadasRestantes--;
            cout << "\nJogadas realizadas: " << jogadasRealizadas << "\n";
        }

        if (paresEncontrados == 8)
        {
            cout << "VOCE GANHOU!!";
        }
        else
        {
            cout << "VOCE PERDEU!!";
        }

        cout << "\nJogar novamente? [S/N] ";
        cin >> opc;
        if (opc == 'N' || opc == 'n')
        {
            jogo = false;
            cout << "Obrigado por jogar :)";
        }
    }

    return 0;
}