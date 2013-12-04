###Conway's Game of Life using Genetic Algorithm

This is an implementation of [Conway's Game of Life](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using Genetic Algorithm. 

####The Genetic Algorithm is implemented using C++.

The code was initially written in javascript but due to some reason or the other, it froze the browser. So, I thought the best would be to rewrite the whole program in C++.

There are two programs in the C++ folder.

* `cgol.cpp`

This cpp program will find state in which a generation will last for less than 1000 generation. 

	- First, 10 generations less than 15000 are found in the first iteration.
	- 1/3rd of the stored generation are used in the next iteration.
	- The genes are randomly selected and either mutated or cross overed.
	- Again, 1/3rd genes are chosen from the set of newly formed genes + old genes from the last iteration.
	- The process is stopped when a state stops or loops in less than 1000 generations.

* `new_pattern.cpp`

This cpp program will find a state which forms a different pattern than the Conway's Game of Life.

	- Rules are set randomly at the beginning of the game.
	- 10 states are picked in the first iteration.
	- 1/3rd of the states are picked to the next generation which have the least loop or dead state.
	- The genes are randomly selected and either mutated or crossed over.
	- Again, 1/3rd of the genes are chosen formed from the set of newly formed genes + old genes from the last iteration.
	- The process is stopped when a state stops or loops in less than 1000 generations.
	
	
#### Visualization is done in javascript
A state is represented in the form of 1s and 0s. I have used 10X10 board, in which input is done either randomly by the program or you can input a gamestate.

Use `CreateGameBoard()` function to change game input method.
Remove the comments either:

```javascript
for (var i=0; i < 100; i++) {
			this.game_space[i] = this.IsLiveOrDead();
			
 Or
 
this.game_space =  [1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 
					0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 
					0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
					0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 
					1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 
					0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 
					1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 
					1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 
					1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
					1, 1, 1, 1, 0, 0, 0, 1, 0, 0];
```

The index.html has 3 buttons to either pause the game, continue the game after pause or run one generation at a click after pause.

####Running the Game

* Run either `cgol.cpp` or `new_pattern.cpp`.
* After a generation is found, it will print the initial state of the game board.
* In `new_pattern.cpp`, it will print out the initial state and the rules.

	```
	Live if surrounding cell == 1
	Die if surrounding cell > 7
	Die if surrounding cell < 5
	Ended after 37 generation
	Intial State: 
	[1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 
	1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 
	0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 
	1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 
	1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 
	0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 
	1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 
	1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 
	1, 0, 0, 1, 1, 0, 0, 0, 0, 0]
	```

* Change input method to user input in `script.js`.

 ```javascript
this.game_space =  [1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 
					0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 
					0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
					0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 
					1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 
					0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 
					1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 
					1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 
					1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
					1, 1, 1, 1, 0, 0, 0, 1, 0, 0];
```

* Change the rule set in `script.js` file to see the visualization:

	```javascript
	if (count == 1) // rule1
				return true;
			else if (count > 7) // rule2
				return false
			else if (count < 5) // rule3
				return false;
	```
* __If you just want to see the Conway's Game of Life in action, do the following changes to `script.js`__
	* Change input mode to random. (refer above)
	* Change rule set to:
	```javascript
	if (count == 2) // rule1
				return true;
			else if (count > 2) // rule2
				return false
			else if (count < 2) // rule3
				return false;
	```
	* _Done._
	
	
###Few interesting patterns that I observed were:

#####Pattern 1
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-09-42-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-09-49-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-09-55-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-10-18-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-10-25-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-10-33-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-10-40-pm.png)

#####Pattern 2
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-01-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-08-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-12-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-17-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-22-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-28-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-36-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-15-43-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-34-53-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-35-00-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-35-07-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-35-13-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-35-20-pm.png)
![alt text](http://prashish.files.wordpress.com/2013/12/screen-shot-2013-12-03-at-6-35-26-pm.png)
