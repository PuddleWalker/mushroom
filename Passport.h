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
		cout << "Ф.И.О.: " << FullName << endl;
		cout << "Пол: ";
		if (Gen) cout << "Мужской\n";
		else cout << "Женский\n";
		cout << "Дата рождения: " << BirthDate << endl;
		cout << "Место рождения: " << BirthPlace << endl;
		cout << "Место жительства: ";
		if (Registration == "None")
			cout << "не зарегистрирован\n";
		else {
			cout << "зарегистрирован по адресу, " << Registration << endl;
		}
		cout << "Воинская обязанность: ";
		if (MilitaryDuty) cout << "Обязан";
		else cout << "Необязан";
		if (!Gen) cout << "а ";
		cout << " исполнять\nвоинскую обязанность\n";
		if (Children > 0) {
			cout << "Количество детей: " << Children;
		}
		cout << "Семейное положение: ";
		if (!FamilyStatus) cout << "Брак не зарегистрирован\n";
		else cout << "Зарегистрирован брак\n";
		cout << "Количество детей: " << Children << endl;
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
		else cout << "Недостаточно виз для операции\n";
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
		else cout << "Недостаточно виз для операции\n";
	}
	void Fshow(){
		show();
		int count = 1;
		cout << "\t\t" << FNumber << endl << endl;
		if (counter > 0) cout << "Визы:\n\n";
		for (auto elem : Visas) {
			cout << count << ":\n";
			cout << "Страна: " << elem.Country << endl;
			cout << "Длительность визы: " << elem.Duration << endl;
			cout << "Цель посещения: " << elem.Remarks << endl;
		}
	}
	using Passport::Passport;
};
