/*
 * Use this file for experimenting with your code,
 * testing things that don't work, debugging, etc.
 *
 * You can compile and run this via 'make experiment'
 *
 * This file will not be graded
 */
#include <algorithm>
#include <iostream>
#include <vector>

#include "CardStack.h"
#include "CardTypes.h"
#include "GameBoard.h"
#include "Stack.h"

int main() {
  std::cout << "'make experiment' will run this main" << std::endl;

  // When you are finished your implementation, uncomment the code
  // below and make sure 'make experiment' compiles and runs.
  // This will ensure that your interface has the correct syntax and will be
  // compatible with our unit tests that we will run for grading.

  
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

  BoardT board(d);
  try {
    std::cout << "Valid tab move? " << board.is_valid_tab_mv(Foundation, 0, 0) << std::endl;
  } catch (std::out_of_range &e) {}
  try {
    std::cout << "Valid waste move? " << board.is_valid_waste_mv(Foundation, 0) << std::endl;
  } catch (std::invalid_argument &e) {}
  std::cout << "Valid deck move? "   << board.is_valid_deck_mv() << std::endl;
  std::cout << "Is win state? "      << board.is_win_state() << std::endl;
  std::cout << "Valid move exists? " << board.valid_mv_exists() << std::endl;
  try {
    board.tab_mv(Tableau, 0, 1);
  } catch (std::invalid_argument &e) {}
  board.deck_mv();
  try {
    board.waste_mv(Tableau, 0);
  } catch (std::invalid_argument &e) {}
  CardStackT tableau = board.get_tab(0);
  CardStackT foundation = board.get_foundation(0);
  CardStackT deck = board.get_deck();
  CardStackT waste = board.get_waste();

  std::vector<CardT> vec = deck.toSeq();
  std::cout << "Sequence length: " << vec.size() << std::endl;
  std::cout << "Deck size: " << deck.size() << std::endl;
  std::cout << "Deck top: " << deck.top().s << " " << deck.top().r << std::endl;

  CardStackT foo(vec);
  foo = foo.push(d[0]);
  CardT bar = foo.top();
  std::cout << "Card: " << bar.s << " " << bar.r << std::endl;
  foo = foo.pop();
  
  //My own testing
  CardT card1 = {Heart, JACK};
  CardT card2 = {Spade, 3};
  std::vector<CardT> seq;
  seq.push_back(card1);
  CardStackT stack(seq);
  std::cout << "stack with one card: " << stack.top().s << " " << stack.top().r << std::endl;
  stack = stack.push(card2);
  std::cout << "stack with two card: " << stack.top().s << " " << stack.top().r << std::endl;

  std::vector<CardT> stackSeq = stack.toSeq();
  std::cout << "seq with two card top: " << stackSeq[1].s << " " << stackSeq[1].r << std::endl;

  stack.pop();
  std::cout << "stack after pop: " << stack.top().s << " " << stack.top().r << std::endl;


  std::cout << "Foundation size: " <<  foundation.size() << std::endl;

  for (nat t = 0; t < 10; t++){
    std::cout << "Card stack " << t << " size: " << board.get_tab(t).size() << std::endl;
    std::vector<CardT> tab = board.get_tab(t).toSeq();
    std::cout << "Card stack " << t << std::endl;
    for (nat card = 0; card < tab.size(); card++){
      std::cout << "Card " << card << ": " << tab[card].s << " " << tab[card].r << std::endl;
    }
  }

  CardStackT empty;
  CardStackT empty1;
  empty = empty.push(card1);
  empty = empty.push(card2);
  std::cout << "Empty stack check: " << (empty.size() == 0) << std::endl;
  std::cout << "Empty stack check: " << (empty1.size() == 0) << std::endl;
  std::cout << "Foundation size: " <<  foundation.size() << std::endl;

  std::cout << "Empty stack check after two pushes: " << (empty.size() == 0) << std::endl;
  std::cout << "empty stack card at top: " << empty.top().s << " " << empty.top().r << std::endl;
  return 0;
}
