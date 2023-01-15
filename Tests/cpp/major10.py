import sys    # Problem no: 3 and 4 in one


class Student:
    marks = []
    average_marks = 0
    max_mark = 300
    grade = ""
    total_marks = 0

    def __init__(self, name, roll, python_mark, TOC_mark, OS_mark):
        Student.name = name    # can be written using class name i.e Student.name = name
        Student.roll = roll
        Student.marks.append(python_mark)
        Student.marks.append(TOC_mark)
        Student.marks.append(OS_mark)

    def displayData(self):
        print("Roll Number : ", Student.roll)
        print("Name : ", Student.name)
        # print ("Marks in subject 1: ", Student.marks[0])
        # print ("Marks in subject 2: ", Student.marks[1])
        # print ("Marks in subject 3: ", Student.marks[2])
        print("Marks of respective subjects : ",
              Student.marks)   # accessing list at once

    def total(self):
        # total...
        Student.total_marks = Student.marks[0] + \
            Student.marks[1] + Student.marks[2]
        print("total_marks:", Student.total_marks)
        return Student.total_marks

    def moderate_marks(self, grace_mark):
        # self.grace_mark = grace_mark
        Student.marks[0] = Student.marks[0] + grace_mark
        Student.marks[1] = Student.marks[1] + grace_mark
        Student.marks[2] = Student.marks[2] + grace_mark
        if Student.marks[0] > 100 or Student.marks[1] > 100 or Student.marks[2] > 100:
            print("Yours one of the subject's mark is exceeding 100...")
            sys.exit()

        print("The Modified marks are: ", Student.marks)

    def average(self):
        # updated avg marks...
        average_marks = (
            (Student.marks[0] + Student.marks[1] + Student.marks[2]) / 3)
        return average_marks

    def get_grade(self):
        # calculating marks in % ...
        marks_percent = round((Student.total_marks / Student.max_mark) * 100)
        print("testing: ", marks_percent)
        print("Student.total_marks:", Student.total_marks)
        print("Student.max_mark:", Student.max_mark)

        if marks_percent >= 80:
            grade = "A"
        elif marks_percent >= 60 and marks_percent < 80:
            grade = "B"
        elif marks_percent >= 40 and marks_percent < 60:
            grade = "C"
        else:
            grade = "D(Fail)"

        return grade


choice = 1
while(choice == 1):
    choice = 0
    print("\n\n")
    roll = int(input("Enter the roll number: "))
    name = input("Enter the name: ")
    m1 = int(input("Enter the marks in the first subject: "))
    m2 = int(input("Enter the marks in the second subject: "))
    m3 = int(input("Enter the marks in the third subject: "))

    # s1 = Student("Sidhartha Mohanty", 13155, 90, 88, 75)
    s1 = Student(name, roll, m1, m2, m3)
    print(
        f"\n ******* Displaying the {Student.name}'s data *******\n")
    s1.displayData()    # print...

    m_mark = int(input("Enter the Grace mark obtained between 1 - 10: "))
    s1.moderate_marks(m_mark)
    # call average()
    print("Total marks obtained out of 300:", s1.total())
    print("Average mark:", s1.average())

    # call get_grade()
    print("The Grade obtained :", s1.get_grade())

    # Print Student
    print(f'Student Class: {s1.total_marks}')

    choice = int(input('Add another Student?? press 1 or 0'))
