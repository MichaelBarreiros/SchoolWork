## @file SALst.py
#  @author Michael Barreiros
#  @brief SALst
#  @date 11/02/2019

# from StdntAllocTypes import GenT, DeptT, SInfoT
from AALst import AALst
from DCapALst import DCapALst

## @brief SALst an abstract data type for an allocated list of students


class SALst:

    s = {}

    ## @brief the constructor for SALst
    @staticmethod
    def init():
        SALst.s = {}

    ## @brief the elm function
    #  @details returns a boolean for whether or not m exists in the set
    #  @return a boolean value for whether or not m exists in the set
    @staticmethod
    def elm(m):
        return m in SALst.s

    ## @brief the add function
    #  @details adds a student by their macid m to the list
    #  @param m the student's macid
    #  @param i the student info of type SInfoT associated with the student
    #  @exception KeyError if the macid m already appears in the set
    @staticmethod
    def add(m, i):
        if SALst.elm(m):
            raise KeyError
        SALst.s[m] = i

    ## @brief the remove functtion
    #  @details removes a student by their macid m from the set
    #  @param m the student's macid
    #  @exception KeyError if the macid is not in the set
    @staticmethod
    def remove(m):
        if not(SALst.elm(m)):
            raise KeyError
        del SALst.s[m]

    ## @brief the info function
    #  @details this function returns the Student information for a given macid
    #  @param m the student's macid
    #  @exception KeyError if the given student doesn't exist in the set
    #  @return the student information of type SInfoT
    @staticmethod
    def info(m):
        if not(SALst.elm(m)):
            raise KeyError

        return SALst.s[m]

    ## @brief the sort function
    #  @details sorts all members of the set that are filtered by a function f
    #  @param f a function to be applied to the sequence. It takes aspects of
    #  SInfoT and returns a boolean
    #  @return L a sequence of strings that are sorted based on the function
    #  that was passed through
    @staticmethod
    def sort(f):
        usrtd = {}
        for macid in SALst.s:
            if f(SALst.info(macid)):
                usrtd[macid] = SALst.info(macid)
        ## newList was sorted using a line of code that was found
        #  on stackoverflow
        #  link is https://stackoverflow.com/questions/72899/
        #  how-do-i-sort-a-list-of-dictionaries-by-a-value-of-the-dictionary
        srtd = sorted(usrtd, key=lambda k: SALst.info(k).gpa, reverse=True)

        return srtd

    ## @brief the average function
    #  @details computes the average following a criteria given through the
    #  function file
    #  @param f a function that filters the set
    #  @exception ValueError if fset is an empty set which would cause
    #  a division by zero
    #  @return a float value for the average
    @staticmethod
    def average(f):
        fset = {}
        accumulated_gpa = 0
        for macid in SALst.s:
            if f(SALst.info(macid)):
                fset[macid] = SALst.info(macid)
                accumulated_gpa = accumulated_gpa + SALst.info(macid).gpa

        if ((len(fset)) == 0):
            raise ValueError

        return accumulated_gpa / len(fset)

    ## @brief the allocate function
    #  @details sorts freechoice students and other students then allocates
    #  freechoice students first and then allocates the other students
    #  @exception throws Runtimeerror if a student does not get allocated
    @staticmethod
    def allocate():
        AALst.init()
        freechoice_stdnts = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        other_stdnts = SALst.sort(lambda t: not(t.freechoice) and t.gpa >= 4.0)

        for macid in freechoice_stdnts:
            choices = SALst.info(macid).choices
            AALst.add_stdnt(choices.next(), macid)

        for macid in other_stdnts:
            choices = SALst.info(macid).choices
            allocated = False
            while(not(allocated) and not(choices.end())):
                dept = choices.next()
                if AALst.num_alloc(dept) < DCapALst.capacity(dept):
                    AALst.add_stdnt(dept, macid)
                    allocated = True
            if not(allocated):
                raise RuntimeError
