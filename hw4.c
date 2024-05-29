#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

void print_card(card_s* card)
{
    // TODO Print the card as a two character sequence
    // first character for the rank, and second character for the suit
	if (card->rank == 1) {
		printf("A");
	}
	else if (card->rank == 11) {
		printf("J");
	}
	else if (card->rank == 12) {
		printf("Q");
	}
	else if (card->rank == 13) {
		printf("K");
	}
	else {
		printf("%d",card->rank);
	}
	
	if (card->suit == HEARTS) {
		printf("H");
	}
	else if (card->suit == SPADES) {
		printf("S");
	}
	else if (card->suit == CLUBS) {
		printf("C");
	}
	else if (card->suit == DIAMONDS) {
		printf("D");
	}
}

void check_hand(card_s *hand)
{
    // TODO Print whether the hand has two of a kind, two pair,
    // three of a kind, full house, or four of a kind

    // create a temporary array of size 13 initialized to 0
    // iterate through the 5 cards in the hand array and use the temporary array
    // to keep a count of the number of cards of each rank

    // iterate through the temporary array and use three variables to count
    // how many ranks have a count of 4, 3, or 2.  Use those variables to
    // determine what the value of the hand is.
	
	//one pair = 2 cards with same rank : 5H and 5S
	//three of a kind = 3 cards with same rank : 5H , 5S , and 5D
	//four of a kind = 4 cards with same rank : 5S , 5D , 5C , and 5H
	//two pair = 2 cards with same rank, 2 cards with another rank (2 one pairs) : 5H and 5S, 6H and 6C
	//full house = 3 cards with one rank, two cards with another rank (one pair + three of a kind) : 5H , 5S , 5D , and 6H , 6C 
	
	int rankcount[13]= {0};
	int twocount=0, threecount=0, fourcount=0;
	
	
	for (int i=0;i<5;i++) {
		rankcount[hand[i].rank-1]++;
	}
	for (int j=0; j<13; j++) {
		if (rankcount[j] == 2) {
			twocount++;
		}
		else if (rankcount[j] == 3) {
			threecount++;
		}
		else if (rankcount[j] == 4) {
			fourcount++;
		}
	}
	if (fourcount > 0) {
		printf("Four of a Kind\n");
	}
	else if (threecount>0 && twocount>0) {
		printf("Full House\n");
	}
	else if (threecount>0) {
		printf("Three of a Kind\n");
	}
	else if (twocount==2) {
		printf("Two Pair\n");
	}
	else if (twocount==1) {
		printf("One Pair\n");
	}
	else {
		printf("No Hand\n");
	}
}

    
int main(int argc, char **argv)
{
    int seed = atoi(argv[1]);
    card_s hand[5];
    deal_hand(hand, 5, seed);

    for (int i=0; i<5; i++) {
        print_card(&hand[i]);
        if (i<4)
            printf(" ");
    }
    printf("\n");

    check_hand(hand);
}
