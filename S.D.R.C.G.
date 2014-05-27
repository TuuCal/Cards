//GoW v0.01
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a cardsuit can be one of the following
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
	if(suit == Clubs) {
		printf("Clubs");
	} else if(suit == Diamonds) {
		printf("Diamonds");
	} else if(suit == Hearts) {
		printf("Hearts");
	} else if(suit == Spades) {
		printf("Spades");
	}
}

void printValue(int value) {
	if(value == 1) {
		printf("Ace");
	} else if (value == 11) {
		printf("Jack");
	}else if (value == 12) {
		printf("Queen");
	}else if (value == 13) {
		printf("King");
	}else if(value == 2) {
		printf("Two");
	}else if(value == 3){
		printf("Three");
	}else if(value == 4){
		printf("Four");
	}else if(value == 5){
		printf("Five");
	}else if(value == 6){
		printf("Six");
	}else if(value == 7){
		printf("Seven");
	}else if (value == 8){
		printf("Eight");
	}else if(value == 9){
		printf("Nine");
	}else if(value == 10){
		printf("Ten");
	}
}

void printCard(card c) {
	printValue(c.value);
	printf(" of ");
	printSuit(c.suit);
}
 
int main() {
card deck[52];


for (int i=0; i < 13; i++) {
deck[i].suit = Clubs;
deck[i].value = i +1;
}
for (int i=13; i < 26; i++) {
deck[i].suit = Diamonds;
deck[i].value = i - 12;
}
for (int i=26; i < 39 ; i++) {
deck[i].suit = Hearts;
deck[i].value = i - 25;
}
for (int i=39; i < 52; i++) {
deck[i].suit = Spades;
deck[i].value = i - 38;
}


srand (time(NULL));

int a = rand() % 52; 

printf ("%d\t%d\n", deck[a].value, deck[a].suit);
printCard (deck[a]);
printf ("\n");
}
 
