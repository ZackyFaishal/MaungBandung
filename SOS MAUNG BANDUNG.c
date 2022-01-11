///////////////////
//   GAME SOS   //
//////////////////

/*Oleh :
DHAFIN RIZQI FADILAH
MAOLANA FIRMANSYAH
ZACKY FAISHAL ABROR
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
/////////////////////////
///*Modul utama utama*///
////////////////////////
void menuAwal();//Menu di awal permainan untuk memilih apakah ingin main atau cara bermain, atau keluar
void pilihLawan();//modul untuk memilih lawan permainan
void pilihLevel();//modul untuk memilih level dari komputer
void CaraBermain();//untuk menampilkan file cara bermain
void keluar();//modul untuk menampilkan tampilan keluar jika pemain memilih untuk keluar permainan
void gambarPapan(); // Untuk membuat dan menampilkan papan permainan 
void pilihPapan();//Modul untuk memilih papan
void pertanyaan();//untuk memberikan pertanyaan perhitungan bagi pemain (kecuali komputer)
int jawaban,hasil;//untuk menyimpan hasil jawaban dari sistem dan pemain
void tampilanAkhir();//modul yang berguna untuk menampilkan hasil akhir program
void tampilanAkhirVkom();//modul yang berguna untuk menampilkan hasil akhir program melawan komputer
/*waktu*/
int waktuAwal();//mendeklarasikan waktu awal penginputan
int waktuAkhir();//modul untuk mendeklarasikan waktu akhir 

/////////////////////////
///*  Modul Bermain *///
////////////////////////
void papanSkor(); // Untuk menampilkan score permainan
int cariSOS(); // Untuk menghitung score disaat SOS sudah terbentuk
void boardspace();//untuk menyimpan hasil pilihan pemain
int cekPapanPenuh();//untuk mengecek apakah papan sudah terisi penuh atau belum
/*VARIABEL GLOBAL*/
int baris;//untuk mereset hasil baris dari inputan pemain
int kolom; //untuk mereset hasil kolom dari inputan pemain
int level;//untuk menyimpan hasil pilihan level dari pemain
int ukuranPapan;//untuk menyimpan hasil ukuran papan dari pemain
int cariSOS();//modul untuk mencari hasil SOS dari sebuah papan permainan
char papan[15][15]; // Untuk tempat meyimpan Huruf S dan O saat diinputkan pemain
int poin[3] = {0,0}; // Untuk tempat meyimpan score
int counter = 1; // round counter
int baris, kolom; // untuk menyimpan baris dan kolom yang dipilih pemain
int pemainMain = 0; // untuk menampilkan nama pemain yang diinputkan
char nama[2][10]; // Untuk tempat menyimpan nama
int hasilPapan; //untuk menyimpan hasil dari pemilihan papan
int poinKom =0 ;//poin untuk komputer
char komputer[10]="MAUNG";//variabel untuk memasukan nama dari komputer yaitu 'maung'

/////////////////////////////////////
/*MODUL UNTUK BERMAIN LAWAN MANUSIA*/
/////////////////////////////////////
void mainVman();// modul untuk bermain melawan manusia
void inputNamaVman(); // Untuk menginputkan nama pemain
int inputHurufVman(); // untuk menginputkan S atau O ke papan


/////////////////////////////////////
////*MODUL UNTUK LAWAN KOMPUTER*/////
////////////////////////////////////
void mainVKom();//modul untuk bermain melawan komputer
int inputHurufVkom();//modul untuk mengisi huruf dalam papan saat melawan komputer
int cekS_S_wanieun();//modul ini berguna untuk mengecek papan apakah ada S dan S dan akan diisi dengan huruf O untuk level sulit
int cekS_S_nyantuy();//modul ini berguna untuk mengecek papan apakah ada S dan S dan akan diisi dengan huruf O untuk level mudah
int cekS_S_jengatJengat();//modul ini berguna untuk mengecek papan apakah ada S dan S dan akan diisi dengan huruf O untuk level sedang
int cekOS_wanieun();//modul ini berguna untuk mengecek apakah ada huruf S dan O dan akan ditambah dengan huruf S di depannya, untuk level sulit
int cekOS_nyantuy();//modul ini berguna untuk mengecek apakah ada huruf S dan O dan akan ditambah dengan huruf S di depannya, untuk level mudah
int cekOS_jengatJengat();//modul ini berguna untuk mengecek apakah ada huruf S dan O dan akan ditambah dengan huruf S di depannya, untuk level sedang
int cekKosong();//modul untuk mengecek apakah isi dari papan kosong atau tidak
void inputNamaVkom();//modul untuk menginput nama ketika melawan komputer
int gameSelesai();//modul untuk mengecek apakah permainan telah usai atau belum
void papanSkorVkom();//modul untuk menampilkan hasil papan skor ketika melawan komputer
int cariPosisi();//untuk mencari posisi suatu inputan
int cariSOSVKom(int,char);
void hasilLevel();//untuk memberikan inpute berupa dari hasil level yang dipilih oleh pemain
/*leveling*/
void wanieun();//modul untuk level wanieun (hard)
void jengatJengat();//modul untuk level jengat jengat (Medium)
void nyantuy();// modul untuk level nyantuy (easy)
char acakHuruf();//untuk merandom huruf s atau o

void pertanyaan(){
	int a,b;
	int operasi;
	operasi = rand() % 3;
	a = rand() % 21;
	b = rand() % 21;
	printf("\n\n\xc Giliran: %s\n", nama[pemainMain]);
	printf("Jawablah pertanyaan berikut: \n");
	if (operasi == 0){
		hasil = a + b;
		printf("%d + %d = \nJawaban:",a,b);
	}
	else if (operasi == 1){
		hasil = a - b;
		printf("%d - %d = \nJawaban:",a,b);
		}
		if (operasi == 2){
		hasil = a * b;
		printf("%d X %d = \nJawaban:",a,b);
	}
}

void CaraBermain(){
	int kembali;
 FILE*the_file = fopen("caraBermain.txt", "r");
 if(the_file == NULL){
  perror("tidak ada file");
  exit(1);
 }
 
 char line[100];
 while(fgets(line, sizeof(line), the_file)){
  printf("%s", line);
 }
 printf("\t\t Masukkan Pilihanmu: "); scanf("%d",&kembali);
    switch(kembali){
   		case 1:
   			menuAwal();
   			break;
}
}

void gotoxy(int x, int y){
	//untuk menuliskan koordunat di layar
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int waktuAwal(){
    clock_t t;
    t = clock();
    return t;
}
int waktuAkhir(){
    clock_t t;
    t = clock();
    return t;
}

void boardSpace(){
	for (int i = 0; i < hasilPapan; i++)
		for (int j = 0; j < hasilPapan; j++)
			papan[i][j] = ' ';
}

char acakHuruf(){
    char huruf;
    int angka;
    angka=rand()%2;
    if(angka==1){
        huruf='S';
    }else{
        huruf='O';
    }
    return huruf;
}

int main() {
	menuAwal();
	
	return 0;
}

// menu awal program
void menuAwal()
{	system("cls");
	int pilMenu;
	system("color F1");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3   $$$$$$$$$     $$$$$$$$$      $$$$$$$$                                             \xb3\n");
	printf("\t\t\xb3  $$           $$         $$   $$                                                    \xb3\n");
	printf("\t\t\xb3  $$           $$         $$   $$                                                    \xb3\n");
	printf("\t\t\xb3   $$$$$$$     $$         $$    $$$$$$$$                                             \xb3\n");
	printf("\t\t\xb3          $$   $$         $$           $$                                            \xb3\n");
	printf("\t\t\xb3          $$   $$         $$           $$                                            \xb3\n");
	printf("\t\t\xb3  $$$$$$$$$      $$$$$$$$$     $$$$$$$$$                                             \xb3\n");
    printf("\t\t\xb3                                                               MAUNG BANDUNG         \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3    [1]MAIN        [2]CARA BERMAIN        [3]EXIT                                    \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
printf("\t MASUKAN PILIHANMU :"); scanf("%d",&pilMenu);
switch(pilMenu){
   		case 1:
   			pilihLawan();
   			break;
        case 2:
        	system("cls");
   			CaraBermain();
			
   			break;
		case 3:
   			keluar();	
   			break;	
   		default:
   			printf("\t\t\t\t\xaf\xaf\xaf PILIHANMU TIDAK TEPAT, COBA MASUKAN KEMBALI!!!");
      		getch();
      		menuAwal();
		}
}

void pilihLawan(){
	system("cls");
int lawan;
	system("color F1");
	printf("\n\n\n\n\n\n\n");
printf("\t\t _____________________________________________________________________\n                \xb3                                                                     \xb3\n");
printf("\t\t\xb3\t$$        $$$$$    $$           $$     $$$$$     $$$$   $$    \xb3\n");
printf("\t\t\xb3\t$$       $$   $$   $$           $$    $$   $$    $$ $$  $$    \xb3\n");
printf("\t\t\xb3\t$$      $$     $$  $$    $$$$   $$   $$     $$   $$  $$ $$    \xb3\n");
printf("\t\t\xb3\t$$      $$$$$$$$$    $$  $$$$  $$    $$$$$$$$$   $$   $$$$    \xb3\n");
printf("\t\t\xb3\t$$$$$$  $$     $$     $$$   $$$      $$     $$   $$     $$    \xb3\n                \xb3                                                                     \xb3\n");
printf("\t\t\xb3\t\t\t\t               SOS MAUNG BANDUNG      \xb3\n");
printf("\t\t\xb3    [1]LAWAN KOMPUTER [2] LAWAN MANUSIA                              \xb3\n");
printf("\t\t\xb3_____________________________________________________________________\xb3\n\n");
printf("\t MASUKAN PILIHANMU :"); scanf("%d",&lawan);
switch(lawan){
   		case 1:
   			pilihLevel();
   			break;
        case 2:
   			mainVman();
   			break;
   		default:
   			printf("\t\t\t\t\xaf\xaf\xaf PILIHANMU TIDAK TEPAT, COBA MASUKAN KEMBALI!!!");
      		system("pause");
      		pilihLawan();
   		}
}

void pilihLevel(){
	system("cls");
	system("color F1");
   	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$        $$$$$$$$$  $$$            $$$  $$$$$$$$$  $$$                           \xb3\n");
	printf("\t\t\xb3  $$$        $$$         $$$          $$$   $$$        $$$                           \xb3\n");
	printf("\t\t\xb3  $$$        $$$          $$$        $$$    $$$        $$$                           \xb3\n");
	printf("\t\t\xb3  $$$        $$$$$$$$$     $$$      $$$     $$$$$$$$$  $$$                           \xb3\n");
	printf("\t\t\xb3  $$$        $$$            $$$    $$$      $$$        $$$                           \xb3\n");
	printf("\t\t\xb3  $$$        $$$             $$$  $$$       $$$        $$$                           \xb3\n");
	printf("\t\t\xb3  $$$$$$$$$  $$$$$$$$$        $$$$$$        $$$$$$$$$  $$$$$$$$$                     \xb3\n");
    printf("\t\t\xb3                                                               MAUNG BANDUNG         \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3    [1] Nyantui(Mudah)        [2] Jengat-jengat(Sedang)        [3]Wanieun(Sulit)     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t MASUKAN PILIHANMU :"); scanf("%d",&level);
	switch(level){
   		case 1:
   			mainVKom();
   			break;
        case 2:
        	mainVKom();
   			break;
   		case 3:
   			mainVKom();
   			break;
   		default:
   			printf("\t\t\t\t\xaf\xaf\xaf PILIHANMU TIDAK TEPAT, COBA MASUKAN KEMBALI!!!");
      		system("pause");
      		pilihLevel();
   		}
}

void hasilLevel(){
	switch(level){
   		case 1:
   			nyantuy();
   			break;
        case 2:
   			jengatJengat();	
   			break;
   		case 3:
   			wanieun();	
   			break;
   		default:
   			printf("\t\t\t\t\xaf\xaf\xaf PILIHANMU TIDAK TEPAT, COBA MASUKAN KEMBALI!!!");
      		system("pause");
      		pilihLevel();
   		}
	
}

void pilihPapan(){

    int ukuran;
	system("cls");
	system("color F1");
   	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3   $$$$$$$   $$$$$$$   $$$$$$$$    $$$$$$$   $$$$   $$                               \xb3\n");
	printf("\t\t\xb3  $$$   $$$ $$$$$$$$$  $$$   $$$  $$$$$$$$$  $$ $$  $$                               \xb3\n");
	printf("\t\t\xb3  $$     $$ $$$   $$$  $$     $$  $$$   $$$  $$  $$ $$                               \xb3\n");
	printf("\t\t\xb3  $$$$$$$$$ $$$$$$$$$  $$$$$$$$$  $$$$$$$$$  $$  $$ $$                               \xb3\n");
	printf("\t\t\xb3  $$$       $$$$$$$$$  $$$        $$$$$$$$$  $$   $$$$                               \xb3\n");
	printf("\t\t\xb3  $$$       $$$   $$$  $$$        $$$   $$$  $$   $$$$                               \xb3\n");
	printf("\t\t\xb3  $$$       $$$   $$$  $$$        $$$   $$$  $$     $$                               \xb3\n");
    printf("\t\t\xb3                                                      MAUNG BANDUNG                  \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3        [1] (5x5)        [2] (7x7)        [3](9x9)                                   \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Masukkan Pilihanmu: "); scanf("%d",&ukuran);
	system("cls");
	switch(ukuran){
		case 1:
			hasilPapan=5;
			break;
		case 2:
			hasilPapan=7;
			break;
		case 3:
			hasilPapan=9;
			break;
		default:
			printf("\t\t\t\t\xaf\xaf\xaf PILIHANMU TIDAK TEPAT, COBA MASUKAN KEMBALI!!!");
      		system("pause");
      		pilihPapan();
	}
}

void keluar(){
	system("cls");
	system("color f1");
	int pilih;
	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$$$$$      $$$$$$$   $$$$$$$      $$$$$$$   $$$     $$$                          \xb3\n");
	printf("\t\t\xb3  $$$   $$$   $$$$$$$$$  $$$   $$$   $$$$$$$$$  $$$     $$$                          \xb3\n");
	printf("\t\t\xb3  $$$     $$  $$$   $$$  $$$     $$  $$$   $$$  $$$     $$$                          \xb3\n");
	printf("\t\t\xb3  $$$     $$  $$$$$$$$$  $$$     $$  $$$$$$$$$  $$$$$$$$$$$                          \xb3\n");
	printf("\t\t\xb3  $$$     $$  $$$$$$$$$  $$$     $$  $$$$$$$$$  $$$$$$$$$$$                          \xb3\n");
	printf("\t\t\xb3  $$$   $$$   $$$   $$$  $$$   $$$   $$$   $$$  $$$     $$$                          \xb3\n");
	printf("\t\t\xb3  $$$$$$$     $$$   $$$  $$$$$$$     $$$   $$$  $$$     $$$                          \xb3\n");
    printf("\t\t\xb3                                                     (SOS MAUNG BANDUNG)             \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3        KETIK 1 UNTUK KEMBALI KE MENU AWAL                                           \xb3\n");
    printf("\t\t\xb3        KETIK SEMBARANG LALU ENTER 2 KALI UNTUK KELUAR                               \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Masukkan Pilihanmu: "); scanf("%d",&pilih);
    switch(pilih){
   		case 1:system("pause");
   			menuAwal();
   		}
}

void tampilanAkhir(){
		system("cls");
    	system("color F1");
		int pilihanAkhir;
		printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
    printf("\t\t\xb3  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3                             BERMAIN KEMBALI PILIH 1                                 \xb3\n");
    printf("\t\t\xb3                              KELUAR KETIK APA SAJA                                  \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    gotoxy(43,4);
	printf("\xaf\xaf Permainan selesai!!!! \xae\xae\n\n");
	gotoxy(43,7);
	if (poin[0] > poin[1]) printf("\xdb\xaf %s MENANG DENGAN %d POIN!!!! \xae\xdb\n\n", nama[0], poin[0]);
	else if (poin[0] < poin[1]) printf("\xdb\xaf %s MENANG DENGAN %d POIN!!!! \xae\xdb\n\n", nama[1], poin[1]);
	else printf("\xaf\xaf PERMAINAN SERI \xae\xae\n\n");
	poin[pemainMain]=0;	
	gotoxy(17,15);
	printf("Masukan pilihanmu : ");scanf("%d",&pilihanAkhir);
	switch(pilihanAkhir){
		case 1:
			menuAwal();
			break;
		default:
			keluar();
			break;
	system("pause");
}
}

void tampilanAkhirVkom(){
		system("cls");
    	system("color F1");
		int pilihanAkhir;
		printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
	printf("\t\t\xb3  $$                                                                          $$     \xb3\n");
    printf("\t\t\xb3  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3                             BERMAIN KEMBALI PILIH 1                                 \xb3\n");
    printf("\t\t\xb3                              KELUAR KETIK APA SAJA                                  \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    gotoxy(43,4);
	printf("\xaf\xaf Permainan selesai!!!! \xae\xae\n\n");
	gotoxy(43,7);
	if (poin[0] > poin[2]) printf("\xdb\xaf %s MENANG DENGAN %d POIN!!!! \xae\xdb\n\n", nama[0], poin[0]);
	else if (poin[0] < poin[2]) printf("\xdb\xaf MAUNG MENANG DENGAN %d POIN!!!! \xae\xdb\n\n", poin[2]);
	else printf("\xaf\xaf PERMAINAN SERI \xae\xae\n\n");
	poin[pemainMain]=0;	
	gotoxy(17,15);
	printf("Masukan pilihanmu : ");scanf("%d",&pilihanAkhir);
	switch(pilihanAkhir){
		case 1:
			menuAwal();
			break;
		default:
			keluar();
			break;
	system("pause");
}
}


//****************//
// MAIN VS MANUSIA//
//****************//
void mainVman(){
	inputNamaVman();
	pilihPapan();
	boardSpace();
	while (!cekPapanPenuh()) {
		system("cls");
		baris= 0; kolom = 0;
		papanSkor();
		gambarPapan();
		
		int input = inputHurufVman();
		if (input) {
			int point = cariSOS();
			if (!point) {
				printf("\n\xaf\xaf Kamu belum mendapatkan poin.");
				getch();
				pemainMain = (pemainMain + 1) % 2;
			}
			else {
				poin[pemainMain] = poin[pemainMain] + 1;
				printf("\xaf\xaf\xaf Kamu mendapatkan 1 poin. Silakan bermain kembali");
				getch();
			}
			counter++;
		}
	}
	tampilanAkhir();
}
void inputNamaVman() {
	system("cls");
	system("color F1");
   	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$$$    $$$   $$$$$$$   $$$$       $$$$   $$$$$$$                                 \xb3\n");
	printf("\t\t\xb3  $$$$$$   $$$  $$$$$$$$$  $$$$$     $$$$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$ $$$  $$$  $$$   $$$  $$$ $$$ $$$ $$$  $$$   $$$                                \xb3\n");
	printf("\t\t\xb3  $$$  $$$ $$$  $$$$$$$$$  $$$  $$$$   $$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$   $$$$$$  $$$$$$$$$  $$$         $$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$    $$$$$  $$$   $$$  $$$         $$$  $$$   $$$                                \xb3\n");
	printf("\t\t\xb3  $$$     $$$$  $$$   $$$  $$$         $$$  $$$   $$$                                \xb3\n");
    printf("\t\t\xb3                                                       SOS MAUNG BANDUNG             \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3    PEMAIN 1                                                                         \xb3\n");
    printf("\t\t\xb3    PEMAIN 2                                                                         \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Pemain 1: "); scanf("%s",&nama[0][0]);
    printf("\t\t Pemain 2: "); scanf("%s",&nama[1][0]);
}


void papanSkor() {
	gotoxy(0,0);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,194,196,194,196,196,196,196,196,196,196,196,196,191);
	printf("\n\xb3        \xb3:\xb3         \xb3\n");
	printf("\xb3        \xb3:\xb3         \xb3");
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,193,196,193,196,196,196,196,196,196,196,196,196,217);
	gotoxy(2,1);printf("%s\n", nama[0]);
    gotoxy(13,1);printf("%s\n", nama[1]);
    gotoxy(2,2);printf("%d\n\n", poin[0]);
    gotoxy(13,2);printf("%d\n\n", poin[1]);
}

void gambarPapan() {
	system ("color F1");
	int i, j;
	printf("\n   ");
	for (i = 0; i <= hasilPapan; i++) {
		printf("\n   ");
		for (j = 0; j <= hasilPapan; j++) {
			if (!i && !j) printf("      ");
			else if (!i && j == hasilPapan) printf("   %2d  ", j);
			else if (!i) printf("  %2d  ", j);
			else if (!j) printf("  %2d  \xb3", i);
			else if (baris && kolom && baris == i && kolom == j) printf("     \xb3");
			else printf("  %c  \xb3", papan[i - 1][j - 1]);
		}
		printf("   \n   ");
		for (j = 0; j <= hasilPapan; j++) {
			if (i == hasilPapan && !j) printf("      ");
			else if (i == hasilPapan) printf("\xc1\xcd\xcd\xcd\xcd\xcd");
			else if (!j) printf("      ");
			else printf("\xc5\xcd\xcd\xcd\xcd\xcd");
			if (i == hasilPapan && j == hasilPapan) printf("\xd9");
			else if (j == hasilPapan) printf("\xb4");
		}
	}
	printf("\n");
}

int inputHurufVman() {
	int waktu;
	double waktuIsi;
	waktu = waktuAwal();
	pertanyaan();
	scanf("%d",&jawaban);
	if (jawaban==hasil){
		printf("Jawabanmu benar! Lanjutkan pilihanmu!");
		do {
		fflush(stdin);
		printf("\n\n\xdb Baris: ");
		scanf("%d", &baris);
		printf("\xdb Kolom: ");
		scanf("%d", &kolom);
		printf("\n  POSISI SALAH!!!\n \xaf TEKAN ENTER UNTUK MELANJUTKAN!!");
	}while(!(baris > 0 && baris <= hasilPapan && kolom > 0 && kolom <= hasilPapan));
	
	system("cls");
	switch (papan[baris - 1][kolom - 1]) {
	case 'S':	
	case 'O':   printf("\xaf\xaf POSISI SUDAH DIISI !!!\n\xaf\xaf TEKAN ENTER UNTUK MELANJUTKAN!");
		getch();
		return 0;
		default:    
		system("cls");
		papanSkor();
		gambarPapan();		
		waktu=waktuAkhir()-waktu;
		waktuIsi=((double)waktu)/CLOCKS_PER_SEC;
		if (waktuIsi<=15){
			printf("\n\n\xc Giliran: %s\n\xdb Baris: %d\n\xdb Kolom: %d\n\xaf\xaf S/O? ", nama[pemainMain], baris, kolom);
			char ch;
			scanf(" %c", &ch);
			switch (ch) {
			case 's':
			case 'S': papan[baris - 1][kolom - 1] = 'S'; return 1;
			case 'o':
			case 'O': papan[baris - 1][kolom - 1] = 'O'; return 1;
			}
			printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Press any key to continue!!");
			getch();
			return 0;	
		}
		else{
		papanSkor();
		gambarPapan();
		printf("\n WAKTU HABIS, GANTI GILIRAN!!!");
		pemainMain = (pemainMain + 1) % 2;
		getch();
		return 0;
		}
	}
	}else{
		printf("JAWABANMU SALAH, GANTI GILIRAN!!!");
	}
}

int cariSOS(){
	if (papan[baris - 1][kolom - 1] == 'S') {
		if (papan[baris - 3][kolom - 3] == 'S' && papan[baris - 2][kolom - 2] == 'O') return 1;
		if (papan[baris - 3][kolom - 1] == 'S' && papan[baris - 2][kolom - 1] == 'O') return 1;
		if (papan[baris - 3][kolom + 1] == 'S' && papan[baris - 2][kolom] == 'O') return 1;
		if (papan[baris - 1][kolom - 3] == 'S' && papan[baris - 1][kolom - 2] == 'O') return 1;
		if (papan[baris - 1][kolom + 1] == 'S' && papan[baris - 1][kolom] == 'O') return 1;
		if (papan[baris + 1][kolom - 3] == 'S' && papan[baris][kolom - 2] == 'O') return 1;
		if (papan[baris + 1][kolom - 1] == 'S' && papan[baris][kolom - 1] == 'O') return 1;
		if (papan[baris + 1][kolom + 1] == 'S' && papan[baris][kolom] == 'O') return 1;
	}
	else {
		if (papan[baris - 2][kolom - 2] == 'S' && papan[baris][kolom] == 'S') return 1;
		if (papan[baris - 2][kolom - 1] == 'S' && papan[baris][kolom - 1] == 'S') return 1;
		if (papan[baris - 2][kolom] == 'S' && papan[baris][kolom - 2] == 'S') return 1;
		if (papan[baris - 1][kolom - 2] == 'S' && papan[baris - 1][kolom] == 'S') return 1;
	}
	return 0;
}


/**********************
PERMAINAN MELAWAN KOMPUTER
************************/

void mainVKom(){
	pemainMain=0;
	inputNamaVkom();
	pilihPapan();
	boardSpace();
	while(!cekPapanPenuh()) {
		system("cls");
		baris = 0; kolom = 0;
		papanSkorVkom();
		gambarPapan();
		if(pemainMain==0){
			int input = inputHurufVkom();
			if(input){
				int point = cariSOS();
				if (!point) {
					printf("\xaf\xaf\xaf KAMU BELUM MENDAPATKAN POIN!\n GILIRAN PEMAIN SELANJUTNYA!\n");
					system("pause");
					pemainMain = 2;
				}
				else {
					poin[pemainMain] = poin[pemainMain] + 1;
					printf("\xaf\xaf\xaf SELAMAT KAMU MENDAPATKAN POIN, SILAHKAN BERMAIN KEMBALI!\n");
					system("pause");
				}
			}
		}
		else if(pemainMain==2){
			hasilLevel(); 
			}
		}
		tampilanAkhirVkom();	
}

void inputNamaVkom() {
	system("cls");
	system("color F1");
   	printf("\n\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________ \n");
	printf("\t\t\xb3                                                                                     \xb3\n");
	printf("\t\t\xb3  $$$$$    $$$   $$$$$$$   $$$$       $$$$   $$$$$$$                                 \xb3\n");
	printf("\t\t\xb3  $$$$$$   $$$  $$$$$$$$$  $$$$$     $$$$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$ $$$  $$$  $$$   $$$  $$$ $$$ $$$ $$$  $$$   $$$                                \xb3\n");
	printf("\t\t\xb3  $$$  $$$ $$$  $$$$$$$$$  $$$  $$$$   $$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$   $$$$$$  $$$$$$$$$  $$$         $$$  $$$$$$$$$                                \xb3\n");
	printf("\t\t\xb3  $$$    $$$$$  $$$   $$$  $$$         $$$  $$$   $$$                                \xb3\n");
	printf("\t\t\xb3  $$$     $$$$  $$$   $$$  $$$         $$$  $$$   $$$                                \xb3\n");
    printf("\t\t\xb3                                                      SOS MAUNG BANDUNG              \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3    PEMAIN 1                                                                         \xb3\n");
    printf("\t\t\xb3    KOMPUTER                                                                         \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Pemain 1: "); scanf("%s",&nama[0][0]);
}


void papanSkorVkom(){
		gotoxy(0,0);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,194,196,194,196,196,196,196,196,196,196,196,196,191);
	printf("\n\xb3        \xb3:\xb3         \xb3\n");
	printf("\xb3        \xb3:\xb3         \xb3");
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,193,196,193,196,196,196,196,196,196,196,196,196,217);
	gotoxy(2,1);printf("%s\n", nama[0]);
    gotoxy(13,1);printf("%s\n", komputer);
    gotoxy(2,2);printf("%d\n\n", poin[0]);
    gotoxy(13,2);printf("%d\n\n", poin[2]);
}


int cekKosong(int isi){
  	if(isi>0 && isi<((hasilPapan*hasilPapan)+1)){	
		baris = (isi-1)/hasilPapan;
		kolom = (isi-1)%hasilPapan;

		if (papan[baris][kolom]==' '){
			return 1;
		}
		else {
			return 0;
		} 
	}
  	else{
		return 0;	
  	}
}

int inputHurufVkom(){
	pertanyaan();
	scanf("%d",&jawaban);
	if (jawaban==hasil){
	printf("Jawabanmu benar! Lanjutkan pilihanmu!");
	printf("\n\xdb Baris: ");
	scanf("%d", &baris);
	printf("\xdb Kolom: ");
	scanf("%d", &kolom);
	if(!(baris > 0 && baris <= hasilPapan && kolom > 0 && kolom <= hasilPapan)){
		printf("\xaf\xaf POSISI SALAH!! MASUKKAN KEMBALI\n\xaf\xaf Click enter to continue!!");
		system("pause");
		return 0;
	}
	switch(papan[baris - 1][kolom - 1]){
		case 'S':
		case 'O':   
			printf("\xaf\xaf sudah terisi!!\n\xaf\xaf Click enter to continue!!");
			system("pause");
			return 0;
		default:    
			system("cls");
			papanSkorVkom();
			gambarPapan();
			printf("\n\n\xc Giliran: %s\n\xdb baris: %d\n\xdb kolom: %d\n\xaf\xaf S/O? ", nama[pemainMain], baris, kolom);
			char isi;
			scanf(" %c", &isi);
			switch (isi) {
				case 's':
				case 'S': papan[baris - 1][kolom - 1] = 'S'; return 1;
				case 'o':
				case 'O': papan[baris - 1][kolom - 1] = 'O'; return 1;
			}
		printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Click enter to continue!!");
		system("pause");
		return 0;
	}
}else{
		printf("JAWABAN SALAH, GANTI GILIRAN!!!\n");
		pemainMain=2;
	}
	
}

/*LEVELING*/

void wanieun(){
	int isi;
	char symbol;
  	do{
  		system("cls");
  		papanSkorVkom();
    	gambarPapan();
		if(cekOS_wanieun()){
			isi = cekOS_wanieun();
			symbol = 'S';
		}
		else if(cekS_S_wanieun()){
			isi = cekS_S_wanieun();
			symbol = 'O';
		}
		else{
			isi = cariPosisi();
			symbol=acakHuruf();
		}
		baris = (isi-1)/hasilPapan;
		kolom = (isi-1)%hasilPapan;
        
   		papan[baris][kolom] = symbol;
   		if(poinKom==0){
   			if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				system("pause");
			}
		}
		else if(poinKom==1){
			system("cls");
			papanSkorVkom();
    		gambarPapan();
    		if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
   				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}
		}
   }while(cariSOSVKom(isi, symbol) && (!cekPapanPenuh()));

   return;
	
}

void jengatJengat(){
	int isi;
	char symbol;
  	do{
  		system("cls");
  		papanSkorVkom();
    	gambarPapan();
		if(cekOS_jengatJengat()){
			isi = cekOS_jengatJengat();
			symbol = 'S';
		}
		else if(cekS_S_jengatJengat()){
			isi = cekS_S_jengatJengat();
			symbol = 'O';
		}
		else{
			isi = cariPosisi();
			symbol=acakHuruf();
		}
		baris = (isi-1)/hasilPapan;
		kolom = (isi-1)%hasilPapan;
        
   		papan[baris][kolom] = symbol;
   		if(poinKom==0){
   			if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d]] \n", symbol, baris+1, kolom+1);
				system("pause");
			}
		}
		else if(poinKom==1){
			system("cls");
			papanSkorVkom();
    		gambarPapan();
    		if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
   				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}
		}
   }while(cariSOSVKom(isi, symbol) && (!cekPapanPenuh()));

   return;
	
}

void nyantuy(){
	int isi;
	char symbol;
  	do{
  		system("cls");
  		papanSkorVkom();
    	gambarPapan();
		if(cekOS_nyantuy()){
			isi = cekOS_nyantuy();
			symbol = 'S';
		}
		else if(cekS_S_nyantuy()){
			isi = cekS_S_nyantuy();
			symbol = 'O';
		}
		else{
			isi = cariPosisi();
			symbol= acakHuruf();
		}
		baris = (isi-1)/hasilPapan;
		kolom = (isi-1)%hasilPapan;
        
   		papan[baris][kolom] = symbol;
   		if(poinKom==0){
   			if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				system("pause");
			}
		}
		else if(poinKom==1){
			system("cls");
			papanSkorVkom();
    		gambarPapan();
    		if(symbol == 'S'){
   				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
   				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}else if(symbol == 'O'){
				printf("\n\xaf\xaf Komputer memasukan huruf %c di [%d][%d] \n", symbol, baris+1, kolom+1);
				printf("\xaf\xaf\xaf Komputer mendapatkan poin \n");
				system("pause");
			}
		}
   }while(cariSOSVKom(isi, symbol) && (!cekPapanPenuh()));

   return;
}

int cariPosisi(){
	int isi;
	
	for (isi=1; isi<=(hasilPapan*hasilPapan); isi++){
		baris = (isi-1)/hasilPapan;
		kolom = (isi-1)%hasilPapan;
		if (papan[baris][kolom] == ' '){
			return isi;
		}
	}
	return 0;
}

int cekS_S_wanieun(){
	int isi;

    for (int i=0; i<hasilPapan; i++){
        for(int j=0; j<hasilPapan; j++){  
        
            isi = ((i*hasilPapan) +j)+1;
            if(cekKosong(isi)){
		        if((papan[i][j+1] == 'S') && (papan[i][j-1] == 'S')){
                    return isi;
            	}
                if ((papan[i+1][j] == 'S') && (papan[i-1][j] =='S')){
                    return isi;
        		}
                if((papan[i+1][j+1] == 'S') && (papan[i-1][j-1] == 'S')){
                    return isi;
                }
                if((papan[i+1][j-1] == 'S') && (papan[i-1][j+1] == 'S')){
                    return isi;
                }
            }
		}
    }
	return 0;		
}

int cekS_S_nyantuy(){
	int isi;

    for (int i=0; i<hasilPapan; i++){
        for(int j=0; j<hasilPapan; j++){  
        
            isi = ((i*hasilPapan) +j)+1;
            if(cekKosong(isi)){
		        if((papan[i][j+1] == 'S') && (papan[i][j-1] == 'S')){
                    return isi;
            	}
            }
		}
    }
	return 0;		
}

int cekS_S_jengatJengat(){
	int isi;

    for (int i=0; i<hasilPapan; i++){
        for(int j=0; j<hasilPapan; j++){  
        
            isi = ((i*hasilPapan) +j)+1;
            if(cekKosong(isi)){
		        if((papan[i][j+1] == 'S') && (papan[i][j-1] == 'S')){
                    return isi;
            	}
                if ((papan[i+1][j] == 'S') && (papan[i-1][j] =='S')){
                    return isi;
        		}
            }
		}
    }
	return 0;		
}

int cekOS_wanieun(){
	int isi;

	for (int i=0; i<hasilPapan; i++){
		for(int j=0; j<hasilPapan; j++){
		   isi = ((i*hasilPapan) +j)+1;
			if(cekKosong(isi)){
				if((papan[i][j+1] == 'O') && (papan[i][j+2] == 'S')){
					return isi;
				}
                if((papan[i][j-1] == 'O') && (papan[i][j-2] == 'S')){
                    return isi;
                        }
				if((papan[i+1][j] == 'O') && (papan[i+2][j] =='S')){
					return isi;
				}
                if((papan[i-1][j] == 'O') && (papan[i-2][j] =='S')){
                    return isi;
                }
				if((papan[i+1][j+1] == 'O') && (papan[i+2][j+2] == 'S')){
                    return isi;
                }
                if((papan[i-1][j-1] == 'O') && (papan[i-2][j-2] == 'S')){
                    return isi;
                }
                if((papan[i+1][j-1] == 'O') && (papan[i+2][j-2] == 'S')){
                    return isi;
                }
                if((papan[i-1][j+1] == 'O') && (papan[i-2][j+2] == 'S')){
                    return isi;
                }
		  	}
		}
	}
	return 0;
}

int cekOS_nyantuy(){
	int isi;

	for (int i=0; i<hasilPapan; i++){
		for(int j=0; j<hasilPapan; j++){
		   isi = ((i*hasilPapan) +j)+1;
			if(cekKosong(isi)){
				if((papan[i][j+1] == 'O') && (papan[i][j+2] == 'S')){
					return isi;
				}
                if((papan[i][j-1] == 'O') && (papan[i][j-2] == 'S')){
                    return isi;
                }
		  	}
		}
	}
	return 0;
}

int cekOS_jengatJengat(){
	int isi;

	for (int i=0; i<hasilPapan; i++){
		for(int j=0; j<hasilPapan; j++){
		   isi = ((i*hasilPapan) +j)+1;
			if(cekKosong(isi)){
				if((papan[i][j+1] == 'O') && (papan[i][j+2] == 'S')){
					return isi;
				}
                if((papan[i][j-1] == 'O') && (papan[i][j-2] == 'S')){
                    return isi;
                        }
				if((papan[i+1][j] == 'O') && (papan[i+2][j] =='S')){
					return isi;
				}
                if((papan[i-1][j] == 'O') && (papan[i-2][j] =='S')){
                    return isi;
                }
		  	}
		}
	}
	return 0;
}

int cariSOSVKom (int isi, char symbol){
	int dapatPoin;
	baris = (isi-1)/hasilPapan;
	kolom = (isi-1)%hasilPapan;
	dapatPoin = 0;

  	if(symbol == 'S'){
		if ((papan[baris][kolom-2] == 'S') && (papan[baris][kolom-1] == 'O')){
			dapatPoin++;
		}
		if ((papan[baris][kolom+1]== 'O') && (papan[baris][kolom+2] == 'S')){
			dapatPoin++;
		}	
		if((papan[baris+1][kolom] == 'O') && (papan[baris+2][kolom] == 'S')){
			dapatPoin++;
		}
		if((papan[baris-1][kolom] == 'O') && (papan[baris-2][kolom] == 'S')){
			dapatPoin++;
		}
		if((papan[baris+1][kolom+1] == 'O') && (papan[baris+2][kolom+2] == 'S')){
			dapatPoin++;
		}
		if((papan[baris-1][kolom-1] == 'O') && (papan[baris-2][kolom-2] == 'S')){
			dapatPoin++;
		}
		if((papan[baris+1][kolom-1] == 'O') && (papan[baris+2][kolom-2] == 'S')){
			dapatPoin++;
		}
		if((papan[baris-1][kolom+1] == 'O') && (papan[baris-2][kolom+2] == 'S')){
			dapatPoin++;
		}
  	}
  	else if(symbol == 'O'){
		if((papan[baris+1][kolom] == 'S') && (papan[baris-1][kolom] == 'S')){
			dapatPoin++;
		}
		if((papan[baris][kolom+1] == 'S') && (papan[baris][kolom-1] == 'S')){
			dapatPoin++;
		}
		if((papan[baris+1][kolom+1] == 'S') && (papan[baris-1][kolom-1] == 'S')){
			dapatPoin++;
		}
		if((papan[baris+1][kolom-1] == 'S') && (papan[baris-1][kolom+1] == 'S')){
			dapatPoin++;
		}
  	}
    poin[pemainMain] = poin[pemainMain] + dapatPoin;

	if(dapatPoin>0){
		poinKom=1;
		return 1;
	}
	else{
		pemainMain=0;
		poinKom=0;
		return 0;
	}
}

int cekPapanPenuh(){	
	for(baris=0; baris<hasilPapan;baris++){
		for(kolom=0; kolom<hasilPapan; kolom++){
			if (papan[baris][kolom] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
