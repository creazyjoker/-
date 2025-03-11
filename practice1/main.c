#define _CRT_SECURE_NO_WARNINGS
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

}

// 删除学生信息（通过学号匹配）
void deleteStudent(StudentDB* db) {

}

// 修改学生信息（通过学号匹配，修改除学号外的其他信息）
void modifyStudent(StudentDB* db) {
}

// 查询学生信息（通过学号）
void searchStudent(StudentDB* db) {

}

// 按总成绩降序排序学生信息
void sortStudents(StudentDB* db) {

}

// 计算各门课程平均成绩
void calculateAverage(StudentDB* db) {

}

// 保存学生信息到文件
void saveStudents(StudentDB* db) {

}

// 从文件加载学生信息
void loadStudents(StudentDB* db) {

}

// 统计全部课程及格的学生人数（每门课成绩均>=60）
void countPassStudents(StudentDB* db) {

}

// 输出总成绩最高的学生信息
void displayMaxTotal(StudentDB* db) {

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
