/**
 * \file testStack.cpp
 * \brief Implementation of Stack tests.
 * \author Michael Barreiros
 */

#include "Stack.h"
#include "CardTypes.h"
#include "catch.h"
#include "CardStack.h"
using std::vector;
using std::out_of_range;

TEST_CASE( "Test for Stack", "[Stack]" ) {
    SECTION( "Test empty constructor" ){
        CardStackT cs = CardStackT(vector<CardT>());
        REQUIRE(cs.size() == 0); 
    }

    SECTION( "Test empty stack throws out_of_range error when trying to pop" ){
        CardStackT cs = CardStackT(vector<CardT>());
        REQUIRE_THROWS_AS(cs.pop(), out_of_range); 
    }

    SECTION( "Test empty stack throws out_of_range error when trying to access top" ){
        CardStackT cs = CardStackT(vector<CardT>());
        REQUIRE_THROWS_AS(cs.top(), out_of_range); 
    }

    SECTION( "Test non-empty constructor" ){
        CardT c0{Heart, ACE};
        CardT c1{Diamond, KING};
        CardT c2{Spade, 7};

        vector<CardT> cards = vector<CardT>();
        cards.push_back(c0);
        cards.push_back(c1);
        cards.push_back(c2);

        REQUIRE(cards[0].s == Heart);
        REQUIRE(cards[1].s == Diamond);
        REQUIRE(cards[2].s == Spade);

        CardStackT cs = CardStackT(cards);
        REQUIRE(cs.size() == 3);
        REQUIRE(cs.top().r == 7);
    }

    SECTION("Test push does not change original stack's size"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		REQUIRE(cs.size() == 0);
  		cs.push(c0);
  		REQUIRE(cs.size() == 0);
  		cs.push(c1);
  		REQUIRE(cs.size() == 0);
  		cs.push(c2);
  		REQUIRE(cs.size() == 0);
  		cs.push(c3);
  		REQUIRE(cs.size() == 0);
  	}

    SECTION("Test push increases size of new object"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		REQUIRE(cs.size() == 0);
  		cs = cs.push(c0);
  		REQUIRE(cs.size() == 1);
  		cs = cs.push(c1);
  		REQUIRE(cs.size() == 2);
  		cs = cs.push(c2);
  		REQUIRE(cs.size() == 3);
  		cs = cs.push(c3);
  		REQUIRE(cs.size() == 4);
  	}

    SECTION("Test push changes top of new stack"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};

        CardStackT cs = CardStackT(vector<CardT>());  		
  		cs = cs.push(c0);
  		REQUIRE(cs.top().s == Heart);
		REQUIRE(cs.top().r == ACE);
  		cs = cs.push(c1);
  		REQUIRE(cs.top().s == Diamond);
  		REQUIRE(cs.top().r == KING);
  		cs = cs.push(c2);
  		REQUIRE(cs.top().s == Spade);
  		REQUIRE(cs.top().r == 7);
  		cs = cs.push(c3);
  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  	}

    SECTION("Test push does not change top of original stack"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);

  		REQUIRE(cs.top().s == Spade);
  		REQUIRE(cs.top().r == 7);

  		cs.push(c3);
        REQUIRE(cs.top().s == Spade);
  		REQUIRE(cs.top().r == 7);
  	}

    SECTION("Test pop does not change original stack's size"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);
  		cs = cs.push(c3);

  		REQUIRE(cs.size() == 4);
  		cs.pop();
  		REQUIRE(cs.size() == 4);
  		cs.pop();
  		REQUIRE(cs.size() == 4);
  		cs.pop();
  		REQUIRE(cs.size() == 4);
  		cs.pop();
  		REQUIRE(cs.size() == 4);
  	}

    SECTION("Test pop does not change top of original stack"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);
  		cs = cs.push(c3);

  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  		cs.pop();

  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  		cs.pop();

  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  		cs.pop();

  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  	}

    SECTION("Test pop decreases size of new stack"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);
  		cs = cs.push(c3);

  		REQUIRE(cs.size() == 4);
  		cs = cs.pop();
  		REQUIRE(cs.size() == 3);
  		cs = cs.pop();
  		REQUIRE(cs.size() == 2);
  		cs = cs.pop();
  		REQUIRE(cs.size() == 1);
  		cs = cs.pop();
  		REQUIRE(cs.size() == 0);
  	}

    SECTION("Test pop changes top of new stack"){
		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};
  		
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);
  		cs = cs.push(c3);

  		REQUIRE(cs.top().s == Club);
  		REQUIRE(cs.top().r == 10);
  		cs = cs.pop();

  		REQUIRE(cs.top().s == Spade);
  		REQUIRE(cs.top().r == 7);
  		cs = cs.pop();

  		REQUIRE(cs.top().s == Diamond);
  		REQUIRE(cs.top().r == KING);
  		cs = cs.pop();

  		REQUIRE(cs.top().s == Heart);
  		REQUIRE(cs.top().r == ACE);
  	}

    SECTION("Test toSeq returns correct sequence"){
  		CardT c0{Heart, ACE};
  		CardT c1{Diamond, KING};
  		CardT c2{Spade, 7};
  		CardT c3{Club, 10};

  		//proper ordering of cards
		std::vector<CardT> cards = std::vector<CardT>();
		cards.push_back(c0);cards.push_back(c1);cards.push_back(c2);cards.push_back(c3);
  		
  		//test when placed by push()
        CardStackT cs = CardStackT(vector<CardT>());
  		cs = cs.push(c0);
  		cs = cs.push(c1);
  		cs = cs.push(c2);
  		cs = cs.push(c3);

		std::vector<CardT> fromStack = cs.toSeq();
		for (nat i = 0; i < fromStack.size(); i++){
			REQUIRE(cards[i].s == fromStack[i].s);
			REQUIRE(cards[i].r == fromStack[i].r);
		}

		//test when placed by constructor
		CardStackT newCs = CardStackT(cards);

		std::vector<CardT> fromNewStack = newCs.toSeq();
		for (nat i = 0; i < fromNewStack.size(); i++){
			REQUIRE(cards[i].s == fromNewStack[i].s);
			REQUIRE(cards[i].r == fromNewStack[i].r);
		}
  	}
}