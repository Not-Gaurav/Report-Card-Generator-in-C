# Report Card Management System in C

## Overview

The Report Card Management System is a console-based application developed in the C programming language. It provides an efficient and organized way to manage student academic performance data. The system allows users to create, store, view, and export report cards while automating calculations related to marks, percentages, grades, and discipline remarks. Designed for simplicity and reliability, this program demonstrates effective use of C structures, arrays, string manipulation, and file operations.

## Sample Report Cards

Below are complete sample inputs and outputs for demonstration. Each report illustrates how the program handles both passing and failing cases.

### Report Card 1 - Riya Sharma

**Input Data**
Roll Number: CS101
Exam Date: 2025-03-20
Number of Subjects: 5

| No | Subject          | Marks |
| -- | ---------------- | ----- |
| 1  | Mathematics      | 95    |
| 2  | Physics          | 88    |
| 3  | Chemistry        | 92    |
| 4  | English          | 85    |
| 5  | Computer Science | 98    |

**Discipline Grade:** A

**Generated Output:**

```text
=========================================
Report ID   : 1
Name        : Riya Sharma
Roll        : CS101
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Mathematics                    95     Pass
2   Physics                        88     Pass
3   Chemistry                      92     Pass
4   English                        85     Pass
5   Computer Science               98     Pass
-----------------------------------------
Total Marks : 458
Percentage  : 91.60%
Overall Gpa : A+
Discipline  : A  -> Excellent discipline
=========================================
```

### Report Card 2 - Aarav Mehta

**Input Data**
Roll Number: EE207
Exam Date: 2025-03-20
Number of Subjects: 4

| No | Subject             | Marks |
| -- | ------------------- | ----- |
| 1  | Electrical Circuits | 75    |
| 2  | Signals and Systems | 64    |
| 3  | Control Engineering | 70    |
| 4  | Applied Mathematics | 68    |

**Discipline Grade:** B

**Generated Output:**

```text
=========================================
Report ID   : 2
Name        : Aarav Mehta
Roll        : EE207
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Electrical Circuits            75     Pass
2   Signals and Systems            64     Pass
3   Control Engineering            70     Pass
4   Applied Mathematics            68     Pass
-----------------------------------------
Total Marks : 277
Percentage  : 69.25%
Overall Gpa : C
Discipline  : B  -> Very good discipline
=========================================
```

### Report Card 3 - Sneha Patel

**Input Data**
Roll Number: ME305
Exam Date: 2025-03-20
Number of Subjects: 5

| No | Subject                 | Marks |
| -- | ----------------------- | ----- |
| 1  | Mechanics               | 58    |
| 2  | Thermodynamics          | 61    |
| 3  | Fluid Mechanics         | 55    |
| 4  | Manufacturing Processes | 49    |
| 5  | Machine Design          | 63    |

**Discipline Grade:** C

**Generated Output:**

```text
=========================================
Report ID   : 3
Name        : Sneha Patel
Roll        : ME305
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Mechanics                      58     Pass
2   Thermodynamics                 61     Pass
3   Fluid Mechanics                55     Pass
4   Manufacturing Processes        49     Pass
5   Machine Design                 63     Pass
-----------------------------------------
Total Marks : 286
Percentage  : 57.20%
Overall Gpa : D
Discipline  : C  -> Average discipline - room to improve
=========================================
```

### Report Card 4 - Karan Verma

**Input Data**
Roll Number: IT409
Exam Date: 2025-03-20
Number of Subjects: 5

| No | Subject           | Marks |
| -- | ----------------- | ----- |
| 1  | Data Structures   | 82    |
| 2  | Algorithms        | 78    |
| 3  | Database Systems  | 80    |
| 4  | Operating Systems | 85    |
| 5  | Computer Networks | 75    |

**Discipline Grade:** A

**Generated Output:**

```text
=========================================
Report ID   : 4
Name        : Karan Verma
Roll        : IT409
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Data Structures                82     Pass
2   Algorithms                     78     Pass
3   Database Systems               80     Pass
4   Operating Systems              85     Pass
5   Computer Networks              75     Pass
-----------------------------------------
Total Marks : 400
Percentage  : 80.00%
Overall Gpa : A
Discipline  : A  -> Excellent discipline
=========================================
```

### Report Card 5 - Anjali Nair

**Input Data**
Roll Number: CE501
Exam Date: 2025-03-20
Number of Subjects: 4

| No | Subject              | Marks |
| -- | -------------------- | ----- |
| 1  | Structural Analysis  | 48    |
| 2  | Concrete Technology  | 52    |
| 3  | Environmental Engg.  | 47    |
| 4  | Transportation Engg. | 60    |

**Discipline Grade:** D

**Generated Output:**

```text
=========================================
Report ID   : 5
Name        : Anjali Nair
Roll        : CE501
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Structural Analysis            48     Pass
2   Concrete Technology            52     Pass
3   Environmental Engg.            47     Pass
4   Transportation Engg.           60     Pass
-----------------------------------------
Total Marks : 207
Percentage  : 51.75%
Overall Gpa : D
Discipline  : D  -> Needs improvement in discipline
=========================================
```

### Report Card 6 - Rohit Kumar (Fail Case)

**Input Data**
Roll Number: EC603
Exam Date: 2025-03-20
Number of Subjects: 5

| No | Subject               | Marks |
| -- | --------------------- | ----- |
| 1  | Analog Electronics    | 32    |
| 2  | Digital Logic Design  | 45    |
| 3  | Signals and Systems   | 38    |
| 4  | Microprocessors       | 29    |
| 5  | Communication Systems | 41    |

**Discipline Grade:** E

**Generated Output:**

```text
=========================================
Report ID   : 6
Name        : Rohit Kumar
Roll        : EC603
Exam Date   : 2025-03-20
-----------------------------------------
No  Subject                        Marks  Result
1   Analog Electronics             32     Fail
2   Digital Logic Design           45     Pass
3   Signals and Systems            38     Fail
4   Microprocessors                29     Fail
5   Communication Systems          41     Pass
-----------------------------------------
Total Marks : 185
Percentage  : 37.00%
Overall Gpa : F
Discipline  : E  -> Poor discipline - immediate attention required
=========================================
```

### Summary Table of All Sample Students

| Report ID | Name        | Roll No | Percentage | Grade | Discipline | Remark Summary                                 |
| --------- | ----------- | ------- | ---------- | ----- | ---------- | ---------------------------------------------- |
| 1         | Riya Sharma | CS101   | 91.60%     | A+    | A          | Excellent discipline                           |
| 2         | Aarav Mehta | EE207   | 69.25%     | C     | B          | Very good discipline                           |
| 3         | Sneha Patel | ME305   | 57.20%     | D     | C          | Average discipline - room to improve           |
| 4         | Karan Verma | IT409   | 80.00%     | A     | A          | Excellent discipline                           |
| 5         | Anjali Nair | CE501   | 51.75%     | D     | D          | Needs improvement in discipline                |
| 6         | Rohit Kumar | EC603   | 37.00%     | F     | E          | Poor discipline - immediate attention required |
