#ifndef PaymentF_H
#define PaymentF_H
#include"MHM_User_Classes.h"
using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

int paymentFare::calculateFare(int economicSeats, int businessSeats, int executiveSeats)
{
	Totalfare = 0;

	int rowCount = 0;
	//conecting to the database and getting the data
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		//queries
		String^ selectQuery = "SELECT * FROM fares;";

		sqlConn->Open();

		//execution of queries

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);

		//routes
		SqlDataReader^ reader = command->ExecuteReader();
		while (reader->Read())	//just like while(fin >> whatever) for file handling
		{
			//reading
			int rp = Convert::ToInt32(reader["routePrice"]);
			int ex = Convert::ToInt32(reader["Executive"]);
			int ec = Convert::ToInt32(reader["Economic"]);
			int b = Convert::ToInt32(reader["Business"]);

			//setting the data
			Totalfare = rp + ex * executiveSeats + ec * economicSeats + b * businessSeats;
		}
		reader->Close();

		return Totalfare;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database" + e->Message, "Database Connection Error", MessageBoxButtons::OK);
		return Totalfare;
	}
}
#endif