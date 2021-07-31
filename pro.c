#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<malloc.h>
void firstpage();
void registrylogin();
void studentlogin();
void teacherlogin();
void workregistry();
//STUDENT SIGNIN////////////////////////////////////////////////
COORD coord={0,0};
void gotoxy(int x,int y)
 {
     coord.X=x;
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void studentlogin()
{
 char sd[200],en[50],pa[50];
 long offsets;
int b,m;

    FILE*sp;
    sp=fopen("studentdetails.txt","r");
    if(sp==NULL)
    {
        gotoxy(30,8);
        printf("FILE NOT FOUND");
        _getch();
        firstpage();
    }
   else
   {
        offsets=ftell(sp);
        fseek(sp,0,SEEK_END);
        if(ftell(sp)==0)
        {
            gotoxy(30,8);
            printf("FILE IS EMPTY");
            _getch();
            firstpage();
        }
        fseek(sp,offsets,SEEK_SET);
    int i=0;
    char senroll[50],spassword[20],ptemp;
 gotoxy(30,8);
 printf("ENTER ENROLLEMENT NUMBER:");
 scanf("%s",&senroll);
 gotoxy(30,9);
 printf("ENTER 8 DIGIT PASSWORD");
 for(i=0;i<8;i++)
{
ptemp=_getch();
spassword[i]=ptemp;
ptemp='*';
printf("%c",ptemp);
}
spassword[i]='\0';
while(!feof(sp))
{
fgets(sd,200,sp);
for(b=0;sd[b]!='_';b++)
        {
            en[b]=sd[b];
        }
        en[b]='\0';
for(b=b+1,m=0;sd[b]!='_';b++,m++)
{
    pa[m]=sd[b];

}
pa[m]='\0';
if(strcmp(en,senroll)==0&&strcmp(pa,spassword)==0)
{
gotoxy(30,10);
printf("VALID USER");
fclose(sp);
_getch();
workstudent(senroll);
break;
}
}
gotoxy(30,10);
printf("INVALID ENROLLMENT ID OR PASSWORD");
gotoxy(30,11);
fclose(sp);
printf("PRESS ENTER");
_getch();
   }
}

void workstudent(char wsenroll[50])
{
 int wc,i,cn=0,score=0,tsc;
 char dh,r,qn[200],ransw[40],cansw[40],sscor[40],sscors[40];
 FILE*ws,*as,*sco,*sco2,*de;
 char destr[200],chen[50];
 int f=0,j,k,z;
 char ce[40],ca[40],ce2[40];
 while(1)
 {
system("cls");
gotoxy(30,8);
printf("1.ENTER TEST");
gotoxy(30,9);
printf("2.SHOW RESULT ");
gotoxy(30,10);
printf("3.GO TO MAIN MENU");
gotoxy(30,11);
printf("4.EXIT");
gotoxy(30,12);
printf("ENTER YOUR CHOICE:");
scanf("%d",&wc);
 switch(wc)
 {
  case 1:
      ws=fopen("questions.txt","r");
      system("cls");
          sco2=fopen("scores.txt","r");
          while(fgets(sscors,40,sco2)!=NULL)
          {
           for(f=0;sscors[f]!='_';f++)
           {
              ce2[f]=sscors[f];
           }
           ce2[f]='\0';
           if(strcmp(wsenroll,ce2)==0)
           {
            gotoxy(30,8);
            printf("YOU HAVE TAKEN TEST ALREADY");
           fclose(sco2);
           goto already;
           }
          fclose(sco2);
          }
gotoxy(30,8);
      printf("WELCOME TO ONLINE TEST\n");
      gotoxy(30,9);
      printf("The Rules of the test are as follows:");
      gotoxy(30,10);
      printf("1. There are 4 options to each question.");
      gotoxy(30,11);
      printf("2. All questions are compulsory.");
      gotoxy(30,12);
      printf("3.THERE IS ONE MARK FOR EACH CORRECT QUESTION AND NO NEGATIVE MARKING");
      gotoxy(30,13);
      printf("PRESS Y TO ENTER TEST OR N TO ABORT:");
      scanf("%s",&r);
      if(r=='y'||r=='Y')
      {
      system("cls");
      while(fgets(qn,200,ws)!=NULL)
      {
          system("cls");
          gotoxy(30,8);
          printf("%s",qn);
          fgets(qn,200,ws);
          gotoxy(30,9);
          printf("%s",qn);
          gotoxy(30,10);
          printf("ENTER YOUR RESPONSE OPTION:");
          scanf("%s",&ransw[cn]);
          cn++;
      }
      as=fopen("answers.txt","r");
    tsc=cn;
     cn=0;
      while(fgets(cansw,50,as)!=NULL)
      {
        dh=cansw[0];
      if(ransw[cn]==dh)
      {
          score++;
      }
      cn++;
      }
      system("cls");
      gotoxy(30,8);
      printf("YOUR SCORE FOR THIS TEST IS :%d\n",score);
      sco=fopen("scores.txt","a+");
      fprintf(sco,"%s_ SCORE:%dOUT OF%d\n",wsenroll,score,tsc);
      gotoxy(30,9);
      printf("TEST IS OVER");
      fclose(sco);
      fclose(ws);
      fclose(as);
      _getch();
      workstudent(wsenroll);
      }
      else
      {
          workstudent(wsenroll);
      }
      already:
      _getch();
      break;
  case 2:
    system("cls");
    sco=fopen("scores.txt","r");
    de=fopen("studentdetails.txt","r");
          while(fgets(sscor,40,sco)!=NULL)
          {
           for(f=0;sscor[f]!='_';f++)
           {
              ce[f]=sscor[f];
           }
           ce[f]='\0';
           if(strcmp(wsenroll,ce)==0)
           {

            gotoxy(30,8);
            printf("YOUR DETAILS ARE:");
             gotoxy(30,10);
             printf("ENROLLMENT ID_PASSWORD_STUDENT NAME_FATHER'S NAME_MOTHER'S NAME_DOB:");
           while(fgets(destr,200,de)!=NULL)
           {
            for(z=0;destr[z]!='_';z++)
            {
                chen[z]=destr[z];
            }
            chen[z]='\0';
            if(strcmp(chen,wsenroll)==0)
            {
              gotoxy(30,11);
              printf("%s",destr);
            }
           }
           gotoxy(30,13);
           printf("YOUR MARKS ARE:");
           gotoxy(30,15);
           printf("ENROLLMENT ID_MARKS");
           gotoxy(30,16);
           printf("%s",sscor);
           goto wsfound;
           }
          }
          gotoxy(30,8);
       printf("YOU HAVE NOT TAKEN TEST YET");
    wsfound:
    fclose(sco);
    _getch();
    break;
  case 3:
    firstpage();
    break;
  case 4:
    exit(0);
    break;
  default:
    gotoxy(30,13);
    printf("INVALID CHOICE");
    break;
 }
 }
}
//REGISTRY LOGIN////////////////////

void registrylogin()
{
    int qr=0;
 char repassword[8],reps;
 gotoxy(30,8);
 printf("ENTER PASSWORD");
 for(qr=0;qr<8;qr++)
{
reps=_getch();
repassword[qr]=reps;
reps='*';
printf("%c",reps);
}
repassword[qr]='\0';
if(strcmp(repassword,"jiit#123")==0)
 {
 gotoxy(30,9);
printf("PERMISSION GRANTED");
_getch();
workregistry();
}
else
{
    gotoxy(30,9);
printf("INVALID PASSWORD");
_getch();
firstpage();
}
}


struct studentdtails
{
    char stunm[50];
    char fnm[50];
    char mnm[50];
    char dob[15];
    char enr[20];
    char spass[20];
    struct studentdtails *link;
};
struct studentdtails *current ,*start=NULL;
void workregistry()
{
while(1)
{
   system("cls");
    struct studentdtails*k;
    k=(struct studentdtails*)malloc(sizeof(struct studentdtails));
    k->link=NULL;
    char stri[200];
    FILE *studetails;
    studetails=fopen("studentdetails.txt","a+");
    int w,ca,l,a,i=0,x,y,z,tz,aq,v,s;
    long offset;
    char denr[50],checkenr[50],shal[200],sstu[200],ss[20],eroll[20];
gotoxy(30,8);
printf("1.ADD STUDENT");
gotoxy(30,9);
printf("2.SHOW ALL STUDENTS");
gotoxy(30,10);
printf("3.SEARCH A STUDENT");
gotoxy(30,11);
printf("4.GO TO MAIN MENU");
gotoxy(30,12);
printf("5.EXIT");
gotoxy(30,13);
printf("ENTER YOUR CHOICE:");
scanf("%d",&ca);
shal[0]='\0';
switch(ca)
{
case(1):
    {
        system("cls");
gotoxy(30,8);
fflush(stdin);
printf("ENTER STUDENT'S NAME :");
gets(k->stunm);
fflush(stdin);
gotoxy(30,9);
printf("ENTER FATHER'S NAME :");
gets(k->fnm);
fflush(stdin);
gotoxy(30,10);
printf("ENTER MOTHER'S NAME :");
gets(k->mnm);
fflush(stdin);
gotoxy(30,11);
printf("ENTER DATE OF BIRTH :");
gets(k->dob);
fflush(stdin);
gotoxy(30,12);
printf("ASSIGN ENROLLMENT ID :");
scanf("%s",&k->enr);
gotoxy(30,13);
printf("ASSIGN NEW 8 DIGIT PASSWORD :");
scanf("%s",&k->spass);
if(start==NULL)
{
 start=k;
 current=k;
}
else
{
current->link=k;
current=k;
}
fprintf(studetails,"%s_%s_STUDENT'S NAME:%s FATHER'S NAME:%s MOTHER'S NAME:%s DOB:%s\n",k->enr,k->spass,k->stunm,k->fnm,k->mnm,k->dob);
fclose(studetails);
gotoxy(30,14);
printf("NEW STUDENT ADDED SUCCESSFULLY");
gotoxy(30,15);
printf("PRESS ANY KEY");
fclose(studetails);
_getch();
    break;
    }
case 2:
          system("cls");
          if(studetails==NULL)
    {
        gotoxy(30,8);
        printf("FILE NOT FOUND");
        _getch();
        break;
    }

       else
       {
        offset=ftell(studetails);
        fseek(studetails,0,SEEK_END);
        if(ftell(studetails)==0)
        {
            gotoxy(30,8);
            printf("FILE IS EMPTY");
            _getch();
            break;
        }
        fseek(studetails,offset,SEEK_SET);
        gotoxy(30,8);
        printf("ENROLLMENT ID_PASSWORD_STUDENT NAME_FATHER'S NAME_MOTHER'S NAME_DOB:");
        aq=1;
        while(fgets(shal,200,studetails)!=NULL)
        {
                gotoxy(30,aq+9);
                printf("%s",shal);

                aq++;
        }
        _getch();
        break;
    }
case 3:
     system("cls");
     if(studetails==NULL)
    {
        gotoxy(30,8);
        printf("FILE NOT FOUND");
        _getch();
        break;
    }
    else
    {
        gotoxy(30,8);
    printf("ENTER ENROLLMENT ID TO SEARCH:");
    scanf("%s",&eroll);
     offset=ftell(studetails);
        fseek(studetails,0,SEEK_END);
        if(ftell(studetails)==0)
        {
            gotoxy(30,9);
            printf("FILE IS EMPTY");
            _getch();
            break;
        }
        fseek(studetails,offset,SEEK_SET);
    while(!feof(studetails))
    {
     fgets(sstu,200,studetails);
     for(a=0;sstu[a]!='_';a++)
     {
       ss[a]=sstu[a];
     }
     ss[a]='\0';
     if(strcmp(ss,eroll)==0)
     {
       system("cls");
       gotoxy(30,8);
       printf("STUDENT FOUND");
       gotoxy(30,9);
       printf("ENROLLMENT ID_PASSWORD_STUDENT NAME_FATHER'S NAME_MOTHER'S NAME_DOB:");
       gotoxy(30,11);
       printf("%s",sstu);
       goto found;
     }
     }
     gotoxy(30,9);
    printf("STUDENT NOT FOUND");
    found:
    _getch();
    break;
    }
case 4:
    {
       firstpage();
   break;
    }
case 5:
    {
        exit(0);
    }
default:
    {
      printf("INVALID CHOICE");
      exit(0);
    }
}
}
}
//TEACHERS LOGIN //////////////////////////
void teacherlogin()
{
int q=0,ma;
 char rpassword[8],rps;
 gotoxy(30,8);
 printf("ENTER PASSWORD");
 for(q=0;q<8;q++)
{
rps=_getch();
rpassword[q]=rps;
rps='*';
printf("%c",rps);
}
rpassword[q]='\0';
if(strcmp(rpassword,"jiit@123")==0)
 {
    gotoxy(30,9);
    printf("PERMISSION GRANTED");
    _getch();
    int rchoice1,coun=1;
    FILE *ques,*ans,*sco3;
    char ch='y',qnm[500],a[50],asc[40];
    char oa[20],ob[20],oc[20],od[20];
    while(1)
    {
        system("cls");
    gotoxy(30,8);
    printf("1.ADD TEST");
    gotoxy(30,9);
    printf("2.SHOW MARKS OF ALL STUDENTS");
    gotoxy(30,10);
    printf("3.GO TO MAIN MENU");
    gotoxy(30,11);
    printf("4.EXIT");
    gotoxy(30,12);
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&rchoice1);
    switch(rchoice1)
    {
    case 1:
       system("cls");
       ques=fopen("questions.txt","w");
    ans=fopen("answers.txt","w");

     while(ch=='y'||ch=='Y')
    {
    system("cls");
    gotoxy(30,8);
    printf("ENTER QUESTIONS:");
    fflush(stdin);
    gotoxy(30,9);
    printf("ENTER %d QUESTION:",coun);
    gets(qnm);
    fflush(stdin);
    gotoxy(30,10);
    printf("ENTER OPTION A:");
    gets(oa);
    fflush(stdin);
    gotoxy(30,11);
    printf("ENTER OPTION B:");
    gets(ob);
    fflush(stdin);
    gotoxy(30,12);
    printf("ENTER OPTION C:");
    gets(oc);
    fflush(stdin);
    gotoxy(30,13);
    printf("ENTER OPTION D:");
    gets(od);
    fflush(stdin);
    gotoxy(30,14);
    printf("ENTER CORRECT OPTION:");
    fflush(stdin);
    gets(a);
    fflush(stdin);
    fprintf(ques,"QUES%d.%s\n(A).%s\t(B).%s\t(C).%s \t(D).%s\n",coun,qnm,oa,ob,oc,od);
    fprintf(ans,"%s\n",a);
    gotoxy(30,15);
    printf("PRESS Y TO ENTER ANOTHER QUES ELSE PRESS N");
    scanf("%s",&ch);
    fflush(stdin);
    coun++;
    }
    gotoxy(30,16);
    printf("QUESTIONS ENTERED SUCCESSFULLY");
    _getch();
    fclose(ques);
    fclose(ans);
    break;
    case 2:
        system("cls");
        sco3=fopen("scores.txt","r");
        gotoxy(30,8);
        printf("ENROLLMENT ID_SCORES:");
        ma=0;
        while(fgets(asc,40,sco3)!=NULL)
        {
           gotoxy(30,ma+9);
           printf("%s",asc);
        ma++;
        }
        _getch();
        fclose(sco3);
        break;
    case 3:
        firstpage();
        break;
    case 4:
     exit(0);
    default:
        gotoxy(30,13);
        printf("INVALID CHOICE");
    }

    }
 }
 else
{
    gotoxy(30,9);
printf("INCORRECT PASSWORD");
_getch();
}
}
//MAIN MENU///////////////////////
void firstpage()
{
    int choice1;
    while(1)
    {
     system("cls");
     gotoxy(30,8);
    printf("WELCOME TO ONLINE EXAM MANAGEMENT SYSTEM");
    gotoxy(30,9);
    printf("1.ENTER AS STUDENT ");
    gotoxy(30,10);
    printf("2.ENTER AS A TEACHER");
    gotoxy(30,11);
    printf("3.ENTER AS REGISTRY");
    gotoxy(30,12);
    printf("4.EXIT");
    gotoxy(30,13);
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&choice1);
    switch(choice1)
    {
    case 1:
        system("cls");
        studentlogin();
        break;
    case 2:
        system("cls");
        teacherlogin();
        break;
    case 3:
        system("cls");
        registrylogin();
        break;
    case 4:
        exit(0);
    default:
        gotoxy(30,14);
        printf("INVALID CHOICE");
    _getch();
    }
    }
}
void main()
{

   printf("\n\n\n\n\n\n\n");
   printf("OOOOO   N    N   L       IIIII   N    N   EEEEE\n");
   printf("O   O   NN   N   L         I     NN   N   E    \n");
   printf("O   O   N N  N   L         I     N N  N   EEEEE\n");
   printf("O   O   N  N N   L         I     N  N N   E    \n");
   printf("OOOOO   N    N   LLLLL   IIIII   N    N   EEEEE ");
   printf("\n\n\t\t\t\t\t\t");
   printf("EEEEE   x   x   AAAAA   M   M\n");
   printf("\t\t\t\t\t\t");
   printf("E        x x    A   A   MM MM\n");
   printf("\t\t\t\t\t\t");
   printf("EEEEE     x     A A A   M M M\n");
   printf("\t\t\t\t\t\t");
   printf("E        x x    A   A   M   M\n");
   printf("\t\t\t\t\t\t");
   printf("EEEEE   x   x   A   A   M   M\n");
    printf("\n\n\t\t\t\t\t\t\t\t");
   printf("SSSSS   Y   Y   SSSSS   TTTTT   EEEEE   M     M");
   printf("\n\t\t\t\t\t\t\t\t");
   printf("S        Y Y    S         T     E       M M M M");
   printf("\n\t\t\t\t\t\t\t\t");
   printf("SSSSS     Y     SSSSS     T     EEEEE   M  M  M");
   printf("\n\t\t\t\t\t\t\t\t");
   printf("    S     Y         S     T     E       M     M");
   printf("\n\t\t\t\t\t\t\t\t");
   printf("SSSSS     Y     SSSSS     T     EEEEE   M     M");

   _getch();
    firstpage();

}
