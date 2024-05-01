#ifndef Function_H
#define Function_H
#include"MHM_Classes.h"

int Admin::GetData(dataRetriever * &a)
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

		sqlConn->Open();

		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows
		a = new dataRetriever[rowCount];

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);
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
#endif