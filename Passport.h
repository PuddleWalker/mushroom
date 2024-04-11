#pragma once
#include<string>
#include<vector>

using namespace std;

class Passport
{
protected:
	enum gender : bool {
		female = false,
		male = true
	};
	string FullName{"Ivanov Ivan Ivanovich"};
	bool Gen{ true };
	string BirthDate{"01.01.2000"};
	string BirthPlace{ "BirthPlace" };
	string Registration{ "None" };
	bool MilitaryDuty{ false };
	bool FamilyStatus{ false };
	int Children{ 0 };
	int Number { 1234567890 };
public:
	Passport(string Name) : FullName{ Name } {};
	Passport(string Name, string BirthDate) : BirthDate{ BirthDate }, FullName{ Name } {};
	void EditInfo(int Info, int num)
	{
		switch (num)
		{
			case 1:
				Number = Info;
				break;
			case 9:
				Children = Info;
				break;
		}
	}
	void EditInfo(string Info, int num)
	{
		switch (num)
		{
			case 2:
				FullName = Info;
				break;
			case 4:
				BirthDate = Info;
				break;
			case 5:
				BirthPlace = Info;
				break;
			case 6:
				Registration = Info;
				break;
		}
	}
	void EditInfo(bool Info, int num)
	{
		switch (num)
		{
			case 3:
				Gen = Info;
				break;
			case 7:
				MilitaryDuty = Info;
				break;
			case 8:
				FamilyStatus = Info;
				break;
		}
	}
	void show()
	{
		cout << "\t\t" << Number << endl << endl;
		cout << "�.�.�.: " << FullName << endl;
		cout << "���: ";
		if (Gen) cout << "�������\n";
		else cout << "�������\n";
		cout << "���� ��������: " << BirthDate << endl;
		cout << "����� ��������: " << BirthPlace << endl;
		cout << "����� ����������: ";
		if (Registration == "None")
			cout << "�� ���������������\n";
		else {
			cout << "��������������� �� ������, " << Registration << endl;
		}
		cout << "�������� �����������: ";
		if (MilitaryDuty) cout << "������";
		else cout << "��������";
		if (!Gen) cout << "� ";
		cout << " ���������\n�������� �����������\n";
		if (Children > 0) {
			cout << "���������� �����: " << Children;
		}
		cout << "�������� ���������: ";
		if (!FamilyStatus) cout << "���� �� ���������������\n";
		else cout << "��������������� ����\n";
		cout << "���������� �����: " << Children << endl;
	}
};


class ForeignPassport : public Passport
{
private:
	struct Visa
	{
		string Duration = "45D";
		string Country = "Russia";
		string Remarks = "tourism";
	};
	int FNumber{ 1234567890 };
	vector<Visa> Visas;
	int counter = 0;
public:
	void AddVisa(){
		counter++;
		Visa elem;
		Visas.push_back(elem);
	}
	void DellVisa(int num){
		auto iter = Visas.begin();
		if (counter > 0 and num > -1 and num < counter - 1)
		{
			counter--;
			Visas.erase(iter + num);
		}
		else cout << "������������ ��� ��� ��������\n";
	}
	void EditVisaInfo(int num, int numb, string Info){
		if (counter > 0) {
			switch (num)
			{
			case 1:
				Visas[numb - 1].Duration = Info;
				break;
			case 2:
				Visas[numb - 1].Country = Info;
				break;
			case 3:
				Visas[numb - 1].Remarks = Info;
				break;
			}
		}
		else cout << "������������ ��� ��� ��������\n";
	}
	void Fshow(){
		show();
		int count = 1;
		cout << "\t\t" << FNumber << endl << endl;
		if (counter > 0) cout << "����:\n\n";
		for (auto elem : Visas) {
			cout << count << ":\n";
			cout << "������: " << elem.Country << endl;
			cout << "������������ ����: " << elem.Duration << endl;
			cout << "���� ���������: " << elem.Remarks << endl;
		}
	}
	using Passport::Passport;
};
