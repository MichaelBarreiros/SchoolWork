from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

DCapALst.init()
DCapALst.add(DeptT.civil, 2)
DCapALst.add(DeptT.chemical, 3)

sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)
sinfo2 = SInfoT("first1", "last", GenT.female, 7.0, SeqADT([DeptT.civil, DeptT.chemical]), True)
sinfo3 = SInfoT("first2", "last", GenT.male, 8.0, SeqADT([DeptT.civil, DeptT.chemical]), False)
sinfo4 = SInfoT("first3", "last", GenT.male, 11.0, SeqADT([DeptT.civil, DeptT.chemical]), False)

SALst.init()
SALst.add("stdnt1", sinfo1)
SALst.add("stdnt2", sinfo2)
SALst.add("stdnt3", sinfo3)
SALst.add("stdnt4", sinfo4)

print(SALst.elm("stdnt1"))
print(SALst.elm("stdnt2"))
print(SALst.elm("stdnt3"))
print(SALst.elm("stdnt4"))
print(SALst.s)

print(SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0))
print(SALst.sort(lambda t: not(t.freechoice) and t.gpa >= 4.0))

print(SALst.average(lambda x: x.gender == GenT.male))

AALst.init()
SALst.allocate()
print(AALst.lst_alloc(DeptT.civil))
print(AALst.lst_alloc(DeptT.chemical))

