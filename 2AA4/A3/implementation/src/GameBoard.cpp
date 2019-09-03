#include <stdexcept>
#include <iostream>

#include "GameBoard.h"

using std::vector;
using std::invalid_argument;
using std::out_of_range;

BoardT::BoardT(){
    this->T = init_seq(10);
    this->F = init_seq(8);
    Stack<CardT> deck;
    this->D = deck;
    Stack<CardT> waste;
    this->W = waste;
}

BoardT::BoardT(vector<CardT> deck){ 
    CardStackT deckStack(deck);
    CardStackT emptyStack;
    if (!(two_decks(init_seq(10), init_seq(8), deckStack, emptyStack))) throw invalid_argument("Deck does not consist of two");

    this->T = tab_deck(deck);
    this->F = init_seq(8);

    vector<CardT> allocDeck;
    for (nat pos = 40; pos < TOTAL_CARDS; pos++){
        allocDeck.push_back(deck[pos]);
    }

    CardStackT d(allocDeck);
    
    this->D = d;
    this->W = emptyStack;
}

bool BoardT::is_valid_tab_mv(CategoryT c, nat n0, nat n1){
    if (c == Tableau  and not(is_valid_pos(Tableau, n0) and is_valid_pos(Tableau, n1))) throw out_of_range("n0 and n1 must be between 0 and 9");
    if (c == Foundation and not(is_valid_pos(Tableau, n0) and is_valid_pos(Foundation, n1))) throw out_of_range("n0 must be between 0 and 9 and n1 must be between 0 and 7");
    
    if (c == Tableau) return valid_tab_tab(n0, n1);
    else if (c == Foundation) return valid_tab_foundation(n0, n1);
    else if (c == Deck) return false;
    else if (c == Waste) return false;
    else return false;
}

bool BoardT::is_valid_waste_mv(CategoryT c, nat n){
    if (W.size() == 0) throw invalid_argument("Waste Stack is empty");
    if (c == Tableau and not(is_valid_pos(Tableau, n))) throw out_of_range("n must be between 0 and 9");
    if (c == Foundation and not(is_valid_pos(Foundation, n))) throw out_of_range("n must be between 0 and 7");

    if (c == Tableau) return valid_waste_tab(n);
    else if (c == Foundation) return valid_waste_foundation(n);
    else return false;
}

bool BoardT::is_valid_deck_mv(){
    return D.size() > 0;
}

void BoardT::tab_mv(CategoryT c, nat n0, nat n1){
    if (not(is_valid_tab_mv(c, n0, n1))) throw invalid_argument("Invalid tab move");

    if (c == Tableau){
        T[n1] = T[n1].push(T[n0].top());
        T[n0] = T[n0].pop();
    }

    if (c == Foundation){
        F[n1] = F[n1].push(T[n0].top());
        T[n0] = T[n0].pop();
    }
}

void BoardT::waste_mv(CategoryT c, nat n){
    if (not(is_valid_waste_mv(c, n))) throw invalid_argument("Invalid waste move");

    if (c == Tableau){
        T[n] = T[n].push(W.top());
        W = W.pop();
    }
    if (c == Foundation){
        F[n] = F[n].push(W.top());
        W = W.pop();
    }
}

void BoardT::deck_mv(){
    if (not(is_valid_deck_mv())) throw invalid_argument("Invalid deck move");

    W = W.push(D.top());
    D = D.pop();
}

CardStackT BoardT::get_tab(nat i){
    if (not(is_valid_pos(Tableau, i))) throw out_of_range("i must be between 0 and 9");

    return T[i];
}

CardStackT BoardT::get_foundation(nat i){
    if (not(is_valid_pos(Foundation, i))) throw out_of_range("i must be between 0 and 7");

    return F[i];
}

CardStackT BoardT::get_deck(){
    return D;
}

CardStackT BoardT::get_waste(){
    return W;
}

bool BoardT::valid_mv_exists(){
    if (is_valid_deck_mv()) return true;
    const CategoryT categories[] = { Tableau, Foundation };

    for(CategoryT c : categories){
        //implements valid_waste_mv
        for (int i = 0; i < 10; i++){
            if (is_valid_pos(c, i)){
                if (is_valid_waste_mv(c, i)){
                    return true;
                }
            }

            //implements valid_tab_mv
            for (int j = 0; j < 10; j++){
                if (is_valid_pos(Tableau, i) and is_valid_pos(c, j)){
                    if (is_valid_tab_mv(c, i, j)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool BoardT::is_win_state(){
    int testCount = 0;
    for (int i = 0; i < 8; i++){
        if (F[i].size() > 0 and F[i].top().r == KING) testCount++;
    }

    if (testCount == 7) return true;
    return false;
}

bool BoardT::two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W){
    bool check = true;
    const SuitT suits[] = { Heart, Diamond, Club, Spade };
    for (SuitT st : suits){
        for (RankT rk = ACE; rk < KING; rk++){
            int cnt_cards = 0;
            //Do the cnt_cards function here
            //Check Tableau stacks
            for (nat t = 0; t < Tmax; t++){
                vector<CardT> seqT = T[t].toSeq();
                for (nat pos = 0; pos < T[t].size(); pos++){
                    if (seqT[pos].s == st and seqT[pos].r == rk) cnt_cards++;
                }
            }

            //Check Foundation stacks
            for (nat f = 0; f < Fmax; f++){
                vector<CardT> seqF = F[f].toSeq();
                for (nat pos = 0; pos < F[f].size(); pos++){
                    if (seqF[pos].s == st and seqF[pos].r == rk) cnt_cards++;
                }
            }

            //Check Deck stack
            vector<CardT> seqD = D.toSeq();
            for (nat pos = 0; pos < D.size(); pos++){
                if (seqD[pos].s == st and seqD[pos].r == rk) cnt_cards++;
            }
            
            //Check Waste stack
            vector<CardT> seqW = W.toSeq();
            for (nat pos = 0; pos < W.size(); pos++){
                if (seqW[pos].s == st and seqW[pos].r == rk) cnt_cards++;
            }

            check = check and cnt_cards == 2;
            if (!check) break;
        }
        if (!check) break;
    }
    return check;
}

SeqCrdStckT BoardT::init_seq(nat n){
    SeqCrdStckT s;
    for (nat i = 0; i < n; i++){
        vector<CardT> empty; 
        s.push_back(CardStackT(empty));
    }
    return s;
}

SeqCrdStckT BoardT::tab_deck(vector<CardT> deck){
    SeqCrdStckT Tab;
    for (nat i = 0; i < Tmax; i++){
        CardStackT t; 
        for (nat j = 4*i; j < 4*(i + 1); j++){
            t = t.push(deck[j]);
        }
        Tab.push_back(t);
    }
    return Tab;
}

bool BoardT::is_valid_pos(CategoryT c, nat n){
    if (c == Tableau){
        if (n >= 0 and n < Tmax) return true;
        return false;
    }
    else if (c == Foundation){
        if (n >= 0 and n < Fmax) return true;
        return false;
    }
    else 
        return true;
}

bool BoardT::valid_tab_tab(nat n0, nat n1){
    if (T[n0].size() == 0) return false;
    else{
        if (T[n1].size() == 0) return true;
        
        return tab_placeable(T[n0].top(), T[n1].top());
    }
}

bool BoardT::valid_tab_foundation(nat n0, nat n1){
    if (T[n0].size() == 0) return false;
    else{
        if (F[n1].size() == 0) return T[n0].top().r == ACE;
        
        return foundation_placeable(T[n0].top(), F[n1].top());
    }
}

bool BoardT::valid_waste_tab(nat n){
    if (T[n].size() == 0) return true;
    else return tab_placeable(W.top(), T[n].top());
}

bool BoardT::valid_waste_foundation(nat n){
    if (F[n].size() == 0) return W.top().r == ACE;
    else return foundation_placeable(W.top(), F[n].top());
}

bool BoardT::tab_placeable(CardT c, CardT d){
    return (c.s == d.s and c.r == d.r -1);
}

bool BoardT::foundation_placeable(CardT c, CardT d){
    return (c.s == d.s and c.r == d.r+1);
}