/*
Nama : Dianna Priyanti
Tanggal : 31 Januari 2019 
Subjek : Sistem Pencatatan Penduduk 
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char ans=0; 
int ok;
int d, valid=0;
void selamatdatang(void);
void Title(void);
void MainMenu(void);
void login(void);
void Add_rec(void);
void func_list();
void cari(void);
void sunting(void);
void hapus(void);
void keluar(void);

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct pasien
{
	int umur;
	char jk;
	char namadepan[20];
	char namabelakang[20]; 
	char NIK[15];
	char Alamat[30];
	char Pekerjaan[30];
	char Agama[20];
	char Status[20];
};

struct pasien  p,temp_c;



main(void)
{
	
    selamatdatang();
	Title();
	login();
	
	
	

}

void selamatdatang(void) 
{
	
	printf("\n\t\t\t\t#\t  SELAMAT DATANG di:\t\t#");
	printf("\n\t\t\t\t#   SISTEM PENCATATAN PENDUDUK BALIGE   #");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();
	system("cls");
	
}

void Title(void)
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       SISTEM PENCATATAN PENDUDUK         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
void MainMenu(void)
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t\t1. Tambah Penduduk\n");
	printf("\n\t\t\t\t2. Daftar Penduduk\n");
	printf("\n\t\t\t\t3. Cari Penduduk\n");
	printf("\n\t\t\t\t4. Update Data penduduk\n");
	printf("\n\t\t\t\t5. Hapus Data Penduduk\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)
	{
	
	case 1:
	tambah();
    	break;
    case 2:
    	func_list();
    	break;
	case 3:
	cari();
    	break;
	case 4:
		sunting();
		break;
	case 5:
		hapus();
		break;
	case 6:
		keluar();
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();
	}
		
	
}
void keluar(void)
{
	system("cls");
	Title(); 
	printf("\n\n\n\n\n\t\t\tTerimakasih Sudah Berkunjung");
	getch();	
}
void login(void)
{
int e=0	;
char Username[15];
char Password[15];
char ori_user[25]="realana07";
char ori_pass[15]="diannapriyanti";

do
{
	printf("\n\n\n\n\t\t\t\tMasukkan Username dan Password");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&Username);
	
	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",&Password);
	
	if (strcmp(Username,ori_user)==0 && strcmp(Password,ori_pass)==0)
	{
		printf("\n\n\n\t\t\t\t\t...Login Berhasil...");
		
		
		getch();
		MainMenu();
		break;
	}
	else
	{
		printf("\n\t\t\tPassword Salah! Coba Lagi");
		e++;
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("You have cross the limit. You cannot login. :( :(");
	getch();
    keluar();
	}
 
system("cls");
}

void tambah(void)
{
	system("cls");
	Title();
	char ans;
	FILE*ek;
	ek=fopen("Record2.dat","a");
	printf("\n\n\t\t\tTambah Penduduk\n");
	A:
	printf("\n\t\t\tNama Depan: ");
	scanf("%s",p.namadepan);
	p.namadepan[0]=toupper(p.namadepan[0]);
	if(strlen(p.namadepan)>20||strlen(p.namadepan)<2)
	{
		printf("\n\t Gagal! Nama Depan Minimal 2 dan Maksimal 20 Karakter ");
		goto A;
	}
	else
	{
		for (d=0;d <strlen(p.namadepan);d++)
		{
			if (isalpha(p.namadepan[d]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Nama Depan Tidak Valid! Coba lagi :");
			goto A;
		}
	}
	B:
	printf("\n\t\t\tNama Belakang: ");
    scanf("%s",p.namabelakang);
    p.namabelakang[0]=toupper(p.namabelakang[0]);
    if(strlen(p.namabelakang)>20||strlen(p.namabelakang)<2)
	{
		printf("\n\t Invalid :( \t  Gagal! Nama Belakang Minimal 2 dan Maksimal 20 Karakter");
		goto B;
	}
	else
	{
		for (d=0;d<strlen(p.namabelakang);d++)
		{
			if (isalpha(p.namabelakang[d]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Nama Belakang Tidak Valid! Coba lagi :");
			goto B;
		}
	}
	do
	{
	    printf("\n\t\t\tJenis Kelamin[F/M]: ");
		scanf(" %c",&p.jk);
		if(toupper(p.jk)=='M'|| toupper(p.jk)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Pilih F Atau M");
    	}
	 }	while(!ok);
    printf("\n\t\t\tUmur:");
    scanf(" %i",&p.umur);
    do
    {
    C:
    printf("\n\t\t\tAlamat(Gunakan _ Sebagai Spasi) : ");
    scanf("%s",p.Alamat);
    p.Alamat[0]=toupper(p.Alamat[0]);
    if(strlen(p.Alamat)>30||strlen(p.Alamat)<2)
	{
		printf("\n\t");
		goto C;
	}
	
}while(!valid);
do
{
	D:
    printf("\n\t\t\tNIK: ");
    scanf("%s",p.NIK);
    if(strlen(p.NIK)>10||strlen(p.NIK)!=10)
	{
		printf("\n\t Maaf! NIK Harus 10 Digit");
		goto D;
	}
	else
	{
		for (d=0;d<strlen(p.NIK);d++)
		{
			if (!isalpha(p.NIK[d]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t NIK Harus Berupa NOMOR");
			goto D;
		}
	}
}while(!valid);
do
{
    printf("\n\t\t\tPekerjaan: ");
    scanf("%s",p.Pekerjaan);
    if (strlen(p.Pekerjaan)>30||strlen(p.Pekerjaan)<2)
    {
       printf("\n\t Gagal! pekerjaan Minimal 2 karakter");	
	}
}while(strlen(p.Pekerjaan)>30||strlen(p.Pekerjaan)<2);
    E:
    printf("\n\t\t\tStatus: ");
    scanf("%s",p.Status);
    p.Status[0]=toupper(p.Status[0]);
    if(strlen(p.Status)>15||strlen(p.Status)<3)
	{
		printf("\n\t Gagal! pekerjaan Minimal 2 karakter");
		goto E;
	}
	else
	{
		for (d=0;d<strlen(p.Status);d++)
		{
			if (isalpha(p.Status[d]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Status Memuat Karakter yang Salah");
			goto E;
		}
	}
	F:
    printf("\n\t\t\tAgama:");
    scanf("%s",p.Agama);
    p.Agama[0]=toupper(p.Agama[0]);
    if(strlen(p.Agama)>30||strlen(p.Agama)<3)
	{
		printf("\n\t Agama Minimal 5 Karakter");
		goto F;
	}
	else
	{
		for (d=0;d<strlen(p.Agama);d++)
		{
			if (isalpha(p.Agama[d]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Input Karakter Yang Sesuai");
			goto F;
		}
	}
    
    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, p.jk, p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama);
    printf("\n\n\t\t\t.... Penduduk Berhasil Didaftarkan ...");
    fclose(ek);
    sd:
    getch();
    printf("\n\n\t\t\tApakah Anda Ingin Menambah Lagi[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	tambah();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\tTerimaksih");
    	getch();
    	MainMenu();
	}
    else
    {
        printf("\n\t\tPilih Y untuk iya dan N untuk Tidak\n");
        goto sd;
    }
}
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t\t\t\tDaftar Penduduk\n");
	gotoxy(1,15);
		printf("Nama Lengkap");
		gotoxy(20,15);
		printf("J.Kelamin");
		gotoxy(32,15);
		printf("Umur");
		gotoxy(37,15);
		printf("Alamat");
		gotoxy(49,15);
		printf("NIK");
		gotoxy(64,15);
		printf("Pekerjaan");
		gotoxy(88,15);
		printf("Status");
		gotoxy(98,15);
		printf("Agama\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, 
					&p.jk, &p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.namadepan, p.namabelakang);
			gotoxy(20,row);
			printf("%c",p.jk);
			gotoxy(32,row);
			printf("%i",p.umur);
			gotoxy(37,row);
			printf("%s",p.Alamat);
			gotoxy(49,row);
			printf("%s",p.NIK);
			gotoxy(64,row);
			printf("%s",p.Pekerjaan);
			gotoxy(88,row);
			printf("%s",p.Status);
			gotoxy(98,row);
			printf("%s",p.Agama);
			row++;
		}
		fclose(ek);
		getch();
		MainMenu();
}
void cari(void)
{
	char name[20];
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\tCari Penduduk\n");
	gotoxy(12,8);
	printf("\n Cari Nama Penduduk Yang ingin dicari : ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, &p.jk, &p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama)!=EOF)
	{
		if(strcmp(p.namadepan,name)==0)
		{
			gotoxy(1,15);
			printf("Nama Lengkap");
			gotoxy(25,15);
			printf("J.Kelamin");
			gotoxy(32,15);
			printf("Umur");
			gotoxy(37,15);
			printf("Alamat");
			gotoxy(52,15);
			printf("NIK");
			gotoxy(64,15);
			printf("Pekerjaan");
			gotoxy(80,15);
			printf("Status");
			gotoxy(95,15);
			printf("Agama\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.namadepan, p.namabelakang);
			gotoxy(25,18);
			printf("%c",p.jk);
			gotoxy(32,18);
			printf("%i",p.umur);
			gotoxy(37,18);
			printf("%s",p.Alamat);
			gotoxy(52,18);
			printf("%s",p.NIK);
			gotoxy(64,18);
			printf("%s",p.Pekerjaan);
			gotoxy(80,18);
			printf("%s",p.Status);
			gotoxy(95,18);
			printf("%s",p.Agama);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.namadepan,name)!=0)
	   {
		gotoxy(5,10);
		printf("Tidak Ditemukan");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tAnda Ingin Mencari Yang Lain[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        cari();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\tTerimakasih");
    	getch();
		MainMenu();
    }
	else
    {
    	printf("\n\tPilihan Salah\n");
    	goto L;
    }
}

void sunting(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("Record2.dat","r");
	   if(ek==NULL)
	   {
		printf("\n\t Tidak Bisa Dibuka ");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\tUpdate Data Penduduk\n");
	   	gotoxy(12,13);
	   	printf("Masukkan Nama Depan Penduduk: ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MainMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, &p.jk, &p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama)!=EOF)
		{
			if(strcmp(p.namadepan, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Penduduk Ditemukan ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.namadepan,p.namabelakang,p.jk, p.umur,p.Alamat,p.NIK,p.Pekerjaan,p.Status,p.Agama);
				gotoxy(12,22);	
				printf("Masukkan Nama Depan Baru: ");
				scanf("%s",p.namadepan);    
				gotoxy(12,24);
				printf("Nama Belakang: ");
				scanf("%s",p.namabelakang);
				gotoxy(12,26);
				printf("Jenis Kelamin: ");
				scanf(" %c",&p.jk);
				p.jk=toupper(p.jk);
				gotoxy(12,28);
				printf("Umur:");
				scanf(" %i",&p.umur);
				gotoxy(12,30);
				printf("Alamat: ");
				scanf("%s",p.Alamat);
				p.Alamat[0]=toupper(p.Alamat[0]);
				gotoxy(12,32);
				printf("NIK: ");
				scanf("%s",p.NIK);
				gotoxy(12,34);
				printf("Pekerjaan: ");
				scanf("%s",p.Pekerjaan);
			    gotoxy(12,36);
				printf("Enter Status: ");
				scanf("%s",p.Status);
				p.Status[0]=toupper(p.Status[0]);
			    gotoxy(12,38);
				printf("Agama: ");
			    scanf("%s",p.Agama);
			    p.Agama[0]=toupper(p.Agama[0]);
			    printf("\nTekan U untuk Update Data");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.namadepan,p.namabelakang,p.jk, p.umur,p.Alamat,p.NIK,p.Pekerjaan,p.Status,p.Agama);
				printf("\n\n\t\t\tData Penduduk Berhasil diupdate");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.namadepan,p.namabelakang,p.jk, p.umur,p.Alamat,p.NIK,p.Pekerjaan,p.Status,p.Agama);	
			}
		 }
		 if(!valid) printf("\n\t\tPenduduk Tidak Ditemukan");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.dat");
   	   rename("temp2.dat","Record2.dat");
		getch();
		MainMenu();		
}
void hapus()
{
	char name[20];
	int found=0;
	system("cls");
	Title();
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\tHapus Data Penduduk\n");
	gotoxy(12,8);
	printf("\n Masukkan Nama Penduduk Yang Akan dihapus :");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.namadepan, p.namabelakang, &p.jk,
			 &p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama)!=EOF)
	{
		if (strcmp(p.namadepan,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, p.jk, p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama);
		else 
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.namadepan, p.namabelakang, p.jk, p.umur, p.Alamat, p.NIK, p.Pekerjaan, p.Status, p.Agama);
			found=1;
		}
	}
	if(found==0)
	{
		printf("\n\n\t\t\tPenduduk Tidak Ditemukan");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\tPenduduk Berhasil diHapus");
		getch();
		MainMenu();
	}
} 

