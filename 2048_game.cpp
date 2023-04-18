#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
using namespace std;

class game_2048{
    public:
    vector<vector<int>> array;
    int random[2];
    game_2048()
    {
        for(int i=0;i<4;i++)
        {
            vector<int>vv;
            for(int j=0;j<4;j++)
            {
                vv.push_back(-1);
            }
            array.push_back(vv);
        }
        array[1][1] = 2;
        array[2][2] = 2;
        cout<<"********* Game Space Created **********"<<endl;
    }
    bool is_win()
    {
        for(int i=0;i<4;i++)
        {

            for(int j=0;j<4;j++)
            {
                if(array[i][j]==2048)
                {
                    cout<<"-------- You WIN THE GAME OF 2048 ---------"<<endl;
                    return 1;
                }
           }
        }
         return 0;

     }
     bool is_game_over()
     {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(array[i][j]==-1)
                {
                    return 0;
                }
           }
        }
        cout<<"------- Sorry GAME OVER ---------"<<endl;
         return 1;
     }
     bool random_generator()
     {
        int row = 4;
        int col = 4;
        srand(time(0));
        row = rand()%4;
        col = rand()%4;

        while(array[row][col]!=-1)
        {
            row = rand()%4;
            col = rand()%4;
        }
        array[row][col] = 2;
        print_the_game();



        return 1;
     }
     bool add_up()
     {
        for(int i = 0;i<4;i++)
        {
            if(array[0][i] == array[1][i]&& array[0][i]!=-1 )
            {
                array[0][i]+=array[1][i];
                array[1][i]= -1;
            }
             if(array[2][i] == array[3][i] && array[2][i]!=-1)
            {
                array[2][i]+=array[3][i];
                array[3][i]= -1;
            }

            if(array[1][i] == array[2][i] && array[1][i]!=-1)
            {
                array[1][i]+=array[2][i];
                array[2][i]= -1;
            }

        }

        return 1;

     }

      bool add_down()
     {
        for(int i = 0;i<4;i++)
        {
            if(array[0][i] == array[1][i] && array[0][i]!=-1)
            {
                array[1][i]+=array[0][i];
                array[0][i]= -1;
            }

            if(array[3][i] == array[2][i] && array[3][i]!=-1)
            {
                array[3][i]+=array[2][i];
                array[2][i]= -1;
            }
            if(array[1][i] == array[2][i] && array[1][i]!=-1)
            {
                array[2][i]+=array[1][i];
                array[1][i]= -1;
            }
        }

        return 1;

     }

      bool add_left()
     {
        for(int i = 0;i<4;i++)
        {
            if(array[i][0] == array[i][1] && array[i][0]!=-1)
            {
                array[i][0]+=array[i][1];
                array[i][1]= -1;
            }
            if(array[i][2] == array[i][3] && array[i][2]!=-1)
            {
                array[i][2]+=array[i][3];
                array[i][3]= -1;
            }
             if(array[i][1] == array[i][2] && array[i][1]!=-1)
            {
                array[i][1]+=array[i][2];
                array[i][2]= -1;
            }
        }

        return 1;

     }
       bool add_right()
     {
        for(int i = 0;i<4;i++)
        {
            if(array[i][0] == array[i][1] && array[i][0]!=-1)
            {
                array[i][1]+=array[i][0];
                array[i][0]= -1;
            }
             if(array[i][3] == array[i][2] && array[i][3]!=-1)
            {
                array[i][3]+=array[i][2];
                array[i][2]= -1;
            }
            if(array[i][1] == array[i][2] && array[i][1]!=-1)
            {
                array[i][2]+=array[i][1];
                array[i][1]= -1;
            }
        }

        return 1;

     }

     bool move_up()
     {
        for(int col =0;col<4;col++)
        {
            for(int row =0;row<4;row++)
            {
                if(array[row][col]!= -1)
                continue;

                for(int i =row+1;i<4;i++)
                {
                    if(array[i][col]!= -1)
                    {
                        array[row][col]= array[i][col];
                        array[i][col]=-1;
                        break;
                    }
                }
            }
        }
        return 1;
     }
     bool move_down()
     {
        for(int col =0;col<4;col++)
        {
            for(int row =3;row>=0;row--)
            {
                if(array[row][col]!= -1)
                continue;

                for(int i =row-1;i>=0;i--)
                {
                    if(array[i][col]!= -1)
                    {
                        array[row][col]= array[i][col];
                        array[i][col]=-1;
                        break;
                    }
                }
            }
        }
        return 1;
     }

     bool move_left()
     {
        for(int row =0;row<4;row++)
        {
            for(int col =0;col<4;col++)
            {
                if(array[row][col]!= -1)
                continue;

                for(int i =col+1;i<4;i++)
                {
                    if(array[row][i]!= -1)
                    {
                        array[row][col]= array[row][i];
                        array[row][i]=-1;
                        break;
                    }
                }
            }
        }
        return 0;
     }

     bool move_right()
     {
        for(int row =0;row<4;row++)
        {
            for(int col =3;col>=0;col--)
            {
                if(array[row][col]!= -1)
                continue;

                for(int i =col-1;i>=0;i--)
                {
                    if(array[row][i]!= -1)
                    {
                        array[row][col]= array[row][i];
                        array[row][i]=-1;
                        break;
                    }
                }
            }
        }
        return 0;
     }

     void print_the_game()
     {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(array[i][j] ==-1)
                 {
                    cout<<"-  ";
                    continue;
                 }
                cout<<array[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
     }

     bool up_arrow()
     {

      //  add_up();
       //  print_the_game();
        move_up();
        add_up();
       // print_the_game();


        random_generator();
        return 1;
     }

     bool down_arrow()
     {

      //  add_down();
        // print_the_game();
       move_down();
       add_down();
       // print_the_game();
        random_generator();
        return 1;
     }
     bool left_arrow()

     {

      //  add_left();
       //  print_the_game();
        move_left();
        add_left();
      //  print_the_game();
        random_generator();
        return 1;
     }
     bool right_arrow()
     {

      //  add_right();
       //  print_the_game();
       move_right();
       add_right();
       // print_the_game();

        random_generator();
        return 1;
     }



};

int main()
{
    game_2048 gm;
    gm.print_the_game();
    char expression=0;
    while( !gm.is_game_over())
    {
        gm.is_win();

        cin>>expression;
        switch (expression)
        {
        case 'w':
            gm.up_arrow();
            break;
        case 'z':
            gm.down_arrow();
            break;
        case 'a':
            gm.left_arrow();
            break;
        case 's':
            gm.right_arrow();
            break;
        default:
            break;
        }
    }


}
