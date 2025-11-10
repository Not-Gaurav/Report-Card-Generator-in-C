#include <stdio.h>
#include <string.h>


#define MAX_REPORTS 200
#define MAX_SUBJECTS 20

typedef struct {
    char name[50];
    int marks;
} Subject;

typedef struct {
    int id;
    char student_name[100];
    char roll[30];
    char exam_date[20];
    int subject_count;
    Subject subjects[MAX_SUBJECTS];
    char discipline_grade;
    char discipline_remark[120];
    int total;
    float percentage;
    char overall_grade[4];
} ReportCard;

ReportCard reports[MAX_REPORTS];
int report_count = 0;

void strip_newline(char *s) {
    size_t l = strlen(s);
    if (l > 0 && s[l-1] == '\n') s[l-1] = '\0';
}

void discipline_remark_for(char grade, char *out) {
    grade = toupper((unsigned char)grade);
    if (grade == 'A') strcpy(out, "Excellent discipline");
    else if (grade == 'B') strcpy(out, "Very good discipline");
    else if (grade == 'C') strcpy(out, "Average discipline - room to improve");
    else if (grade == 'D') strcpy(out, "Needs improvement in discipline");
    else if (grade == 'E') strcpy(out, "Poor discipline - immediate attention required");
    else strcpy(out, "No discipline grade provided");
}

void overall_grade_for(float pct, char *out) {
    if (pct >= 90) strcpy(out, "A+");
    else if (pct >= 80) strcpy(out, "A");
    else if (pct >= 70) strcpy(out, "B");
    else if (pct >= 60) strcpy(out, "C");
    else if (pct >= 50) strcpy(out, "D");
    else strcpy(out, "F");
}

void print_report(const ReportCard *r) {
    printf("\n=========================================\n");
    printf("Report ID   : %d\n", r->id);
    printf("Name        : %s\n", r->student_name);
    printf("Roll        : %s\n", r->roll);
    printf("Exam Date   : %s\n", r->exam_date);
    printf("-----------------------------------------\n");
    printf("%-3s %-30s %-6s %-8s\n", "No", "Subject", "Marks", "Result");
    for (int i = 0; i < r->subject_count; ++i) {
        const Subject *s = &r->subjects[i];
        printf("%-3d %-30s %-6d %-8s\n", i+1, s->name, s->marks, (s->marks >= 40) ? "Pass" : "Fail");
    }
    printf("-----------------------------------------\n");
    printf("Total Marks : %d\n", r->total);
    printf("Percentage  : %.2f%%\n", r->percentage);
    printf("Overall Gpa : %s\n", r->overall_grade);
    printf("Discipline  : %c  -> %s\n", r->discipline_grade, r->discipline_remark);
    printf("=========================================\n\n");
}

void create_report() {
    if (report_count >= MAX_REPORTS) {
        printf("Cannot create more reports.\n");
        return;
    }
    ReportCard r;
    r.id = (report_count == 0) ? 1 : reports[report_count-1].id + 1;
    r.total = 0;
    r.percentage = 0.0f;
    r.subject_count = 0;
    r.discipline_grade = ' ';
    r.discipline_remark[0] = '\0';
    r.overall_grade[0] = '\0';

    printf("Enter student name: ");
    getchar();
    fgets(r.student_name, sizeof(r.student_name), stdin);
    strip_newline(r.student_name);

    printf("Enter roll number: ");
    fgets(r.roll, sizeof(r.roll), stdin);
    strip_newline(r.roll);

    printf("Enter exam date (YYYY-MM-DD): ");
    fgets(r.exam_date, sizeof(r.exam_date), stdin);
    strip_newline(r.exam_date);

    int sc = 0;
    printf("Enter number of subjects (1-%d): ", MAX_SUBJECTS);
    if (scanf("%d", &sc) != 1 || sc < 1 || sc > MAX_SUBJECTS) {
        printf("Invalid subject count.\n");
        return;
    }
    r.subject_count = sc;
    for (int i = 0; i < sc; ++i) {
        getchar();
        printf("Enter name of subject %d: ", i+1);
        fgets(r.subjects[i].name, sizeof(r.subjects[i].name), stdin);
        strip_newline(r.subjects[i].name);
        printf("Enter marks for %s (0-100): ", r.subjects[i].name);
        if (scanf("%d", &r.subjects[i].marks) != 1) {
            printf("Invalid marks input.\n");
            return;
        }
        if (r.subjects[i].marks < 0) r.subjects[i].marks = 0;
        if (r.subjects[i].marks > 100) r.subjects[i].marks = 100;
        r.total += r.subjects[i].marks;
    }

    getchar();
    printf("Enter discipline grade (A/B/C/D/E): ");
    char dg = getchar();
    if (dg == '\n') dg = getchar();
    r.discipline_grade = toupper((unsigned char)dg);
    discipline_remark_for(r.discipline_grade, r.discipline_remark);

    int max_total = sc * 100;
    r.percentage = (max_total > 0) ? ((float)r.total * 100.0f / max_total) : 0.0f;
    overall_grade_for(r.percentage, r.overall_grade);

    reports[report_count++] = r;
    printf("Report card created with ID %d\n", r.id);
}

void list_reports_summary() {
    if (report_count == 0) {
        printf("No report cards available.\n");
        return;
    }
    printf("\nID  Name                              Roll           %s\n", "Percent");
    for (int i = 0; i < report_count; ++i) {
        printf("%-3d %-34s %-14s %.2f%%\n",
               reports[i].id,
               reports[i].student_name,
               reports[i].roll,
               reports[i].percentage);
    }
    printf("\n");
}

void view_report_by_id() {
    if (report_count == 0) {
        printf("No report cards available.\n");
        return;
    }
    int id;
    printf("Enter report ID to view: ");
    if (scanf("%d", &id) != 1) return;
    for (int i = 0; i < report_count; ++i) {
        if (reports[i].id == id) {
            print_report(&reports[i]);
            return;
        }
    }
    printf("Report ID not found.\n");
}

void export_report_to_pdf_with_chrome() {
    if (report_count == 0) {
        printf("No report cards available.\n");
        return;
    }
    int id;
    printf("Enter report ID to export (PDF): ");
    if (scanf("%d", &id) != 1) return;
    for (int i = 0; i < report_count; ++i) {
        if (reports[i].id != id) continue;
        char htmlfile[120], pdffile[120], cmd[1024];
        snprintf(htmlfile, sizeof(htmlfile), "report_%d.html", id);
        snprintf(pdffile, sizeof(pdffile), "report_%d.pdf", id);
        FILE *f = fopen(htmlfile, "w");
        if (!f) {
            printf("Failed to create HTML file.\n");
            return;
        }
        ReportCard *r = &reports[i];
        fprintf(f, "<!doctype html>\n<html><head><meta charset=\"utf-8\"><title>Report %d</title>\n", r->id);
        fprintf(f, "<style>body{font-family:Arial,Helvetica,sans-serif;margin:20px}table{width:100%%;border-collapse:collapse}th,td{border:1px solid #333;padding:6px;text-align:left}h1{margin:0 0 8px}</style>\n</head><body>\n");
        fprintf(f, "<h1>Report Card</h1>\n<p><strong>Report ID:</strong> %d<br><strong>Name:</strong> %s<br><strong>Roll:</strong> %s<br><strong>Exam Date:</strong> %s</p>\n", r->id, r->student_name, r->roll, r->exam_date);
        fprintf(f, "<table><tr><th>No</th><th>Subject</th><th>Marks</th><th>Result</th></tr>\n");
        for (int s = 0; s < r->subject_count; ++s) {
            fprintf(f, "<tr><td>%d</td><td>%s</td><td>%d</td><td>%s</td></tr>\n", s+1, r->subjects[s].name, r->subjects[s].marks, (r->subjects[s].marks >= 40) ? "Pass" : "Fail");
        }
        fprintf(f, "</table>\n<p><strong>Total Marks:</strong> %d<br><strong>Percentage:</strong> %.2f%%<br><strong>Overall Grade:</strong> %s</p>\n", r->total, r->percentage, r->overall_grade);
        fprintf(f, "<p><strong>Discipline:</strong> %c — %s</p>\n", r->discipline_grade, r->discipline_remark);
        fprintf(f, "</body></html>\n");
        fclose(f);

        const char *candidates[] = {
            "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome",
            "/Applications/Chromium.app/Contents/MacOS/Chromium",
            "google-chrome",
            "chromium",
            NULL
        };
        int success = 0;
        for (int ci = 0; candidates[ci] != NULL; ++ci) {
            snprintf(cmd, sizeof(cmd), "\"%s\" --headless --disable-gpu --print-to-pdf=\"%s\" \"%s\"", candidates[ci], pdffile, htmlfile);
            printf("Attempting command:\n%s\n", cmd);
            int rc = system(cmd);
            printf("Command exit code = %d\n", rc);
            if (rc == 0) { success = 1; break; }
        }
        if (success) {
            printf("Exported to %s\n", pdffile);
            remove(htmlfile);
        } else {
            printf("\nPDF export failed.\n");
            printf("HTML file saved as %s. Run the printed command manually in Terminal to see errors.\n", htmlfile);
        }
        return;
    }
    printf("Report ID not found.\n");
}

int main() {
    while (1) {
        printf("\n--- Report Card Management ---\n");
        printf("1. Create new report card\n");
        printf("2. List all report cards (summary)\n");
        printf("3. View a report card by ID\n");
        printf("4. Export a report card to PDF\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        int choice;
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: create_report(); break;
            case 2: list_reports_summary(); break;
            case 3: view_report_by_id(); break;
            case 4: export_report_to_pdf_with_chrome(); break;
            case 5: printf("Exiting.\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}