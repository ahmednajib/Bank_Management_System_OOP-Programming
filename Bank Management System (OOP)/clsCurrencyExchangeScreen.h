#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
    enum enCurrencieMainMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3
        ,CurrencyCalculator = 4, MainMenue = 5
    };

    static short _ReadCurrencyExchangeOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenueScreen()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowCurrenciesExchangeMenue();
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "List Currency Screen Will be here";
        clsListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "Find Currency Screen Will be here";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        //cout << "Update Rate Screen Will be here";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "Currency Calculator Screen Will be here";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();        
    }

    static void _PerfromCurrencyExchangeOption(enCurrencieMainMenueOptions CurrencyExchangeOption)
    {
        switch (CurrencyExchangeOption)
        {
        case enCurrencieMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencieMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencieMainMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencieMainMenueOptions::CurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenueScreen();
            break;
        }
        case enCurrencieMainMenueOptions::MainMenue:
        {

            //do nothing here the main screen will handle it :-) ;

        }

        }
    }

public:

	static void ShowCurrenciesExchangeMenue()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchang))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExchangeOption((enCurrencieMainMenueOptions)_ReadCurrencyExchangeOption());
	}
};

