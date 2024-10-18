#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    char player_choice;
    cout<<"1.Enter (r) for rock\n2.Enter (p) for paper\n3.Enter (s) for scissor ";
    cout<<"\nEnter the player choice :";
    cin>>player_choice;
    int computer_choice;
    int computer,range_max=1,range_min=3;
    srand(time(0));
    computer_choice= range_min +rand() % (range_max - range_min + 1);
    cout<<"\nThe computer choice was :"<<computer_choice;
    switch(computer_choice) {
        case 1:
            if(player_choice == 'r' )
                cout<<"\nYou have drawed the game as computer also choosed rock";
              else if(player_choice == 'p')
                  cout<<"\nYou have lost the game as computer choosed paper";
              else
                  cout<<"\nYou have won the game as computer choosed rock";
        break;
        case 2:
            if(player_choice=='p')
                cout<<"\nYou have drew the game as computer also choosed paper";
        else if (player_choice =='s')
            cout<<"\nYou have won the game as computer choosed paper";
        else
            cout<<"\nYou have lost the game as computer choosed paper";
        break;
        case 3:
            if(player_choice == 's')
                cout<<"\nYou have drawed the game as computer also choosed scissor";
        else if(player_choice=='p')
            cout<<"\nYou have lost lost the game as computer choosed scissor";
        else
            cout<<"\nYou have won the game as computer choosed scissor";
        break;
    }

}
