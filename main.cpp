/*
 
 	YunYunLinux - WIP Linux Hack for Counter-Strike: Global Offensive
    Copyright (C) 2017  xenocidewiki

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with YunYunLinux.  If not, see <http://www.gnu.org/licenses/>.
    
*/

#include "Utils.h"

int main()
{
	//Currently testing functions, WIP
	Utilities utils;
	
	pid_t meme = utils.GetProcessByName( "csgo_linux64" );
	std::cout << meme << std::endl;
	
    return 0;
}