window.onload = position();

function position(){
	setInterval(function(){ //wait function 
	document.getElementById("A").style.background ="#008000";
	document.getElementById("B").style.background ="#008000";
	document.getElementById("C").style.background ="#008000";
	document.getElementById("D").style.background ="#008000";
	document.getElementById("E").style.background ="#008000";
	document.getElementById("F").style.background ="#008000";
	document.getElementById("G").style.background ="#008000";
	document.getElementById("H").style.background ="#008000";
	document.getElementById("I").style.background ="#008000";
	document.getElementById("J").style.background ="#008000";
	document.getElementById("K").style.background ="#008000";
	document.getElementById("L").style.background ="#008000";
	document.getElementById("M").style.background ="#008000";
	document.getElementById("N").style.background ="#008000";
	document.getElementById("O").style.background ="#008000";
	document.getElementById("P").style.background ="#008000";
		var request = new XMLHttpRequest(); //XMLHttpRequest is in-built function
		request.onreadystatechange = function(){
			if (request.readyState == 4 && request.status == 200){ //server status and checks 
				console.log(request.responseText);
			}
			var response = request.responseText;
				switch(response){
					case '"A\\n"':
						document.getElementById("A").style.background = "#ff6600";
						break;
					case '"B\\n"':
						document.getElementById("B").style.background = "#ff6600";
						break;
					case '"C\\n"':
						document.getElementById("C").style.background = "#ff6600";
						break;
					case '"D"':
						document.getElementById("D").style.background = "#ff6600";
						break;
					case 'E':
						document.getElementById("E").style.background = "#ff6600";
						break;
					case '"F\\n"':
						document.getElementById("F").style.background = "#ff6600";
						break;
					case '"G\\n"':
						document.getElementById("G").style.background = "#ff6600";
						break;
					case '"H\\n"':
						document.getElementById("H").style.background = "#ff6600";
						break;
					case '"I\\n"':
						document.getElementById("I").style.background = "#ff6600";
						break;
					case '"J\\n"':
						document.getElementById("J").style.background = "#ff6600";
						break;
					case '"K\\n"':
						document.getElementById("K").style.background = "#ff6600";
						break;
					case '"L\\n"':
						document.getElementById("L").style.background = "#ff6600";
						break;
					case '"M\\n"':
						document.getElementById("M").style.background = "#ff6600";
						break;
					case '"N\\n"':
						document.getElementById("N").style.background = "#ff6600";
						break;
					case '"O\\n"':
						document.getElementById("O").style.background = "#ff6600";
						break;
					case '"P\\n"':
						document.getElementById("P").style.background = "#ff6600";
						break;
					default:
						document.getElementById("P").style.background = "ff6600";
				}

			}
		request.open('GET', 'positionupdate.php', true); //actually opening and sending the files 
		request.send();	
	},3000);		//wait
}