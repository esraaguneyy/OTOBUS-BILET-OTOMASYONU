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


        printf("Sefer baþarýyla eklendi.\n");
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

        FILE *dosya = fopen("sefer.txt", "w"); // Dosyayý yazma modunda açma

        if (dosya == NULL) {
            printf("Dosya açýlamadý.\n");
            return;
        }

        for (int i = 0; i < seferSayisi; i++) {
            fprintf(dosya, "%s,%s,%s,%s,%s,%s\n", seferListesi[i].kalkis, seferListesi[i].varis,
                    seferListesi[i].ucret, seferListesi[i].km, seferListesi[i].plaka, seferListesi[i].sofor);
        }

        fclose(dosya); // Dosyayý kapatma

        printf("Sefer baþarýyla silindi.\n");
    } else {
        printf("Geçersiz sefer indeksi.\n");
    }
}

void seferListeGor(){
	int i;
	int no;
	printf("Sefer ID\tKALKIÞ\t\tVARIÞ\t\tÜCRET\n");
	for ( i = 0; i < seferSayisi; i++) {
	printf(" %d -\t\t%s\t%s\t\t%s\n", i,seferListesi[i].kalkis,seferListesi[i].varis,seferListesi[i].ucret);
	}
	
}

void seferGoruntule() {
	int i;
    printf("Sefer Listesi:\n");
    for ( i = 1; i < seferSayisi; i++) {
        printf("Sefer %d:\n", i);
        printf("Kalkýþ: %s\n", seferListesi[i].kalkis);
        printf("Varýþ: %s\n", seferListesi[i].varis);
        printf("Ücret: %s\n", seferListesi[i].ucret);
        printf("KM: %s\n", seferListesi[i].km);
        printf("Plaka: %s\n", seferListesi[i].plaka);
        printf("Þoför: %s\n", seferListesi[i].sofor);
        printf("---------------------------\n");
    }
}

int ana_giris(char yon_ad[10],int sifre){ // Giriþ Fonksiyonu 
	setlocale(LC_ALL, "Turkish"); // Türkçe dil desteði saðlar.
	int islem_tercih,durum;
	printf("\t\t Ception Turizm - Giris Ekraný\n\n");
	printf("\n 1 - Müþteri Giriþi\n 2 - Yetkili Girisi\n");
	
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
   	printf("\t\t Ception Turizm - Yönetici Giriþ\n\n");
    printf("Kullanýcý Adý Giriniz: "); 
	scanf(" %s",&girilen_isim);
	printf("Lütfen Þifre Giriniz: ");
	scanf("%d",&girilen_sifre);
		if(strcmp(yon_ad,girilen_isim)==0 && (girilen_sifre==sifre)){ // Girilen kullanýcý adý ile þifre kayýtlý kullanýcý adý ve þifre ile eþleþiyor mu diye kontrol eder.
			
		durum=1; 
		system("color 2F"); // Arka planý yeþil renk yapar.
		printf("\n\nKullanýcý Bilgileri Eþlesmiþtir.");
		printf("\nGiriþ Baþarili. \nMenüye Yönlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka planý varsayýlan hale çevirir.
		Sleep(100);
		system("cls"); // CMD Ekranýný temizler.
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
	printf("\t\t Ception Turizm - Müþteri Giriþ\n\n");
	
    printf("Kullanici Adi: ");
    scanf("%s", kullaniciAdi);

    printf("Sifre: ");
    scanf("%s", sifre);

    for (i = 0; i < kullaniciSayisi; i++) {
        if (strcmp(uyeListesi[i].kullaniciAdi, kullaniciAdi) == 0 && strcmp(uyeListesi[i].sifre, sifre) == 0) {
        system("color 2F"); // Arka planý yeþil renk yapar.
		printf("\n\nKullanýcý Bilgileri Eþlesmiþtir.");
		printf("\nGiriþ Baþarili. \nMenüye Yönlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka planý varsayýlan hale çevirir.
		Sleep(100);
		system("cls"); // CMD Ekranýný temizler.
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
	printf("\t\t Ception Turizm - Müþteri Kayýt\n\n");

    printf("Ad: ");
    scanf(" %[^\n]", yeniUye.ad);

    printf("Soyad: ");
    scanf(" %[^\n]", yeniUye.soyad);

    printf("TC Kimlik No: ");
    scanf(" %[^\n]", &yeniUye.tcno);

    printf("Telefon Numaranýz (555555555 Formatýnda giriniz.): ");
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

    printf("\nVeri Tabanýna Kayýt Edildi!\n");

    	system("color 2F"); // Arka planý yeþil renk yapar.
		printf("\n\nKullanýcý Bilgileri Eþlesmiþtir.");
		printf("\nKayýt Baþarýlý. \nMenüye Yönlendiriliyorsunuz...");
		Sleep(100);
		system("color 0F"); // Arka planý varsayýlan hale çevirir.
		Sleep(100);
		system("cls"); // CMD Ekranýný temizler.
    
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
	
	// Üyeleri Okuma
    FILE *dosya = fopen("uye.txt", "r"); // Metin dosyasýný okuma modunda açma

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

    fclose(dosya); // Dosyayý kapatma
}
	
void seferVeriOku(struct sefer *seferListesi, int *seferSayisi) {
    FILE *dosya = fopen("sefer.txt", "r"); // Metin dosyasýný okuma modunda açma

    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
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

    fclose(dosya); // Dosyayý kapatma
}

void bilet_kes(struct uye *uyeListesi, struct sefer *seferListesi) {
    
    // Dosyayý okuma modunda aç
    FILE *dosya = fopen("biletsayisi.txt", "r");

    // Dosya açýldý mý diye kontrol et
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }

    // Dosyadan bir tam sayý oku
    fscanf(dosya, "%d", &bilet_numarasi);

    // Dosyayý kapat
    fclose(dosya);
    
    char dosya_adi[50];
    sprintf(dosya_adi, "Bilet%d.txt", bilet_numarasi);
    bilet_numarasi++; // Bilet numarasýný güncelle
    
    FILE *biletoku = fopen(dosya_adi, "w");
    if (dosya == NULL) {
        printf("Dosya oluþturulamadý.");
        return;
    }
    
    fprintf(dosya, "Müþteri Adý: %s\n", uyeListesi->ad);
    fprintf(dosya, "Müþteri Soyadý: %s\n", uyeListesi->soyad);
    fprintf(dosya, "Müþteri TC No: %s\n", uyeListesi->tcno);
    fprintf(dosya, "Müþteri GSM: %s\n", uyeListesi->gsm);
    
    fprintf(dosya, "Kalkýþ Yeri: %s\n", seferListesi->kalkis);
    fprintf(dosya, "Varýþ Yeri: %s\n", seferListesi->varis);
    fprintf(dosya, "Ücret: %s\n", seferListesi->ucret);
    fprintf(dosya, "Kilometre: %s\n", seferListesi->km);
    fprintf(dosya, "Plaka: %s\n", seferListesi->plaka);
    fprintf(dosya, "Þoför: %s\n", seferListesi->sofor);
    
    fclose(dosya);
    printf("Bilet oluþturuldu: %s\n", dosya_adi);
    
        // Dosyayý yazma modunda aç
    FILE *biletsayiyaz = fopen("biletsayisi.txt", "w");

    // Dosya açýldý mý diye kontrol et
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }

    // Deðeri dosyaya yaz
    fprintf(dosya, "%d", bilet_numarasi);

    // Dosyayý kapat
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
		printf("\t\t  CeptionBANK\n\t\t   Ana Menü\n");
		printf("\n 1 - Sefer Ýþlemleri \n 2 - Bilet Ýþlemleri\n 3 - Üyeleri Görüntüle\n\n 0 - Çýkýþ");
	islem_sor:	islem_tercih = getch();
		
		switch(islem_tercih){
			int seferMenuTekrar;
			int seferMenuTekrar2;
			int uyeGosterMenu;
			
			case '1':
			sefer_menu:
				system("cls");
				printf("\t\t  CeptionTurizm\n\t\t 	Sefer Ýþlemleri\n");
				printf("\n 1 - Seferleri Gör \n 2 - Sefer Ekle\n 3 - Sefer Sil\n\n 0 - Çýkýþ");
					sefer_islem_sor: sefer_islem_tercih = getch();
						switch(sefer_islem_tercih){
							case '1':
								system("cls");
									seferListeGor();
								printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
				
										printf("Kalkýþ Yeri:");
										scanf(" %s",&kalkis);
										printf("Varýþ Yeri:");
										scanf(" %s",&varis);
										printf("Ücret:");
										scanf("%s",&fiyat);
										printf("Mesafe (KM):");
										scanf("%s",&km);
										printf("Otobüs Plaka: ");
										scanf("%s",&plaka);
										printf("Þöför: ");
										scanf("%s",&sofor);
				
									seferEkle(kalkis,varis,fiyat,km,plaka,sofor);
   			   					goto sefer_menu;
   			   						
								break;
								
							case '3':
							
									seferListeGor();
									printf("Silmek Ýstediðiniz Sefer No");
									scanf("%d",&sil_tercih);
									seferSil(sil_tercih);
									goto sefer_menu;
									
								break;
							
							case '4':
								system("cls");
								
								printf("Detaylý Sefer Bilgisi\n\n");
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
				printf("\t\t  CeptionTurizm\n\t\t 	Bilet Ýþlemleri\n");
				printf("\n 1 - Üyeler Ýçin Bilet Kesme \n 2 - Üye Olmayanlar Ýçin Bilet Kesme\n\n 0 - Çýkýþ");
					bilet_islem_sor: bilet_islem_tercih = getch();
						switch(bilet_islem_tercih){
							case '1':
								system("cls");
								printf("Üyeler Ýçin Bilet Kesme\n\n");
								
									seferListeGor();
									
									printf("\nBilet Kesmek Ýstediðiniz Sefer : ");
									scanf("%d",&seferID);
									system("cls");
									
										printf("Bilet Keseceðeniz Sefer | %d - %s - %s Ücret = %s\n\n", seferID,seferListesi[seferID].kalkis,seferListesi[seferID].varis,seferListesi[seferID].ucret);
										   		 printf("ID\tAD\tSOYAD\tTC\t\tGSM\n\n");	
												    for (int i = 1; i < kullaniciSayisi; i++) {
												        printf("%d\t%s\t%s\t%s\t%s", i,uyeListesi[i].ad,uyeListesi[i].soyad,uyeListesi[i].tcno,uyeListesi[i].gsm);
												        printf("\n");
													    }
												
												    
									printf("\nBilet Kesmek Ýstediðiniz Üye : ");
									scanf("%d",&musteriID);
									
									bilet_kes(&uyeListesi[musteriID], &seferListesi[seferID]);
				
								printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
								printf("Üye Olmayanlar Ýçin Bilet Kesme\n\n");
								
									seferListeGor();
									
									printf("\nBilet Kesmek Ýstediðiniz Sefer : ");
									scanf("%d",&seferID);
									system("cls");
									
										printf("Bilet Keseceðeniz Sefer | %d - %s - %s Ücret = %s\n\n", seferID,seferListesi[seferID].kalkis,seferListesi[seferID].varis,seferListesi[seferID].ucret);
										    
											struct uye yeniUye;
										    
												printf("Ad: ");
											    scanf(" %[^\n]", yeniUye.ad);
											
											    printf("Soyad: ");
											    scanf(" %[^\n]", yeniUye.soyad);
											
											    printf("TC Kimlik No: ");
											    scanf(" %[^\n]", &yeniUye.tcno);
											
											    printf("Telefon Numaranýz (555555555 Formatýnda giriniz.): ");
											    scanf(" %[^\n]", &yeniUye.gsm);
											    
											    uyeListesi[99] = yeniUye; // 99 dizisini geçici bellek olarak kullanýyoruz.
											    
										bilet_kes(&uyeListesi[99], &seferListesi[seferID]);
								
								printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
				printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
				printf("Silmek Ýstediðiniz Sefer No");
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
	
hosgeldin:	printf("\t\t Ception Turizm - Müþteri Giriþ\n\n");
			printf("\n 1 - Giriþ Yap\n 2 - Kayýt Ol\n");
			
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
		printf("Sistemde Bir Sorun Ýle Karþýlaþýldý. Lütfen Tekrar Baþlatýn.");
		return 0;
	}
	
m_menu:	
	printf("\t\tCeption Turizm\n\tMüþteri Sekmesi - Ana Menü\n");
		printf("\t\t%s %s\n\n",uyeListesi[ID].ad,uyeListesi[ID].soyad);
		printf("\n1 - Seferleri Gör\n2 - Kullanýcý Bilgilerim\n\n 0 - Çýkýþ");
	m_islem_sor:	m_islem_tercih = getch();
		
		switch(m_islem_tercih){
			int seferMenuTekrar3;
			int uyelikbilgitercih;
			case '1':
				system("cls");
				seferListeGor();
				
				printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
				printf("Üyelik ID:%d\nAd Soyad : %s %s\nTC Kimlik : %s\nTelefon No : %s\nKullanýcý Adý : %s\nÞifre : %s\n", ID,uyeListesi[ID].ad,uyeListesi[ID].soyad,uyeListesi[ID].tcno,uyeListesi[ID].gsm,uyeListesi[ID].kullaniciAdi,uyeListesi[ID].sifre);
				printf("\n\nMenüye Dönmek Ýçin 0'a Basýnýz.");
		
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
