## @file StdntAllocTypes.py
#  @author Michael Barreiros
#  @brief StdntAllocTypes
#  @date 09/02/2019

from enum import Enum
from typing import NamedTuple
from SeqADT import SeqADT

## @brief GenT abstract data type for genders
#  @details can be male or female


class GenT(Enum):
    male = 1
    female = 2

## @brief DeptT abstract data type for departments
#  @details there are 7 unique departments


class DeptT(Enum):
    civil = 1
    chemical = 2
    electrical = 3
    mechanical = 4
    software = 5
    materials = 6
    engphys = 7

## @brief SInfoT abstract data type for Students
#  @details includes first name, last name, gender, gpa, 3 choices, and
#  whether or not they have free choice


class SInfoT(NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float
    choices: type(SeqADT(DeptT))
    freechoice: bool
