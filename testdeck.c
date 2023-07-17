#include <stdio.h>
#include <stdlib.h>

typedef enum kind_e {
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

typedef struct card_s {
    const char *value;
    const kind_t kind;
} card_t;

typedef struct deck_node_s {
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

// Function to compare two cards for sorting
int compare_cards(const void *a, const void *b) {
    const card_t *card_a = *((const card_t **)a);
    const card_t *card_b = *((const card_t **)b);

    if (card_a->kind < card_b->kind)
        return -1;
    else if (card_a->kind > card_b->kind)
        return 1;

    // If the cards have the same kind, compare their values
    // Assume the values are in the order of "Ace" to "King"
    const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int value_a, value_b;

    for (int i = 0; i < 13; i++) {
        if (card_a->value == values[i])
            value_a = i;
        if (card_b->value == values[i])
            value_b = i;
    }

    return value_a - value_b;
}

// Function to sort a deck of cards
void sort_deck(deck_node_t **deck) {
    // Count the number of cards in the deck
    int count = 0;
    deck_node_t *current = *deck;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Create an array of card pointers
    card_t *cards[count];
    current = *deck;

    for (int i = 0; i < count; i++) {
        cards[i] = (card_t *)current->card;
        current = current->next;
    }

    // Sort the array of card pointers using qsort
    qsort(cards, count, sizeof(card_t *), compare_cards);

    // Reorder the deck using the sorted array of card pointers
    current = *deck;

    for (int i = 0; i < count; i++) {
        current->card = cards[i];
        current = current->next;
    }
}

// Function to print the sorted deck
void print_sorted_deck(deck_node_t **deck) {
    deck_node_t *current = *deck;

    while (current != NULL) {
        printf("Value: %s, Kind: %d\n", current->card->value, current->card->kind);
        current = current->next;
    }
}

// Example usage
int main() {
    // Create a deck of cards (already in a shuffled order)
    card_t cards[] = {
        {"Ace", SPADE},
        {"King", CLUB},
        {"8", DIAMOND},
        {"4", HEART},
        {"Queen", DIAMOND},
        {"10", CLUB},
        // Add the remaining cards...
    };

    // Create a doubly linked list to represent the deck
    deck_node_t *deck = NULL;
    deck_node_t *prev = NULL;

    for (int i = 0; i < 52; i++) {
        deck_node_t *node = malloc(sizeof(deck_node_t));
        node->card = &cards[i];
        node->prev = prev;
        node->next = NULL;

        if (prev != NULL)
            prev->next = node;

        prev = node;

        if (deck == NULL)
            deck = node;
    }

    // Sort the deck
    sort_deck(&deck);

    // Print the sorted deck
    printf("Sorted deck:\n");
    print_sorted_deck(&deck);

    return 0;
}
