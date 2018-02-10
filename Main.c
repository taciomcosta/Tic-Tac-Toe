#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


#define INT_MIN -32000
#define INT_MAX 32000
#define BOARD_SIZE 9
#define HUMAN true
#define HUMAN_PIECE 'x'
#define COMPUTER_PIECE 'o'


//Function prototypes
void initialize_board(char board[], int size);
bool has_winner(char board[], int size);
bool is_draw(char board[], int size);
void print_board(char board[], int size);
bool get_turn();
void human_play(char board[], int size);
void computer_play(char board[]);
void play_into_position(char board[], int position, char piece);
int get_computer_choice(char board[], char piece);
bool has_piece(char board[], int position);
int evalurate_board(char board[]);
int minimax(char board[]);


int main(void)
{
  char board[BOARD_SIZE];
  initialize_board(board, BOARD_SIZE);
  while (!has_winner(board, BOARD_SIZE) && !is_draw(board, BOARD_SIZE))
  {
    print_board(board, BOARD_SIZE);
    int turn = get_turn();
    if (turn == HUMAN)
    {
      human_play(board, BOARD_SIZE);
    }
    else
    {
      computer_play(board);
    }
  };
  printf("FINISH!!");
  print_board(board, BOARD_SIZE);
  return 0;
}


void initialize_board(char board[], int size)
{
  int i = 0;
  for (i = 0; i < size; ++i)
  {
    board[i] = i + 49; //ascii
  }
}


void print_board(char board[], int size)
{

  char s[] = "  %c | %c | %c \n ---|---|---\n  %c | %c | %c\n ---|---|---\n  %c | %c | %c\n\n";
  printf(s, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}


bool has_winner(char board[], int size)
{
  int i;
  //horizontal
  for (i = 0; i < size; i += 3)
  {
    if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
    {
      return true;
    }
  }
  //vertical
  for (i = 0; i < size; i += 3)
  {
    if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
    {
      return true;
    }
  }
  //main diagonal
  if (board[0] == board[4] && board[4] == board[8])
  {
    return true;
  }
  //second diagonal
  if (board[2] == board[4] && board[4] == board[6])
  {
    return true;
  }
  return false;
}


bool is_draw(char board[], int size)
{
  int pos;
  for (pos = 0; pos < size; ++pos)
  {
    if (!has_piece(board, pos))
    {
      return false;
    }
  }
  printf("DRAW\n");
  return true;
}


bool get_turn()
{

  static bool isHumanTurn;
  if (isHumanTurn)
  {
    isHumanTurn = false;
  }
  else
  {
    isHumanTurn = true;
  }
  return isHumanTurn;
}


void human_play(char board[], int size)
{

  int position = 0;
  while (position < 1 || position > 9)
  {
    printf("Player1 (x) choose a position[1-9]: ");
    scanf("%i", &position);
  }
  --position;
  play_into_position(board, position, HUMAN_PIECE);
}


void play_into_position(char board[], int position, char piece)
{

  board[position] = piece;
  printf("Playing into %i... \n", position);
}


void computer_play(char board[])
{
  int position = get_computer_choice(board, COMPUTER_PIECE);
  play_into_position(board, position, COMPUTER_PIECE);
}


bool has_piece(char board[], int position)
{

  if (board[position] != HUMAN_PIECE && board[position] != COMPUTER_PIECE)
  {
    return false;
  }
  return true;
}


int get_computer_choice(char board[], char piece)
{

  int choice = rand() % 8 + 1;
  while (has_piece(board, choice))
  {
    choice = rand() % 8 + 1;
  }
  return choice;
  //return minimax(board,piece);
}

/*int mini(char board[]){
 
  //atribuir um valor
   // se alguem tiver ganho  ou houve um empate:
     //> retorna o valor atribuido ao estado atual senão:
       //calcula os movimentos disponíveis 
         //> para cada movimento disponível:
	   //> executa o movimento
	     //> pega o valor do minimax para o outro jogar
	       // > desfaz o movimento
	         // se o valor atual for o maior:
		   // > salvar o valor atual como sendo o maior valor
		     // >salvar o movimento como sendo a melhor escolha 
		       //retorna a posição escolhida como a melhor
		         
			  int boardValue = evaluate_board(board);
			  if(has_winner(board, BOARD_SIZE) || is_draw(board, BOARD_SIZE)){
			    
			      return boardValue;  
			       
			  }
			   
			    bool availableMoves[] = get_available_moves(board);
			     int greatestValue = INT_MIN;
			      int bestChoice;
			       int position;
			       for(position = 0; position < 9; ++position){
			         if(availableMoves[position]){    
				    execute_move(board, position);
				       int currentBoardValue = minimax(board);
				          undo_move(board,position);
					  if(currentBoardValue > greatestValue){
					      greatestValue = currentBoardValue;
					          bestChoice = position;
						     
					  }
					    }
					     
			       }
			        return bestChoice;

  }

  int max(char board[]){
  melhor
    
     int boardValue = evaluate_board(board);
     if(has_winner(board, BOARD_SIZE) || is_draw(board, BOARD_SIZE)){
       
         return boardValue;  
	  
     }
      int smallestValue = INT_MAX;
       int bestChoice;
        bool availableMoves[] = get_available_moves(board);
	 int position;
	 for(position = 0; position < 9; ++position){
	   if(availableMoves[position]){    
	      execute_move(board, position);
	         int currentBoardValue = minimax(board);
		    undo_move(board,position);
		    if(currentBoardValue > smallestValue){
		        smallestValue = currentBoardValue;
			    bestChoice = position;
			       
		    }
		      }
		       
	 }
	  return bestChoice;

  }
  */

/*  
    %c| %c| %c\n ---|---|---\n  %c| %c| %c\n ---|---|---\n  %c| %c| %c\n
     
      Player1  
         
	    

*/
