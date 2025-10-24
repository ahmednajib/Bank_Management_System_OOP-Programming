#pragma once
#include<iostream>
#include<string>
#include "clsDate.h";
using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <=To)
		{
			return true;
		}

		return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}

		return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1BeforeDate2(To, From))
		{
			clsDate::SwapDates(From, To);
		}

		if (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1AfterDate2(Date, To))
			return false;

		return true;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number,From,To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static float ReadFloatNumberBetween(string ErrorMessage = "Invalid Number, Enter again.\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again.\n")
	{
		double Number;
		
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static int ReadpositiveIntNumebr(string ErrorMessage = "Please Enter a positive Number:\n")
	{
		int Number = ReadIntNumber("Invalid Number, Enter again.\n");

		while (Number < 0)
		{
			cout << ErrorMessage << endl;
			Number = ReadIntNumber("Invalid Number, Enter again.\n");
		}

		return Number;
	}

	static double ReadpositiveDblNumebr(string ErrorMessage = "Please Enter a positive Number:\n")
	{
		double Number = ReadDblNumber("Invalid Number, Enter again.\n");

		while (Number < 0)
		{
			cout << ErrorMessage << endl;
			Number = ReadDblNumber("Invalid Number, Enter again.\n");
		}

		return Number;
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};