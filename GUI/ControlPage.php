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

.button1 {
	position:absolute;
    transition: .5s ease;
    top: 34%;
    left: 50%;
    background: #008000; /* Green */
    border: 2px solid white;
    color: white;
    padding: 48px 48px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    cursor: pointer;
}

.button2 {
	position:absolute;
    transition: .5s ease;
    top: 54%;
    left: 50%;
    background: #008000; /* Green */
    border: 2px solid white;
    color: white;
    padding: 48px 48px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    cursor: pointer;
}
.button3 {
	position:absolute;
    transition: .5s ease;
    top: 44%;
    left: 40%;
    background: #008000; /* Green */
    border: 2px solid white;
    color: white;
    padding: 48px 48px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    cursor: pointer;
}
.button4 {
	position:absolute;
    transition: .5s ease;
    top: 44%;
    left: 60%;
    background: #008000; /* Green */
    border: 2px solid white;
    color: white;
    padding: 48px 48px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    cursor: pointer;
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
	font-size: 1.15em;
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
<meta name="viewport" content="width=device-width, initial-scale=1">
<body style="overflow: auto;" onload="lightsensing()">

<a href="https://www.facebook.com/ENG5220RoboPot/" class="fa fa-facebook"></a> 
<a href="https://github.com/FrazLaw/RoboPot" class="fa fa-github"></a>
<a href="https://www.youtube.com/channel/UCD5ITvIJ00v1beTOdpyzPOQ" class="fa fa-youtube-square"></a>	
<h1>RoboPot</h1>

<h3>Group 7 - Fraser Law, Fraser Menzies and Alastair Thurlbeck</h3>

<p class="intro">
This is our solution to moveable plant pots remotely controlled via a web interface!
</p>


<button class="button1" id="A" onclick="myFunction(this)">UP</button>
<button class="button2" id="B" onclick="myFunction(this);">Stop</button>
<button class="button3" id="C" onclick="myFunction(this)">LEFT</button>
<button class="button4" id="D" onclick="myFunction(this)">RIGHT</button>

<script src="lightsensing1.js"></script>
<script src="lightsensing2.js"></script>
<script src="lightsensing3.js"></script>
<script src="lightsensing4.js"></script>
<script src="position.js"></script>
<script src="buttonpress.js"></script>

</body>
</html>
