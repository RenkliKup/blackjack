// Blackjack_ve_class_tasarımı.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;
//degerler
#define as 0
#define joker 10
#define kiz 11
#define papaz 12
//4 temel taş
#define karo 0
#define sinek 1
#define maca 2
#define kupa 3

//kart tasarımı
class kart
{
protected:

	int deger;
	int temel;

public:
	kart(int temel = karo, int deger = 2) :temel(temel), deger(deger)
	{

	}

	void yazdir()
	{

		switch (temel)
		{
		case karo:

			cout << "Karo";
			break;
		case sinek:

			cout << "Sinek";
			break;
		case maca:

			cout << "Maca";
			break;
		case kupa:

			cout << "Kupa";
			break;
		default:
			cout << temel;
			break;
		}

		cout << " ";
		switch (deger)
		{
		case as:

			cout << "As";
			break;
		case joker :

			cout << "Joker";
			break;
		case kiz:

			cout << "Kiz";
			break;
		case papaz :

			cout << "Papaz";
			break;
		default:
			cout << deger+1;
			break;
		}
	}
	
	int getDeger()
	{
		return deger;
	}
	int getTemel()
	{
		return temel;
	}
};
//--------------------------------
//------------Deste Tasarımı--------------
class deste:public kart
{
protected:
	kart kd[52];
public:
	void deste_olustur()
	{
		for (size_t i = 0; i < 52; i++)
		{
			kd[i] = kart(i/13,i%13);
		}
	}
	void deste_yazdir()
	{
		for (size_t i = 0; i < 52; i++)
		{
			kd[i].yazdir(); cout << endl;
		}
	}
	void karistir()
	{
		kart temp;
		for (size_t i = 0; i < 52; i++)
		{
			int x = rand() % 52;
			int y = rand() % 52;
			temp = kd[x];
			kd[x] = kd[y];
			kd[y] = temp;
			
		}
	}
};
//---------------------------------
class blackjack:public deste
{
public:
	int ckt = 0;
	enum status {win,lose,devam};
	blackjack()
	{
		
			
	}
	void blackjack_giris()
	{
		
		for (size_t i = 0; i < 2; i++)
		{
			
			int x = rand() % 52;
			ckt =ckt+ kd[x].getDeger()+1;

			kd[x].yazdir(); cout << endl;
		}
		cout << "Kartlarin toplami:" << ckt << endl;
		
	}
	int kart_cek()
	{
		int x = rand() % 52;
			ckt = ckt + kd[x].getDeger() + 1;

			kd[x].yazdir(); cout << " Kart cekildi" << " kartlarin toplami: " << ckt << endl;
			if (ckt > 21)
			{
				
				return lose;
			}
			else
			{
				return devam;
			}
	}
	int yapay_zeka(blackjack& n)
	{
		while (true)
		{	
			if ((ckt > n.ckt) && (ckt <= 21))
			{
	
				return lose;
				break;
			}
			if (ckt > 21)
			{
				return win;
				break;
			}
			kart_cek();
		}
	}
	
}nesne;
int main()
{
	int bar = 0;
	int status = 2;
	int status2 = 2;
	char devam;
	srand(time(0));

	nesne.deste_olustur();
	nesne.blackjack_giris();
	blackjack yapay_zeka;


	while (true)
	{

		cout << "1-Kart Cek" << endl;
		cout << "2-Kal" << endl;
		cin >> bar;
		switch (bar)
		{
		case 1:

			status = nesne.kart_cek();

			break;
		case 2:
			cout << "----------------Yapay Zeka----------------" << endl;
			yapay_zeka.deste_olustur();
			yapay_zeka.blackjack_giris();
			status2 = yapay_zeka.yapay_zeka(nesne);
			break;
		default:
			cout << "Yanlis deger girdiniz Tekrar deneyiniz" << endl;
			break;
		}
		if (status == 0 || status2 == 0)
		{
			cout << "Kazandiniz" << endl;
			break;
		}
		if (status == 1 || status2 == 1)
		{
			cout << "Kaybettiniz" << endl;
			break;
		}
	}
	system("pause");
}

