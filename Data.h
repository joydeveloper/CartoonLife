namespace Data
{
	enum AppType{ console = 0, window };
	enum BoardType{ line, circle, grid };
	struct COption
	{
		
		AppType apptype = AppType::console;
	};
	struct Mode
	{
		
		BoardType boardtype;
		int white_count, blue_count, green_count, yellow_count, red_count, black_count, grey_count;
		int bonefaces;
		int bonecount;

	};
	struct PlayerOrder
	{
		
		int playercount;
		int computer_player_count;
		int players_max;
	};
	struct Rules
	{
		int die;
		double slowpenalty;
		int win;
		int skipturn_bonus;
		int red;
		int grey;
		int black;
		int blue;
	};


}