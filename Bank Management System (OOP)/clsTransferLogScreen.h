#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:

		static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord LoginRegisterRecord)
		{

			cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
			cout << "| " << setw(10) << left << LoginRegisterRecord.sAcountNumber;
			cout << "| " << setw(10) << left << LoginRegisterRecord.dAcountNumber;
			cout << "| " << setw(10) << left << LoginRegisterRecord.Amount;
			cout << "| " << setw(10) << left << LoginRegisterRecord.sBalance;
			cout << "| " << setw(10) << left << LoginRegisterRecord.dBalance;
			cout << "| " << setw(10) << left << LoginRegisterRecord.User;
		}

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList() ;

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Lo Available In the System!";
        else
            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

