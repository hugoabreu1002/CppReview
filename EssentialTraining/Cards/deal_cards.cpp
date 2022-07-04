// deal_cards.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-11

#include <cstdio>
#include "deck.h"

void deal_hand(Cards::Deck &deck, int num_cards)
{
    while (num_cards--)
    {
        Cards::Card card = deck.deal_card();
        printf("%s ", Cards::card_str(card));
    }
    puts("");
}

int main()
{
    try
    {
        Cards::Deck deck;
        printf("there are %d cards remaining\n", deck.remaining());

        deal_hand(deck, 9);
        deal_hand(deck, 5);
        deal_hand(deck, 13);
        deal_hand(deck, 10);

        printf("there are %d cards remaining\n", deck.remaining());
    }
    catch (Cards::CE &e)
    {
        puts(e.what());
        return 1;
    }

    return 0;
}
