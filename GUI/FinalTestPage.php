<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
.fa {
  padding: 20px;
  font-size: 30px;
  width: 50px;
  text-align: center;
  text-decoration: none;
  margin: 5px 2px;
}
.fa:hover {
    opacity: 0.7;
}
.fa-facebook {
  background: #3B5998;
  color: white;
  float: left;
}
.fa-youtube-square {
  background: red;
  color: white;
  float: left;
}
.fa-github {
	background: black;
	color: white;
	float: left;
}

h1 {
	color: white;
	text-shadow: 1px 1px 5px black, 0 0 25px green, 0 0 5px lawngreen;
	margin-right: 10%;
	font-size: 3em;
	text-align: center;
}
h3 {
	color: white;
	text-shadow: 1px 1px 5px black, 0 0 25px green, 0 0 5px lawngreen;
	text-align: center;
	font-size: 2em;
}
body {
	background-image: url("https://images.pexels.com/photos/413195/pexels-photo-413195.jpeg?h=350&auto=compress&cs=tinysrgb");
}

.button {
    background: #008000; /* Green */
    border: 2px solid white;
    color: white;
    padding: 48px 48px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    cursor: pointer;
	float: left;
}

.button:hover { 
	opacity: 0.7;
}


.button:after {
    content: "";
    clear: both;
    display: table;
}
.btn-group button:hover { 
	background-color: #3e8e41;
}
.btn-group button:not(:last-child) {
    border-right: none; 
}
p.intro {
	color: white;
	text-shadow: 1px 1px 5px black, 0 0 25px green, 0 0 5px lawngreen;
	font-size: 1.25em;
	text-align: center;
}

table {
	font-family: arial, sans-serif;
	width: 40%;
	margin-left: 30%;
	border-collapse: collapse;
}
td, th {
	border: 1px solid black;
	text-align: left;
	padding: 8px;
}
tr {
	background-color: #4CAF50;
}
</style>
	<title>RoboPot</title>
</head>

<body style="overflow: auto;" onload="lightsensing()">

<a href="https://www.facebook.com/ENG5220RoboPot/" class="fa fa-facebook"></a> 
<a href="https://github.com/FrazLaw/RoboPot" class="fa fa-github"></a>
<a href="https://www.youtube.com/channel/UCD5ITvIJ00v1beTOdpyzPOQ" class="fa fa-youtube-square"></a>	
<h1>RoboPot</h1>

<h3>Group 7 - Fraser Law, Fraser Menzies and Alastair Thurlbeck</h3>

<p class="intro">
This is our solution to moveable plant pots remotely controlled via a web interface!
</p>
<table>
	<tr>
		<th>Light Sensor (Position)</th>
		<th>Light Intensity (Lux)</th>
	</tr>
	<tr>
		<td>Top left</td>
		<td id="light1"></td>
		
	</tr>
	<tr>
		<td>Top Right</td>
		<td id="light2"></td>
	</tr>
	<tr>
		<td>Bottom left</td>
		<td id="light3"></td>
	</tr>
	<tr>
		<td>Bottom Right</td>
		<td id="light4"></td>
	</tr>
</table>

<button class="button" style="margin-left: 39.6%" id="A" onclick="myFunction(this)"></button>
<button class="button" id="B" onclick="myFunction(this);"></button>
<button class="button" id="C" onclick="myFunction(this)"></button>
<button class="button" id="D" onclick="myFunction(this)"></button>


<button class="button" style="margin-left: 39.6%" id="E" onclick="myFunction(this)"></button>
<button class="button" id="F" onclick="myFunction(this)"></button>
<button class="button" id="G" onclick="myFunction(this)"></button>
<button class="button" id="H" onclick="myFunction(this)"></button>

<button class="button" style="margin-left: 39.6%" id="I" onclick="myFunction(this)"></button>
<button class="button" id="J" onclick="myFunction(this)"></button>
<button class="button" id="K" onclick="myFunction(this)"></button>
<button class="button" id="L" onclick="myFunction(this)"></button>

<button class="button" style="margin-left: 39.6%" id="M" onclick="myFunction(this)"></button>
<button class="button" id="N" onclick="myFunction(this)"></button>
<button class="button" id="O" onclick="myFunction(this)"></button>
<button class="button" id="P" onclick="myFunction(this)"></button>

<script src="lightsensing.js"></script>
<script src="position.js"></script>
<script src="buttonpress.js"></script>

</body>
</html>
