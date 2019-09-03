## @file DCapALst.py
#  @author Michael Barreiros
#  @brief DCapALst
#  @date 09/02/2019

# from StdntAllocTypes import GenT, DeptT, SInfoT

## @brief DCapALst is an abstract data dype


class DCapALst:
    s = {}

    ## @brief the constructor for DCapALst
    #  @details sets the sequence to be an empty sequence
    @staticmethod
    def init():
        DCapALst.s = {}

    ## @brief the elm function
    #  @details returns whether or not a department is an element
    #  of the sequence
    #  @param d the department name
    #  @return a boolean value of whether or not the department is
    #  in the sequence
    @staticmethod
    def elm(d):
        return d in DCapALst.s

    ## @brief the add function
    #  @details adds a department and its capacity to the sequence
    #  @param d the department name
    #  @param n the department capacity
    #  @exception KeyError if d is already in the sequence
    @staticmethod
    def add(d, n):
        if DCapALst.elm(d):
            raise KeyError
        DCapALst.s[d] = n

    ## @brief the remove function
    #  @details removes a department and its capacity value from the sequence
    #  @param d the department name
    #  @exception KeyEror if d is not in the sequence
    @staticmethod
    def remove(d):
        if not(DCapALst.elm(d)):
            raise KeyError
        del DCapALst.s[d]

    ## @brief the capacity function
    #  @details outputs the capacity value of a given department
    #  @param d the department name
    #  @exception KeyError if d is not in the sequence
    #  @return DCapALst.s[d] this is the capacity of the department
    #  that was given
    @staticmethod
    def capacity(d):
        if not(DCapALst.elm(d)):
            raise KeyError

        return DCapALst.s[d]
