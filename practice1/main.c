#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char id[30];       // ѧ��
    char name[20];     // ����
    char sex[10];      // �Ա�
    char phone[20];    // �ֻ���
    float scoreC;      // C���Գɼ�
    float scoreEng;    // Ӣ��ɼ�
    float scoreMath;   // �ߵ���ѧ�ɼ�
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentDB;

// ��ʾ����ѧ����Ϣ
void displayStudents(StudentDB* db) {
    printf("\n| ѧ�� | ���� | �Ա� | �ֻ��� | C���� | Ӣ�� | ���� |\n");
    for (int i = 0; i < db->count; i++) {
        Student* s = &db->students[i];
        printf("%s  %s  %s  %s  %.2f  %.2f  %.2f\n",
            s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
    }
}

// ����ѧ����Ϣ
void addStudent(StudentDB* db) {
    if (db->count >= MAX_STUDENTS) {
        printf("ѧ�������Ѵ����ޣ�\n");
        return;
    }
    Student s;
    printf("������ѧ�ţ�");
    scanf("%s", s.id);
    printf("������������");
    scanf("%s", s.name);
    printf("�������Ա�");
    scanf("%s", s.sex);
    printf("�������ֻ��ţ�");
    scanf("%s", s.phone);
    printf("������C���Գɼ���");
    scanf("%f", &s.scoreC);
    printf("������Ӣ��ɼ���");
    scanf("%f", &s.scoreEng);
    printf("������ߵ���ѧ�ɼ���");
    scanf("%f", &s.scoreMath);
    db->students[db->count++] = s;
    printf("ѧ����Ϣ��ӳɹ���\n");
}

// ɾ��ѧ����Ϣ��ͨ��ѧ��ƥ�䣩
void deleteStudent(StudentDB* db) {
    char id[30];
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            // ��������¼ǰ��
            for (int j = i; j < db->count - 1; j++) {
                db->students[j] = db->students[j + 1];
            }
            db->count--;
            printf("ѧ����Ϣɾ���ɹ���\n");
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
    }
}

// �޸�ѧ����Ϣ��ͨ��ѧ��ƥ�䣬�޸ĳ�ѧ�����������Ϣ��
void modifyStudent(StudentDB* db) {
    char id[30];
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            Student* s = &db->students[i];
            printf("��ǰ��Ϣ��ѧ�ţ�%s, ������%s, �Ա�%s, �ֻ��ţ�%s, C���ԣ�%.2f, Ӣ�%.2f, ������%.2f\n",
                s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
            printf("�������µ�������");
            scanf("%s", s->name);
            printf("�������µ��Ա�");
            scanf("%s", s->sex);
            printf("�������µ��ֻ��ţ�");
            scanf("%s", s->phone);
            printf("�������µ�C���Գɼ���");
            scanf("%f", &s->scoreC);
            printf("�������µ�Ӣ��ɼ���");
            scanf("%f", &s->scoreEng);
            printf("�������µĸߵ���ѧ�ɼ���");
            scanf("%f", &s->scoreMath);
            printf("ѧ����Ϣ�޸ĳɹ���\n");
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
    }
}

// ��ѯѧ����Ϣ��ͨ��ѧ�ţ�
void searchStudent(StudentDB* db) {
    char id[30];
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            found = 1;
            Student* s = &db->students[i];
            printf("��ѯ�����ѧ�ţ�%s, ������%s, �Ա�%s, �ֻ��ţ�%s, C���ԣ�%.2f, Ӣ�%.2f, ������%.2f\n",
                s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath);
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
    }
}

// ���ܳɼ���������ѧ����Ϣ
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
    printf("ѧ����Ϣ������ɣ����ܳɼ����򣩣�\n");
}

// ������ſγ�ƽ���ɼ�
void calculateAverage(StudentDB* db) {
    if (db->count == 0) {
        printf("û��ѧ�����ݣ�\n");
        return;
    }
    float sumC = 0, sumEng = 0, sumMath = 0;
    for (int i = 0; i < db->count; i++) {
        sumC += db->students[i].scoreC;
        sumEng += db->students[i].scoreEng;
        sumMath += db->students[i].scoreMath;
    }
    printf("ƽ���ɼ���C���ԣ�%.2f, Ӣ�%.2f, �ߵ���ѧ��%.2f\n",
        sumC / db->count, sumEng / db->count, sumMath / db->count);
}

// ����ѧ����Ϣ���ļ�
void saveStudents(StudentDB* db) {
    FILE* fp = fopen("data.txt", "w");
    if (!fp) {
        printf("�޷����ļ��������ݣ�\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        Student* s = &db->students[i];
        fprintf(fp, "%s %s %s %s %.2f %.2f %.2f\n", s->id, s->name, s->sex, s->phone,
            s->scoreC, s->scoreEng, s->scoreMath);
    }
    fclose(fp);
    printf("���ݱ���ɹ���\n");
}

// ���ļ�����ѧ����Ϣ
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

// ͳ��ȫ���γ̼����ѧ��������ÿ�ſγɼ���>=60��
void countPassStudents(StudentDB* db) {
    int countPass = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].scoreC >= 60 &&
            db->students[i].scoreEng >= 60 &&
            db->students[i].scoreMath >= 60) {
            countPass++;
        }
    }
    printf("ȫ���γ̼����ѧ��������%d\n", countPass);
}

// ����ܳɼ���ߵ�ѧ����Ϣ
void displayMaxTotal(StudentDB* db) {
    if (db->count == 0) {
        printf("û��ѧ�����ݣ�\n");
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
    printf("�ܳɼ���ߵ�ѧ����Ϣ��\n");
    printf("ѧ�ţ�%s, ������%s, �Ա�%s, �ֻ��ţ�%s, C���ԣ�%.2f, Ӣ�%.2f, ������%.2f, �ܳɼ���%.2f\n",
        s->id, s->name, s->sex, s->phone, s->scoreC, s->scoreEng, s->scoreMath, maxTotal);
}

// �˵���ʾ����
void menu() {
    printf("\n*************************ѧ���ɼ�����ϵͳ*************************\n");
    printf("1. ��ʾѧ����Ϣ\n");
    printf("2. ����ѧ����Ϣ\n");
    printf("3. ɾ��ѧ����Ϣ\n");
    printf("4. �޸�ѧ����Ϣ\n");
    printf("5. ��ѯѧ����Ϣ\n");
    printf("6. ����ѧ����Ϣ�����ܳɼ�����\n");
    printf("7. ����ѧ��ƽ���ɼ�\n");
    printf("8. ����ѧ����Ϣ\n");
    printf("9. ͳ��ȫ���γ̼�������\n");
    printf("10. ����ܳɼ���ߵ�ѧ����Ϣ\n");
    printf("0. �˳�ϵͳ\n");
    printf("�����������ţ�");
}

int main() {
    StudentDB db;
    db.count = 0;
    // �����������ݣ�����У�
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
            printf("�˳�ϵͳ��\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
