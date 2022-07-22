
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
struct NALA_format
{
	char aadhar[15];
	char register_documents[5];
	char title_deeds[5];
	char basic_value_certificate_from_sub_registrar[5];
	char area_name[50];
    char survey_no[10];
    char plot_no[10];
}N[5];
struct temp1
{
	char aadhar1[15];
	char register_documents1[5];
	char title_deeds1[5];
	char basic_value_certificate_from_sub_registrar1[5];
	char area_name1[50];
    char survey_no1[10];
    char plot_no1[10];
	char vro_a1[2];
}N1[5];
struct tempx
{
	char aadhar2[15];
	char register_documents2[5];
	char title_deeds2[5];
	char basic_value_certificate_from_sub_registrar2[5];
	char area_name2[50];
    char survey_no2[10];
    char plot_no2[10];
	char vro_a2[10];
	char mro_a2[10];
}N2[5];
//extern x;
void NALA();
void VRO();
void MRO();
void backup();
void view_approved_applications();
void file_cpy(char *source_file,char *target_file)
{
	char ch;
	FILE *source,*target;
	source=fopen(source_file,"r");
	target=fopen(target_file,"a");
	if((source==NULL)||(target==NULL))
	{
		printf("error accessing database");
	}
	fprintf(target,"\n%s\n\n","############################################################");
	while((ch=fgetc(source))!=EOF)
	{
		fputc(ch,target);
	}
	fclose(source);
	fclose(target);
}
void file_copy(char *source_file,char *target_file)
{
	char ch;
	FILE *source,*target;
	source=fopen(source_file,"r");
	target=fopen(target_file,"a");
	if((source==NULL)||(target==NULL))
	{
		printf("error accessing database");
	}
	while((ch=fgetc(source))!=EOF)
	{
		fputc(ch,target);
	}
	fclose(source);
	fclose(target);
}
int main()
{
	int ser,usr;
    char username[15];
    char password[12];
	char temp,temp2;
	int designation;
	destin3:
		system("cls");
	printf("############################################################");
    printf("\n\n\t\t GOVTERNMENT OF TELANGANA \t\t\n\n");
    printf("\t\tWELCOME TO REVENUE PORTAL\t\t\n\n");
	printf("############################################################\n");
    printf("\n Whom you want to login as: \n");
    printf("1.Public\n2.Admin\n3.Exit\n\n\t");
    scanf("%d",&usr);
    system("cls");
    switch(usr)
    {
    	case 1:
        	printf("\n\nCurrently available services:\n\n");
        	printf("1.Nala conversion\n2.View approved applications\n3.<Back\n\n\t");
        	scanf("%d",&ser);
        	system("cls");
        	switch (ser)
        	{
            	case 1:
                	NALA();
					goto destin3;
            	case 2:
					view_approved_applications();
					fflush(stdin);
					scanf("%c",&temp);
					if(temp=='\n')
					{
						goto destin3;
					}
            	case 3:
                	goto destin3;
            	/*case 4:
                	printf("\nReidence certificate application successfully completed\n");*/
        	}    		
    	break;
    	case 2:
    		printf("Select Your Designation:\n");
        	printf("\n1.Village Revenue Officer\n2.Mandal Revenue Officer\n");
        	scanf("%d", &designation);
			destin2:
				system("cls");
			if(designation==1)
			{
				printf("Enter your username:\n");
            	scanf("%s", &username);
            	printf("Enter your password:\n");
            	scanf("%s", &password);
            	if (strcmp(username, "admin@vro") == 0)
            	{
                	if (strcmp(password, "123456") == 0)
                    {
						sleep(1);
                    	printf("\nWelcome VRO Sir.Login Success!");
                    	VRO();
                    	fflush(stdin);
						scanf("%c",&temp);
						if(temp=='\n')
						{
							goto destin3;
						}
                    }	
                    else
                    {
                        printf("\nwrong password\n");
						sleep(1);
						goto destin2;
                   	}
                }
			}
            else if(designation==2)
            {	
            	printf("Enter your username:\n");
            	scanf("%s", &username);
            	printf("Enter your password:\n");
            	scanf("%s", &password);
            	if (strcmp(username, "admin@mro") == 0)
            	{
                	if (strcmp(password, "456") == 0)
                    {
						sleep(1);
                    	printf("\nWelcome MRO Sir.Login Success!");
						MRO();
						fflush(stdin);
						scanf("%c",&temp2);
						if(temp2=='\n')
						{
							goto destin3;
						}
                    }	
                    else
                    {
                        printf("\nwrong password\n");
						sleep(1);
						goto destin2;
                   	}
                }
			}
    	break;
	}
	return 0;
}


void NALA()
{
	int f=0;
	char re_enter,ch,jkl;
	do
	{
		system("cls");
		printf("\t\t* * * NALA - Non-Agricultural Land Assesment * * *\n");
		printf("\nEnter the required details");
		destin1:
			fflush(stdin);
		printf("\nEnter your 12-digit aadhar number :\t");
		fflush(stdin);
		scanf("%s",&N[f].aadhar);
		printf("Area Name  :\t");
		fflush(stdin);
		gets(N[f].area_name);
		printf("Enter your plot survey number  :\t");
		fflush(stdin);
		scanf("%s",&N[f].survey_no);
		printf("Enter your plot number  :\t");
		fflush(stdin);
		scanf("%s",&N[f].plot_no);
		system("cls");
		printf("Entered information\n");
		printf("aadhar number : %s\nSurvey number : %s\nPlot number : %s\nArea Name : %s",N[f].aadhar,N[f].survey_no,N[f].plot_no,N[f].area_name);
		printf("\n\nDo you want to make any changes\tpress 'Y' for yes and 'N' for no\n");
		scanf("\n%c",&re_enter);
		if(re_enter=='y'||re_enter=='Y')
		{
			goto destin1;
		}
		else if(re_enter=='n'||re_enter=='N')
		{
			system("cls");
			printf("Have you submitted the following required douments\n\t\tpress 'Y' for yes and 'N' for no");
			printf("\n\t*ENTER CORRECTLY, NO CHANGES CAN BE MADE LATER");
			printf("\nRegister Documents  :\t");
			fflush(stdin);
			scanf("%s",&N[f].register_documents);
			printf("\nTitle Deeeds  :\t");
			fflush(stdin);
			scanf("%s",&N[f].title_deeds);
			printf("\nBasic value certificate from sub registrar  :\t");
			fflush(stdin);
			scanf("%s",&N[f].basic_value_certificate_from_sub_registrar);
		}
		FILE *fp;
		fp=fopen("NALA_application.txt","a");
		if(fp==NULL)
		{
			printf("application not created\n");
			exit(0);
		}
		fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",N[f].aadhar,N[f].survey_no,N[f].plot_no,N[f].register_documents,N[f].title_deeds,N[f].basic_value_certificate_from_sub_registrar,N[f].area_name);
		fclose(fp);
		printf("\nNala application processing\n");
		sleep(1);	
		system("cls");
		printf("Nala application processing..\n");
		sleep(1);	
		system("cls");
		printf("Nala application processing...#\n");
		sleep(1);
		system("cls");
		printf("Nala application processing....#\n");
		sleep(1);
		system("cls");	
		printf("Application submitted successfully.\n\t");
		sleep(1);
		system("cls");
		printf("Do you want to enter another application\n\t		(Y=yes  N=no)\n\t");
		fflush(stdin);
		scanf("%c",&jkl);
	}while((jkl=='y')||(jkl=='Y'));
}

void VRO()
{
	system("cls");
	int num_1,i,j,k,r=0;
	printf("1.View submitted applications\n2.Exit\n\n\t");
	scanf("%d",&num_1);
	
	if(num_1==1)
	{
		FILE *f = fopen("NALA_application.txt","r");
		if(f==NULL)
		{
			printf("application not created\n");
			exit(0);
		}
		for(i=0;i<5;i++)
		{
			fscanf(f,"%s",N1[i].aadhar1);
			fscanf(f,"%s",N1[i].survey_no1);
			fscanf(f,"%s",N1[i].plot_no1);
			fscanf(f,"%s",N1[i].register_documents1);
			fscanf(f,"%s",N1[i].title_deeds1);
			fscanf(f,"%s",N1[i].basic_value_certificate_from_sub_registrar1);
			fscanf(f,"%s",N1[i].area_name1);
		}
		fclose(f);
		/*for(k=0;k<5;++k)
		{
			if((strcmp(N1[j].register_documents1,"y") == 0)||(strcmp(N1[j].register_documents1,"n") == 0))
			{

			}
		}*/
		for(j=0;j<5;j++)
		{
			if((strcmp(N1[j].register_documents1,"y") == 0)||(strcmp(N1[j].register_documents1,"n") == 0))
			{
				printf("\n\n**Appliction:%d**\n",j+1);
				printf("\nAadhar : %s\nSubmitted documents\n		(Y=yes  N=no)\nRegister documents : %s\nTitle deeds : %s\nBasic value certificate : %s\nArea name : %s\nSurvey number : %s\nPlot number : %s\n\n\n",N1[j].aadhar1,N1[j].register_documents1,N1[j].title_deeds1,N1[j].basic_value_certificate_from_sub_registrar1,N1[j].area_name1,N1[j].survey_no1,N1[j].plot_no1);
				printf("\nApprove this application : ");
				scanf("%s",N1[j].vro_a1);
			}  
		}
		f=fopen("VRO_verified.txt","w");
		if(f==NULL)
		{
			printf("error accessing file\n");
			exit(0);
		}
		for(j=0;j<5;j++)
		{
			if(strcmp(N1[j].vro_a1,"y") == 0)
			{
				fprintf(f,"%s\n",N1[j].aadhar1);
				fprintf(f,"%s\n",N1[j].survey_no1);
				fprintf(f,"%s\n",N1[j].plot_no1);
				fprintf(f,"%s\n",N1[j].register_documents1);
				fprintf(f,"%s\n",N1[j].title_deeds1);
				fprintf(f,"%s\n",N1[j].basic_value_certificate_from_sub_registrar1);
				fprintf(f,"%s\n",N1[j].area_name1);
				fprintf(f,"%s\n",N1[j].vro_a1);
			}
		}
		fclose(f);
	}
}


void MRO()
{
	system("cls");
	int num_2,i,j,r=0;
	char src1[]={"NALA_application.txt"},src2[]={"VRO_verified.txt"},src3[]={"MRO_verified.txt"};
	char trgt1[]={"NALA_application_records.txt"},trgt2[]={"VRO_verified_records.txt"},trgt3[]={"MRO_verified_records.txt"},trgt4[]={"Approved_applications.txt"};
	printf("1.Approve NALA applications\n2.exit\n\n\t");
	scanf("%d",&num_2);
	if(num_2==1)
	{
		FILE *d = fopen("VRO_verified.txt","r");
		if(d==NULL)
		{
			printf("error accessing VRO file\n");
			exit(0);
		}
		for(i=0;i<5;i++)
		{
			fscanf(d,"%s",N2[i].aadhar2);
			fscanf(d,"%s",N2[i].survey_no2);
			fscanf(d,"%s",N2[i].plot_no2);
			fscanf(d,"%s",N2[i].register_documents2);
			fscanf(d,"%s",N2[i].title_deeds2);
			fscanf(d,"%s",N2[i].basic_value_certificate_from_sub_registrar2);
			fscanf(d,"%s",N2[i].area_name2);
			fscanf(d,"%s",N2[i].vro_a2);
		}
		fclose(d);
		for(j=0;j<5;j++)
		{
			if(strcmp(N2[j].vro_a2,"y") == 0)
			{
				r++;
			}
		}

		if(r==0)
		{
			system("cls");
			printf("\n\n\tNo applications pending for approval\n\t");
		}
		/*printf("\n\n\n\t\t\t%d",r);
		sleep(5);*/
		for(i=0;i<=r-1;++i)
		{
			printf("\n\n**Appliction:%d**\n",i+1);
			printf("\nAadhar : %s\nSubmitted documents\n		(Y=yes  N=no)\nRegister documents : %s\nTitle deeds : %s\nBasic value certificate : %s\nArea name : %s\nSurvey number : %s\nPlot number : %s\n\n\n",N2[i].aadhar2,N2[i].register_documents2,N2[i].title_deeds2,N2[i].basic_value_certificate_from_sub_registrar2,N2[i].area_name2,N2[i].survey_no2,N2[i].plot_no2);
			printf("\nApprove this application : ");
			scanf("%s",N2[i].mro_a2);
		}
		FILE *g;
		g=fopen("MRO_verified.txt","w");
		if(g==NULL)
		{
			printf("error accessing MRO file\n");
			exit(0);
		}
		for(j=0;j<5;j++)
		{
			if(strcmp(N2[j].mro_a2,"y") == 0)
			{
				fprintf(g,"%s\n",N2[j].aadhar2);
				fprintf(g,"%s\n",N2[j].survey_no2);
				fprintf(g,"%s\n",N2[j].plot_no2);
				fprintf(g,"%s\n",N2[j].register_documents2);
				fprintf(g,"%s\n",N2[j].title_deeds2);
				fprintf(g,"%s\n",N2[j].basic_value_certificate_from_sub_registrar2);
				fprintf(g,"%s\n",N2[j].area_name2);
				fprintf(g,"%s\n",N2[j].vro_a2);
				fprintf(g,"%s\n",N2[j].mro_a2);
			}
		}
		fclose(g);
		file_cpy(src1,trgt1);
		file_cpy(src2,trgt2);
		file_cpy(src3,trgt3);
		file_copy(src3,trgt4);
		backup();
	}
}
void backup()
{
	FILE *s;
	s=fopen("NALA_application.txt","w");
	fclose(s);
	s=fopen("VRO_verified.txt","w");
	fclose(s);
	s=fopen("MRO_verified.txt","w");
	fclose(s);
}
void view_approved_applications()
{
	int j,r=0,i;
	char ch;
	FILE *d = fopen("Approved_applications.txt","r");
	if(d==NULL)
	{
		printf("error accessing VRO file\n");
		exit(0);
	}
	for(i=0;i<5;i++)
	{
		fscanf(d,"%s",N2[i].aadhar2);
		fscanf(d,"%s",N2[i].survey_no2);
		fscanf(d,"%s",N2[i].plot_no2);
		fscanf(d,"%s",N2[i].register_documents2);
		fscanf(d,"%s",N2[i].title_deeds2);
		fscanf(d,"%s",N2[i].basic_value_certificate_from_sub_registrar2);
		fscanf(d,"%s",N2[i].area_name2);
		fscanf(d,"%s",N2[i].vro_a2);
		fscanf(d,"%s",N2[i].mro_a2);
	}
	fclose(d);
	for(j=0;j<30;j++)
	{
		if(strcmp(N2[j].mro_a2,"y") == 0)
		{
			r++;
		}
	}
	for(i=0;i<=r-1;++i)
	{
		printf("\n\n**Appliction:%d**\n",i+1);
		printf("\nAadhar : %s\nArea name : %s\nSurvey number : %s\nPlot number : %s\n\n\n",N2[i].aadhar2,N2[i].area_name2,N2[i].survey_no2,N2[i].plot_no2);
		printf("\nYour application has been approved\n");
	}
	d = fopen("Approved_applications.txt","w");
	fclose(d);
}


