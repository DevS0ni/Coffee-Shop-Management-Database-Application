/*
*****************************************************************************
						Secure Access DataBase Authenticator
SONI DEV ALPESHBHAI (Infernalkin)
*****************************************************************************
*/

#include <iostream>
#include<iomanip>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void)
{
	Environment* env = nullptr;
	Connection* conn = nullptr;
	Statement* stmt = nullptr;

	string str;
	// Used Oracle DataBase Service with credentials provided by the college.
	string usr = "dbs211_222j04";	//SONI DEV CREDENTIALS
	string pass = "12141168*";		//SONI DEV CREDENTIALS
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		stmt = conn->createStatement();


		ResultSet* rs1 = nullptr;
		rs1 = stmt->executeQuery("SELECT ORDERNUMBER n, TABLENUMBER, PRODUCTNAME, QUANTITY, ORDERDATE FROM NEWORDERDETAILS n LEFT OUTER JOIN TABLEDETAILS t USING (TABLEID) 	LEFT OUTER JOIN ORDERITEM o USING (ORDERID) 	LEFT OUTER JOIN PRODUCT p USING (PRODUCTID) ORDER BY ORDERNUMBER DESC");
		cout << "----------------------------- Report 1 (All Orders) -----------------------------" << endl;
		cout << "Order Number  Table  Product                                 Quantity  Date     " << endl;
		//		 150           52     Peached Italia Drink - Estathe          15                29-JUL-22
		cout << "------------  -----  --------------------------------------  --------  ----------" << endl;

		if (!rs1->next())
		{
			cout << "ResultSet is empty." << endl;
		}
		else
		{
			do
			{
				cout << setw(14) << left << rs1->getString(1) << setw(7) << left << rs1->getString(2) << setw(40) << left << rs1->getString(3) << setw(10) << left << rs1->getString(4) << setw(16) << left << rs1->getString(5) << endl;
			} while (rs1->next());

		}

		ResultSet* rs2 = nullptr;
		rs2 = stmt->executeQuery("SELECT ORDERNUMBER n,  TABLENUMBER,  CUSTOMERNAME,  OUTSTANDINGAMOUNT,  ORDERDATE  FROM NEWORDERDETAILS n LEFT OUTER JOIN TABLEDETAILS t USING (TABLEID) 	 	LEFT OUTER JOIN CUSTOMER o USING (CUSTOMERID) ORDER BY ORDERNUMBER DESC");
		cout << endl << "----------------------------- Report 2 (Outstanding Orders) ---------------------" << endl;
		cout <<			"Order Number  Table  Customer                             Ammount         Date     " << endl;
		cout <<			"------------  -----  -----------------------------------  -----------  ----------" << endl;

		if (!rs2->next())
		{
			cout << "ResultSet is empty." << endl;
		}
		else
		{
			do
			{
				cout << setw(14) << left << rs2->getString(1) << setw(7) << left << rs2->getString(2) << setw(37) << left << rs2->getString(3) << setw(13) << left << rs2->getString(4) << setw(1) << left << rs2->getString(5) << endl;
			} while (rs2->next());

		}

		ResultSet* rs3 = nullptr;
		rs3 = stmt->executeQuery("SELECT PRODUCTID p,  PRODUCTNAME, TITLE c, UNITPRICE, AVAILABLE  FROM PRODUCT p LEFT OUTER JOIN CATEGORY c USING (CATEGORYID) 	 ORDER BY AVAILABLE, PRODUCTNAME ");
		cout << endl << "------------------------- Report 3 (Inventory Availability) ---------------------" << endl;
		cout <<			"ID     Product                          Category           Price        Available" << endl;
		cout <<			"-----  ------------------------------   -----------------  -----------  ---------" << endl;

		if (!rs3->next())
		{
			cout << "ResultSet is empty." << endl;
		}
		else
		{
			do
			{
				cout << setw(7) << left << rs3->getString(1) << setw(33) << left << rs3->getString(2) << setw(19) << left << rs3->getString(3) << setw(13) << left << rs3->getString(4) << setw(16) << left << rs3->getString(5) << endl;
			} while (rs3->next());

		}

		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}

