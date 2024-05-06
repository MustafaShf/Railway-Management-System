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
		String^ trainQuery = "SELECT * FROM Trains";

		sqlConn->Open();

		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows
		a = new dataRetriever[rowCount];

		SqlCommand^ command = gcnew SqlCommand(selectQuery, sqlConn);
		SqlCommand^ commandSchedule = gcnew SqlCommand(scheduleQuery, sqlConn);
		SqlCommand^ commandFare = gcnew SqlCommand(fareQuery, sqlConn);
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
			a[i].dataSetter(value, startStr, endStr);
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
			a[i].trainsSetter(ptr1);
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

int Admin::viewFeedback(dataRetriever * &a)
{
	int i = 0;
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		sqlConn->Open();

		//queries
		String^ countQuery = "SELECT COUNT(*) AS [FeedbackCount] FROM userFb;"; //getting total feedbacks from database
		String^ readFeedbackQuery = "SELECT * FROM userFb;";

		//Execute queries
		SqlCommand^ Countcommand = gcnew SqlCommand(countQuery, sqlConn);
		int rowCount = Convert::ToInt32(Countcommand->ExecuteScalar());	//number of rows

		SqlCommand^ command = gcnew SqlCommand(readFeedbackQuery, sqlConn);
		SqlDataReader^ Reader = command->ExecuteReader();
		while (Reader->Read())
		{
			a[i].FeedbackSetter(" ", " ", " ");

			//conversion where necessary
			String^ FeedbackValue = Reader["feedback"]->ToString();
			String^ seatNoValue = Reader["seatNo"]->ToString();
			String^ RatingValue = Reader["rating"]->ToString();

			const char* FeedbackChars = (const char*)(Marshal::StringToHGlobalAnsi(FeedbackValue)).ToPointer();
			const char* seatNoChars = (const char*)(Marshal::StringToHGlobalAnsi(seatNoValue)).ToPointer();
			const char* RatingChars = (const char*)(Marshal::StringToHGlobalAnsi(RatingValue)).ToPointer();
			string FeedbackStr(FeedbackChars);
			string seatNoStr(seatNoChars);
			string RatingStr(RatingChars);

			Marshal::FreeHGlobal(IntPtr((void*)FeedbackChars));
			Marshal::FreeHGlobal(IntPtr((void*)seatNoChars));
			Marshal::FreeHGlobal(IntPtr((void*)RatingChars));

			//setting the data
			a[i].FeedbackSetter(FeedbackStr, seatNoStr, RatingStr);
			i++;
		}
		Reader->Close();
		sqlConn->Close();
		return i;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to read feedback: " + e->Message, "Update Error", MessageBoxButtons::OK);
		return i;
	}
}

void Admin::SetAvailableSchedule(dataRetriever*a)
{
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		//queries
		String^ countQuery = "SELECT COUNT(*) AS [RowCount] FROM schedules;"; //getting total rows of database

		sqlConn->Open();
		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		int rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows

		for (int i = 0; i < rowCount; i++)
		{
			//update query
			String^ updateQuery = "UPDATE schedules SET [1:00] = @a, [2:00] = @b, [3:00] = @c, [4:00] = @d, [5:00] = @e, [6:00] = @f, [7:00] = @g, [8:00] = @h, [9:00] = @i, [10:00] = @j, [11:00] = @k, [12:00] = @l, [13:00] = @m, [14:00] = @n, [15:00] = @o, [16:00] = @p, [17:00] = @q, [18:00] = @r, [19:00] = @s, [20:00] = @t, [21:00] = @u, [22:00] = @v, [23:00] = @w, [24:00] = @x WHERE id = @ID;";
			SqlCommand^ command = gcnew SqlCommand(updateQuery, sqlConn);

			//putting on the database
			command->Parameters->AddWithValue("@a", a[i].scheduleGetter()[0]);
			command->Parameters->AddWithValue("@b", a[i].scheduleGetter()[1]);
			command->Parameters->AddWithValue("@c", a[i].scheduleGetter()[2]);
			command->Parameters->AddWithValue("@d", a[i].scheduleGetter()[3]);
			command->Parameters->AddWithValue("@e", a[i].scheduleGetter()[4]);
			command->Parameters->AddWithValue("@f", a[i].scheduleGetter()[5]);
			command->Parameters->AddWithValue("@g", a[i].scheduleGetter()[6]);
			command->Parameters->AddWithValue("@h", a[i].scheduleGetter()[7]);
			command->Parameters->AddWithValue("@i", a[i].scheduleGetter()[8]);
			command->Parameters->AddWithValue("@j", a[i].scheduleGetter()[9]);
			command->Parameters->AddWithValue("@k", a[i].scheduleGetter()[10]);
			command->Parameters->AddWithValue("@l", a[i].scheduleGetter()[11]);
			command->Parameters->AddWithValue("@m", a[i].scheduleGetter()[12]);
			command->Parameters->AddWithValue("@n", a[i].scheduleGetter()[13]);
			command->Parameters->AddWithValue("@o", a[i].scheduleGetter()[14]);
			command->Parameters->AddWithValue("@p", a[i].scheduleGetter()[15]);
			command->Parameters->AddWithValue("@q", a[i].scheduleGetter()[16]);
			command->Parameters->AddWithValue("@r", a[i].scheduleGetter()[17]);
			command->Parameters->AddWithValue("@s", a[i].scheduleGetter()[18]);
			command->Parameters->AddWithValue("@t", a[i].scheduleGetter()[19]);
			command->Parameters->AddWithValue("@u", a[i].scheduleGetter()[20]);
			command->Parameters->AddWithValue("@v", a[i].scheduleGetter()[21]);
			command->Parameters->AddWithValue("@w", a[i].scheduleGetter()[22]);
			command->Parameters->AddWithValue("@x", a[i].scheduleGetter()[23]);
			command->Parameters->AddWithValue("@ID", i + 1);

			//Execute the update query
			command->ExecuteNonQuery();
		}
		MessageBox::Show("Schedule updated successfully", "Update Success", MessageBoxButtons::OK);
		sqlConn->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to update Schedule: " + e->Message, "Update Error", MessageBoxButtons::OK);
	}
}

void Admin::SetAvailabilityOfTrain(dataRetriever* a)
{
	try
	{
		//connecting
		String^ connString = "Data Source=DESKTOP-600TIJ4\\SQLEXPRESS;Initial Catalog=TMS;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		//queries
		String^ countQuery = "SELECT COUNT(*) AS [RowCount] FROM Trains;"; //getting total rows of database

		sqlConn->Open();
		//execution of queries
		SqlCommand^ countCommand = gcnew SqlCommand(countQuery, sqlConn);
		int rowCount = Convert::ToInt32(countCommand->ExecuteScalar());	//number of rows

		for (int i = 0; i < rowCount; i++)
		{
			//update query
			String^ updateQuery = "UPDATE Trains SET [Green Line] = @gl, [Hazara Express] = @he, [Chiltan Express] = @ce WHERE id = @ID;";
			SqlCommand^ command = gcnew SqlCommand(updateQuery, sqlConn);

			//putting on the database
			command->Parameters->AddWithValue("@gl", a[i].trainsGetter()[0]);
			command->Parameters->AddWithValue("@he", a[i].trainsGetter()[1]);
			command->Parameters->AddWithValue("@ce", a[i].trainsGetter()[2]);
			command->Parameters->AddWithValue("@ID", i + 1);

			//Execute the update query
			command->ExecuteNonQuery();
		}
		MessageBox::Show("Schedule updated successfully", "Update Success", MessageBoxButtons::OK);
		sqlConn->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to update Schedule: " + e->Message, "Update Error", MessageBoxButtons::OK);
	}
}

#endif