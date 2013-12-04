/*
	Initiate a random 10X10 Game Board with random 0s and 1s
*/

var ConwayGameOfLife = {
	glo_fitness: 0,
	game_space: [],
	temp_game_space: [],
	hash_game_space: [],

	start: function(){
		this.createGameBoard();
		
		count = 0;
		var c = 0;
		var temp_space = [];
		this.oneLoop();
	},

	oneLoop: function() {
		temp_space = this.startGameOfLife();
		this.printGameBoard(temp_space);
	},

	createGameBoard : function(){
		/*
		for (var i=0; i < 100; i++) {
			this.game_space[i] = this.IsLiveOrDead();
		}
		*/
		
		// user input game space
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
		this.copyGameBoard();
	},

	copyGameBoard : function() {
		this.temp_game_space = this.game_space.concat();
	},

	startGameOfLife: function() {
		var temp_game_space = [];
		for (var i=1; i <= 100; i++) {
			if (this.conwayGameRules(i) == true)
				temp_game_space.push(1);
			else 
				temp_game_space.push(0);
		}

		this.game_space = temp_game_space;
		return this.game_space;
	},

	IsLiveOrDead: function() {
		return parseInt(Math.random() * (2)); //(max - min + 1) = 2
	},


	printGameBoard: function(game_board) {
		var temp_print_game = [];
		var count = 0;		
		for ( var i = 0; i <= 100; i++ ) {
			if( i % 10 === 0 ) {
				count++;
				temp_print_game[count] = [];
			}

			temp_print_game[count].push(game_board[i]);
		}
	},

	conwayGameRules: function(cell) {
		var R = false, L = false, T = false, B = false;

		// check top
		if(cell <= 10) 
			T = true;
		// check bottom
		if(cell > 89)
			B = true;
		// check right
		if(cell % 10 == 0)
			R = true;
		// check left
		if(String(cell)[1] == 1 || cell == 1)
			L = true;

		return this.checkconwayGameRules(cell, T, R, B, L)		
	},

	checkconwayGameRules: function(cell, T, R, B, L) {
		var surround = {};
		
		surround[cell - 11] = true;
		surround[cell - 10] = true;
		surround[cell - 9] = true;
		surround[cell - 1] = true;
		surround[cell + 1] = true;
		surround[cell + 9] = true;
		surround[cell + 10] = true;
		surround[cell + 11] = true;

		if( T ) {
			delete surround[cell - 11];
			delete surround[cell - 10];
			delete surround[cell - 9];		
		} 

		if( B ) {
			delete surround[cell + 9];
			delete surround[cell + 10];
			delete surround[cell + 11];
		}

		if( L ) {
			delete surround[cell - 11];
			delete surround[cell - 1];
			delete surround[cell + 9];
		}
		
		if( R ) {
			delete surround[cell - 9];
			delete surround[cell + 1];
			delete surround[cell + 11];
		}

		
		var count = 0;
		for (var x in surround) {
			if(this.game_space[x-1] == 1)
				count++;
		}

		//console.log(surround);
		if (count == 1)
			return true;
		else if (count > 0)
			return false
		else if (count < 3)
			return false;
	}
};