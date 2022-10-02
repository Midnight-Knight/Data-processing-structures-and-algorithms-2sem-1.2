#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int x,y,KolVo;
	int t1, t2;
	cout << "¬ведите кол-во генирируемых чисел: ";
	cin >> KolVo;
	vector <int> Num;
	x = 79999999;
	y = 70000000;
	for (int i = 0; i < KolVo; ++i)
	{
		Num.push_back((y + rand() % (x-y)));
	}
	for (int i = 0; i < Num.size(); ++i)
	{
		cout << Num[i] << " ";
		if (((i % 20) == 0) && (i != 0))
		{
			cout << endl;
		}
	}
	cout << endl << endl;
	bool* sor = new bool[x-y];
	for (int i = 0; i < (x-y); ++i)
	{
		sor[i] = false;
	}
	t1 = clock();
	for (int i = 0; i < Num.size(); ++i)
	{
		sor[Num[i]-y] = true;
	}
	t2 = clock();
	t2 = t2 - t1;
	int j = 0;
	for (int i = 0; i < (x-y); ++i)
	{
		if (sor[i] == true)
		{
			cout << y + i << " ";
			if (((j % 20) == 0) && (j != 0))
			{
				cout << endl;
			}
			j++;
		}
	}
	cout << endl << endl << "¬рем€ (в секундах): " << (double(t2)) / CLOCKS_PER_SEC << endl; // 
	return 0;
}
