#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <time.h>

#define MAKS_JENIS_BUKU 50
#define MAKS_JUDUL_BUKU 50
#define MAKS_NAMA_PENULIS 50
#define MAKS_PEMINJAMAN 50
#define MAKS_NAMA_PEMINJAM 50
#define MAKS_USER 20 // Maksimum panjang string untuk username
#define MAKS_PASS 20 // Maksimum panjang string untuk password

/*
				NAMA KELOMPOK :
		Maxwell Rafael Paendong //2205551039
		Firman Karunia Naibaho //2205551059
		
Program ini adalah sebuah aplikasi perpustakaan tentang peminjaman dan pengembalian buku.
Program ini dapat menampilkan daftar buku yang tersedia dan daftar peminjam.
program ini menyimpan semua daftar dalam file bin yang telah terbuat secara otomatis oleh program ini.
*/

// Struktur untuk menyimpan informasi mengenai sebuah buku
typedef struct Buku { //typedef pada struct adalah sebuah cara untuk memberikan sebuah alias atau nama lain untuk tipe data struktur di C
	int kode_buku; // Kode buku (integer)
	char jenis_buku[MAKS_JENIS_BUKU]; // Jenis buku (string)
	char judul_buku[MAKS_JUDUL_BUKU]; // Judul buku (string)
	char penulis[MAKS_NAMA_PENULIS]; // Nama penulis (string)
	int halaman; // Jumlah halaman (integer)
	float harga; // Harga buku (float)
} Buku;

/*typedef struct Bukup{
  int kodep_buku;
  char judulp_buku[MAKS_JUDUL_BUKU];
  char batas[MAKS_PEMINJAMAN];
  char nama_peminjam[MAKS_NAMA_PEMINJAM];
  int nim;
}
Bukup;*/

//struct tm {
  // int tm_sec;         /* seconds,  range 0 to 59          */
//   int tm_min;         /* minutes, range 0 to 59           */
  // int tm_hour;        /* hours, range 0 to 23             */
   //int tm_mday;        /* day of the month, range 1 to 31  */
   //int tm_mon;         /* month, range 0 to 11             */
   //int tm_year;        /* The number of years since 1900   */
   //int tm_wday;        /* day of the week, range 0 to 6    */
   //int tm_yday;        /* day in the year, range 0 to 365  */
   //int tm_isdst;       /* daylight saving time             */
//};

typedef struct Peminjaman{
	char nama_peminjam[MAKS_NAMA_PEMINJAM];
	int nim;
	unsigned int kodep_buku;
	char judulp_buku[MAKS_JUDUL_BUKU];
	char batas[MAKS_PEMINJAMAN];
/*	char tanggal_pengembalian[MAKS_PEMINJAMAN];*/
} Peminjaman;



void login(void) {
	void menu(); // Prosedur untuk menampilkan menu setelah login berhasil
	  int j;
	  char a[25] = " <<< LOGIN >>> ";
	  system("color F2");
	  char user[MAKS_USER] = "Max";  // Variabel yang menyimpan username dan password yang benar
	  char pass[MAKS_PASS] = "Firman";  // Variabel yang menyimpan username dan password yang benar
	  char inputUser[MAKS_USER], inputPass[MAKS_PASS]; // Variabel untuk menyimpan input dari user
	  
	  // Menampilkan tampilan login
	  int result;
	  printf("\n\t\t\t===========================================================================");
	  printf("\n\t\t\t");
	  
	  for (j = 0; j < 30; j++) {
	    Sleep(50); // Fungsi Sleep(50) akan menunda program selama 50 milidetik (0,05 detik) setiap kali dilakukan iterasi perulangan
	    printf("*");
	  }
	  for (j = 0; j < 15; j++) {
	    Sleep(50); // Fungsi Sleep(50) akan menunda program selama 50 milidetik (0,05 detik) setiap kali dilakukan iterasi perulangan
	    printf("%c", a[j]);
	  }
	  for (j = 0; j < 30; j++) {
	    Sleep(50); // Fungsi Sleep(50) akan menunda program selama 50 milidetik (0,05 detik) setiap kali dilakukan iterasi perulangan
	    printf("*");
	  }
	  
	  printf("\n\t\t\t===========================================================================");
	  printf("\n");
	  printf("\n");
	   // Melakukan proses login secara berulang hingga input yang benar diberikan
	  do {
	  	// Menampilkan pesan dan menyimpan input user
	    printf("Masukan Username : ");
	    scanf("%s", inputUser);
	    printf("Masukan Password : ");
	    scanf("%s", inputPass);
	    // Membandingkan input dengan username dan password yang benar
	    if (strcmp(user, inputUser) == 0 && strcmp(pass, inputPass) == 0) {
	      result = 0;
	      printf("Akses diterima. Selamat Datang\n");
	      system("pause");
	      // Menjalankan prosedur menu setelah login berhasil
	      menu();
	    } else {
	      result = 1;
	      printf("Username dan Password tidak match\n");
	      system("cls");
	    }
	  } while (result != 0);
}
void menu(void) {
  int pilihan;
  int validasi();
  //memanggil fungsi yang akan digunakan
  void tambah_buku();
  void delete_buku(void);
  void cari_buku(void);
  void lihat_buku(void);
  void peminjaman(void);
  void lihatp_buku(void);
  void pengembalian(void);
  void help();
  
  
  do {
    system("cls");
    system("color B0");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
    printf("\n\t\t\t                     <<< Selamat Berkunjung :D >>>                          ");
    printf("\n\t\t\t--------------------------------------------------------------------------- ");
     // Mengabaikan input yang diberikan oleh user
    scanf("%*[^\n]");
    // Membersihkan buffer input
    fflush(stdin);

	 // Menampilkan pesan "|>>> MENU PROGRAM <<<|" ke layar console dengan jeda selama 50 milisecond
    int b;
    char j_menu[50] = "|>>> MENU PROGRAM <<<|";
    char j_pilihan[25] = "Masukan Pilihan : ";
    printf("\n\n\t");
    for (b = 0; b < 22; b++) {
      Sleep(50);
      printf("%c", j_menu[b]);

    }
    printf("\n\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\xB2 1. Menambahkan buku    \xB2\n"); 
    printf("\t\xB2 2. Menghapus buku      \xB2\n");
    printf("\t\xB2 3. Mencari buku        \xB2\n");
    printf("\t\xB2 4. Melihat semua buku  \xB2\n");
    printf("\t\xB2 5. Peminjaman          \xB2\n");
    printf("\t\xB2 6. Buku yang dipinjam  \xB2\n");
    printf("\t\xB2 7. Pengembalian        \xB2\n");
    printf("\t\xB2 8. Bantuan             \xB2\n");
    printf("\t\xB2 9. Keluar              \xB2\n");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t");
    for (b = 0; b < 18; b++) {
      Sleep(50);
      printf("%c", j_pilihan[b]);

    }
    pilihan = validasi (1);
    fflush(stdin);

    switch (pilihan) {
    case 1:
      tambah_buku();//memanggil modular tambah_buku
      break;
    case 2:
      delete_buku();//memanggil modular delete
      break;
    case 3:
      cari_buku();//memanggil modular cari_buku
      break;
    case 4:
      lihat_buku();//memanggil modular lihat_buku
      break;
    case 5:
      peminjaman();//memanggil modular peminjaman
      break;
    case 6:
      lihatp_buku();//memanggil modular lihatp_buku
      break;
    case 7:
      pengembalian();//memanggil modular pengembalian
      break;
    case 8:
    	help();//memanggil modular help
    	break;
    case 9:
      exit(0);//keluar dari program
      break;
    default:
      printf("Masukan input yang benar!");
    }
  } while (pilihan != 8);
}

void tambah_buku(void) {
  Buku tambahBuku = {
    0
  }; //Memanggil struct ke fungsi
  FILE * filePointer; //filepointer
  filePointer = fopen("Buku.bin", "ab+"); // ekstensi file ".bin" dapat menandakan bahwa file yang akan dibuka merupakan file biner yang akan digunakan untuk menyimpan data buku dalam bentuk biner. 

  system("cls");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                         <<< Menu Tambah Buku >>>                           ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi nambahin buku
  printf("\n\t\t\tMasukan detail buku dibawah...\n");
  printf("\t\t\tKode buku   :");
  fflush(stdin);
  scanf("%u", & tambahBuku.kode_buku);
  printf("\t\t\tNama buku   :");
  fflush(stdin);
  fgets(tambahBuku.judul_buku, MAKS_JUDUL_BUKU, stdin);
  printf("\t\t\tPenulis buku:");
  fflush(stdin);
  fgets(tambahBuku.penulis, MAKS_NAMA_PENULIS, stdin);
  printf("\t\t\tJenis Buku  :");
  fflush(stdin);
  fgets(tambahBuku.jenis_buku, MAKS_JENIS_BUKU, stdin);
  printf("\t\t\tHalaman     :");
  scanf("%u", & tambahBuku.halaman);
  printf("\t\t\tHarga       :");
  scanf("%f", & tambahBuku.harga);

  //Write ke file
  //Fungsi fwrite merupakan fungsi yang biasa digunakan untuk menuliskan data biner ke dalam file.
  fwrite( & tambahBuku, sizeof(tambahBuku), 1, filePointer);
  fclose(filePointer);//Menutup filePointer
  printf("\n\t\t\tBuku sudah ditambahkan ke database\n");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void delete_buku(void) {
  system("cls");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                          <<< Menu Hapus Buku >>>                           ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi delete buku
  int ketemu = 0, buku = 0;
  FILE * filePointer;
  FILE * tempfP;
  Buku tambahBuku = {
    0
  }; //Memanggil ke struct ke fungsi
  filePointer = fopen("Buku.bin", "rb"); //ekstensi file ".bin" dapat menandakan bahwa file yang akan dibuka merupakan file biner yang akan digunakan untuk menyimpan data buku dalam bentuk biner. 
  tempfP = fopen("temp.bin", "wb"); //membuka file temp.bin

  printf("\n\t\t\tMasukan Kode Buku untuk didelete:");
  fflush(stdin);
  scanf(" %d", & buku);

  while (fread( & tambahBuku, sizeof(tambahBuku), 1, filePointer)) {
    if (tambahBuku.kode_buku != buku) {
      fwrite( & tambahBuku, sizeof(tambahBuku), 1, tempfP);
    } else {
      ketemu = 1;
    }
  }
  if (ketemu == 0) {
    printf("\n\t\t\tBuku berhasil di-delete");
    getchar();
  } else {
    printf("\n\t\t\tBuku tidak ditemukan");
    getchar();
  }
  fclose(filePointer);
  fclose(tempfP);
  remove("Buku.bin");
  rename("temp.bin", "Buku.bin");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void cari_buku(void) {
  system("cls");
  int ketemu = 0;
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                          <<< Menu Cari Buku >>>                            ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi cari buku
 Buku tambahBuku = {
    0
  }; 
  //Memanggil ke struct ke fungsi
  char judulBuku[MAKS_JUDUL_BUKU];
  FILE * filePointer; //filepointer
  filePointer = fopen("Buku.bin", "rb");
  if(filePointer == NULL)
    {
        printf("\n\t\t\tFile belum terbuka\n");
        exit(0);
    }

  printf("\n\t\t\tMasukkan nama buku untuk dicari :");
  fflush(stdin);
  fgets(judulBuku,MAKS_JUDUL_BUKU, stdin);

  while(fread(&tambahBuku, sizeof(tambahBuku),1, filePointer)==1){
    if(strcmp(tambahBuku.judul_buku,judulBuku)== 0){
        ketemu++;
        printf("\n\t\t\tKode Buku    : %u\n", tambahBuku.kode_buku);
        printf("\t\t\tJenis buku     : %s", tambahBuku.jenis_buku);
        printf("\t\t\tPenulis Buku   : %s", tambahBuku.penulis);
        printf("\t\t\tHalaman        : %d\n", tambahBuku.halaman);
        printf("\t\t\tHarga          : Rp%.3f\n", tambahBuku.harga);
    }
  }
    if(ketemu == 0){
        printf("\t\t\tBuku tidak ditemukan");
    }

  fclose(filePointer);
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  getchar();
  system("cls");
}

void lihat_buku(void) {
  system("cls");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                        <<< Menu Lihat Buku >>>                           ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi lihat buku
  int ketemu = 0;
  char judulBuku[MAKS_JUDUL_BUKU] = {
    0
  };
  Buku tambahBuku = {
    0
  }; //Memanggil ke struct ke fungsi
  FILE * filePointer;
  filePointer = fopen("Buku.bin", "rb");
  while (fread( & tambahBuku, sizeof(tambahBuku), 1, filePointer)) {
    printf("\n\t\t\tKode Buku = %u", tambahBuku.kode_buku);
    printf("\n\t\t\tNama Buku = %s", tambahBuku.judul_buku);
    printf("\t\t\tPenulis = %s", tambahBuku.penulis);
    printf("\t\t\tJenis Buku = %s", tambahBuku.jenis_buku);
    printf("\t\t\tHalaman = %u", tambahBuku.halaman);
    printf("\n\t\t\tHarga = Rp%.3f", tambahBuku.harga);
    printf("\n\t\t\t");
    ketemu = 1;
  }
  fclose(filePointer);
  if (!ketemu) {
    printf("\n\t\t\tNo Record");
  }
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void peminjaman(void){
  Peminjaman peminjaman = {
    0
  }; //Memanggil ke struct ke fungsi
  Buku tambahBuku = {
	0
  }; //Memanggil struct buku

  FILE * filePointer; //filepointer
  FILE * fPBuku;
  filePointer = fopen("Bukup.bin", "ab+");
  fPBuku = fopen("Buku.bin", "rb");
  int ketemu = 0;
  char judulBuku[MAKS_JUDUL_BUKU];

  system("cls");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t             		      <<< Menu Peminjaman >>>         	              ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi nambahin buku
  printf("\n\t\t\tMasukan detail peminjaman dibawah...\n");

      printf("\t\t\tNama peminjam :");
      fgets(peminjaman.nama_peminjam, MAKS_NAMA_PEMINJAM, stdin);
      printf("\t\t\tNIM peminjam:");
      scanf("%d", & peminjaman.nim);
      printf("\t\t\tKode buku   :");
      fflush(stdin);
      scanf("%u", & peminjaman.kodep_buku);
      printf("\t\t\tJudul buku  :");
      fflush(stdin);
      fgets(peminjaman.judulp_buku, MAKS_JUDUL_BUKU, stdin);
     // printf("\t\t\tBatas peminjaman (Tanggal/Bulan/Tahun) : %02d/%02d/%04d \n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
      	time_t currentTime;
	    struct tm *localTime;
	
	    time(&currentTime); // Mendapatkan waktu saat ini dalam hitungan detik //direvisi 28 Desember 2022/ By Max dan Firman
	    localTime = localtime(&currentTime); // Mengkonversi waktu saat ini menjadi struktur tm
	        
	    // Menambahkan jumlah hari selama seminggu ke waktu saat ini
	    localTime->tm_mday += 7; //direvisi 28 Desember 2022/ By Firman dan Max
	    mktime(localTime);
	    printf("\t\t\tBatas waktu peminjaman adalah: %02d/%02d/%04d \n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
	    fgets(peminjaman.batas, MAKS_PEMINJAMAN, stdin);

      //Write ke file
      fwrite( & peminjaman, sizeof(peminjaman), 1, filePointer);

  fclose(filePointer);
  fclose(fPBuku);
  printf("\t\t\tDetail peminjaman sudah ditambahkan ke database peminjaman\n");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void lihatp_buku(void){
  system("cls");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                      <<< Menu Lihat Buku Dipinjam >>>                      ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi lihat buku yang dipinjam
  int ketemu = 0;
  char judulp_buku[MAKS_JUDUL_BUKU] = {
    0
  };
  Peminjaman peminjaman = {
    0
  }; //Memanggil ke struct ke fungsi
  FILE * filePointer;
  filePointer = fopen("Bukup.bin", "rb");
  while (fread( & peminjaman, sizeof(peminjaman), 1, filePointer)) {
    printf("\n\t\t\tKode Buku        = %u", peminjaman.kodep_buku);
    printf("\n\t\t\tNama Buku        = %s", peminjaman.judulp_buku);
    printf("\t\t\tBatas Peminjaman = %s", peminjaman.batas);
    printf("\n\t\t\t");
    ketemu = 1;
  }
  fclose(filePointer);
  if (!ketemu) {
    printf("\n\t\t\tNo Record");
  }
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}
/*
void pengembalian(void) {
// Deklarasi variabel
	Peminjaman peminjaman = {0};
	float pembayaran ;
	float total_pembayaran = 15000;
	int ketemu = 1, bukup = 0;
	int denda_per_hari = 1000;
	char nama_peminjam[MAKS_NAMA_PEMINJAM];
	int nim;
	unsigned int kodep_buku;
	FILE *filePointer;
	FILE *tempfP;
	
	// Buka file "Bukup.bin" dan "temp.bin"
	filePointer = fopen("Bukup.bin", "rb");
	tempfP = fopen("temp.bin", "wb+");
	
	// Tampilkan informasi tentang program perpustakaan
	system("cls");
	printf("\t\t\t===========================================================================");
	printf("\n\t\t\t------------ ------------ ");
	printf("\n\t\t\t------------ | PROGRAM PERPUSTAKAAN UNIVERSITAS UDAYANA | ------------ ");
	printf("\n\t\t\t------------ ------------ ");
	printf("\n\t\t\t=========================================================================== ");
	printf("\n\t\t\t--------------------------------------------------------------------------- ");
	printf("\n\t\t\t <<< Menu Pengembalian >>> ");
	printf("\n\t\t\t--------------------------------------------------------------------------- ");
	
	// Ambil input dari user
	printf("\n\t\t\tMasukkan detail pengembalian dibawah...\n");
	printf("\t\t\tNama peminjam :");
	fflush(stdin);
	fgets(nama_peminjam, MAKS_NAMA_PEMINJAM, stdin);
	printf("\t\t\tNIM peminjam :");
	scanf("%d", &nim);
	printf("\t\t\tKode buku :");
	fflush(stdin);
	scanf("%u", &kodep_buku);
	printf("\t\t\tTanggal pengembalian (DD/MM/YYYY) :");
	fflush(stdin);
	fgets(peminjaman.tanggal_pengembalian, MAKS_PEMINJAMAN, stdin);

// Cari data peminjaman yang akan dikembalikan
	while (fread(&peminjaman, sizeof(peminjaman), 1, filePointer)) {// Jika data ditemukan, hitung denda yang harus dibayarkan
		if (strcmp(peminjaman.nama_peminjam, nama_peminjam) == 0 && peminjaman.nim == nim) {
		// Cek apakah tanggal pengembalian lebih lama dari tanggal batas peminjaman
		}
	int selisih_hari = hitung_selisih_hari(peminjaman.batas, peminjaman.tanggal_pengembalian);
	if (selisih_hari > 0){
	total_pembayaran += selisih_hari * denda_per_hari;
	}
	printf("\n\t\t\ttelat %d hari", selisih_hari);
// Tampilkan total pembayaran yang harus dibayarkan
	printf("\n\t\t\tTotal pembayaran: %.2f", total_pembayaran);
	
// Ambil input pembayaran dari user
	printf("\n\t\t\tMasukkan jumlah pembayaran: ");
	scanf("%f", &pembayaran);

// Cek apakah pembayaran sudah cukup atau belum
	if (pembayaran < total_pembayaran) {
// Jika pembayaran kurang dari total pembayaran, tampilkan pesan error
		printf("\n\t\t\tPembayaran yang Anda masukkan tidak cukup. Silakan masukkan pembayaran yang sesuai dengan total pembayaran.");
	} else {
// Jika pembayaran sudah cukup, simpan data pengembalian ke file "Pengembalian.bin"
		FILE * fPengembalian = fopen("Pengembalian.bin", "ab+");
		fwrite(&peminjaman, sizeof(peminjaman), 1, fPengembalian);
		fclose(fPengembalian);
	}
// Hapus data peminjaman dari file "Bukup.bin" dan simpan ke file "Bukup.bin" baru
	fclose(filePointer);
	filePointer = fopen("Bukup.bin", "wb");
	fclose(tempfP);
	tempfP = fopen("temp.bin", "rb");
	while (fread(&peminjaman, sizeof(peminjaman), 1, tempfP)) {
	fwrite(&peminjaman, sizeof(peminjaman), 1, filePointer);
	}

// Tampilkan pesan sukses
	printf("\n\t\t\tPengembalian buku berhasil dilakukan. Terima kasih sudah menggunakan layanan kami.");
}
}


int hitung_selisih_hari(char tanggal_batasX[], char tanggal_pengembalianY[]) {
// Deklarasi variabel
int tahun_batas, tahun_pengembalian, bulan_batas, bulan_pengembalian, tanggal_batas, tanggal_pengembalian;
int selisih_tahun, selisih_bulan, selisih_tanggal;

// Ambil tahun, bulan, dan tanggal dari input tanggal batas peminjaman dan tanggal pengembalian
sscanf(tanggal_batasX, "%d/%d/%d", &tanggal_batas, &bulan_batas, &tahun_batas);
sscanf(tanggal_pengembalianY, "%d/%d/%d", &tanggal_pengembalian, &bulan_pengembalian, &tahun_pengembalian);

// Hitung selisih tahun, bulan, dan tanggal
selisih_tahun = tahun_pengembalian - tahun_batas;
selisih_bulan = bulan_pengembalian - bulan_batas;
selisih_tanggal = tanggal_pengembalian - tanggal_batas;

// Jika selisih bulan atau tanggal kurang dari 0, kurangi selisih tahun dan tambahkan 12 pada selisih bulan
if (selisih_bulan < 0) {
selisih_tahun--;
selisih_bulan += 12;
}
if (selisih_tanggal < 0) {
selisih_bulan--;
selisih_tanggal += 30; // Asumsi jumlah hari dalam setiap bulan adalah 30
}

// Return selisih hari
return selisih_tahun * 365 + selisih_bulan * 30 + selisih_tanggal;
}*/

void pengembalian(void){
  system("cls");
  printf("\n\t\t\t=========================================================================== ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");
  printf("\n\t\t\t                         <<< Menu Pengembalian >>>                          ");
  printf("\n\t\t\t--------------------------------------------------------------------------- ");

  //Fungsi menghapus buku yang dikembalikan
  int ketemu = 1, bukup = 0;
  FILE * filePointer;
  FILE * tempfP;
  Peminjaman peminjaman = {
    0
  }; //Memanggil ke struct ke fungsi
  filePointer = fopen("Bukup.bin", "rb");
  tempfP = fopen("temp.bin", "wb");

  printf("\n\t\t\tMasukan Kode Buku yang sudah dikembalikan:");
  fflush(stdin);
  scanf(" %d", & bukup);

  while (fread( & peminjaman, sizeof(peminjaman), 1, filePointer)) {
    if (peminjaman.kodep_buku != bukup) {
      fwrite( & peminjaman, sizeof(peminjaman), 1, tempfP);
    } else {
      ketemu = 0;
    }
  }
  if (ketemu != '1') {
    printf("\n\t\t\tBuku telah dikembalikan");
    getchar();
  } else {
    printf("\n\t\t\tBuku tidak ditemukan");
    getchar();
  }
	  fclose(filePointer);
	  fclose(tempfP);
	  remove("Bukup.bin");
	  rename("temp.bin", "Bukup.bin");
  printf("\n\t\t\tTekan tombol enter untuk kembali ke menu utama");
  fflush(stdin);
  getchar();
  system("cls");
}

void help(){
	printf ("\n		");
	system("pause");
	system("cls");
	printf ("\t\t=======================================\n");
	printf ("\t\t             Bantuan/Help\n");
	printf ("\t\t=======================================\n");
	printf("\n1. Aplikasi ini bertujuan untuk merekam peminjaman buku dan data buku\n   yang tersedia.\n");
	printf("2. Harap memasukkan jumlah data input sesuai yang diminta.\n");
	printf("3. Masukkan biodata peminjam pada menu peminjaman dengan nama lengkap (nama peminjam buku).\n");
	printf("4. Contoh input nama pada menu peminjaman :  Maxwell Firman \n");
	printf("5. Input data berlebih akan secara otomatis menjadi data input\n   untuk input selanjutnya.\n");
	printf("6. Hanya dapat meminjam buku yang ada di Daftar Buku Tersedia.\n");
	printf("7. Pada konfirmasi tekan tombol enter untuk kembali pada menu. \n");
	printf("\nAkan kembali ke MENU. ");
	system("pause");
	system("cls");
	menu();
}



int validasi (int x) {

	double pilihan = 0;
	int hasil;
	int i = 0;


	//perulangan validasi
	do {
		pilihan = scanf("%d", &hasil);

		while(getchar() != '\n') {
			//tidak ada proses
		}

		if (pilihan == 0) {
			printf("Input Invalid!! Pilih Dengan Benar : ");
		} else if (x==1) {
			if (hasil > 9 || hasil <= 0) {
				printf("Input Invalid!! Pilih Dengan Benar : ");
			} else {
				i = 1;
			}
		}else {
			i = 1;
		}

	} while (i != 1);

	return hasil;

}


int main(void) {
  login();
  return 0;
}
