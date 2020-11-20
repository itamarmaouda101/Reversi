#include <iostream>
using namespace std;

class Game
{
    private:
        int player_won = 0;
    public: 
        
        int plays_now = 0;
        int board[8][8];
        void clear_board()
        {
            for(int i=0; i<8;i++)
            {
                for (int j=0;j<8;j++)
                {
                    board[i][j] = 0;
                }
            }
        }
        void show_board()
        {
            for(int i=0; i<8;i++)
            {
                printf("\n");
                for (int j=0;j<8;j++)
                {
                    printf("%d", board[i][j]);
                }
            }
        }
        void set_player_won(int player)
        {
            player_won = player;
        }
        int get_player_won()
        {
            return player_won;
        }
        int place_is_free(int x, int y)
        {
            if (board[x][y] == 0)
                return 0;
            if (board[x][y] == 1)
                return 1;
            if(board[x][y] == 2)
                return 2;
        }
        bool use_all_disks(Player player)
        {
            if (player.number_of_disks_left = 0)
                return true;
            return false;
        }
        bool all_board_fill()
        {
            for(int i=0; i<8;i++)
            {
                for (int j=0;j<8;j++)
                {
                    if (board[i][j] == 0)
                        return false;
                }
            }
            return true;
        }
        int find_the_winner()
        {
            int player1_disks = 0;
            int player2_disks = 0;
            for (int i=0;i<8;i++)
            {
                for (int j=0;j<8;j++)
                {
                    if (board[i][j] == 1)
                    {
                        player1_disks++;
                    }
                    else if (board[i][j] == 2)
                    {
                        player2_disks++;
                    }
                    else
                    {
                        //made as another check for finding empty hole 
                        return 0;

                    }
                }
            }
        }
        int how_won()
        {
            if ( get_player_won() != 0 || all_board_fill())
            {
                //the game is finished, just need to clac the points
                return find_the_winner();
            }
            return 0;
        }
};
class Player: public Game
{
    public:
        int player_number;
        int number_of_disks_on_table = 0;
        int number_of_disks_left;
        int finish_my_disks()
        {
            return number_of_disks_left == 0;
        }
        int add_disk(int x, int y)
        {
           
            if (place_is_free(x, y) == player_number)
                return -1;
                //when player is want to put disk where hw already have one
            else if (place_is_free(x, y) == 0)
            {
                //hundle as put the disk
                board[x][y] = player_number;
                number_of_disks_on_table ++;
                number_of_disks_left--;
                if (finish_my_disks())
                    set_player_won(player_number);
                    return 5; // 5 means winning!
                return 1;
            }
            else
            {
                //hunde as flip the disk
                board[x][y] = player_number;
                 if (finish_my_disks())
                    set_player_won(player_number);
                    return 5; // 5 means winning! 
                return 2;
            }
            
            
        }
        Player(int number_disks)
        {
            player_number = plays_now + 1;
            number_of_disks_left = number_disks;
            number_of_disks_on_table = 0;
            plays_now++;
        }
};

