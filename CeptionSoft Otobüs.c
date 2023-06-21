#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#define MAX_KULLANICI_SAYISI 100
#define MAX_SEFER_SAYISI 10

struct uye {
    char ad[15];
    char soyad[15];
    char tcno[15];
    char gsm[15];
    char kullaniciAdi[20];
    char sifre[20];
};

struct sefer {
    char kalkis[15];
    char varis[15];
    char ucret[15];
    char km[15];
    char plaka[20];
    char sofor[20];
};


struct uye uyeListesi[MAX_KULLANICI_SAYISI];
struct sefer seferListesi[MAX_SEFER_SAYISI];

int kullaniciSayisi = 1;
int seferSayisi = 1;
int bilet_numarasi = 1;

void seferEkle(const char* kalkis, const char* varis, const char* ucret, const char* km, const char* plaka, const char* sofor) {
    if (seferSayisi < MAX_SEFER_SAYISI) {
        struct sefer yeniSefer;
        strcpy(yeniSefer.kalkis, kalkis);
        strcpy(yeniSefer.varis, varis);
        strcpy(yeniSefer.ucret, ucret);
        strcpy(yeniSefer.km, km);
        strcpy(yeniSefer.plaka, plaka);
        strcpy(yeniSefer.sofor, sofor);
        
        seferListesi[seferSayisi] = yeniSefer;
        seferSayisi++;

	FILE *dosya;
    dosya = fopen("sefer.txt", "a");
    fprintf(dosya, "%s,%s,%s TL,%s KM,%s,%s\n", yeniSefer.kalkis, yeniSefer.varis, yeniSefer.ucret, yeniSefer.km, yeniSefer.plaka,yeniSefer.sofor);
    fclose(dosya);


        printf("Sefer ba�ar�yla eklendi.\n");
    } else {
        printf("Sefer listesi dolu, yeni sefer eklenemiyor.\n");
    }
}

void seferSil(int seferIndex) {
	
    if (seferIndex >= 0 && seferIndex < seferSayisi) {
        for (int i = seferIndex; i < seferSayisi - 1; i++) {
            seferListesi[i] = seferListesi[i + 1];
        }
        seferSayisi--;

        FILE *dosya = fopen("sefer.txt", "w"); // Dosyay� yazma modunda a�ma

        if (dosya == NULL) {
            printf("Dosya a��lamad�.\n");
            return;
        }

        for (int i = 0; i < seferSayisi; i++) {
            fprintf(dosya, "%s,%s,%s,%s,%s,%s\n", seferListesi[i].kalkis, seferListesi[i].varis,
                    seferListesi[i].ucret, seferListesi[i].km, seferListesi[i].plaka, seferListesi[i].sofor);
        }

        fclose(dosya); // Dosyay� kapatma

        printf("Sefer ba�ar�yla silindi.\n");
    } else {
        printf("Ge�ersiz sefer indeksi.\n");
    }
}

void seferListeGor(){
	int i;
	int no;
	printf("Sefer ID\tKALKI�\t\tVARI�\t\t�CRET\n");
	for ( i = 0; i < seferSayisi; i++) {
	printf(" %d -\t\t%s\t%s\t\t%s\n", i,seferListesi[i].kalkis,seferListesi[i].varis,seferListesi[i].ucret);
	}
	
}

void seferGoruntule() {
	int i;
    printf("Sefer Listesi:\n");
    for ( i = 1; i < seferSayisi; i++) {
        printf("Sefer %d:\n", i);
        printf("Kalk��: %s\n", seferListesi[i].kalkis);
        printf("Var��: %s\n", seferListesi[i].varis);
        printf("�cret: %s\n", seferListesi[i].ucret);
        printf("KM: %s\n", seferListesi[i].km);
        printf("Plaka: %s\n", seferListesi[i].plaka);
        printf("�of�r: %s\n", seferListesi[i].sofor);
        printf("---------------------------\n");
    }
}

int ana_giris(char yon_ad[10],int sifre){ // Giri� Fonksiyonu 
	setlocale(LC_ALL, "Turkish"); // T�rk�e dil deste�i sa�lar.
	int islem_tercih,durum;
	printf("\t\t Ception Turizm - Giris Ekran�\n\n");
	printf("\n 1 - M��teri Giri�i\n 2 - Yetkili Girisi\n");
	
	giris_sor:	islem_tercih = getch();
	switch(islem_tercih){
			
			case '1':
                 system("cls");
				durum=0;
				break;
					
			case '2':
    			system("cls");
    			
				
				durum = y_giris(yon_ad,sifre);
    			break;
}
return durum;
}

int y_giris(char yon_ad[10],int sifre){
	int islem_tercih,girilen_sifre,durum;
	char girilen_isim[10];
	system("cls");
   	printf("\t\t Ception Turizm - Y�netici Giri�\n\n");
    printf("Kullan�c� Ad� Giriniz: "); 
	scanf(" %s",&girilen_isim);
	printf("L�tfen �ifre Giriniz: ");
	scanf("%d",&girilen_sifre);
		if(strcmp(yon_ad,girilen_isim)==0 && (girilen_sifre==sifre)){ // Girilen kullan�c� ad� ile �ifre kay�tl� kullan�c� ad� ve �ifre ile e�le�iyor mu diye kontrol eder.
			
		durum=1; 
		system("color 2F"); // Arka plan� ye�il renk yapar.
		printf("\n\nKullan�c� Bilgileri E�lesmi�tir.");
		printf("\nGiri� Ba�arili. \nMen�ye Y�nlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka plan� varsay�lan hale �evirir.
		Sleep(100);
		system("cls"); // CMD Ekran�n� temizler.
}
else{
durum=0;
}
return durum;
}

int m_giris() {
	
  	char kullaniciAdi[20];
    char sifre[20];
    int i;
	system("cls");
	printf("\t\t Ception Turizm - M��teri Giri�\n\n");
	
    printf("Kullanici Adi: ");
    scanf("%s", kullaniciAdi);

    printf("Sifre: ");
    scanf("%s", sifre);

    for (i = 0; i < kullaniciSayisi; i++) {
        if (strcmp(uyeListesi[i].kullaniciAdi, kullaniciAdi) == 0 && strcmp(uyeListesi[i].sifre, sifre) == 0) {
        system("color 2F"); // Arka plan� ye�il renk yapar.
		printf("\n\nKullan�c� Bilgileri E�lesmi�tir.");
		printf("\nGiri� Ba�arili. \nMen�ye Y�nlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka plan� varsay�lan hale �evirir.
		Sleep(100);
		system("cls"); // CMD Ekran�n� temizler.
            return i;
        }
    }

    printf("Giris basarisiz.\n");
    m_giris();
}

int m_kayitOl() {
	
 if (kullaniciSayisi == MAX_KULLANICI_SAYISI) {
        printf("Kullanici siniri asildi.\n");
        return;
    }

    struct uye yeniUye;
    
    system("cls");
	printf("\t\t Ception Turizm - M��teri Kay�t\n\n");

    printf("Ad: ");
    scanf(" %[^\n]", yeniUye.ad);

    printf("Soyad: ");
    scanf(" %[^\n]", yeniUye.soyad);

    printf("TC Kimlik No: ");
    scanf(" %[^\n]", &yeniUye.tcno);

    printf("Telefon Numaran�z (555555555 Format�nda giriniz.): ");
    scanf(" %[^\n]", &yeniUye.gsm);

    printf("Kullanici Adi: ");
    scanf(" %[^\n]", yeniUye.kullaniciAdi);

    printf("Sifre: ");
    scanf(" %[^\n]", yeniUye.sifre);

    uyeListesi[kullaniciSayisi] = yeniUye;
    kullaniciSayisi++;

    FILE *dosya;
    dosya = fopen("uye.txt", "a");
    fprintf(dosya, "%s,%s,%s,%s,%s,%s\n", yeniUye.ad, yeniUye.soyad, yeniUye.tcno, yeniUye.gsm, yeniUye.kullaniciAdi, yeniUye.sifre);
    fclose(dosya);

    printf("\nVeri Taban�na Kay�t Edildi!\n");

    	system("color 2F"); // Arka plan� ye�il renk yapar.
		printf("\n\nKullan�c� Bilgileri E�lesmi�tir.");
		printf("\nKay�t Ba�ar�l�. \nMen�ye Y�nlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka plan� varsay�lan hale �evirir.
		Sleep(100);
		system("cls"); // CMD Ekran�n� temizler.
    
    return;
}
    
void uyeGoster() {
    int i;
    printf("ID\tAD\tSOYAD\tTC\t\tGSM\t\tKullanici Adi\tSifre\n\n");	
    for (i = 1; i < kullaniciSayisi; i++) {
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%s", i,uyeListesi[i].ad,uyeListesi[i].soyad,uyeListesi[i].tcno,uyeListesi[i].gsm,uyeListesi[i].kullaniciAdi,uyeListesi[i].sifre);
        printf("\n");
    }
}
	
void uyeVeriOku() {
	
	// �yeleri Okuma
    FILE *dosya = fopen("uye.txt", "r"); // Metin dosyas�n� okuma modunda a�ma

    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    while (!feof(dosya)) {
        if (kullaniciSayisi == MAX_KULLANICI_SAYISI) {
            printf("Kullanici siniri asildi.\n");
            break;
        }

        struct uye yeniUye;

        fscanf(dosya, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", yeniUye.ad, yeniUye.soyad, &yeniUye.tcno, &yeniUye.gsm, yeniUye.kullaniciAdi, yeniUye.sifre);

        uyeListesi[kullaniciSayisi] = yeniUye;
        kullaniciSayisi++;
    }

    fclose(dosya); // Dosyay� kapatma
}
	
void seferVeriOku(struct sefer *seferListesi, int *seferSayisi) {
    FILE *dosya = fopen("sefer.txt", "r"); // Metin dosyas�n� okuma modunda a�ma

    if (dosya == NULL) {
        printf("Dosya a��lamad�.\n");
        return;
    }

    while ((*seferSayisi < MAX_SEFER_SAYISI) && (fscanf(dosya, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",
                                                     seferListesi[*seferSayisi].kalkis,
                                                     seferListesi[*seferSayisi].varis,
                                                     seferListesi[*seferSayisi].ucret,
                                                     seferListesi[*seferSayisi].km,
                                                     seferListesi[*seferSayisi].plaka,
                                                     seferListesi[*seferSayisi].sofor) == 6)) {
        (*seferSayisi)++;
    }

    fclose(dosya); // Dosyay� kapatma
}

void bilet_kes(struct uye *uyeListesi, struct sefer *seferListesi) {
    
    // Dosyay� okuma modunda a�
    FILE *dosya = fopen("biletsayisi.txt", "r");

    // Dosya a��ld� m� diye kontrol et
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }

    // Dosyadan bir tam say� oku
    fscanf(dosya, "%d", &bilet_numarasi);

    // Dosyay� kapat
    fclose(dosya);
    
    char dosya_adi[50];
    sprintf(dosya_adi, "Bilet%d.txt", bilet_numarasi);
    bilet_numarasi++; // Bilet numaras�n� g�ncelle
    
    FILE *biletoku = fopen(dosya_adi, "w");
    if (dosya == NULL) {
        printf("Dosya olu�turulamad�.");
        return;
    }
    
    fprintf(dosya, "M��teri Ad�: %s\n", uyeListesi->ad);
    fprintf(dosya, "M��teri Soyad�: %s\n", uyeListesi->soyad);
    fprintf(dosya, "M��teri TC No: %s\n", uyeListesi->tcno);
    fprintf(dosya, "M��teri GSM: %s\n", uyeListesi->gsm);
    
    fprintf(dosya, "Kalk�� Yeri: %s\n", seferListesi->kalkis);
    fprintf(dosya, "Var�� Yeri: %s\n", seferListesi->varis);
    fprintf(dosya, "�cret: %s\n", seferListesi->ucret);
    fprintf(dosya, "Kilometre: %s\n", seferListesi->km);
    fprintf(dosya, "Plaka: %s\n", seferListesi->plaka);
    fprintf(dosya, "�of�r: %s\n", seferListesi->sofor);
    
    fclose(dosya);
    printf("Bilet olu�turuldu: %s\n", dosya_adi);
    
        // Dosyay� yazma modunda a�
    FILE *biletsayiyaz = fopen("biletsayisi.txt", "w");

    // Dosya a��ld� m� diye kontrol et
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }

    // De�eri dosyaya yaz
    fprintf(dosya, "%d", bilet_numarasi);

    // Dosyay� kapat
    fclose(dosya);
}

int main() {
		
char yon_ad[10]="admin";	
int sifre=1234;
int islem_tercih;
int m_islem_tercih;
int durum;
int ID;
int sil_tercih;
int sefer_islem_tercih;
int bilet_islem_tercih;
int seferID;
int musteriID;
int tekrar;
uyeVeriOku();
seferVeriOku(seferListesi, &seferSayisi);

giris: durum = ana_giris(yon_ad,sifre);

char kalkis[40],varis[40],fiyat[20],km[10],plaka[30],sofor[50];

menu:
	if(durum==1){
		printf("\t\t  CeptionBANK\n\t\t   Ana Men�\n");
		printf("\n 1 - Sefer ��lemleri \n 2 - Bilet ��lemleri\n 3 - �yeleri G�r�nt�le\n\n 0 - ��k��");
	islem_sor:	islem_tercih = getch();
		
		switch(islem_tercih){
			int seferMenuTekrar;
			int seferMenuTekrar2;
			int uyeGosterMenu;
			
			case '1':
			sefer_menu:
				system("cls");
				printf("\t\t  CeptionTurizm\n\t\t 	Sefer ��lemleri\n");
				printf("\n 1 - Seferleri G�r \n 2 - Sefer Ekle\n 3 - Sefer Sil\n\n 0 - ��k��");
					sefer_islem_sor: sefer_islem_tercih = getch();
						switch(sefer_islem_tercih){
							case '1':
								system("cls");
									seferListeGor();
								printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
								sefergor_sor: seferMenuTekrar = getch();
			
									switch(seferMenuTekrar){
										case '0':
										system("cls");
										goto sefer_menu;
										break;
										
										default:
										goto sefergor_sor;
										}
									goto sefer_menu;
									
								break;
								
							case '2':
								
								system("cls");
									printf("Sefer Ekleme\n\n");
				
										printf("Kalk�� Yeri:");
										scanf(" %s",&kalkis);
										printf("Var�� Yeri:");
										scanf(" %s",&varis);
										printf("�cret:");
										scanf("%s",&fiyat);
										printf("Mesafe (KM):");
										scanf("%s",&km);
										printf("Otob�s Plaka: ");
										scanf("%s",&plaka);
										printf("��f�r: ");
										scanf("%s",&sofor);
				
									seferEkle(kalkis,varis,fiyat,km,plaka,sofor);
   			   					goto sefer_menu;
   			   						
								break;
								
							case '3':
							
									seferListeGor();
									printf("Silmek �stedi�iniz Sefer No");
									scanf("%d",&sil_tercih);
									seferSil(sil_tercih);
									goto sefer_menu;
									
								break;
							
							case '4':
								system("cls");
								
								printf("Detayl� Sefer Bilgisi\n\n");
								seferGoruntule();
								
								break;
								
							case '0':
							system("cls");
							break;
							
							default :
							goto sefer_islem_sor;
						}
				goto menu;
				break;				
				
			case '2':
			bilet_menu:
				system("cls");
				printf("\t\t  CeptionTurizm\n\t\t 	Bilet ��lemleri\n");
				printf("\n 1 - �yeler ��in Bilet Kesme \n 2 - �ye Olmayanlar ��in Bilet Kesme\n\n 0 - ��k��");
					bilet_islem_sor: bilet_islem_tercih = getch();
						switch(bilet_islem_tercih){
							case '1':
								system("cls");
								printf("�yeler ��in Bilet Kesme\n\n");
								
									seferListeGor();
									
									printf("\nBilet Kesmek �stedi�iniz Sefer : ");
									scanf("%d",&seferID);
									system("cls");
									
										printf("Bilet Kesece�eniz Sefer | %d - %s - %s �cret = %s\n\n", seferID,seferListesi[seferID].kalkis,seferListesi[seferID].varis,seferListesi[seferID].ucret);
										   		 printf("ID\tAD\tSOYAD\tTC\t\tGSM\n\n");	
												    for (int i = 1; i < kullaniciSayisi; i++) {
												        printf("%d\t%s\t%s\t%s\t%s", i,uyeListesi[i].ad,uyeListesi[i].soyad,uyeListesi[i].tcno,uyeListesi[i].gsm);
												        printf("\n");
													    }
												
												    
									printf("\nBilet Kesmek �stedi�iniz �ye : ");
									scanf("%d",&musteriID);
									
									bilet_kes(&uyeListesi[musteriID], &seferListesi[seferID]);
				
								printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
								biletmenu_sor: seferMenuTekrar = getch();
							
									switch(seferMenuTekrar){
										case '0':
										system("cls");
										goto bilet_menu;
										break;
										
										default:
										goto biletmenu_sor;
										}
									
								break;
								
							case '2':
															system("cls");
								printf("�ye Olmayanlar ��in Bilet Kesme\n\n");
								
									seferListeGor();
									
									printf("\nBilet Kesmek �stedi�iniz Sefer : ");
									scanf("%d",&seferID);
									system("cls");
									
										printf("Bilet Kesece�eniz Sefer | %d - %s - %s �cret = %s\n\n", seferID,seferListesi[seferID].kalkis,seferListesi[seferID].varis,seferListesi[seferID].ucret);
										    
											struct uye yeniUye;
										    
												printf("Ad: ");
											    scanf(" %[^\n]", yeniUye.ad);
											
											    printf("Soyad: ");
											    scanf(" %[^\n]", yeniUye.soyad);
											
											    printf("TC Kimlik No: ");
											    scanf(" %[^\n]", &yeniUye.tcno);
											
											    printf("Telefon Numaran�z (555555555 Format�nda giriniz.): ");
											    scanf(" %[^\n]", &yeniUye.gsm);
											    
											    uyeListesi[99] = yeniUye; // 99 dizisini ge�ici bellek olarak kullan�yoruz.
											    
										bilet_kes(&uyeListesi[99], &seferListesi[seferID]);
								
								printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
								biletmenu_sor2: seferMenuTekrar2 = getch();
							
									switch(seferMenuTekrar2){
										case '0':
										system("cls");
										goto bilet_menu;
										break;
										
										default:
										goto biletmenu_sor2;
										}
									
   			   					goto sefer_menu;
   			   						
								break;
							
							case '0':
							system("cls");
							break;
							
							default :
							goto bilet_islem_sor;
						}
				goto menu;
				break;				
			
			case '3':
				system("cls");
				uyeGoster();
				printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
								uyegostermenu_sor: uyeGosterMenu = getch();
							
									switch(uyeGosterMenu){
										case '0':
										system("cls");
										goto menu;
										break;
										
										default:
										goto biletmenu_sor;
										}
									
								break;
				goto menu;
				break;
				
			case '4':
				seferListeGor();
				printf("Silmek �stedi�iniz Sefer No");
				scanf("%d",&sil_tercih);
				seferSil(sil_tercih);
				goto menu;
				break;
				
			case '5':
				system("cls");
				seferListeGor();
				system("cls");
				goto menu;
				break;
				
			case '6':
				system("cls");
				uyeGoster(kullaniciSayisi);
				goto menu;
				break;
				
			case '0':
				system("cls");
				goto giris;
				break;
			default :
			goto islem_sor;
		}
	}
		
	else if(durum==0){
	int islem_tercih2;
	
hosgeldin:	printf("\t\t Ception Turizm - M��teri Giri�\n\n");
			printf("\n 1 - Giri� Yap\n 2 - Kay�t Ol\n");
			
			islem_tercih2 = getch();
	switch(islem_tercih2){
			
			case '1':
                 system("cls");
               		ID = m_giris();
				break;
				
			case '2':
    			system("cls");
                 m_kayitOl();
                 printf("");
                 goto hosgeldin;
    			break;
    			
    		default:
    			system("cls");
    			goto hosgeldin;
}
	}
	
	else{
		printf("Sistemde Bir Sorun �le Kar��la��ld�. L�tfen Tekrar Ba�lat�n.");
		return 0;
	}
	
m_menu:	
	printf("\t\tCeption Turizm\n\tM��teri Sekmesi - Ana Men�\n");
		printf("\t\t%s %s\n\n",uyeListesi[ID].ad,uyeListesi[ID].soyad);
		printf("\n1 - Seferleri G�r\n2 - Kullan�c� Bilgilerim\n\n 0 - ��k��");
	m_islem_sor:	m_islem_tercih = getch();
		
		switch(m_islem_tercih){
			int seferMenuTekrar3;
			int uyelikbilgitercih;
			case '1':
				system("cls");
				seferListeGor();
				
				printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
				seferlistegormenu: seferMenuTekrar3 = getch();
							
				switch(seferMenuTekrar3){
					
						case '0':
							
							system("cls");
							goto m_menu;
							
						break;
										
						default:
							goto seferlistegormenu;
							
										}
				break;
				
			case '2':
				system("cls");
				printf("�yelik ID:%d\nAd Soyad : %s %s\nTC Kimlik : %s\nTelefon No : %s\nKullan�c� Ad� : %s\n�ifre : %s\n", ID,uyeListesi[ID].ad,uyeListesi[ID].soyad,uyeListesi[ID].tcno,uyeListesi[ID].gsm,uyeListesi[ID].kullaniciAdi,uyeListesi[ID].sifre);
				printf("\n\nMen�ye D�nmek ��in 0'a Bas�n�z.");
		
				uyelikbilgigor: uyelikbilgitercih = getch();
							
				switch(uyelikbilgitercih){
					
						case '0':
							
							system("cls");
							goto m_menu;
							
						break;
										
						default:
							goto uyelikbilgigor;
							
										}
				break;
			
			case '0':
				system("cls");
				goto giris;
				break;
			default :
			goto islem_sor;
		}
	return 0;
}
