#include <string>
#include "Player.h"

namespace GameBoard
{
	/// <summary>
	/// A struct that the game board is made up of.
	/// It holds whatever a player places in the spot.
	/// </summary>
	struct BoardSlot
	{

		char value = '-';
		bool canPlace = true;
		
		// Make this slot belong to nobody
		Game::Player owner = Game::Player::EMPTY;


		char ToString();
	};
}