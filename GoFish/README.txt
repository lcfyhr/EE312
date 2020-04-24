ReadME File for GoFish 
Created by: Vishal Bhongir & Lars Fyhr

To build and run this program:
1. unzip file into desired directory
2. type "make" into the linux command prompt
3. run the executable "test" (./test)

Information displayed in the console:
  - Confirmation of opening and closing of the output file
  - How many pairs both players had, and the final outcome of the game

Information found in "gofish_results.txt"
  - Description of what happened each turn
  - Look into each players hands and books every 10 turns
  - The final outcome of the game, and both players' full list of pairs

ASSUMPTIONS:
- If player is dealt pair, book before game starts
- If player draws a pair, book pair immediately, still switch turns
- If both players have the same number of pairs, game simply ends in a tie
