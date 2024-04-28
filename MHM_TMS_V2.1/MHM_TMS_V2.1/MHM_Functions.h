#include"MHM_Classes.h"

int Admin::GetData(int*& all_routes, string*& start, string*& end, int**& schedules)
{
	int i = 0, number_of_rectangles = 0;
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
		int rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows

		all_routes = new int[rowCount];
		start = new string[rowCount];
		end = new string[rowCount];
		schedules = new int* [rowCount];	//will contain available schedules for each route

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);
		SqlDataReader^ reader = command->ExecuteReader();
		while (reader->Read())
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

			//getting the data
			all_routes[i] = value;
			start[i] = startStr;
			end[i] = endStr;
			i++;
		}
		reader->Close();
		sqlConn->Close();		

	}
	catch(Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database" + e->Message, "Database Connection Error", MessageBoxButtons::OK);
	}
	return i;
}

void Admin::ChangeRouteAvailability(int* all_routes)
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
			command->Parameters->AddWithValue("@Availability", all_routes[i]);
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