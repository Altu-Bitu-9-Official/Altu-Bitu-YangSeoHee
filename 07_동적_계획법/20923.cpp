#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DODO = 0, SUYEON = 1;

string whoWin(cards &card)
{
    int dodoCard = card[DODO].size();
    int suyeonCard = card[SUYEON].size();
    if ( dodoCard > suyeonCard ) return "do";
    if ( dodoCard < suyeonCard ) return "su";
    return "dosu";
}

void moveCard(deque<int> &card, deque<int> &game)
{
    while ( !game.empty() )
    {
        card.push_back(game.back());  
        game.pop_back();
    }
}

void ringBell(int player, cards &card, cards &game)
{
    moveCard(card[player], game[!player]);
    moveCard(card[player], game[player]);
}

int whoRing(cards & card, cards &game)
{
    if ( !game[DODO].empty() && game[DODO].front() == 5 )
    {
        return DODO;
    }
    else if ( !game[SUYEON].empty() && game[SUYEON].front() == 5 )
    {
        return DODO;              
    }
    else if ( !game[DODO].empty() && !game[SUYEON].empty() && (game[DODO].front() + game[SUYEON].front() == 5) )
    {
        return SUYEON;
    }
    return -1; 
}

string gameStart(int m, cards &card, cards &game)
{
    bool order = DODO; 
    while ( m-- )
    {
        game[order].push_front(card[order].front());
        card[order].pop_front();

        if ( card[order].empty() ) break;

        int bell = whoRing(card, game);     
        if ( bell != -1 )
        {
            ringBell(bell, card, game);
        }

       
        order = !order;
    }
    return whoWin(card);
}

int main()
{
    
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, card1, card2;
    cards card(2), game(2);

    cin >> n >> m;
    while ( n-- )
    {
        cin >> card1 >> card2;
        card[DODO].push_front(card1);
        card[SUYEON].push_front(card2);
    }

    cout << gameStart(m, card, game);
    return 0;
}