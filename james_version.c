//
//  main.c
//  jeff2


//GoW v0.01

#include <stdio.h>
#include <stdlib.h>



// a cardsuit can be one of the following
typedef enum {
    Clubs,
    Diamonds,
    Hearts,
    Spades
} Suit;


//we could define every single card value, but this might be too verbose.
/*
enum cardvalue {
    Ace,
    One,
    Two,
    Three,
    Jack,
    Queen,
};
*/

// a card has a suit and a value.
typedef struct {
    Suit suit;
    short int value;
} Card;

typedef struct {
    unsigned short int length;
    Card cards[52];
} Deck;

/*
struct Node {
    Card card;
    struct Node *next;
};

typedef struct Node * List;
*/

Card makeCard(Suit suit, short int value) {
    Card card;
    card.suit = suit;
    card.value = value;
    return card;
}

Deck emptyDeck() {
    Deck deck;
    deck.length = 0;
    //deck.cards = malloc(sizeof(Card) * 52);
    return deck;
}

/*
void addOne(int * x) {
    (*x)++;
}

int y = 1;
addOne(&y);
*/
//expect y to be 2

/*
 card topCard = deck.cards[deck.length];
 deck.length++;
 return topCard
*/

Card removeCard(Deck *deck) {
    Card topCard = (*deck).cards[0];
    /*
    for(int i = 1; i < (*deck).length; i++) {
        (*deck).cards[i - 1] = (*deck).cards[i];
    }
    (*deck).length--;
    */
    return topCard;
}

/*
void addCard(Deck deck, Card card) {
    deck.cards[deck.length] = card;
    deck.length++;
}
*/

void addCard(Deck * deck, Card card) {
    (*deck).cards[(*deck).length] = card;
    (*deck).length++;
}

typedef unsigned short int Boolean;

Boolean isEmpty(Deck * deck) {
    return (*deck).length == 0;
}

Boolean greaterThan(Card c1, Card c2) {
    return c1.value > c2.value ? 1 : c1.suit > c2.suit ? 1 : 0;
}

int main() {
    
    Deck deck1 = emptyDeck();
    
    Card c1 = makeCard(Spades, 1);
    
    addCard(&deck1, c1);
    
    Card c2 = removeCard(&deck1);
    
    printf("%i - %i", c2.suit, c2.value);
    
    Card deck[52];
    
    //List deck = NULL;
    
    int i = 0;
    for(int suit = 0; suit < 4; suit++) {
        for(int value = 1; value <= 13; value++) {
            
            deck[i] = makeCard(suit, value);
            /*
            deck[i].suit  = suit;
            deck[i].value = value + 1;
            */
            i++;
        }
    }
    

    /*
    
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
    */
    
}





/*
#include <stdio.h>


int main(){
    
    while(1) {
        
        float x, f, k, c;
        char conv;
        scanf ("%f%c", &x, &conv);
        if(conv == 'c') {
            f = (((9.0/5.0) * x) + 32);
            printf("%6.3f Degrees F \n", f);
            k = (x - 273.15);
            printf("%6.3f Degrees K \n", k);
        }else if(conv == 'f') {
            c = ((5.0/9.0) * (x - 32));
            printf("%6.3f Degrees C \n", c);
            k = c - 273.15;
            printf("%6.3f Degrees K \n", k);
        }else if(conv == 'k') {
            c = ( x + 273.15);
            printf("%6.3f Degrees C\n", c);
            f = (((9.0/5.0) * c) +32);
            printf("%6.3f Degrees F\n", f);
        }else {;
            printf("Please enter 'c', 'f', or 'k'");
        }
    }
    
    
    
}





*/

/*
int main ()
{
    
    while(1) {
    float f, c;
    scanf ("%f,", &f);
    c = (5.0/9.0) * (f-32);
    printf("%4.3f \n", c);
    }
}
*/

/* int main()
{
    float fahr, cels;
    float lower = 0, upper = 300, step = 20;
    
    fahr = lower;
    
    while (fahr <= upper) {
        cels = (5.0/9.0) * (fahr - 32.0);
        printf ("%3.0f \t %6.1f \n", fahr, cels);
        fahr = fahr + step;
    }
    
} */

