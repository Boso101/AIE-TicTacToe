#pragma once

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
		
		
		// Make this slot belong to nobody
		Game::Player owner = Game::Player::EMPTY;


		char ToString();

		/// <summary>
		/// Can the player who is trying to place something actually place in this slot
		/// </summary>
		/// <returns> boolean on whether or not the player can take this spot</returns>
		bool CanPlace();
	};
}