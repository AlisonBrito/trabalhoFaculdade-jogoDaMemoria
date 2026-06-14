#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char matrizPrincipal[4][4] = {'1', '4', '5', '2', '7', '2', '8', '7', '3', '6', '1', '4', '6', '5', '3', '8'};
    char matrizGabarito[4][4];
    int numeroAleatorio, linha1, linha2, col1, col2;
    char valor1, valor2, opc;
    bool jogo = true;

    // gerando números aleatórios
    srand(time(NULL));

    // laço principal do jogo
    while (jogo)
    {
        // sorteia uma das transformações da matriz
        numeroAleatorio = rand() % 4;

        // criação da matrizGabarito com base no número sorteado
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

        // inicializa a matriz visível ao jogador com 'X'
        char matrizJogo[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                matrizJogo[i][j] = 'X';
            }
        }

        // controle de pares encontrados e quantidade de jogadas
        int paresEncontrados = 0, jogadasRealizadas = 0, jogadasRestantes = 24;

        // loop das jogadas do usuário
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

            // leitura das coordenadas escolhidas pelo jogador
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
                        cout << "Valor invalido! Digite novamente...\n";
                    }

                } while (linha1 < 0 || linha1 > 3);

                do
                {
                    cout << "Coluna: ";
                    cin >> col1;
                    col1--;

                    if (col1 < 0 || col1 > 3)
                    {
                        cout << "Valor invalido! Digite novamente...\n";
                    }

                } while (col1 < 0 || col1 > 3);

                if (matrizJogo[linha1][col1] != 'X')
                {
                    cout << "Posicao ja encontrada!\n";
                }

            } while (matrizJogo[linha1][col1] != 'X');
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
                        cout << "Valor invalido! Digite novamente...\n";
                    }

                } while (linha2 < 0 || linha2 > 3);

                do
                {
                    cout << "Coluna: ";
                    cin >> col2;
                    col2--;

                    if (col2 < 0 || col2 > 3)
                    {
                        cout << "Valor invalido! Digite novamente...\n";
                    }

                } while (col2 < 0 || col2 > 3);

                // impede que o jogador escolha a mesma posição duas vezes
                if (linha1 == linha2 && col1 == col2)
                {
                    cout << "Escolha posicoes diferentes!\n";
                }
                else if (matrizJogo[linha2][col2] != 'X')
                {
                    cout << "Posicao ja encontrada!\n";
                }

            } while (matrizJogo[linha2][col2] != 'X' || linha1 == linha2 && col1 == col2);
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

            // obtém os valores correspondentes às posições escolhidas
            valor1 = matrizGabarito[linha1][col1];
            valor2 = matrizGabarito[linha2][col2];

            // verifica se as peças escolhidas formam um par
            if (valor1 == valor2)
            {
                cout << "JOGADA OK" << "\n";
                paresEncontrados++;
                matrizJogo[linha1][col1] = valor1;
                matrizJogo[linha2][col2] = valor2;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "JOGADA NOK" << "\n";
                system("pause");
                matrizJogo[linha1][col1] = 'X';
                matrizJogo[linha2][col2] = 'X';
                system("cls");
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