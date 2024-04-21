#include"MHM_Functions.h"

int main()
{
	InitWindow(1440, 1024, "Train Management System");
	InitAudioDevice();

	//load textures
	Texture2D admin1 = LoadTexture("Assets\\RawBG.png");
	Texture2D admin2 = LoadTexture("Assets\\BlurClearBG.png");
	Texture2D TaFR = LoadTexture("Assets\\To_and_From Raw.png");
	Texture2D R = LoadTexture("Assets\\R.png");
	Texture2D UT = LoadTexture("Assets\\UT.png");
	Texture2D T = LoadTexture("Assets\\T.png");

	//screen state handler
	int screen = 0;

	//counts



	float i = 150;				//maintains gap between list elements
	int* all_routes = nullptr;	//will have data such as which route is available, which is not
	string* start = nullptr;
	string* end = nullptr;
	Rectangle* listofroute = nullptr;	//for selection of routes
	int number_of_rectangles = 0;


	Rectangle routeButton{ 100,150,455,242 };
	Rectangle ContinueButton{ 560,715,360,100 };
	int showRouteList = 0;

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		/*--------------------------Update Phase--------------------------*/
		switch (screen)
		{
		case 0:
			number_of_rectangles = Admin::GetRouteData(all_routes, start, end);		//getting the route availibility data from the data Base
			if (CheckCollisionPointRec(GetMousePosition(), routeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				showRouteList = 1;
				screen = 1;
			}
			break;
		case 1:
			for (int j = 0; j < number_of_rectangles; j++)		//works as a toggle
			{
				if (CheckCollisionPointRec(GetMousePosition(), listofroute[j]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && all_routes[j] == 0)
				{
					all_routes[j] = 1;
					Admin::ChangeRouteAvailability(all_routes);

				}
				else if (CheckCollisionPointRec(GetMousePosition(), listofroute[j]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && all_routes[j] == 1)
				{
					all_routes[j] = 0;
					Admin::ChangeRouteAvailability(all_routes);
				}
			}
			if (CheckCollisionPointRec(GetMousePosition(), ContinueButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				screen = 0;
			}
			break;
		default:
			break;
		}









		/*--------------------------Draw Phase--------------------------*/
		BeginDrawing();
		ClearBackground(WHITE);
		switch (screen)
		{
		case 0:
			DrawTexture(admin1, 0, 0, WHITE);
			DrawRectangleRec(routeButton, BLACK);
			DrawTexture(R, static_cast<int>(routeButton.x), static_cast<int>(routeButton.y), WHITE);
			break;
		case 1:
			ClearBackground(WHITE);
			DrawTexture(admin2, -25, -25, WHITE);
			DrawTexture(TaFR, -10, -15, WHITE);

			if (showRouteList == 1)
			{
				listofroute = new Rectangle[number_of_rectangles];
				i = 175;
				for (int j = 0; j < number_of_rectangles; j++)
				{
					listofroute[j] = { 280, i, 910, 80 };		//All the routes in data base
					i = i + 110;
				}
				for (int j = 0; j < number_of_rectangles; j++)
				{
					if (all_routes[j] == 0)	//Untoggled
					{
						DrawRectangleRec(listofroute[j], BLANK);
						DrawTexture(UT, static_cast<int>(listofroute[j].x), static_cast<int>(listofroute[j].y), WHITE);
						DrawText((start[j] + "   to").c_str(), static_cast<int>(listofroute[j].x + 180), static_cast<int>(listofroute[j].y + 17), 40, BLACK);
						DrawText(end[j].c_str(), static_cast<int>(listofroute[j].x+480), static_cast<int>(listofroute[j].y+17), 40, BLACK);
					}
					else if (all_routes[j] == 1)	//Toggled
					{
						DrawRectangleRec(listofroute[j], BLANK);
						DrawTexture(T, static_cast<int>(listofroute[j].x), static_cast<int>(listofroute[j].y), WHITE);
						DrawText((start[j] + "   to").c_str(), static_cast<int>(listofroute[j].x + 180), static_cast<int>(listofroute[j].y + 17), 40, BLACK);
						DrawText(end[j].c_str(), static_cast<int>(listofroute[j].x + 480), static_cast<int>(listofroute[j].y + 17), 40, BLACK);
					}
				}
				DrawRectangleRec(ContinueButton, BLANK);
			}

			break;
		default:
			break;
		}




		EndDrawing();
	}

	UnloadTexture(admin1);
	UnloadTexture(admin2);
	UnloadTexture(TaFR);
	UnloadTexture(R);
	UnloadTexture(UT);

	CloseWindow();
	CloseAudioDevice();
}