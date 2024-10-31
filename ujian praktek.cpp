#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 4 // maksimal data antrian
using namespace std;

struct Deklarasi
{
	int front, rear, data[MAX];
} d;

struct nama
{
	char mn[50];
	Deklarasi dek;
} name[100];

// cek apakah antrian penuh
bool isFull()
{
	return d.rear == MAX;
}

// cek apakah antrian kosong
bool isEmpty()
{
	return d.rear == 0;
}

// Menampilkan Queue
void printQueue(int i,int j)
{
	if (isEmpty())
	{
		cout << "Antrian Kosong" << endl;
	}
	else
	{
		cout << "\nAntrian yang masuk : ";
		for (int i = d.front; i < d.rear; i++)
		{
			cout << name[i].mn << ((d.rear - 1 == i) ? "" : ",");
		}
		for (i; i > j; i--)
		{
			if (isEmpty())
			{
				cout << " ";
			}
			else
			{
				cout << ",Kosong";
			}
		}
		i++;
	}
}

// menambahkan data ke antrian
void enqueue(int i, int c)
{
	if (isFull())
	{
		// menambahkan data ke antrian
		cout << "\nMasukkan nama :";
		cin >> name[i].mn;
	}
	else
	{
		if (i != MAX)
		{
			// menambahkan data ke antrian
			cout << "\nMasukkan nama :";
			cin >> name[i].mn;
			// menempatkan tail pada elemen data terakhir yang ditambahkan
			d.rear++;
		}
	}
	if (i == c - 1)
	{
		i = 0;
		cout << "\n->> Beberapa Pengunjung Mengantri\n";
		d.rear = 0;
		for (i; i < c; i++)
		{
			if (i + 1 > MAX)
			{
				cout << name[i].mn << " Maaf Antrian Sudah Penuh\n";
			}
			else
			{
				cout << name[i].mn << " Masuk Antrian\n";
			}
			d.rear++;
		}
		cout << "Antrian Yang Masuk : ";
		for (int i = d.front; i < MAX; i++)
		{
			cout << name[i].mn << ((d.rear - 1 == i) ? "" : ",");
		}
	}
}

// mengambil data dari antrian
void dequeue(int i)
{
	int j=0;
	if (isEmpty())
	{
		cout << "Antrian masih kosong" << endl;
	}
	else
	{
		cout << name[d.front].mn << " Telah Keluar Dari Resto" << endl;
		// menggeser antrian data ke head
		for (int i = d.front; i < d.rear; i++)
		{
			name[i] = name[i + 1];
			j++;
		}
		d.data[d.rear] = 0;
		d.rear--;
		printQueue(i,j);
	}
}

int main()
{
	int choose;
	int i, c;
	do
	{
		// tampilan menu
		cout << "\n------------------" << endl;
		cout << "   Menu Pilihan " << endl;
		cout << "------------------" << endl;
		cout << " [1] Pengunjung Masuk " << endl;
		cout << " [2] Pengunjung Keluar " << endl;
		cout << " [3] Keluar \n\n"
			 << endl;
		cout << "------------------" << endl;
		cout << "Masukkan Pilihan : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			printf("Masukan Jumlah Pengunjung : ");
			scanf("%d", &c);
			for (i = 0; i < c; i++)
				enqueue(i, c);
			break;
		case 2:
			dequeue(i);
			break;
		default:
			cout << "Pilihan tidak tersedia\n";
			break;
		}
	} while (choose != 3);
	return 0;
}