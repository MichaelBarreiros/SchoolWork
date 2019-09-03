/**
 * \file CardTypes.h
 * \author Michael Barreiros
 * \brief defining the different types and constants that will be used to build cards
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Defining number of total cards for understandability in code
 */
#define TOTAL_CARDS  104

/**
 * \brief Enumerated type defining the 4 different suits of a card
 */
enum SuitT{ Heart, Diamond, Club, Spade };

/**
 * \brief Enumerated type defining the different categories of stacks in the game
 */
enum CategoryT{ Tableau, Foundation, Deck, Waste };

/**
 * \brief A struct defining what a card is. it has a suit of type SuitT and a rank of type RankT
 */
struct CardT{
    SuitT s;
    RankT r;
};

/**
 * \brief defining nat for understandability in code
 */
typedef unsigned int nat;

#endif
