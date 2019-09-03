import pytest
from SeqADT import *
from DCapALst import *
from SALst import *
from AALst import *
from StdntAllocTypes import *


class TestAll:

    def setup_method(self, method):
        self.sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT(
                             [DeptT.civil, DeptT.chemical]), True)
        self.sinfo2 = SInfoT("first1", "last", GenT.female, 7.0, SeqADT(
                             [DeptT.civil, DeptT.chemical]), True)
        self.sinfo3 = SInfoT("first2", "last", GenT.male, 12.0, SeqADT(
                             [DeptT.civil, DeptT.chemical]), False)
        self.sinfo4 = SInfoT("first3", "last", GenT.male, 12.0, SeqADT(
                             [DeptT.civil, DeptT.chemical]), False)

        self.choices = SeqADT([DeptT.civil, DeptT.mechanical, DeptT.engphys])
        self.SeqADT_None = SeqADT(None)
        self.SeqADT_list = SeqADT([1, 2, 3, 4])
        self.DCapALst = DCapALst()
        self.SALst = SALst()

    def teardown_method(self, method):
        self.sinfo1 = None
        self.sinfo2 = None
        self.sinfo3 = None
        self.sinfo4 = None
        self.choices = None
        self.SeqADT_None = None
        self.SeqADT_list = None
        self.DCapALst = self.DCapALst.s.clear()
        self.SALst = self.SALst.s.clear()

    def test_SeqADT_init1(self):
        assert not self.SeqADT_None.s

    def test_SeqADT_init2(self):
        assert self.SeqADT_None.i == 0

    def test_SeqADT_init3(self):
        assert self.SeqADT_list.s == [1, 2, 3, 4]

    def test_SeqADT_start1(self):
        self.choices.start()
        assert self.choices.i == 0

    def test_SeqADT_start2(self):
        self.choices.next()
        self.choices.next()
        self.choices.start()
        assert self.choices.i == 0

    def test_SeqADT_next1(self):
        assert self.choices.next() == DeptT.civil

    def test_SeqADT_next2(self):
        self.choices.next()
        assert self.choices.next() == DeptT.mechanical

    def test_SeqADT_next3(self):
        self.choices.next()
        self.choices.next()
        assert self.choices.next() == DeptT.engphys

    def test_SeqADT_next4(self):
        with pytest.raises(StopIteration):
            self.choices.next()
            self.choices.next()
            self.choices.next()
            self.choices.next()

    def test_SeqADT_end1(self):
        assert not(self.choices.end())

    def test_SeqADT_end2(self):
        self.choices.next()
        self.choices.next()
        self.choices.next()
        assert self.choices.end()

    def test_DCapALst_init1(self):
        assert self.DCapALst.s == {}

    def test_DCapALst_add1(self):
        self.DCapALst.add(DeptT.civil, 10)
        self.DCapALst.add(DeptT.chemical, 20)
        assert self.DCapALst.s == {DeptT.civil: 10, DeptT.chemical: 20}

    def test_DCapALst_add2(self):
        with pytest.raises(KeyError):
            self.DCapALst.add(DeptT.civil, 10)
            self.DCapALst.add(DeptT.civil, 10)

    def test_DCapALst_remove1(self):
        self.DCapALst.add(DeptT.civil, 10)
        self.DCapALst.remove(DeptT.civil)
        assert self.DCapALst.s == {}

    def test_DCapALst_remove2(self):
        with pytest.raises(KeyError):
            self.DCapALst.remove(DeptT.mechanical)

    def test_DCapALst_elm(self):
        self.DCapALst.add(DeptT.civil, 10)
        assert self.DCapALst.elm(DeptT.civil)

    def test_DCapALst_capacity1(self):
        self.DCapALst.add(DeptT.civil, 10)
        assert self.DCapALst.capacity(DeptT.civil) == 10

    def test_DCapALst_capacity2(self):
        with pytest.raises(KeyError):
            self.DCapALst.capacity(DeptT.civil)

    def test_SALst_init1(self):
        assert self.SALst.s == {}

    def test_SALst_add1(self):
        self.SALst.add("student", ["test"])
        assert self.SALst.s == {"student": ["test"]}

    def test_SALst_add2(self):
        with pytest.raises(KeyError):
            self.SALst.add("student", ["test"])
            self.SALst.add("student", ["test"])

    def test_SALst_remove1(self):
        self.SALst.add("student", ["test"])
        self.SALst.remove("student")
        assert self.SALst.s == {}

    def test_SALst_remove2(self):
        with pytest.raises(KeyError):
            self.SALst.remove("student")

    def test_SALst_sort1(self):
        self.SALst.add("s1", self.sinfo1)
        self.SALst.add("s2", self.sinfo2)
        self.SALst.add("s3", self.sinfo3)
        self.SALst.add("s4", self.sinfo4)

        g = self.SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        assert g == ["s1", "s2"]

    def test_SALst_sort2(self):
        g = self.SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        assert g == []

    def test_SALst_average1(self):
        self.SALst.add("s1", self.sinfo1)
        self.SALst.add("s2", self.sinfo2)
        self.SALst.add("s3", self.sinfo3)
        self.SALst.add("s4", self.sinfo4)

        assert self.SALst.average(lambda x: x.gender == GenT.male) == 12.0

    def test_SALst_average2(self):
        with pytest.raises(ValueError):
            self.SALst.add("s1", self.sinfo1)
            self.SALst.add("s3", self.sinfo3)
            self.SALst.add("s4", self.sinfo4)
            self.SALst.average(lambda x: x.gender == GenT.female)

    def test_SALst_allocate1(self):
        self.DCapALst.add(DeptT.chemical, 2)
        self.DCapALst.add(DeptT.civil, 2)
        self.SALst.add("s1", self.sinfo1)
        self.SALst.add("s2", self.sinfo2)
        self.SALst.add("s3", self.sinfo3)
        self.SALst.add("s4", self.sinfo4)

        self.SALst.allocate()
        assert AALst.lst_alloc(DeptT.civil) == ["s1", "s2"]

    def test_SALst_allocate2(self):
        self.DCapALst.add(DeptT.chemical, 2)
        self.DCapALst.add(DeptT.civil, 2)

        self.SALst.allocate()
        assert AALst.lst_alloc(DeptT.civil) == []

    def test_SAL_allocate3(self):
        with pytest.raises(RuntimeError):
            self.DCapALst.add(DeptT.civil, 0)
            self.DCapALst.add(DeptT.chemical, 0)
            self.SALst.add("s3", self.sinfo3)
            self.SALst.allocate()

    def test_SALst_allocate4(self):
        self.DCapALst.add(DeptT.chemical, 1)
        self.DCapALst.add(DeptT.civil, 2)
        self.SALst.add("s1", self.sinfo1)
        self.SALst.add("s2", self.sinfo2)
        self.SALst.add("s3", self.sinfo3)

        self.SALst.allocate()
        assert AALst.lst_alloc(DeptT.chemical) == ["s3"]
