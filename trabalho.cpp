#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char matrizPrincipal[4][4] = {'1', '4', '5', '2', '7', '2', '8', '7', '3', '6', '1', '4', '6', '5', '3', '8'};
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
        case 0: // matriz original
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[i][j];
                    // cout << matrizGabarito[i][j] << "\t";
                }
                // cout << "\n";
            }
            break;

        case 1: // matriz transposta
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[j][i];
                    // cout << matrizGabarito[i][j] << "\t";
                }
                // cout << "\n";
            }
            break;

        case 2: // inversão das linhas
            for (int i = 0, k = 3; i < 4; i++, k--)
            {
                for (int j = 0; j < 4; j++)
                {
                    matrizGabarito[i][j] = matrizPrincipal[k][j];
                    // cout << matrizGabarito[i][j] << "\t";
                }
                // cout << "\n";
            }
            break;

        case 3: // inversão das colunas
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0, k = 3; j < 4; j++, k--)
                {
                    matrizGabarito[i][j] = matrizPrincipal[i][k];
                    // cout << matrizGabarito[i][j] << "\t";
                }
                // cout << "\n";
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
            cout << "\t1\t2\t3\t4\n";
            cout << "\t-\t-\t-\t-\n";

            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << "  ->\t";

                for (int j = 0; j < 4; j++)
                {
                    cout << matrizJogo[i][j] << '\t';
                }

                cout << "\n";
            }

            // Leitura das coordenadas escolhidas pelo jogador
            cout << "\nAdvinhe os numeros atraves da coordenadas";
            cout << "\nPrimeiro numero\n";
            do
            {
                do
                {
                    cout << "Linha: ";
                    cin >> linha1;
                    linha1--;

                    if (linha1 < 0 || linha1 > 3)
                    {
                        cout << "Valor invalido!\n";
                    }

                } while (linha1 < 0 || linha1 > 3);

                do
                {
                    cout << "Coluna: ";
                    cin >> col1;
                    col1--;

                    if (col1 < 0 || col1 > 3)
                    {
                        cout << "Valor invalido!\n";
                    }

                } while (col1 < 0 || col1 > 3);

                if (matrizJogo[linha1][col1] != '?')
                {
                    cout << "Posicao ja encontrada!\n";
                }

            } while (matrizJogo[linha1][col1] != '?');
            matrizJogo[linha1][col1] = matrizGabarito[linha1][col1];
            cout << "\n\t1\t2\t3\t4\n";
            cout << "\t-\t-\t-\t-\n";

            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << "  ->\t";

                for (int j = 0; j < 4; j++)
                {
                    cout << matrizJogo[i][j] << '\t';
                }

                cout << "\n";
            }

            cout << "\nSegundo numero\n";
            do
            {
                do
                {
                    cout << "Linha: ";
                    cin >> linha2;
                    linha2--;

                    if (linha2 < 0 || linha2 > 3)
                    {
                        cout << "Valor invalido!\n";
                    }

                } while (linha2 < 0 || linha2 > 3);

                do
                {
                    cout << "Coluna: ";
                    cin >> col2;
                    col2--;

                    if (col2 < 0 || col2 > 3)
                    {
                        cout << "Valor invalido!\n";
                    }

                } while (col2 < 0 || col2 > 3);

                if (linha1 == linha2 && col1 == col2)
                {
                    cout << "Escolha posicoes diferentes!\n";
                }
                else if (matrizJogo[linha2][col2] != '?')
                {
                    cout << "Posicao ja encontrada!\n";
                }

            } while (matrizJogo[linha2][col2] != '?' || linha1 == linha2 && col1 == col2);
            matrizJogo[linha2][col2] = matrizGabarito[linha2][col2];
            cout << "\n\t1\t2\t3\t4\n";
            cout << "\t-\t-\t-\t-\n";

            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << "  ->\t";

                for (int j = 0; j < 4; j++)
                {
                    cout << matrizJogo[i][j] << '\t';
                }

                cout << "\n";
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
                cin.ignore();
                cout << "\033c";
            }
            else
            {
                cout << "Pecas escolhidas: " << valor1 << " e " << valor2 << "\n";
                cout << "JOGADA NOK" << "\n";
                cin.ignore();
                matrizJogo[linha1][col1] = '?';
                matrizJogo[linha2][col2] = '?';
                cout << "\033c";
            }

            jogadasRealizadas++;
            jogadasRestantes--;
            cout << "\nJogadas realizadas: " << jogadasRealizadas << "\n\n";
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