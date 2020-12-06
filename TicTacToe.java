import java.util.Scanner;

public class TicTacToe {
    boolean win = false;
    int player = 0; 
    int[][] gameBoard = {
        {1, 2, 3}, 
        {4, 5, 6},
        {7, 8, 9}
    };

    static void clearScreen() {  //Clears the screen
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    }

    String symbol() { //Returns a String literal to indicate player based on int turn tracker
        if (player % 2 != 0) {
            return "X";
        }
        else {
            return "O";
        }
    }

    void draw() { //Draws the gameBoard (2 dimensional array) in two nested loops which is iterated through. It changes 25 and 80 to 'X' or 'O' for user facing display
    if (win == false) {
        clearScreen();
            for (int i = 0; i < 3; i ++) {
                for (int j = 0; j < 3; j++) {
                    switch (gameBoard[i][j]) {
                        case 25:
                            System.out.print('X' + " ");
                            break;
                        case 80:
                            System.out.print('O' + " ");
                            break;
                        default:
                            System.out.print(gameBoard[i][j] + " "); 
                    }
                }		
                System.out.print("\n");
            }
        }
    }

    void turn() { //Takes an input for which square to take, validates that input for data type, and being in bounds, and then changes the number to either 25 or 80 based on whose turn it is
        if (win == false) {
            System.out.print("\n" + "It is player " + symbol() + "'s turn" + "\n");
            int square;
            while (true) {
                System.out.print("Choose an available square using a number from 1 to 9" + "\n") ;
                Scanner Square = new Scanner(System.in);

                if(Square.hasNextInt()) {
                    square = Square.nextInt();
                    square--;
                } else {
                    System.out.print("ERROR: Non-integer entered. Please enter a number from 1 to 9" + "\n");
                    square = 1;
                }

                if (square < 0 || square > 8) {
                    System.out.print("Your input is out of bounds" + "\n");
                    continue;
                }
                
                else if (gameBoard[square/3][square%3] > 10) {
                    draw();
                    System.out.print("Error: The square you have chosen is taken. Choose another square" + "\n");
                    continue;
                }

                else if (square >= 0 && square < 9) {
                    switch (player % 2){
                        case 0:
                            gameBoard[square / 3][square % 3] = 80;
                            break;
                        case 1:
                            gameBoard[square / 3][square % 3] = 25;
                            break;
                    }
                    break;
                }
                else {
                    System.out.print("UNRESOLVED ERROR, CONTACT DEVELOPER, MISTAKES WERE MADE, THE END TIMES ARE UPON US" + "\n");
                }
                Square.close();
                break;
            }
        }
        player++;
    }

    void checkWinner() {
        if (win == false) {
            for (int i = 0; i < 3; i++) {
                if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) { //each of these if and AND conditions are possible wins, this one is for every possible row
                    player--;
                    win = true;
                    System.out.print("Congratulations! Player " + symbol() + " won" + "\n");
                }
            }
            for (int j = 0; j < 3; j++) {
                if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) { //every possible column win
                    player--;
                    win = true;
                    System.out.print("Congratulations! Player " + symbol() + " won" + "\n");
                }
            }
            if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) { //This and below are for diagonal wins
                player--;
                win = true;
                System.out.print("Congratulations! Player " + symbol() + " won" + "\n");
            }
            if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
                player--;
                System.out.print("Congratulations! Player " + symbol() + " won" + "\n");
                win = true; 
            }
        }
    }

    void reset() { //Resets the gameboard to original state
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                gameBoard[i][j] = (i * 3) + j + 1; //sets the tiles from 1 to 9 using this formula
            }
        }
        player = 0; //Sets turn counter to 0
    }


    public static void main(String args[]) {
        TicTacToe TicTacToe = new TicTacToe();
        TicTacToe.reset();
        TicTacToe.draw();

        while (true) {
            TicTacToe.turn();
            TicTacToe.draw();
            TicTacToe.checkWinner();
        }
    }
}