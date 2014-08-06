BShip-Game
==========

Info:
	In this version of the game you will play the computer which places its ships randomly.
	When the computer takes a shot for the first time it will randomly choose a coordinate.
	If the computer hits a ship it will continue shooting in locations adjacent to successful
	shots. Try your luck against the formidable computer player.

Build Instructions:

1. In the source directory execute the Makefile using the make command

Note: On subsequent builds you will need to execute "make clean" before "make"

Example Game Board:

        Ship Grid                                Attack Grid                        Steven's turn                             
  |A|B|C|D|E|F|G|H|I|J|                     |A|B|C|D|E|F|G|H|I|J|                     Destroyer was hit!                      
 1|@|@|@|@|@| | | | |@|                    1|X| |X| |X| |X| |X| |                   Steven wins!!!                            
 2| | | | | | | | | |@|                    2| |X|@|@|@|@|X|X|X|X|                                                             
 3| | | | | | | | | |@|                    3|X|@|@|@|@|@|X| |X| |                                                             
 4| | |@|@|@| | | | |@|                    4| |X| |X| |X| |X| |X|                                                             
 5| | | | | | | | | | |                    5|X|@|@|@|X|X|X|X|X|X|                                                             
 6| | | | | | | |O| | |                    6|X|@|@|X|X| |X| |X| |                                                             
 7| | | | | | | |O| | |                    7| |X| |X| |X| |X| |X|                                                             
 8| | |@| | | | |O| | |                    8|X| |X|X|@|@|@| | | |                                                             
 9| | |@| | | | | | | |                    9| | | | | | | | | | |                                                             
10| | | | | | | | | | |                   10| | | | | | | | | | |                                                             
---Legend---   
O Ship         
@ Ship with hit
X Missed Attack

