#define _CRT_SECURE_NO_WARNINGS
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

}

// ɾ��ѧ����Ϣ��ͨ��ѧ��ƥ�䣩
void deleteStudent(StudentDB* db) {

}

// �޸�ѧ����Ϣ��ͨ��ѧ��ƥ�䣬�޸ĳ�ѧ�����������Ϣ��
void modifyStudent(StudentDB* db) {
}

// ��ѯѧ����Ϣ��ͨ��ѧ�ţ�
void searchStudent(StudentDB* db) {

}

// ���ܳɼ���������ѧ����Ϣ
void sortStudents(StudentDB* db) {

}

// ������ſγ�ƽ���ɼ�
void calculateAverage(StudentDB* db) {

}

// ����ѧ����Ϣ���ļ�
void saveStudents(StudentDB* db) {

}

// ���ļ�����ѧ����Ϣ
void loadStudents(StudentDB* db) {

}

// ͳ��ȫ���γ̼����ѧ��������ÿ�ſγɼ���>=60��
void countPassStudents(StudentDB* db) {

}

// ����ܳɼ���ߵ�ѧ����Ϣ
void displayMaxTotal(StudentDB* db) {

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
