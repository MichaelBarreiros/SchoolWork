/**
 * \file testGameBoard.cpp
 * \brief Implementation of GameBoard tests.
 * \author Michael Barreiros
 */

#include "Stack.h"
#include "CardTypes.h"
#include "catch.h"
#include "CardStack.h"
#include "GameBoard.h"
#include <algorithm>
#include <iostream>
using std::vector;
using std::out_of_range;
using std::invalid_argument;

TEST_CASE( "Tests for Gameboard", "[GameBoard]" ){

    SECTION( "Test GameBoard default constructor" ){
        BoardT board = BoardT();
        for (nat i = 0; i < 10; i++){
            REQUIRE(board.get_tab(i).size() == 0);
        }
        for (nat j = 0; j < 8; j++){
            REQUIRE(board.get_foundation(j).size() == 0);
        }
        REQUIRE(board.get_deck().size() == 0);
        REQUIRE(board.get_waste().size() == 0);        
    }

    SECTION( "Test Gameboard deck constructor" ){
        // Produce a new deck (consisting of two standard decks) and shuffle its
        // cards.
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }
        std::random_shuffle(d.begin(), d.end());

        //Construct Board
        BoardT board = BoardT(d);

        for(nat i = 0; i < 10; i++){
            //Ensure each tableau cell is the right size
            REQUIRE(board.get_tab(i).size() == 4);
            vector<CardT> tab = board.get_tab(i).toSeq();
            //Ensure that the tableau is built properly according to the spec
            REQUIRE(tab[0].s == d[4*i].s);
            REQUIRE(tab[0].r == d[4*i].r);
            REQUIRE(tab[1].s == d[4*(i+1) - 3].s);
            REQUIRE(tab[1].r == d[4*(i+1) - 3].r);
            REQUIRE(tab[2].s == d[4*(i+1) - 2].s);
            REQUIRE(tab[2].r == d[4*(i+1) - 2].r);
            REQUIRE(tab[3].s == d[4*(i+1) - 1].s);
            REQUIRE(tab[3].r == d[4*(i+1) - 1].r);

        }
        for (nat j = 0; j < 8; j++){
            REQUIRE(board.get_foundation(j).size() == 0);
        }
        REQUIRE(board.get_deck().size() == 64);
        REQUIRE(board.get_waste().size() == 0);   
    }

    SECTION( "Test GameBoard deck constructor throws invalid_argument" ){
        // Produce a new deck (consisting of only one deck) and shuffle its
        // cards.
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
            }
        }
        std::random_shuffle(d.begin(), d.end());

        //Construct Board
        REQUIRE_THROWS_AS(BoardT(d), invalid_argument);
    }

    SECTION( "Test is_valid_tab_mv" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        /**
         * Checking the state of the game for possible moves
         * for (nat i = 0; i < 10; i++){
         *  std::cout << board.get_tab(i).top().s << " " << board.get_tab(i).top().r << std::endl;
        }*/
        
        REQUIRE(board.is_valid_tab_mv(Tableau, 0, 2));
        REQUIRE(board.is_valid_tab_mv(Deck, 0, 1) == false);
        REQUIRE(board.is_valid_tab_mv(Waste, 0, 1) == false);
        REQUIRE(board.is_valid_tab_mv(Foundation, 0, 0));
    }

    SECTION( "Test is_valid_tab_mv throws out_of_range" ){
        BoardT board = BoardT();
        REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau, 0, 10), out_of_range);
        REQUIRE_THROWS_AS(board.is_valid_tab_mv(Foundation, 0, 8), out_of_range);
    }

    SECTION( "Test is_valid_waste_mv throws invalid_argument" ){
        BoardT board = BoardT();
        REQUIRE_THROWS_AS(board.is_valid_waste_mv(Tableau, 0), invalid_argument);
    }

    SECTION( "Test is_valid_waste_mv throws out_of_range" ){
        //Produce a new deck (consisting of two standard decks
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        board.deck_mv();

        REQUIRE_THROWS_AS(board.is_valid_waste_mv(Tableau, 10), out_of_range);
        REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation, 8), out_of_range);
    }

    SECTION( "Test eis_valid_waste_mv" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        
        //Checking the state of the game for possible moves
        /*for (nat i = 0; i < 10; i++){
            std::cout << board.get_tab(i).top().s << " " << board.get_tab(i).top().r << std::endl;
        }
        */
        board.deck_mv();

        //std::cout << board.get_waste().top().s << " " << board.get_waste().top().r << std::endl;
        REQUIRE(board.is_valid_waste_mv(Tableau, 2) == false);
        REQUIRE(board.is_valid_waste_mv(Deck, 1) == false);
        REQUIRE(board.is_valid_waste_mv(Waste, 1) == false);
        REQUIRE(board.is_valid_waste_mv(Foundation, 0) == false);
    }

    SECTION( "Test is_valid_deck_mv"){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        BoardT emptyBoard = BoardT();
        REQUIRE(board.is_valid_deck_mv());
        REQUIRE(emptyBoard.is_valid_deck_mv() == false);
    }

    SECTION( "Test tab_mv places card correctly" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        
        //Checking the state of the game for possible moves
        /*for (nat i = 0; i < 10; i++){
            std::cout << board.get_tab(i).top().s << " " << board.get_tab(i).top().r << std::endl;
        }*/
        CardT source = board.get_tab(1).top();
        REQUIRE(source.s == Spade);
        REQUIRE(source.r == ACE);
        board.tab_mv(Tableau, 1, 3);
        CardT target = board.get_tab(3).top();
        REQUIRE(source.s == target.s);
        REQUIRE(source.r == target.r);
        board.tab_mv(Foundation, 3, 0);
        CardT fTarget = board.get_foundation(0).top();
        REQUIRE(source.s == fTarget.s);
        REQUIRE(source.r == fTarget.r);
    }

    SECTION ( "Test tab_mv throws invalid argument" ){
        // Produce a new deck (consisting of two standard decks) 
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        REQUIRE_THROWS_AS(board.tab_mv(Tableau, 0, 1), invalid_argument);
        REQUIRE_THROWS_AS(board.tab_mv(Foundation, 3, 0), invalid_argument);
        REQUIRE_THROWS_AS(board.tab_mv(Deck, 0, 0), invalid_argument);
        REQUIRE_THROWS_AS(board.tab_mv(Waste, 0, 0), invalid_argument);
    }

    SECTION( "Test waste_mv places card correctly" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = KING; rank >= ACE; rank--) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        
        //Checking the state of the game for possible moves
        /*for (nat i = 0; i < 10; i++){
            std::cout << board.get_tab(i).top().s << " " << board.get_tab(i).top().r << std::endl;
        }
        std::cout << std::endl;
        */

        board.deck_mv();
        CardT source = board.get_waste().top();
        board.waste_mv(Foundation, 0);
        CardT fTarget = board.get_foundation(0).top();
        REQUIRE(source.s == fTarget.s);
        REQUIRE(source.r == fTarget.r);

        for(int i = 0; i < 57; i++) board.deck_mv();
    
        source = board.get_waste().top();
        REQUIRE(source.s == Spade);
        REQUIRE(source.r == 8);
        board.waste_mv(Tableau, 9);
        CardT target = board.get_tab(9).top();
        REQUIRE(source.s == target.s);
        REQUIRE(source.r == target.r);
    }

    SECTION( "Test waste_mv throws invalid_argument" ){
        BoardT emptyBoard = BoardT();
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Tableau, 0), invalid_argument);
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Tableau, 10), invalid_argument);
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Foundation, 0), invalid_argument);
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Foundation, 8), invalid_argument);
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Deck, 0), invalid_argument);
        REQUIRE_THROWS_AS(emptyBoard.waste_mv(Waste, 0), invalid_argument);
    }

    SECTION( "Test deck_mv" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = KING; rank >= ACE; rank--) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        CardT source = board.get_deck().top();
        nat deckSizeBefore = board.get_deck().size();
        board.deck_mv();
        nat deckSizeAfter = board.get_deck().size();

        CardT target = board.get_waste().top();
        REQUIRE(source.s == target.s);
        REQUIRE(source.r == target.r);
        REQUIRE(deckSizeAfter == deckSizeBefore - 1);
    }

    SECTION( "Test deck_mv throws invalid_argument" ){
        BoardT emptyBoard = BoardT();
        REQUIRE_THROWS_AS(emptyBoard.deck_mv(), invalid_argument);
    }

    SECTION( "Test get_tab returns correctly"){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        REQUIRE(board.get_tab(0).top().s == Diamond);
        REQUIRE(board.get_tab(0).top().r == ACE);
    }

    SECTION( "Test get_tab throws out_of_range" ){
        BoardT emptyBoard = BoardT();
        REQUIRE_THROWS_AS(emptyBoard.get_tab(10), out_of_range);
        REQUIRE_THROWS_AS(emptyBoard.get_tab(100), out_of_range);
    }

    SECTION( "Test get_foundation returns correctly" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        
        //Checking the state of the game for possible moves
        /*for (nat i = 0; i < 10; i++){
            std::cout << board.get_tab(i).top().s << " " << board.get_tab(i).top().r << std::endl;
        }*/
        CardT source = board.get_tab(1).top();
        REQUIRE(source.s == Spade);
        REQUIRE(source.r == ACE);

        board.tab_mv(Foundation, 1, 0);
        CardT fTarget = board.get_foundation(0).top();
        REQUIRE(fTarget.s == Spade);
        REQUIRE(fTarget.r == ACE);
    }

    SECTION( "Test get_foundation throws out_of_range" ){
        BoardT emptyBoard = BoardT();
        REQUIRE_THROWS_AS(emptyBoard.get_foundation(8), out_of_range);
        REQUIRE_THROWS_AS(emptyBoard.get_foundation(100), out_of_range);
    }

    SECTION( "Test get_deck returns correctly" ){
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        
        REQUIRE(board.get_deck().top().s == Spade);
        REQUIRE(board.get_deck().top().r == KING);
        
    }

    SECTION( "Test get_waste returns correctly" ){
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        CardT topDeck = board.get_deck().top();
        board.deck_mv();
        REQUIRE(topDeck.s == board.get_waste().top().s);
        REQUIRE(topDeck.r == board.get_waste().top().r);
    }

    SECTION( "Test valid_mv_exists" ){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        REQUIRE(board.valid_mv_exists());
    }

    SECTION( "Test is_win_state"){
        // Produce a new deck (consisting of two standard decks)
        std::vector<CardT> d;
        for (RankT rank = ACE; rank <= KING; rank++) {
            for (unsigned int suit = 0; suit < 4; suit++) {
                CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
            }
        }

        //Construct Board
        BoardT board = BoardT(d);
        REQUIRE(board.is_win_state() == false);
    }
}

