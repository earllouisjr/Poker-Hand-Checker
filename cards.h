typedef enum {HEARTS, SPADES, CLUBS, DIAMONDS} suit_t;

typedef struct {
    suit_t suit;
    unsigned char rank;
} card_s;

void deal_hand(card_s* hand, unsigned num_cards, unsigned seed);


    


