window.onload = lightsensing3();

function lightsensing3(){
	setInterval(function(){ //wait function 
		var request = new XMLHttpRequest(); //XMLHttpRequest is in-built function
		request.onreadystatechange = function(){
		if (request.readyState == 4 && request.status == 200){ //server status and checks 
				console.log(request.responseText); //request.responseText is the actual value that is being sent, .log isn't actually displaying the data
				document.getElementById("light3").innerHTML =  request.responseText; //document is assigning the value from above into the table 
			}
		}
		request.open('POST', 'lightsensorvalue3.php', true); //actually opening and sending the files 
		request.send();
	},1000);
}	//wait
