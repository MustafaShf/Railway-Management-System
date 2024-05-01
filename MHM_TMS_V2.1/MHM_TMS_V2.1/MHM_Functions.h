#ifndef Function_H
#define Function_H
#include"MHM_Classes.h"

int Admin::GetData(dataRetriever * &a, Admin &admin)
{
	int i = 0;
	int rowCount = 0;
	//conecting to the database and getting the data
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		//queries
		String^ countQuery = "SELECT COUNT(*) AS [RowCount] FROM routes;"; //getting total routes/rows of database
		String^ selectQuery = "SELECT * FROM routes;";
		String^ scheduleQuery = "SELECT * FROM schedules;";
		String^ fareQuery = "SELECT * FROM fares";

		sqlConn->Open();

		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows
		a = new dataRetriever[rowCount];

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);
		SqlCommand^ commandSchedule = gcnew SqlCommand(scheduleQuery, sqlConn);
		SqlCommand^ commandFare = gcnew SqlCommand(fareQuery, sqlConn);

		//routes
		SqlDataReader^ reader = command->ExecuteReader();
		while (reader->Read())	//just like while(fin >> whatever) for file handling
		{
			//reading
			int value = Convert::ToInt32(reader["availability"]);

			//conversion where necessary
			String^ startValue = reader["start"]->ToString();
			String^ endValue = reader["end"]->ToString();

			const char* startChars = (const char*)(Marshal::StringToHGlobalAnsi(startValue)).ToPointer();
			const char* endChars = (const char*)(Marshal::StringToHGlobalAnsi(endValue)).ToPointer();
			string startStr(startChars);
			string endStr(endChars);

			Marshal::FreeHGlobal(IntPtr((void*)startChars));
			Marshal::FreeHGlobal(IntPtr((void*)endChars));

			//setting the data
			a[i].dataSetter(value, startStr, endStr);
			i++;
		}
		reader->Close();

		//schedules
		int* ptr = new int[24];
		SqlDataReader^ readerSchedule = commandSchedule->ExecuteReader();
		while (readerSchedule->Read())	//just like while(fin >> whatever) for file handling
		{
			//reading
			for (int j = 0; j < 24; j++)
			{
				ptr[j] = Convert::ToInt32(readerSchedule[j+1]);
			}

			//setting the data
			a[i].scheduleSetter(ptr);
			i++;
		}
		readerSchedule->Close();

		//fares
		SqlDataReader^ readerFare = commandFare->ExecuteReader();
		while (readerFare->Read())
		{
			int value1 = Convert::ToInt32(readerFare["routePrice"]);
			int value2 = Convert::ToInt32(readerFare["Executive"]);
			int value3 = Convert::ToInt32(readerFare["Economic"]);
			int value4 = Convert::ToInt32(readerFare["Business"]);

			admin.AdminSetter(value1, value2, value3, value4);
		}

		readerFare->Close();
		sqlConn->Close();
		return rowCount;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database" + e->Message, "Database Connection Error", MessageBoxButtons::OK);
		return rowCount;
	}
}


void Admin::ChangeRouteAvailability(dataRetriever* all_routes)
{
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		//queries
		String^ countQuery = "SELECT COUNT(*) AS [RowCount] FROM routes;"; //getting total routes/rows of database

		sqlConn->Open();
		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		int rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows

		for (int i = 0; i < rowCount; i++)
		{
			//update query
			String^ updateQuery = "UPDATE routes SET availability = @Availability WHERE id = @ID;";
			SqlCommand^ command = gcnew SqlCommand(updateQuery, sqlConn);

			//putting on the database
			command->Parameters->AddWithValue("@Availability", all_routes[i].availabilityGetter());
			command->Parameters->AddWithValue("@ID", i + 1);

			//Execute the update query
			command->ExecuteNonQuery();
		}
		MessageBox::Show("Availability updated successfully", "Update Success", MessageBoxButtons::OK);
		sqlConn->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to update availability: " + e->Message, "Update Error", MessageBoxButtons::OK);
	}
}

bool isPositiveInteger(String^ text)
{
	int value;
	if (Int32::TryParse(text, value) && value > 0)		//turns the input into int, then checks if it is >0 or not
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Admin::SetFare(String^ text1, String^ text2, String^ text3, String^ text4, Admin &admin)
{
	admin.AdminSetter(Convert::ToInt32(text1), Convert::ToInt32(text2), Convert::ToInt32(text3), Convert::ToInt32(text4));

	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		sqlConn->Open();

		//update query
		String^ updateQuery = "UPDATE fares SET routePrice = @RoutePrice, Executive = @executive, Economic = @economic, Business = @business WHERE id = @ID;";
		SqlCommand^ command = gcnew SqlCommand(updateQuery, sqlConn);
		
		//putting on the database
		command->Parameters->AddWithValue("@RoutePrice", admin.routePriceGetter());
		command->Parameters->AddWithValue("@executive", admin.ExecutiveGetter());
		command->Parameters->AddWithValue("@economic", admin.EconomicGetter());
		command->Parameters->AddWithValue("@business", admin.BusinessGetter());
		command->Parameters->AddWithValue("@ID", 1);

		//Execute the update query
		command->ExecuteNonQuery();

		MessageBox::Show("Fare updated successfully", "Update Success", MessageBoxButtons::OK);
		sqlConn->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to update fare: " + e->Message, "Update Error", MessageBoxButtons::OK);
	}


}

#endif