# Report-Card-Generator-in-C
A C-based Report Card Management System to create, view, and export student reports. Calculates totals, percentages, and grades automatically with discipline remarks. Supports multiple subjects and PDF export via Chrome headless mode for professional report generation.


# Report Card Management System in C

## Overview

The Report Card Management System is a console-based application developed in the C programming language. It provides an efficient and organized way to manage student academic performance data. The system allows users to create, store, view, and export report cards while automating calculations related to marks, percentages, grades, and discipline remarks. Designed for simplicity and reliability, this program demonstrates effective use of C structures, arrays, string manipulation, and file operations.

This project is particularly suitable for educational institutions, teachers, or administrators seeking to simplify manual record-keeping. It also serves as an excellent academic project for students learning data management and structured programming concepts in C.

## Features

1. **Student Report Creation**
   Users can enter student details such as name, roll number, and exam date. The system supports multiple subjects per student, with marks recorded individually for each subject. All data entries are validated to ensure proper input ranges and consistency.

2. **Automatic Grade Calculation**
   Based on the total marks obtained and the number of subjects, the system automatically calculates the overall percentage and assigns a grade according to defined criteria. Grades range from A+ to F, providing a clear representation of student performance.

3. **Discipline Evaluation**
   The program allows the entry of a discipline grade, which is converted into a predefined remark. This helps provide a holistic overview of the student's academic and behavioral performance.

4. **Multiple Report Storage**
   The program supports storage of multiple report cards within the same execution session. Each report is assigned a unique ID to facilitate easy retrieval and viewing.

5. **Data Display and Summary Listing**
   Users can view the details of a specific report by entering its ID or list all reports in summary form, displaying names, roll numbers, and percentages for quick review.

6. **PDF Export Functionality**
   One of the unique features of this program is the ability to export a student report card to a PDF file. This is achieved by generating an HTML file and then converting it to PDF using Google Chrome's headless mode. The feature allows teachers to generate professional, printable report cards instantly.

7. **Cross-Platform Compatibility**
   The code is compatible with macOS, Linux, and Windows systems that have the GCC compiler installed and access to a headless Chrome executable.

## Technical Details

* **Programming Language:** C
* **Libraries Used:** `stdio.h`, `string.h`, `ctype.h`
* **Core Concepts:** Structures, Arrays, Loops, Conditionals, File Handling
* **PDF Export Tool:** Google Chrome Headless Mode or Chromium

### Grade Evaluation Criteria

* 90% and above: A+
* 80% to 89%: A
* 70% to 79%: B
* 60% to 69%: C
* 50% to 59%: D
* Below 50%: F

### Discipline Remarks

* A: Excellent discipline
* B: Very good discipline
* C: Average discipline - room for improvement
* D: Needs improvement
* E: Poor discipline - immediate attention required

## Installation and Compilation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/report-card-management-system.git
   cd report-card-management-system
   ```

2. **Compile the Program**
   Use GCC or any standard C compiler:

   ```bash
   gcc project1.c -o report_manager
   ```

3. **Run the Application**

   ```bash
   ./report_manager
   ```

4. **Use Chrome for PDF Export**
   Ensure that Google Chrome or Chromium is installed. The program automatically detects the path. If not, you can manually edit the Chrome path in the code.

## Usage Guide

Once executed, the program displays a main menu with the following options:

1. Create new report card
2. List all report cards (summary)
3. View a report card by ID
4. Export a report card to PDF
5. Exit

Follow the on-screen instructions to enter details, view records, or export a report. Each function includes input validation and clear output formatting for ease of use.

## Example Workflow

1. Launch the application and choose option 1 to create a new report card.
2. Enter student details such as name, roll number, and exam date.
3. Specify the number of subjects and their corresponding marks.
4. Assign a discipline grade (A to E).
5. The system automatically calculates totals, percentages, and grades.
6. View or export the report as needed.

## Advantages

* Provides a structured and reliable way to manage academic records.
* Reduces manual effort by automating grade and remark calculations.
* Offers an exportable format for official documentation.
* Simple, lightweight, and highly portable across systems.

## Limitations

* Data is not persistent across sessions; reports are stored only in runtime memory.
* Requires Chrome or Chromium for PDF export functionality.
* Lacks graphical interface (CLI-based only).

## Future Enhancements

* Integration with a database for persistent storage.
* Development of a graphical user interface (GUI) using frameworks like GTK or Qt.
* Addition of import/export features for CSV or JSON formats.
* Implementation of encryption for secure report handling.

## Conclusion

The Report Card Management System in C offers a practical and educationally useful application that demonstrates strong foundational programming skills. It efficiently manages academic records, automates computations, and provides professional-grade PDF outputs. With further development, it can evolve into a complete student performance management platform.

