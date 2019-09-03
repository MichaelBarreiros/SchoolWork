## @file ReadAllocationData.py
#  @author Michael Barreiros 
#  @title ReadAllocationData 
#  @date 01/17/19 

## @brief This function takes an input file of students and outputs a list of dictionaries of students
#  @details This function takes an input file such as students.txt and reads the data from it. It will 
#  strip any special characters from it and create the list in the proper format. An assumption was
#  made that every student is on a new line and that the information is given in only one order "macid 
#  fname lname gender gpa choice1 choice2 choice3"
#  @param s string of a file name to be opened and read
#  @return Students [{student},{student},...,{student}] list of dictionaries. Each dictionary is the information for one student
def readStdnts(s):
	f = open(s, "r")
  
	StudentData = f.read()
	StudentData = StudentData.replace("{", "")
	StudentData = StudentData.replace("}", "")
	StudentData = StudentData.replace("\"", "")
	StudentData = StudentData.replace("[", "")
	StudentData = StudentData.replace("]", "")
	StudentData = StudentData.replace(",", "")
	Students = StudentData.splitlines()
	
	## This for loop creates a new dictionary and populates it for the current student and places it in the list 
	for i in range(0,len(Students)):
		Students[i] = Students[i].lower() 
		Students[i] = Students[i].split()

		choices = [Students[i][5] , Students[i][6], Students[i][7]]
    
		StdntDict = {'macid': Students[i][0], 'fname': Students[i][1], 'lname': Students[i][2], 'gender': Students[i][3], 'gpa': Students[i][4], 'choices': choices }

		StdntDict['gpa'] = float(StdntDict['gpa'])
  
		Students[i] = StdntDict

	f.close()
	return Students

## @brief This function reads from an input file and outputs a list of macId's
#  @details This function reads from an input file. An assumption is made that in this file only the macId of students
#  who received free choice appear, it does not matter if they are on newlines, or if some special characters appear.
#  After reading and stripping unneeded characters the data is formatted into a list who's entries are macId's
#  @param s string of a file name to be opened and read
#  @return names a list who's entries are macId's of student's who got free choice
def readFreeChoice(s):
	f = open(s, "r")
  
	names = f.read()
	names = names.strip()
	names = names.replace(",", "")
	names = names.replace(" ", "\n")
	names = names.lower()
	names = names.splitlines()
	
	## emptyElements was added to control the input and get rid of any empty elements that might have occured
	emptyElements = []
	for i in range(0, len(names)):
		if names[i] == '':
			emptyElements.append(i)
  
	for j in range(0, len(emptyElements)):
		del names[emptyElements[j]-j]

	f.close()
	return names

## @brief This function reads from an input file and outputs a dictionary with departments as keys and their capacity as values
#  @details This function reads from an input file. An assumption is made that in the input file the department name comes first
#  then the department's capacity comes next with at least one space between. Some expected special characters get stripped.
#  The function then matches the department name and updates the capacity value in an existing dictionary.
#  @param s string of a file name to be opened and read
#  @return Capacity {'department': capacity} A dictionary of departments as keys and their capacity as values
def readDeptCapacity(s):
	f = open(s, "r")

	capacities = f.read()
	capacities = capacities.strip()
	capacities = capacities.replace(":", "")
	capacities = capacities.replace("\t", "")
	capacities = capacities.replace(",", "")
	capacities = capacities.replace(" ", "\n")
	capacities = capacities.lower()
	capacities = capacities.splitlines()
	
	## emptyElements was added to control the input and get rid of any empty elements that might have occured
	emptyElements = []
	for i in range(0, len(capacities)):
		if capacities[i] == '':
			emptyElements.append(i)
  
	for j in range(0, len(emptyElements)):
		del capacities[emptyElements[j]-j]
  
	Capacity = {'civil': 0, 'chemical': 0, 'electrical': 0, 'mechanical': 0, 'software': 0, 'materials': 0, 'engphys': 0}

	for i in range(0, len(capacities), 2):
		if capacities[i] == 'civil':
			Capacity['civil'] = int(capacities[i+1])
		if capacities[i] == 'chemical':
			Capacity['chemical'] = int(capacities[i+1])
		if capacities[i] == 'electrical':
			Capacity['electrical'] = int(capacities[i+1])
		if capacities[i] == 'mechanical':
			Capacity['mechanical'] = int(capacities[i+1])
		if capacities[i] == 'software':
			Capacity['software'] = int(capacities[i+1])
		if capacities[i] == 'materials':
			Capacity['materials'] = int(capacities[i+1])
		if capacities[i] == 'engphys':
			Capacity['engphys'] = int(capacities[i+1])

	return Capacity