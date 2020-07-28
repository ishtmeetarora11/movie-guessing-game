#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int front;
int rear;
char game[17];
char holly[17];
int temp;
void solve(FILE *fp,int p)
{
    int l,g=0,y,i,score=0;
    char b[50],j;
    strcpy(game,"H O L L Y W O O D");
    printf("\n\t\t\t\t\t%s\n",game);
    while (!feof(fp))
    {
        fscanf(fp,"%d%s",&l,b);
        if (l==p)
            break;
    }
    printf("\n\t\t");
    char b1[strlen(b)];
    strcpy(b1,b);
    for (i=0;i<strlen(b);i++)
    {
        if (b1[i]=='a'||b1[i]=='e'||b1[i]=='i'||b1[i]=='o'||b1[i]=='u')
        {
            printf(" %c ",b[i]);
        }
        else
        {
            b[i]='_';
            printf(" %c ",b[i]);
        }
    }
    fclose(fp);
    while (strcmp(b1,b)!=0)
    {
        if (strcmp(holly,game)==0)
        {
            printf("\tYou Lose \t Your Score(%d)",score);
            break;
        }
        printf("\n\nEnter your choice\t");
        j=getche();
        printf("\n\n\t");
        for (i=0;i<=strlen(b1);i++)
        {
            if (b1[i]=='a'||b1[i]=='e'||b1[i]=='i'||b1[i]=='o'||b1[i]=='u')
            {
                printf(" %c ",b1[i]);
            }
            else if (b1[i]==j)
            {
                b[i]=j;
                printf(" %c ",j);
            }
            else
            {
                printf(" %c ",b[i]);
            }
        }
        for (i=0;i<=strlen(b);i++)
        {
            if (b1[i]==j)
            {
                y=0;
                break;
            }
            else
            {
                y=1;
            }
        }
        if (y==0)
        {
            printf("\n\tRight Choice\n");
            printf("\n\t\t%s\n",game);
            score+=5;
            printf("Your Score is %d",score);
        }
        else
        {
            printf("\n\tWrong Choice\n\n\t\t");
            dequeue(game);
            score-=2;
            printf("Your Score is %d",score);
        }
    }
    fp=fopen("player.txt","a");
    fprintf(fp,"%d\n",score);
    fclose(fp);
    printf("\n\tEnter 1 for Main Menu 0 to Quit\t");
    int f;
    scanf("%d",&f);
    system("cls");
    if (f==1)
        main();
}
void dequeue(char game2[17])
{
    game[temp]='_';
    int i;
    for (i=front;i<=rear;i++)
        printf("%c",game2[i]);
    printf("\n");
    temp+=2;
}
void main()
{
    printf("\n\n\t\t\t\t    ***********************************\n");
    printf("\t\t\t\t\t\tWELCOME TO HANGMAN\n\n");
    printf("\t\t\t\t\t1.New Game\n\t\t\t\t\t2.Rules and Regulations\n\t\t\t\t\t3.Administrator\n\t\t\t\t\t4.Scores\n\n");
    printf("\t\t\t\t    ***********************************\n");
    printf("\n\n\t\t\t\t\tenter your choice\t");
    int n,i;
    scanf("%d",&n);
    printf("\n\n");
    int m;
    front=0;
    rear=16;
    temp=front;
    FILE *fp;
    int score;
    if (n==1)
    {
        printf("\n\t\t\t\t\t1.Easy\n\t\t\t\t\t2.Medium\n\t\t\t\t\t3.Hard\n\n");
        printf("\n\t\t\t\t\tEnter your choice\t");
        scanf("%d",&m);
        int p;
        strcpy(holly,"_ _ _ _ _ _ _ _ _");
        char player[20];
        printf("\t\t\t\t\tEnter your name\t");
        scanf("%s",&player);
        fp=fopen("player.txt","a");
        fprintf(fp,"%s\t",player);
        fclose(fp);
        printf("\t\t\t\t\tenter lucky no.(1-5)\t");
        scanf("%d",&p);
        system("cls");
        if (m==1)
        {
            fp=fopen("easygame.txt","r");
                    solve(fp,p);
        }
        if (m==2)
        {
            fp=fopen("mediumgame.txt","r");
                    solve(fp,p);
        }
        if (m==3)
        {
            fp=fopen("hardgame.txt","r");
                    solve(fp,p);
        }
    }
    if (n==2)
    {
        printf("1.Player has to choose only a consonent alphabet.\n2.Score awarded for every correct alphabte is +5.\n3.Score awarded for incorrect response is -2.\n");
    }
    if (n==3)
    {

        char pass[8];
        printf("\n\t\t\tEnter password\n\t\t\t\t\t");
        scanf("%s",&pass);
        if (strcmp(pass,"password")==0)
        {
            printf("1.Easy\n2.Medium\n3.Hard\n\n");
            printf("Enter level\t");
            scanf("%d",&m);
            if (m==1)
            {
                int e;
                printf("enter no. of movies you want to enter\n");
                scanf("%d",&e);
                printf("Enter movie no. and movie(use / before next word)\n");
                for (i=0;i<e;i++)
                {
                    fp=fopen("easygame.txt","a");
                    char a[50];
                    int h;
                    scanf("%d",&h);
                    scanf("%s",&a);
                    fprintf(fp,"%d%s\n",h,a);
                    fclose(fp);
                }
            }
            if (m==2)
            {
                int e;
                printf("Enter no. of movies\n");
                scanf("%d",&e);
                printf("Enter movie no. and movie(use / before next word)\n");
                for (i=0;i<e;i++)
                {
                    fp=fopen("mediumgame.txt","a");
                    char a[50];
                    int h;
                    scanf("%d",&h);
                    scanf("%s",&a);
                    fprintf(fp,"%d%s\n",h,a);
                    fclose(fp);
                }
            }
            if (m==3)
            {
                int e;
                printf("enter no. of movies you want to enter\n");
                scanf("%d",&e);
                printf("Enter movie no. and movie(use / before next word)\n");
                for (i=0;i<e;i++)
                {
                    fp=fopen("hardgame.txt","a");
                    char a[50];
                    int h;
                    scanf("%d",&h);
                    scanf("%s",&a);
                    fprintf(fp,"%d%s\n",h,a);
                    fclose(fp);
                }
            }
        }
        else
            printf("*/Enter Correct Password/*\n");
        printf("\n\tEnter 1 for Main Menu 0 to Quit\t");
        int f;
        scanf("%d",&f);
        system("cls");
        if (f==1)
        main();
    }
    if (n==4)
    {
        FILE *fp2;
        fp2=fopen("player.txt","r");
        int score1;
        char name[20];
        printf("\t\tSCORES\n\n");
        while (!feof(fp2))
        {
            fscanf(fp2,"%s%d",name,&score1);
            printf("\t%s\t%d\n",name,score1);
        }
        fclose(fp2);
        printf("\n\tEnter 1 for Main Menu 0 to Quit\ts");
        int f;
        scanf("%d",&f);
        system("cls");
        if (f==1)
            main();
    }
}


