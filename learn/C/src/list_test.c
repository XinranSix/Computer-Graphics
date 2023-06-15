#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int num;
    int score;
    char name[20];
    struct student *next;
} STU;

void link_create_head(STU **p_head, STU *p_new) {
    STU *p_mov = *p_head;
    if (*p_head == NULL) {
        *p_head = p_new;
        p_new->next = NULL;
    } else {
        while (p_mov->next != NULL) {
            p_mov = p_mov->next;
        }
        p_mov->next = p_new;
        p_new->next = NULL;
    }
}

void link_print(STU *head) {
    while (head != NULL) {
        printf("num=%d score=%d name=%s\n", head->num, head->score, head->name);
        head = head->next;
    }
}

void link_free(STU *p_head) {
    STU *pb = p_head;
    while (p_head != NULL) {
        pb = p_head;
        p_head = (p_head)->next;
        free(pb);
    }
}

STU *link_search_num(STU *head, int num) {
    while (head != NULL) {
        if (head->num == num) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

STU *link_search_name(STU *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void link_delete_num(STU **p_head, int num) {
    STU *pb, *pf;
    pb = pf = *p_head;
    if (*p_head == NULL) {
        return;
    }
    while (pb->num != num && pb->next != NULL) {
        pf = pb;
        pb = pb->next;
    }
    if (pb->num == num) {
        if (pb == *p_head) {
            *p_head = pb->next;
        } else {
            pf->next = pb->next;
        }
        free(pb);
    } else {
        printf("没有您要删除的节点\n");
    }
}

void link_insert_num(STU **p_head, STU *p_new) {
    STU *pb, *pf;
    pb = pf = *p_head;
    if (*p_head == NULL) {
        *p_head = p_new;
        p_new->next = NULL;
        return;
    }
    while ((p_new->num >= pb->num) && (pb->next != NULL)) {
        pf = pb;
        pb = pb->next;
    }
    if (p_new->num < pb->num) {
        if (pb == *p_head) {
            p_new->next = *p_head;
            *p_head = p_new;
        } else {
            pf->next = p_new;
            p_new->next = pb;
        }
    } else {
        pb->next = p_new;
        p_new->next = NULL;
    }
}

void link_order(STU *head) {
    STU *pb, *pf, temp;
    pf = head;
    if (head == NULL) {
        printf("链表为空，不用排序\n");
        return;
    }
    if (head->next == NULL) {
        printf("只有一个节点，不用排序\n");
        return;
    }
    while (pf->next != NULL) {
        pb = pf->next;
        while (pb != NULL) {
            if (pf->num > pb->num) {
                temp = *pb;
                *pb = *pf;
                *pf = temp;

                temp.next = pb->next;
                pb->next = pf->next;
                pf->next = temp.next;
            }
            pb = pb->next;
        }
    }
}

void link_revers(STU *head) {}

int main(int argc, char *argv[]) {
    STU *head = NULL, *p_new = NULL;
    int num;
    printf("请输入链表初始个数：\n");
    scanf_s("%d", &num);
    for (int i = 0; i < num; ++i) {
        p_new = (STU *)malloc(sizeof(STU));
        printf("请输入学号、学分、姓名：\n");
        scanf_s("%d %d %s", &p_new->num, &p_new->score, p_new->name, 20);
        link_create_head(&head, p_new);
    }
    link_print(head);
    return 0;
}
