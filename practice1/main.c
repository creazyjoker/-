#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char id[30];       // 学号
    char name[20];     // 姓名
    char sex[10];      // 性别
    char phone[20];    // 手机号
    float scoreC;      // C语言成绩
    float scoreEng;    // 英语成绩
    float scoreMath;   // 高等数学成绩
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentDB;

// 显示所有学生信息
void displayStudents(StudentDB* db) {
    printf("\n| 学号 | 姓名 | 性别 | 手机号 | C语言 | 英语 | 高数 |\n");
    for (int i = 0; i < db->count; i++) {
        Student* s = &db->students[i];
        printf("%s  %s  %s  %s  %.2f  %.2f  %.2f\n",
            s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
    }
}

// 增加学生信息
void addStudent(StudentDB* db) {
    if (db->count >= MAX_STUDENTS) {
        printf("学生数量已达上限！\n");
        return;
    }
    Student s;
    printf("请输入学号：");
    scanf("%s", s.id);
    printf("请输入姓名：");
    scanf("%s", s.name);
    printf("请输入性别：");
    scanf("%s", s.sex);
    printf("请输入手机号：");
    scanf("%s", s.phone);
    printf("请输入C语言成绩：");
    scanf("%f", &s.scoreC);
    printf("请输入英语成绩：");
    scanf("%f", &s.scoreEng);
    printf("请输入高等数学成绩：");
    scanf("%f", &s.scoreMath);
    db->students[db->count++] = s;
    printf("学生信息添加成功！\n");
}

// 删除学生信息（通过学号匹配）
void deleteStudent(StudentDB* db) {
    char id[30];
    printf("请输入要删除的学生学号：");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            // 将后续记录前移
            for (int j = i; j < db->count - 1; j++) {
                db->students[j] = db->students[j + 1];
            }
            db->count--;
            printf("学生信息删除成功！\n");
            break;
        }
    }
    if (!found) {
        printf("未找到该学号的学生！\n");
    }
}

// 修改学生信息（通过学号匹配，修改除学号外的其他信息）
void modifyStudent(StudentDB* db) {
    char id[30];
    printf("请输入要修改的学生学号：");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            Student* s = &db->students[i];
            printf("当前信息：学号：%s, 姓名：%s, 性别：%s, 手机号：%s, C语言：%.2f, 英语：%.2f, 高数：%.2f\n",
                s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
            printf("请输入新的姓名：");
            scanf("%s", s->name);
            printf("请输入新的性别：");
            scanf("%s", s->sex);
            printf("请输入新的手机号：");
            scanf("%s", s->phone);
            printf("请输入新的C语言成绩：");
            scanf("%f", &s->scoreC);
            printf("请输入新的英语成绩：");
            scanf("%f", &s->scoreEng);
            printf("请输入新的高等数学成绩：");
            scanf("%f", &s->scoreMath);
            printf("学生信息修改成功！\n");
            break;
        }
    }
    if (!found) {
        printf("未找到该学号的学生！\n");
    }
}

// 查询学生信息（通过学号）
void searchStudent(StudentDB* db) {
    char id[30];
    printf("请输入要查询的学生学号：");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            Student* s = &db->students[i];
            printf("查询结果：学号：%s, 姓名：%s, 性别：%s, 手机号：%s, C语言：%.2f, 英语：%.2f, 高数：%.2f\n",
                s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
            break;
        }
    }
    if (!found) {
        printf("未找到该学号的学生！\n");
    }
}

// 按总成绩降序排序学生信息
void sortStudents(StudentDB* db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = i + 1; j < db->count; j++) {
            float total_i = db->students[i].scoreC + db->students[i].scoreEng + db->students[i].scoreMath;
            float total_j = db->students[j].scoreC + db->students[j].scoreEng + db->students[j].scoreMath;
            if (total_i < total_j) {
                Student temp = db->students[i];
                db->students[i] = db->students[j];
                db->students[j] = temp;
            }
        }
    }
    printf("学生信息排序完成（按总成绩降序）！\n");
}

// 计算各门课程平均成绩
void calculateAverage(StudentDB* db) {
    if (db->count == 0) {
        printf("没有学生数据！\n");
        return;
    }
    float sumC = 0, sumEng = 0, sumMath = 0;
    for (int i = 0; i < db->count; i++) {
        sumC += db->students[i].scoreC;
        sumEng += db->students[i].scoreEng;
        sumMath += db->students[i].scoreMath;
    }
    printf("平均成绩：C语言：%.2f, 英语：%.2f, 高等数学：%.2f\n",
        sumC / db->count, sumEng / db->count, sumMath / db->count);
}

// 保存学生信息到文件
void saveStudents(StudentDB* db) {
    FILE* fp = fopen("data.txt", "w");
    if (!fp) {
        printf("无法打开文件保存数据！\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        Student* s = &db->students[i];
        fprintf(fp, "%s %s %s %s %.2f %.2f %.2f\n", s->id, s->name, s->sex, s->phone,
            s->scoreC, s->scoreEng, s->scoreMath);
    }
    fclose(fp);
    printf("数据保存成功！\n");
}

// 从文件加载学生信息
void loadStudents(StudentDB* db) {
    FILE* fp = fopen("data.txt", "r");
    if (!fp) {
        db->count = 0;
        return;
    }
    db->count = 0;
    while (fscanf(fp, "%s %s %s %s %f %f %f",
        db->students[db->count].id,
        db->students[db->count].name,
        db->students[db->count].sex,
        db->students[db->count].phone,
        &db->students[db->count].scoreC,
        &db->students[db->count].scoreEng,
        &db->students[db->count].scoreMath) == 7) {
        db->count++;
        if (db->count >= MAX_STUDENTS) break;
    }
    fclose(fp);
}

// 统计全部课程及格的学生人数（每门课成绩均>=60）
void countPassStudents(StudentDB* db) {
    int countPass = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].scoreC >= 60 &&
            db->students[i].scoreEng >= 60 &&
            db->students[i].scoreMath >= 60) {
            countPass++;
        }
    }
    printf("全部课程及格的学生人数：%d\n", countPass);
}

// 输出总成绩最高的学生信息
void displayMaxTotal(StudentDB* db) {
    if (db->count == 0) {
        printf("没有学生数据！\n");
        return;
    }
    int index = 0;
    float maxTotal = db->students[0].scoreC + db->students[0].scoreEng + db->students[0].scoreMath;
    for (int i = 1; i < db->count; i++) {
        float total = db->students[i].scoreC + db->students[i].scoreEng + db->students[i].scoreMath;
        if (total > maxTotal) {
            maxTotal = total;
            index = i;
        }
    }
    Student* s = &db->students[index];
    printf("总成绩最高的学生信息：\n");
    printf("学号：%s, 姓名：%s, 性别：%s, 手机号：%s, C语言：%.2f, 英语：%.2f, 高数：%.2f, 总成绩：%.2f\n",
        s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath, maxTotal);
}

// 菜单显示函数
void menu() {
    printf("\n*************************学生成绩管理系统*************************\n");
    printf("1. 显示学生信息\n");
    printf("2. 增加学生信息\n");
    printf("3. 删除学生信息\n");
    printf("4. 修改学生信息\n");
    printf("5. 查询学生信息\n");
    printf("6. 排序学生信息（按总成绩降序）\n");
    printf("7. 计算学生平均成绩\n");
    printf("8. 保存学生信息\n");
    printf("9. 统计全部课程及格人数\n");
    printf("10. 输出总成绩最高的学生信息\n");
    printf("0. 退出系统\n");
    printf("请输入操作序号：");
}

int main() {
    StudentDB db;
    db.count = 0;
    // 加载已有数据（如果有）
    loadStudents(&db);

    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            displayStudents(&db);
            break;
        case 2:
            addStudent(&db);
            break;
        case 3:
            deleteStudent(&db);
            break;
        case 4:
            modifyStudent(&db);
            break;
        case 5:
            searchStudent(&db);
            break;
        case 6:
            sortStudents(&db);
            break;
        case 7:
            calculateAverage(&db);
            break;
        case 8:
            saveStudents(&db);
            break;
        case 9:
            countPassStudents(&db);
            break;
        case 10:
            displayMaxTotal(&db);
            break;
        case 0:
            printf("退出系统！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
