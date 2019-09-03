## @file SeqADT.py
#  @author Michael Barreiros
#  @brief SeqADT
#  @date 09/02/2019

## @brief An abstract data type for a sequence


class SeqADT:
    
    s = []
    i = 0
    ## @brief SeqADT constructor
    #  @details initalizes the sequence with a given sequence
    #  @param x is a sequence of type T that SeqADT will be initialized to
    #  @return returns itself, a SeqADT type
    def __init__(self, x):
        self.s = x
        self.i = 0

    ## @brief start method
    #  @details resets the iterator i to 0, which is the "start" of the
    #  sequence
    def start(self):
        self.i = 0

    ## @brief next method
    #  @details returns the sequence at i and adds one to the iterator, this
    #  effectively moves the iterator to the next element in the sequence
    #  @exception throws StopIteration if i is greater or equal to the
    #  size of s
    #  @return returns s[i] before i got one added to it
    def next(self):
        if self.i >= len(self.s):
            raise StopIteration
        temp = self.s[self.i]
        self.i = self.i + 1

        return temp

    ## @brief end method
    #  @details this function's purpose is to return whether or not i is
    #  at the end of s
    def end(self):
        return self.i >= len(self.s)
