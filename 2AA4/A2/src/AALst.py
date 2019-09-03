## @file AALst.py
#  @author Michael Barreiros
#  @brief AALst
#  @date 09/02/2019

from StdntAllocTypes import DeptT

## @brief AALst an abstract data type


class AALst:
    s = {}
    ## @brief the constructor for AALst
    #  @details goes through every department in DepT and sets its key
    #  to an empty list
    @staticmethod
    def init():
        for d in DeptT:
            AALst.s[d] = []

    ## @brief the add_stdnt function
    #  @details adds a string, m, to the department, dep.
    #  @param dep the department name
    #  @param m a string
    @staticmethod
    def add_stdnt(dep, m):
        if dep in AALst.s:
            AALst.s[dep].append(m)

    ## @brief the lst_alloc function
    #  @details returns the sequence of strings for a department
    #  @param d the department name
    #  @return AALst.s[d] the List associated with a department
    @staticmethod
    def lst_alloc(d):
        return AALst.s[d]

    ## @brief the num_alloc function
    #  @details outputs the size of the sequence that is the value to
    #  a department, d.
    #  @param d the department name
    #  @return the length of the sequence that is associated with a department
    @staticmethod
    def num_alloc(d):
        return len(AALst.s[d])
