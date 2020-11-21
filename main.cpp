#include <iostream>
using namespace std;

class Game
{
    private:
        int player_won = 0;
        int board[8][8];
        int plays_now = 0;
    public:
    //board opertions 
    ///###############
        void set_board(int x, int y , int player_number)
        {
            board[x][y] = player_number;
        }
        int get_board(int x, int y)
        {
            return board[x][y];
        }
        void clear_board(int board[8][8])
        {
            for(int i=0; i<8;i++)
            {
                for (int j=0;j<8;j++)
                {
                    board[i][j] = 0;
                }
            }
        }
        void show_board_all_disk(int board[8][8])
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
        
        //###################
        
        
        //player opertions
        //######
        int get_plays_now()
        {
            return plays_now;
        }
        void add_player()
        {
            plays_now++;
        }
        void set_player_won(int player)
        {
            player_won = player;
        }
        int get_player_won()
        {
            return player_won;
        }
        //######

        //game opertions
        //#######
        int add_disk(int x, int y);
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
        //#####
        
};
class Player: public Game
{
    protected:
        int board_ops[8][8];
    public:
        int player_number;
        int number_of_disks_on_table = 0;
        int number_of_disks_left;
        
        //board_ops getter and setter
        //###
        void set_board_ops(int x,int y, int set_code)
        {
            board_ops[x][y] == set_code;
        }
        int get_board_ops(int x, int y)
        {
            return board_ops[x][y];
        }
        //###
        int finish_my_disks()
        {
            return number_of_disks_left == 0;
        }
        void mark_ops_board(int x, int y)
        {
            //check's if the place is free
                //#####
                // i code that hole with:
                // 6 is empty hole
                // 0 is enemy hole
                // player_number is the player hole
                //######
            //speacil condicens
            if (((x == 0 || y == 0) || (x == 7 || y == 7)) )
            {
                
                if (x == 0 || y == 0)
                {
                    
                    if(get_board(x,y+1) == player_number)
                    {
                        set_board_ops(x,y+1, player_number);
                        mark_ops_board(x,y+1);
                    }
                    if(get_board(x+1, y+1) == player_number)
                    {
                        set_board_ops(x+1,y+1, player_number);
                        mark_ops_board(x+1,y+1);
                    }
                    if(get_board(x+1,y) == player_number)
                    {
                       set_board_ops(x+1,y, player_number);
                       mark_ops_board(x+1,y); 
                    }
                    if (get_board(x, y+1) == 0)
                        set_board_ops(x, y+1, 6);
                    if (get_board(x+1, y+1) == 0)
                        set_board_ops(x+1, y+1, 6);
                    if (get_board(x+1, y) == 0)
                        set_board_ops(x+1, y, 6);
                }
                if(x == 7 || y == 7)
                {
                    if(get_board(x,y-1) == player_number)
                    {
                        set_board_ops(x,y-1, player_number);
                        mark_ops_board(x,y-1);
                    }
                    if(get_board(x-1, y-1) == player_number)
                    {
                        set_board_ops(x-1,y-1, player_number);
                        mark_ops_board(x-1,y-1);
                    }
                    if(get_board(x-1,y) == player_number)
                    {
                       set_board_ops(x-1,y, player_number);
                       mark_ops_board(x-1,y); 
                    }
                    if(get_board(x,y-1) == 0)
                    
                        set_board_ops(x,y-1, 6);
                    if(get_board(x-1, y-1) == 0)
                        set_board_ops(x-1,y-1, 6);
                    
                    if(get_board(x-1,y) == 0)
                       set_board_ops(x-1,y, 6);
                    
                }
                if(x == 0 || 0<y<7)
                {
                    for(int i=x; i<x+2;i++)
                    {
                        if(get_board(i,y+1) == player_number)
                        {
                            set_board_ops(i,y+1, player_number);
                            mark_ops_board(i, y+1);
                        }
                       
                        if (get_board(i,y) == player_number && i != 0)
                        {
                            set_board_ops(i, y, player_number);
                            mark_ops_board(i, y);
                        }
                        if (get_board(i,y-1) == player_number)
                        {
                            set_board_ops(i, y-1, player_number);
                            mark_ops_board(i, y-1);
                        }
                         if (get_board(i, y+1) == 0)
                            set_board_ops(i, y+1, 6);
                        if (get_board(i, y) == 0 && i != 0)
                            set_board_ops(i, y, 6);
                        if (get_board(i, y-1) == 0)
                            set_board_ops(i, y-1, 6);    
                    }
                }
                //5 ops
                if(y == 0 || 0<x<7)
                //5 ops
                for (int i=0;i<3;i++)
                {
                    if (get_board(i,y) == player_number && i != x)
                    {
                        set_board_ops(i, y, player_number);
                        mark_ops_board(i,y);
                    }
                    if(get_board(i,y+1) == player_number)
                    {
                        set_board_ops(i, y+1, player_number);
                        mark_ops_board(i, y+1);
                    }
                    if (get_board(i,y) == 0 && i != x)
                        set_board_ops(i, y, 6);
                    if (get_board(i, y+1) == 0)
                        set_board_ops(i, y+1, 6);
                }
                if(x == 7 || 0<y<7)
                {
                    for(int i=0;i<3;i++)
                    {
                        if (get_board(x, i) == player_number && i != y)
                        {
                            set_board_ops(x, i, player_number);
                            mark_ops_board(x, i);
                        }
                        if (get_board(x-1, i) == player_number)
                        {
                            set_board_ops(x-1, i, player_number);
                            mark_ops_board(x-1, i);
                        }
                        if (get_board(x, i) == 0 && i != y)
                            set_board_ops(x, i, 6);
                        if (get_board(x-1, i) ==0)
                            set_board_ops(x-1, i, 6);
                    }
                }
                if (y == 7 || 0<x<7)
                {
                    for (int i=0; i<3; i++)
                    {
                        if (get_board(i, y) == player_number && i != x)
                        {
                            set_board_ops(i, y, player_number);
                            mark_ops_board(i, y);
                        }
                        if (get_board(i, y-1) == player_number)
                        {
                            set_board_ops(i, y-1, player_number);
                            mark_ops_board(i,y-1);
                        }
                        if(get_board(i, y) == 0 && i != x)
                            set_board_ops(i, y, 6);
                        if (get_board(i, y-1) == 0)
                            set_board_ops(i, y-1, 6);
                    }
                }
            }
            //hundle as the hole in the middle
            for (int i=x; i<x+3;i++)
            {
                //checks if there is anoter player's disks
                //#######
                if (get_board(i,y+1) == player_number)
                {
                    set_board_ops(i, y+1, player_number);
                    mark_ops_board(i , y+1);
                    //handle as found place to add search
                }
                if(get_board(i, y) == player_number && i != x)
                {
                    set_board_ops(i, y, player_number);
                    mark_ops_board(i , y);
                }
                    //handle as found place to add search
                if (get_board(i,y-1) == player_number)
                {
                    set_board_ops(i, y-1, player_number);
                    mark_ops_board(i , y-1);
                 
                    //handle as found place to add search 
                }
                //######


                //check's if the place is free
                //#####
                // i code that hole with:
                // 6 is empty hole
                // 0 is enemy hole
                // player_number is the player hole
                if (get_board(i,y+1) == 0)
                    set_board_ops(i, y+1, 6);
                    //handle as found place to add disk
                if(get_board(i, y) == 0 )
                    set_board_ops(i, y, 6);
                    //handle as found place to add disk
                if (get_board(i,y-1) == 0)
                    set_board_ops(i, y-1, 6);
                    //handle as found place to add disk        
            }

        }
        void set_player_opsions()
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                   mark_ops_board(i,j); 
                }
            }
            
        }
        int play()
        {
            clear_board(board_ops);
            set_player_opsions();
            cout << "show the board\n";
            show_board_all_disk(board_ops);
            int x, y, ret = -1;
            cout << "enter x place\n";
            cin >>x;
            cout << "enter y place\n";
            cin >>y;
            while (ret != 1)
            {
                ret = add_disk(x, y);
            }
            if (finish_my_disks())
                set_player_won(player_number);
                return 5;
        }
        int add_disk(int x, int y)
        {
           
            if (place_is_free(x, y) != 0)
                return -1;
                //when player is want to put disk where hw already have one
            else
            {
                //hundle as put the disk
                set_board(x, y, player_number);
                number_of_disks_on_table ++;
                number_of_disks_left--;
                return 1;
            }     
        }
        Player(int number_disks)
        {
            player_number = get_plays_now() + 1;
            number_of_disks_left = number_disks;
            number_of_disks_on_table = 0;
            add_player();
        }
};

