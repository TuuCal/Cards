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
} Card;

typedef struct {
	Card cards[52];
	int length;
} Deck;

int isEmpty(Deck deck){
	if (deck.length == 0)
		return 1;
	else
		return 0;
}

void addCard(Deck *d, Card c){
	(*d).cards[(*d).length] = c;
	(*d).length ++;
}

Card removeCard(Deck *d) {
	Card c;
	c.suit = Spades;
	c.value = 2;
	return c;
	// (*d).cards[0];
/*	for (int a = 0; a < 51; a ++) {
		(*d).cards[a] = (*d).cards[a + 1];
	} */
	//return c1; 
}

void printSuit(int suit) {
	printf(suits[suit]); // Now draws from an array
}

void printValue(int value) {
	printf(values[value - 1]); // Subtract 1 to start from 1
}

void printCard(Card c) {
	printValue(c.value); // Now prints the array
	printf(" of ");
	printSuit(c.suit);// Also prints from array
}


Card deck[52];
 
void shuffle(){
		int rnd, rnd1;
		Card temp;

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

void runTests() {

	Deck testDeck;
	testDeck.length = 0;

	if(!isEmpty(testDeck)) {
		printf("isEmpty test 1 failed!\n");
	}

	testDeck.length = 1;

	if(isEmpty(testDeck)) {
		printf("isEmpty test 2 failed!\n");
	}

    testDeck.length = 0;

    Card testCard;
    testCard.suit = Hearts;
    testCard.value = 13;

    addCard(&testDeck, testCard);

    printCard(testDeck.cards[0]);
    printf("\n======\n");

	if(isEmpty(testDeck)) {
		printf("addCard test 1 failed!\n");
	}

	//Card yourmom = 
	removeCard(&testDeck);
	//printCard(yourmom);




}

int main() {

	runTests();

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




/*srand (time(NULL));

	int a = rand() % 52; 

	printf ("%d\t%d\n", deck[a].value, deck[a].suit);
	printCard (deck[a]);
	printf ("\n"); */
