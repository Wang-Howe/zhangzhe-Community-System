#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 15
//结构体定义
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
//会员管理函数
mem* Memberlink();
void admin_menu();
void look();
void increase();
void modify();
void save1();
void reducemember();

//房屋管理函数
void houses();
void addhouse();
void reducehouse();
void viewhouse();
house *relinkhouse();
void savehouse();
//入住管理|场馆预约函数
void selectmember();
void selectvenue();
void viewvenue();
void venue();
//服务员函数
void addwaiter();
void reducewaiter();
void printwaiter();
unsigned int enterChoice();
void savewaiter();
waiterptr * relinkwaiter();
void waiter();
//链表头尾定义
mem* member_head;
mem* member_end;
house *house_head;
house *house_end;
waiterptr *waiter_head;
waiterptr *waiter_end;

//会员管理
mem* Memberlink()
{
    char Name[LENGTH], telephone[LENGTH], house[LENGTH], Check[LENGTH], Venue[LENGTH];
    int ID;
    mem* head = (mem*)malloc(sizeof(mem));
    mem* pr;//给数据域赋值
    FILE* fp = fopen("member.txt", "r");
    pr = head;
    if (fp == NULL)
    {
        printf("打开文件失败！");
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
    printf("您具有以下功能:\n");
    printf("1.查看会员信息\n");
    printf("2.修改会员信息\n");
    printf("3.添加会员信息\n");
    printf("4.删除会员信息\n");
    printf("5.返回主菜单\n");
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
            puts("请输入数字1-5");
            goto loop;
    }
}

void look()
{
    int a,b,c=0;
    mem* node = member_head->next;
    system("cls");
    printf("1.查看所有会员信息\n");
    printf("2.查看特定会员信息\n");
    printf("3.返回上一步\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            system("cls");
            printf("|会员名|会员号|   电话号   |购房类型|入住房屋|预约的场馆|\n");
            while (node != NULL)
            {
                printf(" %-6s %-6d %-11s  %-8s %-8s %-10s\n", node->name, node->ID, node->telephone, node->house, node->check, node->venue);
                node = node->next;
            }
            system("pause");
            look();
        case 2:
            system("cls");
            printf("请输入会员ID:\n");
            scanf("%d",&b);
            while (node != NULL)
            {
                if (node->ID == b)
                {
                    system("cls");
                    printf("|会员名|会员号|   电话号   |购房类型|入住房屋|预约的场馆|\n");
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
                puts("未找到该会员\n");
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
    char name[LENGTH], telephone[LENGTH], house[LENGTH], check[LENGTH], venue[LENGTH]="暂无";
    int ID;
    mem* pr = member_end;
    mem* p = (mem*)malloc(sizeof(mem));
    printf("请输入所要添加人的信息\n");
    printf("********************\n");
    printf("请输入新建会员的名字:");
    scanf("%s", name);
    printf("\n");
    printf("请新建会员号:");
    scanf("%d", &ID);
    printf("\n");
    printf("请输入会员的电话号:");
    scanf("%s", telephone);
    printf("\n");;
    printf("请输入新建会员已购买的房型:");
    scanf("%s", house);
    printf("\n");;
    printf("请输入新建会员入住的房型:");
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
    printf("请输入您想修改信息的会员名:");
    scanf("%s", name);
    system("cls");
    while (node != NULL)
    {
        if (strcmp(name, node->name) == 0)
        {
            b=1;
            loop:printf("请选择您想修改的信息\n");
            printf("1.电话号\n");
            printf("2.购房情况\n");
            printf("3.现住房情况\n");
            printf("4.使用的场馆\n5.返回\n");
            scanf("%d", &a);
            switch (a)
            {
                case 1:
                    printf("请输入你想修改的电话号:\n");
                    scanf("%s", telephone);
                    strcpy(node->telephone, telephone);
                    break;
                case 2:
                    printf("请输入你想修改的已购房类型:\n");
                    scanf("%s", house);
                    strcpy(node->house, house);
                    break;
                case 3:
                    printf("请输入你想修改的住房类型:\n");
                    scanf("%s", check);
                    strcpy(node->check, check);
                    break;
                case 4:
                    printf("请输入你想修改的使用场馆:\n");
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
        puts("未找到该会员\n");
        system("pause");
        modify();
    }else {
        save1();
        puts("保存成功");
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
    printf("请输入想要删除的会员名:");
    scanf("%s",n);
    if (q->name==n){
        member_head->next=q->next;
    }else if (q==NULL){
        puts("无数据");
        system("pause");
    }else {
        while (p) {
            if (q->name == n) {
                p->next = q->next;
                printf("删除成功!\n");
                system("pause");
            }
            q = q->next;
            p = p->next;
        }
    }
    save1();
    admin_menu();
}

//房屋管理
void houses(){
    system("cls");
    printf("请选择功能：\n1.查看房屋信息\n2.增加房屋\n3.删除房屋\n4.返回主菜单\n");
    int a;
    scanf("%d",&a);
    switch (a) {
        case 1: viewhouse();break;
        case 2: addhouse();break;
        case 3: reducehouse();break;
        case 4: return;
        default: puts("请输入数字1-4");break;
    }
}

house *relinkhouse(){
    char name[LENGTH],host[LENGTH];
    int price,num;
    house* head=(house*)malloc(sizeof(house));
    house *p=head;
    FILE *fp=fopen("houses.txt","r");
    if (fp==NULL){
        puts("文件打开失败");
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
    puts("请输入房子编号：\n");
    scanf("%d",&p->num);
    puts("请输入房名：\n");
    scanf("%s",p->name);
    puts("请输入价格：\n");
    scanf("%d",&p->price);
    strcpy(p->host,"暂无");
    house_end->next=p;
    p->next=NULL;
    house_end=p;
    savehouse();
    puts("保存成功");
    system("pause");
    houses();
}

void reducehouse(){
    int d;
    system("cls");
    house *p,*q;
    p=house_head;
    q=p->next;
    printf("请输入想要删除的编号:");
    scanf("%d",&d);
    if (q->num==d){
        house_head->next=q->next;
    }else if (q==NULL){
        puts("无数据");
        system("pause");
    }else {
        while (p) {
            if (q->num == d) {
                p->next = q->next;
                printf("删除成功!\n");
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
    printf("| 编号 | 名字 | 房主 | 价格 |\n");
    while(node!=NULL){
        printf("%-8d%-8s%-8s%-8d\n",node->num,node->name,node->host,node->price);
        node=node->next;
    }
    system("pause");
    houses();
}
//入住管理
void selectmember(){
    system("cls");
    mem* node = member_head->next;
    int a,b=0;
    char house[LENGTH];
    puts("请输入会员ID:\n");
    scanf("%d",&a);
    while (node!=NULL){
        if (node->ID==a){
            system("cls");
            int c;
            puts("1.购买\n2.入住\n3.返回主菜单\n");
            scanf("%d",&c);
            switch (c) {
                case 1:
                    system("cls");
                    puts("请输入将要购买的房子:\n");
                    scanf("%s",house);
                    strcpy(node->house,house);
                    save1();
                    puts("购买成功\n");
                    system("pause");
                    menu();
                case 2:
                    system("cls");
                    puts("请输入将要入住的房子:\n");
                    scanf("%s",house);
                    strcpy(node->check,house);
                    save1();
                    puts("入住成功\n");
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
        puts("未找到该会员\n");
        system("pause");
        selectmember();
    } else{
        puts("操作成功\n");
        system("pause");
        selectmember();
    }
}
//场馆预约
void selectvenue(){
    int a;
    system("cls");
    puts("1.查看场馆信息\n2.预约&取消预约\n3.返回主菜单\n");
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
    puts("1.篮球馆\n"
         "2.羽毛球馆\n"
         "3.乒乓球馆\n"
         "4.游泳馆\n"
         "5.健身馆\n");
    system("pause");
    selectvenue();
}

void venue(){
    system("cls");
    mem* node = member_head->next;
    int a,b=0;
    char venue[LENGTH];
    puts("请输入会员ID:\n");
    scanf("%d",&a);
    while (node!=NULL){
        if (node->ID==a){
            system("cls");
            int c;
            puts("1.预约场馆\n2.取消预约\n3.返回\n");
            scanf("%d",&c);
            switch (c) {
                case 1:
                    system("cls");
                    puts("请输入要预约的场馆：");
                    scanf("%s",venue);
                    strcpy(node->venue,venue);
                    save1();
                    puts("预约成功\n");
                    system("pause");
                    selectvenue();
                case 2:
                    system("cls");
                    strcpy(node->venue,"暂无");
                    save1();
                    puts("取消成功\n");
                    system("pause");
                    selectvenue();
            }
            b=1;
        }
    }
    if (b==0){
        puts("未找到该会员\n");
        system("pause");
        selectvenue();
    } else{
        puts("操作成功\n");
        system("pause");
        selectvenue();
    }
}
//服务人员管理
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
                puts("错误的选项");
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
        printf("内存分配失败\n");
        exit(1);
    }
    printf("请输入编号：\n");
    scanf("%d",&waiter->num);
    printf("请输入姓名：\n");
    scanf("%s",waiter->name);
    printf("请输入服务对象姓名：\n");
    scanf("%s",waiter->sname);
    printf("请输入服务员性别：\n");
    scanf("%s",waiter->sex);
    printf("请输入服务员年龄：\n");
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
    printf("请输入想要删除的编号:");
    scanf("%d",&d);
    if (q->num==d){
        waiter_head->next=q->next;
    }else if (q==NULL){
        puts("无数据");
        system("pause");
    }else {
        while (p) {
            if (q->num == d) {
                p->next = q->next;
                printf("删除成功!\n");
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
    printf("| 编号 | 名字 | 性别 | 年龄 |服务客户|\n");
    while(node!=NULL){
        printf("%-8d%-8s%-8s%-8d%-8s\n",node->num,node->name,node->sex,node->age,node->sname);
        node=node->next;
    }
    system("pause");
}

unsigned int enterChoice(void)
{
    system("cls");
    printf("%s","请选择功能\n"
                "1-添加一名服务员\n"
                "2-删除一名服务员\n"
                "3-查看服务员信息\n"
                "4-回到主菜单\n");
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
        printf("打开文件失败!");
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
        printf("欢迎来到xxx社区系统\n1.会员管理\n2.房屋管理\n3.入住管理\n4.场馆预约\n5.服务人员管理\n6.退出程序\n请输入选项：");
        scanf("%d",&c);
        switch (c) {
            case 1: admin_menu(); break;
            case 2: houses();break;
            case 3: selectmember();break;
            case 4: selectvenue();break;
            case 5: waiter();break;
            case 6: exit(0);
            default: puts("请输入数字1-6");system("pause");break;
        }
    }
}
