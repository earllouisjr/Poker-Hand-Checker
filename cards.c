#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

void deal_hand(card_s *hand, unsigned num_cards, unsigned seed)
{
    card_s deck[52];

    // create a deck of 52 cards in suit/rank order
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            deck[i*13+j].suit = i;
            deck[i*13+j].rank = j+1;
        }
    }

    srandom(seed);

    // randomly select num_cards from the deck
    for (int i=0; i<num_cards; i++) {
        long r = random();
        int index = r % (52-i);
        hand[i] = deck[index];
        deck[index] = deck[51-i];
    }
}
