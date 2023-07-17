#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100 ;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;
string jurusan[MAX_MAHASISWA];
int arr[100];

void tambahMahasiswa(const int MAX_MAHASISWA, int jumlahMahasiswa, int arr[]) {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "========== TAMBAH MAHASISWA ==========" << endl;
		cout << "NIM : ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore();
		cout << "Nama : ";
		getline(cin, nama[jumlahMahasiswa]);
		cout << "Jurusan : ";
		getline(cin, jurusan[jumlahMahasiswa]);
		cout << "Tahun Masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];
		cin.ignore();
		jumlahMahasiswa++;
		cout << "Mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
}


void tampilkanSemuaMahasiswa(int arr[]) {
	
		cout << "================SEMUA DATA MAHASISWA================";
		for (int jumlahMahasiswa = 0; jumlahMahasiswa < MAX_MAHASISWA; jumlahMahasiswa++)
		{
			cout << arr[MAX_MAHASISWA] << " ";
		}
}


void algorithmacariMahasiswaByNIM() {
		cout << "\nMasukkan NIM yang akan dicari : ";
		int item;
		cin >> item;

		int lb;
		int ub;
		int mid;

		lb = 0;
		ub = jumlahMahasiswa - 1;


		while (lb <= ub)
		{

			mid = (lb + ub) / 2;
			if (arr[mid] == item)
			{
				cout << arr[jumlahMahasiswa];
				break;
			}
			else {
				if (item < arr[mid])
				{
					
					ub = mid - 1;
				}
				else
				{
					
					lb = mid + 1;
				}
			}
		}
		if (lb > ub)

			cout << "\n" << item << " tidak ditemukan " << endl;
		
}

void algorithmaSortByTahunMasuk(int low, int high) {
	int pivot, i, j;
	int low;
	int high;
	if (low > high)
		return;

	

	pivot = arr[low];	 

	i = low + 1;		
	j = high;			

	while (i <= j)		
	{
		
		while ((arr[i] <= pivot) && (i <= high)) 
		{										
			i++;								
		}
		

	
		while ((arr[j] > pivot) && (j >= low))		
		{
			j--;									
		}
		
		if (i < j)
		{
			swap(i, j); 
			
		}
	}

	if (low < j)	
	{
		swap(low, j);			
	}
	
	algorithmaSortByTahunMasuk(low, j - 1);


	algorithmaSortByTahunMasuk(j + 1, high);
}
int main() {
	int pilihan;
	int arr[MAX_MAHASISWA];
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa(MAX_MAHASISWA, jumlahMahasiswa, arr);
			break;
		case 2:
			tampilkanSemuaMahasiswa(arr);
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			algorithmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

//2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan?
// terdapat 2 algoritma yang digunakan yaitu search, sort
//3. Jelaskan perbedaan mendasar antara algorithma stack dan queue!
//		Algoritma STACK menggunakan prinsip LIFO yaitu Last in first out dimana yang terakhir masuk ialah yang keluar pertama (diproses terlebih dahulu)
//		Algoritma Queue menggunakan prinsip FIFO yaitu first in first out dimana yang pertama kali masuk ialah yang akan keluar pertama (diproses terlebih dahulu)
//4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack?
// algoritma stack dapat digunakan ketika sebuah data yang terakhir masuk dan yang pertama keluar
//5 a. jumlah kedalaman dari struktur tersebut adalah 5
//	b. 
// in = 1 5 8 10 12 15 20 22 25 28 30 36 38 40 45 48 50
// preorder = 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50
// postorder = 1 8 5 15 12 10 22 20 28 30 38 45 50 48 40 36 25