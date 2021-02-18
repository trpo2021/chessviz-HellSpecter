#include <stdio.h>

#define EMPTY -1

#define WHITE 0
#define BLACK 10

#define PAWN 0
#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define QUEEN 4
#define KING 5

int chessboard[8][8];
int figures[] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};

void printFigure(int figure, FILE* file)
{
    switch (figure) {
    case EMPTY:
        fprintf(file, " ");
        break;
    case WHITE + PAWN:
        fprintf(file, "&#9817;");
        break;
    case WHITE + ROOK:
        fprintf(file, "&#9814;");
        break;
    case WHITE + KNIGHT:
        fprintf(file, "&#9816;");
        break;
    case WHITE + BISHOP:
        fprintf(file, "&#9815;");
        break;
    case WHITE + QUEEN:
        fprintf(file, "&#9812;");
        break;
    case WHITE + KING:
        fprintf(file, "&#9813;");
        break;
    case BLACK + PAWN:
        fprintf(file, "&#9823;");
        break;
    case BLACK + ROOK:
        fprintf(file, "&#9820;");
        break;
    case BLACK + KNIGHT:
        fprintf(file, "&#9822;");
        break;
    case BLACK + BISHOP:
        fprintf(file, "&#9821;");
        break;
    case BLACK + QUEEN:
        fprintf(file, "&#9818;");
        break;
    case BLACK + KING:
        fprintf(file, "&#9819;");
        break;
    }
}

void fillChessboard(int chessboard[8][8])
{
    // Заполняем пустотой поле
    for (int n = 0; n < 8; n++) {
        for (int m = 0; m < 8; m++) {
            chessboard[n][m] = EMPTY;
        }
    }
    // Заполняем пешки
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = BLACK + PAWN;
        chessboard[6][i] = WHITE + PAWN;
    }
    // Заполняем фигуры
    for (int i = 0; i < 8; i++) {
        chessboard[0][i] = BLACK + figures[i];
        chessboard[7][i] = WHITE + figures[i];
    }
}

void printChessboard(int chessboard[8][8])
{
    FILE* html_file;
    html_file = fopen("result.html", "w+");
    fprintf(html_file, "<html><body><table border='1'>");
    for (int n = 0; n < 8; n++) {
        fprintf(html_file, "<tr>");
        for (int m = 0; m < 8; m++) {
            fprintf(html_file, "<td height='21'>");
            printFigure(chessboard[n][m], html_file);
            fprintf(html_file, "</td>");
        }
        fprintf(html_file, "</tr>");
    }
    fprintf(html_file, "</table></body></html>");
}

int main()
{
    fillChessboard(chessboard);
    printChessboard(chessboard);
}
