## @file CalcModule.py
#  @author Michael Barreiros
#  @title CalcModule
#  @date 01/17/19 

## @brief This function sorts a list of dictionaries by the key gpa in decending order
#  @param S A list of students. Each student is a dictionary. 
#  @return newList The same list that was inputted but now sorted in decending order by gpa
def sort(S):
	## newList was sorted using a line of code that was found on stackoverflow
	## link is https://stackoverflow.com/questions/72899/how-do-i-sort-a-list-of-dictionaries-by-a-value-of-the-dictionary
	newList = sorted(S, key = lambda k: k['gpa'], reverse = True)
	return newList

## @brief This function returns the average gpa of a gender in the inputted list. Returns 0 if no population for that gender.
#  @param L A list of students. Each student is a dictionary.
#  @param g A string which would either be "male" or "female"
#  @return average The average gpa for the selected gender
def average(L, g):
	average = 0.0
	sumOfGpa = 0.0
	numOfStudents = 0.0

	for student in L:
		if student['gender'] == g.lower():
			sumOfGpa += student['gpa']
			numOfStudents += 1
	
	if numOfStudents == 0:
		return 0
	else:
		average = sumOfGpa/numOfStudents
		return average

## @brief This is a function allocates students to the appropriate department
#  @details The function sorts the incoming student list by gpa. Then creates new lists for each of the departments.
#  These lists are populated with new students, first from students with free choice then with students from
#  the original list of students. The function returns a dictionary with departments as keys and a list of students, 
#  each student is represented by their own dictionary.
#  An assumption is made that students with free choice who's choice has reached its capacity would attempt to get
#  allocated to their next choice.
#  @param S A list of students. Each student is a dictionary.
#  @param F A list of student's macID's. Each element of the list is a string
#  @param C A Dictionary with departments as key values and thier capacities as values
#  @return allocatedDictionary {'department': [student, student,...], ...} A dictionary with departments as keys and a list of students as values
def allocate(S, F, C):
	#Allocation algorithm assumes that students with free choice are still allocated based on gpa
	S = sort(S)

	civilList = []
	chemList = []
	elecList = []
	mechList = []
	softList = []
	matList = []
	engphysList = []
	
	# this will be a list of only free choice students so they can be allocated first
	freeChoiceStudents = []
	
	for student in S:
		if student['macid'] in F: #student has free choice
			freeChoiceStudents.append(student)

	for student in freeChoiceStudents:
		if student['gpa'] > 4.0: #only allocate student if gpa is greater than 4.0
			for i in range(0,3): #runs through each of their choices only if their previous choice was full
				# each of these if statements try to match student choice to one of the departments
				# then it checks to see if the department is full. If full move on to next choice
				if student['choices'][i] == 'civil':
					if len(civilList) < C['civil']:
						civilList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'chemical':
					if len(chemList) < C['chemical']:
						chemList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'electrical':
					if len(elecList) < C['electrical']:
						elecList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'mechanical':
					if len(mechList) < C['mechanical']:
						mechList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'software':
					if len(softList) < C['software']:
						softList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'materials':
					if len(matList) < C['materials']:
						matList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'engphys':
					if len(engphysList) < C['engphys']:
						engphysList.append(student)
						break
					else:
						continue
		else:
			continue
  
      
	for student in S:
		if student['gpa'] > 4.0: # only allocates student if gpa is greater than 4/0
			if student['macid'] in F: # this is here to check for already allocated members of this list
				continue

			for i in range(0,3):
				if student['choices'][i] == 'civil':
					if len(civilList) < C['civil']:
						civilList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'chemical':
					if len(chemList) < C['chemical']:
						chemList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'electrical':
					if len(elecList) < C['electrical']:
						elecList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'mechanical':
					if len(mechList) < C['mechanical']:
						mechList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'software':
					if len(softList) < C['software']:
						softList.append(student)
						break
					else:
						continue
				if student['choices'][i] == 'materials':
					if len(matList) < C['materials']:
						matList.append(student)
						break
					else:
						continue
			if student['choices'][i] == 'engphys':
					if len(engphysList) < C['engphys']:
						engphysList.append(student)
						break
					else:
						continue
		else:
			continue
  
	allocatedDictionary = {'civil': civilList, 'chemical': chemList, 'electrical': elecList, 'mechanical': mechList, 'software': softList, 'materials': matList, 'engphys': engphysList}

	return allocatedDictionary