## @file Read.py
#  @author Michael Barreiros
#  @brief Read
#  @date 11/02/2019

from StdntAllocTypes import GenT, DeptT, SInfoT
from DCapALst import DCapALst
from SALst import SALst
from SeqADT import SeqADT

## @brief the read module


class Read:
    ## @brief the load stdnt data function
    #  @details reads from a file and saves the data in a SALst data type.
    #  This will go through each line and take it as though it were a student.
    #  Then it assigns each entry to its correct position and adds the student
    #  to the list of type SALst
    @staticmethod
    def load_stdnt_data(s):
        SALst.init()
        stdnt_data = open(s, "r")
        stdnt_data = stdnt_data.read()
        stdnt_data = stdnt_data.replace(",", "")
        stdnt_data = stdnt_data.replace("[", "")
        stdnt_data = stdnt_data.replace("]", "")
        stdnt_data = stdnt_data.splitlines()

        for student in stdnt_data:
            stdnt_info = student.split()
            macid = stdnt_info[0]
            f_name = stdnt_info[2]
            l_name = stdnt_info[3]
            if (stdnt_info[3] == "male"):
                gender = GenT.male
            else:
                gender = GenT.female
            gpa = float(stdnt_info[4])
            choices = []
            for i in range(5, len(stdnt_info) - 1):
                if stdnt_info[i] == "civil":
                    choices.append(DeptT.civil)
                if stdnt_info[i] == "chemical":
                    choices.append(DeptT.chemical)
                if stdnt_info[i] == "electrical":
                    choices.append(DeptT.electrical)
                if stdnt_info[i] == "mechanical":
                    choices.append(DeptT.mechanical)
                if stdnt_info[i] == "software":
                    choices.append(DeptT.software)
                if stdnt_info[i] == "materials":
                    choices.append(DeptT.materials)
                if stdnt_info[i] == "engphys":
                    choices.append(DeptT.engphys)
            if (stdnt_info[-1] == "True"):
                free_choice = True
            else:
                free_choice = False

            info = SInfoT(f_name, l_name, gender, gpa,
                          SeqADT(choices), free_choice)
            SALst.add(macid, info)

    ## @brief the load dcap data function
    #  @details this function reads from a file that is known to be the file
    #  for the department capacities. This function puts the appropriate
    #  capacity with its department and stores it as a DCapALst data type
    @staticmethod
    def load_dcap_data(s):
        DCapALst.init()
        dept_data = open(s, "r")
        dept_data = dept_data.read()
        dept_data = dept_data.replace(",", "")
        dept_data = dept_data.splitline()

        for dept_and_cap in dept_data:
            dept_info = dept_and_cap.split()
            if dept_info[0] == "civil":
                dept = DeptT.civil
            if dept_info[0] == "chemical":
                dept = DeptT.chemical
            if dept_info[0] == "electrical":
                dept = DeptT.electrical
            if dept_info[0] == "mechanical":
                dept = DeptT.mechanical
            if dept_info[0] == "software":
                dept = DeptT.software
            if dept_info[0] == "materials":
                dept = DeptT.materials
            if dept_info[0] == "engphys":
                dept = DeptT.engphys

            cap = int(dept_info[1])
            DCapALst.add(dept, cap)
