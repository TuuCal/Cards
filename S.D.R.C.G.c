#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Changed enum to array housing Suits
char * suits[] = {"Clubs","Diamonds","Hearts","Spades"};
// Changed if statments to an array
char * values[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
 
enum cardsuit {
	Clubs,
	Diamonds,
	Hearts,
	Spades
};

// a card has a suit and a value.
typedef struct {
	enum cardsuit suit;
	short int value;
} card;

void printSuit(int suit) {
	printf(suits[suit]); // Now draws from an array
}

void printValue(int value) {
	printf(values[value - 1]); // Subtract 1 to start from 1
}

void printCard(card c) {
	printValue(c.value); // Now prints the array
	printf(" of ");
	printSuit(c.suit);// Also prints from array
}


card deck[52];
 
void shuffle(){
		int rnd, rnd1;
		card temp;

		for(int i = 0; i < 52 *10; i++) {
			rnd = rand() % 52;
			rnd1 = rand() % 52;
			if (rnd == rnd1){
				rnd = (rnd + 1) % 52;
			}

			temp = deck[rnd];
			deck[rnd] = deck[rnd1];
			deck[rnd1] = temp;
		}
}

int main() {

	for (int i = 0; i < 52; i++) {
		deck[i].suit = i/13;
		deck[i].value = (i%13)+1;
	}

	shuffle();


	for (int i = 0; i < 52; i++) {
		printCard(deck[i]);
		printf("\n");
	}
}
