#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void board(char coordinates[3][3]){
    system("cls");
    printf("\t %c | %c | %c \n", coordinates[0][0], coordinates[0][1], coordinates[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", coordinates[1][0], coordinates[1][1], coordinates[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", coordinates[2][0], coordinates[2][1], coordinates[2][2]);
}

int verify_winner(char coordinates[3][3]) {
    int i;

    for(i = 0; i < 3; i++) {
        if(coordinates[i][0] == coordinates[i][1] && coordinates[i][1] == coordinates[i][2]) 
            return coordinates[i][0]; 
        if(coordinates[0][i] == coordinates[1][i] && coordinates[1][i] == coordinates[2][i]) 
            return coordinates[0][i]; 
    }

    if(coordinates[0][0] == coordinates[1][1] && coordinates[1][1] == coordinates[2][2])
        return coordinates[0][0];
    if(coordinates[0][2] == coordinates[1][1] && coordinates[1][1] == coordinates[2][0])
        return coordinates[0][2]; 
    
    return ' '; 
}

int main(){
    char coordinates[3][3] = { {'1','2','3'},
                               {'4','5','6'},
                               {'7','8','9'} };
    char response;
    int move_counter, l, c, move = 0;
    int player_x, player_o = 0;
    char player;
    
    do {
        move_counter = 1;
 
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                coordinates[i][j] = ' ';
            }
        }
        do {
            board(coordinates);
            
            if(move % 2 == 0){
                printf("Jogador X\n");
            } else {
                printf("Jogador O\n");
            }
            printf("Digite a linha: ");
            char input[10];
            scanf("%s", input);
            if (isdigit(input[0])) {
                l = input[0] - '0'; 
            } else {
                printf("Entrada invalida!\n Por favor, digite um numero de linha valido.\n");
                continue;
            }
            printf("Digite a coluna: ");
            scanf("%s", input);

            if (isdigit(input[0])) {
                c = input[0] - '0'; 
            } else {
                printf("Entrada invalida!\n Por favor, digite um numero de linha valido.\n");
                continue;
            }
            
            if(l < 1 || c < 1 || l > 3 || c > 3 || coordinates[l-1][c-1] != ' '){
                printf("Jogada invalida! Tente novamente.\n");
                continue;
            }
            if(move % 2 == 0){
                coordinates[l-1][c-1] = 'X';
            }else {
                coordinates[l-1][c-1] = 'O';
            }
            move++;
            move_counter++;
           
        } while(move_counter <= 9 && verify_winner(coordinates) == ' ');
        
        board(coordinates);

        if(verify_winner(coordinates) == 'X') {
            printf("\nJogador X venceu!!\n");
            player_x++;
            player = 'X';
        } else if(verify_winner(coordinates) == 'O') {
            printf("\nJogador O venceu!!\n");
            player_o++;
            player = 'O';
        } else {
            printf("\nEmpate\n");

        }
        printf("\nPlacar ate o momento: Jogador X: %d, Jogador O: %d \n", player_x, player_o);
        printf("Deseja jogar novamente?[S-N]\n");
        scanf(" %c", &response);
        if ((response != 's' && response != 'S') && (response != 'n' && response != 'N')){
            do {printf("\nOpcao invalida!!\n Tente novamente!\n");
            scanf(" %c", &response);
            } while ((response != 's' && response != 'S') && (response != 'n' && response != 'N'));
        if (response == 's' || response == 'S'){
            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }
        } 
    } while((response == 's' || response == 'S') && (response != 'n' || response != 'N'));
    printf("\n\nPlacar Final: Jogador X: %d, Jogador O: %d \nAte a proxima!!\n", player_x, player_o);

    system("pause");
    return 0;
}
