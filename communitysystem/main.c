#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 15
//�ṹ�嶨��
typedef struct member {
    char name[LENGTH];
    int ID;
    char telephone[LENGTH];
    char house[LENGTH];
    char check[LENGTH];
    char venue[LENGTH];
    struct member* next;
}mem;

typedef struct house{
    int num;
    char name[LENGTH];
    char host[LENGTH];
    int price;
    struct house *next;
}house;

typedef struct waiter{
    int num;
    char name[LENGTH];
    char sname[LENGTH];
    char sex[LENGTH];
    int age;
    struct waiter *next;
}waiterptr;

void menu();
//��Ա������
mem* Memberlink();
void admin_menu();
void look();
void increase();
void modify();
void save1();
void reducemember();

//���ݹ�����
void houses();
void addhouse();
void reducehouse();
void viewhouse();
house *relinkhouse();
void savehouse();
//��ס����|����ԤԼ����
void selectmember();
void selectvenue();
void viewvenue();
void venue();
//����Ա����
void addwaiter();
void reducewaiter();
void printwaiter();
unsigned int enterChoice();
void savewaiter();
waiterptr * relinkwaiter();
void waiter();
//����ͷβ����
mem* member_head;
mem* member_end;
house *house_head;
house *house_end;
waiterptr *waiter_head;
waiterptr *waiter_end;

//��Ա����
mem* Memberlink()
{
    char Name[LENGTH], telephone[LENGTH], house[LENGTH], Check[LENGTH], Venue[LENGTH];
    int ID;
    mem* head = (mem*)malloc(sizeof(mem));
    mem* pr;//��������ֵ
    FILE* fp = fopen("member.txt", "r");
    pr = head;
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�");
    }
    else
    {
        while (fscanf(fp, "%s %d %s %s %s %s", Name,&ID, telephone, house, Check, Venue) != EOF)
        {
            mem* p = (mem*)malloc(sizeof(mem));
            strcpy(p->name, Name);
            p->ID=ID;
            strcpy(p->telephone, telephone);
            strcpy(p->house, house);
            strcpy(p->check, Check);
            strcpy(p->venue, Venue);
            pr->next = p;
            pr = p;
        }
        pr->next = NULL;
        member_end = pr;
    }
    fclose(fp);
    member_head=head;
}

void admin_menu()
{
    int a;
    loop:system("cls");
    printf("���������¹���:\n");
    printf("1.�鿴��Ա��Ϣ\n");
    printf("2.�޸Ļ�Ա��Ϣ\n");
    printf("3.��ӻ�Ա��Ϣ\n");
    printf("4.ɾ����Ա��Ϣ\n");
    printf("5.�������˵�\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            look();
            break;
        case 2:
            modify();
            break;
        case 3:
            increase();
            break;
        case 4:
            reducemember();
            break;
        case 5:
            menu();
            break;
        default:
            puts("����������1-5");
            goto loop;
    }
}

void look()
{
    int a,b,c=0;
    mem* node = member_head->next;
    system("cls");
    printf("1.�鿴���л�Ա��Ϣ\n");
    printf("2.�鿴�ض���Ա��Ϣ\n");
    printf("3.������һ��\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            system("cls");
            printf("|��Ա��|��Ա��|   �绰��   |��������|��ס����|ԤԼ�ĳ���|\n");
            while (node != NULL)
            {
                printf(" %-6s %-6d %-11s  %-8s %-8s %-10s\n", node->name, node->ID, node->telephone, node->house, node->check, node->venue);
                node = node->next;
            }
            system("pause");
            look();
        case 2:
            system("cls");
            printf("�������ԱID:\n");
            scanf("%d",&b);
            while (node != NULL)
            {
                if (node->ID == b)
                {
                    system("cls");
                    printf("|��Ա��|��Ա��|   �绰��   |��������|��ס����|ԤԼ�ĳ���|\n");
                    printf(" %-6s %-6d %-11s  %-8s %-8s %-10s\n", node->name, node->ID, node->telephone, node->house, node->check, node->venue);
                    printf("\n");
                    c=1;
                }
                node = node->next;
            }
            if (c==1){
            system("pause");
            look();
            }
            else {
                puts("δ�ҵ��û�Ա\n");
                system("pause");
                look();
            }
        case 3:admin_menu();
        default:look();
    }
}

void increase()
{
    system("cls");
    char name[LENGTH], telephone[LENGTH], house[LENGTH], check[LENGTH], venue[LENGTH]="����";
    int ID;
    mem* pr = member_end;
    mem* p = (mem*)malloc(sizeof(mem));
    printf("��������Ҫ����˵���Ϣ\n");
    printf("********************\n");
    printf("�������½���Ա������:");
    scanf("%s", name);
    printf("\n");
    printf("���½���Ա��:");
    scanf("%d", &ID);
    printf("\n");
    printf("�������Ա�ĵ绰��:");
    scanf("%s", telephone);
    printf("\n");;
    printf("�������½���Ա�ѹ���ķ���:");
    scanf("%s", house);
    printf("\n");;
    printf("�������½���Ա��ס�ķ���:");
    scanf("%s", check);
    printf("\n");
    strcpy(p->name, name);
    p->ID=ID;
    strcpy(p->telephone, telephone);
    strcpy(p->house, house);
    strcpy(p->check, check);
    strcpy(p->venue, venue);
    pr->next = p;
    p->next = NULL;
    member_end = p;
    save1();
    admin_menu();
}

void modify()
{
    system("cls");
    int a,b=0;
    mem* node = member_head->next;
    char name[LENGTH], telephone[LENGTH], house[LENGTH], check[LENGTH], venue[LENGTH];
    printf("�����������޸���Ϣ�Ļ�Ա��:");
    scanf("%s", name);
    system("cls");
    while (node != NULL)
    {
        if (strcmp(name, node->name) == 0)
        {
            b=1;
            loop:printf("��ѡ�������޸ĵ���Ϣ\n");
            printf("1.�绰��\n");
            printf("2.�������\n");
            printf("3.��ס�����\n");
            printf("4.ʹ�õĳ���\n5.����\n");
            scanf("%d", &a);
            switch (a)
            {
                case 1:
                    printf("�����������޸ĵĵ绰��:\n");
                    scanf("%s", telephone);
                    strcpy(node->telephone, telephone);
                    break;
                case 2:
                    printf("�����������޸ĵ��ѹ�������:\n");
                    scanf("%s", house);
                    strcpy(node->house, house);
                    break;
                case 3:
                    printf("�����������޸ĵ�ס������:\n");
                    scanf("%s", check);
                    strcpy(node->check, check);
                    break;
                case 4:
                    printf("�����������޸ĵ�ʹ�ó���:\n");
                    scanf("%s", venue);
                    strcpy(node->venue, venue);
                    break;
                case 5:admin_menu();
                default:
                    goto loop;
            }
        }
        node = node->next;
    }
    if (b==0){
        puts("δ�ҵ��û�Ա\n");
        system("pause");
        modify();
    }else {
        save1();
        puts("����ɹ�");
        system("pause");
        admin_menu();
    }
}

void save1()
{
    FILE* fp;
    mem* node = member_head->next;
    fp = fopen("member.txt", "w");
    while (node!=NULL)
    {
        fprintf(fp,"%s %d %s %s %s %s\n", node->name, node->ID, node->telephone, node->house, node->check, node->venue);
        node = node->next;
    }
    fclose(fp);
}

void reducemember(){
    char n[LENGTH];
    system("cls");
    mem *p,*q;
    p=member_head;
    q=p->next;
    printf("��������Ҫɾ���Ļ�Ա��:");
    scanf("%s",n);
    if (q->name==n){
        member_head->next=q->next;
    }else if (q==NULL){
        puts("������");
        system("pause");
    }else {
        while (p) {
            if (q->name == n) {
                p->next = q->next;
                printf("ɾ���ɹ�!\n");
                system("pause");
            }
            q = q->next;
            p = p->next;
        }
    }
    save1();
    admin_menu();
}

//���ݹ���
void houses(){
    system("cls");
    printf("��ѡ���ܣ�\n1.�鿴������Ϣ\n2.���ӷ���\n3.ɾ������\n4.�������˵�\n");
    int a;
    scanf("%d",&a);
    switch (a) {
        case 1: viewhouse();break;
        case 2: addhouse();break;
        case 3: reducehouse();break;
        case 4: return;
        default: puts("����������1-4");break;
    }
}

house *relinkhouse(){
    char name[LENGTH],host[LENGTH];
    int price,num;
    house* head=(house*)malloc(sizeof(house));
    house *p=head;
    FILE *fp=fopen("houses.txt","r");
    if (fp==NULL){
        puts("�ļ���ʧ��");
        exit(1);}
    else{
        while (fscanf(fp,"%d %s %s %d",&num,name,host,&price)!=EOF){
            house *q=(house*)malloc(sizeof(house));
            q->num=num;
            strcpy(q->name,name);
            strcpy(q->host,host);
            q->price=price;
            p->next=q;
            p=q;
        }
        p->next=NULL;
        house_end=p;
        house_head=head;
    }
    fclose(fp);
}

void savehouse(){
    house *p=house_head->next;
    FILE *fp=fopen("houses.txt","w");
    while (p!=NULL){
        fprintf(fp,"%d %s %s %d\n",p->num,p->name,p->host,p->price);
        p=p->next;
    }
    fclose(fp);
}

void addhouse(){
    system("cls");
    house *p=(house*)malloc(sizeof(house));
    puts("�����뷿�ӱ�ţ�\n");
    scanf("%d",&p->num);
    puts("�����뷿����\n");
    scanf("%s",p->name);
    puts("������۸�\n");
    scanf("%d",&p->price);
    strcpy(p->host,"����");
    house_end->next=p;
    p->next=NULL;
    house_end=p;
    savehouse();
    puts("����ɹ�");
    system("pause");
    houses();
}

void reducehouse(){
    int d;
    system("cls");
    house *p,*q;
    p=house_head;
    q=p->next;
    printf("��������Ҫɾ���ı��:");
    scanf("%d",&d);
    if (q->num==d){
        house_head->next=q->next;
    }else if (q==NULL){
        puts("������");
        system("pause");
    }else {
        while (p) {
            if (q->num == d) {
                p->next = q->next;
                printf("ɾ���ɹ�!\n");
                system("pause");
            }
            q = q->next;
            p = p->next;
        }
    }
    savehouse();
    houses();
}

void viewhouse(){
    system("cls");
    house *node=house_head->next;
    printf("| ��� | ���� | ���� | �۸� |\n");
    while(node!=NULL){
        printf("%-8d%-8s%-8s%-8d\n",node->num,node->name,node->host,node->price);
        node=node->next;
    }
    system("pause");
    houses();
}
//��ס����
void selectmember(){
    system("cls");
    mem* node = member_head->next;
    int a,b=0;
    char house[LENGTH];
    puts("�������ԱID:\n");
    scanf("%d",&a);
    while (node!=NULL){
        if (node->ID==a){
            system("cls");
            int c;
            puts("1.����\n2.��ס\n3.�������˵�\n");
            scanf("%d",&c);
            switch (c) {
                case 1:
                    system("cls");
                    puts("�����뽫Ҫ����ķ���:\n");
                    scanf("%s",house);
                    strcpy(node->house,house);
                    save1();
                    puts("����ɹ�\n");
                    system("pause");
                    menu();
                case 2:
                    system("cls");
                    puts("�����뽫Ҫ��ס�ķ���:\n");
                    scanf("%s",house);
                    strcpy(node->check,house);
                    save1();
                    puts("��ס�ɹ�\n");
                    system("pause");
                    menu();
                case 3:
                    menu();
                default:selectmember();
            }
            b=1;
        }
    }
    if (b==0){
        puts("δ�ҵ��û�Ա\n");
        system("pause");
        selectmember();
    } else{
        puts("�����ɹ�\n");
        system("pause");
        selectmember();
    }
}
//����ԤԼ
void selectvenue(){
    int a;
    system("cls");
    puts("1.�鿴������Ϣ\n2.ԤԼ&ȡ��ԤԼ\n3.�������˵�\n");
    scanf("%d",&a);
    switch (a) {
        case 1:viewvenue();
        case 2:venue();
        case 3:menu();
        default:selectvenue();
    }
}

void viewvenue(){
    system("cls");
    puts("1.�����\n"
         "2.��ë���\n"
         "3.ƹ�����\n"
         "4.��Ӿ��\n"
         "5.�����\n");
    system("pause");
    selectvenue();
}

void venue(){
    system("cls");
    mem* node = member_head->next;
    int a,b=0;
    char venue[LENGTH];
    puts("�������ԱID:\n");
    scanf("%d",&a);
    while (node!=NULL){
        if (node->ID==a){
            system("cls");
            int c;
            puts("1.ԤԼ����\n2.ȡ��ԤԼ\n3.����\n");
            scanf("%d",&c);
            switch (c) {
                case 1:
                    system("cls");
                    puts("������ҪԤԼ�ĳ��ݣ�");
                    scanf("%s",venue);
                    strcpy(node->venue,venue);
                    save1();
                    puts("ԤԼ�ɹ�\n");
                    system("pause");
                    selectvenue();
                case 2:
                    system("cls");
                    strcpy(node->venue,"����");
                    save1();
                    puts("ȡ���ɹ�\n");
                    system("pause");
                    selectvenue();
            }
            b=1;
        }
    }
    if (b==0){
        puts("δ�ҵ��û�Ա\n");
        system("pause");
        selectvenue();
    } else{
        puts("�����ɹ�\n");
        system("pause");
        selectvenue();
    }
}
//������Ա����
void waiter()
{
    unsigned int choice;
    while((choice=enterChoice())!=4){
        switch(choice){
            case 1:
                addwaiter();
                break;
            case 2:
                reducewaiter();
                break;
            case 3:
                printwaiter();
                break;
            default:
                puts("�����ѡ��");
                system("cls");
                break;
        }
    }
    return;
}

void addwaiter(){
    system("cls");
    waiterptr *waiter,*temp=waiter_end;
    waiter=(waiterptr*)malloc(sizeof(waiterptr));
    if(waiter==NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    printf("�������ţ�\n");
    scanf("%d",&waiter->num);
    printf("������������\n");
    scanf("%s",waiter->name);
    printf("������������������\n");
    scanf("%s",waiter->sname);
    printf("���������Ա�Ա�\n");
    scanf("%s",waiter->sex);
    printf("���������Ա���䣺\n");
    scanf("%d",&waiter->age);
    temp->next=waiter;
    waiter->next=NULL;
    waiter_end=waiter;
    savewaiter();
}

void reducewaiter()
{
    int d;
    system("cls");
    waiterptr *p,*q;
    p=waiter_head;
    q=p->next;
    printf("��������Ҫɾ���ı��:");
    scanf("%d",&d);
    if (q->num==d){
        waiter_head->next=q->next;
    }else if (q==NULL){
        puts("������");
        system("pause");
    }else {
        while (p) {
            if (q->num == d) {
                p->next = q->next;
                printf("ɾ���ɹ�!\n");
                system("pause");
            }
            q = q->next;
            p = p->next;
        }
    }
    savewaiter();
}

void printwaiter(){
    system("cls");
    waiterptr *node=waiter_head->next;
    printf("| ��� | ���� | �Ա� | ���� |����ͻ�|\n");
    while(node!=NULL){
        printf("%-8d%-8s%-8s%-8d%-8s\n",node->num,node->name,node->sex,node->age,node->sname);
        node=node->next;
    }
    system("pause");
}

unsigned int enterChoice(void)
{
    system("cls");
    printf("%s","��ѡ����\n"
                "1-���һ������Ա\n"
                "2-ɾ��һ������Ա\n"
                "3-�鿴����Ա��Ϣ\n"
                "4-�ص����˵�\n");
    unsigned int choice;
    scanf("%u",&choice);
    return choice;
}

waiterptr * relinkwaiter()
{
    int age,num;
    char name[10],sname[10],sex[10];
    waiterptr *head =(waiterptr *)malloc(sizeof(waiterptr));
    waiterptr *p;
    FILE *fp = fopen("waiters.txt","r");
    p = head;
    if(fp==NULL)
    {
        printf("���ļ�ʧ��!");
        exit(1);
    }
    else
    {
        while(fscanf(fp,"%d %s %s %s %d",&num,name,sname,sex,&age)!=EOF)
        {
            waiterptr *q = (waiterptr *)malloc(sizeof(waiterptr));
            q->num=num;
            strcpy(q->name,name);
            strcpy(q->sname,sname);
            strcpy(q->sex,sex);
            q->age=age;
            p->next=q;
            p=q;
        }
        p->next=NULL;
        waiter_end=p;
        waiter_head=head;
    }
    fclose(fp);
}

void savewaiter(){
    FILE* fp3 = fopen("waiters.txt", "w");
    waiterptr* node = waiter_head->next;
    while (node != NULL) {
        fprintf(fp3,"%d %s %s %s %d\n",node->num,node->name, node->sname,node->sex,node->age);
        node = node->next;
    }
    fclose(fp3);
}

int main() {
    Memberlink();
    relinkwaiter();
    relinkhouse();
    menu();
}

void menu(){
    int c;
    while(1){
        system("cls");
        printf("��ӭ����xxx����ϵͳ\n1.��Ա����\n2.���ݹ���\n3.��ס����\n4.����ԤԼ\n5.������Ա����\n6.�˳�����\n������ѡ�");
        scanf("%d",&c);
        switch (c) {
            case 1: admin_menu(); break;
            case 2: houses();break;
            case 3: selectmember();break;
            case 4: selectvenue();break;
            case 5: waiter();break;
            case 6: exit(0);
            default: puts("����������1-6");system("pause");break;
        }
    }
}
