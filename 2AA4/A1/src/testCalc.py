## @file testCalc.py
#  @author Michael Barreiros
#  @brief  
#  @date 01/16/2019

from ReadAllocationData import *
from CalcModule import *

def compare(test, result, name):
	if test == result:
		print("Testing: ", name)
		print("Test passed: %s == %s" %(test, result))
	else:
		print("Testing: ", name)
		print("Test failed: %s != %s" %(test, result))
  
	print()

def testAverageMales():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 6.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]
	test = average(students, 'male') 

	compare(test, 7.5, "Male average")

def testAverageFemales():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 6.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]
	test = average(students, 'female')
  
	compare(test, 8.35, "Female average")

def testAverageNoMales():
	students = [{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]
	test = average(students, 'male')

	compare(test, 0, "Male average of a student list with no males")

def testAverageNoFemales():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 6.0, 'choices': ['materials', 'engphys', 'civil']}]
	test = average(students, 'female')

	compare(test, 0, "Female average of a student list with no females")

def testSortNormal():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 6.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]

	sortedStudents = [{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']},
	{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 6.0, 'choices': ['materials', 'engphys', 'civil']},
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]

	test = sort(students)

	compare(test, sortedStudents, "Sorting list of students with unique GPAs")

def testSortSame():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 4.7, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]

	sortedStudents = [{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 12.0, 'choices': ['chemical', 'mechanical', 'civil']},
	{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 9.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 4.7, 'choices': ['materials', 'engphys', 'civil']},
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 4.7, 'choices': ['electrical', 'software', 'engphys']}]

	test = sort(students)

	compare(test, sortedStudents, "Sorting list of students some with same GPAs")

def testSortEmpty():
	students = []

	sortedStudents = []

	test = sort(students)

	compare(test, sortedStudents, "Sorting an empty list of students")

def testSortSorted():
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 11.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 9.0, 'choices': ['electrical', 'software', 'engphys']}]

	sortedStudents = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'teststdnt1', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 11.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': 'teststdnt2', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 10.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'teststdnt3', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 9.0, 'choices': ['electrical', 'software', 'engphys']}]

	test = sort(students)

	compare(test, sortedStudents, "Sorting an already sorted list")

def testAllocateNormal(): 
	# in this function we have several scenarios being tested.
	# what happens when someone with free choice has a lower gpa than someone with free choice. free choice gets allocated first
	# we also have a student with a 4.0 gpa. We expect them not to get allocated
	# we have a department with not enough space to allocate everyone so some students have to be allocated to their next choices
	# we have a student with a gpa lower than a 4.0 and has free choice. We expect them not to get allocated
	students = [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'mechanical', 'electrical']},
	{'macid': 'freeChoiceLowGpa', 'fname': 'joe', 'lname': 'shmoe', 'gender': 'male', 'gpa': 2.0, 'choices': ['materials', 'engphys', 'civil']}, 
	{'macid': '4.0', 'fname': 'kate', 'lname': 'makabali', 'gender': 'female', 'gpa': 4.0, 'choices': ['chemical', 'mechanical', 'civil']}, 
	{'macid': 'freeChoice', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 9.0, 'choices': ['software', 'electrical', 'engphys']}]
  
	freeChoice = ["freeChoice", "freeChoiceLowGpa"]

	deptCap = {'civil': 1, 'chemical': 1, 'electrical': 1, 'mechanical': 1, 'software': 1, 'materials': 1, 'engphys': 1}

	test = allocate(students, freeChoice, deptCap)

	allocatedStudents = {'civil': [], 'chemical': [], 'electrical': [],
	'mechanical': [{'macid': 'barreirm', 'fname': 'michael', 'lname': 'barreiros', 'gender': 'male', 'gpa': 12.0, 'choices': ['software', 'mechanical', 'electrical']}],
	'software': [{'macid': 'freeChoice', 'fname': 'bella', 'lname': 'alleb', 'gender': 'female', 'gpa': 9.0, 'choices': ['software', 'electrical', 'engphys']}], 
	'materials': [], 'engphys': []}

	compare(test, allocatedStudents, 
	"Allocation of student list containing \n" +
	"1) Free Choice Student taking the spot of non-free-choice\n" +
	"2) Student below a 4.0 with free choice not getting allocated\n" +
	"3) A student with exactly a 4.0 not getting allocated")
	
def testAllocationEmpty():
	students = []
	freeChoice = []
	deptCap = {'civil': 1, 'chemical': 1, 'electrical': 1, 'mechanical': 1, 'software': 1, 'materials': 1, 'engphys': 1}
	
	allocatedStudents = {'civil': [], 'chemical': [], 'electrical': [],
	'mechanical': [], 'software': [], 'materials': [], 'engphys': []}
	
	test = allocate(students,freeChoice, deptCap)
	
	compare(test, allocatedStudents, "Allocation of an empty student list")
	

def test():
	testAverageMales()
	testAverageFemales()
	testAverageNoMales()
	testAverageNoFemales()
	testSortNormal()
	testSortSame()
	testSortEmpty()
	testSortSorted()
	testAllocateNormal()
	testAllocationEmpty()

test()