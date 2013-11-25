/*
	Initiate a random 10X10 Game Board with random 0s and 1s
	

*/

var ConwayGameOfLife = {
	glo_fitness: 0,
	game_space: [],
	temp_game_space: [],

	start: function() {
		this.createGameBoard();
		this.printGameBoard();
	},

	createGameBoard : function() {
		for ( var i = 0; i < 100; i++ ) {
			this.game_space[i] = this.IsLiveOrDead();
		}
	},

	IsLiveOrDead: function() {
		return parseInt(Math.random() * (2)); // (max - min + 1) = 2
	},

	printGameBoard: function() {
		var temp_print_game = [];
		var count = -1;		

		for ( var i = 0; i < 100; i++ ) {
			if( i % 10 == 0 ) {
				if(count != -1) 
					console.log(temp_print_game[count]);
				count++;
				temp_print_game[count] = [];
			}

			temp_print_game[count].push(this.game_space[i]);
		}

	}
}