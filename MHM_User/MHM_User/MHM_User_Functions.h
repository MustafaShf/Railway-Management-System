#ifndef Functions_H
#define Functions_H
#include"MHM_User_Classes.h"

int UserSelection::GetData(UserDataRetriever *& b)
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
		String^ trainQuery = "SELECT * FROM Trains";

		sqlConn->Open();

		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows
		b = new UserDataRetriever[rowCount];

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);
		SqlCommand^ commandSchedule = gcnew SqlCommand(scheduleQuery, sqlConn);
		SqlCommand^ commandTrain = gcnew SqlCommand(trainQuery, sqlConn);

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
			b[i].UserDataSetter(value, startStr, endStr);
			i++;
		}
		reader->Close();

		//schedules
		int* ptr = new int[24];
		i = 0;
		SqlDataReader^ readerSchedule = commandSchedule->ExecuteReader();
		while (readerSchedule->Read())	//just like while(fin >> whatever) for file handling
		{
			//reading
			for (int j = 0; j < 24; j++)
			{
				ptr[j] = Convert::ToInt32(readerSchedule[j + 1]);
			}

			//setting the data
			b[i].scheduleUserSetter(ptr);
			i++;
		}
		readerSchedule->Close();

		//trains
		int* ptr1 = new int[3];
		i = 0;
		SqlDataReader^ trainReader = commandTrain->ExecuteReader();
		while (trainReader->Read())	//just like while(fin >> whatever) for file handling
		{
			//reading
			for (int j = 0; j < 3; j++)
			{
				ptr1[j] = Convert::ToInt32(trainReader[j + 1]);
			}

			//setting the data
			b[i].trainsUserSetter(ptr1);
			i++;
		}
		trainReader->Close();

		sqlConn->Close();
		delete ptr;
		delete ptr1;
		ptr = nullptr;
		ptr1 = nullptr;

		return rowCount;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database" + e->Message, "Database Connection Error", MessageBoxButtons::OK);
		return rowCount;
	}
}
#endif