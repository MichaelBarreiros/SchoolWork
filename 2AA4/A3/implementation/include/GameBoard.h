/**
 * \file Gameboard.h
 * \author Michael Barreiros
 * \brief An Abstract Data Type for representing the state of a game of Forty Thieves
 */
#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardStack.h"
#include "CardTypes.h"
#include <vector>

/**
 * \brief a typedef for SeqCrdStckT to help in code readability
 */
typedef std::vector<CardStackT> SeqCrdStckT;

/**
 * \brief Class for representing the gameboard of a game of Forty Thieves
 * \details Representing the state of the game as well as functions for making and validating
 * moves and verifying win states and states with no possible moves. 
 */
class BoardT{
    private:
        SeqCrdStckT T;
        SeqCrdStckT F;
        CardStackT D;
        CardStackT W;
        //constants for testing invariants
        
        const nat Tmax = 10;
        const nat Fmax = 8;
        //local functions 

        bool two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W);
        SeqCrdStckT init_seq(nat n);
        SeqCrdStckT tab_deck(std::vector<CardT> deck);
        bool is_valid_pos(CategoryT c, nat n);
        bool valid_tab_tab(nat n0, nat n1);
        bool valid_tab_foundation(nat n0, nat n1);
        bool valid_waste_tab(nat n);
        bool valid_waste_foundation(nat n);
        bool tab_placeable(CardT c, CardT d);
        bool foundation_placeable(CardT c, CardT d);


    public:
        /**
         * \brief Constructs a new Forty Thieves gameboard
         * \details Creates a new instance of a gameboard with all cells empty. This can 
         * be populated manually
         */
        BoardT();

        /**
         * \brief Constructs a new Forty Thieves gameboard from a deck of cards
         * \details Create a new instance of a gameboard by placing first 40 cards of the given deck
         * onto the tableau cells of the gameboard
         * \param deck A deck of cards to be used to set up the gameboard
         * \throws invalid_argument There arent two of every cards in the deck
         */
        BoardT(std::vector<CardT> deck);

        /**
         * \brief Determine whether a given move is valid given the current state of the gameboard
         * \details Returns whether moving a potential card from a Tableau source cell to a target cell
         * is a valid move according to the rules of Forty Thieves
         * \return Whether the move is valid. A boolean value True = 1, False = 0
         * \param c The type of cell of the target cell
         * \param n0 The index for accessing the correct stack of the source Tableau cell
         * \param n1 The index for accessing the correct stack of the target cell
         * \throw out_of_range if the positions given by n0 or n1 are invalid positions on the board
         */
        bool is_valid_tab_mv(CategoryT c, nat n0, nat n1);

        /**
         * \brief Determine whether a given move is valid given the current state of the gameboard
         * \details Returns whether moving a potential card from the waste stack to a target cell
         * is a valid move according to the rules of Forty Thieves
         * \return Whether the move is valid. A boolean value True = 1, False = 0
         * \param c The type of cell of the target cell
         * \param n The index for accessing the correct stack of the target cell
         * \throw out_of_range if the position given by n on the board
         */
        bool is_valid_waste_mv(CategoryT c, nat n);

        /**
         * \brief Determine whether a given move is valid given the current state of the gameboard
         * \details Returns whether moving a potential card from the deck stack to the waste stack
         * is a valid move according to the rules of Forty Thieves
         * \return Whether the move is valid. A boolean value True = 1, False = 0
         */
        bool is_valid_deck_mv();

        /**
         * \brief Make a move from one tableau cell to a target cell, if it's valid
         * \details Moves a card from the top of a tableau cell represented by n0 to
         * the top of the cell represented by c and n1
         * \param c The type of cell of the target cell
         * \param n0 The index for accessing the correct stack of the source Tableau cell
         * \param n1 The index for accessing the correct stack of the target cell  
         * \throw invalid_argument if the desired move is not valid
         */
        void tab_mv(CategoryT c, nat n0, nat n1);

        /**
         * \brief Make a move from the waste stack to a target cell, if it's valid
         * \details Moves a card from the top of the waste stack to the top of the 
         * cell represented by c and n
         * \param c The type of cell of the target cell
         * \param n The index for accessing the correct stack of the target cell
         * \throw invalid_argument if the desired move is not valid
         */
        void waste_mv(CategoryT c, nat n);

        /**
         * \brief Make a move from the deck to the waste
         * \details Moves a card from the top of the deck stack to the top of the waste stack
         * \throw invalid_argument if the desired move is not valid
         */
        void deck_mv();

        /**
         * \brief Get the tab cell designated by n
         * \details Return the Tableau stack at the given position designated by n
         * \param n The position that is being accessed
         * \throw out_of_range if n is not a valid position
         */
        CardStackT get_tab(nat n);

        /**
         * \brief Get the foundation cell designated by n
         * \details Return the Foundation stack at the given position designated by n
         * \param n The position that is being accessed
         * \throw out_of_range if n is not a valid position
         */
        CardStackT get_foundation(nat n);

        /**
         * \brief Get the deck stack
         * \details Returns the deck stack 
         */
        CardStackT get_deck();

        /**
         * \brief Get the waste stack
         * \details Returns the waste stack
         */
        CardStackT get_waste();

        /**
         * \brief Determine whether or not a valid move exists
         * \details Returns whether the current game state contains a valid move
         * \return true if a valid move exists on the gameboard, false otherwhise
         */
        bool valid_mv_exists();

        /**
         * \brief Determine whether the gameboard is currently in the win state
         * \details Returns whether the current game state is a win state. 
         * This means that all eight foundations are stacked from Ace to King.
         * There will be 2 stacks per suit.
         */
        bool is_win_state();
};

#endif
