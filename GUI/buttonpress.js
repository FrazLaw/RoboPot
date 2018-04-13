function myFunction(elem){
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		if (this.readyState == 4 && this.status == 200){
			document.getElementById(elem.id).innerHTML = 
			this.responseText;
		}
	};
	
	if (elem.id == 'A'){
		xhttp.open("POST", "CreateA.php", true);
		xhttp.send();
	} else if (elem.id == 'B'){
		xhttp.open("POST", "CreateB.php", true);
		xhttp.send();
	} else if (elem.id == 'C'){
		xhttp.open("POST", "CreateC.php", true);
		xhttp.send();
	} else if (elem.id == 'D'){
		xhttp.open("POST", "CreateD.php", true);
		xhttp.send();
	} else if (elem.id == 'E'){
		xhttp.open("POST", "CreateE.php", true);
		xhttp.send();
	} else if (elem.id == 'F'){
		xhttp.open("POST", "CreateF.php", true);
		xhttp.send();
	} else if (elem.id == 'G'){
		xhttp.open("POST", "CreateG.php", true);
		xhttp.send();
	} else if (elem.id == 'H'){
		xhttp.open("POST", "CreateH.php", true);
		xhttp.send();
	} else if (elem.id == 'I'){
		xhttp.open("POST", "CreateI.php", true);
		xhttp.send();
	} else if (elem.id == 'J'){
		xhttp.open("POST", "CreateJ.php", true);
		xhttp.send();
	} else if (elem.id == 'K'){
		xhttp.open("POST", "CreateK.php", true);
		xhttp.send();
	} else if (elem.id == 'L'){
		xhttp.open("POST", "CreateL.php", true);
		xhttp.send();
	} else if (elem.id == 'M'){
		xhttp.open("POST", "CreateM.php", true);
		xhttp.send();
	} else if (elem.id == 'N'){
		xhttp.open("POST", "CreateN.php", true);
		xhttp.send();
	} else if (elem.id == 'O'){
		xhttp.open("POST", "CreateO.php", true);
		xhttp.send();
	} else if (elem.id == 'P'){
		xhttp.open("POST", "CreateP.php", true);
		xhttp.send();
	}else {
		xhttp.open("POST", "CreateFile.php", true);
		xhttp.send();
	}
}
