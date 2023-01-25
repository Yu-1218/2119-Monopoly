# Group-project
***Team members:***   
Ye Yu (Beng, Year 1, UID: 3035637527，user name: Yu-1218)    
Yan Yi (Beng, Year1, UID: 3035638325, user name: Ken-cmyk)  

***How to play it in Linux***  
**Please use the command "./main" after the command "make" !!!**
  
***Description of our game:***  
Our game is a kind of “Monopoly”. The rules are as followed.  
**1.Players:**  
The game will include four players.  

**2.Beginning of the game:**  
The process of the game will be displayed on a board which is divided into some small squares. Four different graphics will represent four players and be placed at the “Go space” of the board. All players will get the same amount of initial cash.  

**3.Roll the dice:**  
Each round, players will take turns throwing dice in a default order. This order will be in the default order of the system and will not be controlled by the player.  

**4.Move and action:**  
The players move according to the number of dice rolled, and do some operations depending on the types of the square they are on.  

**5.The types of the square:**  
There are four types of these squares.  
1. unoccupied land: Every player can use some cash to buy the land.  
2. occupied land: If the land belongs to the player who is on it, he can pay some cash and build a house (at most three house can be built on a single land) on the land, which will give the player more toll when other players go on it. If the land belongs to other players, the player must pay some cash as toll to the player who owns the land.
3. Random event: The player will meet some random event, such as losing some cash, get some cash, or can't roll the dice in next round.
4. Go sapce: Player can do nothing but will get some cash.  

**6. Insolvency：**  
When the player's cash is not enough to pay, his real estate will be sold (below the purchase price) automatically to get cash. When all properties are sold and there is no cash, the player will lose the game.  

**7.Winning or losing judgment：**  
The last player who didn't go broke won.  
At the end of the time/step limit, the one with the highest total assets wins.  

***Library we use：***  
cstdlib and ctime: use for make random numbers while rolling the dice    
iostream: standard input and output
fstream: file I/O  
string: store the data of each move and conditions  
cmath: use for calculation  
vector: to store the data and do some operation  
map: for some operation for data    


***Function we use:***  
player(): choose the number of human players and the character  
init(): to init the data for the new game  
cash(): to update the cash every player has  
land(): to update the land every player has  
house(): for every single land, update the number  
map(): display the map and the position of the player  
rolling(): take turns rolling the dice  
chooseaction(): check the status of current land and ask the player to take action.  
checkcash(): after each step, check the cash of a player.  
checkland(): use the array and store the condition of each land.  
triggerrandom(): store the random incidents and if a player is in the particular land, trigger the incidents.  
islose(): detect the number of the cash and if it is below 0, kick out the player.  
timeup(): to end the game when time is up, and determine who wins  
display(): to display every player's information and the data about the game  

